#ifndef sm_car_types_h_
#define sm_car_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_FRCJVbuxI2W2bXvi3bCSqC_
#define DEFINED_TYPEDEF_FOR_struct_FRCJVbuxI2W2bXvi3bCSqC_
typedef struct { real_T blue [ 3 ] ; real_T bluepure [ 3 ] ; real_T bluelight
[ 3 ] ; real_T black [ 3 ] ; real_T yellow [ 3 ] ; real_T green [ 3 ] ;
real_T red [ 3 ] ; real_T orange [ 3 ] ; real_T orangedark [ 3 ] ; real_T
purple [ 3 ] ; real_T yellowpale [ 3 ] ; real_T graydark [ 3 ] ; real_T gray
[ 3 ] ; real_T graylight [ 3 ] ; real_T white [ 3 ] ; }
struct_FRCJVbuxI2W2bXvi3bCSqC ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_Cv345rOcWaDVJIPs9yeO3B_
#define DEFINED_TYPEDEF_FOR_struct_Cv345rOcWaDVJIPs9yeO3B_
typedef struct { real_T clr [ 3 ] ; real_T opc ; real_T rad ; }
struct_Cv345rOcWaDVJIPs9yeO3B ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_Fr78uSAs3jwpq2WfDcviqC_
#define DEFINED_TYPEDEF_FOR_struct_Fr78uSAs3jwpq2WfDcviqC_
typedef struct { real_T clr [ 3 ] ; real_T rad ; }
struct_Fr78uSAs3jwpq2WfDcviqC ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_IQXb0kjq3vgq4c89XmZ7ZH_
#define DEFINED_TYPEDEF_FOR_struct_IQXb0kjq3vgq4c89XmZ7ZH_
typedef struct { real_T clr [ 3 ] ; real_T len ; }
struct_IQXb0kjq3vgq4c89XmZ7ZH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_S1UY0M0BqqqbSEClkrg85C_
#define DEFINED_TYPEDEF_FOR_struct_S1UY0M0BqqqbSEClkrg85C_
typedef struct { real_T len ; } struct_S1UY0M0BqqqbSEClkrg85C ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_wP9vigyWpo1aUZznl2uW0D_
#define DEFINED_TYPEDEF_FOR_struct_wP9vigyWpo1aUZznl2uW0D_
typedef struct { struct_Fr78uSAs3jwpq2WfDcviqC cyl ;
struct_IQXb0kjq3vgq4c89XmZ7ZH piston ; struct_IQXb0kjq3vgq4c89XmZ7ZH bumpstop
; real_T dead_length ; struct_S1UY0M0BqqqbSEClkrg85C cap ; }
struct_wP9vigyWpo1aUZznl2uW0D ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_EXWhDKY1AAiJz96FQQufi_
#define DEFINED_TYPEDEF_FOR_struct_EXWhDKY1AAiJz96FQQufi_
typedef struct { real_T clr [ 3 ] ; real_T opc ; }
struct_EXWhDKY1AAiJz96FQQufi ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_ZWSvjaPLS8jNDntKPfoufG_
#define DEFINED_TYPEDEF_FOR_struct_ZWSvjaPLS8jNDntKPfoufG_
typedef struct { real_T clr [ 3 ] ; } struct_ZWSvjaPLS8jNDntKPfoufG ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_LM6TqPHIfLIZoNphxfgGOC_
#define DEFINED_TYPEDEF_FOR_struct_LM6TqPHIfLIZoNphxfgGOC_
typedef struct { real_T data [ 134 ] ; real_T opc ; }
struct_LM6TqPHIfLIZoNphxfgGOC ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_eajrUoeDIhg0hcv0X7jyaG_
#define DEFINED_TYPEDEF_FOR_struct_eajrUoeDIhg0hcv0X7jyaG_
typedef struct { struct_EXWhDKY1AAiJz96FQQufi body ;
struct_LM6TqPHIfLIZoNphxfgGOC emblem ; } struct_eajrUoeDIhg0hcv0X7jyaG ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_eMcLWfXLdGC8EYNDrULENG_
#define DEFINED_TYPEDEF_FOR_struct_eMcLWfXLdGC8EYNDrULENG_
typedef struct { real_T opc ; } struct_eMcLWfXLdGC8EYNDrULENG ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_YBO68brnCjZq2Tm6NtixiE_
#define DEFINED_TYPEDEF_FOR_struct_YBO68brnCjZq2Tm6NtixiE_
typedef struct { real_T opc ; real_T clr [ 3 ] ; }
struct_YBO68brnCjZq2Tm6NtixiE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_QO7eXdWArdNXJOlVPElL2_
#define DEFINED_TYPEDEF_FOR_struct_QO7eXdWArdNXJOlVPElL2_
typedef struct { struct_FRCJVbuxI2W2bXvi3bCSqC clr ;
struct_Cv345rOcWaDVJIPs9yeO3B hp ; struct_wP9vigyWpo1aUZznl2uW0D Shock ;
struct_EXWhDKY1AAiJz96FQQufi Rim ; struct_Fr78uSAs3jwpq2WfDcviqC DiffShaftOut
; struct_Fr78uSAs3jwpq2WfDcviqC Driveshaft ; struct_Fr78uSAs3jwpq2WfDcviqC
DriveshaftCVs ; struct_Fr78uSAs3jwpq2WfDcviqC Axle ;
struct_Fr78uSAs3jwpq2WfDcviqC AntiRollBar ; struct_Fr78uSAs3jwpq2WfDcviqC
UpperArm ; struct_Fr78uSAs3jwpq2WfDcviqC LowerArm ;
struct_Fr78uSAs3jwpq2WfDcviqC Upright ; struct_Fr78uSAs3jwpq2WfDcviqC Pushrod
; struct_Fr78uSAs3jwpq2WfDcviqC Pullrod ; struct_Fr78uSAs3jwpq2WfDcviqC
Bellcrank ; struct_Fr78uSAs3jwpq2WfDcviqC SteeringArm ;
struct_Fr78uSAs3jwpq2WfDcviqC TrackRod ; struct_ZWSvjaPLS8jNDntKPfoufG
Bushing ; struct_Fr78uSAs3jwpq2WfDcviqC SteeringRack ;
struct_Fr78uSAs3jwpq2WfDcviqC SteeringShafts ; struct_IQXb0kjq3vgq4c89XmZ7ZH
SteeringPinion ; struct_ZWSvjaPLS8jNDntKPfoufG SteeringWheel ;
struct_EXWhDKY1AAiJz96FQQufi TireContactPlane ; struct_eajrUoeDIhg0hcv0X7jyaG
PaceCar ; struct_LM6TqPHIfLIZoNphxfgGOC emblem ;
struct_eMcLWfXLdGC8EYNDrULENG body ; struct_eMcLWfXLdGC8EYNDrULENG part ;
struct_YBO68brnCjZq2Tm6NtixiE Tire ; } struct_QO7eXdWArdNXJOlVPElL2 ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_H17tBJfv2iKNHzYuQyGcq_
#define DEFINED_TYPEDEF_FOR_struct_H17tBJfv2iKNHzYuQyGcq_
typedef struct { real_T d_start ; real_T d_end ; real_T t_to_min ; real_T
t_to_max ; } struct_H17tBJfv2iKNHzYuQyGcq ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_wVXO2ubp0vrpfEB7y1WbUF_
#define DEFINED_TYPEDEF_FOR_struct_wVXO2ubp0vrpfEB7y1WbUF_
typedef struct { struct_H17tBJfv2iKNHzYuQyGcq TL1 ;
struct_H17tBJfv2iKNHzYuQyGcq TL2 ; } struct_wVXO2ubp0vrpfEB7y1WbUF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_Aamt3l8oV8aC2LkUAtJ23G_
#define DEFINED_TYPEDEF_FOR_struct_Aamt3l8oV8aC2LkUAtJ23G_
typedef struct { struct_wVXO2ubp0vrpfEB7y1WbUF vx ; }
struct_Aamt3l8oV8aC2LkUAtJ23G ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_kQRwHoRjleHGHFaydi50eF_
#define DEFINED_TYPEDEF_FOR_struct_kQRwHoRjleHGHFaydi50eF_
typedef struct { real_T FILE_VERSION ; real_T FITTYP ; real_T LONGVL ; real_T
VXLOW ; real_T ROAD_INCREMENT ; real_T ROAD_DIRECTION ; real_T USER_SUB_ID ;
real_T N_TIRE_STATES ; real_T USE_MODE ; real_T HMAX_LOCAL ; real_T
TIME_SWITCH_INTEG ; real_T UNLOADED_RADIUS ; real_T WIDTH ; real_T
ASPECT_RATIO ; real_T RIM_RADIUS ; real_T RIM_WIDTH ; real_T INFLPRES ;
real_T NOMPRES ; real_T MASS1 ; real_T IXX ; real_T IYY ; real_T BELT_MASS ;
real_T BELT_IXX ; real_T BELT_IYY ; real_T GRAVITY ; real_T FNOMIN ; real_T
VERTICAL_STIFFNESS ; real_T VERTICAL_DAMPING ; real_T MC_CONTOUR_A ; real_T
MC_CONTOUR_B ; real_T BREFF ; real_T DREFF ; real_T FREFF ; real_T Q_RE0 ;
real_T Q_V1 ; real_T Q_V2 ; real_T Q_FZ2 ; real_T Q_FCX ; real_T Q_FCY ;
real_T Q_CAM ; real_T PFZ1 ; real_T BOTTOM_OFFST ; real_T BOTTOM_STIFF ;
real_T LONGITUDINAL_STIFFNESS ; real_T LATERAL_STIFFNESS ; real_T
YAW_STIFFNESS ; real_T FREQ_LONG ; real_T FREQ_LAT ; real_T FREQ_YAW ; real_T
FREQ_WINDUP ; real_T DAMP_LONG ; real_T DAMP_LAT ; real_T DAMP_YAW ; real_T
DAMP_WINDUP ; real_T DAMP_RESIDUAL ; real_T DAMP_VLOW ; real_T Q_BVX ; real_T
Q_BVT ; real_T PCFX1 ; real_T PCFX2 ; real_T PCFX3 ; real_T PCFY1 ; real_T
PCFY2 ; real_T PCFY3 ; real_T PCMZ1 ; real_T Q_RA1 ; real_T Q_RA2 ; real_T
Q_RB1 ; real_T Q_RB2 ; real_T ELLIPS_SHIFT ; real_T ELLIPS_LENGTH ; real_T
ELLIPS_HEIGHT ; real_T ELLIPS_ORDER ; real_T ELLIPS_MAX_STEP ; real_T
ELLIPS_NWIDTH ; real_T ELLIPS_NLENGTH ; real_T PRESMIN ; real_T PRESMAX ;
real_T FZMIN ; real_T FZMAX ; real_T KPUMIN ; real_T KPUMAX ; real_T ALPMIN ;
real_T ALPMAX ; real_T CAMMIN ; real_T CAMMAX ; real_T LFZO ; real_T LCX ;
real_T LMUX ; real_T LEX ; real_T LKX ; real_T LHX ; real_T LVX ; real_T LCY
; real_T LMUY ; real_T LEY ; real_T LKY ; real_T LHY ; real_T LVY ; real_T
LTR ; real_T LRES ; real_T LXAL ; real_T LYKA ; real_T LVYKA ; real_T LS ;
real_T LKYC ; real_T LKZC ; real_T LVMX ; real_T LMX ; real_T LMY ; real_T
LMP ; real_T PCX1 ; real_T PDX1 ; real_T PDX2 ; real_T PDX3 ; real_T PEX1 ;
real_T PEX2 ; real_T PEX3 ; real_T PEX4 ; real_T PKX1 ; real_T PKX2 ; real_T
PKX3 ; real_T PHX1 ; real_T PHX2 ; real_T PVX1 ; real_T PVX2 ; real_T PPX1 ;
real_T PPX2 ; real_T PPX3 ; real_T PPX4 ; real_T RBX1 ; real_T RBX2 ; real_T
RBX3 ; real_T RCX1 ; real_T REX1 ; real_T REX2 ; real_T RHX1 ; real_T QSX1 ;
real_T QSX2 ; real_T QSX3 ; real_T QSX4 ; real_T QSX5 ; real_T QSX6 ; real_T
QSX7 ; real_T QSX8 ; real_T QSX9 ; real_T QSX10 ; real_T QSX11 ; real_T QSX12
; real_T QSX13 ; real_T QSX14 ; real_T PPMX1 ; real_T PCY1 ; real_T PDY1 ;
real_T PDY2 ; real_T PDY3 ; real_T PEY1 ; real_T PEY2 ; real_T PEY3 ; real_T
PEY4 ; real_T PEY5 ; real_T PKY1 ; real_T PKY2 ; real_T PKY3 ; real_T PKY4 ;
real_T PKY5 ; real_T PKY6 ; real_T PKY7 ; real_T PHY1 ; real_T PHY2 ; real_T
PVY1 ; real_T PVY2 ; real_T PVY3 ; real_T PVY4 ; real_T PPY1 ; real_T PPY2 ;
real_T PPY3 ; real_T PPY4 ; real_T PPY5 ; real_T RBY1 ; real_T RBY2 ; real_T
RBY3 ; real_T RBY4 ; real_T RCY1 ; real_T REY1 ; real_T REY2 ; real_T RHY1 ;
real_T RHY2 ; real_T RVY1 ; real_T RVY2 ; real_T RVY3 ; real_T RVY4 ; real_T
RVY5 ; real_T RVY6 ; real_T QSY1 ; real_T QSY2 ; real_T QSY3 ; real_T QSY4 ;
real_T QSY5 ; real_T QSY6 ; real_T QSY7 ; real_T QSY8 ; real_T QBZ1 ; real_T
QBZ2 ; real_T QBZ3 ; real_T QBZ4 ; real_T QBZ5 ; real_T QBZ9 ; real_T QBZ10 ;
real_T QCZ1 ; real_T QDZ1 ; real_T QDZ2 ; real_T QDZ3 ; real_T QDZ4 ; real_T
QDZ6 ; real_T QDZ7 ; real_T QDZ8 ; real_T QDZ9 ; real_T QDZ10 ; real_T QDZ11
; real_T QEZ1 ; real_T QEZ2 ; real_T QEZ3 ; real_T QEZ4 ; real_T QEZ5 ;
real_T QHZ1 ; real_T QHZ2 ; real_T QHZ3 ; real_T QHZ4 ; real_T PPZ1 ; real_T
PPZ2 ; real_T SSZ1 ; real_T SSZ2 ; real_T SSZ3 ; real_T SSZ4 ; real_T PDXP1 ;
real_T PDXP2 ; real_T PDXP3 ; real_T PKYP1 ; real_T PDYP1 ; real_T PDYP2 ;
real_T PDYP3 ; real_T PDYP4 ; real_T PHYP1 ; real_T PHYP2 ; real_T PHYP3 ;
real_T PHYP4 ; real_T PECP1 ; real_T PECP2 ; real_T QDTP1 ; real_T QCRP1 ;
real_T QCRP2 ; real_T QBRP1 ; real_T QDRP1 ; real_T SWITCH_INTEG ; real_T
Q_FCY2 ; real_T Q_CAM1 ; real_T Q_CAM2 ; real_T Q_CAM3 ; real_T Q_FYS1 ;
real_T Q_FYS2 ; real_T Q_FYS3 ; real_T ENV_C1 ; real_T ENV_C2 ; real_T Q_A1 ;
real_T Q_A2 ; real_T PHY3 ; real_T PTX1 ; real_T PTX2 ; real_T PTX3 ; real_T
PTY1 ; real_T PTY2 ; real_T LSGKP ; real_T LSGAL ; }
struct_kQRwHoRjleHGHFaydi50eF ;
#endif
#ifndef struct_tag_sX0uxA0Pn3nfAGI4HkabmEF
#define struct_tag_sX0uxA0Pn3nfAGI4HkabmEF
struct tag_sX0uxA0Pn3nfAGI4HkabmEF { boolean_T useLimitsCheck ; boolean_T
useAlphaStar ; boolean_T useTurnSlip ; boolean_T isLowSpeed ; boolean_T
isLowSpeedAlpha ; real_T userDynamics ; } ;
#endif
#ifndef typedef_ntc4vogpvg
#define typedef_ntc4vogpvg
typedef struct tag_sX0uxA0Pn3nfAGI4HkabmEF ntc4vogpvg ;
#endif
#ifndef struct_tag_sbJC7u7wkkygEpNzna3fywF
#define struct_tag_sbJC7u7wkkygEpNzna3fywF
struct tag_sbJC7u7wkkygEpNzna3fywF { real_T dfz ; real_T dpi ; } ;
#endif
#ifndef typedef_jvlq1j5bnt
#define typedef_jvlq1j5bnt
typedef struct tag_sbJC7u7wkkygEpNzna3fywF jvlq1j5bnt ;
#endif
#ifndef struct_tag_sFiDIEH4AWDo5JlWoOi3EGB
#define struct_tag_sFiDIEH4AWDo5JlWoOi3EGB
struct tag_sFiDIEH4AWDo5JlWoOi3EGB { real_T Fz0_prime ; real_T alpha_prime ;
real_T LMUX_prime ; real_T LMUY_prime ; } ;
#endif
#ifndef typedef_jgwgfn3sxv
#define typedef_jgwgfn3sxv
typedef struct tag_sFiDIEH4AWDo5JlWoOi3EGB jgwgfn3sxv ;
#endif
#ifndef struct_tag_sYCavDvexSHefOa1o0DCKzE
#define struct_tag_sYCavDvexSHefOa1o0DCKzE
struct tag_sYCavDvexSHefOa1o0DCKzE { real_T alpha_star ; real_T gamma_star ;
real_T LMUX_star ; real_T LMUY_star ; } ;
#endif
#ifndef typedef_pxpdgjslat
#define typedef_pxpdgjslat
typedef struct tag_sYCavDvexSHefOa1o0DCKzE pxpdgjslat ;
#endif
#ifndef struct_tag_spYABAdq0fxXKOyhHVynXpF
#define struct_tag_spYABAdq0fxXKOyhHVynXpF
struct tag_spYABAdq0fxXKOyhHVynXpF { real_T alpha ; real_T kappa ; real_T
b_gamma ; real_T phit ; real_T Fz ; real_T p ; real_T omega ; real_T phi ;
real_T Vsx ; real_T uFz ; real_T ukappa ; real_T ukappaLow ; real_T ualpha ;
real_T ugamma ; real_T uphit ; real_T uVcx ; real_T nInputs ; real_T
Fz_lowLimit ; } ;
#endif
#ifndef typedef_dp22opl3g0
#define typedef_dp22opl3g0
typedef struct tag_spYABAdq0fxXKOyhHVynXpF dp22opl3g0 ;
#endif
#ifndef struct_tag_sgKan33EWlxEH2sCnyGB5vH
#define struct_tag_sgKan33EWlxEH2sCnyGB5vH
struct tag_sgKan33EWlxEH2sCnyGB5vH { real_T Fx ; real_T Fy ; real_T Fz ;
real_T Mx ; real_T My ; real_T Mz ; } ;
#endif
#ifndef typedef_klzd0t023a
#define typedef_klzd0t023a
typedef struct tag_sgKan33EWlxEH2sCnyGB5vH klzd0t023a ;
#endif
#ifndef struct_tag_smlIHh2I3XhmLFvZf75tslB
#define struct_tag_smlIHh2I3XhmLFvZf75tslB
struct tag_smlIHh2I3XhmLFvZf75tslB { real_T Kxk ; real_T mux ; real_T Kya ;
real_T muy ; real_T t ; real_T Mzr ; } ;
#endif
#ifndef typedef_cy0xbqyc00
#define typedef_cy0xbqyc00
typedef struct tag_smlIHh2I3XhmLFvZf75tslB cy0xbqyc00 ;
#endif
#ifndef struct_emxArray_real_T_1x1
#define struct_emxArray_real_T_1x1
struct emxArray_real_T_1x1 { real_T data ; int32_T size [ 2 ] ; } ;
#endif
#ifndef typedef_bdxze5bf13
#define typedef_bdxze5bf13
typedef struct emxArray_real_T_1x1 bdxze5bf13 ;
#endif
#ifndef struct_tag_cXYpThrbyb760O7UsSpXkB
#define struct_tag_cXYpThrbyb760O7UsSpXkB
struct tag_cXYpThrbyb760O7UsSpXkB { real_T epsilonx ; real_T epsilonk ;
real_T epsilony ; real_T epsilonr ; real_T epsilonv ; bdxze5bf13
reductionSmooth ; bdxze5bf13 reductionSharp ; bdxze5bf13 reductionLinear ;
bdxze5bf13 reductionLinear_alpha ; real_T zeta2 ; real_T epsilong ; } ;
#endif
#ifndef typedef_pd1iththej
#define typedef_pd1iththej
typedef struct tag_cXYpThrbyb760O7UsSpXkB pd1iththej ;
#endif
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T { real_T * data ; int32_T * size ; int32_T
allocatedSize ; int32_T numDimensions ; boolean_T canFreeData ; } ;
#endif
#ifndef typedef_pmvtuvwiaa
#define typedef_pmvtuvwiaa
typedef struct emxArray_real_T pmvtuvwiaa ;
#endif
#ifndef SS_UINT64
#define SS_UINT64 34
#endif
#ifndef SS_INT64
#define SS_INT64 35
#endif
typedef struct mbv0ec4zb2_ mbv0ec4zb2 ; typedef struct kgxijxq1i2_ kgxijxq1i2
; typedef struct P_ P ;
#endif
