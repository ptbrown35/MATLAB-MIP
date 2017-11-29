/*
 * fccr_balance1_dt.h
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
  sizeof(uint256m_T),
  sizeof(int288m_T),
  sizeof(uint288m_T),
  sizeof(int320m_T),
  sizeof(uint320m_T),
  sizeof(int352m_T),
  sizeof(uint352m_T),
  sizeof(int384m_T),
  sizeof(uint384m_T),
  sizeof(int416m_T),
  sizeof(uint416m_T),
  sizeof(int448m_T),
  sizeof(uint448m_T),
  sizeof(int480m_T),
  sizeof(uint480m_T),
  sizeof(int512m_T),
  sizeof(uint512m_T),
  sizeof(int544m_T),
  sizeof(uint544m_T),
  sizeof(int576m_T),
  sizeof(uint576m_T),
  sizeof(int608m_T),
  sizeof(uint608m_T),
  sizeof(int640m_T),
  sizeof(uint640m_T),
  sizeof(int672m_T),
  sizeof(uint672m_T),
  sizeof(int704m_T),
  sizeof(uint704m_T),
  sizeof(int736m_T),
  sizeof(uint736m_T),
  sizeof(int768m_T),
  sizeof(uint768m_T),
  sizeof(int800m_T),
  sizeof(uint800m_T),
  sizeof(int832m_T),
  sizeof(uint832m_T),
  sizeof(int864m_T),
  sizeof(uint864m_T),
  sizeof(int896m_T),
  sizeof(uint896m_T),
  sizeof(int928m_T),
  sizeof(uint928m_T),
  sizeof(int960m_T),
  sizeof(uint960m_T),
  sizeof(int992m_T),
  sizeof(uint992m_T),
  sizeof(int1024m_T),
  sizeof(uint1024m_T),
  sizeof(int1056m_T),
  sizeof(uint1056m_T),
  sizeof(int1088m_T),
  sizeof(uint1088m_T),
  sizeof(int1120m_T),
  sizeof(uint1120m_T),
  sizeof(int1152m_T),
  sizeof(uint1152m_T),
  sizeof(int1184m_T),
  sizeof(uint1184m_T),
  sizeof(int1216m_T),
  sizeof(uint1216m_T),
  sizeof(int1248m_T),
  sizeof(uint1248m_T),
  sizeof(int1280m_T),
  sizeof(uint1280m_T),
  sizeof(int1312m_T),
  sizeof(uint1312m_T),
  sizeof(int1344m_T),
  sizeof(uint1344m_T),
  sizeof(int1376m_T),
  sizeof(uint1376m_T),
  sizeof(int1408m_T),
  sizeof(uint1408m_T),
  sizeof(int1440m_T),
  sizeof(uint1440m_T),
  sizeof(int1472m_T),
  sizeof(uint1472m_T),
  sizeof(int1504m_T),
  sizeof(uint1504m_T),
  sizeof(int1536m_T),
  sizeof(uint1536m_T),
  sizeof(int1568m_T),
  sizeof(uint1568m_T),
  sizeof(int1600m_T),
  sizeof(uint1600m_T),
  sizeof(int1632m_T),
  sizeof(uint1632m_T),
  sizeof(int1664m_T),
  sizeof(uint1664m_T),
  sizeof(int1696m_T),
  sizeof(uint1696m_T),
  sizeof(int1728m_T),
  sizeof(uint1728m_T),
  sizeof(int1760m_T),
  sizeof(uint1760m_T),
  sizeof(int1792m_T),
  sizeof(uint1792m_T),
  sizeof(int1824m_T),
  sizeof(uint1824m_T),
  sizeof(int1856m_T),
  sizeof(uint1856m_T),
  sizeof(int1888m_T),
  sizeof(uint1888m_T),
  sizeof(int1920m_T),
  sizeof(uint1920m_T),
  sizeof(int1952m_T),
  sizeof(uint1952m_T),
  sizeof(int1984m_T),
  sizeof(uint1984m_T),
  sizeof(int2016m_T),
  sizeof(uint2016m_T),
  sizeof(int2048m_T),
  sizeof(uint2048m_T)
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
  "uint256m_T",
  "int288m_T",
  "uint288m_T",
  "int320m_T",
  "uint320m_T",
  "int352m_T",
  "uint352m_T",
  "int384m_T",
  "uint384m_T",
  "int416m_T",
  "uint416m_T",
  "int448m_T",
  "uint448m_T",
  "int480m_T",
  "uint480m_T",
  "int512m_T",
  "uint512m_T",
  "int544m_T",
  "uint544m_T",
  "int576m_T",
  "uint576m_T",
  "int608m_T",
  "uint608m_T",
  "int640m_T",
  "uint640m_T",
  "int672m_T",
  "uint672m_T",
  "int704m_T",
  "uint704m_T",
  "int736m_T",
  "uint736m_T",
  "int768m_T",
  "uint768m_T",
  "int800m_T",
  "uint800m_T",
  "int832m_T",
  "uint832m_T",
  "int864m_T",
  "uint864m_T",
  "int896m_T",
  "uint896m_T",
  "int928m_T",
  "uint928m_T",
  "int960m_T",
  "uint960m_T",
  "int992m_T",
  "uint992m_T",
  "int1024m_T",
  "uint1024m_T",
  "int1056m_T",
  "uint1056m_T",
  "int1088m_T",
  "uint1088m_T",
  "int1120m_T",
  "uint1120m_T",
  "int1152m_T",
  "uint1152m_T",
  "int1184m_T",
  "uint1184m_T",
  "int1216m_T",
  "uint1216m_T",
  "int1248m_T",
  "uint1248m_T",
  "int1280m_T",
  "uint1280m_T",
  "int1312m_T",
  "uint1312m_T",
  "int1344m_T",
  "uint1344m_T",
  "int1376m_T",
  "uint1376m_T",
  "int1408m_T",
  "uint1408m_T",
  "int1440m_T",
  "uint1440m_T",
  "int1472m_T",
  "uint1472m_T",
  "int1504m_T",
  "uint1504m_T",
  "int1536m_T",
  "uint1536m_T",
  "int1568m_T",
  "uint1568m_T",
  "int1600m_T",
  "uint1600m_T",
  "int1632m_T",
  "uint1632m_T",
  "int1664m_T",
  "uint1664m_T",
  "int1696m_T",
  "uint1696m_T",
  "int1728m_T",
  "uint1728m_T",
  "int1760m_T",
  "uint1760m_T",
  "int1792m_T",
  "uint1792m_T",
  "int1824m_T",
  "uint1824m_T",
  "int1856m_T",
  "uint1856m_T",
  "int1888m_T",
  "uint1888m_T",
  "int1920m_T",
  "uint1920m_T",
  "int1952m_T",
  "uint1952m_T",
  "int1984m_T",
  "uint1984m_T",
  "int2016m_T",
  "uint2016m_T",
  "int2048m_T",
  "uint2048m_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&fccr_balance1_B.thetaRefrad), 0, 0, 14 }
  ,

  { (char_T *)(&fccr_balance1_DW.obj), 23, 0, 2 },

  { (char_T *)(&fccr_balance1_DW.obj_b), 19, 0, 1 },

  { (char_T *)(&fccr_balance1_DW.obj_e), 20, 0, 1 },

  { (char_T *)(&fccr_balance1_DW.obj_i), 21, 0, 2 },

  { (char_T *)(&fccr_balance1_DW.FirstOrderFilterLowPass_states), 0, 0, 8 },

  { (char_T *)(&fccr_balance1_DW.phi_PWORK.LoggedData[0]), 11, 0, 5 },

  { (char_T *)(&fccr_balance1_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&fccr_balance1_DW.obj_p), 22, 0, 1 },

  { (char_T *)(&fccr_balance1_DW.objisempty), 8, 0, 7 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&fccr_balance1_P.Button_SampleTime), 0, 0, 44 },

  { (char_T *)(&fccr_balance1_P.Gain_Gain_p), 18, 0, 1 },

  { (char_T *)(&fccr_balance1_P.ENCODER_POLARITY_R_Gain), 14, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] fccr_balance1_dt.h */
