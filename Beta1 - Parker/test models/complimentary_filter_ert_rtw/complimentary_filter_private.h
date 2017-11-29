/*
 * complimentary_filter_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "complimentary_filter".
 *
 * Model version              : 1.178
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Nov 29 14:50:04 2017
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_complimentary_filter_private_h_
#define RTW_HEADER_complimentary_filter_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "complimentary_filter.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void complimentary_filter_step0(void);
extern void complimentary_filter_step1(void);

#endif                                 /* RTW_HEADER_complimentary_filter_private_h_ */
