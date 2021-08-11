#ifndef __NG_STD_QUEUE_H__
#define __NG_STD_QUEUE_H__
typedef ng_std_list_t ng_std_queue_t;
typedef ng_std_list_p ng_std_queue_p;

ng_std_queue_p ng_std_queue()
{
	ng_std_queue_p queue=ng_std_list();
	return queue;
}

void _ng_std_queue_(ng_std_queue_p queue)
{
	_ng_std_list_(queue);
}

void ng_std_queue_enqueue(ng_std_queue_p queue,ng_void_p value)
{
	ng_std_list_push(queue,value);
}

ng_void_p ng_std_queue_dequeue(ng_std_queue_p queue)
{
	if(!queue->head||!queue->head->next) return 0;
	ng_std_list_node_p head=queue->head;
	ng_void_p value=head->value;
	queue->head->next->previous=0;
	queue->head=queue->head->next;
	_ng_std_list_node_(head);
	return value;
}
#endif/*__NG_STD_QUEUE_H__*/