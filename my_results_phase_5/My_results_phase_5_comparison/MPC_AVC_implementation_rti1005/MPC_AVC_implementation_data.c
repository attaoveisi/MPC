/*
 * MPC_AVC_implementation_data.c
 *
 * Real-Time Workshop code generation for Simulink model "MPC_AVC_implementation.mdl".
 *
 * Model Version              : 1.398
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Mar 02 15:01:05 2016
 */

#include "MPC_AVC_implementation.h"
#include "MPC_AVC_implementation_private.h"

/* Block parameters (auto storage) */
Parameters_MPC_AVC_implementati MPC_AVC_implementation_P = {
  /*  AnalogFilterDesign1_A : '<Root>/Analog Filter Design1'
   */
  { -4.6439250434230898E+003, -2.5132741228718346E+003, 2.5132741228718346E+003,
    2.5132741228718346E+003, -1.9235767356299079E+003, -2.5132741228718346E+003,
    2.5132741228718346E+003 },
  2.5132741228718346E+003,             /* AnalogFilterDesign1_B : '<Root>/Analog Filter Design1'
                                        */
  1.0,                                 /* AnalogFilterDesign1_C : '<Root>/Analog Filter Design1'
                                        */
  0.0,                                 /* AnalogFilterDesign1_X0 : '<Root>/Analog Filter Design1'
                                        */
  0.0,                                 /* ProportionalGain_Gain : '<S4>/Proportional Gain'
                                        */
  0.0,                                 /* Integrator_IC : '<S4>/Integrator'
                                        */
  0.0,                                 /* DerivativeGain_Gain : '<S4>/Derivative Gain'
                                        */
  2.0,                                 /* Saturation_UpperSat : '<Root>/Saturation'
                                        */
  -2.0,                                /* Saturation_LowerSat : '<Root>/Saturation'
                                        */
  100.0,                               /* Amplifier2_Gain : '<Root>/Amplifier2'
                                        */
  0.0,                                 /* ProportionalGain_Gain_i : '<S5>/Proportional Gain'
                                        */
  0.0,                                 /* Integrator_IC_e : '<S5>/Integrator'
                                        */
  0.0,                                 /* DerivativeGain_Gain_l : '<S5>/Derivative Gain'
                                        */
  2.0,                                 /* Saturation2_UpperSat : '<Root>/Saturation2'
                                        */
  -2.0,                                /* Saturation2_LowerSat : '<Root>/Saturation2'
                                        */
  100.0,                               /* Amplifier_Gain : '<Root>/Amplifier'
                                        */
  1.0,                                 /* SignalGenerator_Amplitude : '<Root>/Signal Generator'
                                        */
  0.4,                                 /* SignalGenerator_Frequency : '<Root>/Signal Generator'
                                        */
  0.0,                                 /* Gain1_Gain : '<Root>/Gain1'
                                        */
  1.0,                                 /* Saturation1_UpperSat : '<Root>/Saturation1'
                                        */
  -1.0,                                /* Saturation1_LowerSat : '<Root>/Saturation1'
                                        */
  0.1,                                 /* Piezo1_dspace_Gain : '<Root>/Piezo1_dspace'
                                        */
  0.1,                                 /* dSpace_gain1_Gain : '<Root>/dSpace_gain1'
                                        */
  0.1,                                 /* dSpace_gain3_Gain : '<Root>/dSpace_gain3'
                                        */
  125.0,                               /* Amplifier1_Gain : '<Root>/Amplifier1'
                                        */
  0.0,                                 /* IntegralGain_Gain : '<S4>/Integral Gain'
                                        */
  0.0,                                 /* IntegralGain_Gain_c : '<S5>/Integral Gain'
                                        */
  0.1,                                 /* dSpace_gain2_Gain : '<Root>/dSpace_gain2'
                                        */
  5.5920349233898321E+002,             /* deltaFreq_Value : '<S1>/deltaFreq'
                                        */
  10.0,                                /* targetTime_Value : '<S1>/targetTime'
                                        */
  0.5,                                 /* Gain_Gain : '<S1>/Gain'
                                        */
  6.2831853071795862E+000              /* initialFreq_Value : '<S1>/initialFreq'
                                        */
};
