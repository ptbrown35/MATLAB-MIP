/*
 * fccr_balance1_types.h
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

#ifndef RTW_HEADER_fccr_balance1_types_h_
#define RTW_HEADER_fccr_balance1_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
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

#ifndef typedef_beagleboneblue_fccr_bbblueIMU_T
#define typedef_beagleboneblue_fccr_bbblueIMU_T

typedef struct {
  int32_T isInitialized;
  real_T SampleTime;
} beagleboneblue_fccr_bbblueIMU_T;

#endif                                 /*typedef_beagleboneblue_fccr_bbblueIMU_T*/

#ifndef typedef_beagleboneblue_bbblueEncoder__T
#define typedef_beagleboneblue_bbblueEncoder__T

typedef struct {
  int32_T isInitialized;
  real_T SampleTime;
} beagleboneblue_bbblueEncoder__T;

#endif                                 /*typedef_beagleboneblue_bbblueEncoder__T*/

#ifndef typedef_cell_wrap_fccr_balance1_T
#define typedef_cell_wrap_fccr_balance1_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_fccr_balance1_T;

#endif                                 /*typedef_cell_wrap_fccr_balance1_T*/

#ifndef typedef_beagleboneblue_bbblueDCMotor__T
#define typedef_beagleboneblue_bbblueDCMotor__T

typedef struct {
  int32_T isInitialized;
  cell_wrap_fccr_balance1_T inputVarSize;
} beagleboneblue_bbblueDCMotor__T;

#endif                                 /*typedef_beagleboneblue_bbblueDCMotor__T*/

/* Parameters (auto storage) */
typedef struct P_fccr_balance1_T_ P_fccr_balance1_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_fccr_balance1_T RT_MODEL_fccr_balance1_T;

#endif                                 /* RTW_HEADER_fccr_balance1_types_h_ */
