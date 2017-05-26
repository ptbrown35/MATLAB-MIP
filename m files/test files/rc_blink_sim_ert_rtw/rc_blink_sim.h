/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rc_blink_sim.h
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

#ifndef RTW_HEADER_rc_blink_sim_h_
#define RTW_HEADER_rc_blink_sim_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef rc_blink_sim_COMMON_INCLUDES_
# define rc_blink_sim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "roboticscape.h"
#endif                                 /* rc_blink_sim_COMMON_INCLUDES_ */

#include "rc_blink_sim_types.h"

/* Shared type includes */
#include "multiword_types.h"

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

/* Block signals (auto storage) */
typedef struct {
  uint8_T Compare;                     /* '<S3>/Compare' */
} B_rc_blink_sim_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void *MATLABSystem_PWORK;            /* '<Root>/MATLAB System' */
  int32_T counter;                     /* '<Root>/Sine Wave' */
  rc_blink_sys_rc_blink_sim_T obj;     /* '<Root>/MATLAB System' */
} DW_rc_blink_sim_T;

/* Parameters (auto storage) */
struct P_rc_blink_sim_T_ {
  real_T SineWave_Amp;                 /* Expression: 20
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_NumSamp;             /* Expression: 20
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Offset;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_rc_blink_sim_T {
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
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_rc_blink_sim_T rc_blink_sim_P;

/* Block signals (auto storage) */
extern B_rc_blink_sim_T rc_blink_sim_B;

/* Block states (auto storage) */
extern DW_rc_blink_sim_T rc_blink_sim_DW;

/* Model entry point functions */
extern void rc_blink_sim_initialize(void);
extern void rc_blink_sim_step(void);
extern void rc_blink_sim_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rc_blink_sim_T *const rc_blink_sim_M;

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
 * '<Root>' : 'rc_blink_sim'
 * '<S1>'   : 'rc_blink_sim/Compare To Constant'
 * '<S2>'   : 'rc_blink_sim/Compare To Constant1'
 * '<S3>'   : 'rc_blink_sim/Compare To Zero'
 * '<S4>'   : 'rc_blink_sim/Counter Limited'
 * '<S5>'   : 'rc_blink_sim/Counter Limited/Increment Real World'
 * '<S6>'   : 'rc_blink_sim/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_rc_blink_sim_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
