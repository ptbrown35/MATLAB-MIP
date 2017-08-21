/*
 * rc_blink_sim_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rc_blink_sim".
 *
 * Model version              : 1.19
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Aug 14 21:54:00 2017
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
  sizeof(rc_initialize_sys_rc_blink_si_T),
  sizeof(rc_get_led_sys_rc_blink_sim_T),
  sizeof(rc_cleanup_sys_rc_blink_sim_T),
  sizeof(rc_get_led_sys_rc_blink_sim_T)
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
  "rc_initialize_sys_rc_blink_si_T",
  "rc_get_led_sys_rc_blink_sim_T",
  "rc_cleanup_sys_rc_blink_sim_T",
  "rc_get_led_sys_rc_blink_sim_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&rc_blink_sim_B.Compare), 3, 0, 1 },

  { (char_T *)(&rc_blink_sim_B.MATLABSystem1.MATLABSystem3), 2, 0, 1 },

  { (char_T *)(&rc_blink_sim_B.MATLABSystem3.MATLABSystem3), 2, 0, 1 },

  { (char_T *)(&rc_blink_sim_B.MATLABSystem4.MATLABSystem5), 2, 0, 1 },

  { (char_T *)(&rc_blink_sim_B.MATLABSystem5.MATLABSystem5), 2, 0, 1 }
  ,

  { (char_T *)(&rc_blink_sim_DW.Input_PWORK.LoggedData), 11, 0, 7 },

  { (char_T *)(&rc_blink_sim_DW.counter), 6, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.obj), 14, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.obj_h), 16, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem1.obj), 15, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem1.MATLABSystem3_PWORK), 11, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem1.objisempty), 8, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem3.obj), 15, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem3.MATLABSystem3_PWORK), 11, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem3.objisempty), 8, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem4.obj), 17, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem4.MATLABSystem5_PWORK), 11, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem4.objisempty), 8, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem5.obj), 17, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem5.MATLABSystem5_PWORK), 11, 0, 1 },

  { (char_T *)(&rc_blink_sim_DW.MATLABSystem5.objisempty), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  21U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&rc_blink_sim_P.SineWave_Amp), 0, 0, 5 },

  { (char_T *)(&rc_blink_sim_P.Constant_Value_n), 3, 0, 1 },

  { (char_T *)(&rc_blink_sim_P.MATLABSystem1.MATLABSystem3_led), 0, 0, 1 },

  { (char_T *)(&rc_blink_sim_P.MATLABSystem3.MATLABSystem3_led), 0, 0, 1 },

  { (char_T *)(&rc_blink_sim_P.MATLABSystem4.MATLABSystem5_led), 0, 0, 1 },

  { (char_T *)(&rc_blink_sim_P.MATLABSystem5.MATLABSystem5_led), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] rc_blink_sim_dt.h */
