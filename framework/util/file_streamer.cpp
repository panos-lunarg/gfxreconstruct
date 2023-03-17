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

#include "file_streamer.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

bool FileStreamer::Initialize(const std::string& filename, Socket* socket)
{
    int32_t result = util::platform::FileOpen(&file_descriptor_, filename.c_str(), "rb");

    if ((result == 0) && (file_descriptor_ != nullptr))
    {
        filename_ = filename;
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to open file %s", filename.c_str());
        return false;
    }

    assert(socket);
    socket_ = socket;

    return true;
}

size_t FileStreamer::ReadBytes(void* buffer, size_t buffer_size)
{
    assert(file_descriptor_);

    size_t bytes_read = util::platform::FileRead(buffer, 1, buffer_size, file_descriptor_);
    bytes_read_ += bytes_read;

    return bytes_read;
}

bool FileStreamer::StreamFile()
{
    while (true)
    {
        const size_t size = 1024;
        internal_buffer_.resize(size);

        size_t bytes_read = ReadBytes(internal_buffer_.data(), size);
        if (!bytes_read)
        {
            if (!IsFileValid())
            {
                GFXRECON_WRITE_CONSOLE("FileStreamer::StreamFile(): EOF!\n");

                assert(socket_);
                format::BlockHeader block_header{};
                socket_->Send(&block_header, sizeof(block_header));
                // socket_->Terminate();
                return false;
            }
        }

        int ret = socket_->Send(internal_buffer_.data(), bytes_read);
    }

    return true;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(util)
