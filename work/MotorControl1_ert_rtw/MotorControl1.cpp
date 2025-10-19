//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MotorControl1.cpp
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
#include "MotorControl1.h"
#include "rtwtypes.h"
#include <cmath>

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
    bpIdx = static_cast<uint32_T>(maxIndex >> 1UL);
    iLeft = 0UL;
    iRght = maxIndex;
    while (static_cast<uint32_T>(iRght - iLeft) > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = static_cast<uint32_T>(static_cast<uint32_T>(iRght + iLeft) >> 1UL);
    }

    frac = (u0 - bp0[iLeft]) / (bp0[static_cast<uint32_T>(iLeft + 1UL)] -
      bp0[iLeft]);
  } else {
    iLeft = static_cast<uint32_T>(maxIndex - 1UL);
    frac = (u0 - bp0[static_cast<uint32_T>(maxIndex - 1UL)]) / (bp0[maxIndex] -
      bp0[static_cast<uint32_T>(maxIndex - 1UL)]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'wrapping'

  yL_0d0 = table[iLeft];
  return (table[static_cast<uint32_T>(iLeft + 1UL)] - yL_0d0) * frac + yL_0d0;
}

// Function for MATLAB Function: '<S14>/Evaluate Rule Antecedents'
real_T MotorControl1::trimf(real_T x, const real_T params[3])
{
  real_T y;
  y = 0.0;
  if ((params[0] != params[1]) && (params[0] < x) && (x < params[1])) {
    y = 1.0 / (params[1] - params[0]) * (x - params[0]);
  }

  if ((params[1] != params[2]) && (params[1] < x) && (x < params[2])) {
    y = 1.0 / (params[2] - params[1]) * (params[2] - x);
  }

  if (x == params[1]) {
    y = 1.0;
  }

  return y;
}

// Function for MATLAB Function: '<S14>/Evaluate Rule Consequents'
void MotorControl1::trimf_l(const real_T x[200], const real_T params[3], real_T
  y[200])
{
  real_T a;
  real_T b;
  real_T c;
  a = params[0];
  b = params[1];
  c = params[2];
  for (int16_T i{0}; i < 200; i++) {
    real_T x_0;
    y[i] = 0.0;
    if (a != b) {
      x_0 = x[i];
      if ((a < x_0) && (x_0 < b)) {
        y[i] = 1.0 / (b - a) * (x_0 - a);
      }
    }

    if (b != c) {
      x_0 = x[i];
      if ((b < x_0) && (x_0 < c)) {
        y[i] = 1.0 / (c - b) * (c - x_0);
      }
    }

    if (x[i] == b) {
      y[i] = 1.0;
    }
  }
}

// Model step function
void MotorControl1::step()
{
  real_T rtb_aggregatedOutputs[200];
  real_T tmp[200];
  real_T tmp_0[200];
  real_T tmp_1[200];
  real_T tmp_2[200];
  real_T tmp_3[200];
  real_T tmp_4[200];
  real_T tmp_5[200];
  real_T rtb_antecedentOutputs[49];
  real_T inputMFCache[14];
  real_T rtb_Abs;
  real_T rtb_DigitalClock;
  real_T rtb_Gain1_k;
  real_T rtb_Gain_n;
  real_T rtb_Switch_ia;
  real_T rtb_Switch_j_tmp;
  real_T rtb_Switch_j_tmp_0;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_YawDesired;
  int16_T i;
  int16_T ruleID;
  static const real_T i_0[3]{ -1.27777777777778, -1.0, -0.722222222222222 };

  static const real_T h[3]{ -0.944444444444444, -0.666666666666667,
    -0.388888888888889 };

  static const real_T g[3]{ -0.611111111111111, -0.333333333333333,
    -0.0555555555555557 };

  static const real_T f[3]{ -0.277777777777778, -1.11022302462516E-16,
    0.277777777777778 };

  static const real_T e[3]{ 0.0555555555555555, 0.333333333333333,
    0.611111111111111 };

  static const real_T d[3]{ 0.388888888888889, 0.666666666666667,
    0.944444444444444 };

  static const real_T c[3]{ 0.722222222222222, 1.0, 1.27777777777778 };

  static const int8_T b[98]{ 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3,
    3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7,
    7, 7, 7, 7, 7, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6,
    7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4,
    5, 6, 7 };

  static const int8_T b_0[49]{ 1, 1, 1, 1, 2, 3, 4, 1, 1, 1, 2, 3, 4, 5, 1, 1, 2,
    3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6, 7, 7, 3, 4, 5, 6, 7, 7, 7, 4,
    5, 6, 7, 7, 7, 7 };

  // DigitalClock: '<S10>/Digital Clock' incorporates:
  //   DigitalClock: '<S11>/Digital Clock'

  rtb_Switch_ia = (((&rtM)->Timing.clockTick1) * 0.001);

  // Switch: '<S10>/Switch' incorporates:
  //   Constant: '<S10>/Constant2'
  //   DigitalClock: '<S10>/Digital Clock'
  //   Memory: '<S10>/Memory'

  if (rtb_Switch_ia != 0.0) {
    rtb_DigitalClock = rtDW.Memory_PreviousInput;
  } else {
    rtb_DigitalClock = 1.0;
  }

  // End of Switch: '<S10>/Switch'

  // Switch: '<S10>/Switch1' incorporates:
  //   Abs: '<S5>/Abs'
  //   Constant: '<S5>/Constant'
  //   Gain: '<S10>/Gain'
  //   Gain: '<S10>/Gain1'
  //   Gain: '<S5>/rwheel'
  //   Inport: '<Root>/<vx>'
  //   Inport: '<Root>/wL'
  //   Product: '<S5>/Divide'
  //   Sum: '<S5>/Subtract'

  if (std::abs(1.0 - 0.051000000000000004 * rtU.w / rtU.vx) >= 0.11) {
    rtb_DigitalClock *= 0.999;
  } else {
    rtb_DigitalClock *= 1.001;
  }

  // End of Switch: '<S10>/Switch1'

  // Switch: '<S12>/Switch2' incorporates:
  //   Constant: '<S10>/Constant1'
  //   Constant: '<S10>/Constant2'
  //   RelationalOperator: '<S12>/LowerRelop1'
  //   RelationalOperator: '<S12>/UpperRelop'
  //   Switch: '<S12>/Switch'

  if (rtb_DigitalClock > 1.0) {
    // Switch: '<S12>/Switch2'
    rtDW.Switch2 = 1.0;
  } else if (rtb_DigitalClock < 0.0) {
    // Switch: '<S12>/Switch' incorporates:
    //   Constant: '<S10>/Constant1'
    //   Switch: '<S12>/Switch2'

    rtDW.Switch2 = 0.0;
  } else {
    // Switch: '<S12>/Switch2' incorporates:
    //   Switch: '<S12>/Switch'

    rtDW.Switch2 = rtb_DigitalClock;
  }

  // End of Switch: '<S12>/Switch2'

  // Lookup_n-D: '<S2>/1-D Lookup Table' incorporates:
  //   Gain: '<S2>/rad//s to rpm1'
  //   Inport: '<Root>/wL'
  //   Lookup_n-D: '<S4>/1-D Lookup Table'

  rtb_Abs = look1_binlx(9.5492965855137211 * rtU.w, rtConstP.pooled10,
                        rtConstP.pooled9, 70UL);

  // Product: '<S2>/Product' incorporates:
  //   Lookup_n-D: '<S2>/1-D Lookup Table'

  rtb_DigitalClock = rtDW.Switch2 * rtb_Abs;

  // Switch: '<S8>/Switch2' incorporates:
  //   Gain: '<S2>/Gain'
  //   Lookup_n-D: '<S2>/1-D Lookup Table'
  //   RelationalOperator: '<S8>/LowerRelop1'
  //   RelationalOperator: '<S8>/UpperRelop'
  //   Switch: '<S8>/Switch'

  if (rtb_DigitalClock > rtb_Abs) {
    rtb_DigitalClock = rtb_Abs;
  } else if (rtb_DigitalClock < -rtb_Abs) {
    // Switch: '<S8>/Switch' incorporates:
    //   Gain: '<S2>/Gain'

    rtb_DigitalClock = -rtb_Abs;
  }

  // End of Switch: '<S8>/Switch2'

  // Lookup_n-D: '<S4>/1-D Lookup Table1' incorporates:
  //   Gain: '<S4>/rad//s to rpm'
  //   Inport: '<Root>/wR'
  //   Lookup_n-D: '<S2>/1-D Lookup Table1'

  rtb_Gain1_k = look1_binlx(9.5492965855137211 * rtU.w_g, rtConstP.pooled10,
    rtConstP.pooled9, 70UL);

  // Gain: '<S6>/Gain1' incorporates:
  //   Inport: '<Root>/Throttle[~]1'
  //   Lookup_n-D: '<S4>/1-D Lookup Table1'
  //   Product: '<S4>/Product'
  //   Sum: '<S4>/Sum of Elements'

  rtb_Gain_n = (rtb_Abs + rtb_Gain1_k) * rtU.Throttle * 0.5;

  // Switch: '<S11>/Switch' incorporates:
  //   Constant: '<S11>/Constant2'
  //   Memory: '<S11>/Memory'

  if (rtb_Switch_ia != 0.0) {
    rtb_Switch_ia = rtDW.Memory_PreviousInput_e;
  } else {
    rtb_Switch_ia = 1.0;
  }

  // End of Switch: '<S11>/Switch'

  // Switch: '<S11>/Switch1' incorporates:
  //   Abs: '<S5>/Abs1'
  //   Constant: '<S5>/Constant'
  //   Gain: '<S11>/Gain'
  //   Gain: '<S11>/Gain1'
  //   Gain: '<S5>/rwheel'
  //   Inport: '<Root>/<vx>'
  //   Inport: '<Root>/wR'
  //   Product: '<S5>/Divide1'
  //   Sum: '<S5>/Subtract1'

  if (std::abs(1.0 - 0.051000000000000004 * rtU.w_g / rtU.vx) >= 0.11) {
    rtb_Switch_ia *= 0.999;
  } else {
    rtb_Switch_ia *= 1.001;
  }

  // End of Switch: '<S11>/Switch1'

  // Switch: '<S13>/Switch2' incorporates:
  //   Constant: '<S11>/Constant1'
  //   Constant: '<S11>/Constant2'
  //   RelationalOperator: '<S13>/LowerRelop1'
  //   RelationalOperator: '<S13>/UpperRelop'
  //   Switch: '<S13>/Switch'

  if (rtb_Switch_ia > 1.0) {
    // Switch: '<S13>/Switch2'
    rtDW.Switch2_f = 1.0;
  } else if (rtb_Switch_ia < 0.0) {
    // Switch: '<S13>/Switch' incorporates:
    //   Constant: '<S11>/Constant1'
    //   Switch: '<S13>/Switch2'

    rtDW.Switch2_f = 0.0;
  } else {
    // Switch: '<S13>/Switch2' incorporates:
    //   Switch: '<S13>/Switch'

    rtDW.Switch2_f = rtb_Switch_ia;
  }

  // End of Switch: '<S13>/Switch2'

  // Product: '<S2>/Product1'
  rtb_Switch_ia = rtDW.Switch2_f * rtb_Gain1_k;

  // Switch: '<S9>/Switch2' incorporates:
  //   RelationalOperator: '<S9>/LowerRelop1'

  if (!(rtb_Switch_ia > rtb_Gain1_k)) {
    // Gain: '<S2>/Gain1'
    rtb_Gain1_k = -rtb_Gain1_k;

    // Switch: '<S9>/Switch' incorporates:
    //   RelationalOperator: '<S9>/UpperRelop'

    if (!(rtb_Switch_ia < rtb_Gain1_k)) {
      rtb_Gain1_k = rtb_Switch_ia;
    }

    // End of Switch: '<S9>/Switch'
  }

  // End of Switch: '<S9>/Switch2'

  // Sum: '<S18>/Add1' incorporates:
  //   Sum: '<S18>/Add3'
  //   Switch: '<S19>/Switch2'

  rtb_Switch_j_tmp = rtb_Gain_n - rtb_DigitalClock;

  // Sum: '<S18>/Add' incorporates:
  //   Sum: '<S18>/Add2'
  //   Switch: '<S19>/Switch2'

  rtb_Switch_j_tmp_0 = rtb_Gain1_k - rtb_Gain_n;

  // Gain: '<S18>/Gain2' incorporates:
  //   MinMax: '<S18>/Min'
  //   Sum: '<S18>/Add'
  //   Sum: '<S18>/Add1'

  rtb_Switch_ia = std::fmax(rtb_Switch_j_tmp, rtb_Switch_j_tmp_0) * 2.0;

  // Abs: '<S7>/Abs' incorporates:
  //   Gain: '<Root>/Gain2'
  //   Inport: '<Root>/<gy>'
  //   Inport: '<Root>/<vx>'
  //   Product: '<S7>/Divide'
  //   UnitConversion: '<S20>/Unit Conversion'

  // Unit Conversion - from: rad/s to: deg/s
  // Expression: output = (57.2958*input) + (0)
  rtb_Abs = std::abs(rtU.vx / (9.80665 * rtU.gy) * 57.295779513082323);

  // Product: '<S7>/Divide1' incorporates:
  //   Bias: '<S1>/Bias'
  //   Constant: '<S7>/Constant'
  //   Gain: '<S1>/Gain2'
  //   Gain: '<S1>/Gain3'
  //   Gain: '<S7>/Gain'
  //   Gain: '<S7>/StrWheelRatio'
  //   Inport: '<Root>/<vx>'
  //   Inport: '<Root>/aSteerWheel'
  //   Math: '<S7>/Power'
  //   Sum: '<S7>/Add'

  rtb_YawDesired = (rtU.aSteerWheel - 512.0) * 0.0019569471624266144 * 154.0 *
    0.165 * rtU.vx * (rtU.vx * rtU.vx * 0.00044632575662956376 + 1.575);

  // Switch: '<S21>/Switch2' incorporates:
  //   RelationalOperator: '<S21>/LowerRelop1'

  if (!(rtb_YawDesired > rtb_Abs)) {
    // Gain: '<S7>/Gain1'
    rtb_Abs = -rtb_Abs;

    // Switch: '<S21>/Switch' incorporates:
    //   RelationalOperator: '<S21>/UpperRelop'

    if (!(rtb_YawDesired < rtb_Abs)) {
      rtb_Abs = rtb_YawDesired;
    }

    // End of Switch: '<S21>/Switch'
  }

  // End of Switch: '<S21>/Switch2'

  // Sum: '<S3>/Sum' incorporates:
  //   Inport: '<Root>/<nYaw>'

  rtDW.Sum = rtb_Abs - rtU.nYaw;

  // Saturate: '<S3>/Saturation2'
  if (rtDW.Sum > 1.0) {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtb_TmpSignalConversionAtSFun_0 = 1.0;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  } else if (rtDW.Sum < -1.0) {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtb_TmpSignalConversionAtSFun_0 = -1.0;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  } else {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtb_TmpSignalConversionAtSFun_0 = rtDW.Sum;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  }

  // End of Saturate: '<S3>/Saturation2'

  // Sum: '<S3>/Sum1' incorporates:
  //   Delay: '<S3>/Delay'

  rtb_YawDesired = rtDW.Sum - rtDW.Delay_DSTATE;

  // Saturate: '<S3>/Saturation1'
  if (rtb_YawDesired > 1.0) {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtb_YawDesired = 1.0;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  } else if (rtb_YawDesired < -1.0) {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtb_YawDesired = -1.0;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  }

  // End of Saturate: '<S3>/Saturation1'

  // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
  // MATLAB Function: '<S14>/Evaluate Rule Antecedents'
  rtb_Abs = 0.0;
  inputMFCache[0] = trimf(rtb_TmpSignalConversionAtSFun_0, i_0);
  inputMFCache[1] = trimf(rtb_TmpSignalConversionAtSFun_0, h);
  inputMFCache[2] = trimf(rtb_TmpSignalConversionAtSFun_0, g);
  inputMFCache[3] = trimf(rtb_TmpSignalConversionAtSFun_0, f);
  inputMFCache[4] = trimf(rtb_TmpSignalConversionAtSFun_0, e);
  inputMFCache[5] = trimf(rtb_TmpSignalConversionAtSFun_0, d);
  inputMFCache[6] = trimf(rtb_TmpSignalConversionAtSFun_0, c);
  inputMFCache[7] = trimf(rtb_YawDesired, i_0);
  inputMFCache[8] = trimf(rtb_YawDesired, h);
  inputMFCache[9] = trimf(rtb_YawDesired, g);
  inputMFCache[10] = trimf(rtb_YawDesired, f);
  inputMFCache[11] = trimf(rtb_YawDesired, e);
  inputMFCache[12] = trimf(rtb_YawDesired, d);
  inputMFCache[13] = trimf(rtb_YawDesired, c);
  for (ruleID = 0; ruleID < 49; ruleID++) {
    rtb_YawDesired = inputMFCache[static_cast<int16_T>(static_cast<int16_T>
      (b[ruleID]) - 1)];
    if (rtb_YawDesired < 1.0) {
      rtb_TmpSignalConversionAtSFun_0 = rtb_YawDesired;
    } else {
      rtb_TmpSignalConversionAtSFun_0 = 1.0;
    }

    rtb_YawDesired = inputMFCache[static_cast<int16_T>(static_cast<int16_T>(b[
      static_cast<int16_T>(ruleID + 49)]) + 6)];
    if (rtb_TmpSignalConversionAtSFun_0 > rtb_YawDesired) {
      rtb_TmpSignalConversionAtSFun_0 = rtb_YawDesired;
    }

    rtb_antecedentOutputs[ruleID] = rtb_TmpSignalConversionAtSFun_0;
    rtb_Abs += rtb_TmpSignalConversionAtSFun_0;
  }

  // MATLAB Function: '<S14>/Evaluate Rule Consequents' incorporates:
  //   Constant: '<S14>/Output Sample Points'

  trimf_l(rtConstP.OutputSamplePoints_Value, i_0, tmp);
  trimf_l(rtConstP.OutputSamplePoints_Value, h, tmp_0);
  trimf_l(rtConstP.OutputSamplePoints_Value, g, tmp_1);
  trimf_l(rtConstP.OutputSamplePoints_Value, f, tmp_2);
  trimf_l(rtConstP.OutputSamplePoints_Value, e, tmp_3);
  trimf_l(rtConstP.OutputSamplePoints_Value, d, tmp_4);
  trimf_l(rtConstP.OutputSamplePoints_Value, c, tmp_5);
  for (ruleID = 0; ruleID < 200; ruleID++) {
    rtb_aggregatedOutputs[ruleID] = 0.0;
    rtDW.outputMFCache[static_cast<int16_T>(7 * ruleID)] = tmp[ruleID];
    rtDW.outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) + 1)]
      = tmp_0[ruleID];
    rtDW.outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) + 2)]
      = tmp_1[ruleID];
    rtDW.outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) + 3)]
      = tmp_2[ruleID];
    rtDW.outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) + 4)]
      = tmp_3[ruleID];
    rtDW.outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) + 5)]
      = tmp_4[ruleID];
    rtDW.outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) + 6)]
      = tmp_5[ruleID];
  }

  for (ruleID = 0; ruleID < 49; ruleID++) {
    for (i = 0; i < 200; i++) {
      rtb_TmpSignalConversionAtSFun_0 = rtDW.outputMFCache[static_cast<int16_T>(
        static_cast<int16_T>(static_cast<int16_T>(7 * i) + static_cast<int16_T>
        (b_0[ruleID])) - 1)];
      rtb_YawDesired = rtb_antecedentOutputs[ruleID];
      if ((!(rtb_TmpSignalConversionAtSFun_0 > rtb_YawDesired)) && (!std::isnan
           (rtb_TmpSignalConversionAtSFun_0))) {
        rtb_YawDesired = rtb_TmpSignalConversionAtSFun_0;
      }

      if (rtb_aggregatedOutputs[i] < rtb_YawDesired) {
        rtb_aggregatedOutputs[i] = rtb_YawDesired;
      }
    }
  }

  // End of MATLAB Function: '<S14>/Evaluate Rule Consequents'

  // MATLAB Function: '<S14>/Defuzzify Outputs' incorporates:
  //   Constant: '<S14>/Output Sample Points'
  //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

  if (rtb_Abs == 0.0) {
    rtb_Abs = 0.0;
  } else {
    rtb_Abs = 0.0;
    rtb_YawDesired = 0.0;
    for (ruleID = 0; ruleID < 200; ruleID++) {
      rtb_YawDesired += rtb_aggregatedOutputs[ruleID];
    }

    if (!(rtb_YawDesired == 0.0)) {
      for (ruleID = 0; ruleID < 200; ruleID++) {
        rtb_Abs += rtConstP.OutputSamplePoints_Value[ruleID] *
          rtb_aggregatedOutputs[ruleID];
      }

      rtb_Abs *= 1.0 / rtb_YawDesired;
    }
  }

  // End of MATLAB Function: '<S14>/Defuzzify Outputs'
  // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'

  // Gain: '<S18>/Gain' incorporates:
  //   Gain: '<S3>/Gain'
  //   Gain: '<S3>/RearTrack'
  //   Gain: '<S3>/rwheel'

  rtb_Abs = 40.0 * rtb_Abs * 0.725 * 0.255 * 0.8793103448275863;

  // Switch: '<S19>/Switch2' incorporates:
  //   RelationalOperator: '<S19>/LowerRelop1'

  if (!(rtb_Abs > rtb_Switch_ia)) {
    // Gain: '<S18>/Gain3' incorporates:
    //   MinMax: '<S18>/Min1'

    rtb_Switch_ia = std::fmin(rtb_Switch_j_tmp, rtb_Switch_j_tmp_0) * 2.0;

    // Switch: '<S19>/Switch' incorporates:
    //   RelationalOperator: '<S19>/UpperRelop'

    if (!(rtb_Abs < rtb_Switch_ia)) {
      rtb_Switch_ia = rtb_Abs;
    }

    // End of Switch: '<S19>/Switch'
  }

  // Gain: '<S6>/Gain'
  rtb_Switch_ia *= 0.5;

  // Sum: '<S6>/Add' incorporates:
  //   MinMax: '<S6>/Min'

  rtb_DigitalClock = std::fmin(rtb_Gain_n, rtb_DigitalClock) + rtb_Switch_ia;

  // Saturate: '<S6>/Saturation'
  if (rtb_DigitalClock > 60.0) {
    rtb_DigitalClock = 60.0;
  } else if (rtb_DigitalClock < 0.0) {
    rtb_DigitalClock = 0.0;
  }

  // Outport: '<Root>/MMotorL2Demand' incorporates:
  //   Gain: '<Root>/Gain'
  //   Saturate: '<S6>/Saturation'

  rtY.MMotorL2Demand = 0.016666666666666666 * rtb_DigitalClock;

  // Sum: '<S6>/Add1' incorporates:
  //   MinMax: '<S6>/Min1'

  rtb_DigitalClock = std::fmin(rtb_Gain_n, rtb_Gain1_k) - rtb_Switch_ia;

  // Saturate: '<S6>/Saturation1'
  if (rtb_DigitalClock > 60.0) {
    rtb_DigitalClock = 60.0;
  } else if (rtb_DigitalClock < 0.0) {
    rtb_DigitalClock = 0.0;
  }

  // Outport: '<Root>/MMotorR2Demand' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Saturate: '<S6>/Saturation1'

  rtY.MMotorR2Demand = 0.016666666666666666 * rtb_DigitalClock;

  // Update for Memory: '<S10>/Memory'
  rtDW.Memory_PreviousInput = rtDW.Switch2;

  // Update for Memory: '<S11>/Memory'
  rtDW.Memory_PreviousInput_e = rtDW.Switch2_f;

  // Update for Delay: '<S3>/Delay'
  rtDW.Delay_DSTATE = rtDW.Sum;

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
void MotorControl1::initialize()
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

time_T** MotorControl1::RT_MODEL::getTPtrPtr()
{
  return &(Timing.t);
}

boolean_T MotorControl1::RT_MODEL::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

time_T* MotorControl1::RT_MODEL::getTPtr() const
{
  return (Timing.t);
}

void MotorControl1::RT_MODEL::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T MotorControl1::RT_MODEL::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

const char_T** MotorControl1::RT_MODEL::getErrorStatusPtr()
{
  return &errorStatus;
}

const char_T* MotorControl1::RT_MODEL::getErrorStatus() const
{
  return (errorStatus);
}

void MotorControl1::RT_MODEL::setErrorStatus(const char_T* const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
MotorControl1::MotorControl1() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
MotorControl1::~MotorControl1() = default;

// Real-Time Model get method
MotorControl1::RT_MODEL * MotorControl1::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
