#include "ne_ds.h"
#include "sm_car_5a10d5d5_8_ds_sys_struct.h"
#include "sm_car_5a10d5d5_8_ds_obs_all.h"
#include "sm_car_5a10d5d5_8_ds.h"
#include "sm_car_5a10d5d5_8_ds_externals.h"
#include "sm_car_5a10d5d5_8_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_8_ds_obs_all ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { real_T
 Vehicle_Vehicle_Chassis_SuspA2_Linkage_Linkage_R_DoubleWishbone_Pushrod_NoSteer_Shock_Prismatic_Spring_f_in0
;
 Vehicle_Vehicle_Chassis_SuspA2_Linkage_Linkage_R_DoubleWishbone_Pushrod_NoSteer_Shock_Prismatic_Spring_f_in0
= ( - t1 -> mX . mX [ 4UL ] - t1 -> mX . mX [ 5UL ] ) + t1 -> mX . mX [ 6UL ]
; out -> mOBS_ALL . mX [ 0UL ] = 0.0 ; out -> mOBS_ALL . mX [ 1UL ] = 0.0 ;
out -> mOBS_ALL . mX [ 2UL ] = t1 -> mD . mX [ 0UL ] ; out -> mOBS_ALL . mX [
3UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 4UL ] = t1 -> mX . mX
[ 4UL ] ; out -> mOBS_ALL . mX [ 5UL ] = t1 -> mX . mX [ 0UL ] ; out ->
mOBS_ALL . mX [ 6UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 7UL ]
= 0.0 ; out -> mOBS_ALL . mX [ 8UL ] = 0.0 ; out -> mOBS_ALL . mX [ 9UL ] =
t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 10UL ] = t1 -> mX . mX [ 5UL ]
; out -> mOBS_ALL . mX [ 11UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL .
mX [ 12UL ] = 0.0 ; out -> mOBS_ALL . mX [ 13UL ] = - t1 -> mX . mX [ 4UL ] ;
out -> mOBS_ALL . mX [ 14UL ] = 0.0 ; out -> mOBS_ALL . mX [ 15UL ] = - t1 ->
mX . mX [ 4UL ] ; out -> mOBS_ALL . mX [ 16UL ] = - t1 -> mX . mX [ 4UL ] ;
out -> mOBS_ALL . mX [ 17UL ] = 0.0 ; out -> mOBS_ALL . mX [ 18UL ] = - t1 ->
mX . mX [ 5UL ] ; out -> mOBS_ALL . mX [ 19UL ] = 0.0 ; out -> mOBS_ALL . mX
[ 20UL ] = - t1 -> mX . mX [ 5UL ] ; out -> mOBS_ALL . mX [ 21UL ] = - t1 ->
mX . mX [ 5UL ] ; out -> mOBS_ALL . mX [ 22UL ] = 0.0 ; out -> mOBS_ALL . mX
[ 23UL ] = 0.0 ; out -> mOBS_ALL . mX [ 24UL ] = t1 -> mX . mX [ 1UL ] ; out
-> mOBS_ALL . mX [ 25UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [
26UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 27UL ] = t1 -> mX .
mX [ 1UL ] ; out -> mOBS_ALL . mX [ 28UL ] = t1 -> mX . mX [ 1UL ] ; out ->
mOBS_ALL . mX [ 29UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 30UL
] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 31UL ] = t1 -> mU . mX [
0UL ] ; out -> mOBS_ALL . mX [ 32UL ] = 0.0 ; out -> mOBS_ALL . mX [ 33UL ] =
t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 34UL ] = t1 -> mU . mX [ 0UL ]
; out -> mOBS_ALL . mX [ 35UL ] = 0.0 ; out -> mOBS_ALL . mX [ 36UL ] = t1 ->
mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 37UL ] = 0.0 ; out -> mOBS_ALL . mX
[ 38UL ] = 0.0 ; out -> mOBS_ALL . mX [ 39UL ] = 0.0 ; out -> mOBS_ALL . mX [
40UL ] = 0.0 ; out -> mOBS_ALL . mX [ 41UL ] = t1 -> mX . mX [ 2UL ] ; out ->
mOBS_ALL . mX [ 42UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 43UL
] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 44UL ] = t1 -> mX . mX [
2UL ] ; out -> mOBS_ALL . mX [ 45UL ] = t1 -> mX . mX [ 2UL ] ; out ->
mOBS_ALL . mX [ 46UL ] = 0.0 ; out -> mOBS_ALL . mX [ 47UL ] = t1 -> mX . mX
[ 6UL ] ; out -> mOBS_ALL . mX [ 48UL ] = 0.0 ; out -> mOBS_ALL . mX [ 49UL ]
= t1 -> mX . mX [ 6UL ] ; out -> mOBS_ALL . mX [ 50UL ] = t1 -> mX . mX [ 6UL
] ; out -> mOBS_ALL . mX [ 51UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL .
mX [ 52UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 53UL ] = 0.0 ;
out -> mOBS_ALL . mX [ 54UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX
[ 55UL ] = - t1 -> mX . mX [ 6UL ] ; out -> mOBS_ALL . mX [ 56UL ] = t1 -> mU
. mX [ 0UL ] ; out -> mOBS_ALL . mX [ 57UL ] = t1 -> mX . mX [ 3UL ] ; out ->
mOBS_ALL . mX [ 58UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 59UL
] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 60UL ] = t1 -> mU . mX [
0UL ] ; out -> mOBS_ALL . mX [ 61UL ] = t1 -> mU . mX [ 0UL ] ; out ->
mOBS_ALL . mX [ 62UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 63UL
] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 64UL ] = 0.0 ; out ->
mOBS_ALL . mX [ 65UL ] =
 Vehicle_Vehicle_Chassis_SuspA2_Linkage_Linkage_R_DoubleWishbone_Pushrod_NoSteer_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ALL . mX [ 66UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL .
mX [ 67UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX [ 68UL ] = 0.0 ;
out -> mOBS_ALL . mX [ 69UL ] = 0.0 ; out -> mOBS_ALL . mX [ 70UL ] =
 Vehicle_Vehicle_Chassis_SuspA2_Linkage_Linkage_R_DoubleWishbone_Pushrod_NoSteer_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ALL . mX [ 71UL ] = 0.0 ; out -> mOBS_ALL . mX [ 72UL ] =
 Vehicle_Vehicle_Chassis_SuspA2_Linkage_Linkage_R_DoubleWishbone_Pushrod_NoSteer_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ALL . mX [ 73UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL .
mX [ 74UL ] = 0.0 ; out -> mOBS_ALL . mX [ 75UL ] = t1 -> mU . mX [ 0UL ] ;
out -> mOBS_ALL . mX [ 76UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL . mX
[ 77UL ] =
 Vehicle_Vehicle_Chassis_SuspA2_Linkage_Linkage_R_DoubleWishbone_Pushrod_NoSteer_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ALL . mX [ 78UL ] = t1 -> mU . mX [ 0UL ] ; out -> mOBS_ALL .
mX [ 79UL ] =
 Vehicle_Vehicle_Chassis_SuspA2_Linkage_Linkage_R_DoubleWishbone_Pushrod_NoSteer_Shock_Prismatic_Spring_f_in0
; out -> mOBS_ALL . mX [ 80UL ] = t1 -> mU . mX [ 0UL ] ; ( void ) sys ; ( void
) out ; return 0 ; }
