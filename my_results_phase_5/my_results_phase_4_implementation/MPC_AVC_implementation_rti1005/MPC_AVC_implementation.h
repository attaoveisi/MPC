/*
 * MPC_AVC_implementation.h
 *
 * Real-Time Workshop code generation for Simulink model "MPC_AVC_implementation.mdl".
 *
 * Model Version              : 1.389
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Mar 02 12:18:25 2016
 */
#ifndef RTW_HEADER_MPC_AVC_implementation_h_
#define RTW_HEADER_MPC_AVC_implementation_h_
#ifndef MPC_AVC_implementation_COMMON_INCLUDES_
# define MPC_AVC_implementation_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rti_siggen_main.h>
#include <ds2102.h>
#include <ds2004.h>
#include <string.h>
#include <math.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtlibsrc.h"
#include "rt_nonfinite.h"
#include "rt_matrixlib.h"
#include "rt_defines.h"
#endif                                 /* MPC_AVC_implementation_COMMON_INCLUDES_ */

#include "MPC_AVC_implementation_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ((rtm)->Timing.mdlref_GlobalTID)
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ((rtm)->Timing.mdlref_GlobalTID = (val))
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ((rtm)->Timing.mdlref_TriggerTID)
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ((rtm)->Timing.mdlref_TriggerTID = (val))
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ((rtm)->modelMethodsInfo)
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ((rtm)->modelMethodsInfo = (val))
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define MPC_AVC_implementation_rtModel RT_MODEL_MPC_AVC_implementation

/* RTI Signal Generator blocks */
/* ... Type definition for signal generator structure pointers */
typedef struct RTISigGenPtr_tag {
  RTI_DSGenType SignalGenerator_1;     /* <Root>/Signal Generator */
} RTISigGenPtr_T;

/* ... Type definition for signal generator waveform parameters */
typedef struct RTISigGenWF_tag {
  int_T SignalGenerator_1;             /* <Root>/Signal Generator */
} RTISigGenWF_T;

