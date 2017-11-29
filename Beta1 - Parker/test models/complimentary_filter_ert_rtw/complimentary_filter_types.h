/*
 * complimentary_filter_types.h
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

#ifndef RTW_HEADER_complimentary_filter_types_h_
#define RTW_HEADER_complimentary_filter_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_beagleboneblue_fccr_bbblueIMU_T
#define typedef_beagleboneblue_fccr_bbblueIMU_T

typedef struct {
  int32_T isInitialized;
  real_T SampleTime;
} beagleboneblue_fccr_bbblueIMU_T;

#endif                                 /*typedef_beagleboneblue_fccr_bbblueIMU_T*/

#ifndef typedef_beagleboneblue_bbblueLED_comp_T
#define typedef_beagleboneblue_bbblueLED_comp_T

typedef struct {
  int32_T isInitialized;
} beagleboneblue_bbblueLED_comp_T;

#endif                                 /*typedef_beagleboneblue_bbblueLED_comp_T*/

#ifndef typedef_beagleboneblue_bbblueButton_c_T
#define typedef_beagleboneblue_bbblueButton_c_T

typedef struct {
  int32_T isInitialized;
  real_T SampleTime;
} beagleboneblue_bbblueButton_c_T;

#endif                                 /*typedef_beagleboneblue_bbblueButton_c_T*/

/* Parameters (auto storage) */
typedef struct P_complimentary_filter_T_ P_complimentary_filter_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_complimentary_filter_T RT_MODEL_complimentary_filter_T;

#endif                                 /* RTW_HEADER_complimentary_filter_types_h_ */
