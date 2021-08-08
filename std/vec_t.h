#ifndef __NG_STD_VEC_T_H__
#define __NG_STD_VEC_T_H__
/* Where the hell did the source to this go? Guess we're rewriting this when we need it. */
#ifndef NG_STD_VEC_MAX
#define NG_STD_VEC_MAX 32
#endif

typedef struct ng_std_vec_t
{
	ng_void_p2 data;
	ng_u16_t size;
	ng_u16_t capacity;
}ng_std_vec_t,*ng_std_vec_p;

void ng_std_vec_init(register ng_std_vec_p v)
{
	v->data=ng_mem_calloc(sizeof(ng_void_p)*NG_STD_VEC_MAX);
	v->capacity=NG_STD_VEC_MAX;
	v->size=0;
}

void ng_std_vec_deinit(register ng_std_vec_p v)
{
	ng_mem_free(v->data);
	v->data=0;
	v->capacity=0;
	v->size=0;
}

ng_std_vec_p ng_std_vec()
{
	register ng_std_vec_p v=ng_mem_alloc(sizeof(ng_std_vec_t));
	ng_std_vec_init(v);
	return v;
}

void ng_std_vec_del(register ng_std_vec_p v)
{
	ng_std_vec_deinit(v);
	ng_mem_free(v);
}

void ng_std_vec_resize(register ng_std_vec_p v,register ng_i8_t dir)
{

}

void ng_std_vec_push(register ng_std_vec_p v,register ng_void_p v2)
{

}

ng_void_p ng_std_vec_pop(register ng_std_vec_p v)
{
	return 0;
}
#endif//__NG_STD_VEC_T_H__