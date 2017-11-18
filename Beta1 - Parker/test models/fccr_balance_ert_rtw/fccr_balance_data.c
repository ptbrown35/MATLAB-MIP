/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fccr_balance_data.c
 *
 * Code generated for Simulink model 'fccr_balance'.
 *
 * Model version                  : 1.93
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Nov 17 19:12:57 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fccr_balance.h"
#include "fccr_balance_private.h"

/* Block parameters (auto storage) */
P_fccr_balance_T fccr_balance_P = {
  /* Expression: 0.1
   * Referenced by: '<Root>/Button'
   */
  0.1,

  /* Expression: 0.01
   * Referenced by: '<S2>/MATLAB System'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S3>/ENCODER_CHANNEL_L'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S3>/ENCODER_CHANNEL_R'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/Sine Wave'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S3>/Gain1'
   */
  6.2831853071795862,

  /* Expression: 1/35.555
   * Referenced by: '<S3>/Gain2'
   */
  0.028125439459991564,

  /* Expression: 1/60
   * Referenced by: '<S3>/Gain3'
   */
  0.016666666666666666,

  /* Expression: 0
   * Referenced by: '<Root>/DT Fast Loop'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/DT'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<Root>/tau'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S8>/Gain'
   */
  57.295779513082323,

  /* Expression: 1.05
   * Referenced by: '<Root>/D1_GAIN'
   */
  1.05,

  /* Expression: [-4.945, 8.862, -3.967]
   * Referenced by: '<Root>/D1 Inner Loop Controller'
   */
  { -4.945, 8.862, -3.967 },

  /* Expression: [1.000, -1.481, 0.4812]
   * Referenced by: '<Root>/D1 Inner Loop Controller'
   */
  { 1.0, -1.481, 0.4812 },

  /* Expression: 0
   * Referenced by: '<Root>/D1 Inner Loop Controller'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S4>/Gain'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<S4>/MOTOR_POLARITY_L'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S4>/MOTOR_POLARITY_R'
   */
  -1.0,

  /* Expression: 20
   * Referenced by: '<Root>/phi Ref'
   */
  20.0,

  /* Expression: 0.9
   * Referenced by: '<Root>/D2_GAIN'
   */
  0.9,

  /* Expression: [0.18856,  -0.37209,  0.18354]
   * Referenced by: '<Root>/D2 Outer Loop Controller'
   */
  { 0.18856, -0.37209, 0.18354 },

  /* Expression: [1.00000,  -1.86046,   0.86046]
   * Referenced by: '<Root>/D2 Outer Loop Controller'
   */
  { 1.0, -1.86046, 0.86046 },

  /* Expression: 0
   * Referenced by: '<Root>/D2 Outer Loop Controller'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S6>/Gain1'
   */
  0.017453292519943295,

  /* Computed Parameter: Gain_Gain_a
   * Referenced by: '<S3>/Gain'
   */
  { { 0UL, 0x40000000UL } },

  /* Computed Parameter: ENCODER_POLARITY_R_Gain
   * Referenced by: '<S3>/ENCODER_POLARITY_R'
   */
  MIN_int32_T,

  /* Computed Parameter: ENCODER_POLARITY_L_Gain
   * Referenced by: '<S3>/ENCODER_POLARITY_L'
   */
  1073741824
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
