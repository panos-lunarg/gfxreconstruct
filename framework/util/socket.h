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

#ifndef GFXRECON_UTIL_SOCKET_H
#define GFXRECON_UTIL_SOCKET_H

#include "util/defines.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if !defined(WIN32)
class Socket
{
  public:
    enum SocketType
    {
        kLocalSocket,
        kNetworkSocket
    };

    bool       IntializeAsServer(SocketType         type,
                                 const std::string& address = std::string(),
                                 const std::string& port    = std::string());
    bool       IntializeAsClient(SocketType         type,
                                 const std::string& address = std::string(),
                                 const std::string& port    = std::string());
    int        Send(const void* data, size_t size);
    int        Receive(void* data, size_t size);
    void       Terminate();
    bool       IsActive() const { return socket_ != 0; }
    SocketType GetType() const { return type_; }

  private:
    int        socket_ = 0;
    SocketType type_;
    bool       is_server_ = false;
};

#else

class Socket
{
  public:
    enum SocketType
    {
        kLocalSocket,
        kNetworkSocket
    };

    bool IntializeAsServer(SocketType         type,
                           const std::string& address = std::string(),
                           const std::string& port    = std::string())
    {
        return false;
    }

    bool IntializeAsClient(SocketType         type,
                           const std::string& address = std::string(),
                           const std::string& port    = std::string())
    {
        return false;
    }

    int        Send(const void* data, size_t size) { return -1; }
    int        Receive(void* data, size_t size) { return -1; }
    void       Terminate();
    bool       IsActive() const { return false; }
    SocketType GetType() const { return SocketType(0); }
};

#endif

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)

#endif /* GFXRECON_UTIL_SOCKET_H */