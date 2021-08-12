#ifndef __NG_PHYS_JOINT_TYPE_H__
#define __NG_PHYS_JOINT_TYPE_H__
typedef enum ng_phys_joint_type_t
{
	NG_PHYS_JOINT_DISTANCE,
	NG_PHYS_JOINT_GEAR,
	NG_PHYS_JOINT_MOTOR,
	NG_PHYS_JOINT_PRISMATIC,
	NG_PHYS_JOINT_PULLEY,
	NG_PHYS_JOINT_REVOLUTE,
	NG_PHYS_JOINT_WELD
}ng_phys_joint_type_t,*ng_phys_joint_type_p;
#endif/*__NG_PHYS_JOINT_TYPE_H__*/