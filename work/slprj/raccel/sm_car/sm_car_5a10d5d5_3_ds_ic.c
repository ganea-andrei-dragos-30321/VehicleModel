#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_ic.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_ic ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t2 , NeDsMethodOutput * out ) { size_t t1 ; ( void )
LC ; out -> mIC . mX [ 0UL ] = t2 -> mP_R . mX [ 2UL ] ; out -> mIC . mX [
1UL ] = 298.15 ; out -> mIC . mX [ 2UL ] = 0.0 ; out -> mIC . mX [ 3UL ] =
0.0 ; for ( t1 = 4UL ; t1 - 4UL < 5UL ; t1 ++ ) { out -> mIC . mX [ t1 ] =
0.0 ; } out -> mIC . mX [ 9UL ] = 298.15 ; out -> mIC . mX [ 10UL ] = 200.0 ;
out -> mIC . mX [ 11UL ] = 300.0 ; out -> mIC . mX [ 12UL ] = 0.0 ; out ->
mIC . mX [ 13UL ] = 300.0 ; out -> mIC . mX [ 14UL ] = 0.0 ; out -> mIC . mX
[ 15UL ] = t2 -> mP_R . mX [ 3UL ] ; out -> mIC . mX [ 16UL ] = 85.0 ; out ->
mIC . mX [ 17UL ] = 300.0 ; out -> mIC . mX [ 18UL ] = 85.0 ; out -> mIC . mX
[ 19UL ] = 300.0 ; out -> mIC . mX [ 20UL ] = 85.0 ; out -> mIC . mX [ 21UL ]
= 300.0 ; out -> mIC . mX [ 22UL ] = 85.0 ; out -> mIC . mX [ 23UL ] = 300.0
; out -> mIC . mX [ 24UL ] = 85.0 ; out -> mIC . mX [ 25UL ] = 5000.0 ; out
-> mIC . mX [ 26UL ] = 300.0 ; out -> mIC . mX [ 27UL ] = 300.0 ; out -> mIC
. mX [ 28UL ] = 300.0 ; out -> mIC . mX [ 29UL ] = 300.0 ; out -> mIC . mX [
30UL ] = 0.0 ; out -> mIC . mX [ 31UL ] = 0.0 ; out -> mIC . mX [ 32UL ] =
0.0 ; out -> mIC . mX [ 33UL ] = 0.0 ; out -> mIC . mX [ 34UL ] = 0.0 ; out
-> mIC . mX [ 35UL ] = 0.0 ; out -> mIC . mX [ 36UL ] = 0.0 ; out -> mIC . mX
[ 37UL ] = 1.0 ; out -> mIC . mX [ 38UL ] = 1.0 ; out -> mIC . mX [ 39UL ] =
0.0 ; out -> mIC . mX [ 40UL ] = t2 -> mP_R . mX [ 6UL ] ; out -> mIC . mX [
41UL ] = 0.0 ; out -> mIC . mX [ 42UL ] = 0.0 ; out -> mIC . mX [ 43UL ] =
0.0 ; out -> mIC . mX [ 44UL ] = 0.0 ; out -> mIC . mX [ 45UL ] = 0.0 ; out
-> mIC . mX [ 46UL ] = 0.0 ; out -> mIC . mX [ 47UL ] = 0.0 ; out -> mIC . mX
[ 48UL ] = 0.0 ; out -> mIC . mX [ 49UL ] = 0.0 ; out -> mIC . mX [ 50UL ] =
0.0 ; out -> mIC . mX [ 51UL ] = 0.0 ; out -> mIC . mX [ 52UL ] = 0.0 ; out
-> mIC . mX [ 53UL ] = 0.0 ; out -> mIC . mX [ 54UL ] = 0.0 ; out -> mIC . mX
[ 55UL ] = 0.0 ; out -> mIC . mX [ 56UL ] = 0.0 ; out -> mIC . mX [ 57UL ] =
0.0 ; out -> mIC . mX [ 58UL ] = 300.0 ; out -> mIC . mX [ 59UL ] = 1.0 ; out
-> mIC . mX [ 60UL ] = 300.0 ; out -> mIC . mX [ 61UL ] = 1.0 ; out -> mIC .
mX [ 62UL ] = 0.0 ; out -> mIC . mX [ 63UL ] = 300.0 ; out -> mIC . mX [ 64UL
] = 85.0 ; out -> mIC . mX [ 65UL ] = 300.0 ; out -> mIC . mX [ 66UL ] = 0.0
; out -> mIC . mX [ 67UL ] = 300.0 ; out -> mIC . mX [ 68UL ] = 1.0 ; out ->
mIC . mX [ 69UL ] = 300.0 ; out -> mIC . mX [ 70UL ] = 1.0 ; out -> mIC . mX
[ 71UL ] = 0.0 ; out -> mIC . mX [ 72UL ] = 300.0 ; out -> mIC . mX [ 73UL ]
= 85.0 ; out -> mIC . mX [ 74UL ] = 300.0 ; out -> mIC . mX [ 75UL ] = 0.0 ;
out -> mIC . mX [ 76UL ] = 300.0 ; out -> mIC . mX [ 77UL ] = 1.0 ; out ->
mIC . mX [ 78UL ] = 300.0 ; out -> mIC . mX [ 79UL ] = 1.0 ; out -> mIC . mX
[ 80UL ] = 0.0 ; out -> mIC . mX [ 81UL ] = 300.0 ; out -> mIC . mX [ 82UL ]
= 85.0 ; out -> mIC . mX [ 83UL ] = 300.0 ; out -> mIC . mX [ 84UL ] = 0.0 ;
out -> mIC . mX [ 85UL ] = 300.0 ; out -> mIC . mX [ 86UL ] = 1.0 ; out ->
mIC . mX [ 87UL ] = 300.0 ; out -> mIC . mX [ 88UL ] = 1.0 ; out -> mIC . mX
[ 89UL ] = 0.0 ; out -> mIC . mX [ 90UL ] = 300.0 ; out -> mIC . mX [ 91UL ]
= 85.0 ; out -> mIC . mX [ 92UL ] = 300.0 ; out -> mIC . mX [ 93UL ] = 0.0 ;
out -> mIC . mX [ 94UL ] = 300.0 ; out -> mIC . mX [ 95UL ] = 1.0 ; out ->
mIC . mX [ 96UL ] = 300.0 ; out -> mIC . mX [ 97UL ] = 1.0 ; out -> mIC . mX
[ 98UL ] = 0.0 ; out -> mIC . mX [ 99UL ] = 300.0 ; out -> mIC . mX [ 100UL ]
= 85.0 ; out -> mIC . mX [ 101UL ] = 300.0 ; out -> mIC . mX [ 102UL ] = 0.0
; out -> mIC . mX [ 103UL ] = 300.0 ; out -> mIC . mX [ 104UL ] = 1.0 ; out
-> mIC . mX [ 105UL ] = 300.0 ; out -> mIC . mX [ 106UL ] = 1.0 ; out -> mIC
. mX [ 107UL ] = 0.0 ; out -> mIC . mX [ 108UL ] = 300.0 ; out -> mIC . mX [
109UL ] = 300.0 ; out -> mIC . mX [ 110UL ] = 300.0 ; out -> mIC . mX [ 111UL
] = 300.0 ; out -> mIC . mX [ 112UL ] = 0.0 ; out -> mIC . mX [ 113UL ] =
300.0 ; out -> mIC . mX [ 114UL ] = 300.0 ; out -> mIC . mX [ 115UL ] = 300.0
; out -> mIC . mX [ 116UL ] = 0.0 ; out -> mIC . mX [ 117UL ] = 300.0 ; out
-> mIC . mX [ 118UL ] = 300.0 ; out -> mIC . mX [ 119UL ] = 300.0 ; out ->
mIC . mX [ 120UL ] = 0.0 ; out -> mIC . mX [ 121UL ] = 300.0 ; out -> mIC .
mX [ 122UL ] = 300.0 ; out -> mIC . mX [ 123UL ] = 300.0 ; out -> mIC . mX [
124UL ] = 0.0 ; out -> mIC . mX [ 125UL ] = 300.0 ; out -> mIC . mX [ 126UL ]
= 300.0 ; out -> mIC . mX [ 127UL ] = 0.0 ; out -> mIC . mX [ 128UL ] = 300.0
; out -> mIC . mX [ 129UL ] = 85.0 ; out -> mIC . mX [ 130UL ] = 300.0 ; out
-> mIC . mX [ 131UL ] = 300.0 ; out -> mIC . mX [ 132UL ] = 1.0 ; out -> mIC
. mX [ 133UL ] = 300.0 ; out -> mIC . mX [ 134UL ] = 1.0 ; out -> mIC . mX [
135UL ] = 0.0 ; out -> mIC . mX [ 136UL ] = 0.0 ; out -> mIC . mX [ 137UL ] =
420.0 ; out -> mIC . mX [ 138UL ] = 0.0 ; out -> mIC . mX [ 139UL ] = t2 ->
mP_R . mX [ 4UL ] ; out -> mIC . mX [ 140UL ] = 0.0 ; out -> mIC . mX [ 141UL
] = 0.0 ; out -> mIC . mX [ 142UL ] = 1.01325 ; out -> mIC . mX [ 143UL ] =
420.0 ; out -> mIC . mX [ 144UL ] = 300.0 ; out -> mIC . mX [ 145UL ] = 85.0
; out -> mIC . mX [ 146UL ] = 420.0 ; out -> mIC . mX [ 147UL ] = 300.0 ; out
-> mIC . mX [ 148UL ] = 85.0 ; out -> mIC . mX [ 149UL ] = 1.2 ; out -> mIC .
mX [ 150UL ] = 0.0 ; out -> mIC . mX [ 151UL ] = 0.0 ; out -> mIC . mX [
152UL ] = 0.0 ; ( void ) LC ; ( void ) out ; return 0 ; }
