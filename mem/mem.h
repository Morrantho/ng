#ifndef __NG_MEM_H__
#define __NG_MEM_H__
#include <stdlib.h>
#include "size.h"
#include "pool_t.h"

void ng_mem_init()
{
}

void ng_mem_deinit()
{
}

void ng_mem_fill(register ng_void_p block,register ng_u16_t bytes,register ng_i8_t data)
{
	ng_u16_t i;
	for(i=0;i<bytes;i++) *(ng_i8_p)(block+i)=data;
}

void ng_mem_copy(register ng_void_p from,register ng_u16_t bytes,register ng_void_p to)
{
	ng_u16_t i;
	for(i=0;i<bytes;i++) *(ng_i8_p)(to+i)=*(ng_i8_p)(from+i);
}

static ng_u64_t ng_mem_probe(register ng_mem_pool_p pool,register ng_mem_pool_t pool_index,register ng_u16_t bytes)
{
	register ng_u64_t index=pool_index;
	register ng_u64_t found=0;
	register ng_u64_t skip=0;
	while(found<bytes)
	{
		register ng_u64_t addr=(ng_u64_t)pool+index;
		register ng_u64_t reserved=*(ng_u64_p)addr;
		skip=reserved?reserved:8;
		found+=reserved?-found:skip;
		index+=skip;
	}
	return index-found;
}

ng_void_p ng_mem_alloc(register ng_mem_pool_p pool,register ng_u64_t pool_index,register ng_u64_t bytes)
{
	register ng_u64_t total=bytes+8;
	register ng_u64_t i=ng_mem_probe(pool,pool_index,total);
	register ng_u64_t addr=(ng_u64_t)pool+i;
	*(ng_u64_p)addr=total;
	pool_index=i+total;
	return (ng_void_p)addr+8;
}

ng_void_p ng_mem_calloc(register ng_mem_pool_p pool,register ng_u64_t pool_index,register ng_u64_t bytes)
{
	register ng_void_p block=ng_mem_alloc(pool,pool_index,bytes);/* this comes back past the header */
	ng_mem_fill(block,bytes,0);/* so just zero it */
	return block;
}

ng_void_p ng_mem_resize(register ng_mem_pool_p pool,register ng_u64_t pool_index,register ng_void_p old_block,register ng_u64_t new_bytes)
{
	register ng_u64_t old_start=(ng_u64_t)old_block-8;/* header */
	register ng_u64_t old_bytes=*(ng_u64_p)old_start;/* includes pointer size */
	if(new_bytes<old_bytes-8)/* shrink */
	{
		*(ng_u64_p)(old_start)=new_bytes+8;/* Even if 0, we still need this to be a header. */
		return old_block;
	}
	register ng_u64_t diff=new_bytes-(old_bytes-8);
	register ng_u64_t old_end=old_start+old_bytes;
	register ng_u64_t old_mem_ptr=pool_index;/* store if we need to revert */
	pool_index=old_end-(ng_u64_t)pool;/* try to probe from old_block end */
	register ng_u64_t i=ng_mem_probe(pool,pool_index,diff);/* we only need to grow by this much */
	if(i==pool_index)/* we can reserve contiguously, so we're done. */
	{
		pool_index+=diff;/* make next alloc start from here. */
		*(ng_u64_p)(old_start)+=diff;/* add byte difference to old block header. */
		return old_block;
	}
	pool_index=old_mem_ptr;/* revert, another block is right after this block. */
	return 0;
}

void ng_mem_free(register ng_mem_pool_p pool,register ng_u64_t pool_index,register ng_void_p block)
{
	register ng_u64_t start=(ng_u64_t)block-8;
	register ng_u64_t end=start+*(ng_u64_p)start;
	*(ng_u64_p)(start)=0;/* no point in mem_fill()'ing, just 0 header size */
	pool_index=end-(ng_u64_t)pool;/* get back to an index that probe() understands. */
}

ng_void_p ng_mem_realloc(register ng_mem_pool_p pool,register ng_u64_t pool_index,register ng_void_p old_block,register ng_u64_t new_bytes)
{
	if(ng_mem_resize(pool,pool_index,old_block,new_bytes)) return old_block;
	register ng_u64_t old_start=(ng_u64_t)old_block-8;
	register ng_u64_t old_bytes=*(ng_u64_p)old_start;
	register ng_void_p new_block=ng_mem_alloc(pool,pool_index,new_bytes);
	ng_mem_copy(old_block,old_bytes-8,new_block);
	ng_mem_free(pool,pool_index,old_block);
	return new_block;
}
#endif/* __NG_MEM_H__ */