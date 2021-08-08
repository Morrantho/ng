#ifndef __NG_APP_H__
#define __NG_APP_H__

void ng_app_init()
{
	ng_time_init();
	ng_input_init();
	ng_phys_init();
	ng_gfx_init();
	ng_app_window_init();
}

void ng_app_think()
{
	while(ng_app.running)
	{
		register ng_u64_t curtime=ng_time_micros();
		ng_app_window_think();
		ng_input_think();
		ng_app.delta=(curtime-ng_app.curtime)*0.000001;
		ng_app.accumulated+=ng_app.delta;
		while(ng_app.accumulated>=NG_TIME_DELTA)
		{
			ng_phys_think();
			ng_app.elapsed+=NG_TIME_DELTA;
			ng_app.accumulated-=NG_TIME_DELTA;
		}
		ng_gfx_think();
		ng_app.curtime=curtime;
	}
}

void ng_app_deinit()
{
	ng_gfx_deinit();
}

void ng_app_main()
{
	/* Loading? */
	ng_app_init();
	ng_app_think();
	/* Saving? */
	ng_app_deinit();
}
#endif//__NG_APP_H__