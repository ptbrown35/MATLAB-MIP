/*
 * complimentary_filter_dt.h
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
  sizeof(beagleboneblue_bbblueButton_c_T),
  sizeof(beagleboneblue_bbblueLED_comp_T),
  sizeof(beagleboneblue_fccr_bbblueIMU_T)
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
  "beagleboneblue_bbblueButton_c_T",
  "beagleboneblue_bbblueLED_comp_T",
  "beagleboneblue_fccr_bbblueIMU_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&complimentary_filter_B.ThetaAccel), 0, 0, 11 }
  ,

  { (char_T *)(&complimentary_filter_DW.obj), 14, 0, 1 },

  { (char_T *)(&complimentary_filter_DW.obj_f), 16, 0, 1 },

  { (char_T *)(&complimentary_filter_DW.DiscreteTransferFcn_states), 0, 0, 3 },

  { (char_T *)(&complimentary_filter_DW.Scope_PWORK.LoggedData[0]), 11, 0, 3 },

  { (char_T *)(&complimentary_filter_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&complimentary_filter_DW.obj_p), 15, 0, 1 },

  { (char_T *)(&complimentary_filter_DW.objisempty), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&complimentary_filter_P.MATLABSystem_SampleTime), 0, 0, 15 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] complimentary_filter_dt.h */
