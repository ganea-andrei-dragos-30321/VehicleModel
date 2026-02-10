#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_y.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_y ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t8 , NeDsMethodOutput * out ) { real_T
Vehicle_Vehicle_Powertrain_Driveline_L2_R2_Gearbox_L2_tB ; real_T
Vehicle_Vehicle_Powertrain_Driveline_L2_R2_Gearbox_R2_tB ; ( void ) LC ; out
-> mY . mX [ 2UL ] = - t8 -> mX . mX [ 31UL ] - t8 -> mX . mX [ 34UL ] ; out
-> mY . mX [ 3UL ] = - t8 -> mX . mX [ 33UL ] - t8 -> mX . mX [ 35UL ] ;
Vehicle_Vehicle_Powertrain_Driveline_L2_R2_Gearbox_L2_tB = t8 -> mX . mX [
34UL ] * - 0.2 ; Vehicle_Vehicle_Powertrain_Driveline_L2_R2_Gearbox_R2_tB =
t8 -> mX . mX [ 35UL ] * - 0.2 ; out -> mY . mX [ 6UL ] = t8 -> mX . mX [
30UL ] * 0.2 ; out -> mY . mX [ 8UL ] = t8 -> mX . mX [ 32UL ] * 0.2 ; out ->
mY . mX [ 12UL ] = t8 -> mX . mX [ 41UL ] ; out -> mY . mX [ 14UL ] = - t8 ->
mX . mX [ 45UL ] - t8 -> mX . mX [ 51UL ] ; out -> mY . mX [ 19UL ] = t8 ->
mX . mX [ 105UL ] ; out -> mY . mX [ 20UL ] = t8 -> mX . mX [ 1UL ] ; out ->
mY . mX [ 21UL ] = t8 -> mX . mX [ 9UL ] ; out -> mY . mX [ 22UL ] = t8 -> mX
. mX [ 11UL ] ; out -> mY . mX [ 23UL ] = t8 -> mX . mX [ 13UL ] ; out -> mY
. mX [ 0UL ] = - t8 -> mX . mX [ 31UL ] ; out -> mY . mX [ 1UL ] = - t8 -> mX
. mX [ 33UL ] ; out -> mY . mX [ 4UL ] =
Vehicle_Vehicle_Powertrain_Driveline_L2_R2_Gearbox_L2_tB ; out -> mY . mX [
5UL ] = Vehicle_Vehicle_Powertrain_Driveline_L2_R2_Gearbox_R2_tB ; out -> mY
. mX [ 7UL ] = t8 -> mX . mX [ 34UL ] ; out -> mY . mX [ 9UL ] = t8 -> mX .
mX [ 35UL ] ; out -> mY . mX [ 10UL ] = t8 -> mX . mX [ 40UL ] ; out -> mY .
mX [ 11UL ] = - t8 -> mX . mX [ 39UL ] ; out -> mY . mX [ 13UL ] = t8 -> mX .
mX [ 49UL ] ; out -> mY . mX [ 15UL ] =
Vehicle_Vehicle_Powertrain_Driveline_L2_R2_Gearbox_L2_tB ; out -> mY . mX [
16UL ] = t8 -> mX . mX [ 54UL ] ; out -> mY . mX [ 17UL ] = t8 -> mX . mX [
51UL ] ; out -> mY . mX [ 18UL ] =
Vehicle_Vehicle_Powertrain_Driveline_L2_R2_Gearbox_R2_tB ; ( void ) LC ; ( void
) out ; return 0 ; }
