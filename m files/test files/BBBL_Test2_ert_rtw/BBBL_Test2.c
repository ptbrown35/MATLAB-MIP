/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BBBL_Test2.c
 *
 * Code generated for Simulink model 'BBBL_Test2'.
 *
 * Model version                  : 1.85
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Jun 06 20:44:06 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BBBL_Test2.h"
#include "BBBL_Test2_private.h"
#include "BBBL_Test2_dt.h"
#define BBBL_Test2_rc_led_t            (1.0)

/* Block signals (auto storage) */
B_BBBL_Test2_T BBBL_Test2_B;

/* Block states (auto storage) */
DW_BBBL_Test2_T BBBL_Test2_DW;

/* Real-time model */
RT_MODEL_BBBL_Test2_T BBBL_Test2_M_;
RT_MODEL_BBBL_Test2_T *const BBBL_Test2_M = &BBBL_Test2_M_;

/* Model step function */
void BBBL_Test2_step(void)
{
  uint8_T rtb_FixPtSum1;

  /* UnitDelay: '<S3>/Output' */
  BBBL_Test2_B.Output = BBBL_Test2_DW.Output_DSTATE;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  BBBL_Test2_B.Compare = (uint8_T)(BBBL_Test2_B.Output <=
    BBBL_Test2_P.CompareToConstant_const);

  /* Gain: '<Root>/b2' */
  BBBL_Test2_B.b2 = BBBL_Test2_P.b2_Gain * (real_T)BBBL_Test2_B.Compare;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/a'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  BBBL_Test2_B.y = BBBL_Test2_P.a_Gain * BBBL_Test2_B.y + BBBL_Test2_B.b2;

  /* Start for MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Constant: '<S2>/Constant'
   *  MATLABSystem: '<Root>/MATLAB System'
   *  RelationalOperator: '<S2>/Compare'
   */
  rc_set_led(BBBL_Test2_rc_led_t, (uint8_T)(BBBL_Test2_B.y >
              BBBL_Test2_P.CompareToConstant1_const));

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)BBBL_Test2_B.Output +
    BBBL_Test2_P.FixPtConstant_Value);

  /* Switch: '<S5>/FixPt Switch' */
  if (rtb_FixPtSum1 > BBBL_Test2_P.CounterLimited_uplimit) {
    /* Update for UnitDelay: '<S3>/Output' incorporates:
     *  Constant: '<S5>/Constant'
     */
    BBBL_Test2_DW.Output_DSTATE = BBBL_Test2_P.Constant_Value;
  } else {
    /* Update for UnitDelay: '<S3>/Output' */
    BBBL_Test2_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S5>/FixPt Switch' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, BBBL_Test2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(BBBL_Test2_M)!=-1) &&
        !((rtmGetTFinal(BBBL_Test2_M)-BBBL_Test2_M->Timing.taskTime0) >
          BBBL_Test2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(BBBL_Test2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(BBBL_Test2_M)) {
      rtmSetErrorStatus(BBBL_Test2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  BBBL_Test2_M->Timing.taskTime0 =
    (++BBBL_Test2_M->Timing.clockTick0) * BBBL_Test2_M->Timing.stepSize0;
}

/* Model initialize function */
void BBBL_Test2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BBBL_Test2_M, 0,
                sizeof(RT_MODEL_BBBL_Test2_T));
  rtmSetTFinal(BBBL_Test2_M, 60.0);
  BBBL_Test2_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  BBBL_Test2_M->Sizes.checksums[0] = (2493430741U);
  BBBL_Test2_M->Sizes.checksums[1] = (1093693689U);
  BBBL_Test2_M->Sizes.checksums[2] = (988478405U);
  BBBL_Test2_M->Sizes.checksums[3] = (337236055U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    BBBL_Test2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BBBL_Test2_M->extModeInfo,
      &BBBL_Test2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BBBL_Test2_M->extModeInfo, BBBL_Test2_M->Sizes.checksums);
    rteiSetTPtr(BBBL_Test2_M->extModeInfo, rtmGetTPtr(BBBL_Test2_M));
  }

  /* block I/O */
  (void) memset(((void *) &BBBL_Test2_B), 0,
                sizeof(B_BBBL_Test2_T));

  /* states (dwork) */
  (void) memset((void *)&BBBL_Test2_DW, 0,
                sizeof(DW_BBBL_Test2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BBBL_Test2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  BBBL_Test2_DW.obj.isInitialized = 0;
  BBBL_Test2_DW.obj.isInitialized = 1;
  rc_initialize();

  /* InitializeConditions for UnitDelay: '<S3>/Output' */
  BBBL_Test2_DW.Output_DSTATE = BBBL_Test2_P.Output_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  BBBL_Test2_B.y = BBBL_Test2_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void BBBL_Test2_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System'
   */
  if (BBBL_Test2_DW.obj.isInitialized == 1) {
    BBBL_Test2_DW.obj.isInitialized = 2;
    rc_cleanup();
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
