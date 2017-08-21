/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rc_blink_sim_types.h
 *
 * Code generated for Simulink model 'rc_blink_sim'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Aug 20 19:41:28 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rc_blink_sim_types_h_
#define RTW_HEADER_rc_blink_sim_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_rc_get_led_sys_rc_blink_sim_T
#define typedef_rc_get_led_sys_rc_blink_sim_T

typedef struct {
  int32_T isInitialized;
  real_T led;
} rc_get_led_sys_rc_blink_sim_T;

#endif                                 /*typedef_rc_get_led_sys_rc_blink_sim_T*/

#ifndef typedef_struct_T_rc_blink_sim_T
#define typedef_struct_T_rc_blink_sim_T

typedef struct {
  real_T f1[2];
} struct_T_rc_blink_sim_T;

#endif                                 /*typedef_struct_T_rc_blink_sim_T*/

#ifndef typedef_rc_cleanup_sys_rc_blink_sim_T
#define typedef_rc_cleanup_sys_rc_blink_sim_T

typedef struct {
  int32_T isInitialized;
} rc_cleanup_sys_rc_blink_sim_T;

#endif                                 /*typedef_rc_cleanup_sys_rc_blink_sim_T*/

#ifndef typedef_rc_initialize_sys_rc_blink_si_T
#define typedef_rc_initialize_sys_rc_blink_si_T

typedef struct {
  int32_T isInitialized;
} rc_initialize_sys_rc_blink_si_T;

#endif                                 /*typedef_rc_initialize_sys_rc_blink_si_T*/

/* Parameters for system: '<Root>/MATLAB System5' */
typedef struct P_MATLABSystem5_rc_blink_sim_T_ P_MATLABSystem5_rc_blink_sim_T;

/* Parameters for system: '<Root>/MATLAB System3' */
typedef struct P_MATLABSystem3_rc_blink_sim_T_ P_MATLABSystem3_rc_blink_sim_T;

/* Parameters (auto storage) */
typedef struct P_rc_blink_sim_T_ P_rc_blink_sim_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_rc_blink_sim_T RT_MODEL_rc_blink_sim_T;

#endif                                 /* RTW_HEADER_rc_blink_sim_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
