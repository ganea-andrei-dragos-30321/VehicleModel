//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TV_FLC0.cpp
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
#include "TV_FLC0.h"
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

// Function for MATLAB Function: '<S17>/Evaluate Rule Antecedents'
real_T TV_FLC0::trimf(real_T x, const real_T params[3])
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

// Function for MATLAB Function: '<S17>/Evaluate Rule Consequents'
void TV_FLC0::trimf_h(const real_T x[200], const real_T params[3], real_T y[200])
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
void TV_FLC0::step()
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
  real_T rtb_Switch1;
  real_T rtb_Switch1_tmp;
  real_T rtb_Switch1_tmp_0;
  real_T rtb_T;
  real_T rtb_TLNm;
  real_T rtb_TRNm;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_YawDesired;
  real_T rtb_YawMax;
  int16_T inputID;
  int16_T ruleID;
  static const real_T i[3]{ -1.27777777777778, -1.0, -0.722222222222222 };

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

  // Lookup_n-D: '<S4>/1-D Lookup Table' incorporates:
  //   Gain: '<S4>/rad//s to rpm1'
  //   Inport: '<Root>/wL'

  rtb_TLNm = look1_binlx(9.5492965855137211 * rtU.wL, rtConstP.pooled6,
    rtConstP.pooled5, 46UL);

  // Lookup_n-D: '<S4>/1-D Lookup Table1' incorporates:
  //   Gain: '<S4>/rad//s to rpm'
  //   Inport: '<Root>/wR'

  rtb_TRNm = look1_binlx(9.5492965855137211 * rtU.wR, rtConstP.pooled6,
    rtConstP.pooled5, 46UL);

  // Gain: '<S3>/Gain1' incorporates:
  //   Inport: '<Root>/Throttle[~]'
  //   Product: '<S4>/Product2'
  //   Sum: '<S4>/Sum'

  rtb_T = (rtb_TLNm + rtb_TRNm) * rtU.Throttle * 0.5;

  // Switch: '<S13>/Switch1' incorporates:
  //   Abs: '<S2>/Abs'
  //   Constant: '<S2>/Constant'
  //   Gain: '<S13>/Gain'
  //   Gain: '<S13>/Gain1'
  //   Gain: '<S2>/GearRatio'
  //   Gain: '<S2>/rwheel'
  //   Inport: '<Root>/<vx>'
  //   Inport: '<Root>/wL'
  //   Memory: '<S13>/Memory'
  //   Product: '<S2>/Divide'
  //   Sum: '<S2>/Subtract'

  if (std::abs(1.0 - 0.2 * rtU.wL * 0.255 / rtU.vx) >= 0.1) {
    rtb_Switch1 = 0.999 * rtDW.Memory_PreviousInput;
  } else {
    rtb_Switch1 = 1.001 * rtDW.Memory_PreviousInput;
  }

  // End of Switch: '<S13>/Switch1'

  // Switch: '<S15>/Switch2' incorporates:
  //   Constant: '<S13>/Constant1'
  //   Constant: '<S13>/Constant2'
  //   RelationalOperator: '<S15>/LowerRelop1'
  //   RelationalOperator: '<S15>/UpperRelop'
  //   Switch: '<S15>/Switch'

  if (rtb_Switch1 > 1.0) {
    // Switch: '<S15>/Switch2'
    rtDW.Switch2 = 1.0;
  } else if (rtb_Switch1 < 0.0) {
    // Switch: '<S15>/Switch' incorporates:
    //   Constant: '<S13>/Constant1'
    //   Switch: '<S15>/Switch2'

    rtDW.Switch2 = 0.0;
  } else {
    // Switch: '<S15>/Switch2' incorporates:
    //   Switch: '<S15>/Switch'

    rtDW.Switch2 = rtb_Switch1;
  }

  // End of Switch: '<S15>/Switch2'

  // Product: '<S4>/Product'
  rtb_Switch1 = rtDW.Switch2 * rtb_TLNm;

  // Switch: '<S11>/Switch2' incorporates:
  //   RelationalOperator: '<S11>/LowerRelop1'

  if (!(rtb_Switch1 > rtb_TLNm)) {
    // Gain: '<S4>/Gain'
    rtb_TLNm = -rtb_TLNm;

    // Switch: '<S11>/Switch' incorporates:
    //   RelationalOperator: '<S11>/UpperRelop'

    if (!(rtb_Switch1 < rtb_TLNm)) {
      rtb_TLNm = rtb_Switch1;
    }

    // End of Switch: '<S11>/Switch'
  }

  // End of Switch: '<S11>/Switch2'

  // Switch: '<S14>/Switch1' incorporates:
  //   Abs: '<S2>/Abs1'
  //   Constant: '<S2>/Constant'
  //   Gain: '<S14>/Gain'
  //   Gain: '<S14>/Gain1'
  //   Gain: '<S2>/GearRatio1'
  //   Gain: '<S2>/rwheel1'
  //   Inport: '<Root>/<vx>'
  //   Inport: '<Root>/wR'
  //   Memory: '<S14>/Memory'
  //   Product: '<S2>/Divide1'
  //   Sum: '<S2>/Subtract1'

  if (std::abs(1.0 - 0.2 * rtU.wR * 0.255 / rtU.vx) >= 0.1) {
    rtb_Switch1 = 0.999 * rtDW.Memory_PreviousInput_m;
  } else {
    rtb_Switch1 = 1.001 * rtDW.Memory_PreviousInput_m;
  }

  // End of Switch: '<S14>/Switch1'

  // Switch: '<S16>/Switch2' incorporates:
  //   Constant: '<S14>/Constant1'
  //   Constant: '<S14>/Constant2'
  //   RelationalOperator: '<S16>/LowerRelop1'
  //   RelationalOperator: '<S16>/UpperRelop'
  //   Switch: '<S16>/Switch'

  if (rtb_Switch1 > 1.0) {
    // Switch: '<S16>/Switch2'
    rtDW.Switch2_h = 1.0;
  } else if (rtb_Switch1 < 0.0) {
    // Switch: '<S16>/Switch' incorporates:
    //   Constant: '<S14>/Constant1'
    //   Switch: '<S16>/Switch2'

    rtDW.Switch2_h = 0.0;
  } else {
    // Switch: '<S16>/Switch2' incorporates:
    //   Switch: '<S16>/Switch'

    rtDW.Switch2_h = rtb_Switch1;
  }

  // End of Switch: '<S16>/Switch2'

  // Product: '<S4>/Product1'
  rtb_Switch1 = rtDW.Switch2_h * rtb_TRNm;

  // Switch: '<S12>/Switch2' incorporates:
  //   RelationalOperator: '<S12>/LowerRelop1'

  if (!(rtb_Switch1 > rtb_TRNm)) {
    // Gain: '<S4>/Gain1'
    rtb_TRNm = -rtb_TRNm;

    // Switch: '<S12>/Switch' incorporates:
    //   RelationalOperator: '<S12>/UpperRelop'

    if (!(rtb_Switch1 < rtb_TRNm)) {
      rtb_TRNm = rtb_Switch1;
    }

    // End of Switch: '<S12>/Switch'
  }

  // End of Switch: '<S12>/Switch2'

  // Sum: '<S7>/Add1' incorporates:
  //   Sum: '<S7>/Add3'
  //   Switch: '<S10>/Switch2'

  rtb_Switch1_tmp = rtb_T - rtb_TLNm;

  // Sum: '<S7>/Add' incorporates:
  //   Sum: '<S7>/Add2'
  //   Switch: '<S10>/Switch2'

  rtb_Switch1_tmp_0 = rtb_TRNm - rtb_T;

  // Gain: '<S7>/Gain2' incorporates:
  //   MinMax: '<S7>/Min'
  //   Sum: '<S7>/Add'
  //   Sum: '<S7>/Add1'

  rtb_Switch1 = std::fmax(rtb_Switch1_tmp, rtb_Switch1_tmp_0) * 2.0;

  // Abs: '<S6>/Abs' incorporates:
  //   Gain: '<Root>/Gain2'
  //   Inport: '<Root>/<gy>'
  //   Inport: '<Root>/<vx>'
  //   Product: '<S6>/Divide'

  rtb_YawMax = std::abs(1.0 / rtU.vx * (9.80665 * rtU.gy));

  // Product: '<S6>/Divide1' incorporates:
  //   Bias: '<S1>/Bias'
  //   Constant: '<S6>/Constant'
  //   Gain: '<S1>/Gain2'
  //   Gain: '<S1>/Gain3'
  //   Gain: '<S21>/Gain1'
  //   Gain: '<S6>/Gain'
  //   Gain: '<S6>/StrWheelRatio'
  //   Inport: '<Root>/<vx>'
  //   Inport: '<Root>/aSteerWheel'
  //   Math: '<S6>/Power'
  //   Sum: '<S6>/Add'

  rtb_YawDesired = (rtU.aSteerWheel - 512.0) * 0.0019569471624266144 * 154.0 *
    0.017453292519943295 * 0.165 * rtU.vx / (rtU.vx * rtU.vx *
    -0.0007135649843621406 + 1.575);

  // Switch: '<S22>/Switch2' incorporates:
  //   RelationalOperator: '<S22>/LowerRelop1'

  if (!(rtb_YawDesired > rtb_YawMax)) {
    // Gain: '<S6>/Gain1'
    rtb_YawMax = -rtb_YawMax;

    // Switch: '<S22>/Switch' incorporates:
    //   RelationalOperator: '<S22>/UpperRelop'

    if (!(rtb_YawDesired < rtb_YawMax)) {
      rtb_YawMax = rtb_YawDesired;
    }

    // End of Switch: '<S22>/Switch'
  }

  // End of Switch: '<S22>/Switch2'

  // Sum: '<S5>/Sum' incorporates:
  //   Inport: '<Root>/<nYaw>'

  rtDW.Sum = rtb_YawMax - rtU.nYaw;

  // Saturate: '<S5>/Saturation2'
  if (rtDW.Sum > 1.0) {
    // Outputs for Atomic SubSystem: '<S5>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S19>/ SFunction ' incorporates:
    //   MATLAB Function: '<S17>/Evaluate Rule Antecedents'

    rtb_TmpSignalConversionAtSFun_0 = 1.0;

    // End of Outputs for SubSystem: '<S5>/Fuzzy Logic  Controller'
  } else if (rtDW.Sum < -1.0) {
    // Outputs for Atomic SubSystem: '<S5>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S19>/ SFunction ' incorporates:
    //   MATLAB Function: '<S17>/Evaluate Rule Antecedents'

    rtb_TmpSignalConversionAtSFun_0 = -1.0;

    // End of Outputs for SubSystem: '<S5>/Fuzzy Logic  Controller'
  } else {
    // Outputs for Atomic SubSystem: '<S5>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S19>/ SFunction ' incorporates:
    //   MATLAB Function: '<S17>/Evaluate Rule Antecedents'

    rtb_TmpSignalConversionAtSFun_0 = rtDW.Sum;

    // End of Outputs for SubSystem: '<S5>/Fuzzy Logic  Controller'
  }

  // End of Saturate: '<S5>/Saturation2'

  // Sum: '<S5>/Sum1' incorporates:
  //   Delay: '<S5>/Delay'

  rtb_YawMax = rtDW.Sum - rtDW.Delay_DSTATE;

  // Saturate: '<S5>/Saturation1'
  if (rtb_YawMax > 1.0) {
    // Outputs for Atomic SubSystem: '<S5>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S19>/ SFunction ' incorporates:
    //   MATLAB Function: '<S17>/Evaluate Rule Antecedents'

    rtb_YawMax = 1.0;

    // End of Outputs for SubSystem: '<S5>/Fuzzy Logic  Controller'
  } else if (rtb_YawMax < -1.0) {
    // Outputs for Atomic SubSystem: '<S5>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S19>/ SFunction ' incorporates:
    //   MATLAB Function: '<S17>/Evaluate Rule Antecedents'

    rtb_YawMax = -1.0;

    // End of Outputs for SubSystem: '<S5>/Fuzzy Logic  Controller'
  }

  // End of Saturate: '<S5>/Saturation1'

  // Outputs for Atomic SubSystem: '<S5>/Fuzzy Logic  Controller'
  // MATLAB Function: '<S17>/Evaluate Rule Antecedents'
  rtb_YawDesired = 0.0;
  inputMFCache[0] = trimf(rtb_TmpSignalConversionAtSFun_0, i);
  inputMFCache[1] = trimf(rtb_TmpSignalConversionAtSFun_0, h);
  inputMFCache[2] = trimf(rtb_TmpSignalConversionAtSFun_0, g);
  inputMFCache[3] = trimf(rtb_TmpSignalConversionAtSFun_0, f);
  inputMFCache[4] = trimf(rtb_TmpSignalConversionAtSFun_0, e);
  inputMFCache[5] = trimf(rtb_TmpSignalConversionAtSFun_0, d);
  inputMFCache[6] = trimf(rtb_TmpSignalConversionAtSFun_0, c);
  inputMFCache[7] = trimf(rtb_YawMax, i);
  inputMFCache[8] = trimf(rtb_YawMax, h);
  inputMFCache[9] = trimf(rtb_YawMax, g);
  inputMFCache[10] = trimf(rtb_YawMax, f);
  inputMFCache[11] = trimf(rtb_YawMax, e);
  inputMFCache[12] = trimf(rtb_YawMax, d);
  inputMFCache[13] = trimf(rtb_YawMax, c);
  for (ruleID = 0; ruleID < 49; ruleID++) {
    rtb_YawMax = inputMFCache[b[ruleID] - 1];
    if (rtb_YawMax < 1.0) {
      rtb_TmpSignalConversionAtSFun_0 = rtb_YawMax;
    } else {
      rtb_TmpSignalConversionAtSFun_0 = 1.0;
    }

    rtb_YawMax = inputMFCache[b[ruleID + 49] + 6];
    if (rtb_TmpSignalConversionAtSFun_0 > rtb_YawMax) {
      rtb_TmpSignalConversionAtSFun_0 = rtb_YawMax;
    }

    rtb_antecedentOutputs[ruleID] = rtb_TmpSignalConversionAtSFun_0;
    rtb_YawDesired += rtb_TmpSignalConversionAtSFun_0;
  }

  // MATLAB Function: '<S17>/Evaluate Rule Consequents' incorporates:
  //   Constant: '<S17>/Output Sample Points'

  trimf_h(rtConstP.OutputSamplePoints_Value, i, tmp);
  trimf_h(rtConstP.OutputSamplePoints_Value, h, tmp_0);
  trimf_h(rtConstP.OutputSamplePoints_Value, g, tmp_1);
  trimf_h(rtConstP.OutputSamplePoints_Value, f, tmp_2);
  trimf_h(rtConstP.OutputSamplePoints_Value, e, tmp_3);
  trimf_h(rtConstP.OutputSamplePoints_Value, d, tmp_4);
  trimf_h(rtConstP.OutputSamplePoints_Value, c, tmp_5);
  for (ruleID = 0; ruleID < 200; ruleID++) {
    rtb_aggregatedOutputs[ruleID] = 0.0;
    rtDW.outputMFCache[7 * ruleID] = tmp[ruleID];
    rtDW.outputMFCache[7 * ruleID + 1] = tmp_0[ruleID];
    rtDW.outputMFCache[7 * ruleID + 2] = tmp_1[ruleID];
    rtDW.outputMFCache[7 * ruleID + 3] = tmp_2[ruleID];
    rtDW.outputMFCache[7 * ruleID + 4] = tmp_3[ruleID];
    rtDW.outputMFCache[7 * ruleID + 5] = tmp_4[ruleID];
    rtDW.outputMFCache[7 * ruleID + 6] = tmp_5[ruleID];
  }

  for (ruleID = 0; ruleID < 49; ruleID++) {
    for (inputID = 0; inputID < 200; inputID++) {
      rtb_TmpSignalConversionAtSFun_0 = rtDW.outputMFCache[(7 * inputID +
        b_0[ruleID]) - 1];
      rtb_YawMax = rtb_antecedentOutputs[ruleID];
      if ((!(rtb_TmpSignalConversionAtSFun_0 > rtb_YawMax)) && (!std::isnan
           (rtb_TmpSignalConversionAtSFun_0))) {
        rtb_YawMax = rtb_TmpSignalConversionAtSFun_0;
      }

      if (rtb_aggregatedOutputs[inputID] < rtb_YawMax) {
        rtb_aggregatedOutputs[inputID] = rtb_YawMax;
      }
    }
  }

  // End of MATLAB Function: '<S17>/Evaluate Rule Consequents'

  // MATLAB Function: '<S17>/Defuzzify Outputs' incorporates:
  //   Constant: '<S17>/Output Sample Points'
  //   MATLAB Function: '<S17>/Evaluate Rule Antecedents'

  if (rtb_YawDesired == 0.0) {
    rtb_YawDesired = 0.0;
  } else {
    rtb_YawDesired = 0.0;
    rtb_YawMax = 0.0;
    for (ruleID = 0; ruleID < 200; ruleID++) {
      rtb_YawMax += rtb_aggregatedOutputs[ruleID];
    }

    if (!(rtb_YawMax == 0.0)) {
      for (ruleID = 0; ruleID < 200; ruleID++) {
        rtb_YawDesired += rtConstP.OutputSamplePoints_Value[ruleID] *
          rtb_aggregatedOutputs[ruleID];
      }

      rtb_YawDesired *= 1.0 / rtb_YawMax;
    }
  }

  // End of MATLAB Function: '<S17>/Defuzzify Outputs'
  // End of Outputs for SubSystem: '<S5>/Fuzzy Logic  Controller'

  // Gain: '<S7>/Gain' incorporates:
  //   Gain: '<S5>/Gain'
  //   Gain: '<S5>/RearTrack'
  //   Gain: '<S5>/rwheel'

  rtb_YawDesired = 100.0 * rtb_YawDesired * 0.625 * 0.255 * 1.02;

  // Switch: '<S10>/Switch2' incorporates:
  //   RelationalOperator: '<S10>/LowerRelop1'

  if (!(rtb_YawDesired > rtb_Switch1)) {
    // Gain: '<S7>/Gain3' incorporates:
    //   MinMax: '<S7>/Min1'

    rtb_Switch1 = std::fmin(rtb_Switch1_tmp, rtb_Switch1_tmp_0) * 2.0;

    // Switch: '<S10>/Switch' incorporates:
    //   RelationalOperator: '<S10>/UpperRelop'

    if (!(rtb_YawDesired < rtb_Switch1)) {
      rtb_Switch1 = rtb_YawDesired;
    }

    // End of Switch: '<S10>/Switch'
  }

  // Gain: '<S3>/Gain'
  rtb_Switch1 *= 0.5;

  // Sum: '<S3>/Add' incorporates:
  //   MinMax: '<S3>/Min'

  rtb_TLNm = std::fmin(rtb_T, rtb_TLNm) + rtb_Switch1;

  // Switch: '<S8>/Switch2' incorporates:
  //   Constant: '<S3>/Constant'
  //   RelationalOperator: '<S8>/LowerRelop1'
  //   RelationalOperator: '<S8>/UpperRelop'
  //   Switch: '<S8>/Switch'

  if (rtb_TLNm > rtb_T) {
    rtb_TLNm = rtb_T;
  } else if (rtb_TLNm < 0.0) {
    // Switch: '<S8>/Switch' incorporates:
    //   Constant: '<S3>/Constant'

    rtb_TLNm = 0.0;
  }

  // Outport: '<Root>/MMotorL2Demand' incorporates:
  //   Gain: '<Root>/Gain'
  //   Switch: '<S8>/Switch2'

  rtY.MMotorL2Demand = 0.019596050742573669 * rtb_TLNm;

  // Sum: '<S3>/Add1' incorporates:
  //   MinMax: '<S3>/Min1'

  rtb_TRNm = std::fmin(rtb_T, rtb_TRNm) - rtb_Switch1;

  // Switch: '<S9>/Switch2' incorporates:
  //   Constant: '<S3>/Constant'
  //   RelationalOperator: '<S9>/LowerRelop1'
  //   RelationalOperator: '<S9>/UpperRelop'
  //   Switch: '<S9>/Switch'

  if (rtb_TRNm > rtb_T) {
    rtb_TRNm = rtb_T;
  } else if (rtb_TRNm < 0.0) {
    // Switch: '<S9>/Switch' incorporates:
    //   Constant: '<S3>/Constant'

    rtb_TRNm = 0.0;
  }

  // Outport: '<Root>/MMotorR2Demand' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Switch: '<S9>/Switch2'

  rtY.MMotorR2Demand = 0.019596050742573669 * rtb_TRNm;

  // Update for Memory: '<S13>/Memory'
  rtDW.Memory_PreviousInput = rtDW.Switch2;

  // Update for Memory: '<S14>/Memory'
  rtDW.Memory_PreviousInput_m = rtDW.Switch2_h;

  // Update for Delay: '<S5>/Delay'
  rtDW.Delay_DSTATE = rtDW.Sum;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&rtM)->Timing.t[0] =
    ((time_T)(++(&rtM)->Timing.clockTick0)) * (&rtM)->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [2.0s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 2.0, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&rtM)->Timing.clockTick1++;
  }
}

// Model initialize function
void TV_FLC0::initialize()
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
  (&rtM)->Timing.stepSize0 = 2.0;

  // InitializeConditions for Memory: '<S13>/Memory'
  rtDW.Memory_PreviousInput = 1.0;

  // InitializeConditions for Memory: '<S14>/Memory'
  rtDW.Memory_PreviousInput_m = 1.0;
}

time_T** TV_FLC0::RT_MODEL::getTPtrPtr()
{
  return &(Timing.t);
}

boolean_T TV_FLC0::RT_MODEL::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

time_T* TV_FLC0::RT_MODEL::getTPtr() const
{
  return (Timing.t);
}

void TV_FLC0::RT_MODEL::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T TV_FLC0::RT_MODEL::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

const char_T** TV_FLC0::RT_MODEL::getErrorStatusPtr()
{
  return &errorStatus;
}

const char_T* TV_FLC0::RT_MODEL::getErrorStatus() const
{
  return (errorStatus);
}

void TV_FLC0::RT_MODEL::setErrorStatus(const char_T* const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
TV_FLC0::TV_FLC0() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
TV_FLC0::~TV_FLC0() = default;

// Real-Time Model get method
TV_FLC0::RT_MODEL * TV_FLC0::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
