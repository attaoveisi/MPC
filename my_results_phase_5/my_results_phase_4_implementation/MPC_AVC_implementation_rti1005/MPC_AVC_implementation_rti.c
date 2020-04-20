/*********************** dSPACE target specific file *************************

   Include file MPC_AVC_implementation_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1005 6.2 (14-Nov-2008)
   Wed Mar 02 12:18:25 2016

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "MPC_AVC_implementation.h"
#include "MPC_AVC_implementation_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             MPC_AVC_implementation_B
#define RTP_STRUCTURE_NAME             MPC_AVC_implementation_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rti_siggen_main.h>
#include <ds2102.h>
#include <ds2004.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* dSPACE Test-Automation Stimulus Engine */
#define TA_STIMULUS_ENGINE_ENABLE      0

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  {
    ts_timestamp_type ts = { 0, 0 };

    host_service(1, &ts);

#ifdef RTT_ENABLE

    DsDaq_Init(32, 1);

#endif

  }
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1005, (void *) 0,
                        VCM_TXT_RTI1005, 6, 2, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 7, 6, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 7, 1, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 7, 1, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 7, 1, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 7, 1, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS2102 #1 */
  ds2102_init(DS2102_1_BASE);

  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL1 */
  ds2102_set_range(DS2102_1_BASE, 1, DS2102_RNG10);
  ds2102_set_errmode(DS2102_1_BASE, 1, 1);
  ds2102_set_dglmode(DS2102_1_BASE, 1, 0);

  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL2 */
  ds2102_set_range(DS2102_1_BASE, 2, DS2102_RNG10);
  ds2102_set_errmode(DS2102_1_BASE, 2, 1);
  ds2102_set_dglmode(DS2102_1_BASE, 2, 0);

  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL3 */
  ds2102_set_range(DS2102_1_BASE, 3, DS2102_RNG10);
  ds2102_set_errmode(DS2102_1_BASE, 3, 1);
  ds2102_set_dglmode(DS2102_1_BASE, 3, 0);

  /* dSPACE I/O Board DS2004 #1 */
  ds2004_init(DS2004_1_BASE);

  /* dSPACE I/O Board DS2004 #1 Unit:ADC */
  ds2004_single_init(DS2004_1_BASE,
                     DS2004_CH1,
                     DS2004_RNG_10,
                     DS2004_TRIG_SW,
                     0.0);
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

/* Function rti_mdl_initialize_io_units() is empty */
#define rti_mdl_initialize_io_units()

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{

#ifdef RTT_ENABLE

  /* DsDaq background call */
  DsDaq_Background();

#endif

}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.001, 0] */
  /* dSPACE I/O Board DS2004 #1 Unit:ADC */

  /* dSPACE I/O Board DS2004 #1 Unit:ADC Group:ADC */
  ds2004_sw_trigger(DS2004_1_BASE, DS2004_CONV_START_1);
}

#undef __INLINE

/****** [EOF] ****************************************************************/
