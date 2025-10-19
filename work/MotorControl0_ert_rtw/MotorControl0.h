//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MotorControl0.h
//
// Code generated for Simulink model 'MotorControl0'.
//
// Model version                  : 13.51
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Fri Jun 27 17:07:29 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef MotorControl0_h_
#define MotorControl0_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include <string.h>
#include <stddef.h>
#define MotorControl0_M                (rtM)

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// Block signals and states (default storage) for system '<Root>'
struct DW {
  real_T outputMFCache[1400];
  real_T aggregatedOutputs[200];       // '<S14>/Evaluate Rule Consequents'
  real_T dv[200];
  real_T dv1[200];
  real_T dv2[200];
  real_T dv3[200];
  real_T dv4[200];
  real_T dv5[200];
  real_T dv6[200];
  real_T antecedentOutputs[49];        // '<S14>/Evaluate Rule Antecedents'
  real_T inputMFCache[14];
  real_T Switch2;                      // '<S12>/Switch2'
  real_T Switch2_b;                    // '<S13>/Switch2'
  real_T Sum;                          // '<S3>/Sum'
  real_T Delay_DSTATE;                 // '<S3>/Delay'
  real_T Memory_PreviousInput;         // '<S10>/Memory'
  real_T Memory_PreviousInput_n;       // '<S11>/Memory'
  real_T MMotorR2Demand;               // '<S6>/Saturation1'
  real_T Switch1;                      // '<S10>/Switch1'
  real_T Product;                      // '<S2>/Product'
  real_T TRNm;                         // '<S2>/1-D Lookup Table1'
  real_T YawDesired;                   // '<S7>/Divide1'
  real_T rtb_TmpSignalConversionAtSFun_m;
};

// External inputs (root inport signals with default storage)
struct ExtU {
  real_T aSteerWheel;                  // '<Root>/aSteerWheel'
  real_T vx;                           // '<Root>/<vx>'
  real_T gy;                           // '<Root>/<gy>'
  real_T nYaw;                         // '<Root>/<nYaw>'
  real_T w;                            // '<Root>/wL'
  real_T w_g;                          // '<Root>/wR'
  real_T Throttle;                     // '<Root>/Throttle[~]'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY {
  real_T MMotorL2Demand;               // '<Root>/MMotorL2Demand'
  real_T MMotorR2Demand;               // '<Root>/MMotorR2Demand'
};

// Parameters (default storage)
struct P_ {
  real_T F;                            // Variable: F
                                          //  Referenced by: '<S18>/Gain'

  real_T Gr;                           // Variable: Gr
                                          //  Referenced by: '<S5>/rwheel'

  real_T Kneg;                         // Variable: Kneg
                                          //  Referenced by:
                                          //    '<S10>/Gain'
                                          //    '<S11>/Gain'

  real_T Kp;                           // Variable: Kp
                                          //  Referenced by: '<S3>/Gain'

  real_T Kpos;                         // Variable: Kpos
                                          //  Referenced by:
                                          //    '<S10>/Gain1'
                                          //    '<S11>/Gain1'

  real_T Ku;                           // Variable: Ku
                                          //  Referenced by: '<S7>/Gain'

  real_T L;                            // Variable: L
                                          //  Referenced by: '<S7>/Constant'

  real_T MTrq[71];                     // Variable: MTrq
                                          //  Referenced by:
                                          //    '<S2>/1-D Lookup Table'
                                          //    '<S2>/1-D Lookup Table1'
                                          //    '<S4>/1-D Lookup Table'
                                          //    '<S4>/1-D Lookup Table1'

  real_T MWhlSpin[71];                 // Variable: MWhlSpin
                                          //  Referenced by:
                                          //    '<S2>/1-D Lookup Table'
                                          //    '<S2>/1-D Lookup Table1'
                                          //    '<S4>/1-D Lookup Table'
                                          //    '<S4>/1-D Lookup Table1'

