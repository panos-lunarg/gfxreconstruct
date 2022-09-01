#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define SOCKET_NAME "GFXRECON_SOCKET"

struct client_id_t
{
    pid_t pid;
    void *virtual_address;
    size_t nof_pages;
};

int setup_server()
{
    int ret;
    struct sockaddr_un server_addr;
    int socket_fd;
    int data_socket;

    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        printf("%s() error socket: %s\n", __func__, strerror(errno));
        return -1;
    }

    printf("%s() Socket made\n", __func__);

    char socket_name[108];
    memcpy(&socket_name[0], "\0", 1);
    strcpy(&socket_name[1], SOCKET_NAME);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, socket_name, sizeof(server_addr.sun_path) - 1); // 108 char max

    ret = bind(socket_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0)
    {
        printf("%s() error at bind: %s\n", __func__, strerror(errno));
        return -1;
    }
    printf("%s() Bind made\n", __func__);

    // Open 8 back buffers for this demo
    ret = listen(socket_fd, 8);
    if (ret < 0)
    {
        printf("%s() error at listen: %s\n", __func__, strerror(errno));
        return -1;
    }
    printf("%s() Socket listening for packages\n", __func__);

    return socket_fd;
}

#define PAGEMAP_ENTRY 8
#define KPAGEFLAGS_ENTRY 8
#define KPAGEFLAGS_WORD 4
#define GET_BIT(X, Y) (((X) & ((uint64_t)1 << (Y))) >> (Y))

#define PAGEMAP_PAGE_SWAPPED_BIT 62
#define PAGEMAP_PAGE_PRESENT_BIT 63
#define PAGEMAP_SOFT_DIRTY_PTE_BIT 55

#define KPAGEFLAGS_DIRTY_BIT 4

#define PAGE_FRAME_NUMBER_BITS 54
#define PFN_MASK ((((uint64_t)1 << (PAGE_FRAME_NUMBER_BITS + 1)) - 1))
#define GET_PFN(X) X &PFN_MASK
#define INVALID_PFN PFN_MASK

const int __endian_bit = 1;
#define is_bigendian() ((*(char *)&__endian_bit) == 0)

FILE *kpageflags_fp = NULL;

int read_kpageflags(uint64_t PFN)
{
    assert(kpageflags_fp);

    // printf("   %s(%" PRIx64 ", count: %d)\n", __func__, PFN, count);

    // Shifting by virt-addr-offset number of bytes
    // and multiplying by the size of an address (the size of an entry in pagemap file)
    const size_t file_offset = PFN * KPAGEFLAGS_ENTRY;
    // printf("    PFN: 0x%lx, Page_size: %d, Entry_size: %d\n", PFN, getpagesize(), KPAGEFLAGS_ENTRY);
    // printf("    Reading %s at 0x%llx\n", kpageflags_filename, (unsigned long long)file_offset);
    if (fseek(kpageflags_fp, file_offset, SEEK_SET))
    {
        perror("Failed to do fseek!");
        return 0;
    }

    int dirty = 0;
    unsigned char c_buf[KPAGEFLAGS_WORD];
    for (int i = 0; i < KPAGEFLAGS_WORD; i++)
    {
        int c = getc(kpageflags_fp);
        if (c == EOF)
        {
            printf("\nReached end of the file\n");
            return 0;
        }
        if (is_bigendian())
            c_buf[i] = c;
        else
            c_buf[KPAGEFLAGS_WORD - i - 1] = c;
    }

    uint32_t read_val_pagemap = 0;
    for (int i = 0; i < KPAGEFLAGS_WORD; i++)
    {
        read_val_pagemap = (read_val_pagemap << 8) + c_buf[i];
    }

    printf("    PFN: 0x%" PRIx64 " kpageflags: 0x%llx  ", PFN, (unsigned long long)read_val_pagemap);
    printf("    DIRTY: %" PRIx64 "\n", GET_BIT(read_val_pagemap, KPAGEFLAGS_DIRTY_BIT));

    return GET_BIT(read_val_pagemap, KPAGEFLAGS_DIRTY_BIT);
}

