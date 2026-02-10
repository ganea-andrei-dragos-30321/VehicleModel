#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "pm_default_allocator.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ssc_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "sm_car_5a10d5d5_1_geometries.h"
PmfMessageId sm_car_5a10d5d5_1_compOutputsKin ( const
RuntimeDerivedValuesBundle * rtdv , const double * state , const int *
modeVector , const double * input , const double * inputDot , const double *
inputDdot , const double * discreteState , double * output ,
NeuDiagnosticManager * neDiagMgr ) { const double * rtdvd = rtdv -> mDoubles
. mValues ; const int * rtdvi = rtdv -> mInts . mValues ; double xx [ 285 ] ;
( void ) rtdvi ; ( void ) modeVector ; ( void ) inputDot ; ( void ) inputDdot
; ( void ) discreteState ; ( void ) neDiagMgr ; xx [ 0 ] = 0.3353569033338412
; xx [ 1 ] = 0.1616473669588805 ; xx [ 2 ] = 0.05852441872969549 ; xx [ 3 ] =
- 0.926272513115848 ; xx [ 4 ] = - xx [ 0 ] ; xx [ 5 ] = xx [ 1 ] ; xx [ 6 ]
= xx [ 2 ] ; xx [ 7 ] = xx [ 3 ] ; xx [ 8 ] = state [ 6 ] ; xx [ 9 ] = state
[ 7 ] ; xx [ 10 ] = state [ 8 ] ; xx [ 11 ] = state [ 9 ] ; xx [ 12 ] =
0.9999999927733129 ; xx [ 13 ] = - 5.209712147002225e-5 ; xx [ 14 ] = -
1.075253021477014e-4 ; xx [ 15 ] = - 1.332568762347739e-5 ;
pm_math_Quaternion_composeInverse_ra ( xx + 8 , xx + 12 , xx + 16 ) ;
pm_math_Quaternion_compose_ra ( xx + 4 , xx + 16 , xx + 8 ) ;
pm_math_Quaternion_compose_ra ( xx + 0 , xx + 8 , xx + 4 ) ; xx [ 16 ] = - xx
[ 4 ] ; xx [ 17 ] = - xx [ 5 ] ; xx [ 18 ] = - xx [ 6 ] ; xx [ 19 ] = - xx [
7 ] ; xx [ 20 ] = 0.8737353102512165 ; xx [ 21 ] = 8.59724871576778e-5 ; xx [
22 ] = 0.3505602187708891 ; xx [ 23 ] = xx [ 20 ] ; xx [ 24 ] = - xx [ 21 ] ;
xx [ 25 ] = - xx [ 22 ] ; pm_math_Quaternion_xform_ra ( xx + 16 , xx + 23 ,
xx + 26 ) ; xx [ 23 ] = - 0.1087353282122912 ; xx [ 24 ] =
6.559275593194972e-5 ; xx [ 25 ] = 0.3507247335441581 ;
pm_math_Quaternion_xform_ra ( xx + 8 , xx + 23 , xx + 29 ) ;
pm_math_Quaternion_xform_ra ( xx + 0 , xx + 29 , xx + 32 ) ; xx [ 0 ] = xx [
32 ] + state [ 0 ] ; xx [ 1 ] = - ( 0.7228117522831952 * state [ 3 ] +
0.6023431269026627 * state [ 4 ] + 0.3387121613323313 * state [ 5 ] ) ; xx [
2 ] = 0.6401843996644798 * state [ 3 ] - 0.7682212795973757 * state [ 4 ] ;
xx [ 3 ] = 0.9408900423352246 * state [ 5 ] - ( 0.2602058899939164 * state [
3 ] + 0.216838241661597 * state [ 4 ] ) ; pm_math_Quaternion_inverseXform_ra
( xx + 8 , xx + 1 , xx + 29 ) ; xx [ 1 ] = state [ 10 ] ; xx [ 2 ] = state [
11 ] ; xx [ 3 ] = state [ 12 ] ; pm_math_Quaternion_xform_ra ( xx + 12 , xx +
1 , xx + 8 ) ; pm_math_Vector3_cross_ra ( xx + 8 , xx + 23 , xx + 1 ) ; xx [
11 ] = xx [ 29 ] + xx [ 1 ] ; xx [ 23 ] = - xx [ 20 ] ; xx [ 24 ] = xx [ 21 ]
; xx [ 25 ] = xx [ 22 ] ; pm_math_Vector3_cross_ra ( xx + 8 , xx + 23 , xx +
20 ) ; xx [ 23 ] = xx [ 30 ] + xx [ 2 ] ; xx [ 1 ] = xx [ 31 ] + xx [ 3 ] ;
xx [ 29 ] = xx [ 11 ] - xx [ 20 ] ; xx [ 30 ] = xx [ 23 ] - xx [ 21 ] ; xx [
31 ] = xx [ 1 ] - xx [ 22 ] ; pm_math_Quaternion_xform_ra ( xx + 16 , xx + 29
, xx + 20 ) ; xx [ 2 ] = 9.87654321 ; xx [ 3 ] = xx [ 33 ] + state [ 1 ] ; xx
[ 24 ] = xx [ 34 ] + state [ 2 ] ; pm_math_Quaternion_compose_ra ( xx + 16 ,
xx + 12 , xx + 29 ) ; xx [ 16 ] = - xx [ 29 ] ; xx [ 17 ] = - xx [ 30 ] ; xx
[ 18 ] = - xx [ 31 ] ; xx [ 19 ] = - xx [ 32 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 12 , xx + 8 , xx + 29 ) ;
pm_math_Quaternion_xform_ra ( xx + 16 , xx + 29 , xx + 32 ) ; xx [ 25 ] = 2.0
; pm_math_Quaternion_compose_ra ( xx + 4 , xx + 12 , xx + 35 ) ; xx [ 29 ] =
xx [ 35 ] * xx [ 35 ] ; xx [ 30 ] = 1.0 ; xx [ 39 ] = xx [ 25 ] * ( xx [ 29 ]
+ xx [ 36 ] * xx [ 36 ] ) - xx [ 30 ] ; xx [ 40 ] = xx [ 36 ] * xx [ 37 ] ;
xx [ 41 ] = xx [ 35 ] * xx [ 38 ] ; xx [ 42 ] = xx [ 25 ] * ( xx [ 40 ] + xx
[ 41 ] ) ; xx [ 43 ] = xx [ 36 ] * xx [ 38 ] ; xx [ 44 ] = xx [ 35 ] * xx [
37 ] ; xx [ 45 ] = xx [ 25 ] * ( xx [ 43 ] - xx [ 44 ] ) ; xx [ 46 ] = xx [
25 ] * ( xx [ 40 ] - xx [ 41 ] ) ; xx [ 40 ] = xx [ 25 ] * ( xx [ 29 ] + xx [
37 ] * xx [ 37 ] ) - xx [ 30 ] ; xx [ 41 ] = xx [ 37 ] * xx [ 38 ] ; xx [ 47
] = xx [ 35 ] * xx [ 36 ] ; xx [ 48 ] = xx [ 25 ] * ( xx [ 41 ] + xx [ 47 ] )
; xx [ 49 ] = xx [ 25 ] * ( xx [ 43 ] + xx [ 44 ] ) ; xx [ 43 ] = xx [ 25 ] *
( xx [ 41 ] - xx [ 47 ] ) ; xx [ 41 ] = xx [ 25 ] * ( xx [ 29 ] + xx [ 38 ] *
xx [ 38 ] ) - xx [ 30 ] ; xx [ 50 ] = 0.07367941623832658 ; xx [ 51 ] = -
3.756910187825547e-5 ; xx [ 52 ] = - 0.09073226778726644 ;
pm_math_Vector3_cross_ra ( xx + 8 , xx + 50 , xx + 53 ) ; xx [ 50 ] = xx [ 11
] + xx [ 53 ] ; xx [ 51 ] = xx [ 23 ] + xx [ 54 ] ; xx [ 52 ] = xx [ 1 ] + xx
[ 55 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 12 , xx + 50 , xx + 53 ) ;
xx [ 54 ] = - xx [ 35 ] ; xx [ 55 ] = - xx [ 36 ] ; xx [ 56 ] = - xx [ 37 ] ;
xx [ 57 ] = - xx [ 38 ] ; xx [ 35 ] = - 4.399364511996752e-4 ; xx [ 36 ] = -
2.621732545778951e-5 ; xx [ 37 ] = - 7.48205709458595e-4 ;
pm_math_Quaternion_xform_ra ( xx + 4 , xx + 35 , xx + 50 ) ; xx [ 58 ] = xx [
50 ] + xx [ 0 ] ; xx [ 59 ] = xx [ 51 ] + xx [ 3 ] ; xx [ 60 ] = xx [ 52 ] +
xx [ 24 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 54 , xx + 58 , xx + 50
) ; pm_math_Vector3_cross_ra ( xx + 8 , xx + 35 , xx + 58 ) ; xx [ 35 ] = xx
[ 58 ] + xx [ 11 ] ; xx [ 36 ] = xx [ 59 ] + xx [ 23 ] ; xx [ 37 ] = xx [ 60
] + xx [ 1 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 12 , xx + 35 , xx +
58 ) ; xx [ 29 ] = 4.624544703080158e-5 ; xx [ 35 ] = 0.5 ; xx [ 36 ] = xx [
35 ] * state [ 87 ] ; xx [ 37 ] = cos ( xx [ 36 ] ) ; xx [ 38 ] =
2.744162249240789e-5 ; xx [ 44 ] = sin ( xx [ 36 ] ) ; xx [ 36 ] = xx [ 29 ]
* xx [ 37 ] + xx [ 38 ] * xx [ 44 ] ; xx [ 47 ] = 0.2439270907720174 ; xx [
61 ] = state [ 89 ] - xx [ 47 ] ; xx [ 62 ] = xx [ 36 ] * xx [ 61 ] ; xx [ 63
] = xx [ 29 ] * xx [ 44 ] - xx [ 38 ] * xx [ 37 ] ; xx [ 29 ] =
0.7075813371829627 ; xx [ 38 ] = 0.7066319044443767 ; xx [ 64 ] = xx [ 29 ] *
xx [ 37 ] - xx [ 38 ] * xx [ 44 ] ; xx [ 65 ] = xx [ 61 ] * xx [ 64 ] ; xx [
66 ] = xx [ 38 ] * xx [ 37 ] + xx [ 29 ] * xx [ 44 ] ; xx [ 29 ] = xx [ 35 ]
* input [ 4 ] ; xx [ 37 ] = sin ( xx [ 29 ] ) ; xx [ 38 ] = cos ( xx [ 29 ] )
; xx [ 29 ] = xx [ 36 ] * xx [ 37 ] - xx [ 64 ] * xx [ 38 ] ; xx [ 44 ] = xx
[ 47 ] * xx [ 29 ] ; xx [ 67 ] = xx [ 63 ] * xx [ 37 ] + xx [ 66 ] * xx [ 38
] ; xx [ 68 ] = xx [ 36 ] * xx [ 38 ] + xx [ 64 ] * xx [ 37 ] ; xx [ 69 ] =
xx [ 47 ] * xx [ 68 ] ; xx [ 47 ] = xx [ 63 ] * xx [ 38 ] - xx [ 66 ] * xx [
37 ] ; xx [ 37 ] = 0.2074282812441162 ; xx [ 38 ] = 0.7025153126367782 ; xx [
70 ] = xx [ 35 ] * state [ 85 ] ; xx [ 71 ] = cos ( xx [ 70 ] ) ; xx [ 72 ] =
0.702504968825822 ; xx [ 73 ] = sin ( xx [ 70 ] ) ; xx [ 70 ] = xx [ 38 ] *
xx [ 71 ] + xx [ 72 ] * xx [ 73 ] ; xx [ 74 ] = xx [ 37 ] * xx [ 70 ] ; xx [
75 ] = 0.08045767512018399 ; xx [ 76 ] = 0.08053301683244936 ; xx [ 77 ] = xx
[ 75 ] * xx [ 71 ] + xx [ 76 ] * xx [ 73 ] ; xx [ 78 ] = xx [ 72 ] * xx [ 71
] - xx [ 38 ] * xx [ 73 ] ; xx [ 38 ] = xx [ 37 ] * xx [ 78 ] ; xx [ 37 ] =
xx [ 76 ] * xx [ 71 ] - xx [ 75 ] * xx [ 73 ] ; xx [ 71 ] = 0.165942624995293
; xx [ 72 ] = xx [ 71 ] * xx [ 70 ] ; xx [ 73 ] = xx [ 71 ] * xx [ 78 ] ; xx
[ 79 ] = xx [ 25 ] * ( xx [ 62 ] * xx [ 63 ] - xx [ 65 ] * xx [ 66 ] ) - xx [
25 ] * ( xx [ 44 ] * xx [ 67 ] + xx [ 69 ] * xx [ 47 ] ) + xx [ 25 ] * ( xx [
74 ] * xx [ 77 ] + xx [ 38 ] * xx [ 37 ] ) + xx [ 25 ] * ( xx [ 72 ] * xx [
77 ] + xx [ 73 ] * xx [ 37 ] ) - 0.4159877774007961 ; xx [ 80 ] = xx [ 25 ] *
( xx [ 44 ] * xx [ 47 ] - xx [ 69 ] * xx [ 67 ] ) + xx [ 25 ] * ( xx [ 65 ] *
xx [ 63 ] + xx [ 62 ] * xx [ 66 ] ) - ( xx [ 25 ] * ( xx [ 74 ] * xx [ 37 ] -
xx [ 38 ] * xx [ 77 ] ) - xx [ 25 ] * ( xx [ 73 ] * xx [ 77 ] - xx [ 72 ] *
xx [ 37 ] ) ) + 4.919766226684439e-5 ; xx [ 81 ] = xx [ 61 ] - xx [ 25 ] * ( xx
[ 62 ] * xx [ 36 ] + xx [ 65 ] * xx [ 64 ] ) + xx [ 25 ] * ( xx [ 69 ] * xx [
68 ] + xx [ 44 ] * xx [ 29 ] ) - ( xx [ 25 ] * ( xx [ 73 ] * xx [ 78 ] + xx [
72 ] * xx [ 70 ] ) + xx [ 25 ] * ( xx [ 38 ] * xx [ 78 ] + xx [ 74 ] * xx [
70 ] ) ) + 0.4951780678232347 ; pm_math_Quaternion_xform_ra ( xx + 4 , xx +
79 , xx + 36 ) ; xx [ 61 ] = rtdvd [ 678 ] ; xx [ 62 ] = rtdvd [ 679 ] ; xx [
63 ] = rtdvd [ 680 ] ; xx [ 64 ] = rtdvd [ 681 ] ; xx [ 29 ] = xx [ 35 ] *
state [ 39 ] ; xx [ 44 ] = sin ( xx [ 29 ] ) ; xx [ 65 ] = cos ( xx [ 29 ] )
; xx [ 66 ] = rtdvd [ 666 ] * xx [ 44 ] ; xx [ 67 ] = rtdvd [ 667 ] * xx [ 44
] ; xx [ 68 ] = rtdvd [ 668 ] * xx [ 44 ] ; pm_math_Quaternion_compose_ra ( xx
+ 61 , xx + 65 , xx + 69 ) ; xx [ 61 ] = rtdvd [ 725 ] ; xx [ 62 ] = rtdvd [
726 ] ; xx [ 63 ] = rtdvd [ 727 ] ; xx [ 64 ] = rtdvd [ 728 ] ;
pm_math_Quaternion_compose_ra ( xx + 69 , xx + 61 , xx + 65 ) ; xx [ 73 ] =
rtdvd [ 980 ] ; xx [ 74 ] = rtdvd [ 981 ] ; xx [ 75 ] = rtdvd [ 982 ] ; xx [
76 ] = rtdvd [ 983 ] ; xx [ 77 ] = state [ 45 ] ; xx [ 78 ] = state [ 46 ] ;
xx [ 79 ] = state [ 47 ] ; xx [ 80 ] = state [ 48 ] ; xx [ 81 ] = rtdvd [ 987
] ; xx [ 82 ] = rtdvd [ 988 ] ; xx [ 83 ] = rtdvd [ 989 ] ; xx [ 84 ] = rtdvd
[ 990 ] ; pm_math_Quaternion_composeInverse_ra ( xx + 77 , xx + 81 , xx + 85
) ; pm_math_Quaternion_compose_ra ( xx + 73 , xx + 85 , xx + 77 ) ;
pm_math_Quaternion_compose_ra ( xx + 65 , xx + 77 , xx + 73 ) ; xx [ 29 ] =
xx [ 35 ] * state [ 52 ] ; xx [ 44 ] = cos ( xx [ 29 ] ) ; xx [ 47 ] = sin ( xx
[ 29 ] ) ; xx [ 29 ] = rtdvd [ 1037 ] * xx [ 44 ] - rtdvd [ 1040 ] * xx [ 47
] ; xx [ 65 ] = rtdvd [ 1038 ] * xx [ 44 ] + rtdvd [ 1039 ] * xx [ 47 ] ; xx
[ 66 ] = rtdvd [ 1039 ] * xx [ 44 ] - rtdvd [ 1038 ] * xx [ 47 ] ; xx [ 67 ]
= rtdvd [ 1037 ] * xx [ 47 ] + rtdvd [ 1040 ] * xx [ 44 ] ; xx [ 85 ] = xx [
29 ] ; xx [ 86 ] = xx [ 65 ] ; xx [ 87 ] = xx [ 66 ] ; xx [ 88 ] = xx [ 67 ]
; pm_math_Quaternion_compose_ra ( xx + 73 , xx + 85 , xx + 89 ) ;
pm_math_Quaternion_inverseCompose_ra ( xx + 12 , xx + 89 , xx + 73 ) ; xx [
44 ] = xx [ 73 ] * xx [ 73 ] ; xx [ 47 ] = xx [ 74 ] * xx [ 75 ] ; xx [ 68 ]
= xx [ 73 ] * xx [ 76 ] ; xx [ 89 ] = xx [ 74 ] * xx [ 76 ] ; xx [ 90 ] = xx
[ 73 ] * xx [ 75 ] ; xx [ 91 ] = xx [ 75 ] * xx [ 76 ] ; xx [ 92 ] = xx [ 73
] * xx [ 74 ] ; xx [ 93 ] = rtdvd [ 1300 ] ; xx [ 94 ] = rtdvd [ 1301 ] ; xx
[ 95 ] = rtdvd [ 1302 ] ; xx [ 96 ] = rtdvd [ 1303 ] ; xx [ 73 ] = xx [ 35 ]
* state [ 62 ] ; xx [ 97 ] = sin ( xx [ 73 ] ) ; xx [ 98 ] = cos ( xx [ 73 ]
) ; xx [ 99 ] = rtdvd [ 1288 ] * xx [ 97 ] ; xx [ 100 ] = rtdvd [ 1289 ] * xx
[ 97 ] ; xx [ 101 ] = rtdvd [ 1290 ] * xx [ 97 ] ;
pm_math_Quaternion_compose_ra ( xx + 93 , xx + 98 , xx + 102 ) ; xx [ 93 ] =
rtdvd [ 1347 ] ; xx [ 94 ] = rtdvd [ 1348 ] ; xx [ 95 ] = rtdvd [ 1349 ] ; xx
[ 96 ] = rtdvd [ 1350 ] ; pm_math_Quaternion_compose_ra ( xx + 102 , xx + 93
, xx + 97 ) ; xx [ 106 ] = rtdvd [ 1602 ] ; xx [ 107 ] = rtdvd [ 1603 ] ; xx
[ 108 ] = rtdvd [ 1604 ] ; xx [ 109 ] = rtdvd [ 1605 ] ; xx [ 110 ] = state [
68 ] ; xx [ 111 ] = state [ 69 ] ; xx [ 112 ] = state [ 70 ] ; xx [ 113 ] =
state [ 71 ] ; xx [ 114 ] = rtdvd [ 1609 ] ; xx [ 115 ] = rtdvd [ 1610 ] ; xx
[ 116 ] = rtdvd [ 1611 ] ; xx [ 117 ] = rtdvd [ 1612 ] ;
pm_math_Quaternion_composeInverse_ra ( xx + 110 , xx + 114 , xx + 118 ) ;
pm_math_Quaternion_compose_ra ( xx + 106 , xx + 118 , xx + 110 ) ;
pm_math_Quaternion_compose_ra ( xx + 97 , xx + 110 , xx + 106 ) ; xx [ 73 ] =
xx [ 35 ] * state [ 75 ] ; xx [ 97 ] = cos ( xx [ 73 ] ) ; xx [ 98 ] = sin ( xx
[ 73 ] ) ; xx [ 73 ] = rtdvd [ 1659 ] * xx [ 97 ] - rtdvd [ 1662 ] * xx [ 98
] ; xx [ 99 ] = rtdvd [ 1660 ] * xx [ 97 ] + rtdvd [ 1661 ] * xx [ 98 ] ; xx
[ 100 ] = rtdvd [ 1661 ] * xx [ 97 ] - rtdvd [ 1660 ] * xx [ 98 ] ; xx [ 101
] = rtdvd [ 1659 ] * xx [ 98 ] + rtdvd [ 1662 ] * xx [ 97 ] ; xx [ 118 ] = xx
[ 73 ] ; xx [ 119 ] = xx [ 99 ] ; xx [ 120 ] = xx [ 100 ] ; xx [ 121 ] = xx [
101 ] ; pm_math_Quaternion_compose_ra ( xx + 106 , xx + 118 , xx + 122 ) ;
pm_math_Quaternion_inverseCompose_ra ( xx + 12 , xx + 122 , xx + 106 ) ; xx [
97 ] = xx [ 106 ] * xx [ 106 ] ; xx [ 98 ] = xx [ 107 ] * xx [ 108 ] ; xx [
122 ] = xx [ 106 ] * xx [ 109 ] ; xx [ 123 ] = xx [ 107 ] * xx [ 109 ] ; xx [
124 ] = xx [ 106 ] * xx [ 108 ] ; xx [ 125 ] = xx [ 108 ] * xx [ 109 ] ; xx [
126 ] = xx [ 106 ] * xx [ 107 ] ; xx [ 127 ] = - 1.575439899472517 ; xx [ 128
] = 1.574094471282714e-5 ; xx [ 129 ] = - 1.086912595600537e-3 ;
pm_math_Quaternion_xform_ra ( xx + 4 , xx + 127 , xx + 130 ) ; xx [ 133 ] =
xx [ 130 ] + xx [ 0 ] ; xx [ 134 ] = xx [ 131 ] + xx [ 3 ] ; xx [ 135 ] = xx
[ 132 ] + xx [ 24 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 54 , xx + 133
, xx + 130 ) ; pm_math_Vector3_cross_ra ( xx + 8 , xx + 127 , xx + 54 ) ; xx
[ 127 ] = xx [ 54 ] + xx [ 11 ] ; xx [ 128 ] = xx [ 55 ] + xx [ 23 ] ; xx [
129 ] = xx [ 56 ] + xx [ 1 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 12 ,
xx + 127 , xx + 54 ) ; xx [ 133 ] = rtdvd [ 2274 ] ; xx [ 134 ] = rtdvd [
2275 ] ; xx [ 135 ] = rtdvd [ 2276 ] ; xx [ 136 ] = rtdvd [ 2277 ] ; xx [ 57
] = xx [ 35 ] * state [ 107 ] ; xx [ 106 ] = sin ( xx [ 57 ] ) ; xx [ 137 ] =
cos ( xx [ 57 ] ) ; xx [ 138 ] = rtdvd [ 2262 ] * xx [ 106 ] ; xx [ 139 ] =
rtdvd [ 2263 ] * xx [ 106 ] ; xx [ 140 ] = rtdvd [ 2264 ] * xx [ 106 ] ;
pm_math_Quaternion_compose_ra ( xx + 133 , xx + 137 , xx + 141 ) ; xx [ 133 ]
= rtdvd [ 2321 ] ; xx [ 134 ] = rtdvd [ 2322 ] ; xx [ 135 ] = rtdvd [ 2323 ]
; xx [ 136 ] = rtdvd [ 2324 ] ; pm_math_Quaternion_compose_ra ( xx + 141 , xx
+ 133 , xx + 137 ) ; xx [ 145 ] = rtdvd [ 2576 ] ; xx [ 146 ] = rtdvd [ 2577
] ; xx [ 147 ] = rtdvd [ 2578 ] ; xx [ 148 ] = rtdvd [ 2579 ] ; xx [ 149 ] =
state [ 113 ] ; xx [ 150 ] = state [ 114 ] ; xx [ 151 ] = state [ 115 ] ; xx
[ 152 ] = state [ 116 ] ; xx [ 153 ] = rtdvd [ 2583 ] ; xx [ 154 ] = rtdvd [
2584 ] ; xx [ 155 ] = rtdvd [ 2585 ] ; xx [ 156 ] = rtdvd [ 2586 ] ;
pm_math_Quaternion_composeInverse_ra ( xx + 149 , xx + 153 , xx + 157 ) ;
pm_math_Quaternion_compose_ra ( xx + 145 , xx + 157 , xx + 149 ) ;
pm_math_Quaternion_compose_ra ( xx + 137 , xx + 149 , xx + 145 ) ; xx [ 57 ]
= xx [ 35 ] * state [ 120 ] ; xx [ 106 ] = cos ( xx [ 57 ] ) ; xx [ 127 ] =
sin ( xx [ 57 ] ) ; xx [ 57 ] = rtdvd [ 2633 ] * xx [ 106 ] - rtdvd [ 2636 ]
* xx [ 127 ] ; xx [ 128 ] = rtdvd [ 2634 ] * xx [ 106 ] + rtdvd [ 2635 ] * xx
[ 127 ] ; xx [ 129 ] = rtdvd [ 2635 ] * xx [ 106 ] - rtdvd [ 2634 ] * xx [
127 ] ; xx [ 137 ] = rtdvd [ 2633 ] * xx [ 127 ] + rtdvd [ 2636 ] * xx [ 106
] ; xx [ 157 ] = xx [ 57 ] ; xx [ 158 ] = xx [ 128 ] ; xx [ 159 ] = xx [ 129
] ; xx [ 160 ] = xx [ 137 ] ; pm_math_Quaternion_compose_ra ( xx + 145 , xx +
157 , xx + 161 ) ; pm_math_Quaternion_inverseCompose_ra ( xx + 12 , xx + 161
, xx + 145 ) ; xx [ 106 ] = xx [ 145 ] * xx [ 145 ] ; xx [ 127 ] = xx [ 146 ]
* xx [ 147 ] ; xx [ 138 ] = xx [ 145 ] * xx [ 148 ] ; xx [ 139 ] = xx [ 146 ]
* xx [ 148 ] ; xx [ 140 ] = xx [ 145 ] * xx [ 147 ] ; xx [ 161 ] = xx [ 147 ]
* xx [ 148 ] ; xx [ 162 ] = xx [ 145 ] * xx [ 146 ] ; xx [ 163 ] = rtdvd [
3022 ] ; xx [ 164 ] = rtdvd [ 3023 ] ; xx [ 165 ] = rtdvd [ 3024 ] ; xx [ 166
] = rtdvd [ 3025 ] ; xx [ 145 ] = xx [ 35 ] * state [ 134 ] ; xx [ 167 ] =
sin ( xx [ 145 ] ) ; xx [ 168 ] = cos ( xx [ 145 ] ) ; xx [ 169 ] = rtdvd [
3010 ] * xx [ 167 ] ; xx [ 170 ] = rtdvd [ 3011 ] * xx [ 167 ] ; xx [ 171 ] =
rtdvd [ 3012 ] * xx [ 167 ] ; pm_math_Quaternion_compose_ra ( xx + 163 , xx +
168 , xx + 172 ) ; xx [ 163 ] = rtdvd [ 3069 ] ; xx [ 164 ] = rtdvd [ 3070 ]
; xx [ 165 ] = rtdvd [ 3071 ] ; xx [ 166 ] = rtdvd [ 3072 ] ;
pm_math_Quaternion_compose_ra ( xx + 172 , xx + 163 , xx + 167 ) ; xx [ 176 ]
= rtdvd [ 3324 ] ; xx [ 177 ] = rtdvd [ 3325 ] ; xx [ 178 ] = rtdvd [ 3326 ]
; xx [ 179 ] = rtdvd [ 3327 ] ; xx [ 180 ] = state [ 140 ] ; xx [ 181 ] =
state [ 141 ] ; xx [ 182 ] = state [ 142 ] ; xx [ 183 ] = state [ 143 ] ; xx
[ 184 ] = rtdvd [ 3331 ] ; xx [ 185 ] = rtdvd [ 3332 ] ; xx [ 186 ] = rtdvd [
3333 ] ; xx [ 187 ] = rtdvd [ 3334 ] ; pm_math_Quaternion_composeInverse_ra ( xx
+ 180 , xx + 184 , xx + 188 ) ; pm_math_Quaternion_compose_ra ( xx + 176 , xx
+ 188 , xx + 180 ) ; pm_math_Quaternion_compose_ra ( xx + 167 , xx + 180 , xx
+ 176 ) ; xx [ 145 ] = xx [ 35 ] * state [ 147 ] ; xx [ 35 ] = cos ( xx [ 145
] ) ; xx [ 167 ] = sin ( xx [ 145 ] ) ; xx [ 145 ] = rtdvd [ 3381 ] * xx [ 35
] - rtdvd [ 3384 ] * xx [ 167 ] ; xx [ 168 ] = rtdvd [ 3382 ] * xx [ 35 ] +
rtdvd [ 3383 ] * xx [ 167 ] ; xx [ 169 ] = rtdvd [ 3383 ] * xx [ 35 ] - rtdvd
[ 3382 ] * xx [ 167 ] ; xx [ 170 ] = rtdvd [ 3381 ] * xx [ 167 ] + rtdvd [
3384 ] * xx [ 35 ] ; xx [ 188 ] = xx [ 145 ] ; xx [ 189 ] = xx [ 168 ] ; xx [
190 ] = xx [ 169 ] ; xx [ 191 ] = xx [ 170 ] ; pm_math_Quaternion_compose_ra
( xx + 176 , xx + 188 , xx + 192 ) ; pm_math_Quaternion_inverseCompose_ra ( xx
+ 12 , xx + 192 , xx + 176 ) ; xx [ 12 ] = xx [ 176 ] * xx [ 176 ] ; xx [ 13
] = xx [ 177 ] * xx [ 178 ] ; xx [ 14 ] = xx [ 176 ] * xx [ 179 ] ; xx [ 15 ]
= xx [ 177 ] * xx [ 179 ] ; xx [ 35 ] = xx [ 176 ] * xx [ 178 ] ; xx [ 167 ]
= xx [ 178 ] * xx [ 179 ] ; xx [ 171 ] = xx [ 176 ] * xx [ 177 ] ;
pm_math_Quaternion_compose_ra ( xx + 4 , xx + 69 , xx + 192 ) ;
pm_math_Quaternion_compose_ra ( xx + 192 , xx + 61 , xx + 196 ) ;
pm_math_Quaternion_compose_ra ( xx + 196 , xx + 77 , xx + 200 ) ;
pm_math_Quaternion_compose_ra ( xx + 200 , xx + 85 , xx + 204 ) ; xx [ 176 ]
= xx [ 204 ] * xx [ 204 ] ; xx [ 208 ] = xx [ 205 ] * xx [ 206 ] ; xx [ 209 ]
= xx [ 204 ] * xx [ 207 ] ; xx [ 210 ] = xx [ 205 ] * xx [ 207 ] ; xx [ 211 ]
= xx [ 204 ] * xx [ 206 ] ; xx [ 212 ] = xx [ 206 ] * xx [ 207 ] ; xx [ 213 ]
= xx [ 204 ] * xx [ 205 ] ; xx [ 214 ] = - xx [ 204 ] ; xx [ 215 ] = - xx [
205 ] ; xx [ 216 ] = - xx [ 206 ] ; xx [ 217 ] = - xx [ 207 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 69 , xx + 8 , xx + 218 ) ; xx [ 221
] = xx [ 218 ] + rtdvd [ 666 ] * state [ 40 ] ; xx [ 222 ] = xx [ 219 ] +
rtdvd [ 667 ] * state [ 40 ] ; xx [ 223 ] = xx [ 220 ] + rtdvd [ 668 ] *
state [ 40 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 61 , xx + 221 , xx +
218 ) ; pm_math_Quaternion_inverseXform_ra ( xx + 77 , xx + 218 , xx + 224 )
; xx [ 227 ] = state [ 49 ] ; xx [ 228 ] = state [ 50 ] ; xx [ 229 ] = state
[ 51 ] ; pm_math_Quaternion_xform_ra ( xx + 81 , xx + 227 , xx + 230 ) ; xx [
81 ] = xx [ 224 ] + xx [ 230 ] ; xx [ 82 ] = xx [ 225 ] + xx [ 231 ] ; xx [
83 ] = xx [ 226 ] + xx [ 232 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 85
, xx + 81 , xx + 224 ) ; xx [ 84 ] = xx [ 226 ] + state [ 53 ] ; xx [ 226 ] =
xx [ 224 ] ; xx [ 227 ] = xx [ 225 ] ; xx [ 228 ] = xx [ 84 ] ;
pm_math_Quaternion_xform_ra ( xx + 214 , xx + 226 , xx + 233 ) ; xx [ 229 ] =
xx [ 66 ] * rtdvd [ 1033 ] ; xx [ 236 ] = rtdvd [ 1033 ] * xx [ 65 ] ; xx [
237 ] = rtdvd [ 1030 ] - xx [ 25 ] * ( xx [ 229 ] * xx [ 29 ] + xx [ 236 ] *
xx [ 67 ] ) ; xx [ 238 ] = rtdvd [ 1031 ] - xx [ 25 ] * ( xx [ 229 ] * xx [
67 ] - xx [ 236 ] * xx [ 29 ] ) ; xx [ 239 ] = rtdvd [ 1032 ] - ( rtdvd [
1033 ] - xx [ 25 ] * ( xx [ 236 ] * xx [ 65 ] + xx [ 229 ] * xx [ 66 ] ) ) ;
pm_math_Quaternion_xform_ra ( xx + 200 , xx + 237 , xx + 65 ) ; xx [ 200 ] =
rtdvd [ 994 ] ; xx [ 201 ] = rtdvd [ 995 ] ; xx [ 202 ] = rtdvd [ 996 ] ;
pm_math_Quaternion_xform_ra ( xx + 77 , xx + 200 , xx + 240 ) ; xx [ 243 ] =
rtdvd [ 984 ] + xx [ 240 ] ; xx [ 244 ] = rtdvd [ 985 ] + xx [ 241 ] ; xx [
245 ] = rtdvd [ 986 ] + xx [ 242 ] ; pm_math_Quaternion_xform_ra ( xx + 196 ,
xx + 243 , xx + 240 ) ; xx [ 196 ] = rtdvd [ 729 ] ; xx [ 197 ] = rtdvd [ 730
] ; xx [ 198 ] = rtdvd [ 731 ] ; pm_math_Quaternion_xform_ra ( xx + 192 , xx
+ 196 , xx + 246 ) ; xx [ 192 ] = rtdvd [ 663 ] ; xx [ 193 ] = rtdvd [ 664 ]
; xx [ 194 ] = rtdvd [ 665 ] ; pm_math_Quaternion_xform_ra ( xx + 69 , xx +
192 , xx + 249 ) ; xx [ 192 ] = rtdvd [ 656 ] - xx [ 249 ] ; xx [ 193 ] =
rtdvd [ 657 ] - xx [ 250 ] ; xx [ 194 ] = rtdvd [ 658 ] - xx [ 251 ] ;
pm_math_Quaternion_xform_ra ( xx + 4 , xx + 192 , xx + 249 ) ; xx [ 29 ] = xx
[ 67 ] + xx [ 242 ] + xx [ 248 ] + xx [ 251 ] + xx [ 24 ] ;
pm_math_Vector3_cross_ra ( xx + 81 , xx + 237 , xx + 252 ) ;
pm_math_Vector3_cross_ra ( xx + 218 , xx + 243 , xx + 81 ) ;
pm_math_Vector3_cross_ra ( xx + 221 , xx + 196 , xx + 218 ) ;
pm_math_Vector3_cross_ra ( xx + 8 , xx + 192 , xx + 195 ) ; xx [ 192 ] = xx [
195 ] + xx [ 11 ] ; xx [ 193 ] = xx [ 196 ] + xx [ 23 ] ; xx [ 194 ] = xx [
197 ] + xx [ 1 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 69 , xx + 192 ,
xx + 195 ) ; xx [ 69 ] = xx [ 218 ] + xx [ 195 ] + rtdvd [ 669 ] * state [ 40
] ; xx [ 70 ] = xx [ 219 ] + xx [ 196 ] + rtdvd [ 670 ] * state [ 40 ] ; xx [
71 ] = xx [ 220 ] + xx [ 197 ] + rtdvd [ 671 ] * state [ 40 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 61 , xx + 69 , xx + 192 ) ; xx [ 61
] = xx [ 81 ] + xx [ 192 ] ; xx [ 62 ] = xx [ 82 ] + xx [ 193 ] ; xx [ 63 ] =
xx [ 83 ] + xx [ 194 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 77 , xx +
61 , xx + 69 ) ; pm_math_Vector3_cross_ra ( xx + 230 , xx + 200 , xx + 61 ) ;
xx [ 77 ] = xx [ 252 ] + xx [ 69 ] + xx [ 61 ] ; xx [ 78 ] = xx [ 253 ] + xx
[ 70 ] + xx [ 62 ] ; xx [ 79 ] = xx [ 254 ] + xx [ 71 ] + xx [ 63 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 85 , xx + 77 , xx + 61 ) ; xx [ 69
] = xx [ 61 ] + rtdvd [ 5176 ] * xx [ 225 ] ; xx [ 70 ] = xx [ 62 ] - rtdvd [
5176 ] * xx [ 224 ] ; xx [ 71 ] = xx [ 63 ] ; pm_math_Quaternion_xform_ra ( xx
+ 214 , xx + 69 , xx + 61 ) ; pm_math_Quaternion_xform_ra ( xx + 204 , xx +
226 , xx + 69 ) ; xx [ 64 ] = rtdvd [ 5178 ] * xx [ 206 ] ; xx [ 72 ] = rtdvd
[ 5178 ] * xx [ 205 ] ; pm_math_Quaternion_compose_ra ( xx + 4 , xx + 141 ,
xx + 77 ) ; pm_math_Quaternion_compose_ra ( xx + 77 , xx + 133 , xx + 85 ) ;
pm_math_Quaternion_compose_ra ( xx + 85 , xx + 149 , xx + 192 ) ;
pm_math_Quaternion_compose_ra ( xx + 192 , xx + 157 , xx + 196 ) ; xx [ 67 ]
= xx [ 196 ] * xx [ 196 ] ; xx [ 81 ] = xx [ 197 ] * xx [ 198 ] ; xx [ 82 ] =
xx [ 196 ] * xx [ 199 ] ; xx [ 83 ] = xx [ 197 ] * xx [ 199 ] ; xx [ 200 ] =
xx [ 196 ] * xx [ 198 ] ; xx [ 201 ] = xx [ 198 ] * xx [ 199 ] ; xx [ 202 ] =
xx [ 196 ] * xx [ 197 ] ; xx [ 214 ] = - xx [ 196 ] ; xx [ 215 ] = - xx [ 197
] ; xx [ 216 ] = - xx [ 198 ] ; xx [ 217 ] = - xx [ 199 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 141 , xx + 8 , xx + 218 ) ; xx [
221 ] = xx [ 218 ] + rtdvd [ 2262 ] * state [ 108 ] ; xx [ 222 ] = xx [ 219 ]
+ rtdvd [ 2263 ] * state [ 108 ] ; xx [ 223 ] = xx [ 220 ] + rtdvd [ 2264 ] *
state [ 108 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 133 , xx + 221 , xx
+ 218 ) ; pm_math_Quaternion_inverseXform_ra ( xx + 149 , xx + 218 , xx + 224
) ; xx [ 227 ] = state [ 117 ] ; xx [ 228 ] = state [ 118 ] ; xx [ 229 ] =
state [ 119 ] ; pm_math_Quaternion_xform_ra ( xx + 153 , xx + 227 , xx + 230
) ; xx [ 153 ] = xx [ 224 ] + xx [ 230 ] ; xx [ 154 ] = xx [ 225 ] + xx [ 231
] ; xx [ 155 ] = xx [ 226 ] + xx [ 232 ] ; pm_math_Quaternion_inverseXform_ra
( xx + 157 , xx + 153 , xx + 224 ) ; xx [ 156 ] = xx [ 226 ] + state [ 121 ]
; xx [ 226 ] = xx [ 224 ] ; xx [ 227 ] = xx [ 225 ] ; xx [ 228 ] = xx [ 156 ]
; pm_math_Quaternion_xform_ra ( xx + 214 , xx + 226 , xx + 236 ) ; xx [ 203 ]
= xx [ 129 ] * rtdvd [ 2629 ] ; xx [ 229 ] = rtdvd [ 2629 ] * xx [ 128 ] ; xx
[ 242 ] = rtdvd [ 2626 ] - xx [ 25 ] * ( xx [ 203 ] * xx [ 57 ] + xx [ 229 ]
* xx [ 137 ] ) ; xx [ 243 ] = rtdvd [ 2627 ] - xx [ 25 ] * ( xx [ 203 ] * xx
[ 137 ] - xx [ 229 ] * xx [ 57 ] ) ; xx [ 244 ] = rtdvd [ 2628 ] - ( rtdvd [
2629 ] - xx [ 25 ] * ( xx [ 229 ] * xx [ 128 ] + xx [ 203 ] * xx [ 129 ] ) )
; pm_math_Quaternion_xform_ra ( xx + 192 , xx + 242 , xx + 251 ) ; xx [ 192 ]
= rtdvd [ 2590 ] ; xx [ 193 ] = rtdvd [ 2591 ] ; xx [ 194 ] = rtdvd [ 2592 ]
; pm_math_Quaternion_xform_ra ( xx + 149 , xx + 192 , xx + 254 ) ; xx [ 257 ]
= rtdvd [ 2580 ] + xx [ 254 ] ; xx [ 258 ] = rtdvd [ 2581 ] + xx [ 255 ] ; xx
[ 259 ] = rtdvd [ 2582 ] + xx [ 256 ] ; pm_math_Quaternion_xform_ra ( xx + 85
, xx + 257 , xx + 254 ) ; xx [ 85 ] = rtdvd [ 2325 ] ; xx [ 86 ] = rtdvd [
2326 ] ; xx [ 87 ] = rtdvd [ 2327 ] ; pm_math_Quaternion_xform_ra ( xx + 77 ,
xx + 85 , xx + 260 ) ; xx [ 77 ] = rtdvd [ 2259 ] ; xx [ 78 ] = rtdvd [ 2260
] ; xx [ 79 ] = rtdvd [ 2261 ] ; pm_math_Quaternion_xform_ra ( xx + 141 , xx
+ 77 , xx + 263 ) ; xx [ 77 ] = rtdvd [ 2252 ] - xx [ 263 ] ; xx [ 78 ] =
rtdvd [ 2253 ] - xx [ 264 ] ; xx [ 79 ] = rtdvd [ 2254 ] - xx [ 265 ] ;
pm_math_Quaternion_xform_ra ( xx + 4 , xx + 77 , xx + 263 ) ; xx [ 57 ] = xx
[ 253 ] + xx [ 256 ] + xx [ 262 ] + xx [ 265 ] + xx [ 24 ] ;
pm_math_Vector3_cross_ra ( xx + 153 , xx + 242 , xx + 266 ) ;
pm_math_Vector3_cross_ra ( xx + 218 , xx + 257 , xx + 153 ) ;
pm_math_Vector3_cross_ra ( xx + 221 , xx + 85 , xx + 218 ) ;
pm_math_Vector3_cross_ra ( xx + 8 , xx + 77 , xx + 85 ) ; xx [ 77 ] = xx [ 85
] + xx [ 11 ] ; xx [ 78 ] = xx [ 86 ] + xx [ 23 ] ; xx [ 79 ] = xx [ 87 ] +
xx [ 1 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 141 , xx + 77 , xx + 85
) ; xx [ 77 ] = xx [ 218 ] + xx [ 85 ] + rtdvd [ 2265 ] * state [ 108 ] ; xx
[ 78 ] = xx [ 219 ] + xx [ 86 ] + rtdvd [ 2266 ] * state [ 108 ] ; xx [ 79 ]
= xx [ 220 ] + xx [ 87 ] + rtdvd [ 2267 ] * state [ 108 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 133 , xx + 77 , xx + 85 ) ; xx [ 77
] = xx [ 153 ] + xx [ 85 ] ; xx [ 78 ] = xx [ 154 ] + xx [ 86 ] ; xx [ 79 ] =
xx [ 155 ] + xx [ 87 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 149 , xx +
77 , xx + 85 ) ; pm_math_Vector3_cross_ra ( xx + 230 , xx + 192 , xx + 77 ) ;
xx [ 133 ] = xx [ 266 ] + xx [ 85 ] + xx [ 77 ] ; xx [ 134 ] = xx [ 267 ] +
xx [ 86 ] + xx [ 78 ] ; xx [ 135 ] = xx [ 268 ] + xx [ 87 ] + xx [ 79 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 157 , xx + 133 , xx + 77 ) ; xx [
85 ] = xx [ 77 ] + rtdvd [ 5179 ] * xx [ 225 ] ; xx [ 86 ] = xx [ 78 ] -
rtdvd [ 5179 ] * xx [ 224 ] ; xx [ 87 ] = xx [ 79 ] ;
pm_math_Quaternion_xform_ra ( xx + 214 , xx + 85 , xx + 77 ) ;
pm_math_Quaternion_xform_ra ( xx + 196 , xx + 226 , xx + 85 ) ; xx [ 80 ] =
rtdvd [ 5181 ] * xx [ 198 ] ; xx [ 88 ] = rtdvd [ 5181 ] * xx [ 197 ] ;
pm_math_Quaternion_compose_ra ( xx + 4 , xx + 102 , xx + 133 ) ;
pm_math_Quaternion_compose_ra ( xx + 133 , xx + 93 , xx + 141 ) ;
pm_math_Quaternion_compose_ra ( xx + 141 , xx + 110 , xx + 149 ) ;
pm_math_Quaternion_compose_ra ( xx + 149 , xx + 118 , xx + 157 ) ; xx [ 128 ]
= xx [ 157 ] * xx [ 157 ] ; xx [ 129 ] = xx [ 158 ] * xx [ 159 ] ; xx [ 137 ]
= xx [ 157 ] * xx [ 160 ] ; xx [ 153 ] = xx [ 158 ] * xx [ 160 ] ; xx [ 154 ]
= xx [ 157 ] * xx [ 159 ] ; xx [ 155 ] = xx [ 159 ] * xx [ 160 ] ; xx [ 192 ]
= xx [ 157 ] * xx [ 158 ] ; xx [ 214 ] = - xx [ 157 ] ; xx [ 215 ] = - xx [
158 ] ; xx [ 216 ] = - xx [ 159 ] ; xx [ 217 ] = - xx [ 160 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 102 , xx + 8 , xx + 193 ) ; xx [
218 ] = xx [ 193 ] + rtdvd [ 1288 ] * state [ 63 ] ; xx [ 219 ] = xx [ 194 ]
+ rtdvd [ 1289 ] * state [ 63 ] ; xx [ 220 ] = xx [ 195 ] + rtdvd [ 1290 ] *
state [ 63 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 93 , xx + 218 , xx +
193 ) ; pm_math_Quaternion_inverseXform_ra ( xx + 110 , xx + 193 , xx + 221 )
; xx [ 224 ] = state [ 72 ] ; xx [ 225 ] = state [ 73 ] ; xx [ 226 ] = state
[ 74 ] ; pm_math_Quaternion_xform_ra ( xx + 114 , xx + 224 , xx + 227 ) ; xx
[ 114 ] = xx [ 221 ] + xx [ 227 ] ; xx [ 115 ] = xx [ 222 ] + xx [ 228 ] ; xx
[ 116 ] = xx [ 223 ] + xx [ 229 ] ; pm_math_Quaternion_inverseXform_ra ( xx +
118 , xx + 114 , xx + 221 ) ; xx [ 117 ] = xx [ 223 ] + state [ 76 ] ; xx [
223 ] = xx [ 221 ] ; xx [ 224 ] = xx [ 222 ] ; xx [ 225 ] = xx [ 117 ] ;
pm_math_Quaternion_xform_ra ( xx + 214 , xx + 223 , xx + 230 ) ; xx [ 203 ] =
xx [ 100 ] * rtdvd [ 1655 ] ; xx [ 226 ] = rtdvd [ 1655 ] * xx [ 99 ] ; xx [
242 ] = rtdvd [ 1652 ] - xx [ 25 ] * ( xx [ 203 ] * xx [ 73 ] + xx [ 226 ] *
xx [ 101 ] ) ; xx [ 243 ] = rtdvd [ 1653 ] - xx [ 25 ] * ( xx [ 203 ] * xx [
101 ] - xx [ 226 ] * xx [ 73 ] ) ; xx [ 244 ] = rtdvd [ 1654 ] - ( rtdvd [
1655 ] - xx [ 25 ] * ( xx [ 226 ] * xx [ 99 ] + xx [ 203 ] * xx [ 100 ] ) ) ;
pm_math_Quaternion_xform_ra ( xx + 149 , xx + 242 , xx + 99 ) ; xx [ 149 ] =
rtdvd [ 1616 ] ; xx [ 150 ] = rtdvd [ 1617 ] ; xx [ 151 ] = rtdvd [ 1618 ] ;
pm_math_Quaternion_xform_ra ( xx + 110 , xx + 149 , xx + 256 ) ; xx [ 265 ] =
rtdvd [ 1606 ] + xx [ 256 ] ; xx [ 266 ] = rtdvd [ 1607 ] + xx [ 257 ] ; xx [
267 ] = rtdvd [ 1608 ] + xx [ 258 ] ; pm_math_Quaternion_xform_ra ( xx + 141
, xx + 265 , xx + 256 ) ; xx [ 141 ] = rtdvd [ 1351 ] ; xx [ 142 ] = rtdvd [
1352 ] ; xx [ 143 ] = rtdvd [ 1353 ] ; pm_math_Quaternion_xform_ra ( xx + 133
, xx + 141 , xx + 268 ) ; xx [ 133 ] = rtdvd [ 1285 ] ; xx [ 134 ] = rtdvd [
1286 ] ; xx [ 135 ] = rtdvd [ 1287 ] ; pm_math_Quaternion_xform_ra ( xx + 102
, xx + 133 , xx + 271 ) ; xx [ 133 ] = rtdvd [ 1278 ] - xx [ 271 ] ; xx [ 134
] = rtdvd [ 1279 ] - xx [ 272 ] ; xx [ 135 ] = rtdvd [ 1280 ] - xx [ 273 ] ;
pm_math_Quaternion_xform_ra ( xx + 4 , xx + 133 , xx + 271 ) ; xx [ 73 ] = xx
[ 101 ] + xx [ 258 ] + xx [ 270 ] + xx [ 273 ] + xx [ 24 ] ;
pm_math_Vector3_cross_ra ( xx + 114 , xx + 242 , xx + 274 ) ;
pm_math_Vector3_cross_ra ( xx + 193 , xx + 265 , xx + 114 ) ;
pm_math_Vector3_cross_ra ( xx + 218 , xx + 141 , xx + 193 ) ;
pm_math_Vector3_cross_ra ( xx + 8 , xx + 133 , xx + 141 ) ; xx [ 133 ] = xx [
141 ] + xx [ 11 ] ; xx [ 134 ] = xx [ 142 ] + xx [ 23 ] ; xx [ 135 ] = xx [
143 ] + xx [ 1 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 102 , xx + 133 ,
xx + 141 ) ; xx [ 102 ] = xx [ 193 ] + xx [ 141 ] + rtdvd [ 1291 ] * state [
63 ] ; xx [ 103 ] = xx [ 194 ] + xx [ 142 ] + rtdvd [ 1292 ] * state [ 63 ] ;
xx [ 104 ] = xx [ 195 ] + xx [ 143 ] + rtdvd [ 1293 ] * state [ 63 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 93 , xx + 102 , xx + 133 ) ; xx [
93 ] = xx [ 114 ] + xx [ 133 ] ; xx [ 94 ] = xx [ 115 ] + xx [ 134 ] ; xx [
95 ] = xx [ 116 ] + xx [ 135 ] ; pm_math_Quaternion_inverseXform_ra ( xx +
110 , xx + 93 , xx + 102 ) ; pm_math_Vector3_cross_ra ( xx + 227 , xx + 149 ,
xx + 93 ) ; xx [ 110 ] = xx [ 274 ] + xx [ 102 ] + xx [ 93 ] ; xx [ 111 ] =
xx [ 275 ] + xx [ 103 ] + xx [ 94 ] ; xx [ 112 ] = xx [ 276 ] + xx [ 104 ] +
xx [ 95 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 118 , xx + 110 , xx +
93 ) ; xx [ 102 ] = xx [ 93 ] + rtdvd [ 5182 ] * xx [ 222 ] ; xx [ 103 ] = xx
[ 94 ] - rtdvd [ 5182 ] * xx [ 221 ] ; xx [ 104 ] = xx [ 95 ] ;
pm_math_Quaternion_xform_ra ( xx + 214 , xx + 102 , xx + 93 ) ;
pm_math_Quaternion_xform_ra ( xx + 157 , xx + 223 , xx + 102 ) ; xx [ 96 ] =
rtdvd [ 5184 ] * xx [ 159 ] ; xx [ 105 ] = rtdvd [ 5184 ] * xx [ 158 ] ;
pm_math_Quaternion_compose_ra ( xx + 4 , xx + 172 , xx + 110 ) ;
pm_math_Quaternion_compose_ra ( xx + 110 , xx + 163 , xx + 118 ) ;
pm_math_Quaternion_compose_ra ( xx + 118 , xx + 180 , xx + 133 ) ;
pm_math_Quaternion_compose_ra ( xx + 133 , xx + 188 , xx + 141 ) ; xx [ 101 ]
= xx [ 141 ] * xx [ 141 ] ; xx [ 114 ] = xx [ 142 ] * xx [ 143 ] ; xx [ 115 ]
= xx [ 141 ] * xx [ 144 ] ; xx [ 116 ] = xx [ 142 ] * xx [ 144 ] ; xx [ 149 ]
= xx [ 141 ] * xx [ 143 ] ; xx [ 150 ] = xx [ 143 ] * xx [ 144 ] ; xx [ 151 ]
= xx [ 141 ] * xx [ 142 ] ; xx [ 214 ] = - xx [ 141 ] ; xx [ 215 ] = - xx [
142 ] ; xx [ 216 ] = - xx [ 143 ] ; xx [ 217 ] = - xx [ 144 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 172 , xx + 8 , xx + 193 ) ; xx [
218 ] = xx [ 193 ] + rtdvd [ 3010 ] * state [ 135 ] ; xx [ 219 ] = xx [ 194 ]
+ rtdvd [ 3011 ] * state [ 135 ] ; xx [ 220 ] = xx [ 195 ] + rtdvd [ 3012 ] *
state [ 135 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 163 , xx + 218 , xx
+ 193 ) ; pm_math_Quaternion_inverseXform_ra ( xx + 180 , xx + 193 , xx + 221
) ; xx [ 224 ] = state [ 144 ] ; xx [ 225 ] = state [ 145 ] ; xx [ 226 ] =
state [ 146 ] ; pm_math_Quaternion_xform_ra ( xx + 184 , xx + 224 , xx + 227
) ; xx [ 184 ] = xx [ 221 ] + xx [ 227 ] ; xx [ 185 ] = xx [ 222 ] + xx [ 228
] ; xx [ 186 ] = xx [ 223 ] + xx [ 229 ] ; pm_math_Quaternion_inverseXform_ra
( xx + 188 , xx + 184 , xx + 221 ) ; xx [ 152 ] = xx [ 223 ] + state [ 148 ]
; xx [ 223 ] = xx [ 221 ] ; xx [ 224 ] = xx [ 222 ] ; xx [ 225 ] = xx [ 152 ]
; pm_math_Quaternion_xform_ra ( xx + 214 , xx + 223 , xx + 242 ) ; xx [ 187 ]
= xx [ 169 ] * rtdvd [ 3377 ] ; xx [ 203 ] = rtdvd [ 3377 ] * xx [ 168 ] ; xx
[ 265 ] = rtdvd [ 3374 ] - xx [ 25 ] * ( xx [ 187 ] * xx [ 145 ] + xx [ 203 ]
* xx [ 170 ] ) ; xx [ 266 ] = rtdvd [ 3375 ] - xx [ 25 ] * ( xx [ 187 ] * xx
[ 170 ] - xx [ 203 ] * xx [ 145 ] ) ; xx [ 267 ] = rtdvd [ 3376 ] - ( rtdvd [
3377 ] - xx [ 25 ] * ( xx [ 203 ] * xx [ 168 ] + xx [ 187 ] * xx [ 169 ] ) )
; pm_math_Quaternion_xform_ra ( xx + 133 , xx + 265 , xx + 168 ) ; xx [ 133 ]
= rtdvd [ 3338 ] ; xx [ 134 ] = rtdvd [ 3339 ] ; xx [ 135 ] = rtdvd [ 3340 ]
; pm_math_Quaternion_xform_ra ( xx + 180 , xx + 133 , xx + 273 ) ; xx [ 276 ]
= rtdvd [ 3328 ] + xx [ 273 ] ; xx [ 277 ] = rtdvd [ 3329 ] + xx [ 274 ] ; xx
[ 278 ] = rtdvd [ 3330 ] + xx [ 275 ] ; pm_math_Quaternion_xform_ra ( xx +
118 , xx + 276 , xx + 273 ) ; xx [ 118 ] = rtdvd [ 3073 ] ; xx [ 119 ] =
rtdvd [ 3074 ] ; xx [ 120 ] = rtdvd [ 3075 ] ; pm_math_Quaternion_xform_ra ( xx
+ 110 , xx + 118 , xx + 279 ) ; xx [ 110 ] = rtdvd [ 3007 ] ; xx [ 111 ] =
rtdvd [ 3008 ] ; xx [ 112 ] = rtdvd [ 3009 ] ; pm_math_Quaternion_xform_ra ( xx
+ 172 , xx + 110 , xx + 282 ) ; xx [ 110 ] = rtdvd [ 3000 ] - xx [ 282 ] ; xx
[ 111 ] = rtdvd [ 3001 ] - xx [ 283 ] ; xx [ 112 ] = rtdvd [ 3002 ] - xx [
284 ] ; pm_math_Quaternion_xform_ra ( xx + 4 , xx + 110 , xx + 282 ) ; xx [ 4
] = xx [ 170 ] + xx [ 275 ] + xx [ 281 ] + xx [ 284 ] + xx [ 24 ] ;
pm_math_Vector3_cross_ra ( xx + 184 , xx + 265 , xx + 5 ) ;
pm_math_Vector3_cross_ra ( xx + 193 , xx + 276 , xx + 184 ) ;
pm_math_Vector3_cross_ra ( xx + 218 , xx + 118 , xx + 193 ) ;
pm_math_Vector3_cross_ra ( xx + 8 , xx + 110 , xx + 118 ) ; xx [ 8 ] = xx [
118 ] + xx [ 11 ] ; xx [ 9 ] = xx [ 119 ] + xx [ 23 ] ; xx [ 10 ] = xx [ 120
] + xx [ 1 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 172 , xx + 8 , xx +
110 ) ; xx [ 8 ] = xx [ 193 ] + xx [ 110 ] + rtdvd [ 3013 ] * state [ 135 ] ;
xx [ 9 ] = xx [ 194 ] + xx [ 111 ] + rtdvd [ 3014 ] * state [ 135 ] ; xx [ 10
] = xx [ 195 ] + xx [ 112 ] + rtdvd [ 3015 ] * state [ 135 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 163 , xx + 8 , xx + 110 ) ; xx [ 8
] = xx [ 184 ] + xx [ 110 ] ; xx [ 9 ] = xx [ 185 ] + xx [ 111 ] ; xx [ 10 ]
= xx [ 186 ] + xx [ 112 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 180 ,
xx + 8 , xx + 110 ) ; pm_math_Vector3_cross_ra ( xx + 227 , xx + 133 , xx + 8
) ; xx [ 118 ] = xx [ 5 ] + xx [ 110 ] + xx [ 8 ] ; xx [ 119 ] = xx [ 6 ] +
xx [ 111 ] + xx [ 9 ] ; xx [ 120 ] = xx [ 7 ] + xx [ 112 ] + xx [ 10 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 188 , xx + 118 , xx + 5 ) ; xx [ 8
] = xx [ 5 ] + rtdvd [ 5185 ] * xx [ 222 ] ; xx [ 9 ] = xx [ 6 ] - rtdvd [
5185 ] * xx [ 221 ] ; xx [ 10 ] = xx [ 7 ] ; pm_math_Quaternion_xform_ra ( xx
+ 214 , xx + 8 , xx + 5 ) ; pm_math_Quaternion_xform_ra ( xx + 141 , xx + 223
, xx + 8 ) ; xx [ 1 ] = rtdvd [ 5187 ] * xx [ 143 ] ; xx [ 11 ] = rtdvd [
5187 ] * xx [ 142 ] ; output [ 0 ] = xx [ 26 ] + xx [ 0 ] ; output [ 1 ] = xx
[ 20 ] ; output [ 3 ] = xx [ 27 ] + xx [ 3 ] ; output [ 4 ] = xx [ 21 ] ;
output [ 6 ] = xx [ 28 ] + xx [ 24 ] ; output [ 7 ] = xx [ 22 ] ; output [ 9
] = xx [ 16 ] ; output [ 10 ] = xx [ 17 ] ; output [ 11 ] = xx [ 18 ] ;
output [ 12 ] = xx [ 19 ] ; output [ 13 ] = xx [ 32 ] ; output [ 14 ] = xx [
33 ] ; output [ 15 ] = xx [ 34 ] ; output [ 16 ] = state [ 37 ] ; output [ 26
] = state [ 60 ] ; output [ 27 ] = state [ 61 ] ; output [ 46 ] = state [ 53
] ; output [ 56 ] = state [ 83 ] ; output [ 57 ] = state [ 84 ] ; output [ 76
] = state [ 76 ] ; output [ 77 ] = state [ 25 ] ; output [ 79 ] = input [ 4 ]
; output [ 80 ] = state [ 105 ] ; output [ 90 ] = state [ 128 ] ; output [ 91
] = state [ 129 ] ; output [ 110 ] = state [ 121 ] ; output [ 120 ] = state [
155 ] ; output [ 121 ] = state [ 156 ] ; output [ 140 ] = state [ 148 ] ;
output [ 141 ] = xx [ 39 ] ; output [ 142 ] = xx [ 42 ] ; output [ 143 ] = xx
[ 45 ] ; output [ 144 ] = xx [ 46 ] ; output [ 145 ] = xx [ 40 ] ; output [
146 ] = xx [ 48 ] ; output [ 147 ] = xx [ 49 ] ; output [ 148 ] = xx [ 43 ] ;
output [ 149 ] = xx [ 41 ] ; output [ 150 ] = xx [ 53 ] ; output [ 151 ] = xx
[ 39 ] ; output [ 152 ] = xx [ 42 ] ; output [ 153 ] = xx [ 45 ] ; output [
154 ] = xx [ 46 ] ; output [ 155 ] = xx [ 40 ] ; output [ 156 ] = xx [ 48 ] ;
output [ 157 ] = xx [ 49 ] ; output [ 158 ] = xx [ 43 ] ; output [ 159 ] = xx
[ 41 ] ; output [ 160 ] = xx [ 31 ] ; output [ 161 ] = xx [ 50 ] ; output [
162 ] = xx [ 51 ] ; output [ 163 ] = xx [ 52 ] ; output [ 164 ] = xx [ 58 ] ;
output [ 165 ] = xx [ 59 ] ; output [ 166 ] = xx [ 60 ] ; output [ 170 ] = xx
[ 36 ] ; output [ 171 ] = xx [ 37 ] ; output [ 172 ] = xx [ 38 ] ; output [
173 ] = xx [ 25 ] * ( xx [ 44 ] + xx [ 74 ] * xx [ 74 ] ) - xx [ 30 ] ;
output [ 174 ] = xx [ 25 ] * ( xx [ 47 ] + xx [ 68 ] ) ; output [ 175 ] = xx
[ 25 ] * ( xx [ 89 ] - xx [ 90 ] ) ; output [ 176 ] = xx [ 25 ] * ( xx [ 47 ]
- xx [ 68 ] ) ; output [ 177 ] = xx [ 25 ] * ( xx [ 44 ] + xx [ 75 ] * xx [
75 ] ) - xx [ 30 ] ; output [ 178 ] = xx [ 25 ] * ( xx [ 91 ] + xx [ 92 ] ) ;
output [ 179 ] = xx [ 25 ] * ( xx [ 89 ] + xx [ 90 ] ) ; output [ 180 ] = xx
[ 25 ] * ( xx [ 91 ] - xx [ 92 ] ) ; output [ 181 ] = xx [ 25 ] * ( xx [ 44 ]
+ xx [ 76 ] * xx [ 76 ] ) - xx [ 30 ] ; output [ 182 ] = xx [ 25 ] * ( xx [
97 ] + xx [ 107 ] * xx [ 107 ] ) - xx [ 30 ] ; output [ 183 ] = xx [ 25 ] * ( xx
[ 98 ] + xx [ 122 ] ) ; output [ 184 ] = xx [ 25 ] * ( xx [ 123 ] - xx [ 124
] ) ; output [ 185 ] = xx [ 25 ] * ( xx [ 98 ] - xx [ 122 ] ) ; output [ 186
] = xx [ 25 ] * ( xx [ 97 ] + xx [ 108 ] * xx [ 108 ] ) - xx [ 30 ] ; output
[ 187 ] = xx [ 25 ] * ( xx [ 125 ] + xx [ 126 ] ) ; output [ 188 ] = xx [ 25
] * ( xx [ 123 ] + xx [ 124 ] ) ; output [ 189 ] = xx [ 25 ] * ( xx [ 125 ] -
xx [ 126 ] ) ; output [ 190 ] = xx [ 25 ] * ( xx [ 97 ] + xx [ 109 ] * xx [
109 ] ) - xx [ 30 ] ; output [ 191 ] = xx [ 39 ] ; output [ 192 ] = xx [ 42 ]
; output [ 193 ] = xx [ 45 ] ; output [ 194 ] = xx [ 46 ] ; output [ 195 ] =
xx [ 40 ] ; output [ 196 ] = xx [ 48 ] ; output [ 197 ] = xx [ 49 ] ; output
[ 198 ] = xx [ 43 ] ; output [ 199 ] = xx [ 41 ] ; output [ 200 ] = xx [ 130
] ; output [ 201 ] = xx [ 131 ] ; output [ 202 ] = xx [ 132 ] ; output [ 203
] = xx [ 54 ] ; output [ 204 ] = xx [ 55 ] ; output [ 205 ] = xx [ 56 ] ;
output [ 209 ] = xx [ 25 ] * ( xx [ 106 ] + xx [ 146 ] * xx [ 146 ] ) - xx [
30 ] ; output [ 210 ] = xx [ 25 ] * ( xx [ 127 ] + xx [ 138 ] ) ; output [
211 ] = xx [ 25 ] * ( xx [ 139 ] - xx [ 140 ] ) ; output [ 212 ] = xx [ 25 ]
* ( xx [ 127 ] - xx [ 138 ] ) ; output [ 213 ] = xx [ 25 ] * ( xx [ 106 ] +
xx [ 147 ] * xx [ 147 ] ) - xx [ 30 ] ; output [ 214 ] = xx [ 25 ] * ( xx [
161 ] + xx [ 162 ] ) ; output [ 215 ] = xx [ 25 ] * ( xx [ 139 ] + xx [ 140 ]
) ; output [ 216 ] = xx [ 25 ] * ( xx [ 161 ] - xx [ 162 ] ) ; output [ 217 ]
= xx [ 25 ] * ( xx [ 106 ] + xx [ 148 ] * xx [ 148 ] ) - xx [ 30 ] ; output [
218 ] = xx [ 25 ] * ( xx [ 12 ] + xx [ 177 ] * xx [ 177 ] ) - xx [ 30 ] ;
output [ 219 ] = xx [ 25 ] * ( xx [ 13 ] + xx [ 14 ] ) ; output [ 220 ] = xx
[ 25 ] * ( xx [ 15 ] - xx [ 35 ] ) ; output [ 221 ] = xx [ 25 ] * ( xx [ 13 ]
- xx [ 14 ] ) ; output [ 222 ] = xx [ 25 ] * ( xx [ 12 ] + xx [ 178 ] * xx [
178 ] ) - xx [ 30 ] ; output [ 223 ] = xx [ 25 ] * ( xx [ 167 ] + xx [ 171 ]
) ; output [ 224 ] = xx [ 25 ] * ( xx [ 15 ] + xx [ 35 ] ) ; output [ 225 ] =
xx [ 25 ] * ( xx [ 167 ] - xx [ 171 ] ) ; output [ 226 ] = xx [ 25 ] * ( xx [
12 ] + xx [ 179 ] * xx [ 179 ] ) - xx [ 30 ] ; output [ 227 ] = xx [ 25 ] * ( xx
[ 176 ] + xx [ 205 ] * xx [ 205 ] ) - xx [ 30 ] ; output [ 228 ] = xx [ 25 ]
* ( xx [ 208 ] + xx [ 209 ] ) ; output [ 229 ] = xx [ 25 ] * ( xx [ 210 ] -
xx [ 211 ] ) ; output [ 230 ] = xx [ 25 ] * ( xx [ 208 ] - xx [ 209 ] ) ;
output [ 231 ] = xx [ 25 ] * ( xx [ 176 ] + xx [ 206 ] * xx [ 206 ] ) - xx [
30 ] ; output [ 232 ] = xx [ 25 ] * ( xx [ 212 ] + xx [ 213 ] ) ; output [
233 ] = xx [ 25 ] * ( xx [ 210 ] + xx [ 211 ] ) ; output [ 234 ] = xx [ 25 ]
* ( xx [ 212 ] - xx [ 213 ] ) ; output [ 235 ] = xx [ 25 ] * ( xx [ 176 ] +
xx [ 207 ] * xx [ 207 ] ) - xx [ 30 ] ; output [ 236 ] = xx [ 233 ] ; output
[ 237 ] = xx [ 234 ] ; output [ 238 ] = xx [ 235 ] ; output [ 239 ] = rtdvd [
5176 ] - xx [ 25 ] * ( rtdvd [ 5176 ] * xx [ 205 ] * xx [ 205 ] + rtdvd [
5176 ] * xx [ 206 ] * xx [ 206 ] ) + xx [ 29 ] ; output [ 240 ] = xx [ 61 ] ;
output [ 241 ] = xx [ 62 ] ; output [ 242 ] = xx [ 63 ] ; output [ 243 ] = xx
[ 84 ] ; output [ 244 ] = xx [ 69 ] ; output [ 245 ] = xx [ 70 ] ; output [
246 ] = xx [ 71 ] ; output [ 247 ] = xx [ 25 ] * ( xx [ 64 ] * xx [ 204 ] +
xx [ 72 ] * xx [ 207 ] ) + xx [ 65 ] + xx [ 240 ] + xx [ 246 ] + xx [ 249 ] +
xx [ 0 ] ; output [ 248 ] = xx [ 25 ] * ( xx [ 64 ] * xx [ 207 ] - xx [ 72 ]
* xx [ 204 ] ) + xx [ 66 ] + xx [ 241 ] + xx [ 247 ] + xx [ 250 ] + xx [ 3 ]
; output [ 249 ] = rtdvd [ 5178 ] - xx [ 25 ] * ( xx [ 72 ] * xx [ 205 ] + xx
[ 64 ] * xx [ 206 ] ) + xx [ 29 ] ; output [ 250 ] = xx [ 25 ] * ( xx [ 67 ]
+ xx [ 197 ] * xx [ 197 ] ) - xx [ 30 ] ; output [ 251 ] = xx [ 25 ] * ( xx [
81 ] + xx [ 82 ] ) ; output [ 252 ] = xx [ 25 ] * ( xx [ 83 ] - xx [ 200 ] )
; output [ 253 ] = xx [ 25 ] * ( xx [ 81 ] - xx [ 82 ] ) ; output [ 254 ] =
xx [ 25 ] * ( xx [ 67 ] + xx [ 198 ] * xx [ 198 ] ) - xx [ 30 ] ; output [
255 ] = xx [ 25 ] * ( xx [ 201 ] + xx [ 202 ] ) ; output [ 256 ] = xx [ 25 ]
* ( xx [ 83 ] + xx [ 200 ] ) ; output [ 257 ] = xx [ 25 ] * ( xx [ 201 ] - xx
[ 202 ] ) ; output [ 258 ] = xx [ 25 ] * ( xx [ 67 ] + xx [ 199 ] * xx [ 199
] ) - xx [ 30 ] ; output [ 259 ] = xx [ 236 ] ; output [ 260 ] = xx [ 237 ] ;
output [ 261 ] = xx [ 238 ] ; output [ 262 ] = rtdvd [ 5179 ] - xx [ 25 ] * ( rtdvd [ 5179 ] * xx [ 197 ] * xx [ 197 ] + rtdvd [ 5179 ] * xx [ 198 ] * xx [ 198 ] ) + xx [ 57 ] ; output [ 263 ] = xx [ 77 ] ; output [ 264 ] = xx [ 78 ] ; output [ 265 ] = xx [ 79 ] ; output [ 266 ] = xx [ 156 ] ; output [ 267 ] = xx [ 85 ] ; output [ 268 ] = xx [ 86 ] ; output [ 269 ] = xx [ 87 ] ; output [ 270 ] = xx [ 25 ] * ( xx [ 80 ] * xx [ 196 ] + xx [ 88 ] * xx [ 199 ] ) + xx [ 251 ] + xx [ 254 ] + xx [ 260 ] + xx [ 263 ] + xx [ 0 ] ; output [ 271 ] = xx [ 25 ] * ( xx [ 80 ] * xx [ 199 ] - xx [ 88 ] * xx [ 196 ] ) + xx [ 252 ] + xx [ 255 ] + xx [ 261 ] + xx [ 264 ] + xx [ 3 ] ; output [ 272 ] = rtdvd [ 5181 ] - xx [ 25 ] * ( xx [ 88 ] * xx [ 197 ] + xx [ 80 ] * xx [ 198 ] ) + xx [ 57 ] ; output [ 273 ] = xx [ 25 ] * ( xx [ 128 ] + xx [ 158 ] * xx [ 158 ] ) - xx [ 30 ] ; output [ 274 ] = xx [ 25 ] * ( xx [ 129 ] + xx [ 137 ] ) ; output [ 275 ] = xx [ 25 ] * ( xx [ 153 ] - xx [ 154 ] ) ; output [ 276 ] = xx [ 25 ] * ( xx [ 129 ] - xx [ 137 ] ) ; output [ 277 ] = xx [ 25 ] * ( xx [ 128 ] + xx [ 159 ] * xx [ 159 ] ) - xx [ 30 ] ; output [ 278 ] = xx [ 25 ] * ( xx [ 155 ] + xx [ 192 ] ) ; output [ 279 ] = xx [ 25 ] * ( xx [ 153 ] + xx [ 154 ] ) ; output [ 280 ] = xx [ 25 ] * ( xx [ 155 ] - xx [ 192 ] ) ; output [ 281 ] = xx [ 25 ] * ( xx [ 128 ] + xx [ 160 ] * xx [ 160 ] ) - xx [ 30 ] ; output [ 282 ] = xx [ 230 ] ; output [ 283 ] = xx [ 231 ] ; output [ 284 ] = xx [ 232 ] ; output [ 285 ] = rtdvd [ 5182 ] - xx [ 25 ] * ( rtdvd [ 5182 ] * xx [ 158 ] * xx [ 158 ] + rtdvd [ 5182 ] * xx [ 159 ] * xx [ 159 ] ) + xx [ 73 ] ; output [ 286 ] = xx [ 93 ] ; output [ 287 ] = xx [ 94 ] ; output [ 288 ] = xx [ 95 ] ; output [ 289 ] = xx [ 117 ] ; output [ 290 ] = xx [ 102 ] ; output [ 291 ] = xx [ 103 ] ; output [ 292 ] = xx [ 104 ] ; output [ 293 ] = xx [ 25 ] * ( xx [ 96 ] * xx [ 157 ] + xx [ 105 ] * xx [ 160 ] ) + xx [ 99 ] + xx [ 256 ] + xx [ 268 ] + xx [ 271 ] + xx [ 0 ] ; output [ 294 ] = xx [ 25 ] * ( xx [ 96 ] * xx [ 160 ] - xx [ 105 ] * xx [ 157 ] ) + xx [ 100 ] + xx [ 257 ] + xx [ 269 ] + xx [ 272 ] + xx [ 3 ] ; output [ 295 ] = rtdvd [ 5184 ] - xx [ 25 ] * ( xx [ 105 ] * xx [ 158 ] + xx [ 96 ] * xx [ 159 ] ) + xx [ 73 ] ; output [ 296 ] = xx [ 25 ] * ( xx [ 101 ] + xx [ 142 ] * xx [ 142 ] ) - xx [ 30 ] ; output [ 297 ] = xx [ 25 ] * ( xx [ 114 ] + xx [ 115 ] ) ; output [ 298 ] = xx [ 25 ] * ( xx [ 116 ] - xx [ 149 ] ) ; output [ 299 ] = xx [ 25 ] * ( xx [ 114 ] - xx [ 115 ] ) ; output [ 300 ] = xx [ 25 ] * ( xx [ 101 ] + xx [ 143 ] * xx [ 143 ] ) - xx [ 30 ] ; output [ 301 ] = xx [ 25 ] * ( xx [ 150 ] + xx [ 151 ] ) ; output [ 302 ] = xx [ 25 ] * ( xx [ 116 ] + xx [ 149 ] ) ; output [ 303 ] = xx [ 25 ] * ( xx [ 150 ] - xx [ 151 ] ) ; output [ 304 ] = xx [ 25 ] * ( xx [ 101 ] + xx [ 144 ] * xx [ 144 ] ) - xx [ 30 ] ; output [ 305 ] = xx [ 242 ] ; output [ 306 ] = xx [ 243 ] ; output [ 307 ] = xx [ 244 ] ; output [ 308 ] = rtdvd [ 5185 ] - xx [ 25 ] * ( rtdvd [ 5185 ] * xx [ 142 ] * xx [ 142 ] + rtdvd [ 5185 ] * xx [ 143 ] * xx [ 143 ] ) + xx [ 4 ] ; output [ 309 ] = xx [ 5 ] ; output [ 310 ] = xx [ 6 ] ; output [ 311 ] = xx [ 7 ] ; output [ 312 ] = xx [ 152 ] ; output [ 313 ] = xx [ 8 ] ; output [ 314 ] = xx [ 9 ] ; output [ 315 ] = xx [ 10 ] ; output [ 316 ] = xx [ 25 ] * ( xx [ 1 ] * xx [ 141 ] + xx [ 11 ] * xx [ 144 ] ) + xx [ 168 ] + xx [ 273 ] + xx [ 279 ] + xx [ 282 ] + xx [ 0 ] ; output [ 317 ] = xx [ 25 ] * ( xx [ 1 ] * xx [ 144 ] - xx [ 11 ] * xx [ 141 ] ) + xx [ 169 ] + xx [ 274 ] + xx [ 280 ] + xx [ 283 ] + xx [ 3 ] ; output [ 318 ] = rtdvd [ 5187 ] - xx [ 25 ] * ( xx [ 11 ] * xx [ 142 ] + xx [ 1 ] * xx [ 143 ] ) + xx [ 4 ] ; return NULL ; }
