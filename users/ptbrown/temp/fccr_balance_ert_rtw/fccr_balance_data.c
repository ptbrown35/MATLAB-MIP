/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fccr_balance_data.c
 *
 * Code generated for Simulink model 'fccr_balance'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Nov 14 01:15:17 2017
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

  /* Expression: 0.005
   * Referenced by: '<Root>/MATLAB System'
   */
  0.005,

  /* Expression: 22.9
   * Referenced by: '<Root>/Theta Ref (Deg)'
   */
  22.9,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0.005
   * Referenced by: '<S1>/dt'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<S1>/tau'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S7>/tau'
   */
  1.0,

  /* Expression: 0.005
   * Referenced by: '<S7>/dt'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S3>/Gain1'
   */
  0.017453292519943295,

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
   * Referenced by: '<S2>/Constant'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