  real_T StrWheelRatio;                // Variable: StrWheelRatio
                                          //  Referenced by: '<S7>/StrWheelRatio'

  real_T alpha_max;                    // Variable: alpha_max
                                          //  Referenced by:
                                          //    '<S10>/Switch1'
                                          //    '<S11>/Switch1'

  real_T rwheel;                       // Variable: rwheel
                                          //  Referenced by:
                                          //    '<S3>/rwheel'
                                          //    '<S5>/rwheel'

  real_T tr;                           // Variable: tr
                                          //  Referenced by: '<S3>/RearTrack'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S2>/Gain'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S2>/Gain1'

  real_T OutputSamplePoints_Value[200];// Expression: fis.outputSamplePoints
                                          //  Referenced by: '<S14>/Output Sample Points'

  real_T Gain3_Gain;                   // Expression: 2
                                          //  Referenced by: '<S18>/Gain3'

  real_T Gain1_Gain_d;                 // Expression: -1
                                          //  Referenced by: '<S7>/Gain1'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S5>/Constant'

  real_T Constant2_Value;              // Expression: 1
                                          //  Referenced by: '<S10>/Constant2'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S10>/Memory'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S10>/Constant1'

  real_T radstorpm1_Gain;              // Expression: 60/pi/2
                                          //  Referenced by: '<S2>/rad//s to rpm1'

  real_T radstorpm2_Gain;              // Expression: 60/pi/2
                                          //  Referenced by: '<S4>/rad//s to rpm 2'

  real_T radstorpm_Gain;               // Expression: 60/pi/2
                                          //  Referenced by: '<S4>/rad//s to rpm'

  real_T Gain1_Gain_f;                 // Expression: 1/2
                                          //  Referenced by: '<S6>/Gain1'

  real_T radstorpm_Gain_o;             // Expression: 60/pi/2
                                          //  Referenced by: '<S2>/rad//s to rpm'

  real_T Constant2_Value_g;            // Expression: 1
                                          //  Referenced by: '<S11>/Constant2'

  real_T Memory_InitialCondition_o;    // Expression: 0
                                          //  Referenced by: '<S11>/Memory'

  real_T Constant1_Value_b;            // Expression: 0
                                          //  Referenced by: '<S11>/Constant1'

  real_T Gain2_Gain;                   // Expression: 2
                                          //  Referenced by: '<S18>/Gain2'

  real_T Gain2_Gain_f;                 // Expression: 9.80665
                                          //  Referenced by: '<Root>/Gain2'

  real_T Bias_Bias;                    // Expression: -512
                                          //  Referenced by: '<S1>/Bias'

  real_T Gain2_Gain_m;                 // Expression: 1/511
                                          //  Referenced by: '<S1>/Gain2'

  real_T Gain3_Gain_c;                 // Expression: 154
                                          //  Referenced by: '<S1>/Gain3'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S3>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S3>/Saturation2'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S3>/Delay'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S3>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S3>/Saturation1'

  real_T Gain_Gain_l;                  // Expression: 1/2
                                          //  Referenced by: '<S6>/Gain'

  real_T Saturation_UpperSat;          // Expression: 60
                                          //  Referenced by: '<S6>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S6>/Saturation'

  real_T Gain_Gain_a;                  // Expression: 1/60
                                          //  Referenced by: '<Root>/Gain'

  real_T Saturation1_UpperSat_d;       // Expression: 60
                                          //  Referenced by: '<S6>/Saturation1'

  real_T Saturation1_LowerSat_f;       // Expression: 0
                                          //  Referenced by: '<S6>/Saturation1'

  real_T Gain1_Gain_i;                 // Expression: 1/60
                                          //  Referenced by: '<Root>/Gain1'

};