int read_pagemap(const char *pagemap_filename, uint64_t virt_addr, int nof_pages, uint8_t *page_status)
{
    assert(page_status);
    uint8_t *ps = page_status;

    FILE *pamgemap_fp = fopen(pagemap_filename, "rb");
    if (!pamgemap_fp)
    {
        printf("Error: Cannot open %s\n", pagemap_filename);
        return 0;
    }

    kpageflags_fp = fopen("/proc/kpageflags", "rb");
    if (!kpageflags_fp)
    {
        printf("Error: Cannot open %s\n", "/proc/kpageflags");
        fclose(pamgemap_fp);

        return 0;
    }

    const size_t file_offset = virt_addr / getpagesize() * PAGEMAP_ENTRY;
    if (fseek(pamgemap_fp, file_offset, SEEK_SET))
    {
        perror("Error: Failed to do fseek!");
        fclose(pamgemap_fp);
        fclose(kpageflags_fp);

        return 0;
    }

    int dirty = 0;

    for (int p = 0; p < nof_pages; ++p)
    {
        uint64_t read_val_pagemap = 0;
        unsigned char c_buf[PAGEMAP_ENTRY];
        for (int i = 0; i < PAGEMAP_ENTRY; i++)
        {
            int c = getc(pamgemap_fp);
            if (c == EOF)
            {
                printf("Error: Unexpected end of the file\n");
                fclose(pamgemap_fp);
                fclose(kpageflags_fp);

                return 0;
            }
            if (is_bigendian())
                c_buf[i] = c;
            else
                c_buf[PAGEMAP_ENTRY - i - 1] = c;
        }

        for (int i = 0; i < PAGEMAP_ENTRY; i++)
        {
            read_val_pagemap = (read_val_pagemap << 8) + c_buf[i];
        }

        // printf("Page %d", p);
        // printf("  Result: 0x%llx\n", (unsigned long long)read_val_pagemap);

        if (GET_BIT(read_val_pagemap, PAGEMAP_PAGE_PRESENT_BIT))
        {
            uint64_t PFN = GET_PFN(read_val_pagemap);
            // printf("  PFN: 0x%" PRIx64 "\n", PFN);
            if ((page_status[p] = read_kpageflags(PFN)))
                dirty = 1;
        }
        else
        {
            page_status[p] = 0;
        }
    }

    fclose(pamgemap_fp);
    fclose(kpageflags_fp);

    // for (int p = 0; p < nof_pages; ++p)
    //     printf("  page %d: %u\n", p, ps[p]);

    return dirty;
}

// int read_kpageflags(uint64_t PFN, int count, uint8_t *page_status)
// {
//     assert(page_status);
//     assert(kpageflags_fp);

//     // printf("   %s(%" PRIx64 ", count: %d)\n", __func__, PFN, count);

//     // Shifting by virt-addr-offset number of bytes
//     // and multiplying by the size of an address (the size of an entry in pagemap file)
//     const size_t file_offset = PFN * KPAGEFLAGS_ENTRY;
//     // printf("    PFN: 0x%lx, Page_size: %d, Entry_size: %d\n", PFN, getpagesize(), KPAGEFLAGS_ENTRY);
//     // printf("    Reading %s at 0x%llx\n", kpageflags_filename, (unsigned long long)file_offset);
//     if (fseek(kpageflags_fp, file_offset, SEEK_SET))
//     {
//         perror("Failed to do fseek!");
//         return 0;
//     }

//     int dirty = 0;
//     for (int p = 0; p < count; ++p)
//     {
//         unsigned char c_buf[KPAGEFLAGS_WORD];
//         for (int i = 0; i < KPAGEFLAGS_WORD; i++)
//         {
//             int c = getc(kpageflags_fp);
//             if (c == EOF)
//             {
//                 printf("\nReached end of the file\n");
//                 return 0;
//             }
//             if (is_bigendian())
//                 c_buf[i] = c;
//             else
//                 c_buf[KPAGEFLAGS_WORD - i - 1] = c;
//         }

//         uint32_t read_val_pagemap = 0;
//         for (int i = 0; i < KPAGEFLAGS_WORD; i++)
//         {
//             read_val_pagemap = (read_val_pagemap << 8) + c_buf[i];
//         }

//         // printf("    PFN: 0x%" PRIx64 " kpageflags: 0x%llx  ", PFN + p, (unsigned long long)read_val_pagemap);
//         // printf("    DIRTY: %" PRIx64 "\n", GET_BIT(read_val_pagemap, KPAGEFLAGS_DIRTY_BIT));

//         if (GET_BIT(read_val_pagemap, KPAGEFLAGS_DIRTY_BIT))
//         {
//             dirty = 1;
//             page_status[p] = 1;
//         }
//     }

//     return dirty;
// }

// int read_pagemap(const char *pagemap_filename, uint64_t virt_addr, int nof_pages, uint8_t *page_status)
// {
//     assert(page_status);
//     uint8_t *ps = page_status;

//     FILE *pamgemap_fp = fopen(pagemap_filename, "rb");
//     if (!pamgemap_fp)
//     {
//         printf("Error: Cannot open %s\n", pagemap_filename);
//         return 0;
//     }

//     kpageflags_fp = fopen("/proc/kpageflags", "rb");
//     if (!kpageflags_fp)
//     {
//         printf("Error: Cannot open %s\n", "/proc/kpageflags");
//         fclose(pamgemap_fp);

//         return 0;
//     }

//     const size_t file_offset = virt_addr / getpagesize() * PAGEMAP_ENTRY;
//     if (fseek(pamgemap_fp, file_offset, SEEK_SET))
//     {
//         perror("Error: Failed to do fseek!");
//         fclose(pamgemap_fp);
//         fclose(kpageflags_fp);

//         return 0;
//     }
//     errno = 0;

//     uint64_t previous_pfn = UINT64_MAX, base_pfn = UINT64_MAX;
//     int page_count = 0, dirty = 0, p = 0, pp = 0;

