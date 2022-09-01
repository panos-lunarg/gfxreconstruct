#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/mman.h>
#include <assert.h>
#include <time.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/inotify.h>
#include <pthread.h>
#include <fcntl.h>

#define SOCKET_NAME "GFXRECON_SOCKET"
const char *SHADOW_FILE_NAME = "shadow_file.bin";

struct timespec tstart;
size_t page_size;
size_t size;
const size_t pages = 512;

struct client_id_t
{
    pid_t pid;
    void *virtual_address;
    size_t nof_pages;
};

#define LOGE(...) printf(__VA_ARGS__)
#define LOGI(...) printf(__VA_ARGS__)

int setup_client()
{
    struct sockaddr_un server_addr;
    char socket_name[108];

    int data_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (data_socket < 0)
    {
        LOGE("%s() error socket: %s\n", __func__, strerror(errno));
        return -1;
    }

    memcpy(&socket_name[0], "\0", 1);
    strcpy(&socket_name[1], SOCKET_NAME);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, socket_name, sizeof(server_addr.sun_path) - 1);

    // Assuming only one init connection for demo
    int ret = connect(data_socket, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0)
    {
        LOGE("%s() error connect: %s\n", __func__, strerror(errno));
        return -1;
    }

    LOGI("%s() Client Setup Complete\n", __func__);

    return data_socket;
}

static size_t GetSystemPagePotShift()
{
    size_t pot_shift = 0;
    size_t page_size = getpagesize();

    if (page_size != 0)
    {
        assert((page_size & (page_size - 1)) == 0);
        while (page_size != 1)
        {
            page_size >>= 1;
            ++pot_shift;
        }
    }

    return pot_shift;
}

// time_t get_file_timestamp(int fd)
// {
//     struct stat file_stat;
//     int err = fstat(fd, &file_stat);
//     if (err != 0)
//     {
//         perror(" [file_is_modified] stat");
//         exit(errno);
//     }
//     return file_stat.st_mtime;
// }

// int file_is_modified(int fd, time_t oldMTime)
// {
//     struct stat file_stat;
//     int err = fstat(fd, &file_stat);
//     if (err != 0)
//     {
//         perror(" [file_is_modified] stat");
//         exit(errno);
//     }
//     printf("%s() file_stat.st_mtime: %ld oldMTime: %ld\n", __func__, file_stat.st_mtime, oldMTime);
//     return file_stat.st_mtime > oldMTime;
// }

void print_timestamps(int fd)
{
    struct stat file_stat;
    int err = fstat(fd, &file_stat);
    if (err != 0)
    {
        perror(" [file_is_modified] stat");
        exit(errno);
    }

    const unsigned long atime_in_micros = /* 1000000000 * file_stat.st_atim.tv_sec + */ file_stat.st_atim.tv_nsec;
    const unsigned long ctime_in_micros = /* 1000000000 * file_stat.st_ctim.tv_sec + */ file_stat.st_ctim.tv_nsec;
    const unsigned long mtime_in_micros = /* 1000000000 * file_stat.st_mtim.tv_sec + */ file_stat.st_mtim.tv_nsec;

    printf("%s() st_atime: %ld, %ld : st_ctime: %ld, %ld st_mtime: %ld, %ld\n", __func__, file_stat.st_atim.tv_sec - tstart.tv_sec, atime_in_micros,
           file_stat.st_ctim.tv_sec - tstart.tv_sec, ctime_in_micros,
           file_stat.st_mtim.tv_sec - tstart.tv_sec, mtime_in_micros);
}

