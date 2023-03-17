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

#ifndef GFXRECON_UTIL_FILE_STREAMER_H
#define GFXRECON_UTIL_FILE_STREAMER_H

#include "defines.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "socket.h"

#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class FileStreamer
{
  public:
    bool Initialize(const std::string& filename, const std::string& ip, const std::string& port);
    bool StreamFile();

  private:
    size_t ReadBytes(void* buffer, size_t buffer_size);
    bool   IsFileValid() const { return (file_descriptor_ && !feof(file_descriptor_) && !ferror(file_descriptor_)); }

    FILE*                file_descriptor_ = nullptr;
    size_t               bytes_read_      = 0;
    std::string          filename_;
    Socket               socket;
    std::vector<uint8_t> internal_buffer_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)

#endif /* GFXRECON_UTIL_FILE_STREAMER_H */
