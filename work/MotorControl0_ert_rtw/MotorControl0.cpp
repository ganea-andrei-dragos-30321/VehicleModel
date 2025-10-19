//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MotorControl0.cpp
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
#include "MotorControl0.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#define NumBitsPerChar                 8U

static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);

// Forward declaration for local functions
static real_T trimf(real_T x, const real_T params[3]);
static void trimf_g(const real_T x[200], const real_T params[3], real_T y[200]);
extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C"
{
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  static void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    boolean_T result = (boolean_T) 0;
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      uint16_T one = 1U;
      enum {
        LittleEndian,
        BigEndian
      } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
      switch (machByteOrder) {
       case LittleEndian:
        {
          union {
            LittleEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.fltVal = value;
          result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                               0x7FF00000 &&
                               ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                                (tmpVal.bitVal.words.wordL != 0) ));
          break;
        }

       case BigEndian:
        {
          union {
            BigEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.fltVal = value;
          result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                               0x7FF00000 &&
                               ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                                (tmpVal.bitVal.words.wordL != 0) ));
          break;
        }
      }
    }

    return result;
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}

extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      uint16_T one = 1U;
      enum {
        LittleEndian,
        BigEndian
      } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
      switch (machByteOrder) {
       case LittleEndian:
        {
          union {
            LittleEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.bitVal.words.wordH = 0x7FF00000U;
          tmpVal.bitVal.words.wordL = 0x00000000U;
          inf = tmpVal.fltVal;
          break;
        }

       case BigEndian:
        {
          union {
            BigEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.bitVal.words.wordH = 0x7FF00000U;
          tmpVal.bitVal.words.wordL = 0x00000000U;
          inf = tmpVal.fltVal;
          break;
        }
      }
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      uint16_T one = 1U;
      enum {
        LittleEndian,
        BigEndian
      } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
      switch (machByteOrder) {
       case LittleEndian:
        {
          union {
            LittleEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.bitVal.words.wordH = 0xFFF00000U;
          tmpVal.bitVal.words.wordL = 0x00000000U;
          minf = tmpVal.fltVal;
          break;
        }

       case BigEndian:
        {
          union {
            BigEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.bitVal.words.wordH = 0xFFF00000U;
          tmpVal.bitVal.words.wordL = 0x00000000U;
          minf = tmpVal.fltVal;
          break;
        }
      }
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      uint16_T one = 1U;
      enum {
        LittleEndian,
        BigEndian
      } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
      switch (machByteOrder) {
       case LittleEndian:
        {
          union {
            LittleEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.bitVal.words.wordH = 0xFFF80000U;
          tmpVal.bitVal.words.wordL = 0x00000000U;
          nan = tmpVal.fltVal;
          break;
        }

       case BigEndian:
        {
          union {
            BigEndianIEEEDouble bitVal;
            real_T fltVal;
          } tmpVal;

          tmpVal.bitVal.words.wordH = 0x7FFFFFFFU;
          tmpVal.bitVal.words.wordL = 0xFFFFFFFFU;
          nan = tmpVal.fltVal;
          break;
        }
      }
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0.0F } };

    uint16_T one = 1U;
    enum {
      LittleEndian,
      BigEndian
    } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
    switch (machByteOrder) {
     case LittleEndian:
      {
        nanF.wordL.wordLuint = 0xFFC00000U;
        break;
      }

     case BigEndian:
      {
        nanF.wordL.wordLuint = 0x7FFFFFFFU;
        break;
      }
    }

    return nanF.wordL.wordLreal;
  }
}

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
static real_T trimf(real_T x, const real_T params[3])
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
static void trimf_g(const real_T x[200], const real_T params[3], real_T y[200])
{
  real_T a;
  real_T b;
  real_T c;
  a = params[0];
  b = params[1];
  c = params[2];
  for (int16_T i = 0; i < 200; i++) {
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
void MotorControl0_step(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY)
{
  DW *rtDW = rtM->dwork;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T u0_tmp;
  real_T u1_tmp;
  int16_T i;
  int16_T ruleID;
  boolean_T tmp;
  static const real_T i_0[3] = { -1.27777777777778, -1.0, -0.722222222222222 };

  static const real_T h[3] = { -0.944444444444444, -0.666666666666667,
    -0.388888888888889 };

  static const real_T g[3] = { -0.611111111111111, -0.333333333333333,
    -0.0555555555555557 };

  static const real_T f[3] = { -0.277777777777778, -1.11022302462516E-16,
    0.277777777777778 };

  static const real_T e[3] = { 0.0555555555555555, 0.333333333333333,
    0.611111111111111 };

  static const real_T d[3] = { 0.388888888888889, 0.666666666666667,
    0.944444444444444 };

  static const real_T c[3] = { 0.722222222222222, 1.0, 1.27777777777778 };

  static const int8_T b[98] = { 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3,
    3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6,
    7, 7, 7, 7, 7, 7, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5,
    6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3,
    4, 5, 6, 7 };

  static const int8_T b_0[49] = { 1, 1, 1, 1, 2, 3, 4, 1, 1, 1, 2, 3, 4, 5, 1, 1,
    2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6, 7, 7, 3, 4, 5, 6, 7, 7, 7,
    4, 5, 6, 7, 7, 7, 7 };

  // Gain: '<S5>/rwheel'
  rtDW->Switch1 = rtP.rwheel / rtP.Gr;
  rtb_TmpSignalConversionAtSFun_0 = rtDW->Switch1 * rtU->w_g;

  // Switch: '<S10>/Switch1' incorporates:
  //   Abs: '<S5>/Abs'
  //   Clock: '<S10>/Clock'
  //   Constant: '<S5>/Constant'
  //   Gain: '<S10>/Gain'
  //   Gain: '<S10>/Gain1'
  //   Gain: '<S5>/rwheel'
  //   Product: '<S5>/Divide'
  //   Sum: '<S5>/Subtract'
  //   Switch: '<S10>/Switch'

  if (fabs(rtP.Constant_Value - rtDW->Switch1 * rtU->w / rtU->vx) >=
      rtP.alpha_max) {
    // Switch: '<S10>/Switch' incorporates:
    //   Clock: '<S10>/Clock'
    //   Constant: '<S10>/Constant2'
    //   Memory: '<S10>/Memory'

    if (rtM->Timing.t[0] != 0.0) {
      rtDW->MMotorR2Demand = rtDW->Memory_PreviousInput;
    } else {
      rtDW->MMotorR2Demand = rtP.Constant2_Value;
    }

    rtDW->Switch1 = rtP.Kneg * rtDW->MMotorR2Demand;
  } else {
    if (rtM->Timing.t[0] != 0.0) {
      // Switch: '<S10>/Switch' incorporates:
      //   Memory: '<S10>/Memory'

      rtDW->MMotorR2Demand = rtDW->Memory_PreviousInput;
    } else {
      // Switch: '<S10>/Switch' incorporates:
      //   Constant: '<S10>/Constant2'

      rtDW->MMotorR2Demand = rtP.Constant2_Value;
    }

    rtDW->Switch1 = rtP.Kpos * rtDW->MMotorR2Demand;
  }

  // End of Switch: '<S10>/Switch1'

  // Switch: '<S12>/Switch2' incorporates:
  //   Constant: '<S10>/Constant1'
  //   Constant: '<S10>/Constant2'
  //   RelationalOperator: '<S12>/LowerRelop1'
  //   RelationalOperator: '<S12>/UpperRelop'
  //   Switch: '<S12>/Switch'

  if (rtDW->Switch1 > rtP.Constant2_Value) {
    // Switch: '<S12>/Switch2'
    rtDW->Switch2 = rtP.Constant2_Value;
  } else if (rtDW->Switch1 < rtP.Constant1_Value) {
    // Switch: '<S12>/Switch' incorporates:
    //   Constant: '<S10>/Constant1'
    //   Switch: '<S12>/Switch2'

    rtDW->Switch2 = rtP.Constant1_Value;
  } else {
    // Switch: '<S12>/Switch2' incorporates:
    //   Switch: '<S12>/Switch'

    rtDW->Switch2 = rtDW->Switch1;
  }

  // End of Switch: '<S12>/Switch2'

  // Lookup_n-D: '<S2>/1-D Lookup Table' incorporates:
  //   Gain: '<S2>/rad//s to rpm1'

  rtDW->Switch1 = look1_binlx(rtP.radstorpm1_Gain * rtU->w, rtP.MWhlSpin,
    rtP.MTrq, 70UL);

  // Product: '<S2>/Product'
  rtDW->Product = rtDW->Switch2 * rtDW->Switch1;

  // Switch: '<S8>/Switch2' incorporates:
  //   RelationalOperator: '<S8>/LowerRelop1'

  if (!(rtDW->Product > rtDW->Switch1)) {
    // Gain: '<S2>/Gain'
    rtDW->Switch1 *= rtP.Gain_Gain;

    // Switch: '<S8>/Switch' incorporates:
    //   RelationalOperator: '<S8>/UpperRelop'

    if (!(rtDW->Product < rtDW->Switch1)) {
      rtDW->Switch1 = rtDW->Product;
    }

    // End of Switch: '<S8>/Switch'
  }

  // End of Switch: '<S8>/Switch2'

  // Gain: '<S6>/Gain1' incorporates:
  //   Gain: '<S4>/rad//s to rpm'
  //   Gain: '<S4>/rad//s to rpm 2'
  //   Lookup_n-D: '<S4>/1-D Lookup Table'
  //   Lookup_n-D: '<S4>/1-D Lookup Table1'
  //   Product: '<S4>/Product'
  //   Sum: '<S4>/Sum of Elements'

  rtDW->Product = (look1_binlx(rtP.radstorpm2_Gain * rtU->w, rtP.MWhlSpin,
    rtP.MTrq, 70UL) + look1_binlx(rtP.radstorpm_Gain * rtU->w_g, rtP.MWhlSpin,
    rtP.MTrq, 70UL)) * rtU->Throttle * rtP.Gain1_Gain_f;

  // Lookup_n-D: '<S2>/1-D Lookup Table1' incorporates:
  //   Gain: '<S2>/rad//s to rpm'

  rtDW->TRNm = look1_binlx(rtP.radstorpm_Gain_o * rtU->w_g, rtP.MWhlSpin,
    rtP.MTrq, 70UL);

  // Switch: '<S11>/Switch1' incorporates:
  //   Abs: '<S5>/Abs1'
  //   Clock: '<S11>/Clock'
  //   Constant: '<S5>/Constant'
  //   Gain: '<S11>/Gain'
  //   Gain: '<S11>/Gain1'
  //   Product: '<S5>/Divide1'
  //   Sum: '<S5>/Subtract1'
  //   Switch: '<S11>/Switch'

  if (fabs(rtP.Constant_Value - rtb_TmpSignalConversionAtSFun_0 / rtU->vx) >=
      rtP.alpha_max) {
    // Switch: '<S11>/Switch' incorporates:
    //   Clock: '<S11>/Clock'
    //   Constant: '<S11>/Constant2'
    //   Memory: '<S11>/Memory'

    if (rtM->Timing.t[0] != 0.0) {
      rtDW->MMotorR2Demand = rtDW->Memory_PreviousInput_n;
    } else {
      rtDW->MMotorR2Demand = rtP.Constant2_Value_g;
    }

    rtDW->MMotorR2Demand *= rtP.Kneg;
  } else {
    if (rtM->Timing.t[0] != 0.0) {
      // Switch: '<S11>/Switch' incorporates:
      //   Memory: '<S11>/Memory'

      rtDW->MMotorR2Demand = rtDW->Memory_PreviousInput_n;
    } else {
      // Switch: '<S11>/Switch' incorporates:
      //   Constant: '<S11>/Constant2'

      rtDW->MMotorR2Demand = rtP.Constant2_Value_g;
    }

    rtDW->MMotorR2Demand *= rtP.Kpos;
  }

  // End of Switch: '<S11>/Switch1'

  // Switch: '<S13>/Switch2' incorporates:
  //   Constant: '<S11>/Constant1'
  //   Constant: '<S11>/Constant2'
  //   RelationalOperator: '<S13>/LowerRelop1'
  //   RelationalOperator: '<S13>/UpperRelop'
  //   Switch: '<S13>/Switch'

  if (rtDW->MMotorR2Demand > rtP.Constant2_Value_g) {
    // Switch: '<S13>/Switch2'
    rtDW->Switch2_b = rtP.Constant2_Value_g;
  } else if (rtDW->MMotorR2Demand < rtP.Constant1_Value_b) {
    // Switch: '<S13>/Switch' incorporates:
    //   Constant: '<S11>/Constant1'
    //   Switch: '<S13>/Switch2'

    rtDW->Switch2_b = rtP.Constant1_Value_b;
  } else {
    // Switch: '<S13>/Switch2' incorporates:
    //   Switch: '<S13>/Switch'

    rtDW->Switch2_b = rtDW->MMotorR2Demand;
  }

  // End of Switch: '<S13>/Switch2'

  // Product: '<S2>/Product1'
  rtDW->MMotorR2Demand = rtDW->Switch2_b * rtDW->TRNm;

  // Switch: '<S9>/Switch2' incorporates:
  //   RelationalOperator: '<S9>/LowerRelop1'

  if (!(rtDW->MMotorR2Demand > rtDW->TRNm)) {
    // Gain: '<S2>/Gain1'
    rtDW->TRNm *= rtP.Gain1_Gain;

    // Switch: '<S9>/Switch' incorporates:
    //   RelationalOperator: '<S9>/UpperRelop'

    if (!(rtDW->MMotorR2Demand < rtDW->TRNm)) {
      rtDW->TRNm = rtDW->MMotorR2Demand;
    }

    // End of Switch: '<S9>/Switch'
  }

  // End of Switch: '<S9>/Switch2'

  // Sum: '<S18>/Add1' incorporates:
  //   Sum: '<S18>/Add3'
  //   Switch: '<S19>/Switch2'

  u0_tmp = rtDW->Product - rtDW->Switch1;

  // Sum: '<S18>/Add' incorporates:
  //   Sum: '<S18>/Add2'
  //   Switch: '<S19>/Switch2'

  u1_tmp = rtDW->TRNm - rtDW->Product;

  // MinMax: '<S18>/Min' incorporates:
  //   MinMax: '<S18>/Min1'
  //   Sum: '<S18>/Add'
  //   Sum: '<S18>/Add1'
  //   Switch: '<S19>/Switch2'

  tmp = rtIsNaN(u1_tmp);
  if ((u0_tmp >= u1_tmp) || tmp) {
    rtDW->MMotorR2Demand = u0_tmp;
  } else {
    rtDW->MMotorR2Demand = u1_tmp;
  }

  // Gain: '<S18>/Gain2' incorporates:
  //   MinMax: '<S18>/Min'

  rtDW->MMotorR2Demand *= rtP.Gain2_Gain;

  // Abs: '<S7>/Abs' incorporates:
  //   Gain: '<Root>/Gain2'
  //   Product: '<S7>/Divide'
  //   UnitConversion: '<S20>/Unit Conversion'

  // Unit Conversion - from: rad/s to: deg/s
  // Expression: output = (57.2958*input) + (0)
  rtb_TmpSignalConversionAtSFun_0 = fabs(rtU->vx / (rtP.Gain2_Gain_f * rtU->gy) *
    57.295779513082323);

  // Product: '<S7>/Divide1' incorporates:
  //   Bias: '<S1>/Bias'
  //   Constant: '<S7>/Constant'
  //   Gain: '<S1>/Gain2'
  //   Gain: '<S1>/Gain3'
  //   Gain: '<S7>/Gain'
  //   Gain: '<S7>/StrWheelRatio'
  //   Math: '<S7>/Power'
  //   Sum: '<S7>/Add'

  rtDW->YawDesired = (rtU->aSteerWheel + rtP.Bias_Bias) * rtP.Gain2_Gain_m *
    rtP.Gain3_Gain_c * rtP.StrWheelRatio * rtU->vx * (rtU->vx * rtU->vx * rtP.Ku
    + rtP.L);

  // Switch: '<S21>/Switch2' incorporates:
  //   RelationalOperator: '<S21>/LowerRelop1'

  if (!(rtDW->YawDesired > rtb_TmpSignalConversionAtSFun_0)) {
    // Gain: '<S7>/Gain1'
    rtb_TmpSignalConversionAtSFun_0 *= rtP.Gain1_Gain_d;

    // Switch: '<S21>/Switch' incorporates:
    //   RelationalOperator: '<S21>/UpperRelop'

    if (!(rtDW->YawDesired < rtb_TmpSignalConversionAtSFun_0)) {
      rtb_TmpSignalConversionAtSFun_0 = rtDW->YawDesired;
    }

    // End of Switch: '<S21>/Switch'
  }

  // End of Switch: '<S21>/Switch2'

  // Sum: '<S3>/Sum'
  rtDW->Sum = rtb_TmpSignalConversionAtSFun_0 - rtU->nYaw;

  // Saturate: '<S3>/Saturation2'
  if (rtDW->Sum > rtP.Saturation2_UpperSat) {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtDW->rtb_TmpSignalConversionAtSFun_m = rtP.Saturation2_UpperSat;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  } else if (rtDW->Sum < rtP.Saturation2_LowerSat) {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtDW->rtb_TmpSignalConversionAtSFun_m = rtP.Saturation2_LowerSat;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  } else {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtDW->rtb_TmpSignalConversionAtSFun_m = rtDW->Sum;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  }

  // End of Saturate: '<S3>/Saturation2'

  // Sum: '<S3>/Sum1' incorporates:
  //   Delay: '<S3>/Delay'

  rtb_TmpSignalConversionAtSFun_0 = rtDW->Sum - rtDW->Delay_DSTATE;

  // Saturate: '<S3>/Saturation1'
  if (rtb_TmpSignalConversionAtSFun_0 > rtP.Saturation1_UpperSat) {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtb_TmpSignalConversionAtSFun_0 = rtP.Saturation1_UpperSat;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  } else if (rtb_TmpSignalConversionAtSFun_0 < rtP.Saturation1_LowerSat) {
    // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
    // SignalConversion generated from: '<S16>/ SFunction ' incorporates:
    //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

    rtb_TmpSignalConversionAtSFun_0 = rtP.Saturation1_LowerSat;

    // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'
  }

  // End of Saturate: '<S3>/Saturation1'

  // Outputs for Atomic SubSystem: '<S3>/Fuzzy Logic  Controller'
  // MATLAB Function: '<S14>/Evaluate Rule Antecedents'
  rtDW->YawDesired = 0.0;
  rtDW->inputMFCache[0] = trimf(rtDW->rtb_TmpSignalConversionAtSFun_m, i_0);
  rtDW->inputMFCache[1] = trimf(rtDW->rtb_TmpSignalConversionAtSFun_m, h);
  rtDW->inputMFCache[2] = trimf(rtDW->rtb_TmpSignalConversionAtSFun_m, g);
  rtDW->inputMFCache[3] = trimf(rtDW->rtb_TmpSignalConversionAtSFun_m, f);
  rtDW->inputMFCache[4] = trimf(rtDW->rtb_TmpSignalConversionAtSFun_m, e);
  rtDW->inputMFCache[5] = trimf(rtDW->rtb_TmpSignalConversionAtSFun_m, d);
  rtDW->inputMFCache[6] = trimf(rtDW->rtb_TmpSignalConversionAtSFun_m, c);
  rtDW->inputMFCache[7] = trimf(rtb_TmpSignalConversionAtSFun_0, i_0);
  rtDW->inputMFCache[8] = trimf(rtb_TmpSignalConversionAtSFun_0, h);
  rtDW->inputMFCache[9] = trimf(rtb_TmpSignalConversionAtSFun_0, g);
  rtDW->inputMFCache[10] = trimf(rtb_TmpSignalConversionAtSFun_0, f);
  rtDW->inputMFCache[11] = trimf(rtb_TmpSignalConversionAtSFun_0, e);
  rtDW->inputMFCache[12] = trimf(rtb_TmpSignalConversionAtSFun_0, d);
  rtDW->inputMFCache[13] = trimf(rtb_TmpSignalConversionAtSFun_0, c);
  for (ruleID = 0; ruleID < 49; ruleID++) {
    rtDW->rtb_TmpSignalConversionAtSFun_m = 1.0;
    rtb_TmpSignalConversionAtSFun_0 = rtDW->inputMFCache[static_cast<int16_T>(
      static_cast<int16_T>(b[ruleID]) - 1)];
    if (rtb_TmpSignalConversionAtSFun_0 < 1.0) {
      rtDW->rtb_TmpSignalConversionAtSFun_m = rtb_TmpSignalConversionAtSFun_0;
    }

    rtb_TmpSignalConversionAtSFun_0 = rtDW->inputMFCache[static_cast<int16_T>(
      static_cast<int16_T>(b[static_cast<int16_T>(ruleID + 49)]) + 6)];
    if (rtDW->rtb_TmpSignalConversionAtSFun_m > rtb_TmpSignalConversionAtSFun_0)
    {
      rtDW->rtb_TmpSignalConversionAtSFun_m = rtb_TmpSignalConversionAtSFun_0;
    }

    rtDW->antecedentOutputs[ruleID] = rtDW->rtb_TmpSignalConversionAtSFun_m;
    rtDW->YawDesired += rtDW->rtb_TmpSignalConversionAtSFun_m;
  }

  // MATLAB Function: '<S14>/Evaluate Rule Consequents' incorporates:
  //   Constant: '<S14>/Output Sample Points'

  trimf_g(rtP.OutputSamplePoints_Value, i_0, rtDW->dv);
  trimf_g(rtP.OutputSamplePoints_Value, h, rtDW->dv1);
  trimf_g(rtP.OutputSamplePoints_Value, g, rtDW->dv2);
  trimf_g(rtP.OutputSamplePoints_Value, f, rtDW->dv3);
  trimf_g(rtP.OutputSamplePoints_Value, e, rtDW->dv4);
  trimf_g(rtP.OutputSamplePoints_Value, d, rtDW->dv5);
  trimf_g(rtP.OutputSamplePoints_Value, c, rtDW->dv6);
  for (ruleID = 0; ruleID < 200; ruleID++) {
    rtDW->aggregatedOutputs[ruleID] = 0.0;
    rtDW->outputMFCache[static_cast<int16_T>(7 * ruleID)] = rtDW->dv[ruleID];
    rtDW->outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) +
      1)] = rtDW->dv1[ruleID];
    rtDW->outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) +
      2)] = rtDW->dv2[ruleID];
    rtDW->outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) +
      3)] = rtDW->dv3[ruleID];
    rtDW->outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) +
      4)] = rtDW->dv4[ruleID];
    rtDW->outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) +
      5)] = rtDW->dv5[ruleID];
    rtDW->outputMFCache[static_cast<int16_T>(static_cast<int16_T>(7 * ruleID) +
      6)] = rtDW->dv6[ruleID];
  }

  for (ruleID = 0; ruleID < 49; ruleID++) {
    for (i = 0; i < 200; i++) {
      rtDW->rtb_TmpSignalConversionAtSFun_m = rtDW->outputMFCache
        [static_cast<int16_T>(static_cast<int16_T>(static_cast<int16_T>(7 * i) +
        static_cast<int16_T>(b_0[ruleID])) - 1)];
      rtb_TmpSignalConversionAtSFun_0 = rtDW->antecedentOutputs[ruleID];
      if ((!(rtDW->rtb_TmpSignalConversionAtSFun_m >
             rtb_TmpSignalConversionAtSFun_0)) && (!rtIsNaN
           (rtDW->rtb_TmpSignalConversionAtSFun_m))) {
        rtb_TmpSignalConversionAtSFun_0 = rtDW->rtb_TmpSignalConversionAtSFun_m;
      }

      if (rtDW->aggregatedOutputs[i] < rtb_TmpSignalConversionAtSFun_0) {
        rtDW->aggregatedOutputs[i] = rtb_TmpSignalConversionAtSFun_0;
      }
    }
  }

  // End of MATLAB Function: '<S14>/Evaluate Rule Consequents'

  // MATLAB Function: '<S14>/Defuzzify Outputs' incorporates:
  //   Constant: '<S14>/Output Sample Points'
  //   MATLAB Function: '<S14>/Evaluate Rule Antecedents'

  if (rtDW->YawDesired == 0.0) {
    rtDW->YawDesired = 0.0;
  } else {
    rtDW->YawDesired = 0.0;
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
    for (ruleID = 0; ruleID < 200; ruleID++) {
      rtb_TmpSignalConversionAtSFun_0 += rtDW->aggregatedOutputs[ruleID];
    }

    if (rtb_TmpSignalConversionAtSFun_0 == 0.0) {
      rtDW->YawDesired = (rtP.OutputSamplePoints_Value[0] +
                          rtP.OutputSamplePoints_Value[199]) / 2.0;
    } else {
      for (ruleID = 0; ruleID < 200; ruleID++) {
        rtDW->YawDesired += rtP.OutputSamplePoints_Value[ruleID] *
          rtDW->aggregatedOutputs[ruleID];
      }

      rtDW->YawDesired *= 1.0 / rtb_TmpSignalConversionAtSFun_0;
    }
  }

  // End of MATLAB Function: '<S14>/Defuzzify Outputs'
  // End of Outputs for SubSystem: '<S3>/Fuzzy Logic  Controller'

  // Gain: '<S18>/Gain' incorporates:
  //   Gain: '<S3>/Gain'
  //   Gain: '<S3>/RearTrack'
  //   Gain: '<S3>/rwheel'

  rtDW->YawDesired = rtP.tr / 2.0 * (rtP.Kp * rtDW->YawDesired) * rtP.rwheel *
    rtP.F;

  // Switch: '<S19>/Switch2' incorporates:
  //   RelationalOperator: '<S19>/LowerRelop1'

  if (!(rtDW->YawDesired > rtDW->MMotorR2Demand)) {
    // MinMax: '<S18>/Min1'
    if ((u0_tmp <= u1_tmp) || tmp) {
      u1_tmp = u0_tmp;
    }

    // Gain: '<S18>/Gain3' incorporates:
    //   MinMax: '<S18>/Min1'

    rtDW->MMotorR2Demand = rtP.Gain3_Gain * u1_tmp;

    // Switch: '<S19>/Switch' incorporates:
    //   RelationalOperator: '<S19>/UpperRelop'

    if (!(rtDW->YawDesired < rtDW->MMotorR2Demand)) {
      rtDW->MMotorR2Demand = rtDW->YawDesired;
    }

    // End of Switch: '<S19>/Switch'
  }

  // Gain: '<S6>/Gain'
  rtDW->MMotorR2Demand *= rtP.Gain_Gain_l;

  // MinMax: '<S6>/Min'
  if ((rtDW->Product <= rtDW->Switch1) || rtIsNaN(rtDW->Switch1)) {
    rtDW->Switch1 = rtDW->Product;
  }

  // Sum: '<S6>/Add' incorporates:
  //   MinMax: '<S6>/Min'

  rtDW->Switch1 += rtDW->MMotorR2Demand;

  // Saturate: '<S6>/Saturation'
  if (rtDW->Switch1 > rtP.Saturation_UpperSat) {
    rtDW->Switch1 = rtP.Saturation_UpperSat;
  } else if (rtDW->Switch1 < rtP.Saturation_LowerSat) {
    rtDW->Switch1 = rtP.Saturation_LowerSat;
  }

  // Outport: '<Root>/MMotorL2Demand' incorporates:
  //   Gain: '<Root>/Gain'
  //   Saturate: '<S6>/Saturation'

  rtY->MMotorL2Demand = rtP.Gain_Gain_a * rtDW->Switch1;

  // MinMax: '<S6>/Min1'
  if ((rtDW->Product <= rtDW->TRNm) || rtIsNaN(rtDW->TRNm)) {
    rtDW->TRNm = rtDW->Product;
  }

  // Sum: '<S6>/Add1' incorporates:
  //   MinMax: '<S6>/Min1'

  rtDW->Switch1 = rtDW->TRNm - rtDW->MMotorR2Demand;

  // Saturate: '<S6>/Saturation1'
  if (rtDW->Switch1 > rtP.Saturation1_UpperSat_d) {
    rtDW->Switch1 = rtP.Saturation1_UpperSat_d;
  } else if (rtDW->Switch1 < rtP.Saturation1_LowerSat_f) {
    rtDW->Switch1 = rtP.Saturation1_LowerSat_f;
  }

  // Outport: '<Root>/MMotorR2Demand' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Saturate: '<S6>/Saturation1'

  rtY->MMotorR2Demand = rtP.Gain1_Gain_i * rtDW->Switch1;

  // Update for Memory: '<S10>/Memory'
  rtDW->Memory_PreviousInput = rtDW->Switch2;

  // Update for Memory: '<S11>/Memory'
  rtDW->Memory_PreviousInput_n = rtDW->Switch2_b;

  // Update for Delay: '<S3>/Delay'
  rtDW->Delay_DSTATE = rtDW->Sum;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  rtM->Timing.t[0] =
    ((time_T)(++rtM->Timing.clockTick0)) * rtM->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [2.0s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 2.0, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    rtM->Timing.clockTick1++;
  }
}

