#ifndef __NG_TIME_WINDOWS_H__
#define __NG_TIME_WINDOWS_H__
#include "time.h"
static LARGE_INTEGER ng_time_frequency={0};

ng_u64_t ng_time_micros()
{
	LARGE_INTEGER t;
	QueryPerformanceCounter(&t);
	return (t.QuadPart*1000000)/ng_time_frequency.QuadPart;
}

void ng_time_init()
{
	QueryPerformanceFrequency(&ng_time_frequency);
	ng_app.curtime=ng_time_micros();
}
#endif/* __NG_TIME_WINDOWS_H__ */