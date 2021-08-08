#ifndef __NG_MACROS_H__
#define __NG_MACROS_H__
#define _NG_CAT(A,B) A##B
#define NG_CAT(A,B) _NG_CAT(A,B)

#define _NG_STR(S) #S
#define NG_STR(S) _NG_STR(S)

#define NG_LEN(ARR) sizeof(ARR)/sizeof(ARR[0])
#endif//__NG_MACROS_H__