/* Block signals (auto storage) */
typedef struct {
  real_T AnalogFilterDesign1;          /* '<Root>/Analog Filter Design1' */
  real_T Product[10];                  /* '<S2>/Product' */
  real_T Add2[10];                     /* '<S6>/Add2' */
  real_T UnitDelay16[2];               /* '<S2>/Unit Delay16' */
  real_T Gain13[2];                    /* '<S2>/Gain13' */
  real_T Gain16[4];                    /* '<S2>/Gain16' */
  real_T UnitDelay13[2];               /* '<S2>/Unit Delay13' */
  real_T Gain11[2];                    /* '<S2>/Gain11' */
  real_T Gain15[4];                    /* '<S2>/Gain15' */
  real_T UnitDelay14[2];               /* '<S2>/Unit Delay14' */
  real_T Gain12[2];                    /* '<S2>/Gain12' */
  real_T Gain18[4];                    /* '<S2>/Gain18' */
  real_T UnitDelay15[2];               /* '<S2>/Unit Delay15' */
  real_T Gain14[2];                    /* '<S2>/Gain14' */
  real_T Gain17[4];                    /* '<S2>/Gain17' */
  real_T UnitDelay12[2];               /* '<S2>/Unit Delay12' */
  real_T Gain25[2];                    /* '<S2>/Gain25' */
  real_T Gain28[4];                    /* '<S2>/Gain28' */
  real_T UnitDelay9[2];                /* '<S2>/Unit Delay9' */
  real_T Gain23[2];                    /* '<S2>/Gain23' */
  real_T Gain27[4];                    /* '<S2>/Gain27' */
  real_T UnitDelay10[2];               /* '<S2>/Unit Delay10' */
  real_T Gain24[2];                    /* '<S2>/Gain24' */
  real_T Gain30[4];                    /* '<S2>/Gain30' */
  real_T UnitDelay11[2];               /* '<S2>/Unit Delay11' */
  real_T Gain26[2];                    /* '<S2>/Gain26' */
  real_T Gain29[4];                    /* '<S2>/Gain29' */
  real_T UnitDelay7[2];                /* '<S2>/Unit Delay7' */
  real_T Gain33[2];                    /* '<S2>/Gain33' */
  real_T Gain36[4];                    /* '<S2>/Gain36' */
  real_T UnitDelay1[2];                /* '<S2>/Unit Delay1' */
  real_T Gain31[2];                    /* '<S2>/Gain31' */
  real_T Gain35[4];                    /* '<S2>/Gain35' */
  real_T UnitDelay2[2];                /* '<S2>/Unit Delay2' */
  real_T Gain32[2];                    /* '<S2>/Gain32' */
  real_T Gain38[4];                    /* '<S2>/Gain38' */
  real_T UnitDelay6[2];                /* '<S2>/Unit Delay6' */
  real_T Gain34[2];                    /* '<S2>/Gain34' */
  real_T Gain37[4];                    /* '<S2>/Gain37' */
  real_T Add1[4];                      /* '<S2>/Add1' */
  real_T L_m[2];                       /* '<S2>/L_m' */
  real_T Gain1[2];                     /* '<S2>/Gain1' */
  real_T Gain7[2];                     /* '<S2>/Gain7' */
  real_T Gain10[2];                    /* '<S2>/Gain10' */
  real_T Gain9[2];                     /* '<S2>/Gain9' */
  real_T Gain8[2];                     /* '<S2>/Gain8' */
  real_T Gain22[2];                    /* '<S2>/Gain22' */
  real_T Gain21[2];                    /* '<S2>/Gain21' */
  real_T Gain20[2];                    /* '<S2>/Gain20' */
  real_T Gain19[2];                    /* '<S2>/Gain19' */
  real_T Gain6[2];                     /* '<S2>/Gain6' */
  real_T Gain5[2];                     /* '<S2>/Gain5' */
  real_T Gain4[2];                     /* '<S2>/Gain4' */
  real_T Gain3[2];                     /* '<S2>/Gain3' */
  real_T Add[2];                       /* '<S2>/Add' */
  real_T Gain2[2];                     /* '<S2>/Gain2' */
  real_T Sum[2];                       /* '<S2>/Sum' */
  real_T Clock1;                       /* '<S1>/Clock1' */
  real_T Product_j;                    /* '<S1>/Product' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Product1;                     /* '<S1>/Product1' */
  real_T Sum_b;                        /* '<S1>/Sum' */
  real_T Product2;                     /* '<S1>/Product2' */
  real_T Output;                       /* '<S1>/Output' */
  real_T Gain1_m;                      /* '<Root>/Gain1' */
  real_T H[6];                         /* '<Root>/H' */
  real_T B[6];                         /* '<Root>/B' */
  real_T Delay[6];                     /* '<Root>/Delay' */
  real_T Ag[6];                        /* '<Root>/Ag' */
  real_T Add_f[6];                     /* '<Root>/Add' */
  real_T invBgBgHg[2];                 /* '<Root>/inv(Bg'*Bg)*Hg' */
  real_T on_off1[2];                   /* '<Root>/on_off1' */
  real_T Add2_m[2];                    /* '<Root>/Add2' */
  real_T Saturation[2];                /* '<Root>/Saturation' */
  real_T on_off2[2];                   /* '<Root>/on_off2' */
  real_T Amplifier[2];                 /* '<Root>/Amplifier' */
  real_T Amplifier2[2];                /* '<Root>/Amplifier2' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Piezo1_dspace;                /* '<Root>/Piezo1_dspace' */
  real_T dSpace_gain1[2];              /* '<Root>/dSpace_gain1' */
  real_T Amplifier1;                   /* '<Root>/Amplifier1' */
  real_T SFunction1;                   /* '<S3>/S-Function1' */
  real_T dSpace_gain2;                 /* '<Root>/dSpace_gain2' */
  real_T SignalGenerator;              /* '<Root>/Signal Generator' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T Step;                         /* '<Root>/Step' */
  real_T Delay_d[6];                   /* '<S9>/Delay' */
  real_T Ag_b[6];                      /* '<S9>/Ag' */
  real_T Bg[6];                        /* '<S9>/Bg' */
  real_T Add2_i[6];                    /* '<S9>/Add2' */
  real_T UnitDelay4;                   /* '<S9>/Unit Delay4' */
  real_T UnitDelay3;                   /* '<S9>/Unit Delay3' */
  real_T theta;                        /* '<S9>/MATLAB Function1' */
  real_T Ps1;                          /* '<S9>/MATLAB Function1' */
  real_T eta[10];                      /* '<S2>/MATLAB Function' */
  real_T UnitDelay3_f[18];             /* '<S7>/Unit Delay3' */
  real_T A[18];                        /* '<S7>/A' */
  real_T C;                            /* '<S7>/C' */
  real_T Integrator;                   /* '<S7>/Integrator' */
  real_T Gain_l;                       /* '<S7>/Gain' */
  real_T y;                            /* '<S7>/y' */
  real_T Sum1;                         /* '<S7>/Sum1' */
  real_T Product_l[18];                /* '<S7>/Product' */
  real_T y_j[18];                      /* '<S7>/MATLAB Function2' */
  real_T kk1;                          /* '<S7>/MATLAB Function1' */
  real_T B_i[18];                      /* '<S7>/B' */
  real_T Sum_l[18];                    /* '<S7>/Sum' */
} BlockIO_MPC_AVC_implementation;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay16_DSTATE[2];        /* '<S2>/Unit Delay16' */
  real_T UnitDelay13_DSTATE[2];        /* '<S2>/Unit Delay13' */
  real_T UnitDelay14_DSTATE[2];        /* '<S2>/Unit Delay14' */
  real_T UnitDelay15_DSTATE[2];        /* '<S2>/Unit Delay15' */
  real_T UnitDelay12_DSTATE[2];        /* '<S2>/Unit Delay12' */
  real_T UnitDelay9_DSTATE[2];         /* '<S2>/Unit Delay9' */
  real_T UnitDelay10_DSTATE[2];        /* '<S2>/Unit Delay10' */
  real_T UnitDelay11_DSTATE[2];        /* '<S2>/Unit Delay11' */
  real_T UnitDelay7_DSTATE[2];         /* '<S2>/Unit Delay7' */
  real_T UnitDelay1_DSTATE[2];         /* '<S2>/Unit Delay1' */
  real_T UnitDelay2_DSTATE[2];         /* '<S2>/Unit Delay2' */
  real_T UnitDelay6_DSTATE[2];         /* '<S2>/Unit Delay6' */
  real_T Delay_X[6];                   /* '<Root>/Delay' */
  real_T Delay_X_e[6];                 /* '<S9>/Delay' */
  real_T UnitDelay4_DSTATE;            /* '<S9>/Unit Delay4' */
  real_T UnitDelay3_DSTATE;            /* '<S9>/Unit Delay3' */
  real_T UnitDelay3_DSTATE_j[18];      /* '<S7>/Unit Delay3' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  struct {
    void *LoggedData;
  } Control_Signal_PWORK;              /* '<Root>/Control_Signal' */

  struct {
    void *LoggedData;
  } Control_Signal1_PWORK;             /* '<Root>/Control_Signal1' */

  struct {
    void *LoggedData;
  } disturbance_PWORK;                 /* '<Root>/disturbance' */

  struct {
    void *LoggedData;
  } velocimeter_PWORK;                 /* '<Root>/velocimeter' */

  struct {
    void *LoggedData;
  } Kalman_observation_PWORK;          /* '<S2>/Kalman_observation' */

  int32_T systemEnable;                /* '<Root>/Sine Wave' */
} D_Work_MPC_AVC_implementation;

