#include "ne_ds.h"
#include "sm_car_5a10d5d5_5_ds_sys_struct.h"
#include "sm_car_5a10d5d5_5_ds_obs_act.h"
#include "sm_car_5a10d5d5_5_ds.h"
#include "sm_car_5a10d5d5_5_ds_externals.h"
#include "sm_car_5a10d5d5_5_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_5_ds_obs_act ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { out -> mOBS_ACT . mX [
5UL ] = 0.0 ; out -> mOBS_ACT . mX [ 6UL ] = 300.0 ; out -> mOBS_ACT . mX [
0UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 1UL ] = t1 -> mU . mX
[ 0UL ] ; out -> mOBS_ACT . mX [ 2UL ] = 0.0 ; out -> mOBS_ACT . mX [ 3UL ] =
t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 4UL ] = t1 -> mU . mX [ 1UL ]
; out -> mOBS_ACT . mX [ 7UL ] = t1 -> mX . mX [ 0UL ] ; out -> mOBS_ACT . mX
[ 8UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 9UL ] = t1 -> mU .
mX [ 1UL ] ; out -> mOBS_ACT . mX [ 10UL ] = t1 -> mU . mX [ 1UL ] ; out ->
mOBS_ACT . mX [ 11UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 12UL
] = - t1 -> mX . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 13UL ] = - t1 -> mX . mX
[ 0UL ] ; out -> mOBS_ACT . mX [ 14UL ] = - t1 -> mX . mX [ 0UL ] ; out ->
mOBS_ACT . mX [ 15UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 16UL
] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 17UL ] = t1 -> mU . mX [
1UL ] ; out -> mOBS_ACT . mX [ 18UL ] = t1 -> mU . mX [ 1UL ] ; out ->
mOBS_ACT . mX [ 19UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 20UL
] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 21UL ] = 0.0 ; out ->
mOBS_ACT . mX [ 22UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 23UL
] = - t1 -> mX . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 24UL ] = t1 -> mU . mX [
1UL ] ; out -> mOBS_ACT . mX [ 25UL ] = 0.0 ; out -> mOBS_ACT . mX [ 26UL ] =
t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 27UL ] = t1 -> mU . mX [ 1UL ]
; out -> mOBS_ACT . mX [ 28UL ] = - t1 -> mX . mX [ 0UL ] ; out -> mOBS_ACT .
mX [ 29UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 30UL ] = 0.0 ;
out -> mOBS_ACT . mX [ 31UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX
[ 32UL ] = 0.0 ; out -> mOBS_ACT . mX [ 33UL ] = 0.0 ; out -> mOBS_ACT . mX [
34UL ] = - t1 -> mX . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 35UL ] = - t1 -> mX
. mX [ 0UL ] ; out -> mOBS_ACT . mX [ 36UL ] = - t1 -> mX . mX [ 0UL ] ; out
-> mOBS_ACT . mX [ 37UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [
38UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 39UL ] = t1 -> mU .
mX [ 1UL ] ; out -> mOBS_ACT . mX [ 40UL ] = t1 -> mU . mX [ 1UL ] ; out ->
mOBS_ACT . mX [ 41UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 42UL
] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 43UL ] = t1 -> mU . mX [
1UL ] ; out -> mOBS_ACT . mX [ 44UL ] = 0.0 ; out -> mOBS_ACT . mX [ 45UL ] =
0.0 ; out -> mOBS_ACT . mX [ 46UL ] = 0.0 ; out -> mOBS_ACT . mX [ 47UL ] =
t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 48UL ] = t1 -> mU . mX [ 1UL ]
; out -> mOBS_ACT . mX [ 49UL ] = 0.0 ; out -> mOBS_ACT . mX [ 50UL ] = 0.0 ;
out -> mOBS_ACT . mX [ 51UL ] = 0.0 ; out -> mOBS_ACT . mX [ 52UL ] = t1 ->
mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 53UL ] = t1 -> mU . mX [ 1UL ] ; out
-> mOBS_ACT . mX [ 54UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [
55UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ACT . mX [ 56UL ] = t1 -> mU .
mX [ 1UL ] ; ( void ) sys ; ( void ) out ; return 0 ; }
