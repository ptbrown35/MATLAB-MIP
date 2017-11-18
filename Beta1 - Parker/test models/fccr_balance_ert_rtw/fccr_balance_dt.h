/*
 * fccr_balance_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "fccr_balance".
 *
 * Model version              : 1.93
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Nov 17 19:12:57 2017
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
  sizeof(int32_T),
  sizeof(int64m_T),
  sizeof(int32_T),
  sizeof(int64m_T),
  sizeof(int64m_T),
  sizeof(beagleboneblue_bbblueButton_f_T),
  sizeof(beagleboneblue_fccr_bbblueIMU_T),
  sizeof(beagleboneblue_bbblueEncoder__T),
  sizeof(beagleboneblue_bbblueLED_fccr_T),
  sizeof(beagleboneblue_bbblueDCMotor__T),
  sizeof(int64m_T),
  sizeof(uint64m_T),
  sizeof(int96m_T),
  sizeof(uint96m_T),
  sizeof(int128m_T),
  sizeof(uint128m_T),
  sizeof(int160m_T),
  sizeof(uint160m_T),
  sizeof(int192m_T),
  sizeof(uint192m_T),
  sizeof(int224m_T),
  sizeof(uint224m_T),
  sizeof(int256m_T),
  sizeof(uint256m_T)
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
  "int32_T",
  "int64m_T",
  "int32_T",
  "int64m_T",
  "int64m_T",
  "beagleboneblue_bbblueButton_f_T",
  "beagleboneblue_fccr_bbblueIMU_T",
  "beagleboneblue_bbblueEncoder__T",
  "beagleboneblue_bbblueLED_fccr_T",
  "beagleboneblue_bbblueDCMotor__T",
  "int64m_T",
  "uint64m_T",
  "int96m_T",
  "uint96m_T",
  "int128m_T",
  "uint128m_T",
  "int160m_T",
  "uint160m_T",
  "int192m_T",
  "uint192m_T",
  "int224m_T",
  "uint224m_T",
  "int256m_T",
  "uint256m_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&fccr_balance_B.Gain3), 0, 0, 5 },

  { (char_T *)(&fccr_balance_B.DataTypeConversion), 2, 0, 1 }
  ,

  { (char_T *)(&fccr_balance_DW.obj), 23, 0, 2 },

  { (char_T *)(&fccr_balance_DW.obj_a), 19, 0, 1 },

  { (char_T *)(&fccr_balance_DW.obj_d), 20, 0, 1 },

  { (char_T *)(&fccr_balance_DW.obj_o), 21, 0, 2 },

  { (char_T *)(&fccr_balance_DW.UnitDelay_DSTATE), 0, 0, 9 },

  { (char_T *)(&fccr_balance_DW.Encoder_PWORK.LoggedData), 11, 0, 4 },

  { (char_T *)(&fccr_balance_DW.counter), 6, 0, 1 },

  { (char_T *)(&fccr_balance_DW.obj_p), 22, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&fccr_balance_P.Button_SampleTime), 0, 0, 44 },

  { (char_T *)(&fccr_balance_P.Gain_Gain_a), 18, 0, 1 },

  { (char_T *)(&fccr_balance_P.ENCODER_POLARITY_R_Gain), 14, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] fccr_balance_dt.h */
