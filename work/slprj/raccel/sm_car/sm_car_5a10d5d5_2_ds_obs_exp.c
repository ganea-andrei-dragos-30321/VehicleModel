#include "ne_ds.h"
#include "sm_car_5a10d5d5_2_ds_sys_struct.h"
#include "sm_car_5a10d5d5_2_ds_obs_exp.h"
#include "sm_car_5a10d5d5_2_ds.h"
#include "sm_car_5a10d5d5_2_ds_externals.h"
#include "sm_car_5a10d5d5_2_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_2_ds_obs_exp ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { out -> mOBS_EXP . mX [
0UL ] = 0.0 ; out -> mOBS_EXP . mX [ 1UL ] = 0.0 ; out -> mOBS_EXP . mX [ 2UL
] = 0.0 ; out -> mOBS_EXP . mX [ 3UL ] = 0.0 ; out -> mOBS_EXP . mX [ 4UL ] =
0.0 ; out -> mOBS_EXP . mX [ 5UL ] = 0.0 ; out -> mOBS_EXP . mX [ 6UL ] = 0.0
; out -> mOBS_EXP . mX [ 7UL ] = 0.0 ; out -> mOBS_EXP . mX [ 8UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 9UL ] = 0.0 ; out -> mOBS_EXP . mX [ 10UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 11UL ] = 0.0 ; out -> mOBS_EXP . mX [ 12UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 13UL ] = 0.0 ; out -> mOBS_EXP . mX [ 14UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 15UL ] = 0.0 ; out -> mOBS_EXP . mX [ 16UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 17UL ] = 0.0 ; out -> mOBS_EXP . mX [ 18UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 19UL ] = 0.0 ; out -> mOBS_EXP . mX [ 20UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 21UL ] = 0.0 ; out -> mOBS_EXP . mX [ 22UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 23UL ] = 0.0 ; out -> mOBS_EXP . mX [ 24UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 25UL ] = 0.0 ; out -> mOBS_EXP . mX [ 26UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 27UL ] = t1 -> mDP_R . mX [ 3UL ] ; out -> mOBS_EXP .
mX [ 28UL ] = 0.0 ; out -> mOBS_EXP . mX [ 29UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 30UL ] = 0.0 ; out -> mOBS_EXP . mX [ 31UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 32UL ] = 0.0 ; out -> mOBS_EXP . mX [ 33UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 34UL ] = 0.0 ; out -> mOBS_EXP . mX [ 35UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 36UL ] = 0.0 ; out -> mOBS_EXP . mX [ 37UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 38UL ] = 0.0 ; out -> mOBS_EXP . mX [ 39UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 40UL ] = 0.0 ; out -> mOBS_EXP . mX [ 41UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 42UL ] = 0.0 ; out -> mOBS_EXP . mX [ 43UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 44UL ] = t1 -> mDP_R . mX [ 4UL ] ; out -> mOBS_EXP . mX [ 45UL ] = 0.0
; out -> mOBS_EXP . mX [ 46UL ] = 0.0 ; out -> mOBS_EXP . mX [ 47UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 48UL ] = 0.0 ; out -> mOBS_EXP . mX [ 49UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 50UL ] = 0.0 ; out -> mOBS_EXP . mX [ 51UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 52UL ] = 0.0 ; out -> mOBS_EXP . mX [ 53UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 54UL ] = 0.0 ; out -> mOBS_EXP . mX [ 55UL ] = 0.0 ;
out -> mOBS_EXP . mX [ 56UL ] = 0.0 ; out -> mOBS_EXP . mX [ 57UL ] = t1 ->
mP_R . mX [ 4UL ] ; out -> mOBS_EXP . mX [ 58UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 59UL ] = 0.0 ; out -> mOBS_EXP . mX [ 60UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 61UL ] = 0.0 ; out -> mOBS_EXP . mX [ 62UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 63UL ] = 0.0 ; out -> mOBS_EXP . mX [ 64UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 65UL ] = 0.0 ; out -> mOBS_EXP . mX [ 66UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 67UL ] = 0.0 ; out -> mOBS_EXP . mX [ 68UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 69UL ] = 0.0 ; out -> mOBS_EXP . mX [ 70UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 71UL ] = 0.0 ; out -> mOBS_EXP . mX [ 72UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 73UL ] = 0.0 ; out -> mOBS_EXP . mX [ 74UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 75UL ] = 0.0 ; out -> mOBS_EXP . mX [ 76UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 77UL ] = 0.0 ; out -> mOBS_EXP . mX [ 78UL ] = 0.0 ; out -> mOBS_EXP .
mX [ 79UL ] = 0.0 ; out -> mOBS_EXP . mX [ 80UL ] = 0.0 ; ( void ) sys ; ( void
) out ; return 0 ; }
