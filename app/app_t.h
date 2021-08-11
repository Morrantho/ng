#ifndef __NG_APP_T_H__
#define __NG_APP_T_H__
struct
{
	ng_u8_t running;/* program running */
	ng_i64_t curtime;
	ng_f64_t elapsed;
	ng_f64_t delta;
	ng_f64_t accumulated;
}static g_ng_app=
{
	.running=1,
	0
};
#endif/* __NG_APP_T_H__ */