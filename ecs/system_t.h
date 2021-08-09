#ifndef __NG_ECS_SYSTEM_H__
#define __NG_ECS_SYSTEM_H__
typedef void (*ng_ecs_system_fn_p)(ng_u64_t);
typedef struct ng_ecs_system_t
{
	ng_u8_t entities[NG_ECS_ENTITY_MAX];/* bool array */
	ng_u64_t mask;
	ng_ecs_system_fn_p run;
}ng_ecs_system_t,*ng_ecs_system_p;
#endif/*__NG_ECS_SYSTEM_H__*/