/* msleep(): Sleep for the requested number of milliseconds. */
int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do
    {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

int main(int argc, char *argv[])
{
    clock_gettime(CLOCK_REALTIME, &tstart);

    page_size = getpagesize();
    size = pages * page_size;

    size_t system_page_size_ = page_size;
    size_t mapped_range = 2 * system_page_size_ + 300;
    size_t system_page_pot_shift_ = GetSystemPagePotShift();

    size_t total_pages = mapped_range >> system_page_pot_shift_;
    size_t last_segment_size = mapped_range & (system_page_size_ - 1);

    if (last_segment_size != 0)
    {
        ++total_pages;
    }

    printf("mapped_range: %zu\n", mapped_range);
    printf("system_page_pot_shift_: %zu\n", system_page_pot_shift_);
    printf("system_page_size_: %zu\n", system_page_size_);
    printf("total_pages: %zu\n", total_pages);
    printf("last_segment_size: %zu\n", last_segment_size);

    // for (int i = 0; i < 3; ++i)
    {
        int socket_fd = setup_client();
        if (socket_fd < 0)
        {
            LOGE("Client failed\n");
            exit(EXIT_FAILURE);
        }

        int fd = open(SHADOW_FILE_NAME, O_RDWR | O_CREAT, 0666);
        if (fd == -1)
        {
            printf("Error: open failed with error: %s", strerror(errno));
            if (errno == EEXIST)
            {
                fd = open(SHADOW_FILE_NAME, O_RDWR);
            }
        }

        if (fd == -1)
        {
            printf("failed opening file.bin %s\n", strerror(errno));
            return 0;
        }

        if (ftruncate(fd, size) == -1)
            perror("ftruncate");

        uint8_t *ref = malloc(pages * sizeof(uint8_t));

        void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (addr == MAP_FAILED)
            LOGE("mmap failed fd: %d %s\n", fd, strerror(errno));

        if (mlock(addr, size) == -1)
            printf("mlock failed (%s)\n", strerror(errno));

        // printf("memset\n");
        memset(addr, 0, size);
        msync(addr, size, MS_SYNC);

        // msleep(4000);
        // printf("created\n");
        print_timestamps(fd);

        // printf("rand\n");
        unsigned int ref_count = 0;
        {
            srand(time(0));
            uint8_t *c_p = addr;
            for (int p = 0; p < pages; ++p)
            {
                ref[p] = rand() % 2;
                if (ref[p])
                {
                    c_p[p * page_size] = 2;
                    c_p[p * page_size + page_size / 2] = 3;
                    ++ref_count;
                }
            }
        }

        print_timestamps(fd);

        // msleep(400);
        // printf("msync\n");
        // msync(addr, size, MS_SYNC);
        // print_timestamps(fd);

        // Send client information
        int n, block;
        int wrong;
        unsigned int count;
        while (1)
        {
            struct client_id_t client_id = {getpid(), addr, pages};
            n = write(socket_fd, &client_id, sizeof(client_id));
            assert(n == sizeof(client_id));

            uint8_t dirty;
            n = read(socket_fd, &dirty, sizeof(dirty));
            if (dirty)
            {
                uint8_t *page_status = malloc(pages * sizeof(uint8_t));
                assert(page_status);
                memset(page_status, 0, pages * sizeof(uint8_t));

                n = read(socket_fd, page_status, pages * sizeof(uint8_t));

                if (n < 0)
                {
                    printf("\n Read error \n");
                }

                wrong = 0;
                count = 0;
                for (int p = 0; p < pages; ++p)
                {
                    if (page_status[p] != ref[p])
                    {
                        wrong = 1;
                        // printf("  page %d: %u (ref: %u) %s\n", p, page_status[p], ref[p], page_status[p] != ref[p] ? " <-----" : "");
                    }

                    if (page_status[p])
                        ++count;

                    // printf("  page %d: %u (ref: %u) %s\n", p, page_status[p], ref[p], page_status[p] != ref[p] ? " <-----" : "");
                }

                printf("count: %u ref_count: %u\n", count, ref_count);

                if (wrong)
                    printf("Result is wrong\n");

                // if (file_is_modified(fd, timestamp))
                // {
                //     printf("File has been modified\n");
                // }

                free(page_status);
            }
            else
            {
                printf("No dirty pages!\n");
                // if (file_is_modified(fd, timestamp))
                // {
                //     printf("File has been modified\n");
                // }
            }

            print_timestamps(fd);

            scanf("%d", &block);
            if (block == 5)
            {
                msync(addr, size, MS_SYNC);

                printf("rand\n");
                ref_count = 0;
                {
                    uint8_t *c_p = addr;
                    for (int p = 0; p < pages; ++p)
                    {
                        ref[p] = rand() % 2;
                        if (ref[p])
                        {
                            c_p[p * page_size] = 2;
                            c_p[p * page_size + page_size / 2] = 3;
                            ++ref_count;
                        }
                    }
                }
                print_timestamps(fd);
            }
            if (block == 9)
                break;
        }

        if (munmap(addr, size) == -1)
            perror("munmap");

        struct client_id_t term_op = {-1, 0, 0};
        n = write(socket_fd, &term_op, sizeof(term_op));
        assert(n == sizeof(term_op));
        free(ref);

        close(fd);
    }

    return 0;
}