/* Continuous states (auto storage) */
typedef struct {
  real_T AnalogFilterDesign1_CSTATE[4];/* '<Root>/Analog Filter Design1' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
} ContinuousStates_MPC_AVC_implem;

/* State derivatives (auto storage) */
typedef struct {
  real_T AnalogFilterDesign1_CSTATE[4];/* '<Root>/Analog Filter Design1' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
} StateDerivatives_MPC_AVC_implem;

/* State disabled  */
typedef struct {
  boolean_T AnalogFilterDesign1_CSTATE[4];/* '<Root>/Analog Filter Design1' */
  boolean_T Integrator_CSTATE;         /* '<S7>/Integrator' */
} StateDisabled_MPC_AVC_implement;

#ifndef ODE5_INTG
#define ODE5_INTG

/* ODE5 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[6];                        /* derivatives */
} ODE5_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            MPC_AVC_implementation_B
#define BlockIO                        BlockIO_MPC_AVC_implementation
#define rtX                            MPC_AVC_implementation_X
#define ContinuousStates               ContinuousStates_MPC_AVC_implem
#define rtP                            MPC_AVC_implementation_P
#define Parameters                     Parameters_MPC_AVC_implementati
#define rtDWork                        MPC_AVC_implementation_DWork
#define D_Work                         D_Work_MPC_AVC_implementation

/* Parameters (auto storage) */
struct Parameters_MPC_AVC_implementati {
  real_T omega_Value[100];             /* Expression: omega
                                        * '<S2>/omega'
                                        */
  real_T psi_Value[180];               /* Expression: psi
                                        * '<S2>/psi'
                                        */
  real_T AnalogFilterDesign1_A[7];     /* Computed Parameter: A
                                        * '<Root>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_B;        /* Computed Parameter: B
                                        * '<Root>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_C;        /* Computed Parameter: C
                                        * '<Root>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_X0;       /* Expression: 0
                                        * '<Root>/Analog Filter Design1'
                                        */
  real_T zeros110_Value[10];           /* Expression: zeros(1,10)
                                        * '<S6>/zeros(1,10)'
                                        */
  real_T A_cons_Value[40];             /* Expression: A_cons
                                        * '<S2>/A_cons'
                                        */
  real_T UnitDelay16_X0;               /* Expression: 0
                                        * '<S2>/Unit Delay16'
                                        */
  real_T Gain13_Gain;                  /* Expression: -1
                                        * '<S2>/Gain13'
                                        */
  real_T Gain16_Gain;                  /* Expression: coefs(1,1)
                                        * '<S2>/Gain16'
                                        */
  real_T UnitDelay13_X0;               /* Expression: 0
                                        * '<S2>/Unit Delay13'
                                        */
  real_T Gain11_Gain;                  /* Expression: -1
                                        * '<S2>/Gain11'
                                        */
  real_T Gain15_Gain;                  /* Expression: coefs(1,2)
                                        * '<S2>/Gain15'
                                        */
  real_T UnitDelay14_X0;               /* Expression: 0
                                        * '<S2>/Unit Delay14'
                                        */
  real_T Gain12_Gain;                  /* Expression: -1
                                        * '<S2>/Gain12'
                                        */
  real_T Gain18_Gain;                  /* Expression: coefs(1,3)
                                        * '<S2>/Gain18'
                                        */
  real_T UnitDelay15_X0;               /* Expression: 0
                                        * '<S2>/Unit Delay15'
                                        */
  real_T Gain14_Gain;                  /* Expression: -1
                                        * '<S2>/Gain14'
                                        */
  real_T Gain17_Gain;                  /* Expression: coefs(1,4)
                                        * '<S2>/Gain17'
                                        */
  real_T UnitDelay12_X0;               /* Expression: 0
                                        * '<S2>/Unit Delay12'
                                        */
  real_T Gain25_Gain;                  /* Expression: -1
                                        * '<S2>/Gain25'
                                        */
  real_T Gain28_Gain;                  /* Expression: coefs(1,5)
                                        * '<S2>/Gain28'
                                        */
  real_T UnitDelay9_X0;                /* Expression: 0
                                        * '<S2>/Unit Delay9'
                                        */
  real_T Gain23_Gain;                  /* Expression: -1
                                        * '<S2>/Gain23'
                                        */
  real_T Gain27_Gain;                  /* Expression: coefs(1,6)
                                        * '<S2>/Gain27'
                                        */
  real_T UnitDelay10_X0;               /* Expression: 0
                                        * '<S2>/Unit Delay10'
                                        */
  real_T Gain24_Gain;                  /* Expression: -1
                                        * '<S2>/Gain24'
                                        */
  real_T Gain30_Gain;                  /* Expression: coefs(1,7)
                                        * '<S2>/Gain30'
                                        */
  real_T UnitDelay11_X0;               /* Expression: 0
                                        * '<S2>/Unit Delay11'
                                        */
  real_T Gain26_Gain;                  /* Expression: -1
                                        * '<S2>/Gain26'
                                        */
  real_T Gain29_Gain;                  /* Expression: coefs(1,8)
                                        * '<S2>/Gain29'
                                        */
  real_T UnitDelay7_X0;                /* Expression: 0
                                        * '<S2>/Unit Delay7'
                                        */
  real_T Gain33_Gain;                  /* Expression: -1
                                        * '<S2>/Gain33'
                                        */
  real_T Gain36_Gain;                  /* Expression: coefs(1,9)
                                        * '<S2>/Gain36'
                                        */
  real_T UnitDelay1_X0;                /* Expression: 0
                                        * '<S2>/Unit Delay1'
                                        */
  real_T Gain31_Gain;                  /* Expression: -1
                                        * '<S2>/Gain31'
                                        */
  real_T Gain35_Gain;                  /* Expression: coefs(1,10)
                                        * '<S2>/Gain35'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * '<S2>/Unit Delay2'
                                        */
  real_T Gain32_Gain;                  /* Expression: -1
                                        * '<S2>/Gain32'
                                        */
  real_T Gain38_Gain;                  /* Expression: coefs(1,11)
                                        * '<S2>/Gain38'
                                        */
  real_T UnitDelay6_X0;                /* Expression: 0
                                        * '<S2>/Unit Delay6'
                                        */
  real_T Gain34_Gain;                  /* Expression: -1
                                        * '<S2>/Gain34'
                                        */
  real_T Gain37_Gain;                  /* Expression: coefs(1,12)
                                        * '<S2>/Gain37'
                                        */
  real_T B_cons1_Value[4];             /* Expression: u_bound
                                        * '<S2>/B_cons1'
                                        */
  real_T L_m_Gain[20];                 /* Expression: L_m
                                        * '<S2>/L_m'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * '<S2>/Gain1'
                                        */
  real_T Gain7_Gain;                   /* Expression: coefs(1,1)
                                        * '<S2>/Gain7'
                                        */
  real_T Gain10_Gain;                  /* Expression: coefs(1,2)
                                        * '<S2>/Gain10'
                                        */
  real_T Gain9_Gain;                   /* Expression: coefs(1,3)
                                        * '<S2>/Gain9'
                                        */
  real_T Gain8_Gain;                   /* Expression: coefs(1,4)
                                        * '<S2>/Gain8'
                                        */
  real_T Gain22_Gain;                  /* Expression: coefs(1,5)
                                        * '<S2>/Gain22'
                                        */
  real_T Gain21_Gain;                  /* Expression: coefs(1,6)
                                        * '<S2>/Gain21'
                                        */
  real_T Gain20_Gain;                  /* Expression: coefs(1,7)
                                        * '<S2>/Gain20'
                                        */
  real_T Gain19_Gain;                  /* Expression: coefs(1,8)
                                        * '<S2>/Gain19'
                                        */
  real_T Gain6_Gain;                   /* Expression: coefs(1,9)
                                        * '<S2>/Gain6'
                                        */
  real_T Gain5_Gain;                   /* Expression: coefs(1,10)
                                        * '<S2>/Gain5'
                                        */
  real_T Gain4_Gain;                   /* Expression: coefs(1,11)
                                        * '<S2>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: coefs(1,12)
                                        * '<S2>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * '<S2>/Gain2'
                                        */
  real_T deltaFreq_Value;              /* Expression: 2*pi*(f2-f1)
                                        * '<S1>/deltaFreq'
                                        */
  real_T targetTime_Value;             /* Expression: T
                                        * '<S1>/targetTime'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * '<S1>/Gain'
                                        */
  real_T initialFreq_Value;            /* Expression: 2*pi*f1
                                        * '<S1>/initialFreq'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 0.5
                                        * '<Root>/Gain1'
                                        */
  real_T H_Gain[6];                    /* Expression: Hg
                                        * '<Root>/H'
                                        */
  real_T B_Gain[12];                   /* Expression: Bg
                                        * '<Root>/B'
                                        */
  real_T Delay_InitialCondition;       /* Expression: vinit
                                        * '<Root>/Delay'
                                        */
  real_T Ag_Gain[36];                  /* Expression: Ag
                                        * '<Root>/Ag'
                                        */
  real_T invBgBgHg_Gain[2];            /* Expression: inv(Bg'*Bg)*(Bg'*Hg)
                                        * '<Root>/inv(Bg'*Bg)*Hg'
                                        */
  real_T on_off1_Gain;                 /* Expression: -0.15
                                        * '<Root>/on_off1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 2
                                        * '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -2
                                        * '<Root>/Saturation'
                                        */
  real_T on_off2_Gain;                 /* Expression: 1
                                        * '<Root>/on_off2'
                                        */
  real_T Amplifier_Gain;               /* Expression: 100
                                        * '<Root>/Amplifier'
                                        */
  real_T Amplifier2_Gain;              /* Expression: 100
                                        * '<Root>/Amplifier2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * '<Root>/Saturation1'
                                        */
  real_T Piezo1_dspace_Gain;           /* Expression: 0.1
                                        * '<Root>/Piezo1_dspace'
                                        */
  real_T dSpace_gain1_Gain;            /* Expression: 0.1
                                        * '<Root>/dSpace_gain1'
                                        */
  real_T Amplifier1_Gain;              /* Expression: 125
                                        * '<Root>/Amplifier1'
                                        */
  real_T dSpace_gain2_Gain;            /* Expression: 0.1
                                        * '<Root>/dSpace_gain2'
                                        */
  real_T SignalGenerator_Amplitude;    /* Expression: 1
                                        * '<Root>/Signal Generator'
                                        */
  real_T SignalGenerator_Frequency;    /* Expression: 1/2.5
                                        * '<Root>/Signal Generator'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 71*2*pi
                                        * '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SinH
                                        * '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: CosH
                                        * '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SinPhi
                                        * '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: CosPhi
                                        * '<Root>/Sine Wave'
                                        */
  real_T Step_Time;                    /* Expression: 2*dt
                                        * '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * '<Root>/Step'
                                        */
  real_T B_Gain_k[36];                 /* Expression: B
                                        * '<S7>/B'
                                        */
  real_T UnitDelay3_X0;                /* Expression: 0
                                        * '<S7>/Unit Delay3'
                                        */
  real_T A_Gain[324];                  /* Expression: A
                                        * '<S7>/A'
                                        */
  real_T C_Gain[18];                   /* Expression: C
                                        * '<S7>/C'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * '<S7>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * '<S7>/Integrator'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 1/dt
                                        * '<S7>/Gain'
                                        */
  real_T Lf1_Value[449982];            /* Expression: Lf
                                        * '<S7>/Lf1'
                                        */
  real_T Delay_InitialCondition_j;     /* Expression: vinit
                                        * '<S9>/Delay'
                                        */
  real_T Ag_Gain_k[36];                /* Expression: Ag
                                        * '<S9>/Ag'
                                        */
  real_T Bg_Gain[12];                  /* Expression: Bg
                                        * '<S9>/Bg'
                                        */
  real_T Hg_Value[6];                  /* Expression: Hg
                                        * '<S9>/Hg'
                                        */
  real_T Ps_Value;                     /* Expression: Ps
                                        * '<S9>/Ps'
                                        */
  real_T UnitDelay4_X0;                /* Expression: 0
                                        * '<S9>/Unit Delay4'
                                        */
  real_T Rs_Value;                     /* Expression: Rs
                                        * '<S9>/Rs'
                                        */
  real_T UnitDelay3_X0_o;              /* Expression: 0
                                        * '<S9>/Unit Delay3'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_MPC_AVC_implementation {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[5];
    real_T odeF[6][5];
    ODE5_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_MPC_AVC_implementati MPC_AVC_implementation_P;

/* Block signals (auto storage) */
extern BlockIO_MPC_AVC_implementation MPC_AVC_implementation_B;

/* Continuous states (auto storage) */
extern ContinuousStates_MPC_AVC_implem MPC_AVC_implementation_X;

/* Block states (auto storage) */
extern D_Work_MPC_AVC_implementation MPC_AVC_implementation_DWork;

/* Model entry point functions */
extern void MPC_AVC_implementation_initialize(boolean_T firstTime);
extern void MPC_AVC_implementation_output(int_T tid);
extern void MPC_AVC_implementation_update(int_T tid);
extern void MPC_AVC_implementation_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MPC_AVC_implementation *MPC_AVC_implementation_M;

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
 * '<Root>' : MPC_AVC_implementation
 * '<S1>'   : MPC_AVC_implementation/Chirp Signal
 * '<S2>'   : MPC_AVC_implementation/Controller
 * '<S3>'   : MPC_AVC_implementation/DS2004ADC_BL1
 * '<S4>'   : MPC_AVC_implementation/DS2102_B1
 * '<S5>'   : MPC_AVC_implementation/RTI Data
 * '<S6>'   : MPC_AVC_implementation/Controller/Dumm_subsys
 * '<S7>'   : MPC_AVC_implementation/Controller/Kalman Filter
 * '<S8>'   : MPC_AVC_implementation/Controller/MATLAB Function
 * '<S9>'   : MPC_AVC_implementation/Controller/Recursive LS_all
 * '<S10>'  : MPC_AVC_implementation/Controller/Kalman Filter/MATLAB Function1
 * '<S11>'  : MPC_AVC_implementation/Controller/Kalman Filter/MATLAB Function2
 * '<S12>'  : MPC_AVC_implementation/Controller/Recursive LS_all/MATLAB Function1
 * '<S13>'  : MPC_AVC_implementation/RTI Data/RTI Data Store
 * '<S14>'  : MPC_AVC_implementation/RTI Data/RTI Data Store/RTI Data Store
 * '<S15>'  : MPC_AVC_implementation/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store
 */
#endif                                 /* RTW_HEADER_MPC_AVC_implementation_h_ */
