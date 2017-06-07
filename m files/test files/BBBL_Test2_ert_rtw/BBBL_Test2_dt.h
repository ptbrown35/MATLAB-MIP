/*
 * BBBL_Test2_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "BBBL_Test2".
 *
 * Model version              : 1.85
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Tue Jun 06 20:44:06 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(rc_blink_sys_BBBL_Test2_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "rc_blink_sys_BBBL_Test2_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&BBBL_Test2_B.b2), 0, 0, 2 },

  { (char_T *)(&BBBL_Test2_B.Output), 3, 0, 2 }
  ,

  { (char_T *)(&BBBL_Test2_DW.u0_PWORK.LoggedData), 11, 0, 5 },

  { (char_T *)(&BBBL_Test2_DW.obj), 14, 0, 1 },

  { (char_T *)(&BBBL_Test2_DW.Output_DSTATE), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&BBBL_Test2_P.CompareToConstant1_const), 0, 0, 1 },

  { (char_T *)(&BBBL_Test2_P.CompareToConstant_const), 3, 0, 2 },

  { (char_T *)(&BBBL_Test2_P.b2_Gain), 0, 0, 3 },

  { (char_T *)(&BBBL_Test2_P.Constant_Value), 3, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] BBBL_Test2_dt.h */
