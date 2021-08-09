#ifndef __NG_GFX_VK_T_H__
#define __NG_GFX_VK_T_H__
struct
{
	VkInstance instance;
	VkApplicationInfo application_info;
	VkInstanceCreateInfo instance_create_info;
}static ng_gfx=
{
	.instance=0,
	.application_info={0},
	.instance_create_info={0}
};
#endif/* __NG_GFX_VK_T_H__ */