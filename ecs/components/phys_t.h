#ifndef __NG_ECS_COMPONENT_PHYS_H__
#define __NG_ECS_COMPONENT_PHYS_H__
typedef struct ng_ecs_component_phys_t
{
	ng_u8_t frozen;
	ng_f64_t bounce;
	ng_f64_t drag;
	ng_f64_t friction;
	ng_f64_t imass;
	ng_f64_t acceleration[2];
	ng_f64_t gravity[2];
	ng_f64_t velocity[2];
}ng_ecs_component_phys_t,*ng_ecs_component_phys_p;
#endif/*__NG_ECS_COMPONENT_PHYS_H__*/