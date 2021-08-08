#include <stdio.h>
#include "common/defs.h"
#include "common/macros.h"
#include "mem/mem.h"
#include "std/stack_t.h"
#include "std/string.h"
#include "std/vec_t.h"
#include "std/vecn_t.h"
#include "std/simd.h"
#include "gfx/gfx.h"
#include "phys/phys.h"
#include "ecs/ecs.h"
#include "app/app_t.h"

#if defined(_WIN32)||defined(_WIN64)
	#include "windows.h"
#elif defined(__linux__)
	#include "linux.h"
#elif defined(__APPLE__)
	#include "mac.h"
#endif

#include "app/app.h"

int main(int argc,char** argv)
{
	ng_app_main();
	return 0;
}