/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rc_blink_sim.c
 *
 * Code generated for Simulink model 'rc_blink_sim'.
 *
 * Model version                  : 1.89
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu May 25 18:34:06 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rc_blink_sim.h"
#include "rc_blink_sim_private.h"
#include "rc_blink_sim_dt.h"
#define rc_blink_sim_rc_led_t          (1.0)

/* Block signals (auto storage) */
B_rc_blink_sim_T rc_blink_sim_B;

/* Block states (auto storage) */
DW_rc_blink_sim_T rc_blink_sim_DW;

/* Real-time model */
RT_MODEL_rc_blink_sim_T rc_blink_sim_M_;
RT_MODEL_rc_blink_sim_T *const rc_blink_sim_M = &rc_blink_sim_M_;

/* Model step function */
void rc_blink_sim_step(void)
{
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Sin: '<Root>/Sine Wave'
   */
  rc_blink_sim_B.Compare = (uint8_T)(sin(((real_T)rc_blink_sim_DW.counter +
    rc_blink_sim_P.SineWave_Offset) * 2.0 * 3.1415926535897931 /
    rc_blink_sim_P.SineWave_NumSamp) * rc_blink_sim_P.SineWave_Amp +
    rc_blink_sim_P.SineWave_Bias <= rc_blink_sim_P.Constant_Value);

  /* Start for MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  rc_set_led(rc_blink_sim_rc_led_t, rc_blink_sim_B.Compare);

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
  rtmSetTFinal(rc_blink_sim_M, 60.0);
  rc_blink_sim_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  rc_blink_sim_M->Sizes.checksums[0] = (3015280696U);
  rc_blink_sim_M->Sizes.checksums[1] = (622116491U);
  rc_blink_sim_M->Sizes.checksums[2] = (3328475782U);
  rc_blink_sim_M->Sizes.checksums[3] = (748905959U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    rc_blink_sim_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
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
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  rc_blink_sim_DW.obj.isInitialized = 0;
  rc_blink_sim_DW.obj.isInitialized = 1;
  rc_initialize();

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  rc_blink_sim_DW.counter = 0;
}

/* Model terminate function */
void rc_blink_sim_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System'
   */
  if (rc_blink_sim_DW.obj.isInitialized == 1) {
    rc_blink_sim_DW.obj.isInitialized = 2;
    rc_cleanup();
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
