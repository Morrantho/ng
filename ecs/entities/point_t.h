#ifndef __NG_ECS_ENTITY_POINT_H__
#define __NG_ECS_ENTITY_POINT_H__
void ng_ecs_entity_point(ng_f64_t x,ng_f64_t y)
{
	ng_ecs_entity_t e=ng_ecs_entity();
	ng_ecs_component_toggle(e,NG_ECS_COMPONENT_POINT);
	ng_ecs_component_toggle(e,NG_ECS_COMPONENT_PHYS);
	ng_ecs_component_toggle(e,NG_ECS_COMPONENT_COLOR);
	g_ng_ecs.point[e][0]=x;
	g_ng_ecs.point[e][1]=y;
	g_ng_ecs.point[e][2]=8.0;/* radius */
	/* init phys */
	g_ng_ecs.color[e][0]=255;/* r */
	g_ng_ecs.color[e][1]=255;/* g */
	g_ng_ecs.color[e][2]=255;/* b */
	g_ng_ecs.color[e][3]=255;/* a */
	return e;
}
#endif/*__NG_ECS_ENTITY_POINT_H__*/