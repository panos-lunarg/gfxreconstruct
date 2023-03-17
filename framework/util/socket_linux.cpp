/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>

#include "util/logging.h"
#include "util/defines.h"
#include "util/socket.h"

#if defined(WIN32)
#error "This file should be compiled for Unix only"
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#define SOCKET_NAME "GFXRECON_SOCKET"
#define DEFAULT_IP "localhost"
#define DEFAULT_PORT "3490"

static void* get_in_addr(struct sockaddr* sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

bool Socket::IntializeAsServer(SocketType type, const std::string& address, const std::string& port)
{
    int ret, socket_fd;

    type_ = type;

    if (type == kNetworkSocket)
    {
        GFXRECON_WRITE_CONSOLE("Initializing Server Network socket");

        struct addrinfo hints, *res = nullptr;

        memset(&hints, 0, sizeof(hints));
        hints.ai_family   = PF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags    = AI_PASSIVE;

        const char* ip_str = address.size() ? address.c_str() : DEFAULT_IP;
        const char* p_str  = port.size() ? port.c_str() : DEFAULT_PORT;

        GFXRECON_WRITE_CONSOLE("  address: %s port: %s", ip_str, p_str);

        if ((ret = getaddrinfo(ip_str, p_str, &hints, &res)) != 0)
        {
            GFXRECON_LOG_ERROR("Error Server getaddrinfo(): %s\n", gai_strerror(ret));
            return false;
        }

        socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (socket_fd < 0)
        {
            GFXRECON_LOG_ERROR("Error Server socket(): %s\n", strerror(errno));
            return false;
        }

        ret = bind(socket_fd, res->ai_addr, res->ai_addrlen);

        freeaddrinfo(res);
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("Initializing Server local socket");

        socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (socket_fd < 0)
        {
            GFXRECON_LOG_ERROR("Error Server socket: %s\n", strerror(errno));
            return false;
        }

        // bind it to the port we passed in to getaddrinfo():
        char socket_name[108];
        memcpy(&socket_name[0], "\0", 1);
        strcpy(&socket_name[1], SOCKET_NAME);

        struct sockaddr_un server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sun_family = AF_UNIX;
        strncpy(server_addr.sun_path, socket_name, sizeof(server_addr.sun_path) - 1); // 108 char max

        ret = bind(socket_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    }

    if (ret < 0)
    {
        GFXRECON_LOG_ERROR("Error Server bind(): %s\n", strerror(errno));
        return false;
    }

    ret = listen(socket_fd, 1);
    if (ret < 0)
    {
        GFXRECON_LOG_ERROR("Error Server listen(): %s\n", strerror(errno));
        return false;
    }

    GFXRECON_WRITE_CONSOLE("Server socket setup complete. Waiting for client...\n");

    struct sockaddr_storage their_addr;
    socklen_t               sin_size = sizeof(their_addr);
    socket_                          = accept(socket_fd, (struct sockaddr*)&their_addr, &sin_size);

    if (socket_ < 0)
    {
        GFXRECON_LOG_ERROR("Error: Server accept(): %s\n", strerror(errno));
        return false;
    }

    close(socket_fd);

    char s[INET6_ADDRSTRLEN];
    inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr*)&their_addr), s, sizeof(s));

    GFXRECON_WRITE_CONSOLE("Client connected from %s\n", s);

    is_server_ = true;

    return true;
}

bool Socket::IntializeAsClient(SocketType type, const std::string& address, const std::string& port)
{
    int ret, socket_fd;

    type_ = type;

    if (type == kNetworkSocket)
    {
        GFXRECON_WRITE_CONSOLE("Initializing Client Network socket");

        struct addrinfo hints, *servinfo, *p;
        int             ret;

        memset(&hints, 0, sizeof hints);
        hints.ai_family   = PF_INET;
        hints.ai_socktype = SOCK_STREAM;

        const char* ip_str = address.size() ? address.c_str() : DEFAULT_IP;
        const char* p_str  = port.size() ? port.c_str() : DEFAULT_PORT;

        GFXRECON_WRITE_CONSOLE("  address: %s port: %s", ip_str, p_str);

        if ((ret = getaddrinfo(ip_str, p_str, &hints, &servinfo)) != 0)
        {
            GFXRECON_LOG_ERROR("Error Client getaddrinfo(): %s\n", gai_strerror(ret));
            return false;
        }

        // loop through all the results and connect to the first we can
        for (p = servinfo; p != NULL; p = p->ai_next)
        {
            if ((socket_ = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
            {
                GFXRECON_LOG_ERROR("Error Client socket(): %s", strerror(errno));
                continue;
            }

            if (connect(socket_, p->ai_addr, p->ai_addrlen) == -1)
            {
                close(socket_);
                GFXRECON_LOG_ERROR("Error client connect(): %s", strerror(errno));
                continue;
            }

            break;
        }

        if (p == NULL)
        {
            GFXRECON_LOG_ERROR("client: failed to connect");
            freeaddrinfo(servinfo);
            return false;
        }

        freeaddrinfo(servinfo);
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("Initializing Client Local socket");

        socket_ = socket(type == kLocalSocket ? AF_UNIX : AF_INET6, SOCK_STREAM, 0);
        if (socket_ < 0)
        {
            GFXRECON_LOG_ERROR("Error client socket: %s\n", strerror(errno));
            return false;
        }

        char socket_name[108];
        memcpy(&socket_name[0], "\0", 1);
        strcpy(&socket_name[1], SOCKET_NAME);

        struct sockaddr_un server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sun_family = AF_UNIX;
        strncpy(server_addr.sun_path, socket_name, sizeof(server_addr.sun_path) - 1);

        int ret = connect(socket_, (const struct sockaddr*)&server_addr, sizeof(server_addr));
        if (ret < 0)
        {
            GFXRECON_LOG_ERROR("Client Error connect(): %s\n", strerror(errno));
            return false;
        }
    }

    GFXRECON_WRITE_CONSOLE("%s() Client socket setup complete\n", __func__);

    is_server_ = false;

    return true;
}

int Socket::Send(const void* data, size_t size)
{
    assert(socket_);
    assert(data);
    assert(size);

    int ret;
    int attempts = 0;

    while ((ret = send(socket_, data, size, 0)) == -1)
    {
        if (ret == -1)
        {
            GFXRECON_LOG_ERROR("%s Error send(): %s", (is_server_ ? "Server" : "Client"), strerror(errno));
            ++attempts;
        }

        if (attempts == 10)
        {
            GFXRECON_LOG_ERROR(
                "%s Socket send() failed %d times. Abording.", (is_server_ ? "Server" : "Client"), attempts);
            return -1;
        }
    }

    assert(static_cast<size_t>(ret) == size);

    return ret;
}

int Socket::Receive(void* data, size_t size)
{
    assert(socket_);
    assert(data);
    assert(size);

    int ret;
    int attempts = 0;

    while ((ret = recv(socket_, data, size, 0)) == -1)
    {
        if (ret == -1)
        {
            GFXRECON_LOG_ERROR("%s Error recv(): %s", (is_server_ ? "Server" : "Client"), strerror(errno));
            ++attempts;
        }

        if (attempts == 10)
        {
            GFXRECON_LOG_ERROR(
                "%s Socket recv() failed %d times. Abording.", (is_server_ ? "Server" : "Client"), attempts);
            return -1;
        }
    }

    assert(static_cast<size_t>(ret) == size);
    return ret;
}

void Socket::Terminate()
{
    assert(socket_);

    close(socket_);
    socket_ = 0;

    GFXRECON_WRITE_CONSOLE("%s socket closed", is_server_ ? "Server" : "Client");
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)
