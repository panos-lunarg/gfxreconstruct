#include "includes/replay/entrypoints_post.h"
#include "perfetto_replay_commands.h"
#include "format/api_call_id.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(replay)
GFXRECON_BEGIN_NAMESPACE(plugin_perfetto)

extern "C" {
VKAPI_ATTR void VKAPI_CALL CreateInstance_PostCall(VulkanReplayConsumerBase* consumer, const ApiCallInfo& call_info, VkResult returnValue, StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo, StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator, HandlePointerDecoder<VkInstance>* pInstance)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(consumer, call_info, returnValue, pCreateInfo, pAllocator, pInstance);
}
} // extern "C"

GFXRECON_END_NAMESPACE(plugin_perfetto)
GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)
