//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Slip_Control_CodeGen.cpp
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
#include "Slip_Control_CodeGen.h"
#include <cmath>
#include "rtwtypes.h"

static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    // Binary Search
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'wrapping'

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1UL] - yL_0d0) * frac + yL_0d0;
}

// Model step function
void Slip_Control_CodeGen::step()
{
  real_T rtb_DigitalClock;
  real_T rtb_MMotorR2Demand;
  real_T rtb_Switch_a;
  real_T rtb_TLNm;
  real_T rtb_TRNm;

  // Lookup_n-D: '<S2>/1-D Lookup Table' incorporates:
  //   Gain: '<S2>/rad//s to rpm 2'
  //   Inport: '<Root>/wL'

  rtb_TLNm = look1_binlx(9.5492965855137211 * rtU.wL, rtConstP.pooled5,
    rtConstP.pooled4, 46UL);

  // Lookup_n-D: '<S2>/1-D Lookup Table1' incorporates:
  //   Gain: '<S2>/rad//s to rpm'
  //   Inport: '<Root>/wR'

  rtb_TRNm = look1_binlx(9.5492965855137211 * rtU.wR, rtConstP.pooled5,
    rtConstP.pooled4, 46UL);

  // Gain: '<S4>/Gain1' incorporates:
  //   Inport: '<Root>/Throttle[~]'
  //   Product: '<S2>/Product'
  //   Sum: '<S2>/Sum of Elements'

  rtb_MMotorR2Demand = (rtb_TLNm + rtb_TRNm) * rtU.Throttle * 0.5;

  // DigitalClock: '<S7>/Digital Clock' incorporates:
  //   DigitalClock: '<S8>/Digital Clock'

  rtb_Switch_a = (((&rtM)->Timing.clockTick1) * 0.001);

  // Switch: '<S7>/Switch' incorporates:
  //   Constant: '<S7>/Constant2'
  //   DigitalClock: '<S7>/Digital Clock'
  //   Memory: '<S7>/Memory'

  if (rtb_Switch_a != 0.0) {
    rtb_DigitalClock = rtDW.Memory_PreviousInput;
  } else {
    rtb_DigitalClock = 1.0;
  }

  // End of Switch: '<S7>/Switch'

  // Switch: '<S7>/Switch1' incorporates:
  //   Abs: '<S3>/Abs'
  //   Constant: '<S3>/Constant'
  //   Gain: '<S3>/Gr'
  //   Gain: '<S3>/rwheel'
  //   Gain: '<S7>/Gain'
  //   Gain: '<S7>/Gain1'
  //   Inport: '<Root>/<vx>'
  //   Inport: '<Root>/wL'
  //   Product: '<S3>/Divide'
  //   Sum: '<S3>/Subtract'

  if (std::abs(1.0 - 0.2 * rtU.wL * 0.2603 / rtU.vx) >= 0.12) {
    rtb_DigitalClock *= 0.999;
  } else {
    rtb_DigitalClock *= 1.001;
  }

  // End of Switch: '<S7>/Switch1'

  // Switch: '<S9>/Switch2' incorporates:
  //   Constant: '<S7>/Constant1'
  //   Constant: '<S7>/Constant2'
  //   RelationalOperator: '<S9>/LowerRelop1'
  //   RelationalOperator: '<S9>/UpperRelop'
  //   Switch: '<S9>/Switch'

  if (rtb_DigitalClock > 1.0) {
    // Switch: '<S9>/Switch2'
    rtDW.Switch2 = 1.0;
  } else if (rtb_DigitalClock < 0.0) {
    // Switch: '<S9>/Switch' incorporates:
    //   Constant: '<S7>/Constant1'
    //   Switch: '<S9>/Switch2'

    rtDW.Switch2 = 0.0;
  } else {
    // Switch: '<S9>/Switch2' incorporates:
    //   Switch: '<S9>/Switch'

    rtDW.Switch2 = rtb_DigitalClock;
  }

  // End of Switch: '<S9>/Switch2'

  // Product: '<S1>/Product'
  rtb_DigitalClock = rtDW.Switch2 * rtb_TLNm;

  // Switch: '<S5>/Switch2' incorporates:
  //   RelationalOperator: '<S5>/LowerRelop1'

  if (!(rtb_DigitalClock > rtb_TLNm)) {
    // Gain: '<S1>/Gain'
    rtb_TLNm = -rtb_TLNm;

    // Switch: '<S5>/Switch' incorporates:
    //   RelationalOperator: '<S5>/UpperRelop'

    if (!(rtb_DigitalClock < rtb_TLNm)) {
      rtb_TLNm = rtb_DigitalClock;
    }

    // End of Switch: '<S5>/Switch'
  }

  // End of Switch: '<S5>/Switch2'

  // MinMax: '<S4>/Min'
  rtb_TLNm = std::fmin(rtb_MMotorR2Demand, rtb_TLNm);

  // Saturate: '<S4>/Saturation'
  if (rtb_TLNm > 60.0) {
    rtb_TLNm = 60.0;
  } else if (rtb_TLNm < 0.0) {
    rtb_TLNm = 0.0;
  }

  // Outport: '<Root>/MMotorL2Demand' incorporates:
  //   Gain: '<Root>/Gain'
  //   Saturate: '<S4>/Saturation'

  rtY.MMotorL2Demand = 0.019596050742573669 * rtb_TLNm;

  // Switch: '<S8>/Switch' incorporates:
  //   Constant: '<S8>/Constant2'
  //   Memory: '<S8>/Memory'

  if (rtb_Switch_a != 0.0) {
    rtb_Switch_a = rtDW.Memory_PreviousInput_m;
  } else {
    rtb_Switch_a = 1.0;
  }

  // End of Switch: '<S8>/Switch'

  // Switch: '<S8>/Switch1' incorporates:
  //   Abs: '<S3>/Abs1'
  //   Constant: '<S3>/Constant'
  //   Gain: '<S3>/Gr2'
  //   Gain: '<S3>/rwheel2'
  //   Gain: '<S8>/Gain'
  //   Gain: '<S8>/Gain1'
  //   Inport: '<Root>/<vx>'
  //   Inport: '<Root>/wR'
  //   Product: '<S3>/Divide1'
  //   Sum: '<S3>/Subtract1'

  if (std::abs(1.0 - 0.2 * rtU.wR * 0.2603 / rtU.vx) >= 0.12) {
    rtb_Switch_a *= 0.999;
  } else {
    rtb_Switch_a *= 1.001;
  }

  // End of Switch: '<S8>/Switch1'

  // Switch: '<S10>/Switch2' incorporates:
  //   Constant: '<S8>/Constant1'
  //   Constant: '<S8>/Constant2'
  //   RelationalOperator: '<S10>/LowerRelop1'
  //   RelationalOperator: '<S10>/UpperRelop'
  //   Switch: '<S10>/Switch'

  if (rtb_Switch_a > 1.0) {
    // Switch: '<S10>/Switch2'
    rtDW.Switch2_d = 1.0;
  } else if (rtb_Switch_a < 0.0) {
    // Switch: '<S10>/Switch' incorporates:
    //   Constant: '<S8>/Constant1'
    //   Switch: '<S10>/Switch2'

    rtDW.Switch2_d = 0.0;
  } else {
    // Switch: '<S10>/Switch2' incorporates:
    //   Switch: '<S10>/Switch'

    rtDW.Switch2_d = rtb_Switch_a;
  }

  // End of Switch: '<S10>/Switch2'

  // Product: '<S1>/Product1'
  rtb_Switch_a = rtDW.Switch2_d * rtb_TRNm;

  // Switch: '<S6>/Switch2' incorporates:
  //   Gain: '<S1>/Gain1'
  //   RelationalOperator: '<S6>/LowerRelop1'
  //   RelationalOperator: '<S6>/UpperRelop'
  //   Switch: '<S6>/Switch'

  if (rtb_Switch_a > rtb_TRNm) {
    rtb_TLNm = rtb_TRNm;
  } else if (rtb_Switch_a < -rtb_TRNm) {
    // Switch: '<S6>/Switch' incorporates:
    //   Gain: '<S1>/Gain1'

    rtb_TLNm = -rtb_TRNm;
  } else {
    rtb_TLNm = rtb_Switch_a;
  }

  // End of Switch: '<S6>/Switch2'

  // MinMax: '<S4>/Min1'
  rtb_TLNm = std::fmin(rtb_MMotorR2Demand, rtb_TLNm);

  // Saturate: '<S4>/Saturation1'
  if (rtb_TLNm > 60.0) {
    rtb_TLNm = 60.0;
  } else if (rtb_TLNm < 0.0) {
    rtb_TLNm = 0.0;
  }

  // Outport: '<Root>/MMotorR2Demand' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Saturate: '<S4>/Saturation1'

  rtY.MMotorR2Demand = 0.019596050742573669 * rtb_TLNm;

  // Update for Memory: '<S7>/Memory'
  rtDW.Memory_PreviousInput = rtDW.Switch2;

  // Update for Memory: '<S8>/Memory'
  rtDW.Memory_PreviousInput_m = rtDW.Switch2_d;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&rtM)->Timing.t[0] =
    ((time_T)(++(&rtM)->Timing.clockTick0)) * (&rtM)->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.001s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.001, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&rtM)->Timing.clockTick1++;
  }
}

