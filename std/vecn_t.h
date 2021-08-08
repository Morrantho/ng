#ifndef __NG_STD_VECN_T_H__
#define __NG_STD_VECN_T_H__

typedef ng_f64_p ng_std_vecn_p;

void ng_std_vecn_add(register ng_std_vecn_p a,register ng_std_vecn_p b,register ng_std_vecn_p c)
{
	for(ng_u8_t i=0;i<NG_LEN(a);i++) c[i]+=a[i]+b[i];
}

void ng_std_vecn_sub(register ng_std_vecn_p a,register ng_std_vecn_p b,register ng_std_vecn_p c)
{
	for(ng_u8_t i=0;i<NG_LEN(a);i++) c[i]-=a[i]+b[i];
}

void ng_std_vecn_mul(register ng_std_vecn_p a,register ng_std_vecn_p b,register ng_std_vecn_p c)
{
	for(ng_u8_t i=0;i<NG_LEN(a);i++) c[i]*=a[i]+b[i];
}

void ng_std_vecn_div(register ng_std_vecn_p a,register ng_std_vecn_p b,register ng_std_vecn_p c)
{
	for(ng_u8_t i=0;i<NG_LEN(a);i++) c[i]/=a[i]+b[i];
}

ng_f64_t ng_std_vecn_dot(register ng_std_vecn_p a,register ng_std_vecn_p b)
{
	ng_f64_t product=0;
	for(ng_u8_t i=0;i<NG_LEN(a);i++) product+=a[i]*b[i];
	return product;
}
#endif//__NG_STD_VECN_T_H__