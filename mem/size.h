#ifndef __NG_MEM_SIZE_H__
#define __NG_MEM_SIZE_H__
#define NG_MEM_TO_KB(N,F) N*F
#define NG_MEM_TO_MB(N,F) F*NG_MEM_TO_KB(N,F)
#define NG_MEM_TO_GB(N,F) F*NG_MEM_TO_MB(N,F)
#define NG_MEM_KB NG_MEM_TO_KB(1,1024)
#define NG_MEM_MB NG_MEM_TO_MB(1,1024)
#define NG_MEM_GB NG_MEM_TO_GB(1,1024)
#endif/* __NG_MEM_SIZE_H__ */