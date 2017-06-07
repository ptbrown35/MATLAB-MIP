/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rc_blink_sim2.c
 *
 * Code generated for Simulink model 'rc_blink_sim2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Jun 06 20:48:21 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rc_blink_sim2.h"
#include "rc_blink_sim2_private.h"
#include "rc_blink_sim2_dt.h"
#define rc_blink_sim2_rc_led_t         (1.0)

/* Block signals (auto storage) */
B_rc_blink_sim2_T rc_blink_sim2_B;

/* Block states (auto storage) */
DW_rc_blink_sim2_T rc_blink_sim2_DW;

/* Real-time model */
RT_MODEL_rc_blink_sim2_T rc_blink_sim2_M_;
RT_MODEL_rc_blink_sim2_T *const rc_blink_sim2_M = &rc_blink_sim2_M_;

/* Model step function */
void rc_blink_sim2_step(void)
{
  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  Sin: '<Root>/Sine Wave'
   */
  rc_blink_sim2_B.Compare = (uint8_T)(sin(((real_T)rc_blink_sim2_DW.counter +
    rc_blink_sim2_P.SineWave_Offset) * 2.0 * 3.1415926535897931 /
    rc_blink_sim2_P.SineWave_NumSamp) * rc_blink_sim2_P.SineWave_Amp +
    rc_blink_sim2_P.SineWave_Bias <= rc_blink_sim2_P.Constant_Value);

  /* Start for MATLABSystem: '<Root>/MATLAB System1' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System1'
   */
  rc_set_led(rc_blink_sim2_rc_led_t, rc_blink_sim2_B.Compare);

  /* Update for Sin: '<Root>/Sine Wave' */
  rc_blink_sim2_DW.counter++;
  if (rc_blink_sim2_DW.counter == rc_blink_sim2_P.SineWave_NumSamp) {
    rc_blink_sim2_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, rc_blink_sim2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(rc_blink_sim2_M)!=-1) &&
        !((rtmGetTFinal(rc_blink_sim2_M)-rc_blink_sim2_M->Timing.taskTime0) >
          rc_blink_sim2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(rc_blink_sim2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(rc_blink_sim2_M)) {
      rtmSetErrorStatus(rc_blink_sim2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rc_blink_sim2_M->Timing.taskTime0 =
    (++rc_blink_sim2_M->Timing.clockTick0) * rc_blink_sim2_M->Timing.stepSize0;
}

/* Model initialize function */
void rc_blink_sim2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)rc_blink_sim2_M, 0,
                sizeof(RT_MODEL_rc_blink_sim2_T));
  rtmSetTFinal(rc_blink_sim2_M, 30.0);
  rc_blink_sim2_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  rc_blink_sim2_M->Sizes.checksums[0] = (337120902U);
  rc_blink_sim2_M->Sizes.checksums[1] = (2085221672U);
  rc_blink_sim2_M->Sizes.checksums[2] = (3404979144U);
  rc_blink_sim2_M->Sizes.checksums[3] = (3080664901U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    rc_blink_sim2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(rc_blink_sim2_M->extModeInfo,
      &rc_blink_sim2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(rc_blink_sim2_M->extModeInfo,
                        rc_blink_sim2_M->Sizes.checksums);
    rteiSetTPtr(rc_blink_sim2_M->extModeInfo, rtmGetTPtr(rc_blink_sim2_M));
  }

  /* block I/O */
  (void) memset(((void *) &rc_blink_sim2_B), 0,
                sizeof(B_rc_blink_sim2_T));

  /* states (dwork) */
  (void) memset((void *)&rc_blink_sim2_DW, 0,
                sizeof(DW_rc_blink_sim2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    rc_blink_sim2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/MATLAB System1' */
  rc_blink_sim2_DW.obj_g.isInitialized = 0;
  rc_blink_sim2_DW.obj_g.isInitialized = 1;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  rc_blink_sim2_DW.obj.isInitialized = 0;
  rc_blink_sim2_DW.obj.isInitialized = 1;
  rc_initialize();

  /* Start for MATLABSystem: '<Root>/MATLAB System2' */
  rc_blink_sim2_DW.obj_h.isInitialized = 0;
  rc_blink_sim2_DW.obj_h.isInitialized = 1;

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  rc_blink_sim2_DW.counter = 0;
}

/* Model terminate function */
void rc_blink_sim2_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System1' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System1'
   */
  if (rc_blink_sim2_DW.obj_g.isInitialized == 1) {
    rc_blink_sim2_DW.obj_g.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System1' */

  /* Start for MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System'
   */
  if (rc_blink_sim2_DW.obj.isInitialized == 1) {
    rc_blink_sim2_DW.obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System' */

  /* Start for MATLABSystem: '<Root>/MATLAB System2' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System2'
   */
  if (rc_blink_sim2_DW.obj_h.isInitialized == 1) {
    rc_blink_sim2_DW.obj_h.isInitialized = 2;
    rc_cleanup();
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
