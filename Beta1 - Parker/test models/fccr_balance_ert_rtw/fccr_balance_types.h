/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fccr_balance_types.h
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

#ifndef RTW_HEADER_fccr_balance_types_h_
#define RTW_HEADER_fccr_balance_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_beagleboneblue_fccr_bbblueIMU_T
#define typedef_beagleboneblue_fccr_bbblueIMU_T

typedef struct {
  int32_T isInitialized;
  real_T SampleTime;
} beagleboneblue_fccr_bbblueIMU_T;

#endif                                 /*typedef_beagleboneblue_fccr_bbblueIMU_T*/

#ifndef typedef_beagleboneblue_bbblueLED_fccr_T
#define typedef_beagleboneblue_bbblueLED_fccr_T

typedef struct {
  int32_T isInitialized;
} beagleboneblue_bbblueLED_fccr_T;

#endif                                 /*typedef_beagleboneblue_bbblueLED_fccr_T*/

#ifndef typedef_beagleboneblue_bbblueButton_f_T
#define typedef_beagleboneblue_bbblueButton_f_T

typedef struct {
  int32_T isInitialized;
  real_T SampleTime;
} beagleboneblue_bbblueButton_f_T;

#endif                                 /*typedef_beagleboneblue_bbblueButton_f_T*/

/* Parameters (auto storage) */
typedef struct P_fccr_balance_T_ P_fccr_balance_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_fccr_balance_T RT_MODEL_fccr_balance_T;

#endif                                 /* RTW_HEADER_fccr_balance_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
