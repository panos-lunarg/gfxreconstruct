/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "replay_settings.h"

#include "application/application.h"
#include "decode/file_processor.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_frame_inspector_consumer_client.h"
#include "util/argument_parser.h"
#include "util/file_streamer.h"
#include "util/logging.h"
#include "util/socket.h"

#include <exception>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

#if defined(WIN32)
#include <conio.h>
void WaitForExit()
{
    DWORD process_list[2];
    DWORD result = GetConsoleProcessList(process_list, ARRAYSIZE(process_list));

    // If the process list contains a single entry, we assume that the console was created when the gfxrecon-replay.exe
    // process started, and will be destroyed when it exits.  In this case, we will wait on user input before exiting
    // and closing the console window to give the user a chance to read any console output.
    if (result <= 1)
    {
        GFXRECON_WRITE_CONSOLE("\nPress any key to close this window . . .");
        while (!_kbhit())
        {
            Sleep(250);
        }
    }
}
#else
void WaitForExit() {}
#endif

const char kLayerEnvVar[] = "VK_INSTANCE_LAYERS";

int main(int argc, const char** argv)
{
    int return_code = 0;

    // Default initialize logging to report issues while loading settings.
    gfxrecon::util::Log::Init(gfxrecon::decode::kDefaultLogLevel);

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintVersion(argv[0], arg_parser) || CheckOptionPrintUsage(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else
    {
        ProcessDisableDebugPopup(arg_parser);
    }

    // Reinitialize logging with values retrieved from command line arguments
    gfxrecon::util::Log::Settings log_settings;
    GetLogSettings(arg_parser, log_settings);
    gfxrecon::util::Log::Release();
    gfxrecon::util::Log::Init(log_settings);

    try
    {
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        std::string                     filename             = positional_arguments[0];
        gfxrecon::util::Socket          socket;

        socket.IntializeAsClient(gfxrecon::util::Socket::kNetworkSocket, "localhost", "3490");
        gfxrecon::util::FileStreamer streamer;
        streamer.Initialize(filename, &socket);

        while (streamer.StreamFile())
        {}

        gfxrecon::decode::FileProcessor file_processor;
        if (!file_processor.Initialize(filename))
        {
            return_code = -1;
        }
        else
        {
            auto application = std::make_shared<gfxrecon::application::Application>(kApplicationName, &file_processor);

            gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
            gfxrecon::decode::VulkanReplayOptions          vulkan_replay_options =
                GetVulkanReplayOptions(arg_parser, filename, &tracked_object_info_table);

            gfxrecon::decode::VulkanFrameInspectorConsumerClient vulkan_frame_inspector(vulkan_replay_options);
            gfxrecon::decode::VulkanDecoder                      vulkan_decoder;

            vulkan_decoder.AddConsumer(&vulkan_frame_inspector);
            file_processor.AddDecoder(&vulkan_decoder);
            application->SetConsumer(&vulkan_frame_inspector);

            vulkan_frame_inspector.GetIndirectCommandParamsOverSocket(socket);

            application->Run();
        }
    }
    catch (std::runtime_error error)
    {
        GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        return_code = -1;
    }
    catch (const std::exception& error)
    {
        GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        return_code = -1;
    }
    catch (...)
    {
        GFXRECON_WRITE_CONSOLE("Replay failed due to an unhandled exception");
        return_code = -1;
    }

    WaitForExit();

    gfxrecon::util::Log::Release();

    return return_code;
}
