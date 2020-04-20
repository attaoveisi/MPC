/* Include files */

#include "MPC_AVC_implementation_sfun.h"
#include "c4_MPC_AVC_implementation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "MPC_AVC_implementation_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc4_MPC_AVC_implementationInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c4_MPC_AVC_implementation(void);
static void initialize_params_c4_MPC_AVC_implementation(void);
static void enable_c4_MPC_AVC_implementation(void);
static void disable_c4_MPC_AVC_implementation(void);
static void finalize_c4_MPC_AVC_implementation(void);
static void sf_c4_MPC_AVC_implementation(void);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c4_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c4_is_active_c4_MPC_AVC_implementation = 0U;
}

static void initialize_params_c4_MPC_AVC_implementation(void)
{
}

static void enable_c4_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c4_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void finalize_c4_MPC_AVC_implementation(void)
{
}

static void sf_c4_MPC_AVC_implementation(void)
{
  uint8_T c4_previousEvent;
  real_T c4_kk;
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 1.0;
  real_T c4_kk1;
  real_T c4_x;
  real_T c4_b_x;
  real_T *c4_b_kk1;
  real_T *c4_b_kk;
  c4_b_kk = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c4_b_kk1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  _SFD_DATA_RANGE_CHECK(*c4_b_kk1, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_b_kk, 1U);
  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  c4_kk = *c4_b_kk;
  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add_verbose("nargout", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
    0U, 0, 0U, 0, 0, &c4_nargout);
  sf_debug_symbol_scope_add_verbose("nargin", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
    0, 0U, 0, 0, &c4_nargin);
  sf_debug_symbol_scope_add("kk1", &c4_kk1, c4_sf_marshall);
  sf_debug_symbol_scope_add("kk", &c4_kk, c4_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,4);
  c4_x = c4_kk;
  c4_b_x = c4_x;
  c4_b_x = floor(c4_b_x);
  c4_kk1 = c4_b_x + 1.0;
  _SFD_EML_CALL(0,-4);
  sf_debug_symbol_scope_pop();
  *c4_b_kk1 = c4_kk1;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_MPC_AVC_implementationMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create(&c4_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_MPC_AVC_implementation_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[11];
  c4_ResolvedFunctionInfo (*c4_b_info)[11];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[11])c4_info;
  (*c4_b_info)[0].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[0].name = "eml_assert";
  (*c4_b_info)[0].dominantType = "char";
  (*c4_b_info)[0].resolved = "[B]eml_assert";
  (*c4_b_info)[0].fileLength = 0U;
  (*c4_b_info)[0].fileTime1 = 0U;
  (*c4_b_info)[0].fileTime2 = 0U;
  (*c4_b_info)[1].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[1].name = "gt";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved = "[B]gt";
  (*c4_b_info)[1].fileLength = 0U;
  (*c4_b_info)[1].fileTime1 = 0U;
  (*c4_b_info)[1].fileTime2 = 0U;
  (*c4_b_info)[2].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[2].name = "isempty";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved = "[B]isempty";
  (*c4_b_info)[2].fileLength = 0U;
  (*c4_b_info)[2].fileTime1 = 0U;
  (*c4_b_info)[2].fileTime2 = 0U;
  (*c4_b_info)[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[3].name = "isa";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved = "[B]isa";
  (*c4_b_info)[3].fileLength = 0U;
  (*c4_b_info)[3].fileTime1 = 0U;
  (*c4_b_info)[3].fileTime2 = 0U;
  (*c4_b_info)[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[4].name = "isscalar";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved = "[B]isscalar";
  (*c4_b_info)[4].fileLength = 0U;
  (*c4_b_info)[4].fileTime1 = 0U;
  (*c4_b_info)[4].fileTime2 = 0U;
  (*c4_b_info)[5].context = "";
  (*c4_b_info)[5].name = "floor";
  (*c4_b_info)[5].dominantType = "double";
  (*c4_b_info)[5].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[5].fileLength = 550U;
  (*c4_b_info)[5].fileTime1 = 1192466686U;
  (*c4_b_info)[5].fileTime2 = 0U;
  (*c4_b_info)[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[6].name = "isinteger";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved = "[B]isinteger";
  (*c4_b_info)[6].fileLength = 0U;
  (*c4_b_info)[6].fileTime1 = 0U;
  (*c4_b_info)[6].fileTime2 = 0U;
  (*c4_b_info)[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[7].name = "isreal";
  (*c4_b_info)[7].dominantType = "double";
  (*c4_b_info)[7].resolved = "[B]isreal";
  (*c4_b_info)[7].fileLength = 0U;
  (*c4_b_info)[7].fileTime1 = 0U;
  (*c4_b_info)[7].fileTime2 = 0U;
  (*c4_b_info)[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[8].name = "nargin";
  (*c4_b_info)[8].dominantType = "";
  (*c4_b_info)[8].resolved = "[B]nargin";
  (*c4_b_info)[8].fileLength = 0U;
  (*c4_b_info)[8].fileTime1 = 0U;
  (*c4_b_info)[8].fileTime2 = 0U;
  (*c4_b_info)[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[9].name = "class";
  (*c4_b_info)[9].dominantType = "double";
  (*c4_b_info)[9].resolved = "[B]class";
  (*c4_b_info)[9].fileLength = 0U;
  (*c4_b_info)[9].fileTime1 = 0U;
  (*c4_b_info)[9].fileTime2 = 0U;
  (*c4_b_info)[10].context = "";
  (*c4_b_info)[10].name = "plus";
  (*c4_b_info)[10].dominantType = "double";
  (*c4_b_info)[10].resolved = "[B]plus";
  (*c4_b_info)[10].fileLength = 0U;
  (*c4_b_info)[10].fileTime1 = 0U;
  (*c4_b_info)[10].fileTime2 = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11));
  for (c4_i0 = 0; c4_i0 < 11; c4_i0 = c4_i0 + 1) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileTime1, "nameCaptureInfo", 7,
      0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileTime2, "nameCaptureInfo", 7,
      0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i0);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c4_MPC_AVC_implementation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2967682475U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3096590916U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3862958209U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(393650557U);
}

mxArray *sf_c4_MPC_AVC_implementation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3602500040U);
    pr[1] = (double)(3555402026U);
    pr[2] = (double)(822096190U);
    pr[3] = (double)(1770746018U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "aliasId", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "aliasId", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if (!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_MPC_AVC_implementationMachineNumber_,
           4,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance.chartNumber),
           &(chartInstance.instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_MPC_AVC_implementationMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_MPC_AVC_implementationMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_MPC_AVC_implementationMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"kk1",0,
                              NULL);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"kk",0,
                              c4_sf_marshall);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,49);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c4_kk1;
          real_T *c4_kk;
          c4_kk = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c4_kk1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_kk1);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_kk);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_MPC_AVC_implementationMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c4_MPC_AVC_implementation(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c4_MPC_AVC_implementation();
  initialize_c4_MPC_AVC_implementation();
}

