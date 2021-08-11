#ifndef __NG_ECS_T_H__
#define __NG_ECS_T_H__
struct
{
	ng_u64_t entities[NG_ECS_ENTITY_MAX];/* Masks are 32/64bit wide */
	#undef X
	#define X(A,B,C) B C[NG_ECS_ENTITY_MAX];
	NG_ECS_COMPONENTS
	ng_ecs_system_t systems[NG_ECS_SYSTEM_MAX];
}static g_ng_ecs=
{
	.entities={0},
	.systems={0},
	#undef  X
	#define X(A,B,C) .C={0},
	NG_ECS_COMPONENTS
};
#endif/*__NG_ECS_T_H__*/