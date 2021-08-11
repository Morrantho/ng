#ifndef __NG_STD_VEC_H__
#define __NG_STD_VEC_H__
#ifndef NG_STD_VEC_MAX
#define NG_STD_VEC_MAX 32
#endif

typedef struct ng_std_vec_t
{
	ng_void_p2 data;
	ng_u16_t size;
	ng_u16_t capacity;
}ng_std_vec_t,*ng_std_vec_p;

void ng_std_vec_init(register ng_std_vec_p vec)
{
	vec->data=ng_mem_calloc(ng_std_pool,ng_std_pool_index,sizeof(ng_void_p)*NG_STD_VEC_MAX);
	vec->capacity=NG_STD_VEC_MAX;
	vec->size=0;
}

void ng_std_vec_deinit(register ng_std_vec_p vec)
{
	ng_mem_free(ng_std_pool,ng_std_pool_index,vec->data);
	vec->data=0;
	vec->capacity=0;
	vec->size=0;
}

ng_std_vec_p ng_std_vec()
{
	register ng_std_vec_p vec=ng_mem_alloc(ng_std_pool,ng_std_pool_index,sizeof(ng_std_vec_t));
	ng_std_vec_init(vec);
	return vec;
}

void _ng_std_vec_(register ng_std_vec_p vec)
{
	ng_std_vec_deinit(vec);
	ng_mem_free(ng_std_pool,ng_std_pool_index,vec);
}

void ng_std_vec_resize(register ng_std_vec_p vec,register ng_i8_t dir)
{
	vec->capacity+=NG_STD_VEC_MAX*dir;
	vec->data=ng_mem_realloc(ng_std_pool,ng_std_pool_index,vec->data,sizeof(ng_void_p)*vec->capacity);
}

void ng_std_vec_push(register ng_std_vec_p vec,register ng_void_p value)
{
	if(vec->size+1>vec->capacity) ng_std_vec_resize(vec,1);
	vec->data[vec->size++]=value;
}

ng_void_p ng_std_vec_pop(register ng_std_vec_p vec)
{
	vec->size--;
	ng_void_p value=vec->data[vec->size];
	if(vec->size!=0&&vec->size<=(vec->capacity-NG_STD_VEC_MAX))
	{
		ng_std_vec_resize(vec,-1);
	}
	else
	{
		vec->data[vec->size]=0;
	}
	return value;
}
#endif/* __NG_STD_VEC_H__ */