#ifndef __NG_STD_STACK_H__
#define __NG_STD_STACK_H__

typedef struct ng_std_stack_t ng_std_stack_t,*ng_std_stack_p,**ng_std_stack_p2;

struct ng_std_stack_t
{
	ng_std_stack_p next;
	ng_void_p value;
};

ng_std_stack_p ng_std_stack(register ng_void_p v)
{
	register ng_std_stack_p s=ng_mem_alloc(ng_std_pool,ng_std_pool_index,sizeof(ng_std_stack_t));
	s->next=0;
	s->value=v;
	return s;
}

void ng_std_stack_del(ng_std_stack_p2 s)
{
	if(!*s) return;
	ng_std_stack_del(&(*s)->next);
	ng_mem_free(ng_std_pool,ng_std_pool_index,*s);
}

void ng_std_stack_push(ng_std_stack_p2 s,ng_void_p v)
{
	ng_std_stack_p top=*s;
	*s=ng_std_stack(v);
	(*s)->next=top;
}

ng_void_p ng_std_stack_pop(ng_std_stack_p2 s)
{
	ng_std_stack_p top=*s;
	ng_void_p value=top->value;
	*s=(*s)->next;
	ng_mem_free(ng_std_pool,ng_std_pool_index,top);
	return value;
}
#endif/* __NG_STD_STACK_H__ */