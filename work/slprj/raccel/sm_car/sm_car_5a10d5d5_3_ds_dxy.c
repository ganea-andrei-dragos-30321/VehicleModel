#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_dxy.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_dxy ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t20 , NeDsMethodOutput * out ) { real_T t3 [ 4 ] ;
real_T t4 [ 4 ] ; size_t t8 ; ( void ) t20 ; ( void ) LC ; out -> mDXY . mX [
4UL ] = 0.2 ; out -> mDXY . mX [ 7UL ] = 0.2 ; out -> mDXY . mX [ 0UL ] = 1.0
; t3 [ 0UL ] = - 1.0 ; t3 [ 1UL ] = - 0.2 ; t3 [ 2UL ] = 1.0 ; t3 [ 3UL ] = -
0.2 ; t4 [ 0UL ] = - 1.0 ; t4 [ 1UL ] = - 0.2 ; t4 [ 2UL ] = 1.0 ; t4 [ 3UL ]
= - 0.2 ; out -> mDXY . mX [ 1UL ] = 1.0 ; out -> mDXY . mX [ 2UL ] = 1.0 ;
out -> mDXY . mX [ 3UL ] = 1.0 ; out -> mDXY . mX [ 5UL ] = - 1.0 ; out ->
mDXY . mX [ 6UL ] = - 1.0 ; out -> mDXY . mX [ 8UL ] = - 1.0 ; out -> mDXY .
mX [ 9UL ] = - 1.0 ; for ( t8 = 0UL ; t8 < 4UL ; t8 ++ ) { out -> mDXY . mX [
t8 + 10UL ] = t3 [ t8 ] ; } for ( t8 = 0UL ; t8 < 4UL ; t8 ++ ) { out -> mDXY
. mX [ t8 + 14UL ] = t4 [ t8 ] ; } out -> mDXY . mX [ 18UL ] = - 1.0 ; out ->
mDXY . mX [ 19UL ] = 1.0 ; out -> mDXY . mX [ 20UL ] = 1.0 ; out -> mDXY . mX
[ 21UL ] = - 1.0 ; out -> mDXY . mX [ 22UL ] = 1.0 ; out -> mDXY . mX [ 23UL
] = - 1.0 ; out -> mDXY . mX [ 24UL ] = 1.0 ; out -> mDXY . mX [ 25UL ] = 1.0
; out -> mDXY . mX [ 26UL ] = 1.0 ; ( void ) LC ; ( void ) out ; return 0 ; }
