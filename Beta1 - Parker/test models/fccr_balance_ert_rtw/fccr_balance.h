/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fccr_balance.h
 *
 * Code generated for Simulink model 'fccr_balance'.
 *
 * Model version                  : 1.93
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Nov 17 19:12:57 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_fccr_balance_h_
#define RTW_HEADER_fccr_balance_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef fccr_balance_COMMON_INCLUDES_
# define fccr_balance_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_bbblue_driver.h"
#include "fccr_bbblue_driver.h"
#endif                                 /* fccr_balance_COMMON_INCLUDES_ */

#include "fccr_balance_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain3;                        /* '<S3>/Gain3' */
  real_T DTFastLoop;                   /* '<Root>/DT Fast Loop' */
  real_T Gain;                         /* '<S8>/Gain' */
  real_T D1InnerLoopController;        /* '<Root>/D1 Inner Loop Controller' */
  real_T DTSlowloop;                   /* '<Root>/DT Slow loop' */
  real_T b_varargout_4;
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Sum5_e;                       /* '<S7>/Sum5' */
  real_T Sum6;                         /* '<S5>/Sum6' */
  real_T gyro;                         /* '<S2>/Discrete-Time Integrator' */
  real_T MOTOR_POLARITY_R;             /* '<S4>/MOTOR_POLARITY_R' */
  int8_T DataTypeConversion;           /* '<S4>/Data Type Conversion' */
} B_fccr_balance_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueDCMotor__T obj; /* '<S4>/MOTOR_CHANNEL_L' */
  beagleboneblue_bbblueDCMotor__T obj_e;/* '<S4>/MOTOR_CHANNEL_R' */
  beagleboneblue_bbblueButton_f_T obj_a;/* '<Root>/Button' */
  beagleboneblue_fccr_bbblueIMU_T obj_d;/* '<S2>/MATLAB System' */
  beagleboneblue_bbblueEncoder__T obj_o;/* '<S3>/ENCODER_CHANNEL_R' */
  beagleboneblue_bbblueEncoder__T obj_i;/* '<S3>/ENCODER_CHANNEL_L' */
  real_T UnitDelay_DSTATE;             /* '<S5>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S7>/Unit Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_i;           /* '<S7>/Unit Delay' */
  real_T D1InnerLoopController_states[2];/* '<Root>/D1 Inner Loop Controller' */
  real_T D2OuterLoopController_states[2];/* '<Root>/D2 Outer Loop Controller' */
  real_T DTFastLoop_Buffer0;           /* '<Root>/DT Fast Loop' */
  struct {
    void *LoggedData;
  } Encoder_PWORK;                     /* '<Root>/Encoder' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Motors_PWORK;                      /* '<Root>/Motors' */

  struct {
    void *LoggedData;
  } Theta_PWORK;                       /* '<Root>/Theta' */

  int32_T counter;                     /* '<Root>/Sine Wave' */
  beagleboneblue_bbblueLED_fccr_T obj_p;/* '<Root>/LED' */
} DW_fccr_balance_T;

/* Parameters (auto storage) */
struct P_fccr_balance_T_ {
  real_T Button_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/Button'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<S2>/MATLAB System'
                                        */
  real_T ENCODER_CHANNEL_L_SampleTime; /* Expression: 0.01
                                        * Referenced by: '<S3>/ENCODER_CHANNEL_L'
                                        */
  real_T ENCODER_CHANNEL_R_SampleTime; /* Expression: 0.01
                                        * Referenced by: '<S3>/ENCODER_CHANNEL_R'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_NumSamp;             /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Offset;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/35.555
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T DTFastLoop_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/DT Fast Loop'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T DT_Value;                     /* Expression: 0.01
                                        * Referenced by: '<Root>/DT'
                                        */
  real_T tau_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/tau'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S2>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  real_T UnitDelay_InitialCondition_f; /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T D1_GAIN_Gain;                 /* Expression: 1.05
                                        * Referenced by: '<Root>/D1_GAIN'
                                        */
  real_T D1InnerLoopController_NumCoef[3];/* Expression: [-4.945, 8.862, -3.967]
                                           * Referenced by: '<Root>/D1 Inner Loop Controller'
                                           */
  real_T D1InnerLoopController_DenCoef[3];/* Expression: [1.000, -1.481, 0.4812]
                                           * Referenced by: '<Root>/D1 Inner Loop Controller'
                                           */
  real_T D1InnerLoopController_InitialSt;/* Expression: 0
                                          * Referenced by: '<Root>/D1 Inner Loop Controller'
                                          */
  real_T Gain_Gain_o;                  /* Expression: 100
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T MOTOR_POLARITY_L_Gain;        /* Expression: 1
                                        * Referenced by: '<S4>/MOTOR_POLARITY_L'
                                        */
  real_T MOTOR_POLARITY_R_Gain;        /* Expression: -1
                                        * Referenced by: '<S4>/MOTOR_POLARITY_R'
                                        */
  real_T phiRef_Value;                 /* Expression: 20
                                        * Referenced by: '<Root>/phi Ref'
                                        */
  real_T D2_GAIN_Gain;                 /* Expression: 0.9
                                        * Referenced by: '<Root>/D2_GAIN'
                                        */
  real_T D2OuterLoopController_NumCoef[3];/* Expression: [0.18856,  -0.37209,  0.18354]
                                           * Referenced by: '<Root>/D2 Outer Loop Controller'
                                           */
  real_T D2OuterLoopController_DenCoef[3];/* Expression: [1.00000,  -1.86046,   0.86046]
                                           * Referenced by: '<Root>/D2 Outer Loop Controller'
                                           */
  real_T D2OuterLoopController_InitialSt;/* Expression: 0
                                          * Referenced by: '<Root>/D2 Outer Loop Controller'
                                          */
  real_T Gain1_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S6>/Gain1'
                                        */
  int64m_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S3>/Gain'
                                        */
  int32_T ENCODER_POLARITY_R_Gain;     /* Computed Parameter: ENCODER_POLARITY_R_Gain
                                        * Referenced by: '<S3>/ENCODER_POLARITY_R'
                                        */
  int32_T ENCODER_POLARITY_L_Gain;     /* Computed Parameter: ENCODER_POLARITY_L_Gain
                                        * Referenced by: '<S3>/ENCODER_POLARITY_L'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_fccr_balance_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_fccr_balance_T fccr_balance_P;

/* Block signals (auto storage) */
extern B_fccr_balance_T fccr_balance_B;

/* Block states (auto storage) */
extern DW_fccr_balance_T fccr_balance_DW;

/* External function called from main */
extern void fccr_balance_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void fccr_balance_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void fccr_balance_initialize(void);
extern void fccr_balance_step(int_T tid);
extern void fccr_balance_terminate(void);

/* Real-time Model object */
extern RT_MODEL_fccr_balance_T *const fccr_balance_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'fccr_balance'
 * '<S1>'   : 'fccr_balance/Compare To Zero'
 * '<S2>'   : 'fccr_balance/G1'
 * '<S3>'   : 'fccr_balance/G2'
 * '<S4>'   : 'fccr_balance/Motor Input'
 * '<S5>'   : 'fccr_balance/G1/1st Order LP'
 * '<S6>'   : 'fccr_balance/G1/Degrees to Radians'
 * '<S7>'   : 'fccr_balance/G1/First Order HP'
 * '<S8>'   : 'fccr_balance/G1/Radians to Degrees'
 */
#endif                                 /* RTW_HEADER_fccr_balance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
