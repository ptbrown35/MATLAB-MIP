/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fccr_balance_private.h
 *
 * Code generated for Simulink model 'fccr_balance'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Nov  2 16:32:26 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_fccr_balance_private_h_
#define RTW_HEADER_fccr_balance_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "fccr_balance.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void fccr_balance_step0(void);
extern void fccr_balance_step1(void);

#endif                                 /* RTW_HEADER_fccr_balance_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
