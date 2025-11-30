//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Slip_Control_CodeGen.h
//
// Code generated for Simulink model 'Slip_Control_CodeGen'.
//
// Model version                  : 15.43
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Sun Nov 30 14:28:26 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef Slip_Control_CodeGen_h_
#define Slip_Control_CodeGen_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include <string>

// Class declaration for model Slip_Control_CodeGen
class Slip_Control_CodeGen final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T Switch2;                    // '<S9>/Switch2'
    real_T Switch2_d;                  // '<S10>/Switch2'
    real_T Memory_PreviousInput;       // '<S7>/Memory'
    real_T Memory_PreviousInput_m;     // '<S8>/Memory'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Pooled Parameter (Expression: MotorT)
    //  Referenced by:
    //    '<S2>/1-D Lookup Table'
    //    '<S2>/1-D Lookup Table1'

    real_T pooled4[47];

    // Pooled Parameter (Expression: MotorW)
    //  Referenced by:
    //    '<S2>/1-D Lookup Table'
    //    '<S2>/1-D Lookup Table1'

    real_T pooled5[47];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T vx;                         // '<Root>/<vx>'
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
  Slip_Control_CodeGen(Slip_Control_CodeGen const&) = delete;

  // Assignment Operator
  Slip_Control_CodeGen& operator= (Slip_Control_CodeGen const&) & = delete;

  // Move Constructor
  Slip_Control_CodeGen(Slip_Control_CodeGen &&) = delete;

  // Move Assignment Operator
  Slip_Control_CodeGen& operator= (Slip_Control_CodeGen &&) = delete;

  // Real-Time Model get method
  Slip_Control_CodeGen::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  Slip_Control_CodeGen();

  // Destructor
  ~Slip_Control_CodeGen();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const Slip_Control_CodeGen::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S5>/Data Type Duplicate' : Unused code path elimination
//  Block '<S5>/Data Type Propagation' : Unused code path elimination
//  Block '<S6>/Data Type Duplicate' : Unused code path elimination
//  Block '<S6>/Data Type Propagation' : Unused code path elimination
//  Block '<S9>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/Data Type Propagation' : Unused code path elimination
//  Block '<S10>/Data Type Duplicate' : Unused code path elimination
//  Block '<S10>/Data Type Propagation' : Unused code path elimination
//  Block '<S3>/Scope' : Unused code path elimination


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
//  '<Root>' : 'Slip_Control_CodeGen'
//  '<S1>'   : 'Slip_Control_CodeGen/Maximum Torque Allowed'
//  '<S2>'   : 'Slip_Control_CodeGen/Required Torque'
//  '<S3>'   : 'Slip_Control_CodeGen/Slip Control'
//  '<S4>'   : 'Slip_Control_CodeGen/Torque Allocation'
//  '<S5>'   : 'Slip_Control_CodeGen/Maximum Torque Allowed/Saturation Dynamic'
//  '<S6>'   : 'Slip_Control_CodeGen/Maximum Torque Allowed/Saturation Dynamic1'
//  '<S7>'   : 'Slip_Control_CodeGen/Maximum Torque Allowed/Slip Correction Left'
//  '<S8>'   : 'Slip_Control_CodeGen/Maximum Torque Allowed/Slip Correction Right'
//  '<S9>'   : 'Slip_Control_CodeGen/Maximum Torque Allowed/Slip Correction Left/Saturation Dynamic'
//  '<S10>'  : 'Slip_Control_CodeGen/Maximum Torque Allowed/Slip Correction Right/Saturation Dynamic'

#endif                                 // Slip_Control_CodeGen_h_

//
// File trailer for generated code.
//
// [EOF]
//
