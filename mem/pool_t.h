#ifndef __NG_MEM_POOL_H__
#define __NG_MEM_POOL_H__
typedef struct ng_mem_pool_t
{
	ng_u8_p mem;
	ng_u64_t index;
}ng_mem_pool_t,*ng_mem_pool_p;

ng_mem_pool_p ng_mem_pool(ng_u64_t bytes)
{
	ng_mem_pool_p pool=malloc(sizeof(ng_mem_pool_t));
	pool->mem=malloc(bytes);
	pool->index=0;
	return pool;
}

void _ng_mem_pool_(ng_mem_pool_p pool)
{
	free(pool->mem);
	free(pool);
}
#endif/*__NG_MEM_POOL_H__*/