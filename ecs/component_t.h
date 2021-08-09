#ifndef __NG_ECS_COMPONENT_H__
#define __NG_ECS_COMPONENT_H__
typedef enum ng_ecs_component_t
{
	#define X(A,B,C) A,
	NG_ECS_COMPONENTS
}ng_ecs_component_t,*ng_ecs_component_p;
#endif/*__NG_ECS_COMPONENT_H__*/