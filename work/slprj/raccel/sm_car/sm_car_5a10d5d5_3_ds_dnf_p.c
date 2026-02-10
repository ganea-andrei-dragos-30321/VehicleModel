#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_dnf_p.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_dnf_p ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * out ) { static int32_T
_cg_const_1 [ 430 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 ,
2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3
, 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 ,
4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5
, 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 ,
6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6
, 6 , 6 , 6 , 6 , 6 , 6 , 6 , 7 , 8 , 8 , 10 , 10 , 10 , 10 , 10 , 12 , 12 ,
12 , 12 , 12 , 12 , 12 , 12 , 12 , 12 , 12 , 12 , 12 , 13 , 13 , 13 , 13 , 13
, 13 , 13 , 13 , 14 , 14 , 14 , 14 , 14 , 14 , 14 , 14 , 14 , 14 , 14 , 14 ,
14 , 14 , 14 , 14 , 14 , 14 , 14 , 14 , 14 , 14 , 15 , 15 , 15 , 15 , 15 , 15
, 15 , 15 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 ,
16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 17 , 17 , 17 , 17
, 17 , 17 , 17 , 17 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 ,
18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18
, 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 19 , 19 ,
19 , 19 , 19 , 19 , 19 , 19 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20
, 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 20 , 21 ,
21 , 21 , 21 , 21 , 21 , 21 , 21 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22
, 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 ,
22 , 22 , 22 , 22 , 22 , 22 , 23 , 23 , 24 , 24 , 24 , 24 , 24 , 24 , 24 , 25
, 25 , 25 } ; static int32_T _cg_const_2 [ 25 ] = { 90 , 97 , 104 , 111 , 118
, 125 , 140 , 143 , 140 , 143 , 142 , 144 , 104 , 106 , 111 , 113 , 118 , 120
, 90 , 92 , 97 , 99 , 54 , 39 , 49 } ; int32_T i ; ( void ) t1 ; ( void ) LC
; out -> mDNF_P . mNumCol = 429UL ; out -> mDNF_P . mNumRow = 153UL ; for ( i
= 0 ; i < 430 ; i ++ ) { out -> mDNF_P . mJc [ i ] = _cg_const_1 [ i ] ; }
out -> mDNF_P . mIr [ 0 ] = _cg_const_2 [ 0 ] ; out -> mDNF_P . mIr [ 1 ] =
_cg_const_2 [ 1 ] ; out -> mDNF_P . mIr [ 2 ] = _cg_const_2 [ 2 ] ; out ->
mDNF_P . mIr [ 3 ] = _cg_const_2 [ 3 ] ; out -> mDNF_P . mIr [ 4 ] =
_cg_const_2 [ 4 ] ; out -> mDNF_P . mIr [ 5 ] = _cg_const_2 [ 5 ] ; out ->
mDNF_P . mIr [ 6 ] = _cg_const_2 [ 6 ] ; out -> mDNF_P . mIr [ 7 ] =
_cg_const_2 [ 7 ] ; out -> mDNF_P . mIr [ 8 ] = _cg_const_2 [ 8 ] ; out ->
mDNF_P . mIr [ 9 ] = _cg_const_2 [ 9 ] ; out -> mDNF_P . mIr [ 10 ] =
_cg_const_2 [ 10 ] ; out -> mDNF_P . mIr [ 11 ] = _cg_const_2 [ 11 ] ; out ->
mDNF_P . mIr [ 12 ] = _cg_const_2 [ 12 ] ; out -> mDNF_P . mIr [ 13 ] =
_cg_const_2 [ 13 ] ; out -> mDNF_P . mIr [ 14 ] = _cg_const_2 [ 14 ] ; out ->
mDNF_P . mIr [ 15 ] = _cg_const_2 [ 15 ] ; out -> mDNF_P . mIr [ 16 ] =
_cg_const_2 [ 16 ] ; out -> mDNF_P . mIr [ 17 ] = _cg_const_2 [ 17 ] ; out ->
mDNF_P . mIr [ 18 ] = _cg_const_2 [ 18 ] ; out -> mDNF_P . mIr [ 19 ] =
_cg_const_2 [ 19 ] ; out -> mDNF_P . mIr [ 20 ] = _cg_const_2 [ 20 ] ; out ->
mDNF_P . mIr [ 21 ] = _cg_const_2 [ 21 ] ; out -> mDNF_P . mIr [ 22 ] =
_cg_const_2 [ 22 ] ; out -> mDNF_P . mIr [ 23 ] = _cg_const_2 [ 23 ] ; out ->
mDNF_P . mIr [ 24 ] = _cg_const_2 [ 24 ] ; ( void ) LC ; ( void ) out ;
return 0 ; }
