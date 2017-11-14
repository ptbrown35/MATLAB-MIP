/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fccr_balance.h
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
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T accel_x;                      /* '<Root>/MATLAB System' */
  real_T accel_y;                      /* '<Root>/MATLAB System' */
  real_T accel_z;                      /* '<Root>/MATLAB System' */
  real_T gyro_x;                       /* '<Root>/MATLAB System' */
  real_T gyro_y;                       /* '<Root>/MATLAB System' */
  real_T gyro_z;                       /* '<Root>/MATLAB System' */
} B_fccr_balance_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueButton_f_T obj; /* '<Root>/Button' */
  beagleboneblue_fccr_bbblueIMU_T obj_d;/* '<Root>/MATLAB System' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S7>/Unit Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_i;           /* '<S7>/Unit Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[6];
  } data_PWORK;                        /* '<Root>/data' */

  int32_T counter;                     /* '<Root>/Sine Wave' */
  beagleboneblue_bbblueLED_fccr_T obj_p;/* '<Root>/LED' */
} DW_fccr_balance_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T eTheta;                       /* '<Root>/eTheta' */
} ExtY_fccr_balance_T;

/* Parameters (auto storage) */
struct P_fccr_balance_T_ {
  real_T Button_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/Button'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: 0.005
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T ThetaRefDeg_Value;            /* Expression: 22.9
                                        * Referenced by: '<Root>/Theta Ref (Deg)'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T dt_Value;                     /* Expression: 0.005
                                        * Referenced by: '<S1>/dt'
                                        */
  real_T tau_Value;                    /* Expression: 1
                                        * Referenced by: '<S1>/tau'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T tau_Value_m;                  /* Expression: 1
                                        * Referenced by: '<S7>/tau'
                                        */
  real_T dt_Value_o;                   /* Expression: 0.005
                                        * Referenced by: '<S7>/dt'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<Root>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T UnitDelay_InitialCondition_f; /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S3>/Gain1'
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
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
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

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_fccr_balance_T fccr_balance_Y;

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
 * '<S1>'   : 'fccr_balance/1st Order LP'
 * '<S2>'   : 'fccr_balance/Compare To Zero'
 * '<S3>'   : 'fccr_balance/Degrees to Radians'
 * '<S4>'   : 'fccr_balance/Radians to Degrees'
 * '<S5>'   : 'fccr_balance/Slider D1_GAIN'
 * '<S6>'   : 'fccr_balance/Slider D2_GAIN'
 * '<S7>'   : 'fccr_balance/Subsystem'
 */
#endif                                 /* RTW_HEADER_fccr_balance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
