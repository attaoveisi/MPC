/* Include files */

#include "MPC_AVC_implementation_sfun.h"
#include "c2_MPC_AVC_implementation.h"
#include "c3_MPC_AVC_implementation.h"
#include "c4_MPC_AVC_implementation.h"
#include "c5_MPC_AVC_implementation.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _MPC_AVC_implementationMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void MPC_AVC_implementation_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void MPC_AVC_implementation_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_MPC_AVC_implementation_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_MPC_AVC_implementation_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_MPC_AVC_implementation_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_MPC_AVC_implementation_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_MPC_AVC_implementation_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_MPC_AVC_implementation_process_check_sum_call( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(543366055U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3497989307U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4115603684U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3574300421U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2115560174U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2406844353U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2961987849U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2425386970U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_MPC_AVC_implementation_get_check_sum(mxArray *plhs[]);
          sf_c2_MPC_AVC_implementation_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_MPC_AVC_implementation_get_check_sum(mxArray *plhs[]);
          sf_c3_MPC_AVC_implementation_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_MPC_AVC_implementation_get_check_sum(mxArray *plhs[]);
          sf_c4_MPC_AVC_implementation_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_MPC_AVC_implementation_get_check_sum(mxArray *plhs[]);
          sf_c5_MPC_AVC_implementation_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3144864271U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3987530040U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4050147671U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2557795280U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3570373727U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3978333240U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2740733631U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1588473141U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_MPC_AVC_implementation_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern mxArray *sf_c2_MPC_AVC_implementation_get_autoinheritance_info
          (void);
        plhs[0] = sf_c2_MPC_AVC_implementation_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_MPC_AVC_implementation_get_autoinheritance_info
          (void);
        plhs[0] = sf_c3_MPC_AVC_implementation_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_MPC_AVC_implementation_get_autoinheritance_info
          (void);
        plhs[0] = sf_c4_MPC_AVC_implementation_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_MPC_AVC_implementation_get_autoinheritance_info
          (void);
        plhs[0] = sf_c5_MPC_AVC_implementation_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_MPC_AVC_implementation_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_MPC_AVC_implementation_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_MPC_AVC_implementation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_MPC_AVC_implementation_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_MPC_AVC_implementation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_MPC_AVC_implementation_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_MPC_AVC_implementation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_MPC_AVC_implementation_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_MPC_AVC_implementation_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void MPC_AVC_implementation_debug_initialize(void)
{
  _MPC_AVC_implementationMachineNumber_ = sf_debug_initialize_machine(
    "MPC_AVC_implementation","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(_MPC_AVC_implementationMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(_MPC_AVC_implementationMachineNumber_,0);
}

void MPC_AVC_implementation_register_exported_symbols(SimStruct* S)
{
}
