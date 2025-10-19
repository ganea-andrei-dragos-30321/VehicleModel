//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MotorControl1.h
//
// Code generated for Simulink model 'MotorControl1'.
//
// Model version                  : 13.51
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Fri Jun 27 18:01:26 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef MotorControl1_h_
#define MotorControl1_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Class declaration for model MotorControl1
class MotorControl1 final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T outputMFCache[1400];
    real_T Switch2;                    // '<S12>/Switch2'
    real_T Switch2_f;                  // '<S13>/Switch2'
    real_T Sum;                        // '<S3>/Sum'
    real_T Delay_DSTATE;               // '<S3>/Delay'
    real_T Memory_PreviousInput;       // '<S10>/Memory'
    real_T Memory_PreviousInput_e;     // '<S11>/Memory'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Expression: fis.outputSamplePoints
    //  Referenced by: '<S14>/Output Sample Points'

    real_T OutputSamplePoints_Value[200];

    // Pooled Parameter (Expression: MTrq)
    //  Referenced by:
    //    '<S2>/1-D Lookup Table'
    //    '<S2>/1-D Lookup Table1'
    //    '<S4>/1-D Lookup Table'
    //    '<S4>/1-D Lookup Table1'

    real_T pooled9[71];

    // Pooled Parameter (Expression: MWhlSpin)
    //  Referenced by:
    //    '<S2>/1-D Lookup Table'
    //    '<S2>/1-D Lookup Table1'
    //    '<S4>/1-D Lookup Table'
    //    '<S4>/1-D Lookup Table1'

    real_T pooled10[71];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T aSteerWheel;                // '<Root>/aSteerWheel'
    real_T vx;                         // '<Root>/<vx>'
    real_T gy;                         // '<Root>/<gy>'
    real_T nYaw;                       // '<Root>/<nYaw>'
    real_T w;                          // '<Root>/wL'
    real_T w_g;                        // '<Root>/wR'
    real_T Throttle;                   // '<Root>/Throttle[~]1'
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
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
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
  MotorControl1(MotorControl1 const&) = delete;

  // Assignment Operator
  MotorControl1& operator= (MotorControl1 const&) & = delete;

  // Move Constructor
  MotorControl1(MotorControl1 &&) = delete;

  // Move Assignment Operator
  MotorControl1& operator= (MotorControl1 &&) = delete;

  // Real-Time Model get method
  MotorControl1::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  MotorControl1();

  // Destructor
  ~MotorControl1();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // private member function(s) for subsystem '<Root>'
  real_T trimf(real_T x, const real_T params[3]);
  void trimf_l(const real_T x[200], const real_T params[3], real_T y[200]);

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const MotorControl1::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S8>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/Data Type Propagation' : Unused code path elimination
//  Block '<S9>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/Data Type Propagation' : Unused code path elimination
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
//  '<Root>' : 'MotorControl1'
//  '<S1>'   : 'MotorControl1/Conversion'
//  '<S2>'   : 'MotorControl1/Maximum Torque Allowed'
//  '<S3>'   : 'MotorControl1/Moment Required'
//  '<S4>'   : 'MotorControl1/Required Torque'
//  '<S5>'   : 'MotorControl1/Slip Control'
//  '<S6>'   : 'MotorControl1/Torque Allocation'
//  '<S7>'   : 'MotorControl1/Yaw Reference'
//  '<S8>'   : 'MotorControl1/Maximum Torque Allowed/Saturation Dynamic'
//  '<S9>'   : 'MotorControl1/Maximum Torque Allowed/Saturation Dynamic1'
//  '<S10>'  : 'MotorControl1/Maximum Torque Allowed/Slip Correction Left'
//  '<S11>'  : 'MotorControl1/Maximum Torque Allowed/Slip Correction Right'
//  '<S12>'  : 'MotorControl1/Maximum Torque Allowed/Slip Correction Left/Saturation Dynamic'
//  '<S13>'  : 'MotorControl1/Maximum Torque Allowed/Slip Correction Right/Saturation Dynamic'
//  '<S14>'  : 'MotorControl1/Moment Required/Fuzzy Logic  Controller'
//  '<S15>'  : 'MotorControl1/Moment Required/Fuzzy Logic  Controller/Defuzzify Outputs'
//  '<S16>'  : 'MotorControl1/Moment Required/Fuzzy Logic  Controller/Evaluate Rule Antecedents'
//  '<S17>'  : 'MotorControl1/Moment Required/Fuzzy Logic  Controller/Evaluate Rule Consequents'
//  '<S18>'  : 'MotorControl1/Torque Allocation/Subsystem'
//  '<S19>'  : 'MotorControl1/Torque Allocation/Subsystem/Saturation Dynamic'
//  '<S20>'  : 'MotorControl1/Yaw Reference/Angular Velocity Conversion'
//  '<S21>'  : 'MotorControl1/Yaw Reference/Saturation Dynamic'

#endif                                 // MotorControl1_h_

//
// File trailer for generated code.
//
// [EOF]
//
