#ifndef __NG_GFX_VK_H__
#define __NG_GFX_VK_H__
#include <vulkan/vulkan.h>
#include "vk_t.h"

void ng_gfx_vk_init_application_info()
{
	g_ng_gfx.application_info.apiVersion=VK_API_VERSION_1_0;;
	g_ng_gfx.application_info.applicationVersion=VK_MAKE_VERSION(1,0,0);
	g_ng_gfx.application_info.engineVersion=VK_MAKE_VERSION(1,0,0);
	g_ng_gfx.application_info.pApplicationName="ng";
	g_ng_gfx.application_info.pEngineName="ng";
	g_ng_gfx.application_info.sType=VK_STRUCTURE_TYPE_APPLICATION_INFO;
}

ng_u8_t ng_gfx_vk_init_instance_info()
{
	ng_u32_t nextensions=0;
	vkEnumerateInstanceExtensionProperties(0,&nextensions,0);
	VkExtensionProperties extension_properties[nextensions];
	vkEnumerateInstanceExtensionProperties(0,&nextensions,extension_properties);

	g_ng_gfx.instance_create_info.sType=VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	g_ng_gfx.instance_create_info.pApplicationInfo=&g_ng_gfx.application_info;
	g_ng_gfx.instance_create_info.enabledExtensionCount=0;
	g_ng_gfx.instance_create_info.ppEnabledExtensionNames=0;
	g_ng_gfx.instance_create_info.enabledLayerCount=0;
	VkResult r=vkCreateInstance(&g_ng_gfx.instance_create_info,0,&g_ng_gfx.instance);
	return r==VK_SUCCESS;
}

void ng_gfx_vk_init()
{
	ng_gfx_vk_init_application_info();
	ng_gfx_vk_init_instance_info();
}

void ng_gfx_vk_deinit()
{
	vkDestroyInstance(g_ng_gfx.instance,0);
}
#endif/* __NG_GFX_VK_H__ */