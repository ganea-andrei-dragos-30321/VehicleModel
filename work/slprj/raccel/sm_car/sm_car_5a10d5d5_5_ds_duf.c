#include "ne_ds.h"
#include "sm_car_5a10d5d5_5_ds_sys_struct.h"
#include "sm_car_5a10d5d5_5_ds_duf.h"
#include "sm_car_5a10d5d5_5_ds.h"
#include "sm_car_5a10d5d5_5_ds_externals.h"
#include "sm_car_5a10d5d5_5_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_5_ds_duf ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t4 , NeDsMethodOutput * out ) { real_T
Vehicle_Vehicle_Brakes_PedalAbstract_DiscDisc_Actuator_R1_P ; real_T
intrm_sf_mf_1 ; intrm_sf_mf_1 = ( real_T ) ( t4 -> mU . mX [ 0UL ] >= 0.0 ) *
t4 -> mU . mX [ 0UL ] * 1.0995574287564276 / 4.0 * 0.000154508 ;
Vehicle_Vehicle_Brakes_PedalAbstract_DiscDisc_Actuator_R1_P = ( real_T ) ( t4
-> mU . mX [ 0UL ] >= 0.0 ) * 1.0995574287564276 / 4.0 * 0.000154508 ; out ->
mDUF . mX [ 0UL ] = - ( t4 -> mU . mX [ 1UL ] / 0.14142135623730953 * pmf_exp
( - ( t4 -> mU . mX [ 1UL ] / 0.14142135623730953 * ( t4 -> mU . mX [ 1UL ] /
0.14142135623730953 ) ) ) * ( ( Vehicle_Vehicle_Brakes_PedalAbstract_DiscDisc_Actuator_R1_P - Vehicle_Vehicle_Brakes_PedalAbstract_DiscDisc_Actuator_R1_P ) * 2.3316439815971242 ) * 100000.0 + tanh ( t4 -> mU . mX [ 1UL ] / 0.01 ) * Vehicle_Vehicle_Brakes_PedalAbstract_DiscDisc_Actuator_R1_P * 100000.0 ) ; Vehicle_Vehicle_Brakes_PedalAbstract_DiscDisc_Actuator_R1_P = cosh ( t4 -> mU . mX [ 1UL ] / 0.01 ) * cosh ( t4 -> mU . mX [ 1UL ] / 0.01 ) ; out -> mDUF . mX [ 1UL ] = - ( ( 7.0710678118654737 * pmf_exp ( - ( t4 -> mU . mX [ 1UL ] / 0.14142135623730953 * ( t4 -> mU . mX [ 1UL ] / 0.14142135623730953 ) ) ) + - ( t4 -> mU . mX [ 1UL ] / 0.14142135623730953 * 7.0710678118654737 * 2.0 ) * ( t4 -> mU . mX [ 1UL ] / 0.14142135623730953 ) * pmf_exp ( - ( t4 -> mU . mX [ 1UL ] / 0.14142135623730953 * ( t4 -> mU . mX [ 1UL ] / 0.14142135623730953 ) ) ) ) * ( ( intrm_sf_mf_1 - intrm_sf_mf_1 ) * 2.3316439815971242 ) * 100000.0 + 100.0 * ( 1.0 / ( Vehicle_Vehicle_Brakes_PedalAbstract_DiscDisc_Actuator_R1_P == 0.0 ? 1.0E-16 : Vehicle_Vehicle_Brakes_PedalAbstract_DiscDisc_Actuator_R1_P ) ) * intrm_sf_mf_1 * 100000.0 ) ; ( void ) sys ; ( void ) out ; return 0 ; }
