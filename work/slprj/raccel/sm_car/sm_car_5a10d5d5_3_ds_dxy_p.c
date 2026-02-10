#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_dxy_p.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_dxy_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { static int32_T
_cg_const_1 [ 154 ] = { 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 3 , 3
, 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 5 , 7 ,
8 , 10 , 14 , 18 , 18 , 18 , 18 , 19 , 20 , 21 , 21 , 21 , 21 , 22 , 22 , 22
, 22 , 23 , 23 , 25 , 25 , 25 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 ,
26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26
, 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 ,
26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 26 , 27 , 27 , 27 , 27 , 27
, 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 ,
27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27
, 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 } ; static
int32_T _cg_const_2 [ 27 ] = { 20 , 21 , 22 , 23 , 6 , 0 , 2 , 8 , 1 , 3 , 2
, 4 , 7 , 15 , 3 , 5 , 9 , 18 , 11 , 10 , 12 , 14 , 13 , 14 , 17 , 16 , 19 }
; int32_T i ; ( void ) t1 ; ( void ) LC ; out -> mDXY_P . mNumCol = 153UL ;
out -> mDXY_P . mNumRow = 24UL ; for ( i = 0 ; i < 154 ; i ++ ) { out ->
mDXY_P . mJc [ i ] = _cg_const_1 [ i ] ; } out -> mDXY_P . mIr [ 0 ] =
_cg_const_2 [ 0 ] ; out -> mDXY_P . mIr [ 1 ] = _cg_const_2 [ 1 ] ; out ->
mDXY_P . mIr [ 2 ] = _cg_const_2 [ 2 ] ; out -> mDXY_P . mIr [ 3 ] =
_cg_const_2 [ 3 ] ; out -> mDXY_P . mIr [ 4 ] = _cg_const_2 [ 4 ] ; out ->
mDXY_P . mIr [ 5 ] = _cg_const_2 [ 5 ] ; out -> mDXY_P . mIr [ 6 ] =
_cg_const_2 [ 6 ] ; out -> mDXY_P . mIr [ 7 ] = _cg_const_2 [ 7 ] ; out ->
mDXY_P . mIr [ 8 ] = _cg_const_2 [ 8 ] ; out -> mDXY_P . mIr [ 9 ] =
_cg_const_2 [ 9 ] ; out -> mDXY_P . mIr [ 10 ] = _cg_const_2 [ 10 ] ; out ->
mDXY_P . mIr [ 11 ] = _cg_const_2 [ 11 ] ; out -> mDXY_P . mIr [ 12 ] =
_cg_const_2 [ 12 ] ; out -> mDXY_P . mIr [ 13 ] = _cg_const_2 [ 13 ] ; out ->
mDXY_P . mIr [ 14 ] = _cg_const_2 [ 14 ] ; out -> mDXY_P . mIr [ 15 ] =
_cg_const_2 [ 15 ] ; out -> mDXY_P . mIr [ 16 ] = _cg_const_2 [ 16 ] ; out ->
mDXY_P . mIr [ 17 ] = _cg_const_2 [ 17 ] ; out -> mDXY_P . mIr [ 18 ] =
_cg_const_2 [ 18 ] ; out -> mDXY_P . mIr [ 19 ] = _cg_const_2 [ 19 ] ; out ->
mDXY_P . mIr [ 20 ] = _cg_const_2 [ 20 ] ; out -> mDXY_P . mIr [ 21 ] =
_cg_const_2 [ 21 ] ; out -> mDXY_P . mIr [ 22 ] = _cg_const_2 [ 22 ] ; out ->
mDXY_P . mIr [ 23 ] = _cg_const_2 [ 23 ] ; out -> mDXY_P . mIr [ 24 ] =
_cg_const_2 [ 24 ] ; out -> mDXY_P . mIr [ 25 ] = _cg_const_2 [ 25 ] ; out ->
mDXY_P . mIr [ 26 ] = _cg_const_2 [ 26 ] ; ( void ) LC ; ( void ) out ;
return 0 ; }
