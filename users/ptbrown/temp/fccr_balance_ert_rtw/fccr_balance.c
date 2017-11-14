/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fccr_balance.c
 *
 * Code generated for Simulink model 'fccr_balance'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Nov 14 01:15:17 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fccr_balance.h"
#include "fccr_balance_private.h"
#include "fccr_balance_dt.h"

/* Block signals (auto storage) */
B_fccr_balance_T fccr_balance_B;

/* Block states (auto storage) */
DW_fccr_balance_T fccr_balance_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_fccr_balance_T fccr_balance_Y;

/* Real-time model */
RT_MODEL_fccr_balance_T fccr_balance_M_;
RT_MODEL_fccr_balance_T *const fccr_balance_M = &fccr_balance_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void fccr_balance_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(fccr_balance_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (fccr_balance_M->Timing.TaskCounters.TID[1])++;
  if ((fccr_balance_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.1s, 0.0s] */
    fccr_balance_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function for TID0 */
void fccr_balance_step0(void)          /* Sample time: [0.005s, 0.0s] */
{
  boolean_T p;
  boolean_T p_0;
  real_T rtb_Sum6;
  real_T rtb_gyro;
  real_T rtb_Divide;

  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/dt'
   *  Constant: '<S1>/tau'
   *  Sum: '<S1>/Sum4'
   */
  rtb_Divide = fccr_balance_P.dt_Value / (fccr_balance_P.dt_Value +
    fccr_balance_P.tau_Value);

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  p = false;
  p_0 = true;
  if (!(fccr_balance_DW.obj_d.SampleTime ==
        fccr_balance_P.MATLABSystem_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    fccr_balance_DW.obj_d.SampleTime = fccr_balance_P.MATLABSystem_SampleTime;
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  fccr_balance_B.accel_x = fccr_read_accel_x();
  fccr_balance_B.accel_y = fccr_read_accel_y();
  fccr_balance_B.accel_z = fccr_read_accel_z();
  fccr_balance_B.gyro_x = fccr_read_gyro_x();
  fccr_balance_B.gyro_y = fccr_read_gyro_y();
  fccr_balance_B.gyro_z = fccr_read_gyro_z();

  /* Sum: '<S1>/Sum6' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<Root>/Gain'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   *  Sum: '<S1>/Sum5'
   *  Trigonometry: '<Root>/Trigonometric Function'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Sum6 = (fccr_balance_P.Constant_Value - rtb_Divide) *
    fccr_balance_DW.UnitDelay_DSTATE + fccr_balance_P.Gain_Gain * rt_atan2d_snf
    (fccr_balance_B.accel_z, fccr_balance_B.accel_y) * rtb_Divide;

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/dt'
   *  Constant: '<S7>/tau'
   *  Sum: '<S7>/Sum4'
   */
  rtb_Divide = fccr_balance_P.tau_Value_m / (fccr_balance_P.tau_Value_m +
    fccr_balance_P.dt_Value_o);

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtb_gyro = fccr_balance_DW.DiscreteTimeIntegrator_DSTATE;

  /* Sum: '<S7>/Sum5' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Sum: '<S7>/Subtract'
   *  UnitDelay: '<S7>/Unit Delay'
   *  UnitDelay: '<S7>/Unit Delay1'
   */
  rtb_Divide = (fccr_balance_DW.DiscreteTimeIntegrator_DSTATE -
                fccr_balance_DW.UnitDelay_DSTATE_i) * rtb_Divide + rtb_Divide *
    fccr_balance_DW.UnitDelay1_DSTATE;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/Theta Ref (Deg)'
   *  Gain: '<S4>/Gain'
   *  Sum: '<Root>/Sum2'
   */
  fccr_balance_B.Sum3 = fccr_balance_P.ThetaRefDeg_Value - (rtb_Sum6 +
    rtb_Divide) * fccr_balance_P.Gain_Gain_p;

  /* Outport: '<Root>/eTheta' */
  fccr_balance_Y.eTheta = fccr_balance_B.Sum3;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  fccr_balance_DW.UnitDelay_DSTATE = rtb_Sum6;

  /* Update for UnitDelay: '<S7>/Unit Delay1' */
  fccr_balance_DW.UnitDelay1_DSTATE = rtb_Divide;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S3>/Gain1'
   */
  fccr_balance_DW.DiscreteTimeIntegrator_DSTATE += fccr_balance_P.Gain1_Gain *
    fccr_balance_B.gyro_x * fccr_balance_P.DiscreteTimeIntegrator_gainval;

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  fccr_balance_DW.UnitDelay_DSTATE_i = rtb_gyro;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, fccr_balance_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(fccr_balance_M)!=-1) &&
        !((rtmGetTFinal(fccr_balance_M)-fccr_balance_M->Timing.taskTime0) >
          fccr_balance_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(fccr_balance_M, "Simulation finished");
    }

    if (rtmGetStopRequested(fccr_balance_M)) {
      rtmSetErrorStatus(fccr_balance_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  fccr_balance_M->Timing.taskTime0 =
    (++fccr_balance_M->Timing.clockTick0) * fccr_balance_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void fccr_balance_step1(void)          /* Sample time: [0.1s, 0.0s] */
{
  uint8_T rtb_Button_0;
  boolean_T p;
  boolean_T p_0;

  /* Start for MATLABSystem: '<Root>/Button' */
  p = false;
  p_0 = true;
  if (!(fccr_balance_DW.obj.SampleTime == fccr_balance_P.Button_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    fccr_balance_DW.obj.SampleTime = fccr_balance_P.Button_SampleTime;
  }

  /* MATLABSystem: '<Root>/Button' */
  rtb_Button_0 = rc_get_mode_button();

  /* Stop: '<Root>/Stop Simulation' incorporates:
   *  MATLABSystem: '<Root>/Button'
   */
  if (rtb_Button_0 != 0) {
    rtmSetStopRequested(fccr_balance_M, 1);
  }

  /* End of Stop: '<Root>/Stop Simulation' */

  /* Start for MATLABSystem: '<Root>/LED' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   *  Sin: '<Root>/Sine Wave'
   */
  rc_set_led(0U, (uint8_T)(fccr_balance_P.SineWave_Amp * sin(((real_T)
    fccr_balance_DW.counter + fccr_balance_P.SineWave_Offset) * 2.0 *
    3.1415926535897931 / fccr_balance_P.SineWave_NumSamp) +
              fccr_balance_P.SineWave_Bias <= fccr_balance_P.Constant_Value_a));

  /* Update for Sin: '<Root>/Sine Wave' */
  fccr_balance_DW.counter++;
  if (fccr_balance_DW.counter == fccr_balance_P.SineWave_NumSamp) {
    fccr_balance_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
  rtExtModeUpload(1, ((fccr_balance_M->Timing.clockTick1) * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  fccr_balance_M->Timing.clockTick1++;
}

/* Model step wrapper function for compatibility with a static main program */
void fccr_balance_step(int_T tid)
{
  switch (tid) {
   case 0 :
    fccr_balance_step0();
    break;

   case 1 :
    fccr_balance_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void fccr_balance_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)fccr_balance_M, 0,
                sizeof(RT_MODEL_fccr_balance_T));
  rtmSetTFinal(fccr_balance_M, -1);
  fccr_balance_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  fccr_balance_M->Sizes.checksums[0] = (507554010U);
  fccr_balance_M->Sizes.checksums[1] = (1463534633U);
  fccr_balance_M->Sizes.checksums[2] = (2509703084U);
  fccr_balance_M->Sizes.checksums[3] = (1879405640U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    fccr_balance_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(fccr_balance_M->extModeInfo,
      &fccr_balance_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(fccr_balance_M->extModeInfo,
                        fccr_balance_M->Sizes.checksums);
    rteiSetTPtr(fccr_balance_M->extModeInfo, rtmGetTPtr(fccr_balance_M));
  }

  /* block I/O */
  (void) memset(((void *) &fccr_balance_B), 0,
                sizeof(B_fccr_balance_T));

  /* states (dwork) */
  (void) memset((void *)&fccr_balance_DW, 0,
                sizeof(DW_fccr_balance_T));

  /* external outputs */
  fccr_balance_Y.eTheta = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    fccr_balance_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  fccr_balance_DW.obj_d.isInitialized = 0;
  fccr_balance_DW.obj_d.SampleTime = fccr_balance_P.MATLABSystem_SampleTime;
  fccr_balance_DW.obj_d.isInitialized = 1;
  fccr_initialize_imu();

  /* Start for MATLABSystem: '<Root>/Button' */
  fccr_balance_DW.obj.isInitialized = 0;
  fccr_balance_DW.obj.SampleTime = fccr_balance_P.Button_SampleTime;
  fccr_balance_DW.obj.isInitialized = 1;

  /* Start for MATLABSystem: '<Root>/LED' */
  fccr_balance_DW.obj_p.isInitialized = 0;
  fccr_balance_DW.obj_p.isInitialized = 1;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  fccr_balance_DW.UnitDelay_DSTATE = fccr_balance_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
  fccr_balance_DW.UnitDelay1_DSTATE = fccr_balance_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  fccr_balance_DW.DiscreteTimeIntegrator_DSTATE =
    fccr_balance_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  fccr_balance_DW.UnitDelay_DSTATE_i =
    fccr_balance_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  fccr_balance_DW.counter = 0;
}

/* Model terminate function */
void fccr_balance_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  if (fccr_balance_DW.obj_d.isInitialized == 1) {
    fccr_balance_DW.obj_d.isInitialized = 2;
    rc_power_off_imu();
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System' */

  /* Start for MATLABSystem: '<Root>/Button' */
  if (fccr_balance_DW.obj.isInitialized == 1) {
    fccr_balance_DW.obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/Button' */

  /* Start for MATLABSystem: '<Root>/LED' */
  if (fccr_balance_DW.obj_p.isInitialized == 1) {
    fccr_balance_DW.obj_p.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/LED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
