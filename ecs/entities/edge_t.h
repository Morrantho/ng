#ifndef __NG_ECS_ENTITY_EDGE_H__
#define __NG_ECS_ENTITY_EDGE_H__
void ng_ecs_entity_edge(ng_ecs_entity_t point_a,ng_ecs_entity_t point_b)
{
	ng_ecs_entity_t e=ng_ecs_entity();
	ng_ecs_component_toggle(e,NG_ECS_COMPONENT_EDGE);
	ng_ecs_component_toggle(e,NG_ECS_COMPONENT_COLOR);
	g_ng_ecs.edge[e][0]=point_a;
	g_ng_ecs.edge[e][1]=point_b;
	g_ng_ecs.edge[e][2]=32;/* edge length */
	g_ng_ecs.color[e][0]=255;/* r */
	g_ng_ecs.color[e][1]=255;/* g */
	g_ng_ecs.color[e][2]=255;/* b */
	g_ng_ecs.color[e][3]=255;/* a */
	return e;
}
#endif/*__NG_ECS_ENTITY_EDGE_H__*/