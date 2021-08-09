#ifndef __NG_ECS_COMPONENT_POLY_H__
#define __NG_ECS_COMPONENT_POLY_H__
typedef struct ng_ecs_component_poly_t
{
	ng_std_vec_t points;
	ng_std_vec_t edges;
}ng_ecs_component_poly_t,*ng_ecs_component_poly_p;
#endif/*__NG_ECS_COMPONENT_POLY_H__*/