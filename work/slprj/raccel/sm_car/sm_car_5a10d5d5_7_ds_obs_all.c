#include "ne_ds.h"
#include "sm_car_5a10d5d5_7_ds_sys_struct.h"
#include "sm_car_5a10d5d5_7_ds_obs_all.h"
#include "sm_car_5a10d5d5_7_ds.h"
#include "sm_car_5a10d5d5_7_ds_externals.h"
#include "sm_car_5a10d5d5_7_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_7_ds_obs_all ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { out -> mOBS_ALL . mX [
5UL ] = 0.0 ; out -> mOBS_ALL . mX [ 6UL ] = 300.0 ; out -> mOBS_ALL . mX [
0UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 1UL ] = t1 -> mU . mX
[ 0UL ] ; out -> mOBS_ALL . mX [ 2UL ] = 0.0 ; out -> mOBS_ALL . mX [ 3UL ] =
t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 4UL ] = t1 -> mU . mX [ 1UL ]
; out -> mOBS_ALL . mX [ 7UL ] = t1 -> mX . mX [ 0UL ] ; out -> mOBS_ALL . mX
[ 8UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 9UL ] = t1 -> mU .
mX [ 1UL ] ; out -> mOBS_ALL . mX [ 10UL ] = t1 -> mU . mX [ 1UL ] ; out ->
mOBS_ALL . mX [ 11UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 12UL
] = - t1 -> mX . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 13UL ] = - t1 -> mX . mX
[ 0UL ] ; out -> mOBS_ALL . mX [ 14UL ] = - t1 -> mX . mX [ 0UL ] ; out ->
mOBS_ALL . mX [ 15UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 16UL
] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 17UL ] = t1 -> mU . mX [
1UL ] ; out -> mOBS_ALL . mX [ 18UL ] = t1 -> mU . mX [ 1UL ] ; out ->
mOBS_ALL . mX [ 19UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 20UL
] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 21UL ] = 0.0 ; out ->
mOBS_ALL . mX [ 22UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 23UL
] = - t1 -> mX . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 24UL ] = t1 -> mU . mX [
1UL ] ; out -> mOBS_ALL . mX [ 25UL ] = 0.0 ; out -> mOBS_ALL . mX [ 26UL ] =
t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 27UL ] = t1 -> mU . mX [ 1UL ]
; out -> mOBS_ALL . mX [ 28UL ] = - t1 -> mX . mX [ 0UL ] ; out -> mOBS_ALL .
mX [ 29UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 30UL ] = 0.0 ;
out -> mOBS_ALL . mX [ 31UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX
[ 32UL ] = 0.0 ; out -> mOBS_ALL . mX [ 33UL ] = 0.0 ; out -> mOBS_ALL . mX [
34UL ] = - t1 -> mX . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 35UL ] = - t1 -> mX
. mX [ 0UL ] ; out -> mOBS_ALL . mX [ 36UL ] = - t1 -> mX . mX [ 0UL ] ; out
-> mOBS_ALL . mX [ 37UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [
38UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 39UL ] = t1 -> mU .
mX [ 1UL ] ; out -> mOBS_ALL . mX [ 40UL ] = t1 -> mU . mX [ 1UL ] ; out ->
mOBS_ALL . mX [ 41UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 42UL
] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 43UL ] = t1 -> mU . mX [
1UL ] ; out -> mOBS_ALL . mX [ 44UL ] = 0.0 ; out -> mOBS_ALL . mX [ 45UL ] =
0.0 ; out -> mOBS_ALL . mX [ 46UL ] = 0.0 ; out -> mOBS_ALL . mX [ 47UL ] =
t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 48UL ] = t1 -> mU . mX [ 1UL ]
; out -> mOBS_ALL . mX [ 49UL ] = 0.0 ; out -> mOBS_ALL . mX [ 50UL ] = 0.0 ;
out -> mOBS_ALL . mX [ 51UL ] = 0.0 ; out -> mOBS_ALL . mX [ 52UL ] = t1 ->
mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 53UL ] = t1 -> mU . mX [ 1UL ] ; out
-> mOBS_ALL . mX [ 54UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [
55UL ] = t1 -> mU . mX [ 1UL ] ; out -> mOBS_ALL . mX [ 56UL ] = t1 -> mU .
mX [ 1UL ] ; ( void ) sys ; ( void ) out ; return 0 ; }
