#include <stdio.h>
#include "../common/common.h"
#include "../mem/mem.h"
#include "../std/std.h"
#include "../input/input.h"
#include "../ecs/ecs.h"
#include "../phys/phys.h"
#include "../gfx/gfx.h"
#include "../app/app_t.h"

#if defined(_WIN32)||defined(_WIN64)
	#include "windows.h"
#elif defined(__linux__)
	#include "linux.h"
#elif defined(__APPLE__)
	#include "mac.h"
#endif

#include "../app/app.h"

int main(int argc,char** argv)
{
	ng_app_main();
	return 0;
}