#ifndef __NG_STD_H__
#define __NG_STD_H__
static ng_mem_pool_t ng_std_pool[NG_MEM_MB*128]={0};
static ng_u64_t ng_std_pool_index=0;
#include "stack_t.h"
#include "list_t.h"
#include "queue_t.h"
#include "string.h"
#include "vec_t.h"
#include "vecn_t.h"
#include "simd.h"
#endif/* __NG_STD_H__ */