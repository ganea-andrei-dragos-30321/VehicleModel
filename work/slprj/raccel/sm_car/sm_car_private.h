#ifndef sm_car_private_h_
#define sm_car_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "sm_car.h"
#include "sm_car_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
    }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
#else
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
#endif
#endif
extern real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T
table [ ] , uint32_T maxIndex ) ; extern real_T look1_bingxpw ( real_T u0 ,
const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) ; extern
void b0tpjctm23 ( real_T kq0fteb2nf , clo0is4qzz * localB ) ; extern void
p3bcp2inhg ( SimStruct * rtS_p , cvj4gltfca * localDW ) ; extern void
ftwmhzfofq ( cvj4gltfca * localDW ) ; extern void nul0anp0o0 ( SimStruct *
rtS_i , boolean_T dzddd1b050 , real_T nwn3uuxfod , clo0is4qzz * localB ,
cvj4gltfca * localDW ) ; extern void ka314eqjhn ( ggq1efpgow * localDW ) ;
extern void ebwex1dgjw ( real_T krgfs4qkbo , pbci4dfpnj * localB , ggq1efpgow
* localDW , mbv0ec4zb2 * localP ) ; extern void kzxxttmnx0 ( nodikpmnl2 *
localB , nafjax4hek * localDW , kgxijxq1i2 * localP , dhjz20bm0n * localX ) ;
extern void ns3z5plhge ( SimStruct * rtS_m , nafjax4hek * localDW ,
fomnjxr3mn * localXdis ) ; extern void pzjvk1gt3c ( nodikpmnl2 * localB ,
nafjax4hek * localDW , kgxijxq1i2 * localP , dhjz20bm0n * localX , kn3z04sns2
* localXdot ) ; extern void afro25skyf ( nodikpmnl2 * localB , nafjax4hek *
localDW , kgxijxq1i2 * localP , dhjz20bm0n * localX , kn3z04sns2 * localXdot
) ; extern void gidpjhpxen ( SimStruct * rtS_p , real_T k3qyxhis0v , real_T
kx22zeuneh , real_T c5o0etgjdl , real_T b4ssosqlzi , real_T d1jpeupybi ,
real_T kxt24h5cry , real_T chvmwi3krl , real_T g51o1oh314 , real_T jwxyspwglr
, nodikpmnl2 * localB , nafjax4hek * localDW , kgxijxq1i2 * localP ,
dhjz20bm0n * localX , fomnjxr3mn * localXdis ) ; extern void gidpjhpxenTID3 ( real_T jumzqmyw2w , nodikpmnl2 * localB , kgxijxq1i2 * localP ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
