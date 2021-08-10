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
#endif/*__NG_STD_QUEUE_H__*/