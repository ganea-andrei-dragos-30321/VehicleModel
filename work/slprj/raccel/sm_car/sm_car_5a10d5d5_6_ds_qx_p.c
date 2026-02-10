#include "ne_ds.h"
#include "sm_car_5a10d5d5_6_ds_sys_struct.h"
#include "sm_car_5a10d5d5_6_ds_qx_p.h"
#include "sm_car_5a10d5d5_6_ds.h"
#include "sm_car_5a10d5d5_6_ds_externals.h"
#include "sm_car_5a10d5d5_6_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_6_ds_qx_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { static int32_T
_cg_const_2 [ 9 ] = { 4 , 5 , 6 , 4 , 5 , 6 , 4 , 5 , 6 } ; static int32_T
_cg_const_1 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 3 , 6 , 9 } ; ( void ) t1 ; out ->
mQX_P . mNumCol = 7UL ; out -> mQX_P . mNumRow = 7UL ; out -> mQX_P . mJc [ 0
] = _cg_const_1 [ 0 ] ; out -> mQX_P . mJc [ 1 ] = _cg_const_1 [ 1 ] ; out ->
mQX_P . mJc [ 2 ] = _cg_const_1 [ 2 ] ; out -> mQX_P . mJc [ 3 ] =
_cg_const_1 [ 3 ] ; out -> mQX_P . mJc [ 4 ] = _cg_const_1 [ 4 ] ; out ->
mQX_P . mJc [ 5 ] = _cg_const_1 [ 5 ] ; out -> mQX_P . mJc [ 6 ] =
_cg_const_1 [ 6 ] ; out -> mQX_P . mJc [ 7 ] = _cg_const_1 [ 7 ] ; out ->
mQX_P . mIr [ 0 ] = _cg_const_2 [ 0 ] ; out -> mQX_P . mIr [ 1 ] =
_cg_const_2 [ 1 ] ; out -> mQX_P . mIr [ 2 ] = _cg_const_2 [ 2 ] ; out ->
mQX_P . mIr [ 3 ] = _cg_const_2 [ 3 ] ; out -> mQX_P . mIr [ 4 ] =
_cg_const_2 [ 4 ] ; out -> mQX_P . mIr [ 5 ] = _cg_const_2 [ 5 ] ; out ->
mQX_P . mIr [ 6 ] = _cg_const_2 [ 6 ] ; out -> mQX_P . mIr [ 7 ] =
_cg_const_2 [ 7 ] ; out -> mQX_P . mIr [ 8 ] = _cg_const_2 [ 8 ] ; ( void )
sys ; ( void ) out ; return 0 ; }
