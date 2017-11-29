/*
 * fccr_balance1.h
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

#ifndef RTW_HEADER_fccr_balance1_h_
#define RTW_HEADER_fccr_balance1_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef fccr_balance1_COMMON_INCLUDES_
# define fccr_balance1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_bbblue_driver.h"
#include "fccr_bbblue_driver.h"
#endif                                 /* fccr_balance1_COMMON_INCLUDES_ */

#include "fccr_balance1_types.h"

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
  real_T thetaRefrad;                  /* '<Root>/DT Fast Loop' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T u;                            /* '<Root>/D1 Inner Loop Controller' */
  real_T phirad;                       /* '<Root>/Sum2' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T DTSlowloop;                   /* '<Root>/DT Slow loop' */
  real_T Num[2];                       /* '<S2>/First Order Filter Low Pass Coefficients' */
  real_T Den[2];                       /* '<S2>/First Order Filter Low Pass Coefficients' */
  real_T Num_i[2];                     /* '<S2>/First Order Filter High Pass Coefficients' */
  real_T Den_i[2];                     /* '<S2>/First Order Filter High Pass Coefficients' */
  real_T b_varargout_4;
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T MOTOR_POLARITY_L;             /* '<S4>/MOTOR_POLARITY_L' */
  real_T Gain1_m;                      /* '<S2>/Gain1' */
  real_T FirstOrderFilterLowPass_tmp;
} B_fccr_balance1_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueDCMotor__T obj; /* '<S4>/MOTOR_CHANNEL_L' */
  beagleboneblue_bbblueDCMotor__T obj_d;/* '<S4>/MOTOR_CHANNEL_R' */
  beagleboneblue_bbblueButton_f_T obj_b;/* '<Root>/Button' */
  beagleboneblue_fccr_bbblueIMU_T obj_e;/* '<S2>/MATLAB System1' */
  beagleboneblue_bbblueEncoder__T obj_i;/* '<S3>/ENCODER_CHANNEL_R' */
  beagleboneblue_bbblueEncoder__T obj_l;/* '<S3>/ENCODER_CHANNEL_L' */
  real_T FirstOrderFilterLowPass_states;/* '<S2>/First Order Filter Low Pass' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
  real_T FirstOrderFilterHighPass_states;/* '<S2>/First Order Filter High Pass' */
  real_T D1InnerLoopController_states[2];/* '<Root>/D1 Inner Loop Controller' */
  real_T D2OuterLoopController_states[2];/* '<Root>/D2 Outer Loop Controller' */
  real_T DTFastLoop_Buffer0;           /* '<Root>/DT Fast Loop' */
  struct {
    void *LoggedData[2];
  } phi_PWORK;                         /* '<Root>/phi' */

  struct {
    void *LoggedData[2];
  } theta_PWORK;                       /* '<Root>/theta' */

  struct {
    void *LoggedData;
  } u_PWORK;                           /* '<Root>/u' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  beagleboneblue_bbblueLED_fccr_T obj_p;/* '<Root>/LED' */
  boolean_T objisempty;                /* '<S4>/MOTOR_CHANNEL_L' */
  boolean_T objisempty_e;              /* '<S4>/MOTOR_CHANNEL_R' */
  boolean_T objisempty_j;              /* '<S3>/ENCODER_CHANNEL_R' */
  boolean_T objisempty_f;              /* '<S3>/ENCODER_CHANNEL_L' */
  boolean_T objisempty_g;              /* '<S2>/MATLAB System1' */
  boolean_T objisempty_b;              /* '<Root>/Button' */
  boolean_T objisempty_n;              /* '<Root>/LED' */
} DW_fccr_balance1_T;

/* Parameters (auto storage) */
struct P_fccr_balance1_T_ {
  real_T Button_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/Button'
                                        */
  real_T MATLABSystem1_SampleTime;     /* Expression: 0.01
                                        * Referenced by: '<S2>/MATLAB System1'
                                        */
  real_T ENCODER_CHANNEL_L_SampleTime; /* Expression: 0.01
                                        * Referenced by: '<S3>/ENCODER_CHANNEL_L'
                                        */
  real_T ENCODER_CHANNEL_R_SampleTime; /* Expression: 0.01
                                        * Referenced by: '<S3>/ENCODER_CHANNEL_R'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T DTFastLoop_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/DT Fast Loop'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T wc_Value;                     /* Expression: 0.5
                                        * Referenced by: '<Root>/wc'
                                        */
  real_T dt_Value;                     /* Expression: 0.01
                                        * Referenced by: '<Root>/dt'
                                        */
  real_T FirstOrderFilterLowPass_Initial;/* Expression: 0
                                          * Referenced by: '<S2>/First Order Filter Low Pass'
                                          */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S2>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T FirstOrderFilterHighPass_Initia;/* Expression: 0
                                          * Referenced by: '<S2>/First Order Filter High Pass'
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
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -100
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T MOTOR_POLARITY_L_Gain;        /* Expression: 1
                                        * Referenced by: '<S4>/MOTOR_POLARITY_L'
                                        */
  real_T MOTOR_POLARITY_R_Gain;        /* Expression: -1
                                        * Referenced by: '<S4>/MOTOR_POLARITY_R'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 2*pi
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1/35.555
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T phiRef_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/phi Ref'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: pi/180
                                        * Referenced by: '<S1>/Gain1'
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
                                        * Referenced by: '<S5>/Gain1'
                                        */
  int64m_T Gain_Gain_p;                /* Computed Parameter: Gain_Gain_p
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
struct tag_RTM_fccr_balance1_T {
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
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
extern P_fccr_balance1_T fccr_balance1_P;

/* Block signals (auto storage) */
extern B_fccr_balance1_T fccr_balance1_B;

/* Block states (auto storage) */
extern DW_fccr_balance1_T fccr_balance1_DW;

/* External function called from main */
extern void fccr_balance1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void fccr_balance1_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void fccr_balance1_initialize(void);
extern void fccr_balance1_step(int_T tid);
extern void fccr_balance1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_fccr_balance1_T *const fccr_balance1_M;

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
 * '<Root>' : 'fccr_balance1'
 * '<S1>'   : 'fccr_balance1/Degrees to Radians'
 * '<S2>'   : 'fccr_balance1/G1'
 * '<S3>'   : 'fccr_balance1/G2'
 * '<S4>'   : 'fccr_balance1/Motor Input'
 * '<S5>'   : 'fccr_balance1/G1/Degrees to Radians1'
 * '<S6>'   : 'fccr_balance1/G1/First Order Filter High Pass Coefficients'
 * '<S7>'   : 'fccr_balance1/G1/First Order Filter Low Pass Coefficients'
 */
#endif                                 /* RTW_HEADER_fccr_balance1_h_ */
