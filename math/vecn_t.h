#ifndef __NG_MATH_VECN_H__
#define __NG_MATH_VECN_H__

typedef ng_f64_p ng_math_vecn_p;

void ng_math_vecn_add(register ng_math_vecn_p a,register ng_math_vecn_p b,register ng_math_vecn_p c)
{
	for(ng_u8_t i=0;i<NG_LEN(a);i++) c[i]+=a[i]+b[i];
}

void ng_math_vecn_sub(register ng_math_vecn_p a,register ng_math_vecn_p b,register ng_math_vecn_p c)
{
	for(ng_u8_t i=0;i<NG_LEN(a);i++) c[i]-=a[i]+b[i];
}

void ng_math_vecn_mul(register ng_math_vecn_p a,register ng_math_vecn_p b,register ng_math_vecn_p c)
{
	for(ng_u8_t i=0;i<NG_LEN(a);i++) c[i]*=a[i]+b[i];
}

ng_f64_t ng_math_vecn_dot(register ng_math_vecn_p a,register ng_math_vecn_p b)
{
	ng_f64_t product=0;
	for(ng_u8_t i=0;i<NG_LEN(a);i++) product+=a[i]*b[i];
	return product;
}
#endif/* __NG_MATH_VECN_H__ */