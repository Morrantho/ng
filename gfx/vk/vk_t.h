#ifndef __NG_GFX_VK_T_H__
#define __NG_GFX_VK_T_H__
struct
{
	VkApplicationInfo application_info;
	VkInstanceCreateInfo instance_create_info;
	VkDeviceQueueCreateInfo queue_create_info;
	VkDeviceCreateInfo device_create_info;

	VkInstance instance;
	ng_u8_t found_queue_family;
	ng_u32_t queue_family;
	ng_f32_t queue_priority;
	VkPhysicalDevice physical_device;
	VkDevice device;
	VkQueue graphics_queue;
}static g_ng_gfx=
{
	.application_info={0},
	.instance_create_info={0},
	.queue_create_info={0},
	.device_create_info={0},

	.instance=0,
	.queue_family=0,
	.found_queue_family=0,
	.queue_priority=1.0,
	.physical_device=VK_NULL_HANDLE,
	.device=VK_NULL_HANDLE,
	.graphics_queue=VK_NULL_HANDLE
};
#endif/* __NG_GFX_VK_T_H__ */