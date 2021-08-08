#ifndef __NG_TIME_H__
#define __NG_TIME_H__

ng_i64_t ng_time_micros()
{
	LARGE_INTEGER t,f;
	QueryPerformanceFrequency(&f);
	QueryPerformanceCounter(&t);
	return (t.QuadPart*1000000)/f.QuadPart;
}
/* wmmlib refuses to link, so can't timeGetTime(). Don't use it for anything important. */
ng_u16_t ng_time_millis()
{
	return GetTickCount();
}

void ng_time_init()
{
	ng_app.ct=ng_time_micros();
}
#endif//__NG_TIME_H__