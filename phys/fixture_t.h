#ifndef __NG_PHYS_FIXTURE_H__
#define __NG_PHYS_FIXTURE_H__
/* ecs component */
typedef struct ng_phys_fixture_t
{
	ng_f64_t density;
	ng_f64_t friction;
	ng_f64_t gravity;
	ng_f64_t restitution;/* bounce */
}ng_phys_fixture_t,*ng_phys_fixture_p;
#endif/*__NG_PHYS_FIXTURE_H__*/