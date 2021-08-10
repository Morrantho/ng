#ifndef __NG_STD_LIST_H__
#define __NG_STD_LIST_H__

typedef struct ng_std_list_node_t ng_std_list_node_t,*ng_std_list_node_p;

struct ng_std_list_node_t
{
	ng_std_list_node_p next;
	ng_std_list_node_p previous;
	ng_void_p value;
};

typedef struct ng_std_list_t
{
	ng_std_list_node_p head;
	ng_std_list_node_p tail;
}ng_std_list_t,*ng_std_list_p;

ng_std_list_node_p ng_std_list_node(ng_void_p value)
{
	ng_std_list_node_p node=ng_mem_alloc(ng_std_pool,ng_std_pool_index,sizeof(ng_std_list_node_t));
	node->next=0;
	node->previous=0;
	node->value=value;
	return node;
}

void _ng_std_list_node_(ng_std_list_node_p node)
{
	ng_mem_free(ng_std_pool,ng_std_pool_index,node);
}

ng_std_list_p ng_std_list()
{
	ng_std_list_p list=ng_mem_alloc(ng_std_pool,ng_std_pool_index,sizeof(ng_std_list_t));
	list->head=0;
	list->tail=0;
	return list;
}

void _ng_std_list_(ng_std_list_p list)
{
	ng_std_list_node_p tail=list->tail;
	ng_std_list_node_p last=tail;
	while(tail)
	{
		last=tail;
		tail=tail->previous;
		_ng_std_list_node_(last);
	}
	ng_mem_free(ng_std_pool,ng_std_pool_index,list);
}
#endif/*__NG_STD_LIST_H__*/