static void sf_opaque_enable_c4_MPC_AVC_implementation(void *chartInstanceVar)
{
  enable_c4_MPC_AVC_implementation();
}

static void sf_opaque_disable_c4_MPC_AVC_implementation(void *chartInstanceVar)
{
  disable_c4_MPC_AVC_implementation();
}

static void sf_opaque_gateway_c4_MPC_AVC_implementation(void *chartInstanceVar)
{
  sf_c4_MPC_AVC_implementation();
}

static void sf_opaque_terminate_c4_MPC_AVC_implementation(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c4_MPC_AVC_implementation();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_MPC_AVC_implementation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_MPC_AVC_implementation();
  }
}

static void mdlSetWorkWidths_c4_MPC_AVC_implementation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("MPC_AVC_implementation",
      "MPC_AVC_implementation",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("MPC_AVC_implementation",
                "MPC_AVC_implementation",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("MPC_AVC_implementation",
      "MPC_AVC_implementation",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MPC_AVC_implementation",
        "MPC_AVC_implementation",4,1);
      sf_mark_chart_reusable_outputs(S,"MPC_AVC_implementation",
        "MPC_AVC_implementation",4,1);
    }

    sf_set_rtw_dwork_info(S,"MPC_AVC_implementation","MPC_AVC_implementation",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(4078816953U));
  ssSetChecksum1(S,(3635061647U));
  ssSetChecksum2(S,(3937797487U));
  ssSetChecksum3(S,(1856476471U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_MPC_AVC_implementation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "MPC_AVC_implementation",
      "MPC_AVC_implementation",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_MPC_AVC_implementation(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_MPC_AVC_implementation;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c4_MPC_AVC_implementation;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c4_MPC_AVC_implementation;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c4_MPC_AVC_implementation;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c4_MPC_AVC_implementation;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c4_MPC_AVC_implementation;
  chartInstance.chartInfo.mdlStart = mdlStart_c4_MPC_AVC_implementation;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_MPC_AVC_implementation;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c4_MPC_AVC_implementation_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_MPC_AVC_implementation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_MPC_AVC_implementation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_MPC_AVC_implementation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_MPC_AVC_implementation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
