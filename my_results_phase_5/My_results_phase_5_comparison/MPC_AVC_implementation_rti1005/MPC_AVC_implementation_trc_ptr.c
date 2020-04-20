/***************************************************************************

   Source file MPC_AVC_implementation_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1005 6.2 (14-Nov-2008)
   Wed Mar 02 15:01:05 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "MPC_AVC_implementation_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_MPC_AVC_implementation_B_real_T_0 = 0;
volatile real_T *p_MPC_AVC_implementation_P_real_T_0 = 0;
volatile real_T *p_MPC_AVC_implementation_DWork_real_T_0 = 0;
volatile real_T *p_MPC_AVC_implementation_X_real_T_0 = 0;
