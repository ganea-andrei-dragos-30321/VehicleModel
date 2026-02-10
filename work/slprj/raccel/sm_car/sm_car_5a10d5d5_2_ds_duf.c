#include "ne_ds.h"
#include "sm_car_5a10d5d5_2_ds_sys_struct.h"
#include "sm_car_5a10d5d5_2_ds_duf.h"
#include "sm_car_5a10d5d5_2_ds.h"
#include "sm_car_5a10d5d5_2_ds_externals.h"
#include "sm_car_5a10d5d5_2_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_2_ds_duf ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t3 , NeDsMethodOutput * out ) { real_T intrm_sf_mf_0 ;
real_T intrm_sf_mf_1 ; real_T intrm_sf_mf_4 ; real_T t2 ; intrm_sf_mf_0 = ( t3
-> mX . mX [ 0UL ] - t3 -> mDP_R . mX [ 1UL ] ) * 100000.0 + t3 -> mU . mX [
0UL ] * 150.0 ; intrm_sf_mf_1 = ( t3 -> mX . mX [ 0UL ] - t3 -> mDP_R . mX [
0UL ] ) * 100000.0 + t3 -> mU . mX [ 0UL ] * 150.0 ; intrm_sf_mf_4 = ( t3 ->
mX . mX [ 0UL ] - t3 -> mDP_R . mX [ 1UL ] ) / 0.0001 ; t2 = intrm_sf_mf_4 *
intrm_sf_mf_4 * 3.0 - intrm_sf_mf_4 * intrm_sf_mf_4 * intrm_sf_mf_4 * 2.0 ;
intrm_sf_mf_4 = ( t3 -> mDP_R . mX [ 0UL ] - t3 -> mX . mX [ 0UL ] ) / 0.0001
; if ( t3 -> mX . mX [ 0UL ] >= t3 -> mDP_R . mX [ 1UL ] + 0.0001 ) { out ->
mDUF . mX [ 0UL ] = - ( ( real_T ) ( intrm_sf_mf_0 >= 0.0 ) * 150.0 ) ; }
else if ( t3 -> mX . mX [ 0UL ] >= t3 -> mDP_R . mX [ 1UL ] ) { out -> mDUF .
mX [ 0UL ] = - ( ( real_T ) ( intrm_sf_mf_0 >= 0.0 ) * 150.0 * t2 ) ; } else
if ( t3 -> mX . mX [ 0UL ] > t3 -> mDP_R . mX [ 0UL ] ) { out -> mDUF . mX [
0UL ] = 0.0 ; } else if ( t3 -> mX . mX [ 0UL ] > t3 -> mDP_R . mX [ 0UL ] -
0.0001 ) { out -> mDUF . mX [ 0UL ] = - ( ( real_T ) ( intrm_sf_mf_1 <= 0.0 )
* 150.0 * ( intrm_sf_mf_4 * intrm_sf_mf_4 * 3.0 - intrm_sf_mf_4 *
intrm_sf_mf_4 * intrm_sf_mf_4 * 2.0 ) ) ; } else { out -> mDUF . mX [ 0UL ] =
- ( ( real_T ) ( intrm_sf_mf_1 <= 0.0 ) * 150.0 ) ; } ( void ) sys ; ( void )
out ; return 0 ; }
