/*
 * complimentary_filter.c
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

#include "complimentary_filter.h"
#include "complimentary_filter_private.h"
#include "complimentary_filter_dt.h"

/* Block signals (auto storage) */
B_complimentary_filter_T complimentary_filter_B;

/* Block states (auto storage) */
DW_complimentary_filter_T complimentary_filter_DW;

/* Real-time model */
RT_MODEL_complimentary_filter_T complimentary_filter_M_;
RT_MODEL_complimentary_filter_T *const complimentary_filter_M =
  &complimentary_filter_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void complimentary_filter_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(complimentary_filter_M, 1));
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
  (complimentary_filter_M->Timing.TaskCounters.TID[1])++;
  if ((complimentary_filter_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    complimentary_filter_M->Timing.TaskCounters.TID[1] = 0;
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
void complimentary_filter_step0(void)  /* Sample time: [0.01s, 0.0s] */
{
  boolean_T p;
  boolean_T p_0;
  real_T b_varargout_4;
  real_T DiscreteTransferFcn1_tmp;
  real_T DiscreteTransferFcn_tmp;
  real_T Num_m_tmp;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  p = false;
  p_0 = true;
  if (!(complimentary_filter_DW.obj_f.SampleTime ==
        complimentary_filter_P.MATLABSystem_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    complimentary_filter_DW.obj_f.SampleTime =
      complimentary_filter_P.MATLABSystem_SampleTime;
  }

  fccr_read_accel_x();
  DiscreteTransferFcn_tmp = fccr_read_accel_y();
  DiscreteTransferFcn1_tmp = fccr_read_accel_z();
  b_varargout_4 = fccr_read_gyro_x();
  fccr_read_gyro_y();
  fccr_read_gyro_z();

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/dt'
   *  Constant: '<Root>/wc'
   */
  /* MATLAB Function 'MATLAB Function': '<S2>:1' */
  /* '<S2>:1:3' */
  complimentary_filter_B.Num_m[0] = 0.0;
  Num_m_tmp = complimentary_filter_P.wc_Value * complimentary_filter_P.dt_Value;
  complimentary_filter_B.Num_m[1] = Num_m_tmp;

  /* '<S2>:1:4' */
  complimentary_filter_B.Den_k[0] = 1.0;
  complimentary_filter_B.Den_k[1] = Num_m_tmp - 1.0;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/MATLAB System'
   *  MATLABSystem: '<Root>/MATLAB System'
   *  Trigonometry: '<Root>/Trigonometric Function'
   */
  DiscreteTransferFcn_tmp = complimentary_filter_P.Gain_Gain * rt_atan2d_snf
    (DiscreteTransferFcn1_tmp, DiscreteTransferFcn_tmp) -
    complimentary_filter_B.Den_k[1] *
    complimentary_filter_DW.DiscreteTransferFcn_states;
  complimentary_filter_B.ThetaAccel = complimentary_filter_B.Num_m[0] *
    DiscreteTransferFcn_tmp + complimentary_filter_B.Num_m[1] *
    complimentary_filter_DW.DiscreteTransferFcn_states;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/dt'
   *  Constant: '<Root>/wc'
   */
  /* MATLAB Function 'MATLAB Function1': '<S3>:1' */
  /* '<S3>:1:3' */
  complimentary_filter_B.Num[0] = 1.0;
  complimentary_filter_B.Num[1] = -1.0;

  /* '<S3>:1:4' */
  complimentary_filter_B.Den[0] = 1.0;
  complimentary_filter_B.Den[1] = complimentary_filter_P.wc_Value *
    complimentary_filter_P.dt_Value - 1.0;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Gain: '<Root>/Gain1'
   */
  DiscreteTransferFcn1_tmp = complimentary_filter_P.Gain1_Gain *
    complimentary_filter_DW.DiscreteTimeIntegrator_DSTATE -
    complimentary_filter_B.Den[1] *
    complimentary_filter_DW.DiscreteTransferFcn1_states;
  complimentary_filter_B.ThetaGyro = complimentary_filter_B.Num[0] *
    DiscreteTransferFcn1_tmp + complimentary_filter_B.Num[1] *
    complimentary_filter_DW.DiscreteTransferFcn1_states;

  /* Sum: '<Root>/Sum' */
  complimentary_filter_B.ThetaFiltered = complimentary_filter_B.ThetaAccel +
    complimentary_filter_B.ThetaGyro;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  complimentary_filter_DW.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S1>/Gain1'
   *  MATLABSystem: '<Root>/MATLAB System'
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  complimentary_filter_DW.DiscreteTimeIntegrator_DSTATE +=
    complimentary_filter_P.Gain1_Gain_a * b_varargout_4 *
    complimentary_filter_P.DiscreteTimeIntegrator_gainval;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' */
  complimentary_filter_DW.DiscreteTransferFcn1_states = DiscreteTransferFcn1_tmp;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, complimentary_filter_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(complimentary_filter_M)!=-1) &&
        !((rtmGetTFinal(complimentary_filter_M)-
           complimentary_filter_M->Timing.taskTime0) >
          complimentary_filter_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(complimentary_filter_M, "Simulation finished");
    }

    if (rtmGetStopRequested(complimentary_filter_M)) {
      rtmSetErrorStatus(complimentary_filter_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++complimentary_filter_M->Timing.clockTick0)) {
    ++complimentary_filter_M->Timing.clockTickH0;
  }

  complimentary_filter_M->Timing.taskTime0 =
    complimentary_filter_M->Timing.clockTick0 *
    complimentary_filter_M->Timing.stepSize0 +
    complimentary_filter_M->Timing.clockTickH0 *
    complimentary_filter_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void complimentary_filter_step1(void)  /* Sample time: [0.1s, 0.0s] */
{
  uint8_T rtb_Button_0;
  boolean_T p;
  boolean_T p_0;
  real_T rtb_PulseGenerator;

  /* MATLABSystem: '<Root>/Button' */
  p = false;
  p_0 = true;
  if (!(complimentary_filter_DW.obj.SampleTime ==
        complimentary_filter_P.Button_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    complimentary_filter_DW.obj.SampleTime =
      complimentary_filter_P.Button_SampleTime;
  }

  rtb_Button_0 = rc_get_mode_button();

  /* Stop: '<Root>/Stop Simulation' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLABSystem: '<Root>/Button'
   */
  if (rtb_Button_0 != 0) {
    rtmSetStopRequested(complimentary_filter_M, 1);
  }

  /* End of Stop: '<Root>/Stop Simulation' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (complimentary_filter_DW.clockTickCounter <
                        complimentary_filter_P.PulseGenerator_Duty) &&
    (complimentary_filter_DW.clockTickCounter >= 0) ?
    complimentary_filter_P.PulseGenerator_Amp : 0.0;
  if (complimentary_filter_DW.clockTickCounter >=
      complimentary_filter_P.PulseGenerator_Period - 1.0) {
    complimentary_filter_DW.clockTickCounter = 0;
  } else {
    complimentary_filter_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<Root>/Convert to Logical' */
  rtb_PulseGenerator = floor(rtb_PulseGenerator);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  /* Start for MATLABSystem: '<Root>/LED' incorporates:
   *  DataTypeConversion: '<Root>/Convert to Logical'
   */
  rc_set_led(0U, (uint8_T)(rtb_PulseGenerator < 0.0 ? (int32_T)(uint8_T)-(int8_T)
              (uint8_T)-rtb_PulseGenerator : (int32_T)(uint8_T)
              rtb_PulseGenerator));
  rtExtModeUpload(1, (((complimentary_filter_M->Timing.clockTick1+
                        complimentary_filter_M->Timing.clockTickH1* 4294967296.0))
                      * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  complimentary_filter_M->Timing.clockTick1++;
  if (!complimentary_filter_M->Timing.clockTick1) {
    complimentary_filter_M->Timing.clockTickH1++;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void complimentary_filter_step(int_T tid)
{
  switch (tid) {
   case 0 :
    complimentary_filter_step0();
    break;

   case 1 :
    complimentary_filter_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void complimentary_filter_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)complimentary_filter_M, 0,
                sizeof(RT_MODEL_complimentary_filter_T));
  rtmSetTFinal(complimentary_filter_M, -1);
  complimentary_filter_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  complimentary_filter_M->Sizes.checksums[0] = (2984651427U);
  complimentary_filter_M->Sizes.checksums[1] = (3674799925U);
  complimentary_filter_M->Sizes.checksums[2] = (1092956889U);
  complimentary_filter_M->Sizes.checksums[3] = (767317551U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    complimentary_filter_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(complimentary_filter_M->extModeInfo,
      &complimentary_filter_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(complimentary_filter_M->extModeInfo,
                        complimentary_filter_M->Sizes.checksums);
    rteiSetTPtr(complimentary_filter_M->extModeInfo, rtmGetTPtr
                (complimentary_filter_M));
  }

  /* block I/O */
  (void) memset(((void *) &complimentary_filter_B), 0,
                sizeof(B_complimentary_filter_T));

  /* states (dwork) */
  (void) memset((void *)&complimentary_filter_DW, 0,
                sizeof(DW_complimentary_filter_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    complimentary_filter_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Button' */
  complimentary_filter_DW.obj.isInitialized = 0;
  complimentary_filter_DW.objisempty = true;
  complimentary_filter_DW.obj.SampleTime =
    complimentary_filter_P.Button_SampleTime;
  complimentary_filter_DW.obj.isInitialized = 1;

  /* Start for MATLABSystem: '<Root>/LED' */
  complimentary_filter_DW.obj_p.isInitialized = 0;
  complimentary_filter_DW.objisempty_n = true;
  complimentary_filter_DW.obj_p.isInitialized = 1;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  complimentary_filter_DW.obj_f.isInitialized = 0;
  complimentary_filter_DW.objisempty_d = true;
  complimentary_filter_DW.obj_f.SampleTime =
    complimentary_filter_P.MATLABSystem_SampleTime;
  complimentary_filter_DW.obj_f.isInitialized = 1;
  fccr_initialize_imu();

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  complimentary_filter_DW.clockTickCounter = 0;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  complimentary_filter_DW.DiscreteTransferFcn_states =
    complimentary_filter_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  complimentary_filter_DW.DiscreteTimeIntegrator_DSTATE =
    complimentary_filter_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' */
  complimentary_filter_DW.DiscreteTransferFcn1_states =
    complimentary_filter_P.DiscreteTransferFcn1_InitialSta;
}

/* Model terminate function */
void complimentary_filter_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Button' */
  if (complimentary_filter_DW.obj.isInitialized == 1) {
    complimentary_filter_DW.obj.isInitialized = 2;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Button' */

  /* Start for MATLABSystem: '<Root>/LED' */
  if (complimentary_filter_DW.obj_p.isInitialized == 1) {
    complimentary_filter_DW.obj_p.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/LED' */

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  if (complimentary_filter_DW.obj_f.isInitialized == 1) {
    complimentary_filter_DW.obj_f.isInitialized = 2;
    rc_power_off_imu();
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System' */
}
