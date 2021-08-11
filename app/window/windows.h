#ifndef __NG_APP_WINDOW_WINDOWS_H__
#define __NG_APP_WINDOW_WINDOWS_H__
#include "window.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

LRESULT CALLBACK ng_app_window_proc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
	switch(msg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			g_ng_app.running=0;
			return 0;
	}
	return DefWindowProc(hwnd,msg,wp,lp);
}

void ng_app_window_think()
{
	MSG msg={0};
	while(PeekMessage(&msg,0,0,0,PM_NOREMOVE))
	{
		if(!GetMessage(&msg,0,0,0)) return;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void ng_app_window_init()
{
	WNDCLASS wc={0};
	wc.lpfnWndProc=ng_app_window_proc;
	wc.hInstance=GetModuleHandle(0);
	wc.lpszClassName="ng";
	if(!RegisterClass(&wc)) return;
	HWND hwnd=CreateWindow("ng","ng",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,0,0,wc.hInstance,0);
	if(!hwnd) return;
	ShowWindow(hwnd,3);
	UpdateWindow(hwnd);
}
#endif/* __NG_APP_WINDOW_WINDOWS_H__ */