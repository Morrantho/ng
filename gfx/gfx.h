#ifndef __NG_GFX_H__
#define __NG_GFX_H__
#include "vk/vk.h"

void ng_gfx_init()
{
	/* todo: abstract picking an api. just vk for now. */
	ng_gfx_vk_init();
}

void ng_gfx_think()
{
	
}

void ng_gfx_deinit()
{
	ng_gfx_vk_deinit();
}
#endif/* __NG_GFX_H__ */