#ifndef __NG_ECS_H__
#define __NG_ECS_H__

#ifndef NG_ECS_ENT_MAX
#define NG_ECS_ENT_MAX 8192
#endif

#ifndef NG_ECS_CMP_MAX
#define NG_ECS_CMP_MAX 64
#endif

#ifndef NG_ECS_SYS_MAX
#define NG_ECS_SYS_MAX 32
#endif

typedef struct ng_ecs_none_t
{
	ng_u8_t blank;
}ng_ecs_none_t;

#ifndef NG_ECS_COMPONENTS
#define NG_ECS_COMPONENTS\
	X(NG_ECS_NONE,ng_ecs_none_t,none)
#endif

#define X(A,B,C) A,

typedef void (*ng_ecs_fn_p)(ng_u64_t);

typedef enum ng_ecs_component_t
{
	NG_ECS_COMPONENTS
}ng_ecs_component_t,*ng_ecs_component_p;

typedef struct ng_ecs_system_t
{
	ng_u8_t entities[NG_ECS_ENT_MAX];/*Bool array*/
	ng_u64_t mask;
	ng_ecs_fn_p run;
}ng_ecs_system_t,*ng_ecs_system_p;

struct
{
	ng_u64_t entities[NG_ECS_ENT_MAX];
	#undef  X
	#define X(A,B,C) B C[NG_ECS_ENT_MAX];
	NG_ECS_COMPONENTS
	ng_ecs_system_t systems[NG_ECS_SYS_MAX];
}ng_ecs=
{
	.entities={0},
	.systems={0},
	#undef  X
	#define X(A,B,C) .C={0},
	NG_ECS_COMPONENTS
};

void ng_ecs_system(register ng_u64_t mask,register ng_ecs_fn_p fn)
{
	static ng_i32_t id=0;
	ng_ecs.systems[id].mask=mask;
	ng_ecs.systems[id].run=fn;
	id++;
}

void ng_ecs_component_toggle(register ng_u64_t e,register ng_ecs_component_t c)
{
	ng_ecs.entities[e]^=1<<c;
	register ng_u64_t em=ng_ecs.entities[e];
	for(register ng_u64_t s=0;s<NG_ECS_SYS_MAX;s++)
	{
		register ng_u64_t sm=ng_ecs.systems[s].mask;
		register ng_u64_t r=em&sm;
		ng_ecs.systems[s].entities[e]=(r==em||r==sm)&&r!=1;
	}
}
/* store systems by type later */
void ng_ecs_think(register ng_u8_t type)
{
	for(register ng_i32_t s=0;s<NG_ECS_SYS_MAX;s++)
	{
		if(!ng_ecs.systems[s].run) continue;
		for(register ng_i32_t e=0;e<NG_ECS_ENT_MAX;e++)
			if(ng_ecs.systems[s].entities[e])
				ng_ecs.systems[s].run(e);
	}
}
#endif/*__NG_ECS_H__*/