// Model initialize function
void MotorControl0_initialize(RT_MODEL *const rtM, ExtU *rtU, ExtY *rtY)
{
  DW *rtDW = rtM->dwork;

  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, rtM->getTPtrPtr());
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, rtM->getErrorStatusPtr());
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&rtM->solverInfo, false);
  rtsiSetIsContModeFrozen(&rtM->solverInfo, false);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtM->setTPtr(&rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 2.0;

  // states (dwork)
  (void) memset(static_cast<void *>(rtDW), 0,
                sizeof(DW));

  // external inputs
  (void)memset(rtU, 0, sizeof(ExtU));

  // external outputs
  (void)memset(rtY, 0, sizeof(ExtY));

  // InitializeConditions for Memory: '<S10>/Memory'
  rtDW->Memory_PreviousInput = rtP.Memory_InitialCondition;

  // InitializeConditions for Memory: '<S11>/Memory'
  rtDW->Memory_PreviousInput_n = rtP.Memory_InitialCondition_o;

  // InitializeConditions for Delay: '<S3>/Delay'
  rtDW->Delay_DSTATE = rtP.Delay_InitialCondition;
}

time_T* RT_MODEL::getTPtr() const
{
  return (Timing.t);
}

void RT_MODEL::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T RT_MODEL::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

boolean_T RT_MODEL::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

const char_T** RT_MODEL::getErrorStatusPtr()
{
  return &errorStatus;
}

time_T** RT_MODEL::getTPtrPtr()
{
  return &(Timing.t);
}

DW* RT_MODEL::getRootDWork() const
{
  return dwork;
}

void RT_MODEL::setRootDWork(DW* aRootDWork)
{
  dwork = aRootDWork;
}

const char_T* RT_MODEL::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL::setErrorStatus(const char_T* const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
