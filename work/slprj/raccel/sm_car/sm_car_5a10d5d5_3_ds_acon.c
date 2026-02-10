#include "ne_ds.h"
#include "sm_car_5a10d5d5_3_ds_sys_struct.h"
#include "sm_car_5a10d5d5_3_ds_acon.h"
#include "sm_car_5a10d5d5_3_ds.h"
#include "sm_car_5a10d5d5_3_ds_externals.h"
#include "sm_car_5a10d5d5_3_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T sm_car_5a10d5d5_3_ds_acon ( const NeDynamicSystem * LC , const
NeDynamicSystemInput * t187 , NeDsMethodOutput * out ) { real_T t2 [ 5 ] ;
real_T t41 [ 4 ] ; size_t t84 ; ( void ) t187 ; ( void ) LC ; out -> mACON .
mX [ 0UL ] = 0.02 ; t2 [ 0 ] = - 0.0051147484685437807 ; t2 [ 1 ] = -
0.0051147484685437807 ; t2 [ 2 ] = - 0.0051147484685437807 ; t2 [ 3 ] = -
0.0051147484685437807 ; t2 [ 4 ] = - 0.0051147484685437807 ; t41 [ 0 ] = -
1.0 ; t41 [ 1 ] = - 1.0 ; t41 [ 2 ] = - 1.0 ; t41 [ 3 ] = - 1.0 ; out ->
mACON . mX [ 1UL ] = - 1.0 ; out -> mACON . mX [ 2UL ] = - 1.0 ; out -> mACON
. mX [ 3UL ] = - 1.0 ; for ( t84 = 0UL ; t84 < 5UL ; t84 ++ ) { out -> mACON
. mX [ t84 + 4UL ] = t2 [ t84 ] ; } out -> mACON . mX [ 9UL ] = - 1.0 ; out
-> mACON . mX [ 10UL ] = - 0.001 ; out -> mACON . mX [ 11UL ] = 1.0 ; out ->
mACON . mX [ 12UL ] = - 1.0 ; out -> mACON . mX [ 13UL ] = 1.0 ; out -> mACON
. mX [ 14UL ] = - 1.0 ; out -> mACON . mX [ 15UL ] = 0.2 ; out -> mACON . mX
[ 16UL ] = 0.24346629476042422 ; out -> mACON . mX [ 17UL ] = 1.0 ; out ->
mACON . mX [ 18UL ] = 0.24346629476042422 ; out -> mACON . mX [ 19UL ] = 1.0
; out -> mACON . mX [ 20UL ] = 0.24346629476042422 ; out -> mACON . mX [ 21UL
] = 0.40268456375838924 ; out -> mACON . mX [ 22UL ] = - 0.46753246753246747
; out -> mACON . mX [ 23UL ] = - 1.0 ; out -> mACON . mX [ 24UL ] =
0.24346629476042422 ; out -> mACON . mX [ 25UL ] = 0.40268456375838924 ; out
-> mACON . mX [ 26UL ] = - 0.46753246753246747 ; out -> mACON . mX [ 27UL ] =
- 1.0 ; out -> mACON . mX [ 28UL ] = 0.24346629476042422 ; out -> mACON . mX
[ 29UL ] = 0.18983199327463102 ; out -> mACON . mX [ 30UL ] = 1.0 ; out ->
mACON . mX [ 31UL ] = - 0.40268456375838924 ; out -> mACON . mX [ 32UL ] =
0.46753246753246747 ; out -> mACON . mX [ 33UL ] = - 1.0 ; out -> mACON . mX
[ 34UL ] = 1.0 ; out -> mACON . mX [ 35UL ] = - 0.40268456375838924 ; out ->
mACON . mX [ 36UL ] = 0.46753246753246747 ; out -> mACON . mX [ 37UL ] = -
1.0 ; out -> mACON . mX [ 38UL ] = - 0.0002 ; out -> mACON . mX [ 39UL ] =
0.2 ; out -> mACON . mX [ 40UL ] = - 0.2 ; out -> mACON . mX [ 41UL ] = 1.0 ;
out -> mACON . mX [ 42UL ] = - 0.0002 ; out -> mACON . mX [ 43UL ] = 0.2 ;
out -> mACON . mX [ 44UL ] = - 0.2 ; out -> mACON . mX [ 45UL ] = 1.0 ; out
-> mACON . mX [ 46UL ] = 1.0 ; out -> mACON . mX [ 47UL ] = 1.0 ; out ->
mACON . mX [ 48UL ] = 1.0 ; out -> mACON . mX [ 49UL ] = 1.0 ; out -> mACON .
mX [ 50UL ] = 1.0 ; out -> mACON . mX [ 51UL ] = - 1.0 ; out -> mACON . mX [
52UL ] = 1.0 ; out -> mACON . mX [ 53UL ] = 0.0051147484685437807 ; out ->
mACON . mX [ 54UL ] = 0.033333333333333333 ; out -> mACON . mX [ 55UL ] = 1.0
; out -> mACON . mX [ 56UL ] = 0.033333333333333333 ; out -> mACON . mX [
57UL ] = 0.54945054945054939 ; out -> mACON . mX [ 58UL ] = -
0.0053723187541568048 ; out -> mACON . mX [ 59UL ] = 1.0 ; out -> mACON . mX
[ 60UL ] = 0.54945054945054939 ; out -> mACON . mX [ 61UL ] = -
0.5372318754156804 ; out -> mACON . mX [ 62UL ] = - 1.0 ; out -> mACON . mX [
63UL ] = 0.001 ; out -> mACON . mX [ 64UL ] = 1.0 ; out -> mACON . mX [ 65UL
] = 1.0 ; out -> mACON . mX [ 66UL ] = 1.0 ; out -> mACON . mX [ 67UL ] = 0.2
; out -> mACON . mX [ 68UL ] = 1.0 ; out -> mACON . mX [ 69UL ] =
0.51948051948051943 ; out -> mACON . mX [ 70UL ] = 0.9967088673201091 ; out
-> mACON . mX [ 71UL ] = - 1.0 ; out -> mACON . mX [ 72UL ] = 1.0 ; out ->
mACON . mX [ 73UL ] = 1.0 ; out -> mACON . mX [ 74UL ] = 1.0 ; out -> mACON .
mX [ 75UL ] = 1.0 ; out -> mACON . mX [ 76UL ] = 0.2 ; out -> mACON . mX [
77UL ] = 1.0 ; out -> mACON . mX [ 78UL ] = 0.51948051948051943 ; out ->
mACON . mX [ 79UL ] = 0.9967088673201091 ; out -> mACON . mX [ 80UL ] = 1.0 ;
out -> mACON . mX [ 81UL ] = 1.0 ; out -> mACON . mX [ 82UL ] = 1.0 ; out ->
mACON . mX [ 83UL ] = 1.0 ; out -> mACON . mX [ 84UL ] = - 1.0 ; out -> mACON
. mX [ 85UL ] = - 1.0 ; out -> mACON . mX [ 86UL ] = 1.0 ; out -> mACON . mX
[ 87UL ] = - 1.0 ; out -> mACON . mX [ 88UL ] = 1.0 ; out -> mACON . mX [
89UL ] = 1.0 ; out -> mACON . mX [ 90UL ] = - 1.0 ; out -> mACON . mX [ 91UL
] = - 1.0 ; out -> mACON . mX [ 92UL ] = 1.0 ; out -> mACON . mX [ 93UL ] =
1.0 ; out -> mACON . mX [ 94UL ] = - 1.0 ; out -> mACON . mX [ 95UL ] = 1.0 ;
out -> mACON . mX [ 96UL ] = - 1.0 ; out -> mACON . mX [ 97UL ] = - 1.0 ; out
-> mACON . mX [ 98UL ] = 1.0 ; out -> mACON . mX [ 99UL ] = 1.0 ; out ->
mACON . mX [ 100UL ] = - 1.0 ; out -> mACON . mX [ 101UL ] = 1.0 ; out ->
mACON . mX [ 102UL ] = - 1.0 ; out -> mACON . mX [ 103UL ] = 1.0 ; out ->
mACON . mX [ 104UL ] = 1.0 ; out -> mACON . mX [ 105UL ] = - 1.0 ; out ->
mACON . mX [ 106UL ] = 1.0 ; out -> mACON . mX [ 107UL ] = - 1.0 ; out ->
mACON . mX [ 108UL ] = - 1.0 ; out -> mACON . mX [ 109UL ] = 1.0 ; out ->
mACON . mX [ 110UL ] = 1.0 ; out -> mACON . mX [ 111UL ] = - 1.0 ; out ->
mACON . mX [ 112UL ] = 1.0 ; out -> mACON . mX [ 113UL ] = - 1.0 ; out ->
mACON . mX [ 114UL ] = 1.0 ; out -> mACON . mX [ 115UL ] = 1.0 ; out -> mACON
. mX [ 116UL ] = 1.0 ; out -> mACON . mX [ 117UL ] = 0.54945054945054939 ;
out -> mACON . mX [ 118UL ] = 1.0 ; out -> mACON . mX [ 119UL ] = 1.0 ; out
-> mACON . mX [ 120UL ] = 0.54945054945054939 ; out -> mACON . mX [ 121UL ] =
1.0 ; out -> mACON . mX [ 122UL ] = 1.0 ; out -> mACON . mX [ 123UL ] =
0.447427293064877 ; out -> mACON . mX [ 124UL ] = 1.0 ; out -> mACON . mX [
125UL ] = 1.0 ; out -> mACON . mX [ 126UL ] = 0.447427293064877 ; out ->
mACON . mX [ 127UL ] = 1.0 ; out -> mACON . mX [ 128UL ] = 1.0 ; out -> mACON
. mX [ 129UL ] = 1.0 ; out -> mACON . mX [ 130UL ] = 1.0 ; out -> mACON . mX
[ 131UL ] = 1.0 ; out -> mACON . mX [ 132UL ] = 1.0 ; out -> mACON . mX [
133UL ] = 1.0 ; out -> mACON . mX [ 134UL ] = 1.0 ; out -> mACON . mX [ 135UL
] = 1.0 ; out -> mACON . mX [ 136UL ] = 1.0 ; out -> mACON . mX [ 137UL ] = -
1.0 ; out -> mACON . mX [ 138UL ] = - 1.0 ; for ( t84 = 0UL ; t84 < 4UL ; t84
++ ) { out -> mACON . mX [ t84 + 139UL ] = t41 [ t84 ] ; } out -> mACON . mX
[ 143UL ] = 1.0 ; out -> mACON . mX [ 144UL ] = 0.24535192314880536 ; out ->
mACON . mX [ 145UL ] = 1.0 ; out -> mACON . mX [ 146UL ] =
0.24535192314880536 ; out -> mACON . mX [ 147UL ] = 0.0010420073981367265 ;
out -> mACON . mX [ 148UL ] = - 1.0 ; out -> mACON . mX [ 149UL ] = -
0.221483942414175 ; out -> mACON . mX [ 150UL ] = 0.447427293064877 ; out ->
mACON . mX [ 151UL ] = 0.28663972253274855 ; out -> mACON . mX [ 152UL ] = -
0.221483942414175 ; out -> mACON . mX [ 153UL ] = 0.447427293064877 ; out ->
mACON . mX [ 154UL ] = 0.28663972253274855 ; ( void ) LC ; ( void ) out ;
return 0 ; }
