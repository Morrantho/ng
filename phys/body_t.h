#ifndef __NG_PHYS_BODY_H__
#define __NG_PHYS_BODY_H__
/* ecs component */
typedef struct ng_phys_body_t
{
	ng_phys_body_type_t type;
	ng_f64_t position[2];
	ng_f64_t velocity[2];
	ng_f64_t acceleration[2];
	ng_f64_t radius;/* mostly for testing */
	ng_u8_t frozen;
}ng_phys_body_t,*ng_phys_body_p;
#endif/*__NG_PHYS_BODY_H__*/