//     for (; p < nof_pages; ++p)
//     {
//         uint64_t read_val_pagemap = 0;
//         unsigned char c_buf[PAGEMAP_ENTRY];
//         for (int i = 0; i < PAGEMAP_ENTRY; i++)
//         {
//             int c = getc(pamgemap_fp);
//             if (c == EOF)
//             {
//                 printf("Error: Unexpected end of the file\n");
//                 fclose(pamgemap_fp);
//                 fclose(kpageflags_fp);

//                 return 0;
//             }
//             if (is_bigendian())
//                 c_buf[i] = c;
//             else
//                 c_buf[PAGEMAP_ENTRY - i - 1] = c;
//         }

//         for (int i = 0; i < PAGEMAP_ENTRY; i++)
//         {
//             read_val_pagemap = (read_val_pagemap << 8) + c_buf[i];
//         }

//         // printf("Page %d", p);
//         // printf("  Result: 0x%llx\n", (unsigned long long)read_val_pagemap);

//         if (GET_BIT(read_val_pagemap, PAGEMAP_PAGE_PRESENT_BIT))
//         {
//             uint64_t PFN = GET_PFN(read_val_pagemap);
//             // printf("  PFN: 0x%" PRIx64 "\n", PFN);

//             if (!page_count)
//             {
//                 page_count = 1;
//                 base_pfn = previous_pfn = PFN;
//             }
//             else
//             {
//                 assert(previous_pfn != UINT64_MAX);
//                 assert(base_pfn != UINT64_MAX);

//                 if (previous_pfn + 1 != PFN)
//                 {
//                     if (read_kpageflags(base_pfn, page_count, page_status))
//                     {
//                         dirty = 1;
//                     }

//                     for (int kp = 0; kp < page_count; ++pp, ++kp)
//                         printf("page %d: DIRTY: %u\n", pp, ps[pp]);

//                     page_status += page_count;
//                     page_count = 1;
//                     base_pfn = previous_pfn = PFN;
//                 }
//                 else
//                 {
//                     ++page_count;
//                     previous_pfn = PFN;
//                 }
//             }
//         }
//         else
//         {
//             // printf("  PFN: xxx\n");
//             if (page_count)
//             {
//                 assert(base_pfn != UINT64_MAX);
//                 assert(previous_pfn != UINT64_MAX);

//                 if (read_kpageflags(base_pfn, page_count, page_status))
//                 {
//                     dirty = 1;
//                 }

//                 for (int kp = 0; kp < page_count; ++pp, ++kp)
//                     printf("page %d: DIRTY: %u\n", pp, ps[pp]);

//                 page_status += page_count;
//                 page_count = 0;
//                 base_pfn = previous_pfn = UINT64_MAX;
//             }

//             ++page_status;
//         }
//     }

//     assert(pp = nof_pages);

//     if (page_count)
//     {
//         assert(base_pfn != UINT64_MAX);
//         assert(previous_pfn != UINT64_MAX);

//         if (read_kpageflags(base_pfn, page_count, page_status))
//         {
//             dirty = 1;
//         }

//         for (int kp = 0; kp < page_count; ++pp, ++kp)
//             printf("page %d: DIRTY: %u\n", pp, ps[pp]);
//     }

//     fclose(pamgemap_fp);
//     fclose(kpageflags_fp);

//     // for (int p = 0; p < nof_pages; ++p)
//     //     printf("  page %d: %u\n", p, ps[p]);

//     return dirty;
// }

int main(int argc, char *argv[])
{
    int socket_fd = setup_server();
    if (socket_fd < 0)
    {
        printf("Error: server failed\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int connfd = accept(socket_fd, (struct sockaddr *)NULL, NULL);
        if (connfd == -1)
        {
            printf("Error: Server accept failed: %s", strerror(errno));
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("new connection\n");
        }

        while (connfd != -1)
        {
            // Read PID,
            struct client_id_t client_id = {};
            ssize_t r = read(connfd, &client_id, sizeof(client_id));
            if (r == -1)
            {
                printf("Error: Server read failed: %s", strerror(errno));
                exit(EXIT_FAILURE);
            }

            // printf("new request:");
            // printf(" (pid: %d,", client_id.pid);
            // printf(" virtual_address: %p,", client_id.virtual_address);
            // printf(" nof_pages: %zu)\n", client_id.nof_pages);

            if (client_id.pid != -1 && client_id.nof_pages != 0 && client_id.virtual_address != 0)
            {
                char pagemap_filename[0x100] = {};
                sprintf(pagemap_filename, "/proc/%u/pagemap", client_id.pid);

                const size_t size = client_id.nof_pages * sizeof(uint8_t);
                uint8_t *page_status = malloc(size);
                assert(page_status);
                memset(page_status, 0, size);

                uint8_t dirty = read_pagemap(pagemap_filename, (uint64_t)client_id.virtual_address, client_id.nof_pages, page_status);

                write(connfd, &dirty, sizeof(dirty));
                if (dirty)
                    write(connfd, page_status, client_id.nof_pages * sizeof(uint8_t));

                free(page_status);
            }
            else
            {
                if (close(connfd) == -1)
                    perror("Error: Error closing connection:");
                else
                    printf("connection closed\n");

                connfd = -1;
            }
        }
    }
}
