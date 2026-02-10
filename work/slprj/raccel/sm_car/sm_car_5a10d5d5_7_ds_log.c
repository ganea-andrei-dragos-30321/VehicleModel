#include "ne_ds.h"
#include "sm_car_5a10d5d5_7_ds_sys_struct.h"
#include "sm_car_5a10d5d5_7_ds_log.h"
#include "sm_car_5a10d5d5_7_ds.h"
#include "sm_car_5a10d5d5_7_ds_externals.h"
#include "sm_car_5a10d5d5_7_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_7_ds_log ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { out -> mLOG . mX [ 6UL
] = t1 -> mX . mX [ 0UL ] * t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 0UL ]
= t1 -> mU . mX [ 0UL ] ; out -> mLOG . mX [ 1UL ] = t1 -> mU . mX [ 0UL ] ;
out -> mLOG . mX [ 2UL ] = t1 -> mU . mX [ 0UL ] ; out -> mLOG . mX [ 3UL ] =
t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 4UL ] = t1 -> mX . mX [ 0UL ] ;
out -> mLOG . mX [ 5UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 7UL ] =
t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 8UL ] = t1 -> mU . mX [ 1UL ] ;
out -> mLOG . mX [ 9UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 10UL ]
= - t1 -> mX . mX [ 0UL ] ; out -> mLOG . mX [ 11UL ] = - t1 -> mX . mX [ 0UL
] ; out -> mLOG . mX [ 12UL ] = - t1 -> mX . mX [ 0UL ] ; out -> mLOG . mX [
13UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 14UL ] = t1 -> mU . mX [
1UL ] ; out -> mLOG . mX [ 15UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX
[ 16UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 17UL ] = t1 -> mU . mX
[ 1UL ] ; out -> mLOG . mX [ 18UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG .
mX [ 19UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 20UL ] = - t1 -> mX
. mX [ 0UL ] ; out -> mLOG . mX [ 21UL ] = t1 -> mU . mX [ 1UL ] ; out ->
mLOG . mX [ 22UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 23UL ] = t1
-> mU . mX [ 1UL ] ; out -> mLOG . mX [ 24UL ] = - t1 -> mX . mX [ 0UL ] ;
out -> mLOG . mX [ 25UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 26UL ]
= t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 27UL ] = - t1 -> mX . mX [ 0UL ]
; out -> mLOG . mX [ 28UL ] = - t1 -> mX . mX [ 0UL ] ; out -> mLOG . mX [
29UL ] = - t1 -> mX . mX [ 0UL ] ; out -> mLOG . mX [ 30UL ] = t1 -> mU . mX
[ 1UL ] ; out -> mLOG . mX [ 31UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG .
mX [ 32UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 33UL ] = t1 -> mU .
mX [ 1UL ] ; out -> mLOG . mX [ 34UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG
. mX [ 35UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 36UL ] = t1 -> mU
. mX [ 1UL ] ; out -> mLOG . mX [ 37UL ] = t1 -> mU . mX [ 1UL ] ; out ->
mLOG . mX [ 38UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 39UL ] = t1
-> mU . mX [ 1UL ] ; out -> mLOG . mX [ 40UL ] = t1 -> mU . mX [ 1UL ] ; out
-> mLOG . mX [ 41UL ] = t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 42UL ] =
t1 -> mU . mX [ 1UL ] ; out -> mLOG . mX [ 43UL ] = t1 -> mU . mX [ 1UL ] ; ( void ) sys ; ( void ) out ; return 0 ; }
