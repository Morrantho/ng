#ifndef __NG_ECS_H__
#define __NG_ECS_H__
#define NG_ECS_ENTITY_MAX 1<<16/* 65k for now */
#define NG_ECS_COMPONENT_MAX 1<<6/* must be 32/64 bit */
#define NG_ECS_SYSTEM_MAX 1<<5/* prolly no more than 255 */
#ifndef NG_ECS_COMPONENTS
#define NG_ECS_COMPONENTS\
	X(NG_ECS_NCMP,ng_u8_t,spare)
#endif
#include "entity_t.h"
#include "component_t.h"
#include "system_t.h"
#include "ecs_t.h"

void ng_ecs_init()
{
	
}

ng_ecs_entity_t ng_ecs_entity()
{
	ng_ecs_entity_t e;
	for(e=0;e<NG_ECS_ENTITY_MAX;e++)
	{
		if(!ng_ecs.entities[e])
		{
			return e;
		}
	}
	return NG_ECS_ENTITY_MAX-1;
}

void ng_ecs_system(register ng_u64_t mask,register ng_ecs_system_fn_p fn)
{
	static ng_u8_t system_id=0;
	ng_ecs.systems[system_id].mask=mask;
	ng_ecs.systems[system_id].run=fn;
	system_id++;
}

void ng_ecs_component_toggle(register ng_ecs_entity_t e,register ng_ecs_component_t c)
{
	ng_ecs.entities[e]^=1<<c;
	register ng_u64_t em=ng_ecs.entities[e];
	register ng_u8_t s;
	for(s=0;s<NG_ECS_SYSTEM_MAX;s++)
	{
		register ng_u64_t sm=ng_ecs.systems[s].mask;
		register ng_u64_t r=em&sm;
		ng_ecs.systems[s].entities[e]=(r==em||r==sm)&&r!=1;
	}
}
/* store systems by type later */
void ng_ecs_think(register ng_u8_t type)
{
	register ng_u8_t s;
	register ng_u16_t e;
	for(s=0;s<NG_ECS_SYSTEM_MAX;s++)
	{
		if(!ng_ecs.systems[s].run) continue;
		for(e=0;e<NG_ECS_ENTITY_MAX;e++)
		{
			if(ng_ecs.systems[s].entities[e])
			{
				ng_ecs.systems[s].run(e);
			}
		}
	}
}
#endif/*__NG_ECS_H__*/