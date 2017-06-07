/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BBBL_Test2.h
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

#ifndef RTW_HEADER_BBBL_Test2_h_
#define RTW_HEADER_BBBL_Test2_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef BBBL_Test2_COMMON_INCLUDES_
# define BBBL_Test2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "roboticscape.h"
#endif                                 /* BBBL_Test2_COMMON_INCLUDES_ */

#include "BBBL_Test2_types.h"

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
  real_T b2;                           /* '<Root>/b2' */
  real_T y;                            /* '<Root>/Sum' */
  uint8_T Output;                      /* '<S3>/Output' */
  uint8_T Compare;                     /* '<S1>/Compare' */
} B_BBBL_Test2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } u0_PWORK;                          /* '<Root>/<=20' */

  struct {
    void *LoggedData;
  } Counter_PWORK;                     /* '<Root>/Counter' */

  struct {
    void *LoggedData;
  } Input_PWORK;                       /* '<Root>/Input' */

  struct {
    void *LoggedData;
  } Output_PWORK;                      /* '<Root>/Output' */

  void *MATLABSystem_PWORK;            /* '<Root>/MATLAB System' */
  rc_blink_sys_BBBL_Test2_T obj;       /* '<Root>/MATLAB System' */
  uint8_T Output_DSTATE;               /* '<S3>/Output' */
} DW_BBBL_Test2_T;

/* Parameters (auto storage) */
struct P_BBBL_Test2_T_ {
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T CounterLimited_uplimit;      /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S5>/FixPt Switch'
                                        */
  real_T b2_Gain;                      /* Expression: 20
                                        * Referenced by: '<Root>/b2'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T a_Gain;                       /* Expression: 0.8
                                        * Referenced by: '<Root>/a'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S3>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S4>/FixPt Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BBBL_Test2_T {
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
extern P_BBBL_Test2_T BBBL_Test2_P;

/* Block signals (auto storage) */
extern B_BBBL_Test2_T BBBL_Test2_B;

/* Block states (auto storage) */
extern DW_BBBL_Test2_T BBBL_Test2_DW;

/* Model entry point functions */
extern void BBBL_Test2_initialize(void);
extern void BBBL_Test2_step(void);
extern void BBBL_Test2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BBBL_Test2_T *const BBBL_Test2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

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
 * '<Root>' : 'BBBL_Test2'
 * '<S1>'   : 'BBBL_Test2/Compare To Constant'
 * '<S2>'   : 'BBBL_Test2/Compare To Constant1'
 * '<S3>'   : 'BBBL_Test2/Counter Limited'
 * '<S4>'   : 'BBBL_Test2/Counter Limited/Increment Real World'
 * '<S5>'   : 'BBBL_Test2/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_BBBL_Test2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
