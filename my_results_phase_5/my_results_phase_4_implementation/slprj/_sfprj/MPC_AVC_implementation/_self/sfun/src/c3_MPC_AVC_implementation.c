/* Include files */

#include "MPC_AVC_implementation_sfun.h"
#include "c3_MPC_AVC_implementation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "MPC_AVC_implementation_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c3_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc3_MPC_AVC_implementationInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c3_MPC_AVC_implementation(void);
static void initialize_params_c3_MPC_AVC_implementation(void);
static void enable_c3_MPC_AVC_implementation(void);
static void disable_c3_MPC_AVC_implementation(void);
static void finalize_c3_MPC_AVC_implementation(void);
static void sf_c3_MPC_AVC_implementation(void);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshall(void *c3_chartInstance, void *c3_u);
static const mxArray *c3_b_sf_marshall(void *c3_chartInstance, void *c3_u);
static const mxArray *c3_c_sf_marshall(void *c3_chartInstance, void *c3_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c3_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c3_is_active_c3_MPC_AVC_implementation = 0U;
}

static void initialize_params_c3_MPC_AVC_implementation(void)
{
}

static void enable_c3_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c3_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void finalize_c3_MPC_AVC_implementation(void)
{
}

static void sf_c3_MPC_AVC_implementation(void)
{
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  uint8_T c3_previousEvent;
  int32_T c3_i3;
  int32_T c3_i4;
  static real_T c3_Lf[449982];
  real_T c3_kk;
  real_T c3_nargout = 1.0;
  real_T c3_nargin = 2.0;
  real_T c3_kk1;
  real_T c3_y[18];
  real_T c3_x;
  real_T c3_b_x;
  int32_T c3_b_kk1;
  int32_T c3_i5;
  int32_T c3_hoistedExpr;
  int32_T c3_i6;
  real_T *c3_b_kk;
  real_T (*c3_b_y)[18];
  real_T (*c3_b_Lf)[449982];
  c3_b_y = (real_T (*)[18])ssGetOutputPortSignal(chartInstance.S, 1);
  c3_b_kk = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c3_b_Lf = (real_T (*)[449982])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  for (c3_i0 = 0; c3_i0 < 18; c3_i0 = c3_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_y)[c3_i0], 0U);
  }

  for (c3_i1 = 0; c3_i1 < 24999; c3_i1 = c3_i1 + 1) {
    for (c3_i2 = 0; c3_i2 < 18; c3_i2 = c3_i2 + 1) {
      _SFD_DATA_RANGE_CHECK((*c3_b_Lf)[c3_i2 + 18 * c3_i1], 1U);
    }
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_kk, 2U);
  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for (c3_i3 = 0; c3_i3 < 24999; c3_i3 = c3_i3 + 1) {
    for (c3_i4 = 0; c3_i4 < 18; c3_i4 = c3_i4 + 1) {
      c3_Lf[c3_i4 + 18 * c3_i3] = (*c3_b_Lf)[c3_i4 + 18 * c3_i3];
    }
  }

  c3_kk = *c3_b_kk;
  sf_debug_symbol_scope_push(6U, 0U);
  sf_debug_symbol_scope_add_verbose("nargout", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
    0U, 0, 0U, 0, 0, &c3_nargout);
  sf_debug_symbol_scope_add_verbose("nargin", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
    0, 0U, 0, 0, &c3_nargin);
  sf_debug_symbol_scope_add("kk1", &c3_kk1, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("y", &c3_y, c3_c_sf_marshall);
  sf_debug_symbol_scope_add("kk", &c3_kk, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("Lf", &c3_Lf, c3_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,4);
  c3_x = c3_kk;
  c3_b_x = c3_x;
  c3_b_x = floor(c3_b_x);
  c3_kk1 = c3_b_x + 1.0;
  _SFD_EML_CALL(0,6);
  c3_b_kk1 = (int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Lf", (int32_T)
    _SFD_INTEGER_CHECK("kk1", c3_kk1), 1, 24999, 2, 0) - 1;
  for (c3_i5 = 0; c3_i5 < 18; c3_i5 = c3_i5 + 1) {
    c3_hoistedExpr = 0;
    c3_y[c3_i5] = c3_Lf[c3_i5 + 18 * c3_b_kk1];
  }

  _SFD_EML_CALL(0,-6);
  sf_debug_symbol_scope_pop();
  for (c3_i6 = 0; c3_i6 < 18; c3_i6 = c3_i6 + 1) {
    (*c3_b_y)[c3_i6] = c3_y[c3_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_MPC_AVC_implementationMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i7;
  int32_T c3_i8;
  static real_T c3_b_u[449982];
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  for (c3_i7 = 0; c3_i7 < 24999; c3_i7 = c3_i7 + 1) {
    for (c3_i8 = 0; c3_i8 < 18; c3_i8 = c3_i8 + 1) {
      c3_b_u[c3_i8 + 18 * c3_i7] = (*((real_T (*)[449982])c3_u))[c3_i8 + 18 *
        c3_i7];
    }
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create(&c3_b_u, "y", 0, 0U, 1U, 2, 18, 24999));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_b_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create(&c3_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_c_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i9;
  real_T c3_b_u[18];
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  for (c3_i9 = 0; c3_i9 < 18; c3_i9 = c3_i9 + 1) {
    c3_b_u[c3_i9] = (*((real_T (*)[18])c3_u))[c3_i9];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create(&c3_b_u, "y", 0, 0U, 1U, 1, 18));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_MPC_AVC_implementation_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[11];
  c3_ResolvedFunctionInfo (*c3_b_info)[11];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i10;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[11])c3_info;
  (*c3_b_info)[0].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[0].name = "eml_assert";
  (*c3_b_info)[0].dominantType = "char";
  (*c3_b_info)[0].resolved = "[B]eml_assert";
  (*c3_b_info)[0].fileLength = 0U;
  (*c3_b_info)[0].fileTime1 = 0U;
  (*c3_b_info)[0].fileTime2 = 0U;
  (*c3_b_info)[1].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[1].name = "isempty";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved = "[B]isempty";
  (*c3_b_info)[1].fileLength = 0U;
  (*c3_b_info)[1].fileTime1 = 0U;
  (*c3_b_info)[1].fileTime2 = 0U;
  (*c3_b_info)[2].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[2].name = "isa";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved = "[B]isa";
  (*c3_b_info)[2].fileLength = 0U;
  (*c3_b_info)[2].fileTime1 = 0U;
  (*c3_b_info)[2].fileTime2 = 0U;
  (*c3_b_info)[3].context = "";
  (*c3_b_info)[3].name = "floor";
  (*c3_b_info)[3].dominantType = "double";
  (*c3_b_info)[3].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[3].fileLength = 550U;
  (*c3_b_info)[3].fileTime1 = 1192466686U;
  (*c3_b_info)[3].fileTime2 = 0U;
  (*c3_b_info)[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[4].name = "isinteger";
  (*c3_b_info)[4].dominantType = "double";
  (*c3_b_info)[4].resolved = "[B]isinteger";
  (*c3_b_info)[4].fileLength = 0U;
  (*c3_b_info)[4].fileTime1 = 0U;
  (*c3_b_info)[4].fileTime2 = 0U;
  (*c3_b_info)[5].context = "";
  (*c3_b_info)[5].name = "plus";
  (*c3_b_info)[5].dominantType = "double";
  (*c3_b_info)[5].resolved = "[B]plus";
  (*c3_b_info)[5].fileLength = 0U;
  (*c3_b_info)[5].fileTime1 = 0U;
  (*c3_b_info)[5].fileTime2 = 0U;
  (*c3_b_info)[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[6].name = "isscalar";
  (*c3_b_info)[6].dominantType = "double";
  (*c3_b_info)[6].resolved = "[B]isscalar";
  (*c3_b_info)[6].fileLength = 0U;
  (*c3_b_info)[6].fileTime1 = 0U;
  (*c3_b_info)[6].fileTime2 = 0U;
  (*c3_b_info)[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[7].name = "class";
  (*c3_b_info)[7].dominantType = "double";
  (*c3_b_info)[7].resolved = "[B]class";
  (*c3_b_info)[7].fileLength = 0U;
  (*c3_b_info)[7].fileTime1 = 0U;
  (*c3_b_info)[7].fileTime2 = 0U;
  (*c3_b_info)[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[8].name = "nargin";
  (*c3_b_info)[8].dominantType = "";
  (*c3_b_info)[8].resolved = "[B]nargin";
  (*c3_b_info)[8].fileLength = 0U;
  (*c3_b_info)[8].fileTime1 = 0U;
  (*c3_b_info)[8].fileTime2 = 0U;
  (*c3_b_info)[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[9].name = "gt";
  (*c3_b_info)[9].dominantType = "double";
  (*c3_b_info)[9].resolved = "[B]gt";
  (*c3_b_info)[9].fileLength = 0U;
  (*c3_b_info)[9].fileTime1 = 0U;
  (*c3_b_info)[9].fileTime2 = 0U;
  (*c3_b_info)[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[10].name = "isreal";
  (*c3_b_info)[10].dominantType = "double";
  (*c3_b_info)[10].resolved = "[B]isreal";
  (*c3_b_info)[10].fileLength = 0U;
  (*c3_b_info)[10].fileTime1 = 0U;
  (*c3_b_info)[10].fileTime2 = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11));
  for (c3_i10 = 0; c3_i10 < 11; c3_i10 = c3_i10 + 1) {
    c3_r0 = &c3_info[c3_i10];
    sf_mex_addfield(c3_m0, sf_mex_create(c3_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
                    "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create(c3_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c3_r0->name)), "name",
                    "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create(c3_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create(c3_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved",
                    "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create(&c3_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create(&c3_r0->fileTime1, "nameCaptureInfo", 7,
      0U, 0U, 0), "fileTime1", "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create(&c3_r0->fileTime2, "nameCaptureInfo", 7,
      0U, 0U, 0), "fileTime2", "nameCaptureInfo", c3_i10);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c3_MPC_AVC_implementation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1491425345U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2507247845U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2554905763U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3954667797U);
}

mxArray *sf_c3_MPC_AVC_implementation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2619459419U);
    pr[1] = (double)(2829857596U);
    pr[2] = (double)(4218653047U);
    pr[3] = (double)(2606182936U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(18);
      pr[1] = (double)(24999);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "aliasId", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(18);
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
           3,
           1,
           1,
           3,
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

          {
            unsigned int dimVector[1];
            dimVector[0]= 18;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"y",0,c3_c_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 18;
            dimVector[1]= 24999;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Lf",0,c3_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"kk",0,
                              c3_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,65);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c3_y)[18];
          real_T (*c3_Lf)[449982];
          real_T *c3_kk;
          c3_y = (real_T (*)[18])ssGetOutputPortSignal(chartInstance.S, 1);
          c3_kk = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c3_Lf = (real_T (*)[449982])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_Lf);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_kk);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_MPC_AVC_implementationMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c3_MPC_AVC_implementation(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c3_MPC_AVC_implementation();
  initialize_c3_MPC_AVC_implementation();
}

static void sf_opaque_enable_c3_MPC_AVC_implementation(void *chartInstanceVar)
{
  enable_c3_MPC_AVC_implementation();
}

static void sf_opaque_disable_c3_MPC_AVC_implementation(void *chartInstanceVar)
{
  disable_c3_MPC_AVC_implementation();
}

static void sf_opaque_gateway_c3_MPC_AVC_implementation(void *chartInstanceVar)
{
  sf_c3_MPC_AVC_implementation();
}

static void sf_opaque_terminate_c3_MPC_AVC_implementation(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c3_MPC_AVC_implementation();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_MPC_AVC_implementation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_MPC_AVC_implementation();
  }
}

static void mdlSetWorkWidths_c3_MPC_AVC_implementation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("MPC_AVC_implementation",
      "MPC_AVC_implementation",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("MPC_AVC_implementation",
                "MPC_AVC_implementation",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("MPC_AVC_implementation",
      "MPC_AVC_implementation",3,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MPC_AVC_implementation",
        "MPC_AVC_implementation",3,2);
      sf_mark_chart_reusable_outputs(S,"MPC_AVC_implementation",
        "MPC_AVC_implementation",3,1);
    }

    sf_set_rtw_dwork_info(S,"MPC_AVC_implementation","MPC_AVC_implementation",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(4277455476U));
  ssSetChecksum1(S,(2642450727U));
  ssSetChecksum2(S,(2301620889U));
  ssSetChecksum3(S,(275257670U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_MPC_AVC_implementation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "MPC_AVC_implementation",
      "MPC_AVC_implementation",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_MPC_AVC_implementation(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_MPC_AVC_implementation;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c3_MPC_AVC_implementation;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c3_MPC_AVC_implementation;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c3_MPC_AVC_implementation;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c3_MPC_AVC_implementation;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c3_MPC_AVC_implementation;
  chartInstance.chartInfo.mdlStart = mdlStart_c3_MPC_AVC_implementation;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_MPC_AVC_implementation;
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

void c3_MPC_AVC_implementation_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_MPC_AVC_implementation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_MPC_AVC_implementation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_MPC_AVC_implementation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_MPC_AVC_implementation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
