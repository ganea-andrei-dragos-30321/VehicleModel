#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_bcon_p.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_bcon_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { static int32_T
_cg_const_2 [ 9 ] = { 35 , 36 , 12 , 14 , 61 , 67 , 73 , 79 , 85 } ; static
int32_T _cg_const_1 [ 8 ] = { 0 , 0 , 0 , 1 , 2 , 3 , 4 , 9 } ; ( void ) t1 ;
( void ) LC ; out -> mBCON_P . mNumCol = 7UL ; out -> mBCON_P . mNumRow =
153UL ; out -> mBCON_P . mJc [ 0 ] = _cg_const_1 [ 0 ] ; out -> mBCON_P . mJc
[ 1 ] = _cg_const_1 [ 1 ] ; out -> mBCON_P . mJc [ 2 ] = _cg_const_1 [ 2 ] ;
out -> mBCON_P . mJc [ 3 ] = _cg_const_1 [ 3 ] ; out -> mBCON_P . mJc [ 4 ] =
_cg_const_1 [ 4 ] ; out -> mBCON_P . mJc [ 5 ] = _cg_const_1 [ 5 ] ; out ->
mBCON_P . mJc [ 6 ] = _cg_const_1 [ 6 ] ; out -> mBCON_P . mJc [ 7 ] =
_cg_const_1 [ 7 ] ; out -> mBCON_P . mIr [ 0 ] = _cg_const_2 [ 0 ] ; out ->
mBCON_P . mIr [ 1 ] = _cg_const_2 [ 1 ] ; out -> mBCON_P . mIr [ 2 ] =
_cg_const_2 [ 2 ] ; out -> mBCON_P . mIr [ 3 ] = _cg_const_2 [ 3 ] ; out ->
mBCON_P . mIr [ 4 ] = _cg_const_2 [ 4 ] ; out -> mBCON_P . mIr [ 5 ] =
_cg_const_2 [ 5 ] ; out -> mBCON_P . mIr [ 6 ] = _cg_const_2 [ 6 ] ; out ->
mBCON_P . mIr [ 7 ] = _cg_const_2 [ 7 ] ; out -> mBCON_P . mIr [ 8 ] =
_cg_const_2 [ 8 ] ; ( void ) LC ; ( void ) out ; return 0 ; }
