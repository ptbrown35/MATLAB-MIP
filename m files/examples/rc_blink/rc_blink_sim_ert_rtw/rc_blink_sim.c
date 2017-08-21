/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rc_blink_sim.c
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

#include "rc_blink_sim.h"
#include "rc_blink_sim_private.h"
#include "rc_blink_sim_dt.h"

/* Block signals (auto storage) */
B_rc_blink_sim_T rc_blink_sim_B;

/* Block states (auto storage) */
DW_rc_blink_sim_T rc_blink_sim_DW;

/* Real-time model */
RT_MODEL_rc_blink_sim_T rc_blink_sim_M_;
RT_MODEL_rc_blink_sim_T *const rc_blink_sim_M = &rc_blink_sim_M_;

/*
 * Start for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 */
void rc_blink_si_MATLABSystem5_Start(DW_MATLABSystem5_rc_blink_sim_T *localDW,
  P_MATLABSystem5_rc_blink_sim_T *localP)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System5' */
  localDW->obj.isInitialized = 0;
  localDW->objisempty = true;
  localDW->obj.led = localP->MATLABSystem5_led;
  localDW->obj.isInitialized = 1;
}

/*
 * Output and update for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 */
void rc_blink_sim_MATLABSystem5(B_MATLABSystem5_rc_blink_sim_T *localB,
  DW_MATLABSystem5_rc_blink_sim_T *localDW, P_MATLABSystem5_rc_blink_sim_T
  *localP)
{
  boolean_T p;
  boolean_T p_0;

  /* Start for MATLABSystem: '<Root>/MATLAB System5' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System5'
   */
  p = false;
  p_0 = true;
  if (!(localDW->obj.led == localP->MATLABSystem5_led)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    localDW->obj.led = localP->MATLABSystem5_led;
  }

  /* MATLABSystem: '<Root>/MATLAB System5' incorporates:
   *  Start for MATLABSystem: '<Root>/MATLAB System5'
   */
  localB->MATLABSystem5 = rc_get_led(localDW->obj.led);
}

/*
 * Termination for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 */
void rc_blink_sim_MATLABSystem5_Term(DW_MATLABSystem5_rc_blink_sim_T *localDW)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System5' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System5'
   */
  if (localDW->obj.isInitialized == 1) {
    localDW->obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System5' */
}

/*
 * Start for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 */
void rc_blink_si_MATLABSystem3_Start(DW_MATLABSystem3_rc_blink_sim_T *localDW,
  P_MATLABSystem3_rc_blink_sim_T *localP)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System3' */
  localDW->obj.isInitialized = 0;
  localDW->objisempty = true;
  localDW->obj.led = localP->MATLABSystem3_led;
  localDW->obj.isInitialized = 1;
}

/*
 * Output and update for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 */
void rc_blink_sim_MATLABSystem3(uint8_T rtu_0, B_MATLABSystem3_rc_blink_sim_T
  *localB, DW_MATLABSystem3_rc_blink_sim_T *localDW,
  P_MATLABSystem3_rc_blink_sim_T *localP)
{
  boolean_T p;
  boolean_T p_0;

  /* Start for MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System3'
   */
  p = false;
  p_0 = true;
  if (!(localDW->obj.led == localP->MATLABSystem3_led)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    localDW->obj.led = localP->MATLABSystem3_led;
  }

  /* MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  Start for MATLABSystem: '<Root>/MATLAB System3'
   */
  localB->MATLABSystem3 = rc_set_led(localDW->obj.led, rtu_0);
}

/*
 * Termination for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 */
void rc_blink_sim_MATLABSystem3_Term(DW_MATLABSystem3_rc_blink_sim_T *localDW)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System3'
   */
  if (localDW->obj.isInitialized == 1) {
    localDW->obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System3' */
}

