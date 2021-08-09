#ifndef __NG_ECS_ENTITY_H__
#define __NG_ECS_ENTITY_H__
/* Just make them shorts. They're only used as indices. If we go over 65k ents, we f'd up. */
typedef ng_u16_t ng_ecs_entity_t,*ng_ecs_entity_p;
#endif/*__NG_ECS_ENTITY_H__*/