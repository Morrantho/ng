#ifndef __NG_TIME_WINDOWS_H__
#define __NG_TIME_WINDOWS_H__
#include "time.h"
static LARGE_INTEGER g_ng_time_frequency={0};
static ng_f64_t g_ng_time_ffrequency=0;

ng_u64_t ng_time_micros()
{
	LARGE_INTEGER t;
	QueryPerformanceCounter(&t);
	return (t.QuadPart*1000000)*g_ng_time_ffrequency;
}

void ng_time_init()
{
	QueryPerformanceFrequency(&g_ng_time_frequency);
	g_ng_time_ffrequency=1/g_ng_time_frequency.QuadPart;
	g_ng_app.curtime=ng_time_micros();
}
#endif/* __NG_TIME_WINDOWS_H__ */