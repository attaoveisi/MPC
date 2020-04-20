/*
 * MPC_AVC_implementation.c
 *
 * Real-Time Workshop code generation for Simulink model "MPC_AVC_implementation.mdl".
 *
 * Model Version              : 1.398
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Mar 02 15:01:05 2016
 */

#include "MPC_AVC_implementation_trc_ptr.h"
#include "MPC_AVC_implementation.h"
#include "MPC_AVC_implementation_private.h"

/* RTI Signal Generator blocks */
/* ... Declaration of signal generator structure pointers */
RTISigGenPtr_T RTISigGenPtr = {
  NULL                                 /* <Root>/Signal Generator */
};

/* ... Declaration of signal generator waveform parameters */
RTISigGenWF_T RTISigGenWF = {
  2                                    /* <Root>/Signal Generator (square) */
};

/* Block signals (auto storage) */
BlockIO_MPC_AVC_implementation MPC_AVC_implementation_B;

/* Continuous states */
ContinuousStates_MPC_AVC_implem MPC_AVC_implementation_X;

/* Solver Matrices */

/* A and B matrices used by ODE5 fixed-step solver */
static const real_T rt_ODE5_A[6] = {
  1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
};

static const real_T rt_ODE5_B[6][6] = {
  { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

  { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

  { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

  { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0, 0.0
  },

  { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
};

/* Block states (auto storage) */
D_Work_MPC_AVC_implementation MPC_AVC_implementation_DWork;

/* Real-time model */
RT_MODEL_MPC_AVC_implementation MPC_AVC_implementation_M_;
RT_MODEL_MPC_AVC_implementation *MPC_AVC_implementation_M =
  &MPC_AVC_implementation_M_;

/* This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  MPC_AVC_implementation_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  MPC_AVC_implementation_output(0);
  MPC_AVC_implementation_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++)
    hB[i] = h * rt_ODE5_B[1][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  MPC_AVC_implementation_output(0);
  MPC_AVC_implementation_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++)
    hB[i] = h * rt_ODE5_B[2][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  MPC_AVC_implementation_output(0);
  MPC_AVC_implementation_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++)
    hB[i] = h * rt_ODE5_B[3][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  MPC_AVC_implementation_output(0);
  MPC_AVC_implementation_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++)
    hB[i] = h * rt_ODE5_B[4][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  MPC_AVC_implementation_output(0);
  MPC_AVC_implementation_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++)
    hB[i] = h * rt_ODE5_B[5][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void MPC_AVC_implementation_output(int_T tid)
{
  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(MPC_AVC_implementation_M)) {
    MPC_AVC_implementation_M->Timing.t[0] = rtsiGetT
      (&MPC_AVC_implementation_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(MPC_AVC_implementation_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&MPC_AVC_implementation_M->solverInfo,
                          ((MPC_AVC_implementation_M->Timing.clockTick0+1)*
      MPC_AVC_implementation_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T tmp;

    /* StateSpace Block: '<Root>/Analog Filter Design1' */
    {
      MPC_AVC_implementation_B.AnalogFilterDesign1 =
        MPC_AVC_implementation_P.AnalogFilterDesign1_C*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[3];
    }

    /* Gain: '<S4>/Proportional Gain' */
    MPC_AVC_implementation_B.ProportionalGain =
      MPC_AVC_implementation_P.ProportionalGain_Gain *
      MPC_AVC_implementation_B.AnalogFilterDesign1;

    /* Integrator: '<S4>/Integrator' */
    MPC_AVC_implementation_B.Integrator =
      MPC_AVC_implementation_X.Integrator_CSTATE;

    /* Gain: '<S4>/Derivative Gain' */
    MPC_AVC_implementation_B.DerivativeGain =
      MPC_AVC_implementation_P.DerivativeGain_Gain *
      MPC_AVC_implementation_B.AnalogFilterDesign1;

    /* Derivative Block: '<S4>/Ideal Derivative' */
    {
      real_T t = MPC_AVC_implementation_M->Timing.t[0];
      real_T timeStampA =
        MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampA;
      real_T timeStampB =
        MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        MPC_AVC_implementation_B.IdealDerivative = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank =
          &MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        MPC_AVC_implementation_B.IdealDerivative =
          (MPC_AVC_implementation_B.DerivativeGain - *lastBank++) / deltaT;
      }
    }

    /* Sum: '<S4>/Sum' */
    MPC_AVC_implementation_B.Sum = (MPC_AVC_implementation_B.ProportionalGain +
      MPC_AVC_implementation_B.Integrator) +
      MPC_AVC_implementation_B.IdealDerivative;

    /* Saturate: '<Root>/Saturation' */
    tmp = MPC_AVC_implementation_B.Sum;
    MPC_AVC_implementation_B.Saturation = rt_SATURATE(tmp,
      MPC_AVC_implementation_P.Saturation_LowerSat,
      MPC_AVC_implementation_P.Saturation_UpperSat);

    /* Gain: '<Root>/Amplifier2' */
    MPC_AVC_implementation_B.Amplifier2 =
      MPC_AVC_implementation_P.Amplifier2_Gain *
      MPC_AVC_implementation_B.Saturation;
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* Gain: '<S5>/Proportional Gain' */
    MPC_AVC_implementation_B.ProportionalGain_l =
      MPC_AVC_implementation_P.ProportionalGain_Gain_i *
      MPC_AVC_implementation_B.AnalogFilterDesign1;

    /* Integrator: '<S5>/Integrator' */
    MPC_AVC_implementation_B.Integrator_a =
      MPC_AVC_implementation_X.Integrator_CSTATE_a;

    /* Gain: '<S5>/Derivative Gain' */
    MPC_AVC_implementation_B.DerivativeGain_g =
      MPC_AVC_implementation_P.DerivativeGain_Gain_l *
      MPC_AVC_implementation_B.AnalogFilterDesign1;

    /* Derivative Block: '<S5>/Ideal Derivative' */
    {
      real_T t = MPC_AVC_implementation_M->Timing.t[0];
      real_T timeStampA =
        MPC_AVC_implementation_DWork.IdealDerivative_RWORK_b.TimeStampA;
      real_T timeStampB =
        MPC_AVC_implementation_DWork.IdealDerivative_RWORK_b.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        MPC_AVC_implementation_B.IdealDerivative_f = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank =
          &MPC_AVC_implementation_DWork.IdealDerivative_RWORK_b.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        MPC_AVC_implementation_B.IdealDerivative_f =
          (MPC_AVC_implementation_B.DerivativeGain_g - *lastBank++) / deltaT;
      }
    }

    /* Sum: '<S5>/Sum' */
    MPC_AVC_implementation_B.Sum_j =
      (MPC_AVC_implementation_B.ProportionalGain_l +
       MPC_AVC_implementation_B.Integrator_a) +
      MPC_AVC_implementation_B.IdealDerivative_f;

    /* Saturate: '<Root>/Saturation2' */
    tmp = MPC_AVC_implementation_B.Sum_j;
    MPC_AVC_implementation_B.Saturation2 = rt_SATURATE(tmp,
      MPC_AVC_implementation_P.Saturation2_LowerSat,
      MPC_AVC_implementation_P.Saturation2_UpperSat);

    /* Gain: '<Root>/Amplifier' */
    MPC_AVC_implementation_B.Amplifier = MPC_AVC_implementation_P.Amplifier_Gain
      * MPC_AVC_implementation_B.Saturation2;
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* SignalGenerator Block: '<Root>/Signal Generator'
     */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M)) {
      MPC_AVC_implementation_B.SignalGenerator = rti_siggen_output
        (RTISigGenWF.SignalGenerator_1,
         MPC_AVC_implementation_P.SignalGenerator_Amplitude,
         MPC_AVC_implementation_P.SignalGenerator_Frequency,
         RTISigGenPtr.SignalGenerator_1);
    }

    /* Gain: '<Root>/Gain1' */
    MPC_AVC_implementation_B.Gain1 = MPC_AVC_implementation_P.Gain1_Gain *
      MPC_AVC_implementation_B.SignalGenerator;

    /* Saturate: '<Root>/Saturation1' */
    tmp = MPC_AVC_implementation_B.Gain1;
    MPC_AVC_implementation_B.Saturation1 = rt_SATURATE(tmp,
      MPC_AVC_implementation_P.Saturation1_LowerSat,
      MPC_AVC_implementation_P.Saturation1_UpperSat);

    /* Gain: '<Root>/Piezo1_dspace' */
    MPC_AVC_implementation_B.Piezo1_dspace =
      MPC_AVC_implementation_P.Piezo1_dspace_Gain *
      MPC_AVC_implementation_B.Saturation1;
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL1 */
      ds2102_out(DS2102_1_BASE, 1, (dsfloat)
                 MPC_AVC_implementation_B.Piezo1_dspace);
    }

    /* Gain: '<Root>/dSpace_gain1' */
    MPC_AVC_implementation_B.dSpace_gain1 =
      MPC_AVC_implementation_P.dSpace_gain1_Gain *
      MPC_AVC_implementation_B.Saturation;
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL2 */
      ds2102_out(DS2102_1_BASE, 2, (dsfloat)
                 MPC_AVC_implementation_B.dSpace_gain1);
    }

    /* Gain: '<Root>/dSpace_gain3' */
    MPC_AVC_implementation_B.dSpace_gain3 =
      MPC_AVC_implementation_P.dSpace_gain3_Gain *
      MPC_AVC_implementation_B.Saturation2;
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL3 */
      ds2102_out(DS2102_1_BASE, 3, (dsfloat)
                 MPC_AVC_implementation_B.dSpace_gain3);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* This comment workarounds a Real-Time Workshop code generation problem */
    }

    /* Gain: '<Root>/Amplifier1' */
    MPC_AVC_implementation_B.Amplifier1 =
      MPC_AVC_implementation_P.Amplifier1_Gain *
      MPC_AVC_implementation_B.AnalogFilterDesign1;
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */
      {
        /* dSPACE I/O Board DS2004 #1 Unit:ADC Group:ADC */
        ds2004_single_in(DS2004_1_BASE,
                         DS2004_CH1,
                         (dsfloat *)&MPC_AVC_implementation_B.SFunction1);
      }
    }

    /* Gain: '<S4>/Integral Gain' */
    MPC_AVC_implementation_B.IntegralGain =
      MPC_AVC_implementation_P.IntegralGain_Gain *
      MPC_AVC_implementation_B.AnalogFilterDesign1;

    /* Gain: '<S5>/Integral Gain' */
    MPC_AVC_implementation_B.IntegralGain_p =
      MPC_AVC_implementation_P.IntegralGain_Gain_c *
      MPC_AVC_implementation_B.AnalogFilterDesign1;
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<Root>/dSpace_gain2' */
      MPC_AVC_implementation_B.dSpace_gain2 =
        MPC_AVC_implementation_P.dSpace_gain2_Gain *
        MPC_AVC_implementation_B.SFunction1;
    }

    /* Clock Block: '<S1>/Clock1'
     */
    MPC_AVC_implementation_B.Clock1 = MPC_AVC_implementation_M->Timing.t[0];
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Product: '<S1>/Product' incorporates:
       *  Constant: '<S1>/deltaFreq'
       *  Constant: '<S1>/targetTime'
       */
      MPC_AVC_implementation_B.Product =
        MPC_AVC_implementation_P.deltaFreq_Value /
        MPC_AVC_implementation_P.targetTime_Value;

      /* Gain: '<S1>/Gain' */
      MPC_AVC_implementation_B.Gain = MPC_AVC_implementation_P.Gain_Gain *
        MPC_AVC_implementation_B.Product;
    }

    /* Product: '<S1>/Product1' */
    MPC_AVC_implementation_B.Product1 = MPC_AVC_implementation_B.Clock1 *
      MPC_AVC_implementation_B.Gain;

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/initialFreq'
     */
    MPC_AVC_implementation_B.Sum_b = MPC_AVC_implementation_B.Product1 +
      MPC_AVC_implementation_P.initialFreq_Value;

    /* Product: '<S1>/Product2' */
    MPC_AVC_implementation_B.Product2 = MPC_AVC_implementation_B.Clock1 *
      MPC_AVC_implementation_B.Sum_b;

    /* Trigonometry: '<S1>/Output' */
    MPC_AVC_implementation_B.Output = sin(MPC_AVC_implementation_B.Product2);

    /* user code (Output function Trailer) */
    /* dSPACE Data Capture block: (none) */
    /* ... Service number: 1 */
    /* ... Service name:   (default) */
    if (rtmIsContinuousTask(MPC_AVC_implementation_M, 0) && rtmIsMajorTimeStep
        (MPC_AVC_implementation_M)) {
      host_service(1, rtk_current_task_absolute_time_ptr_get());

#ifdef RTT_ENABLE

      DsDaq_Service(1, (DsDaqSTimestampStruct *)
                    rtk_current_task_absolute_time_ptr_get());

#endif

    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void MPC_AVC_implementation_update(int_T tid)
{
  /* Derivative Block: '<S4>/Ideal Derivative' */
  {
    real_T timeStampA =
      MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampA;
    real_T timeStampB =
      MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampB;
    real_T *lastBank =
      &MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }

    *lastBank++ = MPC_AVC_implementation_M->Timing.t[0];
    *lastBank++ = MPC_AVC_implementation_B.DerivativeGain;
  }

  /* Derivative Block: '<S5>/Ideal Derivative' */
  {
    real_T timeStampA =
      MPC_AVC_implementation_DWork.IdealDerivative_RWORK_b.TimeStampA;
    real_T timeStampB =
      MPC_AVC_implementation_DWork.IdealDerivative_RWORK_b.TimeStampB;
    real_T *lastBank =
      &MPC_AVC_implementation_DWork.IdealDerivative_RWORK_b.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }

    *lastBank++ = MPC_AVC_implementation_M->Timing.t[0];
    *lastBank++ = MPC_AVC_implementation_B.DerivativeGain_g;
  }

  if (rtmIsMajorTimeStep(MPC_AVC_implementation_M)) {
    rt_ertODEUpdateContinuousStates(&MPC_AVC_implementation_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++MPC_AVC_implementation_M->Timing.clockTick0))
    ++MPC_AVC_implementation_M->Timing.clockTickH0;
  MPC_AVC_implementation_M->Timing.t[0] =
    MPC_AVC_implementation_M->Timing.clockTick0 *
    MPC_AVC_implementation_M->Timing.stepSize0 +
    MPC_AVC_implementation_M->Timing.clockTickH0 *
    MPC_AVC_implementation_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
      MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++MPC_AVC_implementation_M->Timing.clockTick1))
      ++MPC_AVC_implementation_M->Timing.clockTickH1;
    MPC_AVC_implementation_M->Timing.t[1] =
      MPC_AVC_implementation_M->Timing.clockTick1 *
      MPC_AVC_implementation_M->Timing.stepSize1 +
      MPC_AVC_implementation_M->Timing.clockTickH1 *
      MPC_AVC_implementation_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MPC_AVC_implementation_derivatives(void)
{
  /* StateSpace Block: '<Root>/Analog Filter Design1' */
  {
    ((StateDerivatives_MPC_AVC_implem *)
      MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE[0]
      = MPC_AVC_implementation_P.AnalogFilterDesign1_B*
      MPC_AVC_implementation_B.dSpace_gain2;
    ((StateDerivatives_MPC_AVC_implem *)
      MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE[0]
      += (MPC_AVC_implementation_P.AnalogFilterDesign1_A[0])*
      MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[0]
      + (MPC_AVC_implementation_P.AnalogFilterDesign1_A[1])*
      MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[1];
    ((StateDerivatives_MPC_AVC_implem *)
      MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE[1]
      = (MPC_AVC_implementation_P.AnalogFilterDesign1_A[2])*
      MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[0];
    ((StateDerivatives_MPC_AVC_implem *)
      MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE[2]
      = (MPC_AVC_implementation_P.AnalogFilterDesign1_A[3])*
      MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[1]
      + (MPC_AVC_implementation_P.AnalogFilterDesign1_A[4])*
      MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[2]
      + (MPC_AVC_implementation_P.AnalogFilterDesign1_A[5])*
      MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[3];
    ((StateDerivatives_MPC_AVC_implem *)
      MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE[3]
      = (MPC_AVC_implementation_P.AnalogFilterDesign1_A[6])*
      MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[2];
  }

  /* Derivatives for Integrator: '<S4>/Integrator' */
  ((StateDerivatives_MPC_AVC_implem *)
    MPC_AVC_implementation_M->ModelData.derivs)->Integrator_CSTATE =
    MPC_AVC_implementation_B.IntegralGain;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  ((StateDerivatives_MPC_AVC_implem *)
    MPC_AVC_implementation_M->ModelData.derivs)->Integrator_CSTATE_a =
    MPC_AVC_implementation_B.IntegralGain_p;
}

/* Model initialize function */
void MPC_AVC_implementation_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((char_T *)MPC_AVC_implementation_M,0,
                sizeof(RT_MODEL_MPC_AVC_implementation));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MPC_AVC_implementation_M->solverInfo,
                          &MPC_AVC_implementation_M->Timing.simTimeStep);
    rtsiSetTPtr(&MPC_AVC_implementation_M->solverInfo, &rtmGetTPtr
                (MPC_AVC_implementation_M));
    rtsiSetStepSizePtr(&MPC_AVC_implementation_M->solverInfo,
                       &MPC_AVC_implementation_M->Timing.stepSize0);
    rtsiSetdXPtr(&MPC_AVC_implementation_M->solverInfo,
                 &MPC_AVC_implementation_M->ModelData.derivs);
    rtsiSetContStatesPtr(&MPC_AVC_implementation_M->solverInfo,
                         &MPC_AVC_implementation_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&MPC_AVC_implementation_M->solverInfo,
      &MPC_AVC_implementation_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&MPC_AVC_implementation_M->solverInfo,
                          (&rtmGetErrorStatus(MPC_AVC_implementation_M)));
    rtsiSetRTModelPtr(&MPC_AVC_implementation_M->solverInfo,
                      MPC_AVC_implementation_M);
  }

  rtsiSetSimTimeStep(&MPC_AVC_implementation_M->solverInfo, MAJOR_TIME_STEP);
  MPC_AVC_implementation_M->ModelData.intgData.y =
    MPC_AVC_implementation_M->ModelData.odeY;
  MPC_AVC_implementation_M->ModelData.intgData.f[0] =
    MPC_AVC_implementation_M->ModelData.odeF[0];
  MPC_AVC_implementation_M->ModelData.intgData.f[1] =
    MPC_AVC_implementation_M->ModelData.odeF[1];
  MPC_AVC_implementation_M->ModelData.intgData.f[2] =
    MPC_AVC_implementation_M->ModelData.odeF[2];
  MPC_AVC_implementation_M->ModelData.intgData.f[3] =
    MPC_AVC_implementation_M->ModelData.odeF[3];
  MPC_AVC_implementation_M->ModelData.intgData.f[4] =
    MPC_AVC_implementation_M->ModelData.odeF[4];
  MPC_AVC_implementation_M->ModelData.intgData.f[5] =
    MPC_AVC_implementation_M->ModelData.odeF[5];
  MPC_AVC_implementation_M->ModelData.contStates = ((real_T *)
    &MPC_AVC_implementation_X);
  rtsiSetSolverData(&MPC_AVC_implementation_M->solverInfo, (void *)
                    &MPC_AVC_implementation_M->ModelData.intgData);
  rtsiSetSolverName(&MPC_AVC_implementation_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = MPC_AVC_implementation_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    MPC_AVC_implementation_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    MPC_AVC_implementation_M->Timing.sampleTimes =
      (&MPC_AVC_implementation_M->Timing.sampleTimesArray[0]);
    MPC_AVC_implementation_M->Timing.offsetTimes =
      (&MPC_AVC_implementation_M->Timing.offsetTimesArray[0]);

    /* task periods */
    MPC_AVC_implementation_M->Timing.sampleTimes[0] = (0.0);
    MPC_AVC_implementation_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    MPC_AVC_implementation_M->Timing.offsetTimes[0] = (0.0);
    MPC_AVC_implementation_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(MPC_AVC_implementation_M, &MPC_AVC_implementation_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = MPC_AVC_implementation_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    MPC_AVC_implementation_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(MPC_AVC_implementation_M, -1);
  MPC_AVC_implementation_M->Timing.stepSize0 = 0.001;
  MPC_AVC_implementation_M->Timing.stepSize1 = 0.001;
  MPC_AVC_implementation_M->solverInfoPtr =
    (&MPC_AVC_implementation_M->solverInfo);
  MPC_AVC_implementation_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&MPC_AVC_implementation_M->solverInfo, 0.001);
  rtsiSetSolverMode(&MPC_AVC_implementation_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  MPC_AVC_implementation_M->ModelData.blockIO = ((void *)
    &MPC_AVC_implementation_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&MPC_AVC_implementation_B.AnalogFilterDesign1);
    for (i = 0; i < 33; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  MPC_AVC_implementation_M->ModelData.defaultParam = ((real_T *)
    &MPC_AVC_implementation_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &MPC_AVC_implementation_X;
    MPC_AVC_implementation_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_MPC_AVC_implem));
  }

  /* states (dwork) */
  MPC_AVC_implementation_M->Work.dwork = ((void *) &MPC_AVC_implementation_DWork);
  (void) memset((char_T *) &MPC_AVC_implementation_DWork,0,
                sizeof(D_Work_MPC_AVC_implementation));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *)
      &MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampA;
    for (i = 0; i < 8; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void MPC_AVC_implementation_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  MPC_AVC_implementation_output(tid);
}

void MdlUpdate(int_T tid)
{
  MPC_AVC_implementation_update(tid);
}

void MdlInitializeSizes(void)
{
  MPC_AVC_implementation_M->Sizes.numContStates = (6);/* Number of continuous states */
  MPC_AVC_implementation_M->Sizes.numY = (0);/* Number of model outputs */
  MPC_AVC_implementation_M->Sizes.numU = (0);/* Number of model inputs */
  MPC_AVC_implementation_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  MPC_AVC_implementation_M->Sizes.numSampTimes = (2);/* Number of sample times */
  MPC_AVC_implementation_M->Sizes.numBlocks = (46);/* Number of blocks */
  MPC_AVC_implementation_M->Sizes.numBlockIO = (33);/* Number of block outputs */
  MPC_AVC_implementation_M->Sizes.numBlockPrms = (38);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* StateSpace Block: '<Root>/Analog Filter Design1' */
  MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[0] =
    MPC_AVC_implementation_P.AnalogFilterDesign1_X0;
  MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[1] =
    MPC_AVC_implementation_P.AnalogFilterDesign1_X0;
  MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[2] =
    MPC_AVC_implementation_P.AnalogFilterDesign1_X0;
  MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[3] =
    MPC_AVC_implementation_P.AnalogFilterDesign1_X0;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  MPC_AVC_implementation_X.Integrator_CSTATE =
    MPC_AVC_implementation_P.Integrator_IC;

  /* Derivative Block: '<S4>/Ideal Derivative' */
  MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampA = rtInf;
  MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  MPC_AVC_implementation_X.Integrator_CSTATE_a =
    MPC_AVC_implementation_P.Integrator_IC_e;

  /* Derivative Block: '<S5>/Ideal Derivative' */
  MPC_AVC_implementation_DWork.IdealDerivative_RWORK_b.TimeStampA = rtInf;
  MPC_AVC_implementation_DWork.IdealDerivative_RWORK_b.TimeStampB = rtInf;
}

void MdlStart(void)
{
  /* SignalGenerator Block: <Root>/Signal Generator (modif. by dSPACE) */
  rti_siggen_init(MPC_AVC_implementation_P.SignalGenerator_Amplitude,
                  MPC_AVC_implementation_P.SignalGenerator_Frequency, 0.001, 1,
                  &RTISigGenPtr.SignalGenerator_1);

  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL1 */
  ds2102_out(DS2102_1_BASE, 1, 0);

  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL2 */
  ds2102_out(DS2102_1_BASE, 2, 0);

  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL3 */
  ds2102_out(DS2102_1_BASE, 3, 0);
  MdlInitialize();
}

RT_MODEL_MPC_AVC_implementation *MPC_AVC_implementation(void)
{
  MPC_AVC_implementation_initialize(1);
  return MPC_AVC_implementation_M;
}

void MdlTerminate(void)
{
  MPC_AVC_implementation_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