// Parameters (default storage)
typedef struct P_ P;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  DW *dwork;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint16_T clockTick0;
    time_T stepSize0;
    uint16_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;

  time_T* getTPtr() const;
  void setTPtr(time_T* aTPtr);
  boolean_T isMinorTimeStep() const;
  boolean_T isMajorTimeStep() const;
  const char_T** getErrorStatusPtr();
  time_T** getTPtrPtr();
  DW* getRootDWork() const;
  void setRootDWork(DW* aRootDWork);
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const aErrorStatus);
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P rtP;

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void MotorControl0_initialize(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY);
  extern void MotorControl0_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY);

#ifdef __cplusplus

}

#endif

#define NOT_USING_NONFINITE_LITERALS   1

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static void rt_InitInfAndNaN(size_t realSize);
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
  struct BigEndianIEEEDouble {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  };

  struct LittleEndianIEEEDouble {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  };

  struct IEEESingle {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  };
}                                      // extern "C"

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S8>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/Data Type Propagation' : Unused code path elimination
//  Block '<S9>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/Data Type Propagation' : Unused code path elimination
//  Block '<S2>/Scope' : Unused code path elimination
//  Block '<S12>/Data Type Duplicate' : Unused code path elimination
//  Block '<S12>/Data Type Propagation' : Unused code path elimination
//  Block '<S13>/Data Type Duplicate' : Unused code path elimination
//  Block '<S13>/Data Type Propagation' : Unused code path elimination
//  Block '<S3>/Scope' : Unused code path elimination
//  Block '<S19>/Data Type Duplicate' : Unused code path elimination
//  Block '<S19>/Data Type Propagation' : Unused code path elimination
//  Block '<S21>/Data Type Duplicate' : Unused code path elimination
//  Block '<S21>/Data Type Propagation' : Unused code path elimination
//  Block '<S14>/InputConversion' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'MotorControl0'
//  '<S1>'   : 'MotorControl0/Conversion'
//  '<S2>'   : 'MotorControl0/Maximum Torque Allowed'
//  '<S3>'   : 'MotorControl0/Moment Required'
//  '<S4>'   : 'MotorControl0/Required Torque'
//  '<S5>'   : 'MotorControl0/Slip Control'
//  '<S6>'   : 'MotorControl0/Torque Allocation'
//  '<S7>'   : 'MotorControl0/Yaw Reference'
//  '<S8>'   : 'MotorControl0/Maximum Torque Allowed/Saturation Dynamic'
//  '<S9>'   : 'MotorControl0/Maximum Torque Allowed/Saturation Dynamic1'
//  '<S10>'  : 'MotorControl0/Maximum Torque Allowed/Slip Correction Left'
//  '<S11>'  : 'MotorControl0/Maximum Torque Allowed/Slip Correction Right'
//  '<S12>'  : 'MotorControl0/Maximum Torque Allowed/Slip Correction Left/Saturation Dynamic'
//  '<S13>'  : 'MotorControl0/Maximum Torque Allowed/Slip Correction Right/Saturation Dynamic'
//  '<S14>'  : 'MotorControl0/Moment Required/Fuzzy Logic  Controller'
//  '<S15>'  : 'MotorControl0/Moment Required/Fuzzy Logic  Controller/Defuzzify Outputs'
//  '<S16>'  : 'MotorControl0/Moment Required/Fuzzy Logic  Controller/Evaluate Rule Antecedents'
//  '<S17>'  : 'MotorControl0/Moment Required/Fuzzy Logic  Controller/Evaluate Rule Consequents'
//  '<S18>'  : 'MotorControl0/Torque Allocation/Subsystem'
//  '<S19>'  : 'MotorControl0/Torque Allocation/Subsystem/Saturation Dynamic'
//  '<S20>'  : 'MotorControl0/Yaw Reference/Angular Velocity Conversion'
//  '<S21>'  : 'MotorControl0/Yaw Reference/Saturation Dynamic'

#endif                                 // MotorControl0_h_

//
// File trailer for generated code.
//
// [EOF]
//
