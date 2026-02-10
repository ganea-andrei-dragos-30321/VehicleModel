#include "ne_ds.h"
#include "sm_car_5a10d5d5_6_ds_sys_struct.h"
#include "sm_car_5a10d5d5_6_ds_obs_act.h"
#include "sm_car_5a10d5d5_6_ds.h"
#include "sm_car_5a10d5d5_6_ds_externals.h"
#include "sm_car_5a10d5d5_6_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_6_ds_obs_act ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { real_T
 Vehicle_Vehicle_Chassis_SuspA1_Linkage_Linkage_R_DoubleWishbone_Pushrod_Shock_Prismatic_Spring_f_in0
;
 Vehicle_Vehicle_Chassis_SuspA1_Linkage_Linkage_R_DoubleWishbone_Pushrod_Shock_Prismatic_Spring_f_in0
= ( - t1 -> mX . mX [ 4UL ] - t1 -> mX . mX [ 5UL ] ) + t1 -> mX . mX [ 6UL ]
; out -> mOBS_ACT . mX [ 0UL ] = 0.0 ; out -> mOBS_ACT . mX [ 1UL ] = 0.0 ;
out -> mOBS_ACT . mX [ 2UL ] = t1 -> mD . mX [ 0UL ] ; out -> mOBS_ACT . mX [
3UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 4UL ] = t1 -> mX . mX
[ 4UL ] ; out -> mOBS_ACT . mX [ 5UL ] = t1 -> mX . mX [ 0UL ] ; out ->
mOBS_ACT . mX [ 6UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 7UL ]
= 0.0 ; out -> mOBS_ACT . mX [ 8UL ] = 0.0 ; out -> mOBS_ACT . mX [ 9UL ] =
t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 10UL ] = t1 -> mX . mX [ 5UL ]
; out -> mOBS_ACT . mX [ 11UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT .
mX [ 12UL ] = 0.0 ; out -> mOBS_ACT . mX [ 13UL ] = - t1 -> mX . mX [ 4UL ] ;
out -> mOBS_ACT . mX [ 14UL ] = 0.0 ; out -> mOBS_ACT . mX [ 15UL ] = - t1 ->
mX . mX [ 4UL ] ; out -> mOBS_ACT . mX [ 16UL ] = - t1 -> mX . mX [ 4UL ] ;
out -> mOBS_ACT . mX [ 17UL ] = 0.0 ; out -> mOBS_ACT . mX [ 18UL ] = - t1 ->
mX . mX [ 5UL ] ; out -> mOBS_ACT . mX [ 19UL ] = 0.0 ; out -> mOBS_ACT . mX
[ 20UL ] = - t1 -> mX . mX [ 5UL ] ; out -> mOBS_ACT . mX [ 21UL ] = - t1 ->
mX . mX [ 5UL ] ; out -> mOBS_ACT . mX [ 22UL ] = 0.0 ; out -> mOBS_ACT . mX
[ 23UL ] = 0.0 ; out -> mOBS_ACT . mX [ 24UL ] = t1 -> mX . mX [ 1UL ] ; out
-> mOBS_ACT . mX [ 25UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [
26UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 27UL ] = t1 -> mX .
mX [ 1UL ] ; out -> mOBS_ACT . mX [ 28UL ] = t1 -> mX . mX [ 1UL ] ; out ->
mOBS_ACT . mX [ 29UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 30UL
] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 31UL ] = t1 -> mU . mX [
0UL ] ; out -> mOBS_ACT . mX [ 32UL ] = 0.0 ; out -> mOBS_ACT . mX [ 33UL ] =
t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 34UL ] = t1 -> mU . mX [ 0UL ]
; out -> mOBS_ACT . mX [ 35UL ] = 0.0 ; out -> mOBS_ACT . mX [ 36UL ] = t1 ->
mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 37UL ] = 0.0 ; out -> mOBS_ACT . mX
[ 38UL ] = 0.0 ; out -> mOBS_ACT . mX [ 39UL ] = 0.0 ; out -> mOBS_ACT . mX [
40UL ] = 0.0 ; out -> mOBS_ACT . mX [ 41UL ] = t1 -> mX . mX [ 2UL ] ; out ->
mOBS_ACT . mX [ 42UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 43UL
] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 44UL ] = t1 -> mX . mX [
2UL ] ; out -> mOBS_ACT . mX [ 45UL ] = t1 -> mX . mX [ 2UL ] ; out ->
mOBS_ACT . mX [ 46UL ] = 0.0 ; out -> mOBS_ACT . mX [ 47UL ] = t1 -> mX . mX
[ 6UL ] ; out -> mOBS_ACT . mX [ 48UL ] = 0.0 ; out -> mOBS_ACT . mX [ 49UL ]
= t1 -> mX . mX [ 6UL ] ; out -> mOBS_ACT . mX [ 50UL ] = t1 -> mX . mX [ 6UL
] ; out -> mOBS_ACT . mX [ 51UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT .
mX [ 52UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 53UL ] = 0.0 ;
out -> mOBS_ACT . mX [ 54UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX
[ 55UL ] = - t1 -> mX . mX [ 6UL ] ; out -> mOBS_ACT . mX [ 56UL ] = t1 -> mU
. mX [ 0UL ] ; out -> mOBS_ACT . mX [ 57UL ] = t1 -> mX . mX [ 3UL ] ; out ->
mOBS_ACT . mX [ 58UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 59UL
] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 60UL ] = t1 -> mU . mX [
0UL ] ; out -> mOBS_ACT . mX [ 61UL ] = t1 -> mU . mX [ 0UL ] ; out ->
mOBS_ACT . mX [ 62UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 63UL
] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 64UL ] = 0.0 ; out ->
mOBS_ACT . mX [ 65UL ] =
 Vehicle_Vehicle_Chassis_SuspA1_Linkage_Linkage_R_DoubleWishbone_Pushrod_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ACT . mX [ 66UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT .
mX [ 67UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX [ 68UL ] = 0.0 ;
out -> mOBS_ACT . mX [ 69UL ] = 0.0 ; out -> mOBS_ACT . mX [ 70UL ] =
 Vehicle_Vehicle_Chassis_SuspA1_Linkage_Linkage_R_DoubleWishbone_Pushrod_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ACT . mX [ 71UL ] = 0.0 ; out -> mOBS_ACT . mX [ 72UL ] =
 Vehicle_Vehicle_Chassis_SuspA1_Linkage_Linkage_R_DoubleWishbone_Pushrod_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ACT . mX [ 73UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT .
mX [ 74UL ] = 0.0 ; out -> mOBS_ACT . mX [ 75UL ] = t1 -> mU . mX [ 0UL ] ;
out -> mOBS_ACT . mX [ 76UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT . mX
[ 77UL ] =
 Vehicle_Vehicle_Chassis_SuspA1_Linkage_Linkage_R_DoubleWishbone_Pushrod_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ACT . mX [ 78UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ACT .
mX [ 79UL ] =
 Vehicle_Vehicle_Chassis_SuspA1_Linkage_Linkage_R_DoubleWishbone_Pushrod_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ACT . mX [ 80UL ] = t1 -> mU . mX [ 0UL ] ; ( void ) sys ; ( void
) out ; return 0 ; }
