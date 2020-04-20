  /*********************** dSPACE target specific file *************************

   Header file MPC_AVC_implementation_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1005 6.2 (14-Nov-2008)
   Wed Mar 02 15:01:05 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_MPC_AVC_implementation_trc_ptr_h_
  #define RTI_HEADER_MPC_AVC_implementation_trc_ptr_h_
  /* Include the model header file. */
  #include "MPC_AVC_implementation.h"
  #include "MPC_AVC_implementation_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_MPC_AVC_implementation_B_real_T_0;
              EXTERN_C volatile  real_T *p_MPC_AVC_implementation_P_real_T_0;
              EXTERN_C volatile  real_T *p_MPC_AVC_implementation_DWork_real_T_0;
              EXTERN_C volatile  real_T *p_MPC_AVC_implementation_X_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_MPC_AVC_implementation_B_real_T_0 = &MPC_AVC_implementation_B.AnalogFilterDesign1;\
              p_MPC_AVC_implementation_P_real_T_0 = &MPC_AVC_implementation_P.AnalogFilterDesign1_A[0];\
              p_MPC_AVC_implementation_DWork_real_T_0 = &MPC_AVC_implementation_DWork.IdealDerivative_RWORK.TimeStampA;\
              p_MPC_AVC_implementation_X_real_T_0 = &MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[0];\

   #endif                       /* RTI_HEADER_MPC_AVC_implementation_trc_ptr_h_ */
