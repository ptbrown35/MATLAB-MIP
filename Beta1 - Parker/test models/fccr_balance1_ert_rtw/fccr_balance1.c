/*
 * fccr_balance1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "fccr_balance1".
 *
 * Model version              : 1.180
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Nov 29 15:22:42 2017
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fccr_balance1.h"
#include "fccr_balance1_private.h"
#include "fccr_balance1_dt.h"

/* Block signals (auto storage) */
B_fccr_balance1_T fccr_balance1_B;

/* Block states (auto storage) */
DW_fccr_balance1_T fccr_balance1_DW;

/* Real-time model */
RT_MODEL_fccr_balance1_T fccr_balance1_M_;
RT_MODEL_fccr_balance1_T *const fccr_balance1_M = &fccr_balance1_M_;
static void rate_monotonic_scheduler(void);
real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  uint32_T yi;
  uint32_T u1i;
  uint32_T carry = 0U;
  int32_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0U ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T i;
  uint32_T ys;
  uint32_T yi;
  uint32_T u1i;
  int32_T nc;
  uint32_T nr;
  uint32_T nl;
  int32_T i1;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      nl = 32U - nr;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << nl | yi;
        i++;
      }

      yi = u1i >> nr;
      u1i = nc < n1 ? u1[nc] : ys;
      y[i] = u1i << nl | yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void fccr_balance1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(fccr_balance1_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  fccr_balance1_M->Timing.RateInteraction.TID0_1 =
    (fccr_balance1_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (fccr_balance1_M->Timing.TaskCounters.TID[1])++;
  if ((fccr_balance1_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    fccr_balance1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function for TID0 */
void fccr_balance1_step0(void)         /* Sample time: [0.01s, 0.0s] */
{
  int32_T k;
  int32_T rtb_ENCODER_CHANNEL_L_0;
  boolean_T p;
  boolean_T p_0;
  real_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;
  int8_T rtb_Sum1_0;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/DT Fast Loop' */
  if (fccr_balance1_M->Timing.RateInteraction.TID0_1) {
    fccr_balance1_B.thetaRefrad = fccr_balance1_DW.DTFastLoop_Buffer0;
  }

  /* End of RateTransition: '<Root>/DT Fast Loop' */

  /* Start for MATLABSystem: '<S2>/MATLAB System1' */
  p = false;
  p_0 = true;
  if (!(fccr_balance1_DW.obj_e.SampleTime ==
        fccr_balance1_P.MATLABSystem1_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    fccr_balance1_DW.obj_e.SampleTime = fccr_balance1_P.MATLABSystem1_SampleTime;
  }

  fccr_read_accel_x();
  fccr_balance1_B.FirstOrderFilterLowPass_tmp = fccr_read_accel_y();
  fccr_balance1_B.Gain1_m = fccr_read_accel_z();
  fccr_balance1_B.b_varargout_4 = fccr_read_gyro_x();
  fccr_read_gyro_y();
  fccr_read_gyro_z();

  /* Gain: '<S2>/Gain1' incorporates:
   *  MATLABSystem: '<S2>/MATLAB System1'
   *  MATLABSystem: '<S2>/MATLAB System1'
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  fccr_balance1_B.Gain1_m = fccr_balance1_P.Gain1_Gain * rt_atan2d_snf
    (fccr_balance1_B.Gain1_m, fccr_balance1_B.FirstOrderFilterLowPass_tmp);

  /* MATLAB Function: '<S2>/First Order Filter Low Pass Coefficients' incorporates:
   *  Constant: '<Root>/dt'
   *  Constant: '<Root>/wc'
   */
  /* MATLAB Function 'G1/First Order Filter Low Pass Coefficients': '<S7>:1' */
  /* '<S7>:1:3' */
  fccr_balance1_B.Num[0] = 0.0;
  fccr_balance1_B.FirstOrderFilterLowPass_tmp = fccr_balance1_P.wc_Value *
    fccr_balance1_P.dt_Value;
  fccr_balance1_B.Num[1] = fccr_balance1_B.FirstOrderFilterLowPass_tmp;

  /* '<S7>:1:4' */
  fccr_balance1_B.Den[0] = 1.0;
  fccr_balance1_B.Den[1] = fccr_balance1_B.FirstOrderFilterLowPass_tmp - 1.0;

  /* DiscreteTransferFcn: '<S2>/First Order Filter Low Pass' */
  fccr_balance1_B.FirstOrderFilterLowPass_tmp = fccr_balance1_B.Gain1_m -
    fccr_balance1_B.Den[1] * fccr_balance1_DW.FirstOrderFilterLowPass_states;

  /* MATLAB Function: '<S2>/First Order Filter High Pass Coefficients' incorporates:
   *  Constant: '<Root>/dt'
   *  Constant: '<Root>/wc'
   */
  /* MATLAB Function 'G1/First Order Filter High Pass Coefficients': '<S6>:1' */
  /* '<S6>:1:3' */
  fccr_balance1_B.Num_i[0] = 1.0;
  fccr_balance1_B.Num_i[1] = -1.0;

  /* '<S6>:1:4' */
  fccr_balance1_B.Den_i[0] = 1.0;
  fccr_balance1_B.Den_i[1] = fccr_balance1_P.wc_Value * fccr_balance1_P.dt_Value
    - 1.0;

  /* DiscreteTransferFcn: '<S2>/First Order Filter High Pass' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator1'
   *  Gain: '<S2>/Gain2'
   */
  fccr_balance1_B.Gain1_m = fccr_balance1_P.Gain2_Gain *
    fccr_balance1_DW.DiscreteTimeIntegrator1_DSTATE - fccr_balance1_B.Den_i[1] *
    fccr_balance1_DW.FirstOrderFilterHighPass_states;
  fccr_balance1_B.Sum1 = fccr_balance1_B.Num_i[0] * fccr_balance1_B.Gain1_m;
  fccr_balance1_B.Sum1 += fccr_balance1_B.Num_i[1] *
    fccr_balance1_DW.FirstOrderFilterHighPass_states;

  /* Sum: '<S2>/Sum' incorporates:
   *  DiscreteTransferFcn: '<S2>/First Order Filter Low Pass'
   */
  fccr_balance1_B.Sum = (fccr_balance1_B.Num[0] *
    fccr_balance1_B.FirstOrderFilterLowPass_tmp + fccr_balance1_B.Num[1] *
    fccr_balance1_DW.FirstOrderFilterLowPass_states) + fccr_balance1_B.Sum1;

  /* Gain: '<Root>/D1_GAIN' incorporates:
   *  Sum: '<Root>/Sum'
   */
  fccr_balance1_B.Sum1 = (fccr_balance1_B.thetaRefrad - fccr_balance1_B.Sum) *
    fccr_balance1_P.D1_GAIN_Gain;

  /* DiscreteTransferFcn: '<Root>/D1 Inner Loop Controller' */
  fccr_balance1_B.MOTOR_POLARITY_L = ((fccr_balance1_B.Sum1 -
    fccr_balance1_P.D1InnerLoopController_DenCoef[1] *
    fccr_balance1_DW.D1InnerLoopController_states[0]) -
    fccr_balance1_P.D1InnerLoopController_DenCoef[2] *
    fccr_balance1_DW.D1InnerLoopController_states[1]) /
    fccr_balance1_P.D1InnerLoopController_DenCoef[0];
  fccr_balance1_B.u = (fccr_balance1_P.D1InnerLoopController_NumCoef[0] *
                       fccr_balance1_B.MOTOR_POLARITY_L +
                       fccr_balance1_P.D1InnerLoopController_NumCoef[1] *
                       fccr_balance1_DW.D1InnerLoopController_states[0]) +
    fccr_balance1_P.D1InnerLoopController_NumCoef[2] *
    fccr_balance1_DW.D1InnerLoopController_states[1];

  /* Gain: '<S4>/Gain' */
  fccr_balance1_B.Sum1 = fccr_balance1_P.Gain_Gain * fccr_balance1_B.u;

  /* Saturate: '<S4>/Saturation' */
  if (fccr_balance1_B.Sum1 > fccr_balance1_P.Saturation_UpperSat) {
    fccr_balance1_B.Sum1 = fccr_balance1_P.Saturation_UpperSat;
  } else {
    if (fccr_balance1_B.Sum1 < fccr_balance1_P.Saturation_LowerSat) {
      fccr_balance1_B.Sum1 = fccr_balance1_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  Gain: '<S4>/MOTOR_POLARITY_L'
   */
  tmp = fccr_balance1_P.MOTOR_POLARITY_L_Gain * fccr_balance1_B.Sum1;
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      rtb_Sum1_0 = (int8_T)tmp;
    } else {
      rtb_Sum1_0 = MIN_int8_T;
    }
  } else {
    rtb_Sum1_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion1' */

  /* Start for MATLABSystem: '<S4>/MOTOR_CHANNEL_L' */
  MW_set_motor(3U, rtb_Sum1_0, 2U);

  /* Gain: '<S4>/MOTOR_POLARITY_R' */
  fccr_balance1_B.Sum1 *= fccr_balance1_P.MOTOR_POLARITY_R_Gain;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (fccr_balance1_B.Sum1 < 128.0) {
    if (fccr_balance1_B.Sum1 >= -128.0) {
      rtb_Sum1_0 = (int8_T)fccr_balance1_B.Sum1;
    } else {
      rtb_Sum1_0 = MIN_int8_T;
    }
  } else {
    rtb_Sum1_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* Start for MATLABSystem: '<S4>/MOTOR_CHANNEL_R' */
  MW_set_motor(2U, rtb_Sum1_0, 2U);

  /* Start for MATLABSystem: '<S3>/ENCODER_CHANNEL_R' */
  p = false;
  p_0 = true;
  if (!(fccr_balance1_DW.obj_i.SampleTime ==
        fccr_balance1_P.ENCODER_CHANNEL_R_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    fccr_balance1_DW.obj_i.SampleTime =
      fccr_balance1_P.ENCODER_CHANNEL_R_SampleTime;
  }

  /* MATLABSystem: '<S3>/ENCODER_CHANNEL_R' */
  k = getEncoderValue(2U, 1U, 0);

  /* Start for MATLABSystem: '<S3>/ENCODER_CHANNEL_L' */
  p = false;
  p_0 = true;
  if (!(fccr_balance1_DW.obj_l.SampleTime ==
        fccr_balance1_P.ENCODER_CHANNEL_L_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    fccr_balance1_DW.obj_l.SampleTime =
      fccr_balance1_P.ENCODER_CHANNEL_L_SampleTime;
  }

  /* MATLABSystem: '<S3>/ENCODER_CHANNEL_L' */
  rtb_ENCODER_CHANNEL_L_0 = getEncoderValue(3U, 1U, 0);

  /* Gain: '<S3>/ENCODER_POLARITY_R' incorporates:
   *  MATLABSystem: '<S3>/ENCODER_CHANNEL_R'
   */
  tmp_3 = (uint32_T)fccr_balance1_P.ENCODER_POLARITY_R_Gain;
  tmp_4 = (uint32_T)k;
  sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_2.chunks[0U], 2);

  /* Sum: '<S3>/Sum2' */
  sMultiWordShr(&tmp_2.chunks[0U], 2, 1U, &tmp_1.chunks[0U], 2);

  /* Gain: '<S3>/ENCODER_POLARITY_L' incorporates:
   *  MATLABSystem: '<S3>/ENCODER_CHANNEL_L'
   */
  tmp_3 = (uint32_T)fccr_balance1_P.ENCODER_POLARITY_L_Gain;
  tmp_4 = (uint32_T)rtb_ENCODER_CHANNEL_L_0;
  sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_2.chunks[0U], 2);

  /* Sum: '<S3>/Sum2' */
  MultiWordAdd(&tmp_1.chunks[0U], &tmp_2.chunks[0U], &tmp_0.chunks[0U], 2);

  /* Gain: '<S3>/Gain' */
  fccr_balance1_B.Sum1 = sMultiWord2Double(&fccr_balance1_P.Gain_Gain_p.chunks
    [0U], 2, 0) * 1.0842021724855044E-19 * (sMultiWord2Double(&tmp_0.chunks[0U],
    2, 0) * 9.3132257461547852E-10);

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain3'
   */
  fccr_balance1_B.phirad = fccr_balance1_P.Gain1_Gain_i * fccr_balance1_B.Sum1 *
    fccr_balance1_P.Gain2_Gain_e * fccr_balance1_P.Gain3_Gain +
    fccr_balance1_B.Sum;

  /* Gain: '<S1>/Gain1' incorporates:
   *  Constant: '<Root>/phi Ref'
   */
  fccr_balance1_B.Gain1 = fccr_balance1_P.Gain1_Gain_n *
    fccr_balance1_P.phiRef_Value;

  /* Sum: '<Root>/Sum1' */
  fccr_balance1_B.Sum1 = fccr_balance1_B.Gain1 - fccr_balance1_B.phirad;

  /* RateTransition: '<Root>/DT Slow loop' */
  if (fccr_balance1_M->Timing.RateInteraction.TID0_1) {
    fccr_balance1_B.DTSlowloop = fccr_balance1_B.Sum1;
  }

  /* End of RateTransition: '<Root>/DT Slow loop' */

  /* Update for DiscreteTransferFcn: '<S2>/First Order Filter Low Pass' */
  fccr_balance1_DW.FirstOrderFilterLowPass_states =
    fccr_balance1_B.FirstOrderFilterLowPass_tmp;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' incorporates:
   *  Gain: '<S5>/Gain1'
   *  MATLABSystem: '<S2>/MATLAB System1'
   *  MATLABSystem: '<S2>/MATLAB System1'
   */
  fccr_balance1_DW.DiscreteTimeIntegrator1_DSTATE +=
    fccr_balance1_P.Gain1_Gain_j * fccr_balance1_B.b_varargout_4 *
    fccr_balance1_P.DiscreteTimeIntegrator1_gainval;

  /* Update for DiscreteTransferFcn: '<S2>/First Order Filter High Pass' */
  fccr_balance1_DW.FirstOrderFilterHighPass_states = fccr_balance1_B.Gain1_m;

  /* Update for DiscreteTransferFcn: '<Root>/D1 Inner Loop Controller' */
  fccr_balance1_DW.D1InnerLoopController_states[1] =
    fccr_balance1_DW.D1InnerLoopController_states[0];
  fccr_balance1_DW.D1InnerLoopController_states[0] =
    fccr_balance1_B.MOTOR_POLARITY_L;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, fccr_balance1_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(fccr_balance1_M)!=-1) &&
        !((rtmGetTFinal(fccr_balance1_M)-fccr_balance1_M->Timing.taskTime0) >
          fccr_balance1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(fccr_balance1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(fccr_balance1_M)) {
      rtmSetErrorStatus(fccr_balance1_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++fccr_balance1_M->Timing.clockTick0)) {
    ++fccr_balance1_M->Timing.clockTickH0;
  }

  fccr_balance1_M->Timing.taskTime0 = fccr_balance1_M->Timing.clockTick0 *
    fccr_balance1_M->Timing.stepSize0 + fccr_balance1_M->Timing.clockTickH0 *
    fccr_balance1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void fccr_balance1_step1(void)         /* Sample time: [0.1s, 0.0s] */
{
  uint8_T rtb_Button_0;
  boolean_T p;
  boolean_T p_0;
  real_T rtb_D2OuterLoopController;
  real_T rtb_PulseGenerator;

  /* Start for MATLABSystem: '<Root>/Button' */
  p = false;
  p_0 = true;
  if (!(fccr_balance1_DW.obj_b.SampleTime == fccr_balance1_P.Button_SampleTime))
  {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    fccr_balance1_DW.obj_b.SampleTime = fccr_balance1_P.Button_SampleTime;
  }

  /* MATLABSystem: '<Root>/Button' */
  rtb_Button_0 = rc_get_pause_button();

  /* Stop: '<Root>/Stop Simulation' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLABSystem: '<Root>/Button'
   */
  if (rtb_Button_0 != 0) {
    rtmSetStopRequested(fccr_balance1_M, 1);
  }

  /* End of Stop: '<Root>/Stop Simulation' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (fccr_balance1_DW.clockTickCounter <
                        fccr_balance1_P.PulseGenerator_Duty) &&
    (fccr_balance1_DW.clockTickCounter >= 0) ?
    fccr_balance1_P.PulseGenerator_Amp : 0.0;
  if (fccr_balance1_DW.clockTickCounter >= fccr_balance1_P.PulseGenerator_Period
      - 1.0) {
    fccr_balance1_DW.clockTickCounter = 0;
  } else {
    fccr_balance1_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<Root>/Convert to Logical' */
  rtb_PulseGenerator = floor(rtb_PulseGenerator);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  /* Start for MATLABSystem: '<Root>/LED' incorporates:
   *  DataTypeConversion: '<Root>/Convert to Logical'
   */
  rc_set_led(0U, (uint8_T)(rtb_PulseGenerator < 0.0 ? (int32_T)(uint8_T)-(int8_T)
              (uint8_T)-rtb_PulseGenerator : (int32_T)(uint8_T)
              rtb_PulseGenerator));

  /* DiscreteTransferFcn: '<Root>/D2 Outer Loop Controller' incorporates:
   *  Gain: '<Root>/D2_GAIN'
   */
  rtb_PulseGenerator = ((fccr_balance1_P.D2_GAIN_Gain *
    fccr_balance1_B.DTSlowloop - fccr_balance1_P.D2OuterLoopController_DenCoef[1]
    * fccr_balance1_DW.D2OuterLoopController_states[0]) -
                        fccr_balance1_P.D2OuterLoopController_DenCoef[2] *
                        fccr_balance1_DW.D2OuterLoopController_states[1]) /
    fccr_balance1_P.D2OuterLoopController_DenCoef[0];
  rtb_D2OuterLoopController = fccr_balance1_P.D2OuterLoopController_NumCoef[0] *
    rtb_PulseGenerator;
  rtb_D2OuterLoopController += fccr_balance1_P.D2OuterLoopController_NumCoef[1] *
    fccr_balance1_DW.D2OuterLoopController_states[0];
  rtb_D2OuterLoopController += fccr_balance1_P.D2OuterLoopController_NumCoef[2] *
    fccr_balance1_DW.D2OuterLoopController_states[1];

  /* Update for RateTransition: '<Root>/DT Fast Loop' */
  fccr_balance1_DW.DTFastLoop_Buffer0 = rtb_D2OuterLoopController;

  /* Update for DiscreteTransferFcn: '<Root>/D2 Outer Loop Controller' */
  fccr_balance1_DW.D2OuterLoopController_states[1] =
    fccr_balance1_DW.D2OuterLoopController_states[0];
  fccr_balance1_DW.D2OuterLoopController_states[0] = rtb_PulseGenerator;
  rtExtModeUpload(1, (((fccr_balance1_M->Timing.clockTick1+
                        fccr_balance1_M->Timing.clockTickH1* 4294967296.0)) *
                      0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  fccr_balance1_M->Timing.clockTick1++;
  if (!fccr_balance1_M->Timing.clockTick1) {
    fccr_balance1_M->Timing.clockTickH1++;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void fccr_balance1_step(int_T tid)
{
  switch (tid) {
   case 0 :
    fccr_balance1_step0();
    break;

   case 1 :
    fccr_balance1_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void fccr_balance1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)fccr_balance1_M, 0,
                sizeof(RT_MODEL_fccr_balance1_T));
  rtmSetTFinal(fccr_balance1_M, -1);
  fccr_balance1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  fccr_balance1_M->Sizes.checksums[0] = (2260593857U);
  fccr_balance1_M->Sizes.checksums[1] = (3485731059U);
  fccr_balance1_M->Sizes.checksums[2] = (901580007U);
  fccr_balance1_M->Sizes.checksums[3] = (78030728U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    fccr_balance1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(fccr_balance1_M->extModeInfo,
      &fccr_balance1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(fccr_balance1_M->extModeInfo,
                        fccr_balance1_M->Sizes.checksums);
    rteiSetTPtr(fccr_balance1_M->extModeInfo, rtmGetTPtr(fccr_balance1_M));
  }

  /* block I/O */
  (void) memset(((void *) &fccr_balance1_B), 0,
                sizeof(B_fccr_balance1_T));

  /* states (dwork) */
  (void) memset((void *)&fccr_balance1_DW, 0,
                sizeof(DW_fccr_balance1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    fccr_balance1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 150;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Button' */
  fccr_balance1_DW.obj_b.isInitialized = 0;
  fccr_balance1_DW.objisempty_b = true;
  fccr_balance1_DW.obj_b.SampleTime = fccr_balance1_P.Button_SampleTime;
  fccr_balance1_DW.obj_b.isInitialized = 1;

  /* Start for MATLABSystem: '<Root>/LED' */
  fccr_balance1_DW.obj_p.isInitialized = 0;
  fccr_balance1_DW.objisempty_n = true;
  fccr_balance1_DW.obj_p.isInitialized = 1;

  /* Start for RateTransition: '<Root>/DT Fast Loop' */
  fccr_balance1_B.thetaRefrad = fccr_balance1_P.DTFastLoop_InitialCondition;

  /* Start for MATLABSystem: '<S2>/MATLAB System1' */
  fccr_balance1_DW.obj_e.isInitialized = 0;
  fccr_balance1_DW.objisempty_g = true;
  fccr_balance1_DW.obj_e.SampleTime = fccr_balance1_P.MATLABSystem1_SampleTime;
  fccr_balance1_DW.obj_e.isInitialized = 1;
  fccr_initialize_imu();

  /* Start for MATLABSystem: '<S4>/MOTOR_CHANNEL_L' */
  fccr_balance1_DW.obj.isInitialized = 0;
  fccr_balance1_DW.objisempty = true;
  fccr_balance1_DW.obj.isInitialized = 1;

  /* Start for MATLABSystem: '<S4>/MOTOR_CHANNEL_R' */
  fccr_balance1_DW.obj_d.isInitialized = 0;
  fccr_balance1_DW.objisempty_e = true;
  fccr_balance1_DW.obj_d.isInitialized = 1;

  /* Start for MATLABSystem: '<S3>/ENCODER_CHANNEL_R' */
  fccr_balance1_DW.obj_i.isInitialized = 0;
  fccr_balance1_DW.objisempty_j = true;
  fccr_balance1_DW.obj_i.SampleTime =
    fccr_balance1_P.ENCODER_CHANNEL_R_SampleTime;
  fccr_balance1_DW.obj_i.isInitialized = 1;

  /* Start for MATLABSystem: '<S3>/ENCODER_CHANNEL_L' */
  fccr_balance1_DW.obj_l.isInitialized = 0;
  fccr_balance1_DW.objisempty_f = true;
  fccr_balance1_DW.obj_l.SampleTime =
    fccr_balance1_P.ENCODER_CHANNEL_L_SampleTime;
  fccr_balance1_DW.obj_l.isInitialized = 1;

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  fccr_balance1_DW.clockTickCounter = 0;

  /* InitializeConditions for RateTransition: '<Root>/DT Fast Loop' */
  fccr_balance1_DW.DTFastLoop_Buffer0 =
    fccr_balance1_P.DTFastLoop_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/First Order Filter Low Pass' */
  fccr_balance1_DW.FirstOrderFilterLowPass_states =
    fccr_balance1_P.FirstOrderFilterLowPass_Initial;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  fccr_balance1_DW.DiscreteTimeIntegrator1_DSTATE =
    fccr_balance1_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/First Order Filter High Pass' */
  fccr_balance1_DW.FirstOrderFilterHighPass_states =
    fccr_balance1_P.FirstOrderFilterHighPass_Initia;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/D1 Inner Loop Controller' */
  fccr_balance1_DW.D1InnerLoopController_states[0] =
    fccr_balance1_P.D1InnerLoopController_InitialSt;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/D2 Outer Loop Controller' */
  fccr_balance1_DW.D2OuterLoopController_states[0] =
    fccr_balance1_P.D2OuterLoopController_InitialSt;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/D1 Inner Loop Controller' */
  fccr_balance1_DW.D1InnerLoopController_states[1] =
    fccr_balance1_P.D1InnerLoopController_InitialSt;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/D2 Outer Loop Controller' */
  fccr_balance1_DW.D2OuterLoopController_states[1] =
    fccr_balance1_P.D2OuterLoopController_InitialSt;
}

/* Model terminate function */
void fccr_balance1_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/Button' */
  if (fccr_balance1_DW.obj_b.isInitialized == 1) {
    fccr_balance1_DW.obj_b.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/Button' */

  /* Start for MATLABSystem: '<Root>/LED' */
  if (fccr_balance1_DW.obj_p.isInitialized == 1) {
    fccr_balance1_DW.obj_p.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/LED' */

  /* Start for MATLABSystem: '<S2>/MATLAB System1' */
  if (fccr_balance1_DW.obj_e.isInitialized == 1) {
    fccr_balance1_DW.obj_e.isInitialized = 2;
    rc_power_off_imu();
  }

  /* End of Start for MATLABSystem: '<S2>/MATLAB System1' */

  /* Start for MATLABSystem: '<S4>/MOTOR_CHANNEL_L' */
  if (fccr_balance1_DW.obj.isInitialized == 1) {
    fccr_balance1_DW.obj.isInitialized = 2;
    MW_terminate_motor(2U);
  }

  /* End of Start for MATLABSystem: '<S4>/MOTOR_CHANNEL_L' */

  /* Start for MATLABSystem: '<S4>/MOTOR_CHANNEL_R' */
  if (fccr_balance1_DW.obj_d.isInitialized == 1) {
    fccr_balance1_DW.obj_d.isInitialized = 2;
    MW_terminate_motor(2U);
  }

  /* End of Start for MATLABSystem: '<S4>/MOTOR_CHANNEL_R' */

  /* Start for MATLABSystem: '<S3>/ENCODER_CHANNEL_R' */
  if (fccr_balance1_DW.obj_i.isInitialized == 1) {
    fccr_balance1_DW.obj_i.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<S3>/ENCODER_CHANNEL_R' */

  /* Start for MATLABSystem: '<S3>/ENCODER_CHANNEL_L' */
  if (fccr_balance1_DW.obj_l.isInitialized == 1) {
    fccr_balance1_DW.obj_l.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<S3>/ENCODER_CHANNEL_L' */
}
