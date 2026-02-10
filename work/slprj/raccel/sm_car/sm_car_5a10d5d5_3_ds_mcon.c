#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_mcon.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_mcon ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { static real_T
_cg_const_1 [ 50 ] = { - 1.0 , 1.0 , 1.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0
, 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0
, 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.5 , 1.0 , 0.8 , 0.02 , 0.8 ,
0.02 , - 1.0 , 0.79519851557330368 , - 1.0 , 0.079519851557330379 , - 1.0 ,
0.079519851557330379 , - 1.0 , 0.079519851557330379 , - 1.0 ,
0.079519851557330379 , 1.0 , - 1.0 , - 1.0 , - 1.0 , - 1.0 } ; ( void ) t1 ;
( void ) LC ; out -> mMCON . mX [ 0 ] = _cg_const_1 [ 0 ] ; out -> mMCON . mX
[ 1 ] = _cg_const_1 [ 1 ] ; out -> mMCON . mX [ 2 ] = _cg_const_1 [ 2 ] ; out
-> mMCON . mX [ 3 ] = _cg_const_1 [ 3 ] ; out -> mMCON . mX [ 4 ] =
_cg_const_1 [ 4 ] ; out -> mMCON . mX [ 5 ] = _cg_const_1 [ 5 ] ; out ->
mMCON . mX [ 6 ] = _cg_const_1 [ 6 ] ; out -> mMCON . mX [ 7 ] = _cg_const_1
[ 7 ] ; out -> mMCON . mX [ 8 ] = _cg_const_1 [ 8 ] ; out -> mMCON . mX [ 9 ]
= _cg_const_1 [ 9 ] ; out -> mMCON . mX [ 10 ] = _cg_const_1 [ 10 ] ; out ->
mMCON . mX [ 11 ] = _cg_const_1 [ 11 ] ; out -> mMCON . mX [ 12 ] =
_cg_const_1 [ 12 ] ; out -> mMCON . mX [ 13 ] = _cg_const_1 [ 13 ] ; out ->
mMCON . mX [ 14 ] = _cg_const_1 [ 14 ] ; out -> mMCON . mX [ 15 ] =
_cg_const_1 [ 15 ] ; out -> mMCON . mX [ 16 ] = _cg_const_1 [ 16 ] ; out ->
mMCON . mX [ 17 ] = _cg_const_1 [ 17 ] ; out -> mMCON . mX [ 18 ] =
_cg_const_1 [ 18 ] ; out -> mMCON . mX [ 19 ] = _cg_const_1 [ 19 ] ; out ->
mMCON . mX [ 20 ] = _cg_const_1 [ 20 ] ; out -> mMCON . mX [ 21 ] =
_cg_const_1 [ 21 ] ; out -> mMCON . mX [ 22 ] = _cg_const_1 [ 22 ] ; out ->
mMCON . mX [ 23 ] = _cg_const_1 [ 23 ] ; out -> mMCON . mX [ 24 ] =
_cg_const_1 [ 24 ] ; out -> mMCON . mX [ 25 ] = _cg_const_1 [ 25 ] ; out ->
mMCON . mX [ 26 ] = _cg_const_1 [ 26 ] ; out -> mMCON . mX [ 27 ] =
_cg_const_1 [ 27 ] ; out -> mMCON . mX [ 28 ] = _cg_const_1 [ 28 ] ; out ->
mMCON . mX [ 29 ] = _cg_const_1 [ 29 ] ; out -> mMCON . mX [ 30 ] =
_cg_const_1 [ 30 ] ; out -> mMCON . mX [ 31 ] = _cg_const_1 [ 31 ] ; out ->
mMCON . mX [ 32 ] = _cg_const_1 [ 32 ] ; out -> mMCON . mX [ 33 ] =
_cg_const_1 [ 33 ] ; out -> mMCON . mX [ 34 ] = _cg_const_1 [ 34 ] ; out ->
mMCON . mX [ 35 ] = _cg_const_1 [ 35 ] ; out -> mMCON . mX [ 36 ] =
_cg_const_1 [ 36 ] ; out -> mMCON . mX [ 37 ] = _cg_const_1 [ 37 ] ; out ->
mMCON . mX [ 38 ] = _cg_const_1 [ 38 ] ; out -> mMCON . mX [ 39 ] =
_cg_const_1 [ 39 ] ; out -> mMCON . mX [ 40 ] = _cg_const_1 [ 40 ] ; out ->
mMCON . mX [ 41 ] = _cg_const_1 [ 41 ] ; out -> mMCON . mX [ 42 ] =
_cg_const_1 [ 42 ] ; out -> mMCON . mX [ 43 ] = _cg_const_1 [ 43 ] ; out ->
mMCON . mX [ 44 ] = _cg_const_1 [ 44 ] ; out -> mMCON . mX [ 45 ] =
_cg_const_1 [ 45 ] ; out -> mMCON . mX [ 46 ] = _cg_const_1 [ 46 ] ; out ->
mMCON . mX [ 47 ] = _cg_const_1 [ 47 ] ; out -> mMCON . mX [ 48 ] =
_cg_const_1 [ 48 ] ; out -> mMCON . mX [ 49 ] = _cg_const_1 [ 49 ] ; ( void )
LC ; ( void ) out ; return 0 ; }
