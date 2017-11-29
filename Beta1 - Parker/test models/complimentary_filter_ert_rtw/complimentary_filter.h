/*
 * complimentary_filter.h
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

#ifndef RTW_HEADER_complimentary_filter_h_
#define RTW_HEADER_complimentary_filter_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef complimentary_filter_COMMON_INCLUDES_
# define complimentary_filter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "fccr_bbblue_driver.h"
#include "MW_bbblue_driver.h"
#endif                                 /* complimentary_filter_COMMON_INCLUDES_ */

#include "complimentary_filter_types.h"

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
  real_T ThetaAccel;                   /* '<Root>/Discrete Transfer Fcn' */
  real_T ThetaGyro;                    /* '<Root>/Discrete Transfer Fcn1' */
  real_T ThetaFiltered;                /* '<Root>/Sum' */
  real_T Num[2];                       /* '<Root>/MATLAB Function1' */
  real_T Den[2];                       /* '<Root>/MATLAB Function1' */
  real_T Num_m[2];                     /* '<Root>/MATLAB Function' */
  real_T Den_k[2];                     /* '<Root>/MATLAB Function' */
} B_complimentary_filter_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueButton_c_T obj; /* '<Root>/Button' */
  beagleboneblue_fccr_bbblueIMU_T obj_f;/* '<Root>/MATLAB System' */
  real_T DiscreteTransferFcn_states;   /* '<Root>/Discrete Transfer Fcn' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn1_states;  /* '<Root>/Discrete Transfer Fcn1' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  beagleboneblue_bbblueLED_comp_T obj_p;/* '<Root>/LED' */
  boolean_T objisempty;                /* '<Root>/Button' */
  boolean_T objisempty_n;              /* '<Root>/LED' */
  boolean_T objisempty_d;              /* '<Root>/MATLAB System' */
} DW_complimentary_filter_T;

/* Parameters (auto storage) */
struct P_complimentary_filter_T_ {
  real_T MATLABSystem_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T Button_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/Button'
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
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T wc_Value;                     /* Expression: 0.5
                                        * Referenced by: '<Root>/wc'
                                        */
  real_T dt_Value;                     /* Expression: 0.01
                                        * Referenced by: '<Root>/dt'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<Root>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T DiscreteTransferFcn1_InitialSta;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete Transfer Fcn1'
                                          */
  real_T Gain1_Gain_a;                 /* Expression: pi/180
                                        * Referenced by: '<S1>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_complimentary_filter_T {
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

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_complimentary_filter_T complimentary_filter_P;

/* Block signals (auto storage) */
extern B_complimentary_filter_T complimentary_filter_B;

/* Block states (auto storage) */
extern DW_complimentary_filter_T complimentary_filter_DW;

/* External function called from main */
extern void complimentary_filter_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void complimentary_filter_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void complimentary_filter_initialize(void);
extern void complimentary_filter_step(int_T tid);
extern void complimentary_filter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_complimentary_filter_T *const complimentary_filter_M;

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
 * '<Root>' : 'complimentary_filter'
 * '<S1>'   : 'complimentary_filter/Degrees to Radians'
 * '<S2>'   : 'complimentary_filter/MATLAB Function'
 * '<S3>'   : 'complimentary_filter/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_complimentary_filter_h_ */
