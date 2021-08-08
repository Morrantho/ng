#ifndef __NG_APP_T_H__
#define __NG_APP_T_H__
struct
{
	ng_u8_t running;/* program running */
	ng_u8_t state_now;/* state now */
	ng_u8_t state_last;/* state last */
	ng_i64_t ct;/* current time */
	ng_f64_t t;/* time */
	ng_f64_t dt;/* delta time */
	ng_f64_t ft;/* frame time */
	ng_f64_t acc;/* accumulator */
	ng_f64_t alpha;/* state blending factor */
}ng_app=
{
	.running=1,
	.dt=0.01,
	0
};
#endif//__NG_APP_T_H__