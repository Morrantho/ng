#ifndef __NG_APP_H__
#define __NG_APP_H__

void ng_app_init()
{
	ng_time_init();
	ng_phys_init();
	ng_gfx_init();
	ng_app_window_init();
}

void ng_app_tick()
{
	while(ng_app.running)
	{
		register ng_i64_t ct=ng_time_micros();
		ng_app_window_poll();
		ng_app.ft=(ct-ng_app.ct)/1000000.0;
		ng_app.ct=ct;
		if(ng_app.ft>0.25) ng_app.ft=0.25;
		ng_app.acc+=ng_app.ft; /* Accumulate leftover time */
		while(ng_app.acc>=ng_app.dt)
		{
			ng_app.state_last=ng_app.state_now;
			ng_phys_integrate(ng_app.state_now,ng_app.t,ng_app.dt);
			ng_app.t+=ng_app.dt;
			ng_app.acc-=ng_app.dt;
		}
		ng_app.alpha=ng_app.acc/ng_app.dt;
		ng_f64_t state=ng_app.state_now*ng_app.alpha+ng_app.state_last*(1.0-ng_app.alpha);
		ng_gfx_render(state);
	}
}

void ng_app_deinit()
{
	
}

void ng_app_main()
{
	/* Loading? */
	ng_app_init();
	ng_app_tick();
	/* Saving? */
	ng_app_deinit();
}
#endif//__NG_APP_H__