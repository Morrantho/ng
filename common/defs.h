#ifndef __NG_DEFS_H__
#define __NG_DEFS_H__
typedef unsigned char ng_u8_t,*ng_u8_p;
typedef unsigned short ng_u16_t,*ng_u16_p;
typedef unsigned int ng_u32_t,*ng_u32_p;
typedef unsigned long long ng_u64_t,*ng_u64_p;

typedef char ng_i8_t,*ng_i8_p;
typedef short ng_i16_t,*ng_i16_p;
typedef int ng_i32_t,*ng_i32_p;
typedef long long ng_i64_t,*ng_i64_p;

typedef float ng_f32_t,*ng_f32_p;
typedef double ng_f64_t,*ng_f64_p;
typedef long double ng_f80_t,*ng_f80_p;

typedef void *ng_void_p,**ng_void_p2,***ng_void_p3;

typedef ng_void_p (*ng_fn_p)(ng_u8_t,...);
#endif/* __NG_DEFS_H__ */