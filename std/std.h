#ifndef __NG_STD_H__
#define __NG_STD_H__
static ng_mem_pool_p ng_std_pool=0;
#include "stack_t.h"
#include "list_t.h"
#include "queue_t.h"
#include "str.h"
#include "vec_t.h"
#include "simd.h"

void ng_std_init()
{
	ng_std_pool=ng_mem_pool(NG_MEM_MB*128);
}

void ng_std_deinit()
{
	_ng_mem_pool_(ng_std_pool);
}
#endif/* __NG_STD_H__ */