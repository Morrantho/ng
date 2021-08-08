#ifndef __NG_STD_SIMD_H__
#define __NG_STD_SIMD_H__
#if defined(__AVX512__)
	#define NG_STD_SIMD avx512
#elif defined(__AVX2__)
	#define NG_STD_SIMD avx2
#elif defined(__AVX__)
	#define NG_STD_SIMD avx
#elif defined(__SSE4__)
	#define NG_STD_SIMD sse4
#elif defined(__SSE2__)
	#define NG_STD_SIMD sse2
#elif defined(__SSE__)
	#define NG_STD_SIMD sse
#elif defined(__MMX__)
	#define NG_STD_SIMD mmx
#endif
#ifdef NG_STD_SIMD
	#include <immintrin.h>
#else
	#define NG_STD_SIMD
#endif
#define _NG_STD_SIMD_INCL(F,EXT) NG_STR(NG_CAT(F##_,NG_STD_SIMD.EXT))
#define NG_STD_SIMD_INCL(F,EXT) _NG_STD_SIMD_INCL(F,EXT)
#endif//__NG_STD_SIMD_H__