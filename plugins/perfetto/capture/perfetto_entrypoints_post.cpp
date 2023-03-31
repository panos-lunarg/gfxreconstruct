#include "includes/capture/entrypoints_post.h"
#include "perfetto_encoder_commands.h"
#include "format/api_call_id.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(capture)
GFXRECON_BEGIN_NAMESPACE(plugin_perfetto)

extern "C" {
VKAPI_ATTR VkResult VKAPI_CALL CreateInstance_PostCall(encode::VulkanCaptureManager* manager, VkResult result, const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
{
PerfettoEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(manager, result, pCreateInfo, pAllocator, pInstance);
return result;
}
} // extern "C"

GFXRECON_END_NAMESPACE(plugin_perfetto)
GFXRECON_END_NAMESPACE(capture)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)
