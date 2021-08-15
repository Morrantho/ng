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
	VkResult result=vkCreateInstance(&g_ng_gfx.instance_create_info,0,&g_ng_gfx.instance);
	return result==VK_SUCCESS;
}

void ng_gfx_vk_validate_physical_device(VkPhysicalDevice physical_device)
{
	ng_u32_t n_queue_families=0;
	ng_u32_t feature_mask=VK_QUEUE_GRAPHICS_BIT;
	vkGetPhysicalDeviceQueueFamilyProperties(physical_device,&n_queue_families,0);
	VkQueueFamilyProperties queue_families[n_queue_families];
	vkGetPhysicalDeviceQueueFamilyProperties(physical_device,&n_queue_families,queue_families);
	for(ng_u32_t i=0;i<n_queue_families;i++)
	{
		ng_u32_t flags=queue_families[i].queueFlags;
		ng_u8_t has_features=flags&feature_mask;
		if(has_features)
		{
			g_ng_gfx.found_queue_family=1;
			g_ng_gfx.queue_family=i;
			return;
		}
	}
}

void ng_gfx_vk_init_physical_device()
{
	ng_u32_t n_physical_devices=0;
	vkEnumeratePhysicalDevices(g_ng_gfx.instance,&n_physical_devices,0);
	if(!n_physical_devices) return;
	VkPhysicalDevice physical_devices[n_physical_devices];
	vkEnumeratePhysicalDevices(g_ng_gfx.instance,&n_physical_devices,physical_devices);
	for(ng_u32_t i=0;i<n_physical_devices;i++)
	{
		ng_gfx_vk_validate_physical_device(physical_devices[i]);
		if(g_ng_gfx.found_queue_family)
		{
			g_ng_gfx.physical_device=physical_devices[i];
			return;
		}
	}
}

ng_u8_t ng_gfx_vk_init_queue_create_info()
{
	g_ng_gfx.queue_create_info.sType=VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	g_ng_gfx.queue_create_info.queueFamilyIndex=g_ng_gfx.queue_family;
	g_ng_gfx.queue_create_info.queueCount=1;
	g_ng_gfx.queue_create_info.pQueuePriorities=&g_ng_gfx.queue_priority;
	return 0;
}

void ng_gfx_vk_init_device_create_info()
{
	VkPhysicalDeviceFeatures physical_device_features={0};
	g_ng_gfx.device_create_info.sType=VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	g_ng_gfx.device_create_info.pQueueCreateInfos=&g_ng_gfx.queue_create_info;
	g_ng_gfx.device_create_info.queueCreateInfoCount=1;
	g_ng_gfx.device_create_info.pEnabledFeatures=&physical_device_features;
	g_ng_gfx.device_create_info.enabledExtensionCount=0;
}

ng_u8_t ng_gfx_vk_init_device()
{
	ng_gfx_vk_init_queue_create_info();
	ng_gfx_vk_init_device_create_info();
	ng_u8_t result=vkCreateDevice(g_ng_gfx.physical_device,&g_ng_gfx.device_create_info,0,&g_ng_gfx.device);
	vkGetDeviceQueue(g_ng_gfx.device,g_ng_gfx.queue_family,0,&g_ng_gfx.graphics_queue);
	return result==VK_SUCCESS;
}

void ng_gfx_vk_init()
{
	ng_gfx_vk_init_application_info();
	ng_gfx_vk_init_instance_info();
	ng_gfx_vk_init_physical_device();
	ng_gfx_vk_init_device();
}

void ng_gfx_vk_deinit()
{
	vkDestroyDevice(g_ng_gfx.device,0);
	vkDestroyInstance(g_ng_gfx.instance,0);
}
#endif/* __NG_GFX_VK_H__ */