#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_mcon_p.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_mcon_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { static int32_T
_cg_const_1 [ 154 ] = { 0 , 1 , 2 , 3 , 4 , 9 , 14 , 19 , 24 , 29 , 30 , 31 ,
32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47
, 48 , 49 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 ,
50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50
, 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 ,
50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50
, 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 ,
50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50
, 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 ,
50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50
, 50 , 50 } ; static int32_T _cg_const_2 [ 50 ] = { 0 , 9 , 2 , 3 , 4 , 5 , 6
, 7 , 8 , 4 , 5 , 6 , 7 , 8 , 4 , 5 , 6 , 7 , 8 , 4 , 5 , 6 , 7 , 8 , 4 , 5 ,
6 , 7 , 8 , 11 , 10 , 13 , 12 , 15 , 14 , 1 , 16 , 22 , 17 , 23 , 18 , 25 ,
19 , 28 , 20 , 21 , 24 , 26 , 27 , 29 } ; int32_T i ; ( void ) t1 ; ( void )
LC ; out -> mMCON_P . mNumCol = 153UL ; out -> mMCON_P . mNumRow = 153UL ;
for ( i = 0 ; i < 154 ; i ++ ) { out -> mMCON_P . mJc [ i ] = _cg_const_1 [ i
] ; } out -> mMCON_P . mIr [ 0 ] = _cg_const_2 [ 0 ] ; out -> mMCON_P . mIr [
1 ] = _cg_const_2 [ 1 ] ; out -> mMCON_P . mIr [ 2 ] = _cg_const_2 [ 2 ] ;
out -> mMCON_P . mIr [ 3 ] = _cg_const_2 [ 3 ] ; out -> mMCON_P . mIr [ 4 ] =
_cg_const_2 [ 4 ] ; out -> mMCON_P . mIr [ 5 ] = _cg_const_2 [ 5 ] ; out ->
mMCON_P . mIr [ 6 ] = _cg_const_2 [ 6 ] ; out -> mMCON_P . mIr [ 7 ] =
_cg_const_2 [ 7 ] ; out -> mMCON_P . mIr [ 8 ] = _cg_const_2 [ 8 ] ; out ->
mMCON_P . mIr [ 9 ] = _cg_const_2 [ 9 ] ; out -> mMCON_P . mIr [ 10 ] =
_cg_const_2 [ 10 ] ; out -> mMCON_P . mIr [ 11 ] = _cg_const_2 [ 11 ] ; out
-> mMCON_P . mIr [ 12 ] = _cg_const_2 [ 12 ] ; out -> mMCON_P . mIr [ 13 ] =
_cg_const_2 [ 13 ] ; out -> mMCON_P . mIr [ 14 ] = _cg_const_2 [ 14 ] ; out
-> mMCON_P . mIr [ 15 ] = _cg_const_2 [ 15 ] ; out -> mMCON_P . mIr [ 16 ] =
_cg_const_2 [ 16 ] ; out -> mMCON_P . mIr [ 17 ] = _cg_const_2 [ 17 ] ; out
-> mMCON_P . mIr [ 18 ] = _cg_const_2 [ 18 ] ; out -> mMCON_P . mIr [ 19 ] =
_cg_const_2 [ 19 ] ; out -> mMCON_P . mIr [ 20 ] = _cg_const_2 [ 20 ] ; out
-> mMCON_P . mIr [ 21 ] = _cg_const_2 [ 21 ] ; out -> mMCON_P . mIr [ 22 ] =
_cg_const_2 [ 22 ] ; out -> mMCON_P . mIr [ 23 ] = _cg_const_2 [ 23 ] ; out
-> mMCON_P . mIr [ 24 ] = _cg_const_2 [ 24 ] ; out -> mMCON_P . mIr [ 25 ] =
_cg_const_2 [ 25 ] ; out -> mMCON_P . mIr [ 26 ] = _cg_const_2 [ 26 ] ; out
-> mMCON_P . mIr [ 27 ] = _cg_const_2 [ 27 ] ; out -> mMCON_P . mIr [ 28 ] =
_cg_const_2 [ 28 ] ; out -> mMCON_P . mIr [ 29 ] = _cg_const_2 [ 29 ] ; out
-> mMCON_P . mIr [ 30 ] = _cg_const_2 [ 30 ] ; out -> mMCON_P . mIr [ 31 ] =
_cg_const_2 [ 31 ] ; out -> mMCON_P . mIr [ 32 ] = _cg_const_2 [ 32 ] ; out
-> mMCON_P . mIr [ 33 ] = _cg_const_2 [ 33 ] ; out -> mMCON_P . mIr [ 34 ] =
_cg_const_2 [ 34 ] ; out -> mMCON_P . mIr [ 35 ] = _cg_const_2 [ 35 ] ; out
-> mMCON_P . mIr [ 36 ] = _cg_const_2 [ 36 ] ; out -> mMCON_P . mIr [ 37 ] =
_cg_const_2 [ 37 ] ; out -> mMCON_P . mIr [ 38 ] = _cg_const_2 [ 38 ] ; out
-> mMCON_P . mIr [ 39 ] = _cg_const_2 [ 39 ] ; out -> mMCON_P . mIr [ 40 ] =
_cg_const_2 [ 40 ] ; out -> mMCON_P . mIr [ 41 ] = _cg_const_2 [ 41 ] ; out
-> mMCON_P . mIr [ 42 ] = _cg_const_2 [ 42 ] ; out -> mMCON_P . mIr [ 43 ] =
_cg_const_2 [ 43 ] ; out -> mMCON_P . mIr [ 44 ] = _cg_const_2 [ 44 ] ; out
-> mMCON_P . mIr [ 45 ] = _cg_const_2 [ 45 ] ; out -> mMCON_P . mIr [ 46 ] =
_cg_const_2 [ 46 ] ; out -> mMCON_P . mIr [ 47 ] = _cg_const_2 [ 47 ] ; out
-> mMCON_P . mIr [ 48 ] = _cg_const_2 [ 48 ] ; out -> mMCON_P . mIr [ 49 ] =
_cg_const_2 [ 49 ] ; ( void ) LC ; ( void ) out ; return 0 ; }