/* Model step function */
void rc_blink_sim_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_Compare;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  Sin: '<Root>/Sine Wave'
   */
  rc_blink_sim_B.Compare = (uint8_T)(sin(((real_T)rc_blink_sim_DW.counter +
    rc_blink_sim_P.SineWave_Offset) * 2.0 * 3.1415926535897931 /
    rc_blink_sim_P.SineWave_NumSamp) * rc_blink_sim_P.SineWave_Amp +
    rc_blink_sim_P.SineWave_Bias <= rc_blink_sim_P.Constant_Value);
  rc_blink_sim_MATLABSystem3(rc_blink_sim_B.Compare,
    &rc_blink_sim_B.MATLABSystem1, &rc_blink_sim_DW.MATLABSystem1,
    (P_MATLABSystem3_rc_blink_sim_T *)&rc_blink_sim_P.MATLABSystem1);

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Compare = (uint8_T)(rc_blink_sim_B.Compare ==
    rc_blink_sim_P.Constant_Value_n);
  rc_blink_sim_MATLABSystem3(rtb_Compare, &rc_blink_sim_B.MATLABSystem3,
    &rc_blink_sim_DW.MATLABSystem3, (P_MATLABSystem3_rc_blink_sim_T *)
    &rc_blink_sim_P.MATLABSystem3);
  rc_blink_sim_MATLABSystem5(&rc_blink_sim_B.MATLABSystem4,
    &rc_blink_sim_DW.MATLABSystem4, (P_MATLABSystem5_rc_blink_sim_T *)
    &rc_blink_sim_P.MATLABSystem4);
  rc_blink_sim_MATLABSystem5(&rc_blink_sim_B.MATLABSystem5,
    &rc_blink_sim_DW.MATLABSystem5, (P_MATLABSystem5_rc_blink_sim_T *)
    &rc_blink_sim_P.MATLABSystem5);

  /* Update for Sin: '<Root>/Sine Wave' */
  rc_blink_sim_DW.counter++;
  if (rc_blink_sim_DW.counter == rc_blink_sim_P.SineWave_NumSamp) {
    rc_blink_sim_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, rc_blink_sim_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(rc_blink_sim_M)!=-1) &&
        !((rtmGetTFinal(rc_blink_sim_M)-rc_blink_sim_M->Timing.taskTime0) >
          rc_blink_sim_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(rc_blink_sim_M, "Simulation finished");
    }

    if (rtmGetStopRequested(rc_blink_sim_M)) {
      rtmSetErrorStatus(rc_blink_sim_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rc_blink_sim_M->Timing.taskTime0 =
    (++rc_blink_sim_M->Timing.clockTick0) * rc_blink_sim_M->Timing.stepSize0;
}

/* Model initialize function */
void rc_blink_sim_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)rc_blink_sim_M, 0,
                sizeof(RT_MODEL_rc_blink_sim_T));
  rtmSetTFinal(rc_blink_sim_M, 30.0);
  rc_blink_sim_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  rc_blink_sim_M->Sizes.checksums[0] = (1679535820U);
  rc_blink_sim_M->Sizes.checksums[1] = (1857826624U);
  rc_blink_sim_M->Sizes.checksums[2] = (1336751227U);
  rc_blink_sim_M->Sizes.checksums[3] = (3778018303U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    rc_blink_sim_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(rc_blink_sim_M->extModeInfo,
      &rc_blink_sim_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(rc_blink_sim_M->extModeInfo,
                        rc_blink_sim_M->Sizes.checksums);
    rteiSetTPtr(rc_blink_sim_M->extModeInfo, rtmGetTPtr(rc_blink_sim_M));
  }

  /* block I/O */
  (void) memset(((void *) &rc_blink_sim_B), 0,
                sizeof(B_rc_blink_sim_T));

  /* states (dwork) */
  (void) memset((void *)&rc_blink_sim_DW, 0,
                sizeof(DW_rc_blink_sim_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    rc_blink_sim_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  rc_blink_si_MATLABSystem3_Start(&rc_blink_sim_DW.MATLABSystem1,
    (P_MATLABSystem3_rc_blink_sim_T *)&rc_blink_sim_P.MATLABSystem1);
  rc_blink_si_MATLABSystem3_Start(&rc_blink_sim_DW.MATLABSystem3,
    (P_MATLABSystem3_rc_blink_sim_T *)&rc_blink_sim_P.MATLABSystem3);
  rc_blink_si_MATLABSystem5_Start(&rc_blink_sim_DW.MATLABSystem4,
    (P_MATLABSystem5_rc_blink_sim_T *)&rc_blink_sim_P.MATLABSystem4);
  rc_blink_si_MATLABSystem5_Start(&rc_blink_sim_DW.MATLABSystem5,
    (P_MATLABSystem5_rc_blink_sim_T *)&rc_blink_sim_P.MATLABSystem5);

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  rc_blink_sim_DW.obj.isInitialized = 0;
  rc_blink_sim_DW.obj.isInitialized = 1;
  rc_initialize();

  /* Start for MATLABSystem: '<Root>/MATLAB System2' */
  rc_blink_sim_DW.obj_h.isInitialized = 0;
  rc_blink_sim_DW.obj_h.isInitialized = 1;

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  rc_blink_sim_DW.counter = 0;
}

/* Model terminate function */
void rc_blink_sim_terminate(void)
{
  rc_blink_sim_MATLABSystem3_Term(&rc_blink_sim_DW.MATLABSystem1);
  rc_blink_sim_MATLABSystem3_Term(&rc_blink_sim_DW.MATLABSystem3);
  rc_blink_sim_MATLABSystem5_Term(&rc_blink_sim_DW.MATLABSystem4);
  rc_blink_sim_MATLABSystem5_Term(&rc_blink_sim_DW.MATLABSystem5);

  /* Start for MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System'
   */
  if (rc_blink_sim_DW.obj.isInitialized == 1) {
    rc_blink_sim_DW.obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System' */

  /* Start for MATLABSystem: '<Root>/MATLAB System2' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System2'
   */
  if (rc_blink_sim_DW.obj_h.isInitialized == 1) {
    rc_blink_sim_DW.obj_h.isInitialized = 2;
    rc_cleanup();
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
