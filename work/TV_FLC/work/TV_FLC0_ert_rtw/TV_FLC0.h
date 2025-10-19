//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TV_FLC0.h
//
// Code generated for Simulink model 'TV_FLC0'.
//
// Model version                  : 13.67
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Mon Jul 14 17:05:02 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef TV_FLC0_h_
#define TV_FLC0_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Class declaration for model TV_FLC0
class TV_FLC0 final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T outputMFCache[1400];
    real_T Switch2;                    // '<S15>/Switch2'
    real_T Switch2_h;                  // '<S16>/Switch2'
    real_T Sum;                        // '<S5>/Sum'
    real_T Delay_DSTATE;               // '<S5>/Delay'
    real_T Memory_PreviousInput;       // '<S13>/Memory'
    real_T Memory_PreviousInput_m;     // '<S14>/Memory'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Expression: fis.outputSamplePoints
    //  Referenced by: '<S17>/Output Sample Points'

    real_T OutputSamplePoints_Value[200];

    // Pooled Parameter (Expression: MotorT)
    //  Referenced by:
    //    '<S4>/1-D Lookup Table'
    //    '<S4>/1-D Lookup Table1'

    real_T pooled5[47];

    // Pooled Parameter (Expression: MotorW)
    //  Referenced by:
    //    '<S4>/1-D Lookup Table'
    //    '<S4>/1-D Lookup Table1'

    real_T pooled6[47];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T aSteerWheel;                // '<Root>/aSteerWheel'
    real_T vx;                         // '<Root>/<vx>'
    real_T gy;                         // '<Root>/<gy>'
    real_T nYaw;                       // '<Root>/<nYaw>'
    real_T wL;                         // '<Root>/wL'
    real_T wR;                         // '<Root>/wR'
    real_T Throttle;                   // '<Root>/Throttle[~]'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T MMotorL2Demand;             // '<Root>/MMotorL2Demand'
    real_T MMotorR2Demand;             // '<Root>/MMotorR2Demand'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;

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

    time_T** getTPtrPtr();
    boolean_T isMinorTimeStep() const;
    time_T* getTPtr() const;
    void setTPtr(time_T* aTPtr);
    boolean_T isMajorTimeStep() const;
    const char_T** getErrorStatusPtr();
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus);
  };

  // Copy Constructor
  TV_FLC0(TV_FLC0 const&) = delete;

  // Assignment Operator
  TV_FLC0& operator= (TV_FLC0 const&) & = delete;

  // Move Constructor
  TV_FLC0(TV_FLC0 &&) = delete;

  // Move Assignment Operator
  TV_FLC0& operator= (TV_FLC0 &&) = delete;

  // Real-Time Model get method
  TV_FLC0::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  TV_FLC0();

  // Destructor
  ~TV_FLC0();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // private member function(s) for subsystem '<Root>'
  real_T trimf(real_T x, const real_T params[3]);
  void trimf_h(const real_T x[200], const real_T params[3], real_T y[200]);

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const TV_FLC0::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination
//  Block '<Root>/Scope2' : Unused code path elimination
//  Block '<Root>/Scope3' : Unused code path elimination
//  Block '<S10>/Data Type Duplicate' : Unused code path elimination
//  Block '<S10>/Data Type Propagation' : Unused code path elimination
//  Block '<S8>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/Data Type Propagation' : Unused code path elimination
//  Block '<S9>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/Data Type Propagation' : Unused code path elimination
//  Block '<S11>/Data Type Duplicate' : Unused code path elimination
//  Block '<S11>/Data Type Propagation' : Unused code path elimination
//  Block '<S12>/Data Type Duplicate' : Unused code path elimination
//  Block '<S12>/Data Type Propagation' : Unused code path elimination
//  Block '<S15>/Data Type Duplicate' : Unused code path elimination
//  Block '<S15>/Data Type Propagation' : Unused code path elimination
//  Block '<S16>/Data Type Duplicate' : Unused code path elimination
//  Block '<S16>/Data Type Propagation' : Unused code path elimination
//  Block '<S5>/Scope' : Unused code path elimination
//  Block '<S22>/Data Type Duplicate' : Unused code path elimination
//  Block '<S22>/Data Type Propagation' : Unused code path elimination
//  Block '<S6>/Scope' : Unused code path elimination
//  Block '<S17>/InputConversion' : Eliminate redundant data type conversion


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
//  '<Root>' : 'TV_FLC0'
//  '<S1>'   : 'TV_FLC0/Conversion'
//  '<S2>'   : 'TV_FLC0/Slip Control'
//  '<S3>'   : 'TV_FLC0/Torque Allocation'
//  '<S4>'   : 'TV_FLC0/Torque intervention'
//  '<S5>'   : 'TV_FLC0/Yaw Moment Required'
//  '<S6>'   : 'TV_FLC0/Yaw Reference'
//  '<S7>'   : 'TV_FLC0/Torque Allocation/Delta Torque'
//  '<S8>'   : 'TV_FLC0/Torque Allocation/Saturation Dynamic'
//  '<S9>'   : 'TV_FLC0/Torque Allocation/Saturation Dynamic1'
//  '<S10>'  : 'TV_FLC0/Torque Allocation/Delta Torque/Saturation Dynamic'
//  '<S11>'  : 'TV_FLC0/Torque intervention/Saturation Dynamic'
//  '<S12>'  : 'TV_FLC0/Torque intervention/Saturation Dynamic1'
//  '<S13>'  : 'TV_FLC0/Torque intervention/Slip Correction Left'
//  '<S14>'  : 'TV_FLC0/Torque intervention/Slip Correction Right'
//  '<S15>'  : 'TV_FLC0/Torque intervention/Slip Correction Left/Saturation Dynamic'
//  '<S16>'  : 'TV_FLC0/Torque intervention/Slip Correction Right/Saturation Dynamic'
//  '<S17>'  : 'TV_FLC0/Yaw Moment Required/Fuzzy Logic  Controller'
//  '<S18>'  : 'TV_FLC0/Yaw Moment Required/Fuzzy Logic  Controller/Defuzzify Outputs'
//  '<S19>'  : 'TV_FLC0/Yaw Moment Required/Fuzzy Logic  Controller/Evaluate Rule Antecedents'
//  '<S20>'  : 'TV_FLC0/Yaw Moment Required/Fuzzy Logic  Controller/Evaluate Rule Consequents'
//  '<S21>'  : 'TV_FLC0/Yaw Reference/Degrees to Radians'
//  '<S22>'  : 'TV_FLC0/Yaw Reference/Saturation Dynamic'

#endif                                 // TV_FLC0_h_

//
// File trailer for generated code.
//
// [EOF]
//
