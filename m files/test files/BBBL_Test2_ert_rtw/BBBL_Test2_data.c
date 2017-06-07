/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BBBL_Test2_data.c
 *
 * Code generated for Simulink model 'BBBL_Test2'.
 *
 * Model version                  : 1.85
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Jun 06 20:44:06 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BBBL_Test2.h"
#include "BBBL_Test2_private.h"

/* Block parameters (auto storage) */
P_BBBL_Test2_T BBBL_Test2_P = {
  30.0,                                /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  20U,                                 /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  40U,                                 /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S5>/FixPt Switch'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/b2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<Root>/a'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S3>/Output'
                                        */
  1U                                   /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S4>/FixPt Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
