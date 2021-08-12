#ifndef __NG_PHYS_SHAPE_H__
#define __NG_PHYS_SHAPE_H__
/* ecs component */
typedef struct ng_phys_shape_t
{
	ng_std_vec_t points;
	ng_std_vec_t edges;
}ng_phys_shape_t,*ng_phys_shape_p;
#endif/*__NG_PHYS_SHAPE_H__*/