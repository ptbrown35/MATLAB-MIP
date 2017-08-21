/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rc_blink_sim_private.h
 *
 * Code generated for Simulink model 'rc_blink_sim'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Aug 14 21:54:00 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rc_blink_sim_private_h_
#define RTW_HEADER_rc_blink_sim_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rc_blink_sim.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void rc_blink_si_MATLABSystem5_Start(DW_MATLABSystem5_rc_blink_sim_T
  *localDW, P_MATLABSystem5_rc_blink_sim_T *localP);
extern void rc_blink_sim_MATLABSystem5(B_MATLABSystem5_rc_blink_sim_T *localB,
  DW_MATLABSystem5_rc_blink_sim_T *localDW, P_MATLABSystem5_rc_blink_sim_T
  *localP);
extern void rc_blink_si_MATLABSystem3_Start(DW_MATLABSystem3_rc_blink_sim_T
  *localDW, P_MATLABSystem3_rc_blink_sim_T *localP);
extern void rc_blink_sim_MATLABSystem3(uint8_T rtu_0,
  B_MATLABSystem3_rc_blink_sim_T *localB, DW_MATLABSystem3_rc_blink_sim_T
  *localDW, P_MATLABSystem3_rc_blink_sim_T *localP);
extern void rc_blink_sim_MATLABSystem5_Term(DW_MATLABSystem5_rc_blink_sim_T
  *localDW);
extern void rc_blink_sim_MATLABSystem3_Term(DW_MATLABSystem3_rc_blink_sim_T
  *localDW);

#endif                                 /* RTW_HEADER_rc_blink_sim_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
