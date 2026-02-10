#include "ne_ds.h"
#include "sm_car_5a10d5d5_8_ds_sys_struct.h"
#include "sm_car_5a10d5d5_8_ds_dxf.h"
#include "sm_car_5a10d5d5_8_ds.h"
#include "sm_car_5a10d5d5_8_ds_externals.h"
#include "sm_car_5a10d5d5_8_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_8_ds_dxf ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t3 , NeDsMethodOutput * out ) { real_T
Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v ;
real_T intrm_sf_mf_0 ; real_T intrm_sf_mf_1 ; real_T intrm_sf_mf_4 ;
intrm_sf_mf_0 = ( t3 -> mX . mX [ 0UL ] - t3 -> mDP_R . mX [ 1UL ] ) *
100000.0 + t3 -> mU . mX [ 0UL ] * 150.0 ; intrm_sf_mf_1 = ( t3 -> mX . mX [
0UL ] - t3 -> mDP_R . mX [ 0UL ] ) * 100000.0 + t3 -> mU . mX [ 0UL ] * 150.0
; Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v =
( t3 -> mX . mX [ 0UL ] - t3 -> mDP_R . mX [ 1UL ] ) / 0.0001 ; intrm_sf_mf_4
= ( t3 -> mDP_R . mX [ 0UL ] - t3 -> mX . mX [ 0UL ] ) / 0.0001 ; if ( t3 ->
mX . mX [ 0UL ] >= t3 -> mDP_R . mX [ 1UL ] + 0.0001 ) { out -> mDXF . mX [
0UL ] = - ( ( real_T ) ( intrm_sf_mf_0 >= 0.0 ) * 100000.0 ) ; } else if ( t3
-> mX . mX [ 0UL ] >= t3 -> mDP_R . mX [ 1UL ] ) { out -> mDXF . mX [ 0UL ] =
- ( ( ( 10000.0 *
Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v *
6.0 -
Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v *
Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v *
10000.0 * 6.0 ) * intrm_sf_mf_0 + 100000.0 * ( Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v * Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v * 3.0 - Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v * Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v * Vehicle_Vehicle_Chassis_Damper_Independent_Damper_R2_Linear_Bumpstop_R_v * 2.0 ) ) * ( real_T ) ( intrm_sf_mf_0 >= 0.0 ) ) ; } else if ( t3 -> mX . mX [ 0UL ] > t3 -> mDP_R . mX [ 0UL ] ) { out -> mDXF . mX [ 0UL ] = 0.0 ; } else if ( t3 -> mX . mX [ 0UL ] > t3 -> mDP_R . mX [ 0UL ] - 0.0001 ) { out -> mDXF . mX [ 0UL ] = - ( ( ( - 10000.0 * intrm_sf_mf_4 * 6.0 - intrm_sf_mf_4 * intrm_sf_mf_4 * - 10000.0 * 6.0 ) * intrm_sf_mf_1 + 100000.0 * ( intrm_sf_mf_4 * intrm_sf_mf_4 * 3.0 - intrm_sf_mf_4 * intrm_sf_mf_4 * intrm_sf_mf_4 * 2.0 ) ) * ( real_T ) ( intrm_sf_mf_1 <= 0.0 ) ) ; } else { out -> mDXF . mX [ 0UL ] = - ( ( real_T ) ( intrm_sf_mf_1 <= 0.0 ) * 100000.0 ) ; } out -> mDXF . mX [ 1UL ] = 1.0 ; ( void ) sys ; ( void ) out ; return 0 ; }
