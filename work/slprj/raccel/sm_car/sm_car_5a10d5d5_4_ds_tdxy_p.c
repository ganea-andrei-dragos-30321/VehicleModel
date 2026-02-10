#include "ne_ds.h"
#include "sm_car_5a10d5d5_4_ds_sys_struct.h"
#include "sm_car_5a10d5d5_4_ds_tdxy_p.h"
#include "sm_car_5a10d5d5_4_ds.h"
#include "sm_car_5a10d5d5_4_ds_externals.h"
#include "sm_car_5a10d5d5_4_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_4_ds_tdxy_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { static int32_T
_cg_const_1 [ 8 ] = { 0 , 0 , 1 , 2 , 2 , 4 , 6 , 8 } ; static int32_T
_cg_const_2 [ 8 ] = { 2 , 4 , 0 , 6 , 1 , 6 , 5 , 6 } ; ( void ) t1 ; out ->
mTDXY_P . mNumCol = 7UL ; out -> mTDXY_P . mNumRow = 7UL ; out -> mTDXY_P .
mJc [ 0 ] = _cg_const_1 [ 0 ] ; out -> mTDXY_P . mJc [ 1 ] = _cg_const_1 [ 1
] ; out -> mTDXY_P . mJc [ 2 ] = _cg_const_1 [ 2 ] ; out -> mTDXY_P . mJc [ 3
] = _cg_const_1 [ 3 ] ; out -> mTDXY_P . mJc [ 4 ] = _cg_const_1 [ 4 ] ; out
-> mTDXY_P . mJc [ 5 ] = _cg_const_1 [ 5 ] ; out -> mTDXY_P . mJc [ 6 ] =
_cg_const_1 [ 6 ] ; out -> mTDXY_P . mJc [ 7 ] = _cg_const_1 [ 7 ] ; out ->
mTDXY_P . mIr [ 0 ] = _cg_const_2 [ 0 ] ; out -> mTDXY_P . mIr [ 1 ] =
_cg_const_2 [ 1 ] ; out -> mTDXY_P . mIr [ 2 ] = _cg_const_2 [ 2 ] ; out ->
mTDXY_P . mIr [ 3 ] = _cg_const_2 [ 3 ] ; out -> mTDXY_P . mIr [ 4 ] =
_cg_const_2 [ 4 ] ; out -> mTDXY_P . mIr [ 5 ] = _cg_const_2 [ 5 ] ; out ->
mTDXY_P . mIr [ 6 ] = _cg_const_2 [ 6 ] ; out -> mTDXY_P . mIr [ 7 ] =
_cg_const_2 [ 7 ] ; ( void ) sys ; ( void ) out ; return 0 ; }