// Model initialize function
void Slip_Control_CodeGen::initialize()
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&rtM)->solverInfo, &(&rtM)->Timing.simTimeStep);
    rtsiSetTPtr(&(&rtM)->solverInfo, (&rtM)->getTPtrPtr());
    rtsiSetStepSizePtr(&(&rtM)->solverInfo, &(&rtM)->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&rtM)->solverInfo, (&rtM)->getErrorStatusPtr());
    rtsiSetRTModelPtr(&(&rtM)->solverInfo, (&rtM));
  }

  rtsiSetSimTimeStep(&(&rtM)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&(&rtM)->solverInfo, false);
  rtsiSetIsContModeFrozen(&(&rtM)->solverInfo, false);
  rtsiSetSolverName(&(&rtM)->solverInfo,"FixedStepDiscrete");
  (&rtM)->setTPtr(&(&rtM)->Timing.tArray[0]);
  (&rtM)->Timing.stepSize0 = 0.001;
}

time_T** Slip_Control_CodeGen::RT_MODEL::getTPtrPtr()
{
  return &(Timing.t);
}

boolean_T Slip_Control_CodeGen::RT_MODEL::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

time_T* Slip_Control_CodeGen::RT_MODEL::getTPtr() const
{
  return (Timing.t);
}

void Slip_Control_CodeGen::RT_MODEL::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T Slip_Control_CodeGen::RT_MODEL::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

const char_T** Slip_Control_CodeGen::RT_MODEL::getErrorStatusPtr()
{
  return &errorStatus;
}

const char_T* Slip_Control_CodeGen::RT_MODEL::getErrorStatus() const
{
  return (errorStatus);
}

void Slip_Control_CodeGen::RT_MODEL::setErrorStatus(const char_T* const
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
Slip_Control_CodeGen::Slip_Control_CodeGen() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Slip_Control_CodeGen::~Slip_Control_CodeGen() = default;

// Real-Time Model get method
Slip_Control_CodeGen::RT_MODEL * Slip_Control_CodeGen::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
