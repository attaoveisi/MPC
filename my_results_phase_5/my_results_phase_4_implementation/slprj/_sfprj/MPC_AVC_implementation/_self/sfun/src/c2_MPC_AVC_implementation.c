/* Include files */

#include "MPC_AVC_implementation_sfun.h"
#include "c2_MPC_AVC_implementation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "MPC_AVC_implementation_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_MPC_AVC_implementationInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_MPC_AVC_implementation(void);
static void initialize_params_c2_MPC_AVC_implementation(void);
static void enable_c2_MPC_AVC_implementation(void);
static void disable_c2_MPC_AVC_implementation(void);
static void finalize_c2_MPC_AVC_implementation(void);
static void sf_c2_MPC_AVC_implementation(void);
static void c2_c2_MPC_AVC_implementation(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static void c2_inv(real_T c2_x[100], real_T c2_y[100]);
static void c2_invNxN(real_T c2_x[100], real_T c2_y[100]);
static int32_T c2_eml_ixamax(int32_T c2_n, real_T c2_x[100], int32_T c2_ix0,
  int32_T c2_incx);
static void c2_eml_xswap(real_T c2_x[100], int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_b_x[100]);
static void c2_eml_xgeru(int32_T c2_m, int32_T c2_n, int32_T c2_ix0, int32_T
  c2_iy0, real_T c2_A[100], int32_T c2_ia0, real_T c2_b_A[100]);
static real_T c2_norm(real_T c2_x[100]);
static void c2_eml_warning(void);
static void c2_b_eml_warning(real_T c2_varargin_3);
static void c2_mldivide(real_T c2_A[100], real_T c2_B[40], real_T c2_Y[40]);
static void c2_eml_xgetrf(real_T c2_A[100], real_T c2_b_A[100], int32_T c2_ipiv
  [10], int32_T *c2_info);
static void c2_b_mldivide(real_T c2_A[100], real_T c2_B[10], real_T c2_Y[10]);
static real_T c2_mrdivide(real_T c2_A, real_T c2_B);
static void c2_c_eml_warning(void);
static real_T c2_max(real_T c2_varargin_1, real_T c2_varargin_2);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[108]);
static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[108]);
static void c2_mul_wide_s32(int32_T c2_in0, int32_T c2_in1, uint32_T
  *c2_ptrOutBitsHi, uint32_T *c2_ptrOutBitsLo);
static int32_T c2_mul_s32_s32_s32_sat(int32_T c2_a, int32_T c2_b);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_MPC_AVC_implementation = 0U;
}

static void initialize_params_c2_MPC_AVC_implementation(void)
{
}

static void enable_c2_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void finalize_c2_MPC_AVC_implementation(void)
{
}

static void sf_c2_MPC_AVC_implementation(void)
{
  int32_T c2_i0;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  uint8_T c2_previousEvent;
  real_T (*c2_omega)[100];
  real_T (*c2_eta)[10];
  real_T (*c2_f)[10];
  real_T (*c2_A_cons)[40];
  real_T (*c2_b)[4];
  c2_eta = (real_T (*)[10])ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 3);
  c2_omega = (real_T (*)[100])ssGetInputPortSignal(chartInstance.S, 0);
  c2_A_cons = (real_T (*)[40])ssGetInputPortSignal(chartInstance.S, 2);
  c2_f = (real_T (*)[10])ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c2_i0 = 0; c2_i0 < 10; c2_i0 = c2_i0 + 1) {
    for (c2_i1 = 0; c2_i1 < 10; c2_i1 = c2_i1 + 1) {
      _SFD_DATA_RANGE_CHECK((*c2_omega)[c2_i1 + 10 * c2_i0], 0U);
    }
  }

  for (c2_i2 = 0; c2_i2 < 10; c2_i2 = c2_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_eta)[c2_i2], 1U);
  }

  for (c2_i3 = 0; c2_i3 < 10; c2_i3 = c2_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_f)[c2_i3], 2U);
  }

  for (c2_i4 = 0; c2_i4 < 10; c2_i4 = c2_i4 + 1) {
    for (c2_i5 = 0; c2_i5 < 4; c2_i5 = c2_i5 + 1) {
      _SFD_DATA_RANGE_CHECK((*c2_A_cons)[c2_i5 + 4 * c2_i4], 3U);
    }
  }

  for (c2_i6 = 0; c2_i6 < 4; c2_i6 = c2_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_b)[c2_i6], 4U);
  }

  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_MPC_AVC_implementation();
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_MPC_AVC_implementationMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void c2_c2_MPC_AVC_implementation(void)
{
  int32_T c2_i7;
  int32_T c2_i8;
  real_T c2_omega[100];
  int32_T c2_i9;
  real_T c2_f[10];
  int32_T c2_i10;
  int32_T c2_i11;
  real_T c2_A_cons[40];
  int32_T c2_i12;
  real_T c2_b[4];
  real_T c2_nargout = 1.0;
  real_T c2_nargin = 4.0;
  real_T c2_al;
  real_T c2_la;
  real_T c2_w;
  real_T c2_lambda_p[4];
  real_T c2_km;
  real_T c2_lambda[4];
  real_T c2_x_ini[4];
  real_T c2_m;
  real_T c2_n;
  real_T c2_d[4];
  real_T c2_P[16];
  real_T c2_i;
  real_T c2_kk;
  real_T c2_m1;
  real_T c2_n1;
  real_T c2_eta[10];
  real_T c2_b_m1;
  int32_T c2_i13;
  int32_T c2_i14;
  real_T c2_b_omega[100];
  real_T c2_dv0[100];
  int32_T c2_i15;
  int32_T c2_i16;
  real_T c2_a[100];
  int32_T c2_i17;
  real_T c2_b_b[10];
  int32_T c2_i18;
  int32_T c2_i19;
  real_T c2_A[100];
  int32_T c2_i20;
  real_T c2_B[10];
  int32_T c2_i21;
  real_T c2_C[10];
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  real_T c2_b_A[100];
  int32_T c2_i25;
  real_T c2_b_B[10];
  int32_T c2_i26;
  real_T c2_b_C[10];
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  real_T c2_c_A[100];
  int32_T c2_i30;
  real_T c2_c_B[10];
  int32_T c2_i31;
  int32_T c2_i32;
  real_T c2_d0;
  real_T c2_b_i;
  int32_T c2_c_i;
  int32_T c2_i33;
  int32_T c2_hoistedExpr;
  real_T c2_b_a[10];
  int32_T c2_i34;
  real_T c2_c_b[10];
  int32_T c2_i35;
  real_T c2_x[10];
  int32_T c2_i36;
  real_T c2_y[10];
  int32_T c2_i37;
  real_T c2_b_x[10];
  int32_T c2_i38;
  real_T c2_b_y[10];
  int32_T c2_i39;
  real_T c2_c_x[10];
  int32_T c2_i40;
  real_T c2_c_y[10];
  int32_T c2_i41;
  real_T c2_d_x[10];
  int32_T c2_i42;
  real_T c2_d_y[10];
  int32_T c2_i43;
  real_T c2_e_x[10];
  int32_T c2_i44;
  real_T c2_e_y[10];
  real_T c2_f_x;
  real_T c2_f_y;
  int32_T c2_i45;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i46;
  int32_T c2_i47;
  real_T c2_c_a[40];
  int32_T c2_i48;
  int32_T c2_i49;
  real_T c2_c_omega[100];
  int32_T c2_i50;
  int32_T c2_i51;
  real_T c2_b_A_cons[40];
  real_T c2_d_b[40];
  int32_T c2_i52;
  int32_T c2_i53;
  real_T c2_d_A[40];
  int32_T c2_i54;
  int32_T c2_i55;
  real_T c2_d_B[40];
  int32_T c2_i56;
  int32_T c2_i57;
  real_T c2_c_C[16];
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  real_T c2_e_A[40];
  int32_T c2_i62;
  int32_T c2_i63;
  real_T c2_e_B[40];
  int32_T c2_i64;
  int32_T c2_i65;
  real_T c2_d_C[16];
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  real_T c2_f_A[40];
  int32_T c2_i70;
  int32_T c2_i71;
  real_T c2_f_B[40];
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  real_T c2_d_a[40];
  int32_T c2_i77;
  int32_T c2_i78;
  real_T c2_d_omega[100];
  int32_T c2_i79;
  real_T c2_b_f[10];
  real_T c2_e_b[10];
  int32_T c2_i80;
  int32_T c2_i81;
  real_T c2_g_A[40];
  int32_T c2_i82;
  real_T c2_g_B[10];
  int32_T c2_i83;
  int32_T c2_i84;
  real_T c2_h_A[40];
  int32_T c2_i85;
  real_T c2_h_B[10];
  int32_T c2_i86;
  int32_T c2_i87;
  real_T c2_i_A[40];
  int32_T c2_i88;
  real_T c2_i_B[10];
  int32_T c2_i89;
  real_T c2_g_y[4];
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  real_T c2_d1;
  real_T c2_b_km;
  int32_T c2_i94;
  real_T c2_d2;
  real_T c2_d_i;
  real_T c2_e_a;
  real_T c2_f_b;
  real_T c2_h_y;
  int32_T c2_e_i;
  int32_T c2_i95;
  int32_T c2_b_hoistedExpr;
  real_T c2_f_a[4];
  int32_T c2_i96;
  real_T c2_g_b[4];
  int32_T c2_i97;
  real_T c2_g_x[4];
  int32_T c2_i98;
  real_T c2_i_y[4];
  int32_T c2_i99;
  real_T c2_h_x[4];
  int32_T c2_i100;
  real_T c2_j_y[4];
  int32_T c2_i101;
  real_T c2_i_x[4];
  int32_T c2_i102;
  real_T c2_k_y[4];
  int32_T c2_i103;
  real_T c2_j_x[4];
  int32_T c2_i104;
  real_T c2_l_y[4];
  int32_T c2_i105;
  real_T c2_k_x[4];
  int32_T c2_i106;
  real_T c2_m_y[4];
  real_T c2_l_x;
  real_T c2_n_y;
  int32_T c2_i107;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_i108;
  real_T c2_g_a[4];
  int32_T c2_i109;
  real_T c2_h_b[4];
  int32_T c2_i110;
  real_T c2_m_x[4];
  int32_T c2_i111;
  real_T c2_o_y[4];
  int32_T c2_i112;
  real_T c2_n_x[4];
  int32_T c2_i113;
  real_T c2_p_y[4];
  int32_T c2_i114;
  real_T c2_o_x[4];
  int32_T c2_i115;
  real_T c2_q_y[4];
  int32_T c2_i116;
  real_T c2_p_x[4];
  int32_T c2_i117;
  real_T c2_r_y[4];
  int32_T c2_i118;
  real_T c2_q_x[4];
  int32_T c2_i119;
  real_T c2_s_y[4];
  real_T c2_r_x;
  int32_T c2_i120;
  int32_T c2_e_k;
  int32_T c2_f_k;
  int32_T c2_i121;
  int32_T c2_i122;
  real_T c2_e_omega[100];
  int32_T c2_i123;
  int32_T c2_i124;
  real_T c2_c_A_cons[40];
  real_T c2_h_a[40];
  int32_T c2_i125;
  real_T c2_i_b[4];
  int32_T c2_i126;
  int32_T c2_i127;
  real_T c2_j_A[40];
  int32_T c2_i128;
  real_T c2_j_B[4];
  int32_T c2_i129;
  int32_T c2_i130;
  real_T c2_k_A[40];
  int32_T c2_i131;
  real_T c2_k_B[4];
  int32_T c2_i132;
  int32_T c2_i133;
  real_T c2_l_A[40];
  int32_T c2_i134;
  real_T c2_l_B[4];
  int32_T c2_i135;
  real_T c2_t_y[10];
  int32_T c2_i136;
  int32_T c2_i137;
  int32_T c2_i138;
  real_T c2_f_omega[100];
  int32_T c2_i139;
  real_T c2_c_f[10];
  real_T c2_dv1[10];
  int32_T c2_i140;
  int32_T c2_i141;
  real_T (*c2_b_eta)[10];
  real_T (*c2_g_omega)[100];
  real_T (*c2_d_f)[10];
  real_T (*c2_d_A_cons)[40];
  real_T (*c2_j_b)[4];
  c2_b_eta = (real_T (*)[10])ssGetOutputPortSignal(chartInstance.S, 1);
  c2_j_b = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 3);
  c2_g_omega = (real_T (*)[100])ssGetInputPortSignal(chartInstance.S, 0);
  c2_d_A_cons = (real_T (*)[40])ssGetInputPortSignal(chartInstance.S, 2);
  c2_d_f = (real_T (*)[10])ssGetInputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c2_i7 = 0; c2_i7 < 10; c2_i7 = c2_i7 + 1) {
    for (c2_i8 = 0; c2_i8 < 10; c2_i8 = c2_i8 + 1) {
      c2_omega[c2_i8 + 10 * c2_i7] = (*c2_g_omega)[c2_i8 + 10 * c2_i7];
    }
  }

  for (c2_i9 = 0; c2_i9 < 10; c2_i9 = c2_i9 + 1) {
    c2_f[c2_i9] = (*c2_d_f)[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 10; c2_i10 = c2_i10 + 1) {
    for (c2_i11 = 0; c2_i11 < 4; c2_i11 = c2_i11 + 1) {
      c2_A_cons[c2_i11 + 4 * c2_i10] = (*c2_d_A_cons)[c2_i11 + 4 * c2_i10];
    }
  }

  for (c2_i12 = 0; c2_i12 < 4; c2_i12 = c2_i12 + 1) {
    c2_b[c2_i12] = (*c2_j_b)[c2_i12];
  }

  sf_debug_symbol_scope_push(22U, 0U);
  sf_debug_symbol_scope_add_verbose("nargout", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
    0U, 0, 0U, 0, 0, &c2_nargout);
  sf_debug_symbol_scope_add_verbose("nargin", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
    0, 0U, 0, 0, &c2_nargin);
  sf_debug_symbol_scope_add("al", &c2_al, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("la", &c2_la, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("w", &c2_w, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("lambda_p", &c2_lambda_p, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("km", &c2_km, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("lambda", &c2_lambda, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("x_ini", &c2_x_ini, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("m", &c2_m, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("n", &c2_n, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("d", &c2_d, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("P", &c2_P, c2_f_sf_marshall);
  sf_debug_symbol_scope_add("i", &c2_i, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("kk", &c2_kk, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("m1", &c2_m1, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("n1", &c2_n1, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("eta", &c2_eta, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("b", &c2_b, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("A_cons", &c2_A_cons, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("f", &c2_f, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("omega", &c2_omega, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c2_b_m1 = 10.0;
  c2_n1 = 4.0;
  c2_m1 = c2_b_m1;

  /*  eta=-omega\f; */
  _SFD_EML_CALL(0,5);
  for (c2_i13 = 0; c2_i13 < 10; c2_i13 = c2_i13 + 1) {
    for (c2_i14 = 0; c2_i14 < 10; c2_i14 = c2_i14 + 1) {
      c2_b_omega[c2_i14 + 10 * c2_i13] = c2_omega[c2_i14 + 10 * c2_i13];
    }
  }

  c2_inv(c2_b_omega, c2_dv0);
  for (c2_i15 = 0; c2_i15 < 10; c2_i15 = c2_i15 + 1) {
    for (c2_i16 = 0; c2_i16 < 10; c2_i16 = c2_i16 + 1) {
      c2_a[c2_i16 + 10 * c2_i15] = -c2_dv0[c2_i16 + 10 * c2_i15];
    }
  }

  for (c2_i17 = 0; c2_i17 < 10; c2_i17 = c2_i17 + 1) {
    c2_b_b[c2_i17] = c2_f[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 10; c2_i18 = c2_i18 + 1) {
    for (c2_i19 = 0; c2_i19 < 10; c2_i19 = c2_i19 + 1) {
      c2_A[c2_i19 + 10 * c2_i18] = c2_a[c2_i19 + 10 * c2_i18];
    }
  }

  for (c2_i20 = 0; c2_i20 < 10; c2_i20 = c2_i20 + 1) {
    c2_B[c2_i20] = c2_b_b[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 10; c2_i21 = c2_i21 + 1) {
    c2_C[c2_i21] = 0.0;
  }

  for (c2_i22 = 0; c2_i22 < 10; c2_i22 = c2_i22 + 1) {
    c2_eta[c2_i22] = c2_C[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 10; c2_i23 = c2_i23 + 1) {
    for (c2_i24 = 0; c2_i24 < 10; c2_i24 = c2_i24 + 1) {
      c2_b_A[c2_i24 + 10 * c2_i23] = c2_A[c2_i24 + 10 * c2_i23];
    }
  }

  for (c2_i25 = 0; c2_i25 < 10; c2_i25 = c2_i25 + 1) {
    c2_b_B[c2_i25] = c2_B[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 10; c2_i26 = c2_i26 + 1) {
    c2_b_C[c2_i26] = c2_eta[c2_i26];
  }

  for (c2_i27 = 0; c2_i27 < 10; c2_i27 = c2_i27 + 1) {
    c2_eta[c2_i27] = c2_b_C[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 10; c2_i28 = c2_i28 + 1) {
    for (c2_i29 = 0; c2_i29 < 10; c2_i29 = c2_i29 + 1) {
      c2_c_A[c2_i29 + 10 * c2_i28] = c2_b_A[c2_i29 + 10 * c2_i28];
    }
  }

  for (c2_i30 = 0; c2_i30 < 10; c2_i30 = c2_i30 + 1) {
    c2_c_B[c2_i30] = c2_b_B[c2_i30];
  }

  for (c2_i31 = 0; c2_i31 < 10; c2_i31 = c2_i31 + 1) {
    c2_eta[c2_i31] = 0.0;
    for (c2_i32 = 0; c2_i32 < 10; c2_i32 = c2_i32 + 1) {
      c2_eta[c2_i31] = c2_eta[c2_i31] + c2_c_A[c2_i31 + 10 * c2_i32] *
        c2_c_B[c2_i32];
    }
  }

  _SFD_EML_CALL(0,6);
  c2_kk = 0.0;
  c2_d0 = 1.0;
  c2_i = c2_d0;
  c2_b_i = c2_d0;
  while (c2_b_i <= 4.0) {
    c2_i = c2_b_i;
    CV_EML_FOR(0, 0, 1);
    _SFD_EML_CALL(0,8);
    c2_c_i = (int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A_cons", (int32_T)
      _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1;
    for (c2_i33 = 0; c2_i33 < 10; c2_i33 = c2_i33 + 1) {
      c2_hoistedExpr = 0;
      c2_b_a[c2_i33] = c2_A_cons[c2_c_i + 4 * c2_i33];
    }

    for (c2_i34 = 0; c2_i34 < 10; c2_i34 = c2_i34 + 1) {
      c2_c_b[c2_i34] = c2_eta[c2_i34];
    }

    for (c2_i35 = 0; c2_i35 < 10; c2_i35 = c2_i35 + 1) {
      c2_x[c2_i35] = c2_b_a[c2_i35];
    }

    for (c2_i36 = 0; c2_i36 < 10; c2_i36 = c2_i36 + 1) {
      c2_y[c2_i36] = c2_c_b[c2_i36];
    }

    for (c2_i37 = 0; c2_i37 < 10; c2_i37 = c2_i37 + 1) {
      c2_b_x[c2_i37] = c2_x[c2_i37];
    }

    for (c2_i38 = 0; c2_i38 < 10; c2_i38 = c2_i38 + 1) {
      c2_b_y[c2_i38] = c2_y[c2_i38];
    }

    for (c2_i39 = 0; c2_i39 < 10; c2_i39 = c2_i39 + 1) {
      c2_c_x[c2_i39] = c2_b_x[c2_i39];
    }

    for (c2_i40 = 0; c2_i40 < 10; c2_i40 = c2_i40 + 1) {
      c2_c_y[c2_i40] = c2_b_y[c2_i40];
    }

    for (c2_i41 = 0; c2_i41 < 10; c2_i41 = c2_i41 + 1) {
      c2_d_x[c2_i41] = c2_c_x[c2_i41];
    }

    for (c2_i42 = 0; c2_i42 < 10; c2_i42 = c2_i42 + 1) {
      c2_d_y[c2_i42] = c2_c_y[c2_i42];
    }

    for (c2_i43 = 0; c2_i43 < 10; c2_i43 = c2_i43 + 1) {
      c2_e_x[c2_i43] = c2_d_x[c2_i43];
    }

    for (c2_i44 = 0; c2_i44 < 10; c2_i44 = c2_i44 + 1) {
      c2_e_y[c2_i44] = c2_d_y[c2_i44];
    }

    c2_f_x = 0.0;
    c2_f_y = c2_f_x;
    c2_i45 = 1;
    for (c2_k = c2_i45; c2_k < 11; c2_k = c2_k + 1) {
      c2_b_k = c2_k;
      c2_f_y = c2_f_y + c2_e_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c2_b_k), 1, 10, 1, 0) - 1] *
        c2_e_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c2_b_k), 1, 10, 1, 0) - 1];
    }

    if (CV_EML_IF(0, 0, c2_f_y > c2_b[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("b",
          (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1])) {
      _SFD_EML_CALL(0,9);
      c2_kk = c2_kk + 1.0;
    } else {
      _SFD_EML_CALL(0,11);
    }

    c2_b_i = c2_b_i + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }

  CV_EML_FOR(0, 0, 0);
  _SFD_EML_CALL(0,14);
  if (CV_EML_IF(0, 1, c2_kk == 0.0)) {
  } else {
    _SFD_EML_CALL(0,17);
    for (c2_i46 = 0; c2_i46 < 10; c2_i46 = c2_i46 + 1) {
      for (c2_i47 = 0; c2_i47 < 4; c2_i47 = c2_i47 + 1) {
        c2_c_a[c2_i47 + 4 * c2_i46] = c2_A_cons[c2_i47 + 4 * c2_i46];
      }
    }

    for (c2_i48 = 0; c2_i48 < 10; c2_i48 = c2_i48 + 1) {
      for (c2_i49 = 0; c2_i49 < 10; c2_i49 = c2_i49 + 1) {
        c2_c_omega[c2_i49 + 10 * c2_i48] = c2_omega[c2_i49 + 10 * c2_i48];
      }
    }

    for (c2_i50 = 0; c2_i50 < 4; c2_i50 = c2_i50 + 1) {
      for (c2_i51 = 0; c2_i51 < 10; c2_i51 = c2_i51 + 1) {
        c2_b_A_cons[c2_i51 + 10 * c2_i50] = c2_A_cons[c2_i50 + 4 * c2_i51];
      }
    }

    c2_mldivide(c2_c_omega, c2_b_A_cons, c2_d_b);
    for (c2_i52 = 0; c2_i52 < 10; c2_i52 = c2_i52 + 1) {
      for (c2_i53 = 0; c2_i53 < 4; c2_i53 = c2_i53 + 1) {
        c2_d_A[c2_i53 + 4 * c2_i52] = c2_c_a[c2_i53 + 4 * c2_i52];
      }
    }

    for (c2_i54 = 0; c2_i54 < 4; c2_i54 = c2_i54 + 1) {
      for (c2_i55 = 0; c2_i55 < 10; c2_i55 = c2_i55 + 1) {
        c2_d_B[c2_i55 + 10 * c2_i54] = c2_d_b[c2_i55 + 10 * c2_i54];
      }
    }

    for (c2_i56 = 0; c2_i56 < 4; c2_i56 = c2_i56 + 1) {
      for (c2_i57 = 0; c2_i57 < 4; c2_i57 = c2_i57 + 1) {
        c2_c_C[c2_i57 + 4 * c2_i56] = 0.0;
      }
    }

    for (c2_i58 = 0; c2_i58 < 4; c2_i58 = c2_i58 + 1) {
      for (c2_i59 = 0; c2_i59 < 4; c2_i59 = c2_i59 + 1) {
        c2_P[c2_i59 + 4 * c2_i58] = c2_c_C[c2_i59 + 4 * c2_i58];
      }
    }

    for (c2_i60 = 0; c2_i60 < 10; c2_i60 = c2_i60 + 1) {
      for (c2_i61 = 0; c2_i61 < 4; c2_i61 = c2_i61 + 1) {
        c2_e_A[c2_i61 + 4 * c2_i60] = c2_d_A[c2_i61 + 4 * c2_i60];
      }
    }

    for (c2_i62 = 0; c2_i62 < 4; c2_i62 = c2_i62 + 1) {
      for (c2_i63 = 0; c2_i63 < 10; c2_i63 = c2_i63 + 1) {
        c2_e_B[c2_i63 + 10 * c2_i62] = c2_d_B[c2_i63 + 10 * c2_i62];
      }
    }

    for (c2_i64 = 0; c2_i64 < 4; c2_i64 = c2_i64 + 1) {
      for (c2_i65 = 0; c2_i65 < 4; c2_i65 = c2_i65 + 1) {
        c2_d_C[c2_i65 + 4 * c2_i64] = c2_P[c2_i65 + 4 * c2_i64];
      }
    }

    for (c2_i66 = 0; c2_i66 < 4; c2_i66 = c2_i66 + 1) {
      for (c2_i67 = 0; c2_i67 < 4; c2_i67 = c2_i67 + 1) {
        c2_P[c2_i67 + 4 * c2_i66] = c2_d_C[c2_i67 + 4 * c2_i66];
      }
    }

    for (c2_i68 = 0; c2_i68 < 10; c2_i68 = c2_i68 + 1) {
      for (c2_i69 = 0; c2_i69 < 4; c2_i69 = c2_i69 + 1) {
        c2_f_A[c2_i69 + 4 * c2_i68] = c2_e_A[c2_i69 + 4 * c2_i68];
      }
    }

    for (c2_i70 = 0; c2_i70 < 4; c2_i70 = c2_i70 + 1) {
      for (c2_i71 = 0; c2_i71 < 10; c2_i71 = c2_i71 + 1) {
        c2_f_B[c2_i71 + 10 * c2_i70] = c2_e_B[c2_i71 + 10 * c2_i70];
      }
    }

    for (c2_i72 = 0; c2_i72 < 4; c2_i72 = c2_i72 + 1) {
      for (c2_i73 = 0; c2_i73 < 4; c2_i73 = c2_i73 + 1) {
        c2_P[c2_i72 + 4 * c2_i73] = 0.0;
        for (c2_i74 = 0; c2_i74 < 10; c2_i74 = c2_i74 + 1) {
          c2_P[c2_i72 + 4 * c2_i73] = c2_P[c2_i72 + 4 * c2_i73] + c2_f_A[c2_i72
            + 4 * c2_i74] * c2_f_B[c2_i74 + 10 * c2_i73];
        }
      }
    }

    _SFD_EML_CALL(0,18);
    for (c2_i75 = 0; c2_i75 < 10; c2_i75 = c2_i75 + 1) {
      for (c2_i76 = 0; c2_i76 < 4; c2_i76 = c2_i76 + 1) {
        c2_d_a[c2_i76 + 4 * c2_i75] = c2_A_cons[c2_i76 + 4 * c2_i75];
      }
    }

    for (c2_i77 = 0; c2_i77 < 10; c2_i77 = c2_i77 + 1) {
      for (c2_i78 = 0; c2_i78 < 10; c2_i78 = c2_i78 + 1) {
        c2_d_omega[c2_i78 + 10 * c2_i77] = c2_omega[c2_i78 + 10 * c2_i77];
      }
    }

    for (c2_i79 = 0; c2_i79 < 10; c2_i79 = c2_i79 + 1) {
      c2_b_f[c2_i79] = c2_f[c2_i79];
    }

    c2_b_mldivide(c2_d_omega, c2_b_f, c2_e_b);
    for (c2_i80 = 0; c2_i80 < 10; c2_i80 = c2_i80 + 1) {
      for (c2_i81 = 0; c2_i81 < 4; c2_i81 = c2_i81 + 1) {
        c2_g_A[c2_i81 + 4 * c2_i80] = c2_d_a[c2_i81 + 4 * c2_i80];
      }
    }

    for (c2_i82 = 0; c2_i82 < 10; c2_i82 = c2_i82 + 1) {
      c2_g_B[c2_i82] = c2_e_b[c2_i82];
    }

    for (c2_i83 = 0; c2_i83 < 10; c2_i83 = c2_i83 + 1) {
      for (c2_i84 = 0; c2_i84 < 4; c2_i84 = c2_i84 + 1) {
        c2_h_A[c2_i84 + 4 * c2_i83] = c2_g_A[c2_i84 + 4 * c2_i83];
      }
    }

    for (c2_i85 = 0; c2_i85 < 10; c2_i85 = c2_i85 + 1) {
      c2_h_B[c2_i85] = c2_g_B[c2_i85];
    }

    for (c2_i86 = 0; c2_i86 < 10; c2_i86 = c2_i86 + 1) {
      for (c2_i87 = 0; c2_i87 < 4; c2_i87 = c2_i87 + 1) {
        c2_i_A[c2_i87 + 4 * c2_i86] = c2_h_A[c2_i87 + 4 * c2_i86];
      }
    }

    for (c2_i88 = 0; c2_i88 < 10; c2_i88 = c2_i88 + 1) {
      c2_i_B[c2_i88] = c2_h_B[c2_i88];
    }

    for (c2_i89 = 0; c2_i89 < 4; c2_i89 = c2_i89 + 1) {
      c2_g_y[c2_i89] = 0.0;
      for (c2_i90 = 0; c2_i90 < 10; c2_i90 = c2_i90 + 1) {
        c2_g_y[c2_i89] = c2_g_y[c2_i89] + c2_i_A[c2_i89 + 4 * c2_i90] *
          c2_i_B[c2_i90];
      }
    }

    for (c2_i91 = 0; c2_i91 < 4; c2_i91 = c2_i91 + 1) {
      c2_d[c2_i91] = c2_g_y[c2_i91] + c2_b[c2_i91];
    }

    _SFD_EML_CALL(0,19);
    c2_n = 4.0;
    c2_m = 1.0;
    _SFD_EML_CALL(0,20);
    for (c2_i92 = 0; c2_i92 < 4; c2_i92 = c2_i92 + 1) {
      c2_x_ini[c2_i92] = 0.0;
    }

    _SFD_EML_CALL(0,21);
    for (c2_i93 = 0; c2_i93 < 4; c2_i93 = c2_i93 + 1) {
      c2_lambda[c2_i93] = c2_x_ini[c2_i93];
    }

    /*  al=10; */
    c2_d1 = 1.0;
    c2_km = c2_d1;
    c2_b_km = c2_d1;
   label_1:
    ;
    if (c2_b_km <= 38.0) {
      c2_km = c2_b_km;
      CV_EML_FOR(0, 1, 1);

      /* find tomegae elements in tomegae solution vector one by one */
      /*  km could be larger if tomegae Lagranger multiplier omegaas a slow */
      /*  convergence rate. */
      _SFD_EML_CALL(0,28);
      for (c2_i94 = 0; c2_i94 < 4; c2_i94 = c2_i94 + 1) {
        c2_lambda_p[c2_i94] = c2_lambda[c2_i94];
      }

      c2_d2 = 1.0;
      c2_i = c2_d2;
      c2_d_i = c2_d2;
      while (c2_d_i <= 4.0) {
        c2_i = c2_d_i;
        CV_EML_FOR(0, 2, 1);
        _SFD_EML_CALL(0,30);
        c2_e_a = c2_P[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("P", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1) + 4 * ((int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("P", (int32_T)_SFD_INTEGER_CHECK("i", c2_i),
          1, 4, 2, 0) - 1)];
        c2_f_b = c2_lambda[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("lambda",
          (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1];
        c2_h_y = c2_e_a * c2_f_b;
        c2_e_i = (int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("P", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1;
        for (c2_i95 = 0; c2_i95 < 4; c2_i95 = c2_i95 + 1) {
          c2_b_hoistedExpr = 0;
          c2_f_a[c2_i95] = c2_P[c2_e_i + 4 * c2_i95];
        }

        for (c2_i96 = 0; c2_i96 < 4; c2_i96 = c2_i96 + 1) {
          c2_g_b[c2_i96] = c2_lambda[c2_i96];
        }

        for (c2_i97 = 0; c2_i97 < 4; c2_i97 = c2_i97 + 1) {
          c2_g_x[c2_i97] = c2_f_a[c2_i97];
        }

        for (c2_i98 = 0; c2_i98 < 4; c2_i98 = c2_i98 + 1) {
          c2_i_y[c2_i98] = c2_g_b[c2_i98];
        }

        for (c2_i99 = 0; c2_i99 < 4; c2_i99 = c2_i99 + 1) {
          c2_h_x[c2_i99] = c2_g_x[c2_i99];
        }

        for (c2_i100 = 0; c2_i100 < 4; c2_i100 = c2_i100 + 1) {
          c2_j_y[c2_i100] = c2_i_y[c2_i100];
        }

        for (c2_i101 = 0; c2_i101 < 4; c2_i101 = c2_i101 + 1) {
          c2_i_x[c2_i101] = c2_h_x[c2_i101];
        }

        for (c2_i102 = 0; c2_i102 < 4; c2_i102 = c2_i102 + 1) {
          c2_k_y[c2_i102] = c2_j_y[c2_i102];
        }

        for (c2_i103 = 0; c2_i103 < 4; c2_i103 = c2_i103 + 1) {
          c2_j_x[c2_i103] = c2_i_x[c2_i103];
        }

        for (c2_i104 = 0; c2_i104 < 4; c2_i104 = c2_i104 + 1) {
          c2_l_y[c2_i104] = c2_k_y[c2_i104];
        }

        for (c2_i105 = 0; c2_i105 < 4; c2_i105 = c2_i105 + 1) {
          c2_k_x[c2_i105] = c2_j_x[c2_i105];
        }

        for (c2_i106 = 0; c2_i106 < 4; c2_i106 = c2_i106 + 1) {
          c2_m_y[c2_i106] = c2_l_y[c2_i106];
        }

        c2_l_x = 0.0;
        c2_n_y = c2_l_x;
        c2_i107 = 1;
        for (c2_c_k = c2_i107; c2_c_k < 5; c2_c_k = c2_c_k + 1) {
          c2_d_k = c2_c_k;
          c2_n_y = c2_n_y + c2_k_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
            _SFD_INTEGER_CHECK("k", (real_T)c2_d_k), 1, 4, 1, 0) - 1] *
            c2_m_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK(
            "k", (real_T)c2_d_k), 1, 4, 1, 0) - 1];
        }

        c2_w = c2_n_y - c2_h_y;
        _SFD_EML_CALL(0,31);
        c2_w = c2_w + c2_d[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("d", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1];
        _SFD_EML_CALL(0,32);
        c2_la = c2_mrdivide(-c2_w, c2_P[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "P", (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1)
                            + 4 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("P",
          (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 4, 2, 0) - 1)]);
        _SFD_EML_CALL(0,33);
        c2_lambda[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("lambda", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_max(0.0,
          c2_la);
        c2_d_i = c2_d_i + 1.0;
        sf_mex_listen_for_ctrl_c(chartInstance.S);
      }

      CV_EML_FOR(0, 2, 0);
      _SFD_EML_CALL(0,36);
      for (c2_i108 = 0; c2_i108 < 4; c2_i108 = c2_i108 + 1) {
        c2_g_a[c2_i108] = c2_lambda[c2_i108] - c2_lambda_p[c2_i108];
      }

      for (c2_i109 = 0; c2_i109 < 4; c2_i109 = c2_i109 + 1) {
        c2_h_b[c2_i109] = c2_lambda[c2_i109] - c2_lambda_p[c2_i109];
      }

      for (c2_i110 = 0; c2_i110 < 4; c2_i110 = c2_i110 + 1) {
        c2_m_x[c2_i110] = c2_g_a[c2_i110];
      }

      for (c2_i111 = 0; c2_i111 < 4; c2_i111 = c2_i111 + 1) {
        c2_o_y[c2_i111] = c2_h_b[c2_i111];
      }

      for (c2_i112 = 0; c2_i112 < 4; c2_i112 = c2_i112 + 1) {
        c2_n_x[c2_i112] = c2_m_x[c2_i112];
      }

      for (c2_i113 = 0; c2_i113 < 4; c2_i113 = c2_i113 + 1) {
        c2_p_y[c2_i113] = c2_o_y[c2_i113];
      }

      for (c2_i114 = 0; c2_i114 < 4; c2_i114 = c2_i114 + 1) {
        c2_o_x[c2_i114] = c2_n_x[c2_i114];
      }

      for (c2_i115 = 0; c2_i115 < 4; c2_i115 = c2_i115 + 1) {
        c2_q_y[c2_i115] = c2_p_y[c2_i115];
      }

      for (c2_i116 = 0; c2_i116 < 4; c2_i116 = c2_i116 + 1) {
        c2_p_x[c2_i116] = c2_o_x[c2_i116];
      }

      for (c2_i117 = 0; c2_i117 < 4; c2_i117 = c2_i117 + 1) {
        c2_r_y[c2_i117] = c2_q_y[c2_i117];
      }

      for (c2_i118 = 0; c2_i118 < 4; c2_i118 = c2_i118 + 1) {
        c2_q_x[c2_i118] = c2_p_x[c2_i118];
      }

      for (c2_i119 = 0; c2_i119 < 4; c2_i119 = c2_i119 + 1) {
        c2_s_y[c2_i119] = c2_r_y[c2_i119];
      }

      c2_r_x = 0.0;
      c2_al = c2_r_x;
      c2_i120 = 1;
      for (c2_e_k = c2_i120; c2_e_k < 5; c2_e_k = c2_e_k + 1) {
        c2_f_k = c2_e_k;
        c2_al = c2_al + c2_q_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
          _SFD_INTEGER_CHECK("k", (real_T)c2_f_k), 1, 4, 1, 0) - 1] * c2_s_y[
          (int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
          (real_T)c2_f_k), 1, 4, 1, 0) - 1];
      }

      _SFD_EML_CALL(0,37);
      if (CV_EML_IF(0, 2, c2_al < 1.0E-007)) {
      } else {
        c2_b_km = c2_b_km + 1.0;
        sf_mex_listen_for_ctrl_c(chartInstance.S);
        goto label_1;
      }
    } else {
      CV_EML_FOR(0, 1, 0);
    }

    _SFD_EML_CALL(0,41);
    for (c2_i121 = 0; c2_i121 < 10; c2_i121 = c2_i121 + 1) {
      for (c2_i122 = 0; c2_i122 < 10; c2_i122 = c2_i122 + 1) {
        c2_e_omega[c2_i122 + 10 * c2_i121] = c2_omega[c2_i122 + 10 * c2_i121];
      }
    }

    for (c2_i123 = 0; c2_i123 < 4; c2_i123 = c2_i123 + 1) {
      for (c2_i124 = 0; c2_i124 < 10; c2_i124 = c2_i124 + 1) {
        c2_c_A_cons[c2_i124 + 10 * c2_i123] = c2_A_cons[c2_i123 + 4 * c2_i124];
      }
    }

    c2_mldivide(c2_e_omega, c2_c_A_cons, c2_h_a);
    for (c2_i125 = 0; c2_i125 < 4; c2_i125 = c2_i125 + 1) {
      c2_i_b[c2_i125] = c2_lambda[c2_i125];
    }

    for (c2_i126 = 0; c2_i126 < 4; c2_i126 = c2_i126 + 1) {
      for (c2_i127 = 0; c2_i127 < 10; c2_i127 = c2_i127 + 1) {
        c2_j_A[c2_i127 + 10 * c2_i126] = c2_h_a[c2_i127 + 10 * c2_i126];
      }
    }

    for (c2_i128 = 0; c2_i128 < 4; c2_i128 = c2_i128 + 1) {
      c2_j_B[c2_i128] = c2_i_b[c2_i128];
    }

    for (c2_i129 = 0; c2_i129 < 4; c2_i129 = c2_i129 + 1) {
      for (c2_i130 = 0; c2_i130 < 10; c2_i130 = c2_i130 + 1) {
        c2_k_A[c2_i130 + 10 * c2_i129] = c2_j_A[c2_i130 + 10 * c2_i129];
      }
    }

    for (c2_i131 = 0; c2_i131 < 4; c2_i131 = c2_i131 + 1) {
      c2_k_B[c2_i131] = c2_j_B[c2_i131];
    }

    for (c2_i132 = 0; c2_i132 < 4; c2_i132 = c2_i132 + 1) {
      for (c2_i133 = 0; c2_i133 < 10; c2_i133 = c2_i133 + 1) {
        c2_l_A[c2_i133 + 10 * c2_i132] = c2_k_A[c2_i133 + 10 * c2_i132];
      }
    }

    for (c2_i134 = 0; c2_i134 < 4; c2_i134 = c2_i134 + 1) {
      c2_l_B[c2_i134] = c2_k_B[c2_i134];
    }

    for (c2_i135 = 0; c2_i135 < 10; c2_i135 = c2_i135 + 1) {
      c2_t_y[c2_i135] = 0.0;
      for (c2_i136 = 0; c2_i136 < 4; c2_i136 = c2_i136 + 1) {
        c2_t_y[c2_i135] = c2_t_y[c2_i135] + c2_l_A[c2_i135 + 10 * c2_i136] *
          c2_l_B[c2_i136];
      }
    }

    for (c2_i137 = 0; c2_i137 < 10; c2_i137 = c2_i137 + 1) {
      for (c2_i138 = 0; c2_i138 < 10; c2_i138 = c2_i138 + 1) {
        c2_f_omega[c2_i138 + 10 * c2_i137] = -c2_omega[c2_i138 + 10 * c2_i137];
      }
    }

    for (c2_i139 = 0; c2_i139 < 10; c2_i139 = c2_i139 + 1) {
      c2_c_f[c2_i139] = c2_f[c2_i139];
    }

    c2_b_mldivide(c2_f_omega, c2_c_f, c2_dv1);
    for (c2_i140 = 0; c2_i140 < 10; c2_i140 = c2_i140 + 1) {
      c2_eta[c2_i140] = c2_dv1[c2_i140] - c2_t_y[c2_i140];
    }
  }

  _SFD_EML_CALL(0,-41);
  sf_debug_symbol_scope_pop();
  for (c2_i141 = 0; c2_i141 < 10; c2_i141 = c2_i141 + 1) {
    (*c2_b_eta)[c2_i141] = c2_eta[c2_i141];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static void c2_inv(real_T c2_x[100], real_T c2_y[100])
{
  int32_T c2_i142;
  int32_T c2_i143;
  real_T c2_b_x[100];
  int32_T c2_i144;
  int32_T c2_i145;
  real_T c2_c_x[100];
  int32_T c2_i146;
  int32_T c2_i147;
  real_T c2_xinv[100];
  int32_T c2_i148;
  int32_T c2_i149;
  real_T c2_d_x[100];
  real_T c2_n1x;
  int32_T c2_i150;
  int32_T c2_i151;
  real_T c2_b_xinv[100];
  real_T c2_n1xinv;
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_y;
  real_T c2_rc;
  real_T c2_e_x;
  boolean_T c2_b_b;
  real_T c2_r;
  for (c2_i142 = 0; c2_i142 < 10; c2_i142 = c2_i142 + 1) {
    for (c2_i143 = 0; c2_i143 < 10; c2_i143 = c2_i143 + 1) {
      c2_b_x[c2_i143 + 10 * c2_i142] = c2_x[c2_i143 + 10 * c2_i142];
    }
  }

  c2_invNxN(c2_b_x, c2_y);
  for (c2_i144 = 0; c2_i144 < 10; c2_i144 = c2_i144 + 1) {
    for (c2_i145 = 0; c2_i145 < 10; c2_i145 = c2_i145 + 1) {
      c2_c_x[c2_i145 + 10 * c2_i144] = c2_x[c2_i145 + 10 * c2_i144];
    }
  }

  for (c2_i146 = 0; c2_i146 < 10; c2_i146 = c2_i146 + 1) {
    for (c2_i147 = 0; c2_i147 < 10; c2_i147 = c2_i147 + 1) {
      c2_xinv[c2_i147 + 10 * c2_i146] = c2_y[c2_i147 + 10 * c2_i146];
    }
  }

  for (c2_i148 = 0; c2_i148 < 10; c2_i148 = c2_i148 + 1) {
    for (c2_i149 = 0; c2_i149 < 10; c2_i149 = c2_i149 + 1) {
      c2_d_x[c2_i149 + 10 * c2_i148] = c2_c_x[c2_i149 + 10 * c2_i148];
    }
  }

  c2_n1x = c2_norm(c2_d_x);
  for (c2_i150 = 0; c2_i150 < 10; c2_i150 = c2_i150 + 1) {
    for (c2_i151 = 0; c2_i151 < 10; c2_i151 = c2_i151 + 1) {
      c2_b_xinv[c2_i151 + 10 * c2_i150] = c2_xinv[c2_i151 + 10 * c2_i150];
    }
  }

  c2_n1xinv = c2_norm(c2_b_xinv);
  c2_a = c2_n1x;
  c2_b = c2_n1xinv;
  c2_b_y = c2_a * c2_b;
  c2_rc = 1.0 / c2_b_y;
  if (c2_n1x == 0.0) {
    goto label_1;
  } else if (c2_n1xinv == 0.0) {
    goto label_1;
  } else if (c2_rc == 0.0) {
    goto label_1;
  } else {
    c2_e_x = c2_rc;
    c2_b_b = rtIsNaN(c2_e_x);
    if (c2_b_b) {
    } else {
      c2_r = 2.2204460492503131E-016;
      if (c2_rc < c2_r) {
      } else {
        return;
      }
    }
  }

  c2_b_eml_warning(c2_rc);
  return;
 label_1:
  ;
  c2_eml_warning();
}

static void c2_invNxN(real_T c2_x[100], real_T c2_y[100])
{
  int32_T c2_i152;
  int32_T c2_i153;
  real_T c2_b_x[100];
  int32_T c2_i154;
  int32_T c2_i155;
  int32_T c2_i156;
  int32_T c2_i157;
  real_T c2_A[100];
  int32_T c2_i158;
  int32_T c2_i159;
  real_T c2_c_x[100];
  int32_T c2_i160;
  int32_T c2_hoistedExpr;
  int32_T c2_d_x[10];
  int32_T c2_i161;
  int32_T c2_ipiv[10];
  int32_T c2_i162;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  real_T c2_b;
  real_T c2_d3;
  real_T c2_d4;
  int32_T c2_i163;
  int32_T c2_jm1;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_mmj;
  int32_T c2_c_a;
  int32_T c2_d_a;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_jj;
  int32_T c2_e_a;
  real_T c2_e_b;
  real_T c2_d5;
  real_T c2_d6;
  int32_T c2_i164;
  int32_T c2_jp1j;
  int32_T c2_f_a;
  real_T c2_f_b;
  real_T c2_d7;
  real_T c2_d8;
  int32_T c2_i165;
  int32_T c2_c;
  int32_T c2_i166;
  int32_T c2_i167;
  real_T c2_e_x[100];
  int32_T c2_g_a;
  real_T c2_g_b;
  real_T c2_d9;
  real_T c2_d10;
  int32_T c2_i168;
  int32_T c2_jpiv_offset;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_jpiv;
  int32_T c2_i_a;
  int32_T c2_i_b;
  int32_T c2_b_c;
  int32_T c2_j_a;
  int32_T c2_j_b;
  int32_T c2_jrow;
  int32_T c2_k_a;
  int32_T c2_k_b;
  int32_T c2_jprow;
  int32_T c2_i169;
  int32_T c2_i170;
  real_T c2_f_x[100];
  int32_T c2_b_jp1j;
  int32_T c2_l_a;
  int32_T c2_m_a;
  real_T c2_l_b;
  real_T c2_d11;
  real_T c2_d12;
  int32_T c2_i171;
  int32_T c2_m_b;
  int32_T c2_loop_ub;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_g_x;
  real_T c2_b_y;
  real_T c2_h_x;
  real_T c2_c_y;
  real_T c2_z;
  int32_T c2_n_a;
  int32_T c2_n_b;
  int32_T c2_c_c;
  int32_T c2_o_a;
  int32_T c2_o_b;
  int32_T c2_d_c;
  int32_T c2_p_a;
  int32_T c2_p_b;
  int32_T c2_e_c;
  int32_T c2_i172;
  int32_T c2_i173;
  real_T c2_i_x[100];
  int32_T c2_i174;
  int32_T c2_i175;
  int32_T c2_i176;
  int32_T c2_b_ipiv[10];
  int32_T c2_i177;
  int32_T c2_c_ipiv[10];
  int32_T c2_i178;
  int32_T c2_b_hoistedExpr;
  int32_T c2_j_x[10];
  int32_T c2_i179;
  int32_T c2_p[10];
  real_T c2_d13;
  real_T c2_k;
  real_T c2_b_k;
  int32_T c2_ipk;
  int32_T c2_pipk;
  int32_T c2_i180;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_f_c;
  int32_T c2_e_k;
  int32_T c2_c_j;
  int32_T c2_d_j;
  int32_T c2_i181;
  int32_T c2_i182;
  int32_T c2_i183;
  int32_T c2_i184;
  int32_T c2_c_i;
  int32_T c2_d_i;
  real_T c2_q_a;
  real_T c2_q_b;
  real_T c2_d_y;
  int32_T c2_m;
  int32_T c2_n;
  real_T c2_alpha1;
  int32_T c2_i185;
  int32_T c2_i186;
  real_T c2_b_A[100];
  int32_T c2_ia0;
  int32_T c2_lda;
  int32_T c2_i187;
  int32_T c2_i188;
  real_T c2_B[100];
  int32_T c2_ib0;
  int32_T c2_ldb;
  int32_T c2_i189;
  int32_T c2_i190;
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_i191;
  int32_T c2_i192;
  real_T c2_c_A[100];
  int32_T c2_b_ia0;
  int32_T c2_b_lda;
  int32_T c2_i193;
  int32_T c2_i194;
  real_T c2_b_B[100];
  int32_T c2_b_ib0;
  int32_T c2_b_ldb;
  int32_T c2_i195;
  int32_T c2_i196;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_c_alpha1;
  int32_T c2_i197;
  int32_T c2_i198;
  real_T c2_d_A[100];
  int32_T c2_c_ia0;
  int32_T c2_c_lda;
  int32_T c2_i199;
  int32_T c2_i200;
  real_T c2_c_B[100];
  int32_T c2_c_ib0;
  int32_T c2_c_ldb;
  int32_T c2_i201;
  int32_T c2_i202;
  boolean_T c2_NON_UNIT_ALPHA;
  int32_T c2_i203;
  int32_T c2_i204;
  int32_T c2_i205;
  int32_T c2_Aoffset;
  int32_T c2_i206;
  int32_T c2_i207;
  int32_T c2_i208;
  int32_T c2_Boffset;
  int32_T c2_i209;
  int32_T c2_b_loop_ub;
  int32_T c2_e_j;
  int32_T c2_f_j;
  int32_T c2_i210;
  int32_T c2_i211;
  int32_T c2_i212;
  int32_T c2_i213;
  int32_T c2_i214;
  int32_T c2_i215;
  int32_T c2_jBcol;
  int32_T c2_i216;
  int32_T c2_c_loop_ub;
  int32_T c2_e_i;
  int32_T c2_f_i;
  int32_T c2_i217;
  int32_T c2_i218;
  int32_T c2_i219;
  int32_T c2_i220;
  int32_T c2_d_loop_ub;
  int32_T c2_g_j;
  int32_T c2_i221;
  int32_T c2_i222;
  int32_T c2_i223;
  int32_T c2_i224;
  int32_T c2_i225;
  int32_T c2_i226;
  int32_T c2_i227;
  int32_T c2_e_loop_ub;
  int32_T c2_g_i;
  int32_T c2_i228;
  int32_T c2_i229;
  int32_T c2_i230;
  int32_T c2_i231;
  int32_T c2_i232;
  int32_T c2_i233;
  int32_T c2_d_m;
  real_T c2_f_loop_ub;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_i234;
  int32_T c2_i235;
  int32_T c2_i236;
  int32_T c2_i237;
  int32_T c2_i238;
  int32_T c2_i239;
  int32_T c2_kAcol;
  int32_T c2_i240;
  int32_T c2_i241;
  int32_T c2_i242;
  int32_T c2_i243;
  int32_T c2_i244;
  int32_T c2_i245;
  real_T c2_k_x;
  int32_T c2_i246;
  int32_T c2_i247;
  int32_T c2_i248;
  real_T c2_e_y;
  real_T c2_l_x;
  real_T c2_f_y;
  real_T c2_b_z;
  int32_T c2_i249;
  int32_T c2_i250;
  int32_T c2_i251;
  int32_T c2_i252;
  int32_T c2_i253;
  int32_T c2_i254;
  int32_T c2_i255;
  int32_T c2_g_loop_ub;
  int32_T c2_h_i;
  int32_T c2_i256;
  int32_T c2_i257;
  int32_T c2_i258;
  int32_T c2_i259;
  int32_T c2_i260;
  int32_T c2_i261;
  int32_T c2_i262;
  int32_T c2_i263;
  int32_T c2_i264;
  int32_T c2_i265;
  int32_T c2_i266;
  int32_T c2_i267;
  for (c2_i152 = 0; c2_i152 < 10; c2_i152 = c2_i152 + 1) {
    for (c2_i153 = 0; c2_i153 < 10; c2_i153 = c2_i153 + 1) {
      c2_b_x[c2_i153 + 10 * c2_i152] = 0.0;
    }
  }

  for (c2_i154 = 0; c2_i154 < 10; c2_i154 = c2_i154 + 1) {
    for (c2_i155 = 0; c2_i155 < 10; c2_i155 = c2_i155 + 1) {
      c2_y[c2_i155 + 10 * c2_i154] = c2_b_x[c2_i155 + 10 * c2_i154];
    }
  }

  for (c2_i156 = 0; c2_i156 < 10; c2_i156 = c2_i156 + 1) {
    for (c2_i157 = 0; c2_i157 < 10; c2_i157 = c2_i157 + 1) {
      c2_A[c2_i157 + 10 * c2_i156] = c2_x[c2_i157 + 10 * c2_i156];
    }
  }

  for (c2_i158 = 0; c2_i158 < 10; c2_i158 = c2_i158 + 1) {
    for (c2_i159 = 0; c2_i159 < 10; c2_i159 = c2_i159 + 1) {
      c2_c_x[c2_i159 + 10 * c2_i158] = c2_A[c2_i159 + 10 * c2_i158];
    }
  }

  for (c2_i160 = 0; c2_i160 < 10; c2_i160 = c2_i160 + 1) {
    c2_hoistedExpr = 0;
    c2_d_x[c2_i160] = 1 + c2_i160;
  }

  for (c2_i161 = 0; c2_i161 < 10; c2_i161 = c2_i161 + 1) {
    c2_ipiv[c2_i161] = c2_d_x[c2_i161];
  }

  c2_i162 = 1;
  for (c2_j = c2_i162; c2_j < 10; c2_j = c2_j + 1) {
    c2_b_j = c2_j;
    c2_a = c2_b_j;
    c2_b = 1.0;
    c2_d3 = c2_b;
    c2_d4 = c2_d3 < 0.0 ? ceil(c2_d3 - 0.5) : floor(c2_d3 + 0.5);
    if (c2_d4 < 2.147483648E+009) {
      if (c2_d4 >= -2.147483648E+009) {
        c2_i163 = (int32_T)c2_d4;
      } else {
        c2_i163 = MIN_int32_T;
      }
    } else {
      c2_i163 = MAX_int32_T;
    }

    c2_jm1 = c2_a - c2_i163;
    c2_b_a = 10;
    c2_b_b = c2_b_j;
    c2_mmj = c2_b_a - c2_b_b;
    c2_c_a = 1;
    c2_d_a = c2_jm1;
    c2_c_b = 11;
    c2_d_b = c2_d_a * c2_c_b;
    c2_jj = c2_c_a + c2_d_b;
    c2_e_a = c2_jj;
    c2_e_b = 1.0;
    c2_d5 = c2_e_b;
    c2_d6 = c2_d5 < 0.0 ? ceil(c2_d5 - 0.5) : floor(c2_d5 + 0.5);
    if (c2_d6 < 2.147483648E+009) {
      if (c2_d6 >= -2.147483648E+009) {
        c2_i164 = (int32_T)c2_d6;
      } else {
        c2_i164 = MIN_int32_T;
      }
    } else {
      c2_i164 = MAX_int32_T;
    }

    c2_jp1j = c2_e_a + c2_i164;
    c2_f_a = c2_mmj;
    c2_f_b = 1.0;
    c2_d7 = c2_f_b;
    c2_d8 = c2_d7 < 0.0 ? ceil(c2_d7 - 0.5) : floor(c2_d7 + 0.5);
    if (c2_d8 < 2.147483648E+009) {
      if (c2_d8 >= -2.147483648E+009) {
        c2_i165 = (int32_T)c2_d8;
      } else {
        c2_i165 = MIN_int32_T;
      }
    } else {
      c2_i165 = MAX_int32_T;
    }

    c2_c = c2_f_a + c2_i165;
    for (c2_i166 = 0; c2_i166 < 10; c2_i166 = c2_i166 + 1) {
      for (c2_i167 = 0; c2_i167 < 10; c2_i167 = c2_i167 + 1) {
        c2_e_x[c2_i167 + 10 * c2_i166] = c2_c_x[c2_i167 + 10 * c2_i166];
      }
    }

    c2_g_a = c2_eml_ixamax(c2_c, c2_e_x, c2_jj, 1);
    c2_g_b = 1.0;
    c2_d9 = c2_g_b;
    c2_d10 = c2_d9 < 0.0 ? ceil(c2_d9 - 0.5) : floor(c2_d9 + 0.5);
    if (c2_d10 < 2.147483648E+009) {
      if (c2_d10 >= -2.147483648E+009) {
        c2_i168 = (int32_T)c2_d10;
      } else {
        c2_i168 = MIN_int32_T;
      }
    } else {
      c2_i168 = MAX_int32_T;
    }

    c2_jpiv_offset = c2_g_a - c2_i168;
    c2_h_a = c2_jj;
    c2_h_b = c2_jpiv_offset;
    c2_jpiv = c2_h_a + c2_h_b;
    if (c2_c_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK(
          "jpiv", (real_T)c2_jpiv), 1, 100, 1, 0) - 1] != 0.0) {
      if ((real_T)c2_jpiv_offset != 0.0) {
        c2_i_a = c2_b_j;
        c2_i_b = c2_jpiv_offset;
        c2_b_c = c2_i_a + c2_i_b;
        c2_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv", _SFD_INTEGER_CHECK(
          "j", (real_T)c2_b_j), 1, 10, 1, 0) - 1] = c2_b_c;
        c2_j_a = 1;
        c2_j_b = c2_jm1;
        c2_jrow = c2_j_a + c2_j_b;
        c2_k_a = c2_jrow;
        c2_k_b = c2_jpiv_offset;
        c2_jprow = c2_k_a + c2_k_b;
        for (c2_i169 = 0; c2_i169 < 10; c2_i169 = c2_i169 + 1) {
          for (c2_i170 = 0; c2_i170 < 10; c2_i170 = c2_i170 + 1) {
            c2_f_x[c2_i170 + 10 * c2_i169] = c2_c_x[c2_i170 + 10 * c2_i169];
          }
        }

        c2_eml_xswap(c2_f_x, c2_jrow, c2_jprow, c2_c_x);
      }

      c2_b_jp1j = c2_jp1j;
      c2_l_a = c2_jp1j;
      c2_m_a = c2_mmj;
      c2_l_b = 1.0;
      c2_d11 = c2_l_b;
      c2_d12 = c2_d11 < 0.0 ? ceil(c2_d11 - 0.5) : floor(c2_d11 + 0.5);
      if (c2_d12 < 2.147483648E+009) {
        if (c2_d12 >= -2.147483648E+009) {
          c2_i171 = (int32_T)c2_d12;
        } else {
          c2_i171 = MIN_int32_T;
        }
      } else {
        c2_i171 = MAX_int32_T;
      }

      c2_m_b = c2_m_a - c2_i171;
      c2_loop_ub = c2_l_a + c2_m_b;
      for (c2_i = c2_b_jp1j; c2_i <= c2_loop_ub; c2_i = c2_i + 1) {
        c2_b_i = c2_i;
        c2_g_x = c2_c_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          _SFD_INTEGER_CHECK("i", (real_T)c2_b_i), 1, 100, 1, 0) - 1];
        c2_b_y = c2_c_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          _SFD_INTEGER_CHECK("jj", (real_T)c2_jj), 1, 100, 1, 0) - 1];
        c2_h_x = c2_g_x;
        c2_c_y = c2_b_y;
        c2_z = c2_h_x / c2_c_y;
        c2_c_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("i",
          (real_T)c2_b_i), 1, 100, 1, 0) - 1] = c2_z;
      }
    }

    c2_n_a = c2_jj;
    c2_n_b = 11;
    c2_c_c = c2_n_a + c2_n_b;
    c2_o_a = c2_jj;
    c2_o_b = 10;
    c2_d_c = c2_o_a + c2_o_b;
    c2_p_a = 10;
    c2_p_b = c2_b_j;
    c2_e_c = c2_p_a - c2_p_b;
    for (c2_i172 = 0; c2_i172 < 10; c2_i172 = c2_i172 + 1) {
      for (c2_i173 = 0; c2_i173 < 10; c2_i173 = c2_i173 + 1) {
        c2_i_x[c2_i173 + 10 * c2_i172] = c2_c_x[c2_i173 + 10 * c2_i172];
      }
    }

    c2_eml_xgeru(c2_mmj, c2_e_c, c2_jp1j, c2_d_c, c2_i_x, c2_c_c, c2_c_x);
  }

  for (c2_i174 = 0; c2_i174 < 10; c2_i174 = c2_i174 + 1) {
    for (c2_i175 = 0; c2_i175 < 10; c2_i175 = c2_i175 + 1) {
      c2_x[c2_i175 + 10 * c2_i174] = c2_c_x[c2_i175 + 10 * c2_i174];
    }
  }

  for (c2_i176 = 0; c2_i176 < 10; c2_i176 = c2_i176 + 1) {
    c2_b_ipiv[c2_i176] = c2_ipiv[c2_i176];
  }

  for (c2_i177 = 0; c2_i177 < 10; c2_i177 = c2_i177 + 1) {
    c2_c_ipiv[c2_i177] = c2_b_ipiv[c2_i177];
  }

  for (c2_i178 = 0; c2_i178 < 10; c2_i178 = c2_i178 + 1) {
    c2_b_hoistedExpr = 0;
    c2_j_x[c2_i178] = 1 + c2_i178;
  }

  for (c2_i179 = 0; c2_i179 < 10; c2_i179 = c2_i179 + 1) {
    c2_p[c2_i179] = c2_j_x[c2_i179];
  }

  c2_d13 = 1.0;
  for (c2_k = c2_d13; c2_k <= 10.0; c2_k = c2_k + 1.0) {
    c2_b_k = c2_k;
    c2_ipk = c2_c_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_b_k), 1, 10, 1, 0) - 1];
    if ((real_T)c2_ipk > c2_b_k) {
      c2_pipk = c2_p[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("perm",
        _SFD_INTEGER_CHECK("ipk", (real_T)c2_ipk), 1, 10, 1, 0) - 1];
      c2_p[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("perm", _SFD_INTEGER_CHECK("ipk",
        (real_T)c2_ipk), 1, 10, 1, 0) - 1] = c2_p[(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("perm", (int32_T)_SFD_INTEGER_CHECK("k",
        c2_b_k), 1, 10, 1, 0) - 1];
      c2_p[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("perm", (int32_T)
        _SFD_INTEGER_CHECK("k", c2_b_k), 1, 10, 1, 0) - 1] = c2_pipk;
    }
  }

  c2_i180 = 1;
  for (c2_c_k = c2_i180; c2_c_k < 11; c2_c_k = c2_c_k + 1) {
    c2_d_k = c2_c_k;
    c2_f_c = c2_p[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("p", _SFD_INTEGER_CHECK(
      "k", (real_T)c2_d_k), 1, 10, 1, 0) - 1];
    c2_y[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
            (real_T)c2_d_k), 1, 10, 1, 0) - 1) + 10 * ((int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("c", (real_T)c2_f_c),
      1, 10, 2, 0) - 1)] = 1.0;
    c2_e_k = c2_d_k;
    for (c2_c_j = c2_e_k; c2_c_j < 11; c2_c_j = c2_c_j + 1) {
      c2_d_j = c2_c_j;
      if (c2_y[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("j",
             (real_T)c2_d_j), 1, 10, 1, 0) - 1) + 10 * ((int32_T)
           _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("c", (real_T)
             c2_f_c), 1, 10, 2, 0) - 1)] != 0.0) {
        c2_i181 = c2_d_j;
        c2_i182 = 1;
        c2_i183 = c2_i181 + c2_i182;
        if ((c2_i181 < 0) && (c2_i182 < 0) && (c2_i183 >= 0)) {
          c2_i183 = MIN_int32_T;
        } else {
          if ((c2_i181 > 0) && (c2_i182 > 0) && (c2_i183 <= 0)) {
            c2_i183 = MAX_int32_T;
          }
        }

        c2_i184 = c2_i183;
        for (c2_c_i = c2_i184; c2_c_i < 11; c2_c_i = c2_c_i + 1) {
          c2_d_i = c2_c_i;
          c2_q_a = c2_y[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
            _SFD_INTEGER_CHECK("j", (real_T)c2_d_j), 1, 10, 1, 0) - 1) + 10 *
            ((int32_T
              )_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("c", (real_T)
               c2_f_c), 1, 10, 2, 0) - 1)];
          c2_q_b = c2_x[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
            _SFD_INTEGER_CHECK("i", (real_T)c2_d_i), 1, 10, 1, 0) - 1) + 10 *
            ((int32_T
              )_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("j", (real_T)
               c2_d_j), 1, 10, 2, 0) - 1)];
          c2_d_y = c2_q_a * c2_q_b;
          c2_y[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("i",
                  (real_T)c2_d_i), 1, 10, 1, 0) - 1) + 10 * ((int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("c", (real_T)
            c2_f_c), 1, 10, 2, 0) - 1)] = c2_y[((int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("i", (real_T)
            c2_d_i), 1, 10, 1, 0) - 1) + 10 * ((int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("c", (real_T)
            c2_f_c), 1, 10, 2, 0) - 1)] - c2_d_y;
        }
      }
    }
  }

  c2_m = 10;
  c2_n = 10;
  c2_alpha1 = 1.0;
  for (c2_i185 = 0; c2_i185 < 10; c2_i185 = c2_i185 + 1) {
    for (c2_i186 = 0; c2_i186 < 10; c2_i186 = c2_i186 + 1) {
      c2_b_A[c2_i186 + 10 * c2_i185] = c2_x[c2_i186 + 10 * c2_i185];
    }
  }

  c2_ia0 = 1;
  c2_lda = 10;
  for (c2_i187 = 0; c2_i187 < 10; c2_i187 = c2_i187 + 1) {
    for (c2_i188 = 0; c2_i188 < 10; c2_i188 = c2_i188 + 1) {
      c2_B[c2_i188 + 10 * c2_i187] = c2_y[c2_i188 + 10 * c2_i187];
    }
  }

  c2_ib0 = 1;
  c2_ldb = 10;
  for (c2_i189 = 0; c2_i189 < 10; c2_i189 = c2_i189 + 1) {
    for (c2_i190 = 0; c2_i190 < 10; c2_i190 = c2_i190 + 1) {
      c2_y[c2_i190 + 10 * c2_i189] = c2_B[c2_i190 + 10 * c2_i189];
    }
  }

  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  for (c2_i191 = 0; c2_i191 < 10; c2_i191 = c2_i191 + 1) {
    for (c2_i192 = 0; c2_i192 < 10; c2_i192 = c2_i192 + 1) {
      c2_c_A[c2_i192 + 10 * c2_i191] = c2_b_A[c2_i192 + 10 * c2_i191];
    }
  }

  c2_b_ia0 = c2_ia0;
  c2_b_lda = c2_lda;
  for (c2_i193 = 0; c2_i193 < 10; c2_i193 = c2_i193 + 1) {
    for (c2_i194 = 0; c2_i194 < 10; c2_i194 = c2_i194 + 1) {
      c2_b_B[c2_i194 + 10 * c2_i193] = c2_y[c2_i194 + 10 * c2_i193];
    }
  }

  c2_b_ib0 = c2_ib0;
  c2_b_ldb = c2_ldb;
  for (c2_i195 = 0; c2_i195 < 10; c2_i195 = c2_i195 + 1) {
    for (c2_i196 = 0; c2_i196 < 10; c2_i196 = c2_i196 + 1) {
      c2_y[c2_i196 + 10 * c2_i195] = c2_b_B[c2_i196 + 10 * c2_i195];
    }
  }

  c2_c_m = c2_b_m;
  c2_c_n = c2_b_n;
  c2_c_alpha1 = c2_b_alpha1;
  for (c2_i197 = 0; c2_i197 < 10; c2_i197 = c2_i197 + 1) {
    for (c2_i198 = 0; c2_i198 < 10; c2_i198 = c2_i198 + 1) {
      c2_d_A[c2_i198 + 10 * c2_i197] = c2_c_A[c2_i198 + 10 * c2_i197];
    }
  }

  c2_c_ia0 = c2_b_ia0;
  c2_c_lda = c2_b_lda;
  for (c2_i199 = 0; c2_i199 < 10; c2_i199 = c2_i199 + 1) {
    for (c2_i200 = 0; c2_i200 < 10; c2_i200 = c2_i200 + 1) {
      c2_c_B[c2_i200 + 10 * c2_i199] = c2_y[c2_i200 + 10 * c2_i199];
    }
  }

  c2_c_ib0 = c2_b_ib0;
  c2_c_ldb = c2_b_ldb;
  for (c2_i201 = 0; c2_i201 < 10; c2_i201 = c2_i201 + 1) {
    for (c2_i202 = 0; c2_i202 < 10; c2_i202 = c2_i202 + 1) {
      c2_y[c2_i202 + 10 * c2_i201] = c2_c_B[c2_i202 + 10 * c2_i201];
    }
  }

  c2_NON_UNIT_ALPHA = (c2_c_alpha1 != 1.0);
  if ((real_T)c2_c_n == 0.0) {
  } else {
    c2_i203 = c2_c_ia0;
    c2_i204 = 1;
    c2_i205 = c2_i203 - c2_i204;
    if ((c2_i203 < 0) && (c2_i204 >= 0) && (c2_i205 >= 0)) {
      c2_i205 = MIN_int32_T;
    } else {
      if ((c2_i203 >= 0) && (c2_i204 < 0) && (c2_i205 < 0)) {
        c2_i205 = MAX_int32_T;
      }
    }

    c2_Aoffset = c2_i205;
    c2_i206 = c2_c_ib0;
    c2_i207 = 1;
    c2_i208 = c2_i206 - c2_i207;
    if ((c2_i206 < 0) && (c2_i207 >= 0) && (c2_i208 >= 0)) {
      c2_i208 = MIN_int32_T;
    } else {
      if ((c2_i206 >= 0) && (c2_i207 < 0) && (c2_i208 < 0)) {
        c2_i208 = MAX_int32_T;
      }
    }

    c2_Boffset = c2_i208;
    if (c2_c_alpha1 == 0.0) {
      c2_i209 = 1;
      c2_b_loop_ub = c2_c_n;
      for (c2_e_j = c2_i209; c2_e_j <= c2_b_loop_ub; c2_e_j = c2_e_j + 1) {
        c2_f_j = c2_e_j;
        c2_i210 = c2_f_j;
        c2_i211 = 1;
        c2_i212 = c2_i210 - c2_i211;
        if ((c2_i210 < 0) && (c2_i211 >= 0) && (c2_i212 >= 0)) {
          c2_i212 = MIN_int32_T;
        } else {
          if ((c2_i210 >= 0) && (c2_i211 < 0) && (c2_i212 < 0)) {
            c2_i212 = MAX_int32_T;
          }
        }

        c2_i213 = c2_Boffset;
        c2_i214 = c2_mul_s32_s32_s32_sat(c2_i212, c2_c_ldb);
        c2_i215 = c2_i213 + c2_i214;
        if ((c2_i213 < 0) && (c2_i214 < 0) && (c2_i215 >= 0)) {
          c2_i215 = MIN_int32_T;
        } else {
          if ((c2_i213 > 0) && (c2_i214 > 0) && (c2_i215 <= 0)) {
            c2_i215 = MAX_int32_T;
          }
        }

        c2_jBcol = c2_i215;
        c2_i216 = 1;
        c2_c_loop_ub = c2_c_m;
        for (c2_e_i = c2_i216; c2_e_i <= c2_c_loop_ub; c2_e_i = c2_e_i + 1) {
          c2_f_i = c2_e_i;
          c2_i217 = c2_f_i;
          c2_i218 = c2_jBcol;
          c2_i219 = c2_i217 + c2_i218;
          if ((c2_i217 < 0) && (c2_i218 < 0) && (c2_i219 >= 0)) {
            c2_i219 = MIN_int32_T;
          } else {
            if ((c2_i217 > 0) && (c2_i218 > 0) && (c2_i219 <= 0)) {
              c2_i219 = MAX_int32_T;
            }
          }

          c2_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
            (real_T)c2_i219), 1, 100, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c2_i220 = 1;
      c2_d_loop_ub = c2_c_n;
      for (c2_g_j = c2_i220; c2_g_j <= c2_d_loop_ub; c2_g_j = c2_g_j + 1) {
        c2_f_j = c2_g_j;
        c2_i221 = c2_f_j;
        c2_i222 = 1;
        c2_i223 = c2_i221 - c2_i222;
        if ((c2_i221 < 0) && (c2_i222 >= 0) && (c2_i223 >= 0)) {
          c2_i223 = MIN_int32_T;
        } else {
          if ((c2_i221 >= 0) && (c2_i222 < 0) && (c2_i223 < 0)) {
            c2_i223 = MAX_int32_T;
          }
        }

        c2_i224 = c2_Boffset;
        c2_i225 = c2_mul_s32_s32_s32_sat(c2_i223, c2_c_ldb);
        c2_i226 = c2_i224 + c2_i225;
        if ((c2_i224 < 0) && (c2_i225 < 0) && (c2_i226 >= 0)) {
          c2_i226 = MIN_int32_T;
        } else {
          if ((c2_i224 > 0) && (c2_i225 > 0) && (c2_i226 <= 0)) {
            c2_i226 = MAX_int32_T;
          }
        }

        c2_jBcol = c2_i226;
        if (c2_NON_UNIT_ALPHA) {
          c2_i227 = 1;
          c2_e_loop_ub = c2_c_m;
          for (c2_g_i = c2_i227; c2_g_i <= c2_e_loop_ub; c2_g_i = c2_g_i + 1) {
            c2_f_i = c2_g_i;
            c2_i228 = c2_f_i;
            c2_i229 = c2_jBcol;
            c2_i230 = c2_i228 + c2_i229;
            if ((c2_i228 < 0) && (c2_i229 < 0) && (c2_i230 >= 0)) {
              c2_i230 = MIN_int32_T;
            } else {
              if ((c2_i228 > 0) && (c2_i229 > 0) && (c2_i230 <= 0)) {
                c2_i230 = MAX_int32_T;
              }
            }

            c2_i231 = c2_f_i;
            c2_i232 = c2_jBcol;
            c2_i233 = c2_i231 + c2_i232;
            if ((c2_i231 < 0) && (c2_i232 < 0) && (c2_i233 >= 0)) {
              c2_i233 = MIN_int32_T;
            } else {
              if ((c2_i231 > 0) && (c2_i232 > 0) && (c2_i233 <= 0)) {
                c2_i233 = MAX_int32_T;
              }
            }

            c2_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i233), 1, 100, 1, 0) - 1] = c2_c_alpha1 * c2_y[(
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i230), 1, 100, 1, 0) - 1];
          }
        }

        c2_d_m = c2_c_m;
        c2_f_loop_ub = 1.0;
        for (c2_f_k = c2_d_m; c2_f_k >= (int32_T)c2_f_loop_ub; c2_f_k = c2_f_k +
             -1) {
          c2_g_k = c2_f_k;
          c2_i234 = c2_g_k;
          c2_i235 = 1;
          c2_i236 = c2_i234 - c2_i235;
          if ((c2_i234 < 0) && (c2_i235 >= 0) && (c2_i236 >= 0)) {
            c2_i236 = MIN_int32_T;
          } else {
            if ((c2_i234 >= 0) && (c2_i235 < 0) && (c2_i236 < 0)) {
              c2_i236 = MAX_int32_T;
            }
          }

          c2_i237 = c2_Aoffset;
          c2_i238 = c2_mul_s32_s32_s32_sat(c2_i236, c2_c_lda);
          c2_i239 = c2_i237 + c2_i238;
          if ((c2_i237 < 0) && (c2_i238 < 0) && (c2_i239 >= 0)) {
            c2_i239 = MIN_int32_T;
          } else {
            if ((c2_i237 > 0) && (c2_i238 > 0) && (c2_i239 <= 0)) {
              c2_i239 = MAX_int32_T;
            }
          }

          c2_kAcol = c2_i239;
          c2_i240 = c2_g_k;
          c2_i241 = c2_jBcol;
          c2_i242 = c2_i240 + c2_i241;
          if ((c2_i240 < 0) && (c2_i241 < 0) && (c2_i242 >= 0)) {
            c2_i242 = MIN_int32_T;
          } else {
            if ((c2_i240 > 0) && (c2_i241 > 0) && (c2_i242 <= 0)) {
              c2_i242 = MAX_int32_T;
            }
          }

          if (c2_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i242), 1, 100, 1, 0) - 1] != 0.0) {
            c2_i243 = c2_g_k;
            c2_i244 = c2_jBcol;
            c2_i245 = c2_i243 + c2_i244;
            if ((c2_i243 < 0) && (c2_i244 < 0) && (c2_i245 >= 0)) {
              c2_i245 = MIN_int32_T;
            } else {
              if ((c2_i243 > 0) && (c2_i244 > 0) && (c2_i245 <= 0)) {
                c2_i245 = MAX_int32_T;
              }
            }

            c2_k_x = c2_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B",
              _SFD_INTEGER_CHECK("", (real_T)c2_i245), 1, 100, 1, 0) - 1];
            c2_i246 = c2_g_k;
            c2_i247 = c2_kAcol;
            c2_i248 = c2_i246 + c2_i247;
            if ((c2_i246 < 0) && (c2_i247 < 0) && (c2_i248 >= 0)) {
              c2_i248 = MIN_int32_T;
            } else {
              if ((c2_i246 > 0) && (c2_i247 > 0) && (c2_i248 <= 0)) {
                c2_i248 = MAX_int32_T;
              }
            }

            c2_e_y = c2_d_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
              _SFD_INTEGER_CHECK("", (real_T)c2_i248), 1, 100, 1, 0) - 1];
            c2_l_x = c2_k_x;
            c2_f_y = c2_e_y;
            c2_b_z = c2_l_x / c2_f_y;
            c2_i249 = c2_g_k;
            c2_i250 = c2_jBcol;
            c2_i251 = c2_i249 + c2_i250;
            if ((c2_i249 < 0) && (c2_i250 < 0) && (c2_i251 >= 0)) {
              c2_i251 = MIN_int32_T;
            } else {
              if ((c2_i249 > 0) && (c2_i250 > 0) && (c2_i251 <= 0)) {
                c2_i251 = MAX_int32_T;
              }
            }

            c2_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i251), 1, 100, 1, 0) - 1] = c2_b_z;
            c2_i252 = 1;
            c2_i253 = c2_g_k;
            c2_i254 = 1;
            c2_i255 = c2_i253 - c2_i254;
            if ((c2_i253 < 0) && (c2_i254 >= 0) && (c2_i255 >= 0)) {
              c2_i255 = MIN_int32_T;
            } else {
              if ((c2_i253 >= 0) && (c2_i254 < 0) && (c2_i255 < 0)) {
                c2_i255 = MAX_int32_T;
              }
            }

            c2_g_loop_ub = c2_i255;
            for (c2_h_i = c2_i252; c2_h_i <= c2_g_loop_ub; c2_h_i = c2_h_i + 1)
            {
              c2_f_i = c2_h_i;
              c2_i256 = c2_f_i;
              c2_i257 = c2_kAcol;
              c2_i258 = c2_i256 + c2_i257;
              if ((c2_i256 < 0) && (c2_i257 < 0) && (c2_i258 >= 0)) {
                c2_i258 = MIN_int32_T;
              } else {
                if ((c2_i256 > 0) && (c2_i257 > 0) && (c2_i258 <= 0)) {
                  c2_i258 = MAX_int32_T;
                }
              }

              c2_i259 = c2_g_k;
              c2_i260 = c2_jBcol;
              c2_i261 = c2_i259 + c2_i260;
              if ((c2_i259 < 0) && (c2_i260 < 0) && (c2_i261 >= 0)) {
                c2_i261 = MIN_int32_T;
              } else {
                if ((c2_i259 > 0) && (c2_i260 > 0) && (c2_i261 <= 0)) {
                  c2_i261 = MAX_int32_T;
                }
              }

              c2_i262 = c2_f_i;
              c2_i263 = c2_jBcol;
              c2_i264 = c2_i262 + c2_i263;
              if ((c2_i262 < 0) && (c2_i263 < 0) && (c2_i264 >= 0)) {
                c2_i264 = MIN_int32_T;
              } else {
                if ((c2_i262 > 0) && (c2_i263 > 0) && (c2_i264 <= 0)) {
                  c2_i264 = MAX_int32_T;
                }
              }

              c2_i265 = c2_f_i;
              c2_i266 = c2_jBcol;
              c2_i267 = c2_i265 + c2_i266;
              if ((c2_i265 < 0) && (c2_i266 < 0) && (c2_i267 >= 0)) {
                c2_i267 = MIN_int32_T;
              } else {
                if ((c2_i265 > 0) && (c2_i266 > 0) && (c2_i267 <= 0)) {
                  c2_i267 = MAX_int32_T;
                }
              }

              c2_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i267), 1, 100, 1, 0) - 1] = c2_y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i264), 1, 100, 1, 0) - 1] - c2_y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i261), 1, 100, 1, 0) - 1] * c2_d_A[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("", (real_T)
                c2_i258), 1, 100, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static int32_T c2_eml_ixamax(int32_T c2_n, real_T c2_x[100], int32_T c2_ix0,
  int32_T c2_incx)
{
  int32_T c2_idxmax;
  int32_T c2_b_n;
  int32_T c2_i268;
  int32_T c2_i269;
  real_T c2_b_x[100];
  int32_T c2_b_ix0;
  int32_T c2_b_incx;
  int32_T c2_c_n;
  int32_T c2_i270;
  int32_T c2_i271;
  real_T c2_c_x[100];
  int32_T c2_c_ix0;
  int32_T c2_c_incx;
  int32_T c2_ONE;
  int32_T c2_d_x;
  int32_T c2_ix;
  int32_T c2_e_x;
  int32_T c2_ixinc;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_y;
  real_T c2_h_x;
  real_T c2_b_y;
  real_T c2_smax;
  int32_T c2_i272;
  int32_T c2_loop_ub;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_a;
  int32_T c2_b;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_c_y;
  real_T c2_k_x;
  real_T c2_d_y;
  real_T c2_s;
  c2_b_n = c2_n;
  for (c2_i268 = 0; c2_i268 < 10; c2_i268 = c2_i268 + 1) {
    for (c2_i269 = 0; c2_i269 < 10; c2_i269 = c2_i269 + 1) {
      c2_b_x[c2_i269 + 10 * c2_i268] = c2_x[c2_i269 + 10 * c2_i268];
    }
  }

  c2_b_ix0 = c2_ix0;
  c2_b_incx = c2_incx;
  c2_c_n = c2_b_n;
  for (c2_i270 = 0; c2_i270 < 10; c2_i270 = c2_i270 + 1) {
    for (c2_i271 = 0; c2_i271 < 10; c2_i271 = c2_i271 + 1) {
      c2_c_x[c2_i271 + 10 * c2_i270] = c2_b_x[c2_i271 + 10 * c2_i270];
    }
  }

  c2_c_ix0 = c2_b_ix0;
  c2_c_incx = c2_b_incx;
  c2_ONE = 1;
  if ((real_T)c2_c_n < 1.0) {
  } else if ((real_T)c2_c_incx < 1.0) {
  } else {
    c2_idxmax = c2_ONE;
    if ((real_T)c2_c_n > 1.0) {
      c2_d_x = c2_c_ix0;
      c2_ix = c2_d_x;
      c2_e_x = c2_c_incx;
      c2_ixinc = c2_e_x;
      c2_f_x = c2_c_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("ix", (real_T)c2_ix), 1, 100, 1, 0) - 1];
      c2_g_x = 0.0;
      c2_y = fabs(c2_g_x);
      c2_h_x = c2_f_x;
      c2_b_y = fabs(c2_h_x);
      c2_smax = c2_b_y + c2_y;
      c2_i272 = 2;
      c2_loop_ub = c2_c_n;
      for (c2_k = c2_i272; c2_k <= c2_loop_ub; c2_k = c2_k + 1) {
        c2_b_k = c2_k;
        c2_a = c2_ix;
        c2_b = c2_ixinc;
        c2_ix = c2_a + c2_b;
        c2_i_x = c2_c_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
          _SFD_INTEGER_CHECK("ix", (real_T)c2_ix), 1, 100, 1, 0) - 1];
        c2_j_x = 0.0;
        c2_c_y = fabs(c2_j_x);
        c2_k_x = c2_i_x;
        c2_d_y = fabs(c2_k_x);
        c2_s = c2_d_y + c2_c_y;
        if (c2_s > c2_smax) {
          c2_idxmax = c2_b_k;
          c2_smax = c2_s;
        }
      }
    }

    return c2_idxmax;
  }

  return 0;
}

static void c2_eml_xswap(real_T c2_x[100], int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_b_x[100])
{
  int32_T c2_i273;
  int32_T c2_i274;
  int32_T c2_i275;
  int32_T c2_i276;
  real_T c2_c_x[100];
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_i277;
  int32_T c2_i278;
  real_T c2_d_x[100];
  int32_T c2_i279;
  int32_T c2_i280;
  real_T c2_e_x[100];
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_i281;
  int32_T c2_i282;
  real_T c2_f_x[100];
  int32_T c2_g_x;
  int32_T c2_ix;
  int32_T c2_h_x;
  int32_T c2_iy;
  int32_T c2_i283;
  int32_T c2_k;
  real_T c2_temp;
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_i284;
  int32_T c2_i285;
  int32_T c2_i286;
  int32_T c2_i287;
  for (c2_i273 = 0; c2_i273 < 10; c2_i273 = c2_i273 + 1) {
    for (c2_i274 = 0; c2_i274 < 10; c2_i274 = c2_i274 + 1) {
      c2_b_x[c2_i274 + 10 * c2_i273] = c2_x[c2_i274 + 10 * c2_i273];
    }
  }

  for (c2_i275 = 0; c2_i275 < 10; c2_i275 = c2_i275 + 1) {
    for (c2_i276 = 0; c2_i276 < 10; c2_i276 = c2_i276 + 1) {
      c2_c_x[c2_i276 + 10 * c2_i275] = c2_b_x[c2_i276 + 10 * c2_i275];
    }
  }

  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  for (c2_i277 = 0; c2_i277 < 10; c2_i277 = c2_i277 + 1) {
    for (c2_i278 = 0; c2_i278 < 10; c2_i278 = c2_i278 + 1) {
      c2_d_x[c2_i278 + 10 * c2_i277] = c2_c_x[c2_i278 + 10 * c2_i277];
    }
  }

  for (c2_i279 = 0; c2_i279 < 10; c2_i279 = c2_i279 + 1) {
    for (c2_i280 = 0; c2_i280 < 10; c2_i280 = c2_i280 + 1) {
      c2_e_x[c2_i280 + 10 * c2_i279] = c2_d_x[c2_i280 + 10 * c2_i279];
    }
  }

  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  for (c2_i281 = 0; c2_i281 < 10; c2_i281 = c2_i281 + 1) {
    for (c2_i282 = 0; c2_i282 < 10; c2_i282 = c2_i282 + 1) {
      c2_f_x[c2_i282 + 10 * c2_i281] = c2_e_x[c2_i282 + 10 * c2_i281];
    }
  }

  c2_g_x = c2_c_ix0;
  c2_ix = c2_g_x;
  c2_h_x = c2_c_iy0;
  c2_iy = c2_h_x;
  c2_i283 = 1;
  for (c2_k = c2_i283; c2_k < 11; c2_k = c2_k + 1) {
    c2_temp = c2_f_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
      _SFD_INTEGER_CHECK("ix", (real_T)c2_ix), 1, 100, 1, 0) - 1];
    c2_f_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("ix",
      (real_T)c2_ix), 1, 100, 1, 0) - 1] = c2_f_x[(int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("iy", (real_T)c2_iy),
      1, 100, 1, 0) - 1];
    c2_f_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("iy",
      (real_T)c2_iy), 1, 100, 1, 0) - 1] = c2_temp;
    c2_a = c2_iy;
    c2_b = 10;
    c2_iy = c2_a + c2_b;
    c2_b_a = c2_ix;
    c2_b_b = 10;
    c2_ix = c2_b_a + c2_b_b;
  }

  for (c2_i284 = 0; c2_i284 < 10; c2_i284 = c2_i284 + 1) {
    for (c2_i285 = 0; c2_i285 < 10; c2_i285 = c2_i285 + 1) {
      c2_d_x[c2_i285 + 10 * c2_i284] = c2_f_x[c2_i285 + 10 * c2_i284];
    }
  }

  for (c2_i286 = 0; c2_i286 < 10; c2_i286 = c2_i286 + 1) {
    for (c2_i287 = 0; c2_i287 < 10; c2_i287 = c2_i287 + 1) {
      c2_b_x[c2_i287 + 10 * c2_i286] = c2_d_x[c2_i287 + 10 * c2_i286];
    }
  }
}

static void c2_eml_xgeru(int32_T c2_m, int32_T c2_n, int32_T c2_ix0, int32_T
  c2_iy0, real_T c2_A[100], int32_T c2_ia0, real_T c2_b_A
  [100])
{
  int32_T c2_i288;
  int32_T c2_i289;
  int32_T c2_b_m;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_i290;
  int32_T c2_i291;
  real_T c2_c_A[100];
  int32_T c2_b_ia0;
  int32_T c2_i292;
  int32_T c2_i293;
  int32_T c2_c_m;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_i294;
  int32_T c2_i295;
  real_T c2_d_A[100];
  int32_T c2_c_ia0;
  int32_T c2_i296;
  int32_T c2_i297;
  int32_T c2_d_m;
  int32_T c2_d_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_i298;
  int32_T c2_i299;
  real_T c2_e_A[100];
  int32_T c2_d_ia0;
  int32_T c2_i300;
  int32_T c2_i301;
  int32_T c2_e_m;
  int32_T c2_e_n;
  real_T c2_alpha1;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_i302;
  int32_T c2_i303;
  real_T c2_f_A[100];
  int32_T c2_e_ia0;
  int32_T c2_i304;
  int32_T c2_i305;
  int32_T c2_x;
  int32_T c2_ixstart;
  int32_T c2_a;
  real_T c2_b;
  real_T c2_d14;
  real_T c2_d15;
  int32_T c2_i306;
  int32_T c2_jA;
  int32_T c2_b_x;
  int32_T c2_jy;
  int32_T c2_i307;
  int32_T c2_loop_ub;
  int32_T c2_j;
  real_T c2_yjy;
  real_T c2_temp;
  int32_T c2_ix;
  real_T c2_b_a;
  int32_T c2_b_b;
  real_T c2_d16;
  real_T c2_d17;
  int32_T c2_i308;
  int32_T c2_i309;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_b_loop_ub;
  int32_T c2_ijA;
  int32_T c2_b_ijA;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_f_a;
  int32_T c2_f_b;
  for (c2_i288 = 0; c2_i288 < 10; c2_i288 = c2_i288 + 1) {
    for (c2_i289 = 0; c2_i289 < 10; c2_i289 = c2_i289 + 1) {
      c2_b_A[c2_i289 + 10 * c2_i288] = c2_A[c2_i289 + 10 * c2_i288];
    }
  }

  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  for (c2_i290 = 0; c2_i290 < 10; c2_i290 = c2_i290 + 1) {
    for (c2_i291 = 0; c2_i291 < 10; c2_i291 = c2_i291 + 1) {
      c2_c_A[c2_i291 + 10 * c2_i290] = c2_b_A[c2_i291 + 10 * c2_i290];
    }
  }

  c2_b_ia0 = c2_ia0;
  for (c2_i292 = 0; c2_i292 < 10; c2_i292 = c2_i292 + 1) {
    for (c2_i293 = 0; c2_i293 < 10; c2_i293 = c2_i293 + 1) {
      c2_b_A[c2_i293 + 10 * c2_i292] = c2_c_A[c2_i293 + 10 * c2_i292];
    }
  }

  c2_c_m = c2_b_m;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  for (c2_i294 = 0; c2_i294 < 10; c2_i294 = c2_i294 + 1) {
    for (c2_i295 = 0; c2_i295 < 10; c2_i295 = c2_i295 + 1) {
      c2_d_A[c2_i295 + 10 * c2_i294] = c2_b_A[c2_i295 + 10 * c2_i294];
    }
  }

  c2_c_ia0 = c2_b_ia0;
  for (c2_i296 = 0; c2_i296 < 10; c2_i296 = c2_i296 + 1) {
    for (c2_i297 = 0; c2_i297 < 10; c2_i297 = c2_i297 + 1) {
      c2_b_A[c2_i297 + 10 * c2_i296] = c2_d_A[c2_i297 + 10 * c2_i296];
    }
  }

  c2_d_m = c2_c_m;
  c2_d_n = c2_c_n;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  for (c2_i298 = 0; c2_i298 < 10; c2_i298 = c2_i298 + 1) {
    for (c2_i299 = 0; c2_i299 < 10; c2_i299 = c2_i299 + 1) {
      c2_e_A[c2_i299 + 10 * c2_i298] = c2_b_A[c2_i299 + 10 * c2_i298];
    }
  }

  c2_d_ia0 = c2_c_ia0;
  for (c2_i300 = 0; c2_i300 < 10; c2_i300 = c2_i300 + 1) {
    for (c2_i301 = 0; c2_i301 < 10; c2_i301 = c2_i301 + 1) {
      c2_b_A[c2_i301 + 10 * c2_i300] = c2_e_A[c2_i301 + 10 * c2_i300];
    }
  }

  c2_e_m = c2_d_m;
  c2_e_n = c2_d_n;
  c2_alpha1 = -1.0;
  c2_e_ix0 = c2_d_ix0;
  c2_e_iy0 = c2_d_iy0;
  for (c2_i302 = 0; c2_i302 < 10; c2_i302 = c2_i302 + 1) {
    for (c2_i303 = 0; c2_i303 < 10; c2_i303 = c2_i303 + 1) {
      c2_f_A[c2_i303 + 10 * c2_i302] = c2_b_A[c2_i303 + 10 * c2_i302];
    }
  }

  c2_e_ia0 = c2_d_ia0;
  for (c2_i304 = 0; c2_i304 < 10; c2_i304 = c2_i304 + 1) {
    for (c2_i305 = 0; c2_i305 < 10; c2_i305 = c2_i305 + 1) {
      c2_b_A[c2_i305 + 10 * c2_i304] = c2_f_A[c2_i305 + 10 * c2_i304];
    }
  }

  if (c2_alpha1 == 0.0) {
  } else {
    c2_x = c2_e_ix0;
    c2_ixstart = c2_x;
    c2_a = c2_e_ia0;
    c2_b = 1.0;
    c2_d14 = c2_b;
    c2_d15 = c2_d14 < 0.0 ? ceil(c2_d14 - 0.5) : floor(c2_d14 + 0.5);
    if (c2_d15 < 2.147483648E+009) {
      if (c2_d15 >= -2.147483648E+009) {
        c2_i306 = (int32_T)c2_d15;
      } else {
        c2_i306 = MIN_int32_T;
      }
    } else {
      c2_i306 = MAX_int32_T;
    }

    c2_jA = c2_a - c2_i306;
    c2_b_x = c2_e_iy0;
    c2_jy = c2_b_x;
    c2_i307 = 1;
    c2_loop_ub = c2_e_n;
    for (c2_j = c2_i307; c2_j <= c2_loop_ub; c2_j = c2_j + 1) {
      c2_yjy = c2_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
        _SFD_INTEGER_CHECK("jy", (real_T)c2_jy), 1, 100, 1, 0) - 1];
      if (c2_yjy != 0.0) {
        c2_temp = c2_yjy * c2_alpha1;
        c2_ix = c2_ixstart;
        c2_b_a = 1.0;
        c2_b_b = c2_jA;
        c2_d16 = c2_b_a;
        c2_d17 = c2_d16 < 0.0 ? ceil(c2_d16 - 0.5) : floor(c2_d16 + 0.5);
        if (c2_d17 < 2.147483648E+009) {
          if (c2_d17 >= -2.147483648E+009) {
            c2_i308 = (int32_T)c2_d17;
          } else {
            c2_i308 = MIN_int32_T;
          }
        } else {
          c2_i308 = MAX_int32_T;
        }

        c2_i309 = c2_i308 + c2_b_b;
        c2_c_a = c2_e_m;
        c2_c_b = c2_jA;
        c2_b_loop_ub = c2_c_a + c2_c_b;
        for (c2_ijA = c2_i309; c2_ijA <= c2_b_loop_ub; c2_ijA = c2_ijA + 1) {
          c2_b_ijA = c2_ijA;
          c2_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK(
            "ijA", (real_T)c2_b_ijA), 1, 100, 1, 0) - 1] = c2_b_A[(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("ijA", (real_T)
            c2_b_ijA), 1, 100, 1, 0) - 1] + c2_b_A[(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("ix", (real_T)
            c2_ix), 1, 100, 1, 0) - 1] * c2_temp;
          c2_d_a = c2_ix;
          c2_d_b = 1;
          c2_ix = c2_d_a + c2_d_b;
        }
      }

      c2_e_a = c2_jy;
      c2_e_b = 10;
      c2_jy = c2_e_a + c2_e_b;
      c2_f_a = c2_jA;
      c2_f_b = 10;
      c2_jA = c2_f_a + c2_f_b;
    }
  }
}

static real_T c2_norm(real_T c2_x[100])
{
  real_T c2_y;
  int32_T c2_i310;
  int32_T c2_i311;
  real_T c2_b_x[100];
  real_T c2_ZERO;
  real_T c2_d18;
  real_T c2_j;
  real_T c2_b_j;
  real_T c2_s;
  real_T c2_d19;
  real_T c2_i;
  real_T c2_b_i;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  boolean_T c2_b;
  for (c2_i310 = 0; c2_i310 < 10; c2_i310 = c2_i310 + 1) {
    for (c2_i311 = 0; c2_i311 < 10; c2_i311 = c2_i311 + 1) {
      c2_b_x[c2_i311 + 10 * c2_i310] = c2_x[c2_i311 + 10 * c2_i310];
    }
  }

  c2_ZERO = 0.0;
  c2_y = c2_ZERO;
  c2_d18 = 1.0;
  c2_j = c2_d18;
 label_1:
  ;
  if (c2_j <= 10.0) {
    c2_b_j = c2_j;
    c2_s = c2_ZERO;
    c2_d19 = 1.0;
    for (c2_i = c2_d19; c2_i <= 10.0; c2_i = c2_i + 1.0) {
      c2_b_i = c2_i;
      c2_c_x = c2_b_x[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("i", c2_b_i), 1, 10, 1, 0) - 1) + 10 * ((
        int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("j",
        c2_b_j), 1, 10, 2, 0) - 1)];
      c2_b_y = fabs(c2_c_x);
      c2_s = c2_s + c2_b_y;
    }

    c2_d_x = c2_s;
    c2_b = rtIsNaN(c2_d_x);
    if (c2_b) {
      return rtNaN;
    } else {
      if (c2_s > c2_y) {
        c2_y = c2_s;
      }

      c2_j = c2_j + 1.0;
      goto label_1;
    }
  }

  return c2_y;
}

static void c2_eml_warning(void)
{
  int32_T c2_i312;
  static char c2_cv0[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  char c2_varargin_1[21];
  int32_T c2_i313;
  static char c2_cv1[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o',
    ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char c2_varargin_2[40];
  int32_T c2_i314;
  char c2_u[21];
  const mxArray *c2_y = NULL;
  int32_T c2_i315;
  char c2_b_u[40];
  const mxArray *c2_b_y = NULL;
  for (c2_i312 = 0; c2_i312 < 21; c2_i312 = c2_i312 + 1) {
    c2_varargin_1[c2_i312] = c2_cv0[c2_i312];
  }

  for (c2_i313 = 0; c2_i313 < 40; c2_i313 = c2_i313 + 1) {
    c2_varargin_2[c2_i313] = c2_cv1[c2_i313];
  }

  for (c2_i314 = 0; c2_i314 < 21; c2_i314 = c2_i314 + 1) {
    c2_u[c2_i314] = c2_varargin_1[c2_i314];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create(&c2_u, "y", 8, 0U, 1U, 2, 1, 21));
  for (c2_i315 = 0; c2_i315 < 40; c2_i315 = c2_i315 + 1) {
    c2_b_u[c2_i315] = c2_varargin_2[c2_i315];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 8, 0U, 1U, 2, 1, 40));
  sf_mex_call("warning", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static void c2_b_eml_warning(real_T c2_varargin_3)
{
  int32_T c2_i316;
  static char c2_cv2[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'l', 'l',
    'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', 'e', 'd',
    'M', 'a', 't', 'r', 'i', 'x' };

  char c2_varargin_1[27];
  int32_T c2_i317;
  static char c2_cv3[103] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ',', ' ', 'c'
    , 'l', 'o', 's', 'e', ' ', 't', 'o', ' ', 's', 'i', 'n', 'g', 'u', 'l', 'a',
    'r', ' ', 'o', 'r', ' ',
    'b', 'a', 'd', 'l', 'y', ' ', 's', 'c', 'a', 'l', 'e', 'd', '.', '\\', 'n',
    ' ', ' ', ' ', ' ', ' ', ' '
    , ' ', ' ', ' ', 'R', 'e', 's', 'u', 'l', 't', 's', ' ', 'm', 'a', 'y', ' ',
    'b', 'e', ' ', 'i', 'n',
    'a', 'c', 'c', 'u', 'r', 'a', 't', 'e', '.', ' ', 'R', 'C', 'O', 'N', 'D',
    ' ', '=', ' ', '%', 'e', '.'
  };

  char c2_varargin_2[103];
  int32_T c2_i318;
  char c2_u[27];
  const mxArray *c2_y = NULL;
  int32_T c2_i319;
  char c2_b_u[103];
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  for (c2_i316 = 0; c2_i316 < 27; c2_i316 = c2_i316 + 1) {
    c2_varargin_1[c2_i316] = c2_cv2[c2_i316];
  }

  for (c2_i317 = 0; c2_i317 < 103; c2_i317 = c2_i317 + 1) {
    c2_varargin_2[c2_i317] = c2_cv3[c2_i317];
  }

  for (c2_i318 = 0; c2_i318 < 27; c2_i318 = c2_i318 + 1) {
    c2_u[c2_i318] = c2_varargin_1[c2_i318];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create(&c2_u, "y", 8, 0U, 1U, 2, 1, 27));
  for (c2_i319 = 0; c2_i319 < 103; c2_i319 = c2_i319 + 1) {
    c2_b_u[c2_i319] = c2_varargin_2[c2_i319];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 8, 0U, 1U, 2, 1, 103));
  c2_c_u = c2_varargin_3;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create(&c2_c_u, "y", 0, 0U, 0U, 0));
  sf_mex_call("warning", 0U, 3U, 14, c2_y, 14, c2_b_y, 14, c2_c_y);
}

static void c2_mldivide(real_T c2_A[100], real_T c2_B[40], real_T c2_Y[40])
{
  int32_T c2_i320;
  int32_T c2_i321;
  real_T c2_b_A[100];
  int32_T c2_i322;
  int32_T c2_i323;
  real_T c2_b_B[40];
  int32_T c2_i324;
  int32_T c2_i325;
  real_T c2_c_A[100];
  int32_T c2_info;
  int32_T c2_ipiv[10];
  real_T c2_d_A[100];
  int32_T c2_i326;
  int32_T c2_i327;
  int32_T c2_i328;
  int32_T c2_b_ipiv[10];
  int32_T c2_b_info;
  real_T c2_CZERO;
  int32_T c2_i329;
  int32_T c2_i330;
  int32_T c2_i331;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_ip;
  int32_T c2_i332;
  int32_T c2_j;
  int32_T c2_b_j;
  real_T c2_temp;
  int32_T c2_m;
  int32_T c2_n;
  real_T c2_alpha1;
  int32_T c2_i333;
  int32_T c2_i334;
  real_T c2_e_A[100];
  int32_T c2_ia0;
  int32_T c2_lda;
  int32_T c2_i335;
  int32_T c2_i336;
  real_T c2_c_B[40];
  int32_T c2_ib0;
  int32_T c2_ldb;
  int32_T c2_i337;
  int32_T c2_i338;
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_i339;
  int32_T c2_i340;
  real_T c2_f_A[100];
  int32_T c2_b_ia0;
  int32_T c2_b_lda;
  int32_T c2_i341;
  int32_T c2_i342;
  real_T c2_d_B[40];
  int32_T c2_b_ib0;
  int32_T c2_b_ldb;
  int32_T c2_i343;
  int32_T c2_i344;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_c_alpha1;
  int32_T c2_i345;
  int32_T c2_i346;
  real_T c2_g_A[100];
  int32_T c2_c_ia0;
  int32_T c2_c_lda;
  int32_T c2_i347;
  int32_T c2_i348;
  real_T c2_e_B[40];
  int32_T c2_c_ib0;
  int32_T c2_c_ldb;
  int32_T c2_i349;
  int32_T c2_i350;
  boolean_T c2_NON_UNIT_ALPHA;
  int32_T c2_i351;
  int32_T c2_i352;
  int32_T c2_i353;
  int32_T c2_Aoffset;
  int32_T c2_i354;
  int32_T c2_i355;
  int32_T c2_i356;
  int32_T c2_Boffset;
  int32_T c2_i357;
  int32_T c2_loop_ub;
  int32_T c2_c_j;
  int32_T c2_d_j;
  int32_T c2_i358;
  int32_T c2_i359;
  int32_T c2_i360;
  int32_T c2_i361;
  int32_T c2_i362;
  int32_T c2_i363;
  int32_T c2_jBcol;
  int32_T c2_i364;
  int32_T c2_b_loop_ub;
  int32_T c2_c_i;
  int32_T c2_d_i;
  int32_T c2_i365;
  int32_T c2_i366;
  int32_T c2_i367;
  int32_T c2_i368;
  int32_T c2_c_loop_ub;
  int32_T c2_e_j;
  int32_T c2_i369;
  int32_T c2_i370;
  int32_T c2_i371;
  int32_T c2_i372;
  int32_T c2_i373;
  int32_T c2_i374;
  int32_T c2_i375;
  int32_T c2_d_loop_ub;
  int32_T c2_e_i;
  int32_T c2_i376;
  int32_T c2_i377;
  int32_T c2_i378;
  int32_T c2_i379;
  int32_T c2_i380;
  int32_T c2_i381;
  int32_T c2_i382;
  int32_T c2_e_loop_ub;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i383;
  int32_T c2_i384;
  int32_T c2_i385;
  int32_T c2_i386;
  int32_T c2_i387;
  int32_T c2_i388;
  int32_T c2_kAcol;
  int32_T c2_i389;
  int32_T c2_i390;
  int32_T c2_i391;
  int32_T c2_i392;
  int32_T c2_i393;
  int32_T c2_i394;
  int32_T c2_i395;
  int32_T c2_f_loop_ub;
  int32_T c2_f_i;
  int32_T c2_i396;
  int32_T c2_i397;
  int32_T c2_i398;
  int32_T c2_i399;
  int32_T c2_i400;
  int32_T c2_i401;
  int32_T c2_i402;
  int32_T c2_i403;
  int32_T c2_i404;
  int32_T c2_i405;
  int32_T c2_i406;
  int32_T c2_i407;
  int32_T c2_d_m;
  int32_T c2_d_n;
  real_T c2_d_alpha1;
  int32_T c2_i408;
  int32_T c2_i409;
  real_T c2_h_A[100];
  int32_T c2_d_ia0;
  int32_T c2_d_lda;
  int32_T c2_i410;
  int32_T c2_i411;
  real_T c2_f_B[40];
  int32_T c2_d_ib0;
  int32_T c2_d_ldb;
  int32_T c2_i412;
  int32_T c2_i413;
  int32_T c2_e_m;
  int32_T c2_e_n;
  real_T c2_e_alpha1;
  int32_T c2_i414;
  int32_T c2_i415;
  real_T c2_i_A[100];
  int32_T c2_e_ia0;
  int32_T c2_e_lda;
  int32_T c2_i416;
  int32_T c2_i417;
  real_T c2_g_B[40];
  int32_T c2_e_ib0;
  int32_T c2_e_ldb;
  int32_T c2_i418;
  int32_T c2_i419;
  int32_T c2_f_m;
  int32_T c2_f_n;
  real_T c2_f_alpha1;
  int32_T c2_i420;
  int32_T c2_i421;
  real_T c2_j_A[100];
  int32_T c2_f_ia0;
  int32_T c2_f_lda;
  int32_T c2_i422;
  int32_T c2_i423;
  real_T c2_h_B[40];
  int32_T c2_f_ib0;
  int32_T c2_f_ldb;
  int32_T c2_i424;
  int32_T c2_i425;
  boolean_T c2_b_NON_UNIT_ALPHA;
  int32_T c2_i426;
  int32_T c2_i427;
  int32_T c2_i428;
  int32_T c2_b_Aoffset;
  int32_T c2_i429;
  int32_T c2_i430;
  int32_T c2_i431;
  int32_T c2_b_Boffset;
  int32_T c2_i432;
  int32_T c2_g_loop_ub;
  int32_T c2_f_j;
  int32_T c2_g_j;
  int32_T c2_i433;
  int32_T c2_i434;
  int32_T c2_i435;
  int32_T c2_i436;
  int32_T c2_i437;
  int32_T c2_i438;
  int32_T c2_b_jBcol;
  int32_T c2_i439;
  int32_T c2_h_loop_ub;
  int32_T c2_g_i;
  int32_T c2_h_i;
  int32_T c2_i440;
  int32_T c2_i441;
  int32_T c2_i442;
  int32_T c2_i443;
  int32_T c2_i_loop_ub;
  int32_T c2_h_j;
  int32_T c2_i444;
  int32_T c2_i445;
  int32_T c2_i446;
  int32_T c2_i447;
  int32_T c2_i448;
  int32_T c2_i449;
  int32_T c2_i450;
  int32_T c2_j_loop_ub;
  int32_T c2_i_i;
  int32_T c2_i451;
  int32_T c2_i452;
  int32_T c2_i453;
  int32_T c2_i454;
  int32_T c2_i455;
  int32_T c2_i456;
  int32_T c2_g_m;
  real_T c2_k_loop_ub;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_i457;
  int32_T c2_i458;
  int32_T c2_i459;
  int32_T c2_i460;
  int32_T c2_i461;
  int32_T c2_i462;
  int32_T c2_b_kAcol;
  int32_T c2_i463;
  int32_T c2_i464;
  int32_T c2_i465;
  int32_T c2_i466;
  int32_T c2_i467;
  int32_T c2_i468;
  real_T c2_x;
  int32_T c2_i469;
  int32_T c2_i470;
  int32_T c2_i471;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_z;
  int32_T c2_i472;
  int32_T c2_i473;
  int32_T c2_i474;
  int32_T c2_i475;
  int32_T c2_i476;
  int32_T c2_i477;
  int32_T c2_i478;
  int32_T c2_l_loop_ub;
  int32_T c2_j_i;
  int32_T c2_i479;
  int32_T c2_i480;
  int32_T c2_i481;
  int32_T c2_i482;
  int32_T c2_i483;
  int32_T c2_i484;
  int32_T c2_i485;
  int32_T c2_i486;
  int32_T c2_i487;
  int32_T c2_i488;
  int32_T c2_i489;
  int32_T c2_i490;
  for (c2_i320 = 0; c2_i320 < 10; c2_i320 = c2_i320 + 1) {
    for (c2_i321 = 0; c2_i321 < 10; c2_i321 = c2_i321 + 1) {
      c2_b_A[c2_i321 + 10 * c2_i320] = c2_A[c2_i321 + 10 * c2_i320];
    }
  }

  for (c2_i322 = 0; c2_i322 < 4; c2_i322 = c2_i322 + 1) {
    for (c2_i323 = 0; c2_i323 < 10; c2_i323 = c2_i323 + 1) {
      c2_b_B[c2_i323 + 10 * c2_i322] = c2_B[c2_i323 + 10 * c2_i322];
    }
  }

  for (c2_i324 = 0; c2_i324 < 10; c2_i324 = c2_i324 + 1) {
    for (c2_i325 = 0; c2_i325 < 10; c2_i325 = c2_i325 + 1) {
      c2_c_A[c2_i325 + 10 * c2_i324] = c2_b_A[c2_i325 + 10 * c2_i324];
    }
  }

  c2_eml_xgetrf(c2_c_A, c2_d_A, c2_ipiv, &c2_info);
  for (c2_i326 = 0; c2_i326 < 10; c2_i326 = c2_i326 + 1) {
    for (c2_i327 = 0; c2_i327 < 10; c2_i327 = c2_i327 + 1) {
      c2_b_A[c2_i327 + 10 * c2_i326] = c2_d_A[c2_i327 + 10 * c2_i326];
    }
  }

  for (c2_i328 = 0; c2_i328 < 10; c2_i328 = c2_i328 + 1) {
    c2_b_ipiv[c2_i328] = c2_ipiv[c2_i328];
  }

  c2_b_info = c2_info;
  if ((real_T)c2_b_info > 0.0) {
    c2_eml_warning();
  }

  c2_CZERO = 0.0;
  for (c2_i329 = 0; c2_i329 < 4; c2_i329 = c2_i329 + 1) {
    for (c2_i330 = 0; c2_i330 < 10; c2_i330 = c2_i330 + 1) {
      c2_Y[c2_i330 + 10 * c2_i329] = c2_b_B[c2_i330 + 10 * c2_i329] + c2_CZERO;
    }
  }

  c2_i331 = 1;
  for (c2_i = c2_i331; c2_i < 11; c2_i = c2_i + 1) {
    c2_b_i = c2_i;
    if (c2_b_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv",
         _SFD_INTEGER_CHECK("i", (real_T)c2_b_i), 1, 10, 1, 0) - 1] != c2_b_i) {
      c2_ip = c2_b_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv",
        _SFD_INTEGER_CHECK("i", (real_T)c2_b_i), 1, 10, 1, 0) - 1];
      c2_i332 = 1;
      for (c2_j = c2_i332; c2_j < 5; c2_j = c2_j + 1) {
        c2_b_j = c2_j;
        c2_temp = c2_Y[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X",
          _SFD_INTEGER_CHECK("i", (real_T)c2_b_i), 1, 10, 1, 0) - 1) + 10 * ((
          int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("j",
          (real_T)c2_b_j), 1, 4, 2, 0) - 1)];
        c2_Y[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("i",
                (real_T)c2_b_i), 1, 10, 1, 0) - 1) + 10 * ((int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("j", (real_T)
          c2_b_j), 1, 4, 2, 0) - 1)] = c2_Y[((int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("ip", (real_T)
          c2_ip), 1, 10, 1, 0) - 1) + 10 * ((int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("j", (real_T)
          c2_b_j), 1, 4, 2, 0) - 1)];
        c2_Y[((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("ip",
                (real_T)c2_ip), 1, 10, 1, 0) - 1) + 10 * ((int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("j", (real_T)
          c2_b_j), 1, 4, 2, 0) - 1)] = c2_temp;
      }
    }
  }

  c2_m = 10;
  c2_n = 4;
  c2_alpha1 = 1.0;
  for (c2_i333 = 0; c2_i333 < 10; c2_i333 = c2_i333 + 1) {
    for (c2_i334 = 0; c2_i334 < 10; c2_i334 = c2_i334 + 1) {
      c2_e_A[c2_i334 + 10 * c2_i333] = c2_b_A[c2_i334 + 10 * c2_i333];
    }
  }

  c2_ia0 = 1;
  c2_lda = 10;
  for (c2_i335 = 0; c2_i335 < 4; c2_i335 = c2_i335 + 1) {
    for (c2_i336 = 0; c2_i336 < 10; c2_i336 = c2_i336 + 1) {
      c2_c_B[c2_i336 + 10 * c2_i335] = c2_Y[c2_i336 + 10 * c2_i335];
    }
  }

  c2_ib0 = 1;
  c2_ldb = 10;
  for (c2_i337 = 0; c2_i337 < 4; c2_i337 = c2_i337 + 1) {
    for (c2_i338 = 0; c2_i338 < 10; c2_i338 = c2_i338 + 1) {
      c2_Y[c2_i338 + 10 * c2_i337] = c2_c_B[c2_i338 + 10 * c2_i337];
    }
  }

  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  for (c2_i339 = 0; c2_i339 < 10; c2_i339 = c2_i339 + 1) {
    for (c2_i340 = 0; c2_i340 < 10; c2_i340 = c2_i340 + 1) {
      c2_f_A[c2_i340 + 10 * c2_i339] = c2_e_A[c2_i340 + 10 * c2_i339];
    }
  }

  c2_b_ia0 = c2_ia0;
  c2_b_lda = c2_lda;
  for (c2_i341 = 0; c2_i341 < 4; c2_i341 = c2_i341 + 1) {
    for (c2_i342 = 0; c2_i342 < 10; c2_i342 = c2_i342 + 1) {
      c2_d_B[c2_i342 + 10 * c2_i341] = c2_Y[c2_i342 + 10 * c2_i341];
    }
  }

  c2_b_ib0 = c2_ib0;
  c2_b_ldb = c2_ldb;
  for (c2_i343 = 0; c2_i343 < 4; c2_i343 = c2_i343 + 1) {
    for (c2_i344 = 0; c2_i344 < 10; c2_i344 = c2_i344 + 1) {
      c2_Y[c2_i344 + 10 * c2_i343] = c2_d_B[c2_i344 + 10 * c2_i343];
    }
  }

  c2_c_m = c2_b_m;
  c2_c_n = c2_b_n;
  c2_c_alpha1 = c2_b_alpha1;
  for (c2_i345 = 0; c2_i345 < 10; c2_i345 = c2_i345 + 1) {
    for (c2_i346 = 0; c2_i346 < 10; c2_i346 = c2_i346 + 1) {
      c2_g_A[c2_i346 + 10 * c2_i345] = c2_f_A[c2_i346 + 10 * c2_i345];
    }
  }

  c2_c_ia0 = c2_b_ia0;
  c2_c_lda = c2_b_lda;
  for (c2_i347 = 0; c2_i347 < 4; c2_i347 = c2_i347 + 1) {
    for (c2_i348 = 0; c2_i348 < 10; c2_i348 = c2_i348 + 1) {
      c2_e_B[c2_i348 + 10 * c2_i347] = c2_Y[c2_i348 + 10 * c2_i347];
    }
  }

  c2_c_ib0 = c2_b_ib0;
  c2_c_ldb = c2_b_ldb;
  for (c2_i349 = 0; c2_i349 < 4; c2_i349 = c2_i349 + 1) {
    for (c2_i350 = 0; c2_i350 < 10; c2_i350 = c2_i350 + 1) {
      c2_Y[c2_i350 + 10 * c2_i349] = c2_e_B[c2_i350 + 10 * c2_i349];
    }
  }

  c2_NON_UNIT_ALPHA = (c2_c_alpha1 != 1.0);
  if ((real_T)c2_c_n == 0.0) {
  } else {
    c2_i351 = c2_c_ia0;
    c2_i352 = 1;
    c2_i353 = c2_i351 - c2_i352;
    if ((c2_i351 < 0) && (c2_i352 >= 0) && (c2_i353 >= 0)) {
      c2_i353 = MIN_int32_T;
    } else {
      if ((c2_i351 >= 0) && (c2_i352 < 0) && (c2_i353 < 0)) {
        c2_i353 = MAX_int32_T;
      }
    }

    c2_Aoffset = c2_i353;
    c2_i354 = c2_c_ib0;
    c2_i355 = 1;
    c2_i356 = c2_i354 - c2_i355;
    if ((c2_i354 < 0) && (c2_i355 >= 0) && (c2_i356 >= 0)) {
      c2_i356 = MIN_int32_T;
    } else {
      if ((c2_i354 >= 0) && (c2_i355 < 0) && (c2_i356 < 0)) {
        c2_i356 = MAX_int32_T;
      }
    }

    c2_Boffset = c2_i356;
    if (c2_c_alpha1 == 0.0) {
      c2_i357 = 1;
      c2_loop_ub = c2_c_n;
      for (c2_c_j = c2_i357; c2_c_j <= c2_loop_ub; c2_c_j = c2_c_j + 1) {
        c2_d_j = c2_c_j;
        c2_i358 = c2_d_j;
        c2_i359 = 1;
        c2_i360 = c2_i358 - c2_i359;
        if ((c2_i358 < 0) && (c2_i359 >= 0) && (c2_i360 >= 0)) {
          c2_i360 = MIN_int32_T;
        } else {
          if ((c2_i358 >= 0) && (c2_i359 < 0) && (c2_i360 < 0)) {
            c2_i360 = MAX_int32_T;
          }
        }

        c2_i361 = c2_Boffset;
        c2_i362 = c2_mul_s32_s32_s32_sat(c2_i360, c2_c_ldb);
        c2_i363 = c2_i361 + c2_i362;
        if ((c2_i361 < 0) && (c2_i362 < 0) && (c2_i363 >= 0)) {
          c2_i363 = MIN_int32_T;
        } else {
          if ((c2_i361 > 0) && (c2_i362 > 0) && (c2_i363 <= 0)) {
            c2_i363 = MAX_int32_T;
          }
        }

        c2_jBcol = c2_i363;
        c2_i364 = 1;
        c2_b_loop_ub = c2_c_m;
        for (c2_c_i = c2_i364; c2_c_i <= c2_b_loop_ub; c2_c_i = c2_c_i + 1) {
          c2_d_i = c2_c_i;
          c2_i365 = c2_d_i;
          c2_i366 = c2_jBcol;
          c2_i367 = c2_i365 + c2_i366;
          if ((c2_i365 < 0) && (c2_i366 < 0) && (c2_i367 >= 0)) {
            c2_i367 = MIN_int32_T;
          } else {
            if ((c2_i365 > 0) && (c2_i366 > 0) && (c2_i367 <= 0)) {
              c2_i367 = MAX_int32_T;
            }
          }

          c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
            (real_T)c2_i367), 1, 40, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c2_i368 = 1;
      c2_c_loop_ub = c2_c_n;
      for (c2_e_j = c2_i368; c2_e_j <= c2_c_loop_ub; c2_e_j = c2_e_j + 1) {
        c2_d_j = c2_e_j;
        c2_i369 = c2_d_j;
        c2_i370 = 1;
        c2_i371 = c2_i369 - c2_i370;
        if ((c2_i369 < 0) && (c2_i370 >= 0) && (c2_i371 >= 0)) {
          c2_i371 = MIN_int32_T;
        } else {
          if ((c2_i369 >= 0) && (c2_i370 < 0) && (c2_i371 < 0)) {
            c2_i371 = MAX_int32_T;
          }
        }

        c2_i372 = c2_Boffset;
        c2_i373 = c2_mul_s32_s32_s32_sat(c2_i371, c2_c_ldb);
        c2_i374 = c2_i372 + c2_i373;
        if ((c2_i372 < 0) && (c2_i373 < 0) && (c2_i374 >= 0)) {
          c2_i374 = MIN_int32_T;
        } else {
          if ((c2_i372 > 0) && (c2_i373 > 0) && (c2_i374 <= 0)) {
            c2_i374 = MAX_int32_T;
          }
        }

        c2_jBcol = c2_i374;
        if (c2_NON_UNIT_ALPHA) {
          c2_i375 = 1;
          c2_d_loop_ub = c2_c_m;
          for (c2_e_i = c2_i375; c2_e_i <= c2_d_loop_ub; c2_e_i = c2_e_i + 1) {
            c2_d_i = c2_e_i;
            c2_i376 = c2_d_i;
            c2_i377 = c2_jBcol;
            c2_i378 = c2_i376 + c2_i377;
            if ((c2_i376 < 0) && (c2_i377 < 0) && (c2_i378 >= 0)) {
              c2_i378 = MIN_int32_T;
            } else {
              if ((c2_i376 > 0) && (c2_i377 > 0) && (c2_i378 <= 0)) {
                c2_i378 = MAX_int32_T;
              }
            }

            c2_i379 = c2_d_i;
            c2_i380 = c2_jBcol;
            c2_i381 = c2_i379 + c2_i380;
            if ((c2_i379 < 0) && (c2_i380 < 0) && (c2_i381 >= 0)) {
              c2_i381 = MIN_int32_T;
            } else {
              if ((c2_i379 > 0) && (c2_i380 > 0) && (c2_i381 <= 0)) {
                c2_i381 = MAX_int32_T;
              }
            }

            c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i381), 1, 40, 1, 0) - 1] = c2_c_alpha1 * c2_Y[(
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i378), 1, 40, 1, 0) - 1];
          }
        }

        c2_i382 = 1;
        c2_e_loop_ub = c2_c_m;
        for (c2_k = c2_i382; c2_k <= c2_e_loop_ub; c2_k = c2_k + 1) {
          c2_b_k = c2_k;
          c2_i383 = c2_b_k;
          c2_i384 = 1;
          c2_i385 = c2_i383 - c2_i384;
          if ((c2_i383 < 0) && (c2_i384 >= 0) && (c2_i385 >= 0)) {
            c2_i385 = MIN_int32_T;
          } else {
            if ((c2_i383 >= 0) && (c2_i384 < 0) && (c2_i385 < 0)) {
              c2_i385 = MAX_int32_T;
            }
          }

          c2_i386 = c2_Aoffset;
          c2_i387 = c2_mul_s32_s32_s32_sat(c2_i385, c2_c_lda);
          c2_i388 = c2_i386 + c2_i387;
          if ((c2_i386 < 0) && (c2_i387 < 0) && (c2_i388 >= 0)) {
            c2_i388 = MIN_int32_T;
          } else {
            if ((c2_i386 > 0) && (c2_i387 > 0) && (c2_i388 <= 0)) {
              c2_i388 = MAX_int32_T;
            }
          }

          c2_kAcol = c2_i388;
          c2_i389 = c2_b_k;
          c2_i390 = c2_jBcol;
          c2_i391 = c2_i389 + c2_i390;
          if ((c2_i389 < 0) && (c2_i390 < 0) && (c2_i391 >= 0)) {
            c2_i391 = MIN_int32_T;
          } else {
            if ((c2_i389 > 0) && (c2_i390 > 0) && (c2_i391 <= 0)) {
              c2_i391 = MAX_int32_T;
            }
          }

          if (c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i391), 1, 40, 1, 0) - 1] != 0.0) {
            c2_i392 = c2_b_k;
            c2_i393 = 1;
            c2_i394 = c2_i392 + c2_i393;
            if ((c2_i392 < 0) && (c2_i393 < 0) && (c2_i394 >= 0)) {
              c2_i394 = MIN_int32_T;
            } else {
              if ((c2_i392 > 0) && (c2_i393 > 0) && (c2_i394 <= 0)) {
                c2_i394 = MAX_int32_T;
              }
            }

            c2_i395 = c2_i394;
            c2_f_loop_ub = c2_c_m;
            for (c2_f_i = c2_i395; c2_f_i <= c2_f_loop_ub; c2_f_i = c2_f_i + 1)
            {
              c2_d_i = c2_f_i;
              c2_i396 = c2_d_i;
              c2_i397 = c2_kAcol;
              c2_i398 = c2_i396 + c2_i397;
              if ((c2_i396 < 0) && (c2_i397 < 0) && (c2_i398 >= 0)) {
                c2_i398 = MIN_int32_T;
              } else {
                if ((c2_i396 > 0) && (c2_i397 > 0) && (c2_i398 <= 0)) {
                  c2_i398 = MAX_int32_T;
                }
              }

              c2_i399 = c2_b_k;
              c2_i400 = c2_jBcol;
              c2_i401 = c2_i399 + c2_i400;
              if ((c2_i399 < 0) && (c2_i400 < 0) && (c2_i401 >= 0)) {
                c2_i401 = MIN_int32_T;
              } else {
                if ((c2_i399 > 0) && (c2_i400 > 0) && (c2_i401 <= 0)) {
                  c2_i401 = MAX_int32_T;
                }
              }

              c2_i402 = c2_d_i;
              c2_i403 = c2_jBcol;
              c2_i404 = c2_i402 + c2_i403;
              if ((c2_i402 < 0) && (c2_i403 < 0) && (c2_i404 >= 0)) {
                c2_i404 = MIN_int32_T;
              } else {
                if ((c2_i402 > 0) && (c2_i403 > 0) && (c2_i404 <= 0)) {
                  c2_i404 = MAX_int32_T;
                }
              }

              c2_i405 = c2_d_i;
              c2_i406 = c2_jBcol;
              c2_i407 = c2_i405 + c2_i406;
              if ((c2_i405 < 0) && (c2_i406 < 0) && (c2_i407 >= 0)) {
                c2_i407 = MIN_int32_T;
              } else {
                if ((c2_i405 > 0) && (c2_i406 > 0) && (c2_i407 <= 0)) {
                  c2_i407 = MAX_int32_T;
                }
              }

              c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i407), 1, 40, 1, 0) - 1] = c2_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i404), 1, 40, 1, 0) - 1] - c2_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i401), 1, 40, 1, 0) - 1] * c2_g_A[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("", (real_T)
                c2_i398), 1, 100, 1, 0) - 1];
            }
          }
        }
      }
    }
  }

  c2_d_m = 10;
  c2_d_n = 4;
  c2_d_alpha1 = 1.0;
  for (c2_i408 = 0; c2_i408 < 10; c2_i408 = c2_i408 + 1) {
    for (c2_i409 = 0; c2_i409 < 10; c2_i409 = c2_i409 + 1) {
      c2_h_A[c2_i409 + 10 * c2_i408] = c2_b_A[c2_i409 + 10 * c2_i408];
    }
  }

  c2_d_ia0 = 1;
  c2_d_lda = 10;
  for (c2_i410 = 0; c2_i410 < 4; c2_i410 = c2_i410 + 1) {
    for (c2_i411 = 0; c2_i411 < 10; c2_i411 = c2_i411 + 1) {
      c2_f_B[c2_i411 + 10 * c2_i410] = c2_Y[c2_i411 + 10 * c2_i410];
    }
  }

  c2_d_ib0 = 1;
  c2_d_ldb = 10;
  for (c2_i412 = 0; c2_i412 < 4; c2_i412 = c2_i412 + 1) {
    for (c2_i413 = 0; c2_i413 < 10; c2_i413 = c2_i413 + 1) {
      c2_Y[c2_i413 + 10 * c2_i412] = c2_f_B[c2_i413 + 10 * c2_i412];
    }
  }

  c2_e_m = c2_d_m;
  c2_e_n = c2_d_n;
  c2_e_alpha1 = c2_d_alpha1;
  for (c2_i414 = 0; c2_i414 < 10; c2_i414 = c2_i414 + 1) {
    for (c2_i415 = 0; c2_i415 < 10; c2_i415 = c2_i415 + 1) {
      c2_i_A[c2_i415 + 10 * c2_i414] = c2_h_A[c2_i415 + 10 * c2_i414];
    }
  }

  c2_e_ia0 = c2_d_ia0;
  c2_e_lda = c2_d_lda;
  for (c2_i416 = 0; c2_i416 < 4; c2_i416 = c2_i416 + 1) {
    for (c2_i417 = 0; c2_i417 < 10; c2_i417 = c2_i417 + 1) {
      c2_g_B[c2_i417 + 10 * c2_i416] = c2_Y[c2_i417 + 10 * c2_i416];
    }
  }

  c2_e_ib0 = c2_d_ib0;
  c2_e_ldb = c2_d_ldb;
  for (c2_i418 = 0; c2_i418 < 4; c2_i418 = c2_i418 + 1) {
    for (c2_i419 = 0; c2_i419 < 10; c2_i419 = c2_i419 + 1) {
      c2_Y[c2_i419 + 10 * c2_i418] = c2_g_B[c2_i419 + 10 * c2_i418];
    }
  }

  c2_f_m = c2_e_m;
  c2_f_n = c2_e_n;
  c2_f_alpha1 = c2_e_alpha1;
  for (c2_i420 = 0; c2_i420 < 10; c2_i420 = c2_i420 + 1) {
    for (c2_i421 = 0; c2_i421 < 10; c2_i421 = c2_i421 + 1) {
      c2_j_A[c2_i421 + 10 * c2_i420] = c2_i_A[c2_i421 + 10 * c2_i420];
    }
  }

  c2_f_ia0 = c2_e_ia0;
  c2_f_lda = c2_e_lda;
  for (c2_i422 = 0; c2_i422 < 4; c2_i422 = c2_i422 + 1) {
    for (c2_i423 = 0; c2_i423 < 10; c2_i423 = c2_i423 + 1) {
      c2_h_B[c2_i423 + 10 * c2_i422] = c2_Y[c2_i423 + 10 * c2_i422];
    }
  }

  c2_f_ib0 = c2_e_ib0;
  c2_f_ldb = c2_e_ldb;
  for (c2_i424 = 0; c2_i424 < 4; c2_i424 = c2_i424 + 1) {
    for (c2_i425 = 0; c2_i425 < 10; c2_i425 = c2_i425 + 1) {
      c2_Y[c2_i425 + 10 * c2_i424] = c2_h_B[c2_i425 + 10 * c2_i424];
    }
  }

  c2_b_NON_UNIT_ALPHA = (c2_f_alpha1 != 1.0);
  if ((real_T)c2_f_n == 0.0) {
  } else {
    c2_i426 = c2_f_ia0;
    c2_i427 = 1;
    c2_i428 = c2_i426 - c2_i427;
    if ((c2_i426 < 0) && (c2_i427 >= 0) && (c2_i428 >= 0)) {
      c2_i428 = MIN_int32_T;
    } else {
      if ((c2_i426 >= 0) && (c2_i427 < 0) && (c2_i428 < 0)) {
        c2_i428 = MAX_int32_T;
      }
    }

    c2_b_Aoffset = c2_i428;
    c2_i429 = c2_f_ib0;
    c2_i430 = 1;
    c2_i431 = c2_i429 - c2_i430;
    if ((c2_i429 < 0) && (c2_i430 >= 0) && (c2_i431 >= 0)) {
      c2_i431 = MIN_int32_T;
    } else {
      if ((c2_i429 >= 0) && (c2_i430 < 0) && (c2_i431 < 0)) {
        c2_i431 = MAX_int32_T;
      }
    }

    c2_b_Boffset = c2_i431;
    if (c2_f_alpha1 == 0.0) {
      c2_i432 = 1;
      c2_g_loop_ub = c2_f_n;
      for (c2_f_j = c2_i432; c2_f_j <= c2_g_loop_ub; c2_f_j = c2_f_j + 1) {
        c2_g_j = c2_f_j;
        c2_i433 = c2_g_j;
        c2_i434 = 1;
        c2_i435 = c2_i433 - c2_i434;
        if ((c2_i433 < 0) && (c2_i434 >= 0) && (c2_i435 >= 0)) {
          c2_i435 = MIN_int32_T;
        } else {
          if ((c2_i433 >= 0) && (c2_i434 < 0) && (c2_i435 < 0)) {
            c2_i435 = MAX_int32_T;
          }
        }

        c2_i436 = c2_b_Boffset;
        c2_i437 = c2_mul_s32_s32_s32_sat(c2_i435, c2_f_ldb);
        c2_i438 = c2_i436 + c2_i437;
        if ((c2_i436 < 0) && (c2_i437 < 0) && (c2_i438 >= 0)) {
          c2_i438 = MIN_int32_T;
        } else {
          if ((c2_i436 > 0) && (c2_i437 > 0) && (c2_i438 <= 0)) {
            c2_i438 = MAX_int32_T;
          }
        }

        c2_b_jBcol = c2_i438;
        c2_i439 = 1;
        c2_h_loop_ub = c2_f_m;
        for (c2_g_i = c2_i439; c2_g_i <= c2_h_loop_ub; c2_g_i = c2_g_i + 1) {
          c2_h_i = c2_g_i;
          c2_i440 = c2_h_i;
          c2_i441 = c2_b_jBcol;
          c2_i442 = c2_i440 + c2_i441;
          if ((c2_i440 < 0) && (c2_i441 < 0) && (c2_i442 >= 0)) {
            c2_i442 = MIN_int32_T;
          } else {
            if ((c2_i440 > 0) && (c2_i441 > 0) && (c2_i442 <= 0)) {
              c2_i442 = MAX_int32_T;
            }
          }

          c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
            (real_T)c2_i442), 1, 40, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c2_i443 = 1;
      c2_i_loop_ub = c2_f_n;
      for (c2_h_j = c2_i443; c2_h_j <= c2_i_loop_ub; c2_h_j = c2_h_j + 1) {
        c2_g_j = c2_h_j;
        c2_i444 = c2_g_j;
        c2_i445 = 1;
        c2_i446 = c2_i444 - c2_i445;
        if ((c2_i444 < 0) && (c2_i445 >= 0) && (c2_i446 >= 0)) {
          c2_i446 = MIN_int32_T;
        } else {
          if ((c2_i444 >= 0) && (c2_i445 < 0) && (c2_i446 < 0)) {
            c2_i446 = MAX_int32_T;
          }
        }

        c2_i447 = c2_b_Boffset;
        c2_i448 = c2_mul_s32_s32_s32_sat(c2_i446, c2_f_ldb);
        c2_i449 = c2_i447 + c2_i448;
        if ((c2_i447 < 0) && (c2_i448 < 0) && (c2_i449 >= 0)) {
          c2_i449 = MIN_int32_T;
        } else {
          if ((c2_i447 > 0) && (c2_i448 > 0) && (c2_i449 <= 0)) {
            c2_i449 = MAX_int32_T;
          }
        }

        c2_b_jBcol = c2_i449;
        if (c2_b_NON_UNIT_ALPHA) {
          c2_i450 = 1;
          c2_j_loop_ub = c2_f_m;
          for (c2_i_i = c2_i450; c2_i_i <= c2_j_loop_ub; c2_i_i = c2_i_i + 1) {
            c2_h_i = c2_i_i;
            c2_i451 = c2_h_i;
            c2_i452 = c2_b_jBcol;
            c2_i453 = c2_i451 + c2_i452;
            if ((c2_i451 < 0) && (c2_i452 < 0) && (c2_i453 >= 0)) {
              c2_i453 = MIN_int32_T;
            } else {
              if ((c2_i451 > 0) && (c2_i452 > 0) && (c2_i453 <= 0)) {
                c2_i453 = MAX_int32_T;
              }
            }

            c2_i454 = c2_h_i;
            c2_i455 = c2_b_jBcol;
            c2_i456 = c2_i454 + c2_i455;
            if ((c2_i454 < 0) && (c2_i455 < 0) && (c2_i456 >= 0)) {
              c2_i456 = MIN_int32_T;
            } else {
              if ((c2_i454 > 0) && (c2_i455 > 0) && (c2_i456 <= 0)) {
                c2_i456 = MAX_int32_T;
              }
            }

            c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i456), 1, 40, 1, 0) - 1] = c2_f_alpha1 * c2_Y[(
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i453), 1, 40, 1, 0) - 1];
          }
        }

        c2_g_m = c2_f_m;
        c2_k_loop_ub = 1.0;
        for (c2_c_k = c2_g_m; c2_c_k >= (int32_T)c2_k_loop_ub; c2_c_k = c2_c_k +
             -1) {
          c2_d_k = c2_c_k;
          c2_i457 = c2_d_k;
          c2_i458 = 1;
          c2_i459 = c2_i457 - c2_i458;
          if ((c2_i457 < 0) && (c2_i458 >= 0) && (c2_i459 >= 0)) {
            c2_i459 = MIN_int32_T;
          } else {
            if ((c2_i457 >= 0) && (c2_i458 < 0) && (c2_i459 < 0)) {
              c2_i459 = MAX_int32_T;
            }
          }

          c2_i460 = c2_b_Aoffset;
          c2_i461 = c2_mul_s32_s32_s32_sat(c2_i459, c2_f_lda);
          c2_i462 = c2_i460 + c2_i461;
          if ((c2_i460 < 0) && (c2_i461 < 0) && (c2_i462 >= 0)) {
            c2_i462 = MIN_int32_T;
          } else {
            if ((c2_i460 > 0) && (c2_i461 > 0) && (c2_i462 <= 0)) {
              c2_i462 = MAX_int32_T;
            }
          }

          c2_b_kAcol = c2_i462;
          c2_i463 = c2_d_k;
          c2_i464 = c2_b_jBcol;
          c2_i465 = c2_i463 + c2_i464;
          if ((c2_i463 < 0) && (c2_i464 < 0) && (c2_i465 >= 0)) {
            c2_i465 = MIN_int32_T;
          } else {
            if ((c2_i463 > 0) && (c2_i464 > 0) && (c2_i465 <= 0)) {
              c2_i465 = MAX_int32_T;
            }
          }

          if (c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i465), 1, 40, 1, 0) - 1] != 0.0) {
            c2_i466 = c2_d_k;
            c2_i467 = c2_b_jBcol;
            c2_i468 = c2_i466 + c2_i467;
            if ((c2_i466 < 0) && (c2_i467 < 0) && (c2_i468 >= 0)) {
              c2_i468 = MIN_int32_T;
            } else {
              if ((c2_i466 > 0) && (c2_i467 > 0) && (c2_i468 <= 0)) {
                c2_i468 = MAX_int32_T;
              }
            }

            c2_x = c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B",
              _SFD_INTEGER_CHECK("", (real_T)c2_i468), 1, 40, 1, 0) - 1];
            c2_i469 = c2_d_k;
            c2_i470 = c2_b_kAcol;
            c2_i471 = c2_i469 + c2_i470;
            if ((c2_i469 < 0) && (c2_i470 < 0) && (c2_i471 >= 0)) {
              c2_i471 = MIN_int32_T;
            } else {
              if ((c2_i469 > 0) && (c2_i470 > 0) && (c2_i471 <= 0)) {
                c2_i471 = MAX_int32_T;
              }
            }

            c2_y = c2_j_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
              _SFD_INTEGER_CHECK("", (real_T)c2_i471), 1, 100, 1, 0) - 1];
            c2_b_x = c2_x;
            c2_b_y = c2_y;
            c2_z = c2_b_x / c2_b_y;
            c2_i472 = c2_d_k;
            c2_i473 = c2_b_jBcol;
            c2_i474 = c2_i472 + c2_i473;
            if ((c2_i472 < 0) && (c2_i473 < 0) && (c2_i474 >= 0)) {
              c2_i474 = MIN_int32_T;
            } else {
              if ((c2_i472 > 0) && (c2_i473 > 0) && (c2_i474 <= 0)) {
                c2_i474 = MAX_int32_T;
              }
            }

            c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i474), 1, 40, 1, 0) - 1] = c2_z;
            c2_i475 = 1;
            c2_i476 = c2_d_k;
            c2_i477 = 1;
            c2_i478 = c2_i476 - c2_i477;
            if ((c2_i476 < 0) && (c2_i477 >= 0) && (c2_i478 >= 0)) {
              c2_i478 = MIN_int32_T;
            } else {
              if ((c2_i476 >= 0) && (c2_i477 < 0) && (c2_i478 < 0)) {
                c2_i478 = MAX_int32_T;
              }
            }

            c2_l_loop_ub = c2_i478;
            for (c2_j_i = c2_i475; c2_j_i <= c2_l_loop_ub; c2_j_i = c2_j_i + 1)
            {
              c2_h_i = c2_j_i;
              c2_i479 = c2_h_i;
              c2_i480 = c2_b_kAcol;
              c2_i481 = c2_i479 + c2_i480;
              if ((c2_i479 < 0) && (c2_i480 < 0) && (c2_i481 >= 0)) {
                c2_i481 = MIN_int32_T;
              } else {
                if ((c2_i479 > 0) && (c2_i480 > 0) && (c2_i481 <= 0)) {
                  c2_i481 = MAX_int32_T;
                }
              }

              c2_i482 = c2_d_k;
              c2_i483 = c2_b_jBcol;
              c2_i484 = c2_i482 + c2_i483;
              if ((c2_i482 < 0) && (c2_i483 < 0) && (c2_i484 >= 0)) {
                c2_i484 = MIN_int32_T;
              } else {
                if ((c2_i482 > 0) && (c2_i483 > 0) && (c2_i484 <= 0)) {
                  c2_i484 = MAX_int32_T;
                }
              }

              c2_i485 = c2_h_i;
              c2_i486 = c2_b_jBcol;
              c2_i487 = c2_i485 + c2_i486;
              if ((c2_i485 < 0) && (c2_i486 < 0) && (c2_i487 >= 0)) {
                c2_i487 = MIN_int32_T;
              } else {
                if ((c2_i485 > 0) && (c2_i486 > 0) && (c2_i487 <= 0)) {
                  c2_i487 = MAX_int32_T;
                }
              }

              c2_i488 = c2_h_i;
              c2_i489 = c2_b_jBcol;
              c2_i490 = c2_i488 + c2_i489;
              if ((c2_i488 < 0) && (c2_i489 < 0) && (c2_i490 >= 0)) {
                c2_i490 = MIN_int32_T;
              } else {
                if ((c2_i488 > 0) && (c2_i489 > 0) && (c2_i490 <= 0)) {
                  c2_i490 = MAX_int32_T;
                }
              }

              c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i490), 1, 40, 1, 0) - 1] = c2_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i487), 1, 40, 1, 0) - 1] - c2_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i484), 1, 40, 1, 0) - 1] * c2_j_A[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("", (real_T)
                c2_i481), 1, 100, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static void c2_eml_xgetrf(real_T c2_A[100], real_T c2_b_A[100], int32_T c2_ipiv
  [10], int32_T *c2_info)
{
  int32_T c2_i491;
  int32_T c2_i492;
  int32_T c2_i493;
  int32_T c2_hoistedExpr;
  int32_T c2_x[10];
  int32_T c2_i494;
  int32_T c2_i495;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  real_T c2_b;
  real_T c2_d20;
  real_T c2_d21;
  int32_T c2_i496;
  int32_T c2_jm1;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_mmj;
  int32_T c2_c_a;
  int32_T c2_d_a;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_jj;
  int32_T c2_e_a;
  real_T c2_e_b;
  real_T c2_d22;
  real_T c2_d23;
  int32_T c2_i497;
  int32_T c2_jp1j;
  int32_T c2_f_a;
  real_T c2_f_b;
  real_T c2_d24;
  real_T c2_d25;
  int32_T c2_i498;
  int32_T c2_c;
  int32_T c2_i499;
  int32_T c2_i500;
  real_T c2_c_A[100];
  int32_T c2_g_a;
  real_T c2_g_b;
  real_T c2_d26;
  real_T c2_d27;
  int32_T c2_i501;
  int32_T c2_jpiv_offset;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_jpiv;
  int32_T c2_i_a;
  int32_T c2_i_b;
  int32_T c2_b_c;
  int32_T c2_j_a;
  int32_T c2_j_b;
  int32_T c2_jrow;
  int32_T c2_k_a;
  int32_T c2_k_b;
  int32_T c2_jprow;
  int32_T c2_i502;
  int32_T c2_i503;
  real_T c2_d_A[100];
  int32_T c2_b_jp1j;
  int32_T c2_l_a;
  int32_T c2_m_a;
  real_T c2_l_b;
  real_T c2_d28;
  real_T c2_d29;
  int32_T c2_i504;
  int32_T c2_m_b;
  int32_T c2_loop_ub;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_b_x;
  real_T c2_y;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_z;
  int32_T c2_n_a;
  int32_T c2_n_b;
  int32_T c2_c_c;
  int32_T c2_o_a;
  int32_T c2_o_b;
  int32_T c2_d_c;
  int32_T c2_p_a;
  int32_T c2_p_b;
  int32_T c2_e_c;
  int32_T c2_i505;
  int32_T c2_i506;
  real_T c2_e_A[100];
  int32_T c2_d_x;
  for (c2_i491 = 0; c2_i491 < 10; c2_i491 = c2_i491 + 1) {
    for (c2_i492 = 0; c2_i492 < 10; c2_i492 = c2_i492 + 1) {
      c2_b_A[c2_i492 + 10 * c2_i491] = c2_A[c2_i492 + 10 * c2_i491];
    }
  }

  for (c2_i493 = 0; c2_i493 < 10; c2_i493 = c2_i493 + 1) {
    c2_hoistedExpr = 0;
    c2_x[c2_i493] = 1 + c2_i493;
  }

  for (c2_i494 = 0; c2_i494 < 10; c2_i494 = c2_i494 + 1) {
    c2_ipiv[c2_i494] = c2_x[c2_i494];
  }

  *c2_info = 0;
  c2_i495 = 1;
  for (c2_j = c2_i495; c2_j < 10; c2_j = c2_j + 1) {
    c2_b_j = c2_j;
    c2_a = c2_b_j;
    c2_b = 1.0;
    c2_d20 = c2_b;
    c2_d21 = c2_d20 < 0.0 ? ceil(c2_d20 - 0.5) : floor(c2_d20 + 0.5);
    if (c2_d21 < 2.147483648E+009) {
      if (c2_d21 >= -2.147483648E+009) {
        c2_i496 = (int32_T)c2_d21;
      } else {
        c2_i496 = MIN_int32_T;
      }
    } else {
      c2_i496 = MAX_int32_T;
    }

    c2_jm1 = c2_a - c2_i496;
    c2_b_a = 10;
    c2_b_b = c2_b_j;
    c2_mmj = c2_b_a - c2_b_b;
    c2_c_a = 1;
    c2_d_a = c2_jm1;
    c2_c_b = 11;
    c2_d_b = c2_d_a * c2_c_b;
    c2_jj = c2_c_a + c2_d_b;
    c2_e_a = c2_jj;
    c2_e_b = 1.0;
    c2_d22 = c2_e_b;
    c2_d23 = c2_d22 < 0.0 ? ceil(c2_d22 - 0.5) : floor(c2_d22 + 0.5);
    if (c2_d23 < 2.147483648E+009) {
      if (c2_d23 >= -2.147483648E+009) {
        c2_i497 = (int32_T)c2_d23;
      } else {
        c2_i497 = MIN_int32_T;
      }
    } else {
      c2_i497 = MAX_int32_T;
    }

    c2_jp1j = c2_e_a + c2_i497;
    c2_f_a = c2_mmj;
    c2_f_b = 1.0;
    c2_d24 = c2_f_b;
    c2_d25 = c2_d24 < 0.0 ? ceil(c2_d24 - 0.5) : floor(c2_d24 + 0.5);
    if (c2_d25 < 2.147483648E+009) {
      if (c2_d25 >= -2.147483648E+009) {
        c2_i498 = (int32_T)c2_d25;
      } else {
        c2_i498 = MIN_int32_T;
      }
    } else {
      c2_i498 = MAX_int32_T;
    }

    c2_c = c2_f_a + c2_i498;
    for (c2_i499 = 0; c2_i499 < 10; c2_i499 = c2_i499 + 1) {
      for (c2_i500 = 0; c2_i500 < 10; c2_i500 = c2_i500 + 1) {
        c2_c_A[c2_i500 + 10 * c2_i499] = c2_b_A[c2_i500 + 10 * c2_i499];
      }
    }

    c2_g_a = c2_eml_ixamax(c2_c, c2_c_A, c2_jj, 1);
    c2_g_b = 1.0;
    c2_d26 = c2_g_b;
    c2_d27 = c2_d26 < 0.0 ? ceil(c2_d26 - 0.5) : floor(c2_d26 + 0.5);
    if (c2_d27 < 2.147483648E+009) {
      if (c2_d27 >= -2.147483648E+009) {
        c2_i501 = (int32_T)c2_d27;
      } else {
        c2_i501 = MIN_int32_T;
      }
    } else {
      c2_i501 = MAX_int32_T;
    }

    c2_jpiv_offset = c2_g_a - c2_i501;
    c2_h_a = c2_jj;
    c2_h_b = c2_jpiv_offset;
    c2_jpiv = c2_h_a + c2_h_b;
    if (c2_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK(
          "jpiv", (real_T)c2_jpiv), 1, 100, 1, 0) - 1] != 0.0) {
      if ((real_T)c2_jpiv_offset != 0.0) {
        c2_i_a = c2_b_j;
        c2_i_b = c2_jpiv_offset;
        c2_b_c = c2_i_a + c2_i_b;
        c2_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv", _SFD_INTEGER_CHECK(
          "j", (real_T)c2_b_j), 1, 10, 1, 0) - 1] = c2_b_c;
        c2_j_a = 1;
        c2_j_b = c2_jm1;
        c2_jrow = c2_j_a + c2_j_b;
        c2_k_a = c2_jrow;
        c2_k_b = c2_jpiv_offset;
        c2_jprow = c2_k_a + c2_k_b;
        for (c2_i502 = 0; c2_i502 < 10; c2_i502 = c2_i502 + 1) {
          for (c2_i503 = 0; c2_i503 < 10; c2_i503 = c2_i503 + 1) {
            c2_d_A[c2_i503 + 10 * c2_i502] = c2_b_A[c2_i503 + 10 * c2_i502];
          }
        }

        c2_eml_xswap(c2_d_A, c2_jrow, c2_jprow, c2_b_A);
      }

      c2_b_jp1j = c2_jp1j;
      c2_l_a = c2_jp1j;
      c2_m_a = c2_mmj;
      c2_l_b = 1.0;
      c2_d28 = c2_l_b;
      c2_d29 = c2_d28 < 0.0 ? ceil(c2_d28 - 0.5) : floor(c2_d28 + 0.5);
      if (c2_d29 < 2.147483648E+009) {
        if (c2_d29 >= -2.147483648E+009) {
          c2_i504 = (int32_T)c2_d29;
        } else {
          c2_i504 = MIN_int32_T;
        }
      } else {
        c2_i504 = MAX_int32_T;
      }

      c2_m_b = c2_m_a - c2_i504;
      c2_loop_ub = c2_l_a + c2_m_b;
      for (c2_i = c2_b_jp1j; c2_i <= c2_loop_ub; c2_i = c2_i + 1) {
        c2_b_i = c2_i;
        c2_b_x = c2_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          _SFD_INTEGER_CHECK("i", (real_T)c2_b_i), 1, 100, 1, 0) - 1];
        c2_y = c2_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          _SFD_INTEGER_CHECK("jj", (real_T)c2_jj), 1, 100, 1, 0) - 1];
        c2_c_x = c2_b_x;
        c2_b_y = c2_y;
        c2_z = c2_c_x / c2_b_y;
        c2_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("i",
          (real_T)c2_b_i), 1, 100, 1, 0) - 1] = c2_z;
      }
    } else {
      *c2_info = c2_b_j;
    }

    c2_n_a = c2_jj;
    c2_n_b = 11;
    c2_c_c = c2_n_a + c2_n_b;
    c2_o_a = c2_jj;
    c2_o_b = 10;
    c2_d_c = c2_o_a + c2_o_b;
    c2_p_a = 10;
    c2_p_b = c2_b_j;
    c2_e_c = c2_p_a - c2_p_b;
    for (c2_i505 = 0; c2_i505 < 10; c2_i505 = c2_i505 + 1) {
      for (c2_i506 = 0; c2_i506 < 10; c2_i506 = c2_i506 + 1) {
        c2_e_A[c2_i506 + 10 * c2_i505] = c2_b_A[c2_i506 + 10 * c2_i505];
      }
    }

    c2_eml_xgeru(c2_mmj, c2_e_c, c2_jp1j, c2_d_c, c2_e_A, c2_c_c, c2_b_A);
  }

  if ((real_T)*c2_info == 0.0) {
    if (!(c2_b_A[99] != 0.0)) {
      c2_d_x = 10;
      *c2_info = c2_d_x;
    }
  }
}

static void c2_b_mldivide(real_T c2_A[100], real_T c2_B[10], real_T c2_Y[10])
{
  int32_T c2_i507;
  int32_T c2_i508;
  real_T c2_b_A[100];
  int32_T c2_i509;
  real_T c2_b_B[10];
  int32_T c2_i510;
  int32_T c2_i511;
  real_T c2_c_A[100];
  int32_T c2_info;
  int32_T c2_ipiv[10];
  real_T c2_d_A[100];
  int32_T c2_i512;
  int32_T c2_i513;
  int32_T c2_i514;
  int32_T c2_b_ipiv[10];
  int32_T c2_b_info;
  real_T c2_CZERO;
  int32_T c2_i515;
  int32_T c2_i516;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_ip;
  real_T c2_temp;
  int32_T c2_m;
  int32_T c2_n;
  real_T c2_alpha1;
  int32_T c2_i517;
  int32_T c2_i518;
  real_T c2_e_A[100];
  int32_T c2_ia0;
  int32_T c2_lda;
  int32_T c2_i519;
  real_T c2_c_B[10];
  int32_T c2_ib0;
  int32_T c2_ldb;
  int32_T c2_i520;
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_i521;
  int32_T c2_i522;
  real_T c2_f_A[100];
  int32_T c2_b_ia0;
  int32_T c2_b_lda;
  int32_T c2_i523;
  real_T c2_d_B[10];
  int32_T c2_b_ib0;
  int32_T c2_b_ldb;
  int32_T c2_i524;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_c_alpha1;
  int32_T c2_i525;
  int32_T c2_i526;
  real_T c2_g_A[100];
  int32_T c2_c_ia0;
  int32_T c2_c_lda;
  int32_T c2_i527;
  real_T c2_e_B[10];
  int32_T c2_c_ib0;
  int32_T c2_c_ldb;
  int32_T c2_i528;
  boolean_T c2_NON_UNIT_ALPHA;
  int32_T c2_i529;
  int32_T c2_i530;
  int32_T c2_i531;
  int32_T c2_Aoffset;
  int32_T c2_i532;
  int32_T c2_i533;
  int32_T c2_i534;
  int32_T c2_Boffset;
  int32_T c2_i535;
  int32_T c2_loop_ub;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_i536;
  int32_T c2_i537;
  int32_T c2_i538;
  int32_T c2_i539;
  int32_T c2_i540;
  int32_T c2_i541;
  int32_T c2_jBcol;
  int32_T c2_i542;
  int32_T c2_b_loop_ub;
  int32_T c2_c_i;
  int32_T c2_d_i;
  int32_T c2_i543;
  int32_T c2_i544;
  int32_T c2_i545;
  int32_T c2_i546;
  int32_T c2_c_loop_ub;
  int32_T c2_c_j;
  int32_T c2_i547;
  int32_T c2_i548;
  int32_T c2_i549;
  int32_T c2_i550;
  int32_T c2_i551;
  int32_T c2_i552;
  int32_T c2_i553;
  int32_T c2_d_loop_ub;
  int32_T c2_e_i;
  int32_T c2_i554;
  int32_T c2_i555;
  int32_T c2_i556;
  int32_T c2_i557;
  int32_T c2_i558;
  int32_T c2_i559;
  int32_T c2_i560;
  int32_T c2_e_loop_ub;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i561;
  int32_T c2_i562;
  int32_T c2_i563;
  int32_T c2_i564;
  int32_T c2_i565;
  int32_T c2_i566;
  int32_T c2_kAcol;
  int32_T c2_i567;
  int32_T c2_i568;
  int32_T c2_i569;
  int32_T c2_i570;
  int32_T c2_i571;
  int32_T c2_i572;
  int32_T c2_i573;
  int32_T c2_f_loop_ub;
  int32_T c2_f_i;
  int32_T c2_i574;
  int32_T c2_i575;
  int32_T c2_i576;
  int32_T c2_i577;
  int32_T c2_i578;
  int32_T c2_i579;
  int32_T c2_i580;
  int32_T c2_i581;
  int32_T c2_i582;
  int32_T c2_i583;
  int32_T c2_i584;
  int32_T c2_i585;
  int32_T c2_d_m;
  int32_T c2_d_n;
  real_T c2_d_alpha1;
  int32_T c2_i586;
  int32_T c2_i587;
  real_T c2_h_A[100];
  int32_T c2_d_ia0;
  int32_T c2_d_lda;
  int32_T c2_i588;
  real_T c2_f_B[10];
  int32_T c2_d_ib0;
  int32_T c2_d_ldb;
  int32_T c2_i589;
  int32_T c2_e_m;
  int32_T c2_e_n;
  real_T c2_e_alpha1;
  int32_T c2_i590;
  int32_T c2_i591;
  real_T c2_i_A[100];
  int32_T c2_e_ia0;
  int32_T c2_e_lda;
  int32_T c2_i592;
  real_T c2_g_B[10];
  int32_T c2_e_ib0;
  int32_T c2_e_ldb;
  int32_T c2_i593;
  int32_T c2_f_m;
  int32_T c2_f_n;
  real_T c2_f_alpha1;
  int32_T c2_i594;
  int32_T c2_i595;
  real_T c2_j_A[100];
  int32_T c2_f_ia0;
  int32_T c2_f_lda;
  int32_T c2_i596;
  real_T c2_h_B[10];
  int32_T c2_f_ib0;
  int32_T c2_f_ldb;
  int32_T c2_i597;
  boolean_T c2_b_NON_UNIT_ALPHA;
  int32_T c2_i598;
  int32_T c2_i599;
  int32_T c2_i600;
  int32_T c2_b_Aoffset;
  int32_T c2_i601;
  int32_T c2_i602;
  int32_T c2_i603;
  int32_T c2_b_Boffset;
  int32_T c2_i604;
  int32_T c2_g_loop_ub;
  int32_T c2_d_j;
  int32_T c2_e_j;
  int32_T c2_i605;
  int32_T c2_i606;
  int32_T c2_i607;
  int32_T c2_i608;
  int32_T c2_i609;
  int32_T c2_i610;
  int32_T c2_b_jBcol;
  int32_T c2_i611;
  int32_T c2_h_loop_ub;
  int32_T c2_g_i;
  int32_T c2_h_i;
  int32_T c2_i612;
  int32_T c2_i613;
  int32_T c2_i614;
  int32_T c2_i615;
  int32_T c2_i_loop_ub;
  int32_T c2_f_j;
  int32_T c2_i616;
  int32_T c2_i617;
  int32_T c2_i618;
  int32_T c2_i619;
  int32_T c2_i620;
  int32_T c2_i621;
  int32_T c2_i622;
  int32_T c2_j_loop_ub;
  int32_T c2_i_i;
  int32_T c2_i623;
  int32_T c2_i624;
  int32_T c2_i625;
  int32_T c2_i626;
  int32_T c2_i627;
  int32_T c2_i628;
  int32_T c2_g_m;
  real_T c2_k_loop_ub;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_i629;
  int32_T c2_i630;
  int32_T c2_i631;
  int32_T c2_i632;
  int32_T c2_i633;
  int32_T c2_i634;
  int32_T c2_b_kAcol;
  int32_T c2_i635;
  int32_T c2_i636;
  int32_T c2_i637;
  int32_T c2_i638;
  int32_T c2_i639;
  int32_T c2_i640;
  real_T c2_x;
  int32_T c2_i641;
  int32_T c2_i642;
  int32_T c2_i643;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_z;
  int32_T c2_i644;
  int32_T c2_i645;
  int32_T c2_i646;
  int32_T c2_i647;
  int32_T c2_i648;
  int32_T c2_i649;
  int32_T c2_i650;
  int32_T c2_l_loop_ub;
  int32_T c2_j_i;
  int32_T c2_i651;
  int32_T c2_i652;
  int32_T c2_i653;
  int32_T c2_i654;
  int32_T c2_i655;
  int32_T c2_i656;
  int32_T c2_i657;
  int32_T c2_i658;
  int32_T c2_i659;
  int32_T c2_i660;
  int32_T c2_i661;
  int32_T c2_i662;
  for (c2_i507 = 0; c2_i507 < 10; c2_i507 = c2_i507 + 1) {
    for (c2_i508 = 0; c2_i508 < 10; c2_i508 = c2_i508 + 1) {
      c2_b_A[c2_i508 + 10 * c2_i507] = c2_A[c2_i508 + 10 * c2_i507];
    }
  }

  for (c2_i509 = 0; c2_i509 < 10; c2_i509 = c2_i509 + 1) {
    c2_b_B[c2_i509] = c2_B[c2_i509];
  }

  for (c2_i510 = 0; c2_i510 < 10; c2_i510 = c2_i510 + 1) {
    for (c2_i511 = 0; c2_i511 < 10; c2_i511 = c2_i511 + 1) {
      c2_c_A[c2_i511 + 10 * c2_i510] = c2_b_A[c2_i511 + 10 * c2_i510];
    }
  }

  c2_eml_xgetrf(c2_c_A, c2_d_A, c2_ipiv, &c2_info);
  for (c2_i512 = 0; c2_i512 < 10; c2_i512 = c2_i512 + 1) {
    for (c2_i513 = 0; c2_i513 < 10; c2_i513 = c2_i513 + 1) {
      c2_b_A[c2_i513 + 10 * c2_i512] = c2_d_A[c2_i513 + 10 * c2_i512];
    }
  }

  for (c2_i514 = 0; c2_i514 < 10; c2_i514 = c2_i514 + 1) {
    c2_b_ipiv[c2_i514] = c2_ipiv[c2_i514];
  }

  c2_b_info = c2_info;
  if ((real_T)c2_b_info > 0.0) {
    c2_eml_warning();
  }

  c2_CZERO = 0.0;
  for (c2_i515 = 0; c2_i515 < 10; c2_i515 = c2_i515 + 1) {
    c2_Y[c2_i515] = c2_b_B[c2_i515] + c2_CZERO;
  }

  c2_i516 = 1;
  for (c2_i = c2_i516; c2_i < 11; c2_i = c2_i + 1) {
    c2_b_i = c2_i;
    if (c2_b_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv",
         _SFD_INTEGER_CHECK("i", (real_T)c2_b_i), 1, 10, 1, 0) - 1] != c2_b_i) {
      c2_ip = c2_b_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv",
        _SFD_INTEGER_CHECK("i", (real_T)c2_b_i), 1, 10, 1, 0) - 1];
      c2_temp = c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X",
        _SFD_INTEGER_CHECK("i", (real_T)c2_b_i), 1, 10, 1, 0) - 1];
      c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("i",
        (real_T)c2_b_i), 1, 10, 1, 0) - 1] = c2_Y[(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("ip", (real_T)c2_ip),
        1, 10, 1, 0) - 1];
      c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("ip",
        (real_T)c2_ip), 1, 10, 1, 0) - 1] = c2_temp;
    }
  }

  c2_m = 10;
  c2_n = 1;
  c2_alpha1 = 1.0;
  for (c2_i517 = 0; c2_i517 < 10; c2_i517 = c2_i517 + 1) {
    for (c2_i518 = 0; c2_i518 < 10; c2_i518 = c2_i518 + 1) {
      c2_e_A[c2_i518 + 10 * c2_i517] = c2_b_A[c2_i518 + 10 * c2_i517];
    }
  }

  c2_ia0 = 1;
  c2_lda = 10;
  for (c2_i519 = 0; c2_i519 < 10; c2_i519 = c2_i519 + 1) {
    c2_c_B[c2_i519] = c2_Y[c2_i519];
  }

  c2_ib0 = 1;
  c2_ldb = 10;
  for (c2_i520 = 0; c2_i520 < 10; c2_i520 = c2_i520 + 1) {
    c2_Y[c2_i520] = c2_c_B[c2_i520];
  }

  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  for (c2_i521 = 0; c2_i521 < 10; c2_i521 = c2_i521 + 1) {
    for (c2_i522 = 0; c2_i522 < 10; c2_i522 = c2_i522 + 1) {
      c2_f_A[c2_i522 + 10 * c2_i521] = c2_e_A[c2_i522 + 10 * c2_i521];
    }
  }

  c2_b_ia0 = c2_ia0;
  c2_b_lda = c2_lda;
  for (c2_i523 = 0; c2_i523 < 10; c2_i523 = c2_i523 + 1) {
    c2_d_B[c2_i523] = c2_Y[c2_i523];
  }

  c2_b_ib0 = c2_ib0;
  c2_b_ldb = c2_ldb;
  for (c2_i524 = 0; c2_i524 < 10; c2_i524 = c2_i524 + 1) {
    c2_Y[c2_i524] = c2_d_B[c2_i524];
  }

  c2_c_m = c2_b_m;
  c2_c_n = c2_b_n;
  c2_c_alpha1 = c2_b_alpha1;
  for (c2_i525 = 0; c2_i525 < 10; c2_i525 = c2_i525 + 1) {
    for (c2_i526 = 0; c2_i526 < 10; c2_i526 = c2_i526 + 1) {
      c2_g_A[c2_i526 + 10 * c2_i525] = c2_f_A[c2_i526 + 10 * c2_i525];
    }
  }

  c2_c_ia0 = c2_b_ia0;
  c2_c_lda = c2_b_lda;
  for (c2_i527 = 0; c2_i527 < 10; c2_i527 = c2_i527 + 1) {
    c2_e_B[c2_i527] = c2_Y[c2_i527];
  }

  c2_c_ib0 = c2_b_ib0;
  c2_c_ldb = c2_b_ldb;
  for (c2_i528 = 0; c2_i528 < 10; c2_i528 = c2_i528 + 1) {
    c2_Y[c2_i528] = c2_e_B[c2_i528];
  }

  c2_NON_UNIT_ALPHA = (c2_c_alpha1 != 1.0);
  if ((real_T)c2_c_n == 0.0) {
  } else {
    c2_i529 = c2_c_ia0;
    c2_i530 = 1;
    c2_i531 = c2_i529 - c2_i530;
    if ((c2_i529 < 0) && (c2_i530 >= 0) && (c2_i531 >= 0)) {
      c2_i531 = MIN_int32_T;
    } else {
      if ((c2_i529 >= 0) && (c2_i530 < 0) && (c2_i531 < 0)) {
        c2_i531 = MAX_int32_T;
      }
    }

    c2_Aoffset = c2_i531;
    c2_i532 = c2_c_ib0;
    c2_i533 = 1;
    c2_i534 = c2_i532 - c2_i533;
    if ((c2_i532 < 0) && (c2_i533 >= 0) && (c2_i534 >= 0)) {
      c2_i534 = MIN_int32_T;
    } else {
      if ((c2_i532 >= 0) && (c2_i533 < 0) && (c2_i534 < 0)) {
        c2_i534 = MAX_int32_T;
      }
    }

    c2_Boffset = c2_i534;
    if (c2_c_alpha1 == 0.0) {
      c2_i535 = 1;
      c2_loop_ub = c2_c_n;
      for (c2_j = c2_i535; c2_j <= c2_loop_ub; c2_j = c2_j + 1) {
        c2_b_j = c2_j;
        c2_i536 = c2_b_j;
        c2_i537 = 1;
        c2_i538 = c2_i536 - c2_i537;
        if ((c2_i536 < 0) && (c2_i537 >= 0) && (c2_i538 >= 0)) {
          c2_i538 = MIN_int32_T;
        } else {
          if ((c2_i536 >= 0) && (c2_i537 < 0) && (c2_i538 < 0)) {
            c2_i538 = MAX_int32_T;
          }
        }

        c2_i539 = c2_Boffset;
        c2_i540 = c2_mul_s32_s32_s32_sat(c2_i538, c2_c_ldb);
        c2_i541 = c2_i539 + c2_i540;
        if ((c2_i539 < 0) && (c2_i540 < 0) && (c2_i541 >= 0)) {
          c2_i541 = MIN_int32_T;
        } else {
          if ((c2_i539 > 0) && (c2_i540 > 0) && (c2_i541 <= 0)) {
            c2_i541 = MAX_int32_T;
          }
        }

        c2_jBcol = c2_i541;
        c2_i542 = 1;
        c2_b_loop_ub = c2_c_m;
        for (c2_c_i = c2_i542; c2_c_i <= c2_b_loop_ub; c2_c_i = c2_c_i + 1) {
          c2_d_i = c2_c_i;
          c2_i543 = c2_d_i;
          c2_i544 = c2_jBcol;
          c2_i545 = c2_i543 + c2_i544;
          if ((c2_i543 < 0) && (c2_i544 < 0) && (c2_i545 >= 0)) {
            c2_i545 = MIN_int32_T;
          } else {
            if ((c2_i543 > 0) && (c2_i544 > 0) && (c2_i545 <= 0)) {
              c2_i545 = MAX_int32_T;
            }
          }

          c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
            (real_T)c2_i545), 1, 10, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c2_i546 = 1;
      c2_c_loop_ub = c2_c_n;
      for (c2_c_j = c2_i546; c2_c_j <= c2_c_loop_ub; c2_c_j = c2_c_j + 1) {
        c2_b_j = c2_c_j;
        c2_i547 = c2_b_j;
        c2_i548 = 1;
        c2_i549 = c2_i547 - c2_i548;
        if ((c2_i547 < 0) && (c2_i548 >= 0) && (c2_i549 >= 0)) {
          c2_i549 = MIN_int32_T;
        } else {
          if ((c2_i547 >= 0) && (c2_i548 < 0) && (c2_i549 < 0)) {
            c2_i549 = MAX_int32_T;
          }
        }

        c2_i550 = c2_Boffset;
        c2_i551 = c2_mul_s32_s32_s32_sat(c2_i549, c2_c_ldb);
        c2_i552 = c2_i550 + c2_i551;
        if ((c2_i550 < 0) && (c2_i551 < 0) && (c2_i552 >= 0)) {
          c2_i552 = MIN_int32_T;
        } else {
          if ((c2_i550 > 0) && (c2_i551 > 0) && (c2_i552 <= 0)) {
            c2_i552 = MAX_int32_T;
          }
        }

        c2_jBcol = c2_i552;
        if (c2_NON_UNIT_ALPHA) {
          c2_i553 = 1;
          c2_d_loop_ub = c2_c_m;
          for (c2_e_i = c2_i553; c2_e_i <= c2_d_loop_ub; c2_e_i = c2_e_i + 1) {
            c2_d_i = c2_e_i;
            c2_i554 = c2_d_i;
            c2_i555 = c2_jBcol;
            c2_i556 = c2_i554 + c2_i555;
            if ((c2_i554 < 0) && (c2_i555 < 0) && (c2_i556 >= 0)) {
              c2_i556 = MIN_int32_T;
            } else {
              if ((c2_i554 > 0) && (c2_i555 > 0) && (c2_i556 <= 0)) {
                c2_i556 = MAX_int32_T;
              }
            }

            c2_i557 = c2_d_i;
            c2_i558 = c2_jBcol;
            c2_i559 = c2_i557 + c2_i558;
            if ((c2_i557 < 0) && (c2_i558 < 0) && (c2_i559 >= 0)) {
              c2_i559 = MIN_int32_T;
            } else {
              if ((c2_i557 > 0) && (c2_i558 > 0) && (c2_i559 <= 0)) {
                c2_i559 = MAX_int32_T;
              }
            }

            c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i559), 1, 10, 1, 0) - 1] = c2_c_alpha1 * c2_Y[(
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i556), 1, 10, 1, 0) - 1];
          }
        }

        c2_i560 = 1;
        c2_e_loop_ub = c2_c_m;
        for (c2_k = c2_i560; c2_k <= c2_e_loop_ub; c2_k = c2_k + 1) {
          c2_b_k = c2_k;
          c2_i561 = c2_b_k;
          c2_i562 = 1;
          c2_i563 = c2_i561 - c2_i562;
          if ((c2_i561 < 0) && (c2_i562 >= 0) && (c2_i563 >= 0)) {
            c2_i563 = MIN_int32_T;
          } else {
            if ((c2_i561 >= 0) && (c2_i562 < 0) && (c2_i563 < 0)) {
              c2_i563 = MAX_int32_T;
            }
          }

          c2_i564 = c2_Aoffset;
          c2_i565 = c2_mul_s32_s32_s32_sat(c2_i563, c2_c_lda);
          c2_i566 = c2_i564 + c2_i565;
          if ((c2_i564 < 0) && (c2_i565 < 0) && (c2_i566 >= 0)) {
            c2_i566 = MIN_int32_T;
          } else {
            if ((c2_i564 > 0) && (c2_i565 > 0) && (c2_i566 <= 0)) {
              c2_i566 = MAX_int32_T;
            }
          }

          c2_kAcol = c2_i566;
          c2_i567 = c2_b_k;
          c2_i568 = c2_jBcol;
          c2_i569 = c2_i567 + c2_i568;
          if ((c2_i567 < 0) && (c2_i568 < 0) && (c2_i569 >= 0)) {
            c2_i569 = MIN_int32_T;
          } else {
            if ((c2_i567 > 0) && (c2_i568 > 0) && (c2_i569 <= 0)) {
              c2_i569 = MAX_int32_T;
            }
          }

          if (c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i569), 1, 10, 1, 0) - 1] != 0.0) {
            c2_i570 = c2_b_k;
            c2_i571 = 1;
            c2_i572 = c2_i570 + c2_i571;
            if ((c2_i570 < 0) && (c2_i571 < 0) && (c2_i572 >= 0)) {
              c2_i572 = MIN_int32_T;
            } else {
              if ((c2_i570 > 0) && (c2_i571 > 0) && (c2_i572 <= 0)) {
                c2_i572 = MAX_int32_T;
              }
            }

            c2_i573 = c2_i572;
            c2_f_loop_ub = c2_c_m;
            for (c2_f_i = c2_i573; c2_f_i <= c2_f_loop_ub; c2_f_i = c2_f_i + 1)
            {
              c2_d_i = c2_f_i;
              c2_i574 = c2_d_i;
              c2_i575 = c2_kAcol;
              c2_i576 = c2_i574 + c2_i575;
              if ((c2_i574 < 0) && (c2_i575 < 0) && (c2_i576 >= 0)) {
                c2_i576 = MIN_int32_T;
              } else {
                if ((c2_i574 > 0) && (c2_i575 > 0) && (c2_i576 <= 0)) {
                  c2_i576 = MAX_int32_T;
                }
              }

              c2_i577 = c2_b_k;
              c2_i578 = c2_jBcol;
              c2_i579 = c2_i577 + c2_i578;
              if ((c2_i577 < 0) && (c2_i578 < 0) && (c2_i579 >= 0)) {
                c2_i579 = MIN_int32_T;
              } else {
                if ((c2_i577 > 0) && (c2_i578 > 0) && (c2_i579 <= 0)) {
                  c2_i579 = MAX_int32_T;
                }
              }

              c2_i580 = c2_d_i;
              c2_i581 = c2_jBcol;
              c2_i582 = c2_i580 + c2_i581;
              if ((c2_i580 < 0) && (c2_i581 < 0) && (c2_i582 >= 0)) {
                c2_i582 = MIN_int32_T;
              } else {
                if ((c2_i580 > 0) && (c2_i581 > 0) && (c2_i582 <= 0)) {
                  c2_i582 = MAX_int32_T;
                }
              }

              c2_i583 = c2_d_i;
              c2_i584 = c2_jBcol;
              c2_i585 = c2_i583 + c2_i584;
              if ((c2_i583 < 0) && (c2_i584 < 0) && (c2_i585 >= 0)) {
                c2_i585 = MIN_int32_T;
              } else {
                if ((c2_i583 > 0) && (c2_i584 > 0) && (c2_i585 <= 0)) {
                  c2_i585 = MAX_int32_T;
                }
              }

              c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i585), 1, 10, 1, 0) - 1] = c2_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i582), 1, 10, 1, 0) - 1] - c2_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i579), 1, 10, 1, 0) - 1] * c2_g_A[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("", (real_T)
                c2_i576), 1, 100, 1, 0) - 1];
            }
          }
        }
      }
    }
  }

  c2_d_m = 10;
  c2_d_n = 1;
  c2_d_alpha1 = 1.0;
  for (c2_i586 = 0; c2_i586 < 10; c2_i586 = c2_i586 + 1) {
    for (c2_i587 = 0; c2_i587 < 10; c2_i587 = c2_i587 + 1) {
      c2_h_A[c2_i587 + 10 * c2_i586] = c2_b_A[c2_i587 + 10 * c2_i586];
    }
  }

  c2_d_ia0 = 1;
  c2_d_lda = 10;
  for (c2_i588 = 0; c2_i588 < 10; c2_i588 = c2_i588 + 1) {
    c2_f_B[c2_i588] = c2_Y[c2_i588];
  }

  c2_d_ib0 = 1;
  c2_d_ldb = 10;
  for (c2_i589 = 0; c2_i589 < 10; c2_i589 = c2_i589 + 1) {
    c2_Y[c2_i589] = c2_f_B[c2_i589];
  }

  c2_e_m = c2_d_m;
  c2_e_n = c2_d_n;
  c2_e_alpha1 = c2_d_alpha1;
  for (c2_i590 = 0; c2_i590 < 10; c2_i590 = c2_i590 + 1) {
    for (c2_i591 = 0; c2_i591 < 10; c2_i591 = c2_i591 + 1) {
      c2_i_A[c2_i591 + 10 * c2_i590] = c2_h_A[c2_i591 + 10 * c2_i590];
    }
  }

  c2_e_ia0 = c2_d_ia0;
  c2_e_lda = c2_d_lda;
  for (c2_i592 = 0; c2_i592 < 10; c2_i592 = c2_i592 + 1) {
    c2_g_B[c2_i592] = c2_Y[c2_i592];
  }

  c2_e_ib0 = c2_d_ib0;
  c2_e_ldb = c2_d_ldb;
  for (c2_i593 = 0; c2_i593 < 10; c2_i593 = c2_i593 + 1) {
    c2_Y[c2_i593] = c2_g_B[c2_i593];
  }

  c2_f_m = c2_e_m;
  c2_f_n = c2_e_n;
  c2_f_alpha1 = c2_e_alpha1;
  for (c2_i594 = 0; c2_i594 < 10; c2_i594 = c2_i594 + 1) {
    for (c2_i595 = 0; c2_i595 < 10; c2_i595 = c2_i595 + 1) {
      c2_j_A[c2_i595 + 10 * c2_i594] = c2_i_A[c2_i595 + 10 * c2_i594];
    }
  }

  c2_f_ia0 = c2_e_ia0;
  c2_f_lda = c2_e_lda;
  for (c2_i596 = 0; c2_i596 < 10; c2_i596 = c2_i596 + 1) {
    c2_h_B[c2_i596] = c2_Y[c2_i596];
  }

  c2_f_ib0 = c2_e_ib0;
  c2_f_ldb = c2_e_ldb;
  for (c2_i597 = 0; c2_i597 < 10; c2_i597 = c2_i597 + 1) {
    c2_Y[c2_i597] = c2_h_B[c2_i597];
  }

  c2_b_NON_UNIT_ALPHA = (c2_f_alpha1 != 1.0);
  if ((real_T)c2_f_n == 0.0) {
  } else {
    c2_i598 = c2_f_ia0;
    c2_i599 = 1;
    c2_i600 = c2_i598 - c2_i599;
    if ((c2_i598 < 0) && (c2_i599 >= 0) && (c2_i600 >= 0)) {
      c2_i600 = MIN_int32_T;
    } else {
      if ((c2_i598 >= 0) && (c2_i599 < 0) && (c2_i600 < 0)) {
        c2_i600 = MAX_int32_T;
      }
    }

    c2_b_Aoffset = c2_i600;
    c2_i601 = c2_f_ib0;
    c2_i602 = 1;
    c2_i603 = c2_i601 - c2_i602;
    if ((c2_i601 < 0) && (c2_i602 >= 0) && (c2_i603 >= 0)) {
      c2_i603 = MIN_int32_T;
    } else {
      if ((c2_i601 >= 0) && (c2_i602 < 0) && (c2_i603 < 0)) {
        c2_i603 = MAX_int32_T;
      }
    }

    c2_b_Boffset = c2_i603;
    if (c2_f_alpha1 == 0.0) {
      c2_i604 = 1;
      c2_g_loop_ub = c2_f_n;
      for (c2_d_j = c2_i604; c2_d_j <= c2_g_loop_ub; c2_d_j = c2_d_j + 1) {
        c2_e_j = c2_d_j;
        c2_i605 = c2_e_j;
        c2_i606 = 1;
        c2_i607 = c2_i605 - c2_i606;
        if ((c2_i605 < 0) && (c2_i606 >= 0) && (c2_i607 >= 0)) {
          c2_i607 = MIN_int32_T;
        } else {
          if ((c2_i605 >= 0) && (c2_i606 < 0) && (c2_i607 < 0)) {
            c2_i607 = MAX_int32_T;
          }
        }

        c2_i608 = c2_b_Boffset;
        c2_i609 = c2_mul_s32_s32_s32_sat(c2_i607, c2_f_ldb);
        c2_i610 = c2_i608 + c2_i609;
        if ((c2_i608 < 0) && (c2_i609 < 0) && (c2_i610 >= 0)) {
          c2_i610 = MIN_int32_T;
        } else {
          if ((c2_i608 > 0) && (c2_i609 > 0) && (c2_i610 <= 0)) {
            c2_i610 = MAX_int32_T;
          }
        }

        c2_b_jBcol = c2_i610;
        c2_i611 = 1;
        c2_h_loop_ub = c2_f_m;
        for (c2_g_i = c2_i611; c2_g_i <= c2_h_loop_ub; c2_g_i = c2_g_i + 1) {
          c2_h_i = c2_g_i;
          c2_i612 = c2_h_i;
          c2_i613 = c2_b_jBcol;
          c2_i614 = c2_i612 + c2_i613;
          if ((c2_i612 < 0) && (c2_i613 < 0) && (c2_i614 >= 0)) {
            c2_i614 = MIN_int32_T;
          } else {
            if ((c2_i612 > 0) && (c2_i613 > 0) && (c2_i614 <= 0)) {
              c2_i614 = MAX_int32_T;
            }
          }

          c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
            (real_T)c2_i614), 1, 10, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c2_i615 = 1;
      c2_i_loop_ub = c2_f_n;
      for (c2_f_j = c2_i615; c2_f_j <= c2_i_loop_ub; c2_f_j = c2_f_j + 1) {
        c2_e_j = c2_f_j;
        c2_i616 = c2_e_j;
        c2_i617 = 1;
        c2_i618 = c2_i616 - c2_i617;
        if ((c2_i616 < 0) && (c2_i617 >= 0) && (c2_i618 >= 0)) {
          c2_i618 = MIN_int32_T;
        } else {
          if ((c2_i616 >= 0) && (c2_i617 < 0) && (c2_i618 < 0)) {
            c2_i618 = MAX_int32_T;
          }
        }

        c2_i619 = c2_b_Boffset;
        c2_i620 = c2_mul_s32_s32_s32_sat(c2_i618, c2_f_ldb);
        c2_i621 = c2_i619 + c2_i620;
        if ((c2_i619 < 0) && (c2_i620 < 0) && (c2_i621 >= 0)) {
          c2_i621 = MIN_int32_T;
        } else {
          if ((c2_i619 > 0) && (c2_i620 > 0) && (c2_i621 <= 0)) {
            c2_i621 = MAX_int32_T;
          }
        }

        c2_b_jBcol = c2_i621;
        if (c2_b_NON_UNIT_ALPHA) {
          c2_i622 = 1;
          c2_j_loop_ub = c2_f_m;
          for (c2_i_i = c2_i622; c2_i_i <= c2_j_loop_ub; c2_i_i = c2_i_i + 1) {
            c2_h_i = c2_i_i;
            c2_i623 = c2_h_i;
            c2_i624 = c2_b_jBcol;
            c2_i625 = c2_i623 + c2_i624;
            if ((c2_i623 < 0) && (c2_i624 < 0) && (c2_i625 >= 0)) {
              c2_i625 = MIN_int32_T;
            } else {
              if ((c2_i623 > 0) && (c2_i624 > 0) && (c2_i625 <= 0)) {
                c2_i625 = MAX_int32_T;
              }
            }

            c2_i626 = c2_h_i;
            c2_i627 = c2_b_jBcol;
            c2_i628 = c2_i626 + c2_i627;
            if ((c2_i626 < 0) && (c2_i627 < 0) && (c2_i628 >= 0)) {
              c2_i628 = MIN_int32_T;
            } else {
              if ((c2_i626 > 0) && (c2_i627 > 0) && (c2_i628 <= 0)) {
                c2_i628 = MAX_int32_T;
              }
            }

            c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i628), 1, 10, 1, 0) - 1] = c2_f_alpha1 * c2_Y[(
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i625), 1, 10, 1, 0) - 1];
          }
        }

        c2_g_m = c2_f_m;
        c2_k_loop_ub = 1.0;
        for (c2_c_k = c2_g_m; c2_c_k >= (int32_T)c2_k_loop_ub; c2_c_k = c2_c_k +
             -1) {
          c2_d_k = c2_c_k;
          c2_i629 = c2_d_k;
          c2_i630 = 1;
          c2_i631 = c2_i629 - c2_i630;
          if ((c2_i629 < 0) && (c2_i630 >= 0) && (c2_i631 >= 0)) {
            c2_i631 = MIN_int32_T;
          } else {
            if ((c2_i629 >= 0) && (c2_i630 < 0) && (c2_i631 < 0)) {
              c2_i631 = MAX_int32_T;
            }
          }

          c2_i632 = c2_b_Aoffset;
          c2_i633 = c2_mul_s32_s32_s32_sat(c2_i631, c2_f_lda);
          c2_i634 = c2_i632 + c2_i633;
          if ((c2_i632 < 0) && (c2_i633 < 0) && (c2_i634 >= 0)) {
            c2_i634 = MIN_int32_T;
          } else {
            if ((c2_i632 > 0) && (c2_i633 > 0) && (c2_i634 <= 0)) {
              c2_i634 = MAX_int32_T;
            }
          }

          c2_b_kAcol = c2_i634;
          c2_i635 = c2_d_k;
          c2_i636 = c2_b_jBcol;
          c2_i637 = c2_i635 + c2_i636;
          if ((c2_i635 < 0) && (c2_i636 < 0) && (c2_i637 >= 0)) {
            c2_i637 = MIN_int32_T;
          } else {
            if ((c2_i635 > 0) && (c2_i636 > 0) && (c2_i637 <= 0)) {
              c2_i637 = MAX_int32_T;
            }
          }

          if (c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i637), 1, 10, 1, 0) - 1] != 0.0) {
            c2_i638 = c2_d_k;
            c2_i639 = c2_b_jBcol;
            c2_i640 = c2_i638 + c2_i639;
            if ((c2_i638 < 0) && (c2_i639 < 0) && (c2_i640 >= 0)) {
              c2_i640 = MIN_int32_T;
            } else {
              if ((c2_i638 > 0) && (c2_i639 > 0) && (c2_i640 <= 0)) {
                c2_i640 = MAX_int32_T;
              }
            }

            c2_x = c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B",
              _SFD_INTEGER_CHECK("", (real_T)c2_i640), 1, 10, 1, 0) - 1];
            c2_i641 = c2_d_k;
            c2_i642 = c2_b_kAcol;
            c2_i643 = c2_i641 + c2_i642;
            if ((c2_i641 < 0) && (c2_i642 < 0) && (c2_i643 >= 0)) {
              c2_i643 = MIN_int32_T;
            } else {
              if ((c2_i641 > 0) && (c2_i642 > 0) && (c2_i643 <= 0)) {
                c2_i643 = MAX_int32_T;
              }
            }

            c2_y = c2_j_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
              _SFD_INTEGER_CHECK("", (real_T)c2_i643), 1, 100, 1, 0) - 1];
            c2_b_x = c2_x;
            c2_b_y = c2_y;
            c2_z = c2_b_x / c2_b_y;
            c2_i644 = c2_d_k;
            c2_i645 = c2_b_jBcol;
            c2_i646 = c2_i644 + c2_i645;
            if ((c2_i644 < 0) && (c2_i645 < 0) && (c2_i646 >= 0)) {
              c2_i646 = MIN_int32_T;
            } else {
              if ((c2_i644 > 0) && (c2_i645 > 0) && (c2_i646 <= 0)) {
                c2_i646 = MAX_int32_T;
              }
            }

            c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c2_i646), 1, 10, 1, 0) - 1] = c2_z;
            c2_i647 = 1;
            c2_i648 = c2_d_k;
            c2_i649 = 1;
            c2_i650 = c2_i648 - c2_i649;
            if ((c2_i648 < 0) && (c2_i649 >= 0) && (c2_i650 >= 0)) {
              c2_i650 = MIN_int32_T;
            } else {
              if ((c2_i648 >= 0) && (c2_i649 < 0) && (c2_i650 < 0)) {
                c2_i650 = MAX_int32_T;
              }
            }

            c2_l_loop_ub = c2_i650;
            for (c2_j_i = c2_i647; c2_j_i <= c2_l_loop_ub; c2_j_i = c2_j_i + 1)
            {
              c2_h_i = c2_j_i;
              c2_i651 = c2_h_i;
              c2_i652 = c2_b_kAcol;
              c2_i653 = c2_i651 + c2_i652;
              if ((c2_i651 < 0) && (c2_i652 < 0) && (c2_i653 >= 0)) {
                c2_i653 = MIN_int32_T;
              } else {
                if ((c2_i651 > 0) && (c2_i652 > 0) && (c2_i653 <= 0)) {
                  c2_i653 = MAX_int32_T;
                }
              }

              c2_i654 = c2_d_k;
              c2_i655 = c2_b_jBcol;
              c2_i656 = c2_i654 + c2_i655;
              if ((c2_i654 < 0) && (c2_i655 < 0) && (c2_i656 >= 0)) {
                c2_i656 = MIN_int32_T;
              } else {
                if ((c2_i654 > 0) && (c2_i655 > 0) && (c2_i656 <= 0)) {
                  c2_i656 = MAX_int32_T;
                }
              }

              c2_i657 = c2_h_i;
              c2_i658 = c2_b_jBcol;
              c2_i659 = c2_i657 + c2_i658;
              if ((c2_i657 < 0) && (c2_i658 < 0) && (c2_i659 >= 0)) {
                c2_i659 = MIN_int32_T;
              } else {
                if ((c2_i657 > 0) && (c2_i658 > 0) && (c2_i659 <= 0)) {
                  c2_i659 = MAX_int32_T;
                }
              }

              c2_i660 = c2_h_i;
              c2_i661 = c2_b_jBcol;
              c2_i662 = c2_i660 + c2_i661;
              if ((c2_i660 < 0) && (c2_i661 < 0) && (c2_i662 >= 0)) {
                c2_i662 = MIN_int32_T;
              } else {
                if ((c2_i660 > 0) && (c2_i661 > 0) && (c2_i662 <= 0)) {
                  c2_i662 = MAX_int32_T;
                }
              }

              c2_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c2_i662), 1, 10, 1, 0) - 1] = c2_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i659), 1, 10, 1, 0) - 1] - c2_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c2_i656), 1, 10, 1, 0) - 1] * c2_j_A[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("", (real_T)
                c2_i653), 1, 100, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static real_T c2_mrdivide(real_T c2_A, real_T c2_B)
{
  real_T c2_x;
  real_T c2_b_y;
  real_T c2_b_x;
  real_T c2_c_y;
  real_T c2_c_x;
  real_T c2_d_y;
  c2_x = c2_A;
  c2_b_y = c2_B;
  if (c2_b_y == 0.0) {
    c2_c_eml_warning();
  }

  c2_b_x = c2_x;
  c2_c_y = c2_b_y;
  c2_c_x = c2_b_x;
  c2_d_y = c2_c_y;
  return c2_c_x / c2_d_y;
}

static void c2_c_eml_warning(void)
{
  int32_T c2_i663;
  static char c2_cv4[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char c2_varargin_1[19];
  int32_T c2_i664;
  static char c2_cv5[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char c2_varargin_2[15];
  int32_T c2_i665;
  char c2_u[19];
  const mxArray *c2_y = NULL;
  int32_T c2_i666;
  char c2_b_u[15];
  const mxArray *c2_b_y = NULL;
  for (c2_i663 = 0; c2_i663 < 19; c2_i663 = c2_i663 + 1) {
    c2_varargin_1[c2_i663] = c2_cv4[c2_i663];
  }

  for (c2_i664 = 0; c2_i664 < 15; c2_i664 = c2_i664 + 1) {
    c2_varargin_2[c2_i664] = c2_cv5[c2_i664];
  }

  for (c2_i665 = 0; c2_i665 < 19; c2_i665 = c2_i665 + 1) {
    c2_u[c2_i665] = c2_varargin_1[c2_i665];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create(&c2_u, "y", 8, 0U, 1U, 2, 1, 19));
  for (c2_i666 = 0; c2_i666 < 15; c2_i666 = c2_i666 + 1) {
    c2_b_u[c2_i666] = c2_varargin_2[c2_i666];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 8, 0U, 1U, 2, 1, 15));
  sf_mex_call("warning", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static real_T c2_max(real_T c2_varargin_1, real_T c2_varargin_2)
{
  real_T c2_x;
  real_T c2_y;
  boolean_T c2_domax;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_xk;
  real_T c2_yk;
  boolean_T c2_b_domax;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_rx;
  real_T c2_ry;
  real_T c2_d_x;
  boolean_T c2_b;
  real_T c2_extremum;
  c2_x = c2_varargin_1;
  c2_y = c2_varargin_2;
  c2_domax = true;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_xk = c2_b_x;
  c2_yk = c2_b_y;
  c2_b_domax = c2_domax;
  c2_c_x = c2_xk;
  c2_c_y = c2_yk;
  c2_rx = c2_xk;
  c2_ry = c2_yk;
  if (c2_b_domax) {
    if (c2_rx >= c2_ry) {
      goto label_1;
    }
  }

  if (!c2_b_domax) {
    if (c2_rx <= c2_ry) {
      goto label_1;
    }
  }

  c2_d_x = c2_ry;
  c2_b = rtIsNaN(c2_d_x);
  if (c2_b) {
  } else {
    c2_extremum = c2_c_y;
    goto label_2;
  }

 label_1:
  ;
  c2_extremum = c2_c_x;
 label_2:
  ;
  return c2_extremum;
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i667;
  int32_T c2_i668;
  real_T c2_b_u[100];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i667 = 0; c2_i667 < 10; c2_i667 = c2_i667 + 1) {
    for (c2_i668 = 0; c2_i668 < 10; c2_i668 = c2_i668 + 1) {
      c2_b_u[c2_i668 + 10 * c2_i667] = (*((real_T (*)[100])c2_u))[c2_i668 + 10 *
        c2_i667];
    }
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 2, 10, 10));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i669;
  real_T c2_b_u[10];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i669 = 0; c2_i669 < 10; c2_i669 = c2_i669 + 1) {
    c2_b_u[c2_i669] = (*((real_T (*)[10])c2_u))[c2_i669];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 10));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i670;
  int32_T c2_i671;
  real_T c2_b_u[40];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i670 = 0; c2_i670 < 10; c2_i670 = c2_i670 + 1) {
    for (c2_i671 = 0; c2_i671 < 4; c2_i671 = c2_i671 + 1) {
      c2_b_u[c2_i671 + 4 * c2_i670] = (*((real_T (*)[40])c2_u))[c2_i671 + 4 *
        c2_i670];
    }
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 2, 4, 10));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i672;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i672 = 0; c2_i672 < 4; c2_i672 = c2_i672 + 1) {
    c2_b_u[c2_i672] = (*((real_T (*)[4])c2_u))[c2_i672];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i673;
  int32_T c2_i674;
  real_T c2_b_u[16];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i673 = 0; c2_i673 < 4; c2_i673 = c2_i673 + 1) {
    for (c2_i674 = 0; c2_i674 < 4; c2_i674 = c2_i674 + 1) {
      c2_b_u[c2_i674 + 4 * c2_i673] = (*((real_T (*)[16])c2_u))[c2_i674 + 4 *
        c2_i673];
    }
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_MPC_AVC_implementation_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[108];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i675;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 108));
  for (c2_i675 = 0; c2_i675 < 108; c2_i675 = c2_i675 + 1) {
    c2_r0 = &c2_info[c2_i675];
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i675);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i675);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i675);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved",
                    "nameCaptureInfo", c2_i675);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c2_i675);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime1, "nameCaptureInfo", 7,
      0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i675);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime2, "nameCaptureInfo", 7,
      0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i675);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[108])
{
  c2_info[0].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[0].name = "abs";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[0].fileLength = 990U;
  c2_info[0].fileTime1 = 1192466652U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[1].name = "mpower";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[1].fileLength = 3338U;
  c2_info[1].fileTime1 = 1192466918U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[2].name = "mtimes";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[2].fileLength = 1990U;
  c2_info[2].fileTime1 = 1197652350U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[3].name = "eml_refblas_xgerx";
  c2_info[3].dominantType = "int32";
  c2_info[3].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[3].fileLength = 2218U;
  c2_info[3].fileTime1 = 1195314402U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/assert_integral";
  c2_info[4].name = "false";
  c2_info[4].dominantType = "";
  c2_info[4].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[4].fileLength = 238U;
  c2_info[4].fileTime1 = 1192466720U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[5].name = "isequal";
  c2_info[5].dominantType = "char";
  c2_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[5].fileLength = 2029U;
  c2_info[5].fileTime1 = 1192466732U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[6].name = "eml_scalexp_size";
  c2_info[6].dominantType = "int32";
  c2_info[6].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[6].fileLength = 872U;
  c2_info[6].fileTime1 = 1192466806U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[7].name = "eml_isa_uint";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[7].fileLength = 239U;
  c2_info[7].fileTime1 = 1192466792U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[8].name = "nargin";
  c2_info[8].dominantType = "";
  c2_info[8].resolved = "[B]nargin";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[9].name = "isnumeric";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]isnumeric";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[10].name = "inf";
  c2_info[10].dominantType = "";
  c2_info[10].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/inf.m";
  c2_info[10].fileLength = 474U;
  c2_info[10].fileTime1 = 1192466728U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m/zerosum";
  c2_info[11].name = "plus";
  c2_info[11].dominantType = "int32";
  c2_info[11].resolved = "[B]plus";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[12].name = "colon";
  c2_info[12].dominantType = "int32";
  c2_info[12].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[12].fileLength = 7324U;
  c2_info[12].fileTime1 = 1197300746U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xgemm.m";
  c2_info[13].name = "eml_refblas_xgemm";
  c2_info[13].dominantType = "int32";
  c2_info[13].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[13].fileLength = 5746U;
  c2_info[13].fileTime1 = 1195314400U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c2_info[14].name = "isinf";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[14].fileLength = 472U;
  c2_info[14].fileTime1 = 1192466734U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c2_info[15].name = "eps";
  c2_info[15].dominantType = "char";
  c2_info[15].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[15].fileLength = 1339U;
  c2_info[15].fileTime1 = 1192466718U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[16].name = "isstruct";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]isstruct";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c2_info[17].name = "intmin";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[17].fileLength = 1505U;
  c2_info[17].fileTime1 = 1192466730U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[18].name = "eml_xgemm";
  c2_info[18].dominantType = "int32";
  c2_info[18].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[18].fileLength = 2968U;
  c2_info[18].fileTime1 = 1192466836U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[19].name = "eml_scalexp_compatible";
  c2_info[19].dominantType = "int32";
  c2_info[19].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[19].fileLength = 376U;
  c2_info[19].fileTime1 = 1192466804U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_scalar_bin_extremum";
  c2_info[20].name = "isnan";
  c2_info[20].dominantType = "int32";
  c2_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[20].fileLength = 472U;
  c2_info[20].fileTime1 = 1192466736U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c2_info[21].name = "eml_index_class";
  c2_info[21].dominantType = "";
  c2_info[21].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[21].fileLength = 909U;
  c2_info[21].fileTime1 = 1192466782U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[22].name = "int32";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]int32";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[23].name = "real";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]real";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[24].name = "isscalar";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]isscalar";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c2_info[25].name = "eml_xtrsm";
  c2_info[25].dominantType = "int32";
  c2_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c2_info[25].fileLength = 2205U;
  c2_info[25].fileTime1 = 1195314374U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[26].name = "eml_blas_ixamax";
  c2_info[26].dominantType = "int32";
  c2_info[26].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_ixamax.m";
  c2_info[26].fileLength = 216U;
  c2_info[26].fileTime1 = 1192466848U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[27].name = "eml_xdotu";
  c2_info[27].dominantType = "int32";
  c2_info[27].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c2_info[27].fileLength = 1346U;
  c2_info[27].fileTime1 = 1195314372U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c2_info[28].name = "intmax";
  c2_info[28].dominantType = "char";
  c2_info[28].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[28].fileLength = 1535U;
  c2_info[28].fileTime1 = 1192466728U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c2_info[29].name = "eml_xdot";
  c2_info[29].dominantType = "int32";
  c2_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[29].fileLength = 1223U;
  c2_info[29].fileTime1 = 1192466832U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[30].name = "eml_is_float_class";
  c2_info[30].dominantType = "char";
  c2_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[30].fileLength = 226U;
  c2_info[30].fileTime1 = 1197652350U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c2_info[31].name = "logical";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[B]logical";
  c2_info[31].fileLength = 0U;
  c2_info[31].fileTime1 = 0U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xswap.m";
  c2_info[32].name = "eml_refblas_xswap";
  c2_info[32].dominantType = "int32";
  c2_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[32].fileLength = 981U;
  c2_info[32].fileTime1 = 1192466884U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/assert_integral";
  c2_info[33].name = "not";
  c2_info[33].dominantType = "logical";
  c2_info[33].resolved = "[B]not";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[34].name = "minus";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved = "[B]minus";
  c2_info[34].fileLength = 0U;
  c2_info[34].fileTime1 = 0U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[35].name = "nargout";
  c2_info[35].dominantType = "";
  c2_info[35].resolved = "[B]nargout";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context = "";
  c2_info[36].name = "size";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved = "[B]size";
  c2_info[36].fileLength = 0U;
  c2_info[36].fileTime1 = 0U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[37].name = "eml_xswap";
  c2_info[37].dominantType = "int32";
  c2_info[37].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[37].fileLength = 1219U;
  c2_info[37].fileTime1 = 1192466844U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c2_info[38].name = "eml_blas_xger";
  c2_info[38].dominantType = "int32";
  c2_info[38].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xger.m";
  c2_info[38].fileLength = 292U;
  c2_info[38].fileTime1 = 1192466856U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/assert_integral";
  c2_info[39].name = "ne";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved = "[B]ne";
  c2_info[39].fileLength = 0U;
  c2_info[39].fileTime1 = 0U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[40].name = "eml_check_dim";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c2_info[40].fileLength = 1434U;
  c2_info[40].fileTime1 = 1192466768U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context = "";
  c2_info[41].name = "mrdivide";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[41].fileLength = 638U;
  c2_info[41].fileTime1 = 1197300750U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[42].name = "imag";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved = "[B]imag";
  c2_info[42].fileLength = 0U;
  c2_info[42].fileTime1 = 0U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[43].name = "floor";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[43].fileLength = 550U;
  c2_info[43].fileTime1 = 1192466686U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[44].name = "eml_index_plus";
  c2_info[44].dominantType = "int32";
  c2_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[44].fileLength = 272U;
  c2_info[44].fileTime1 = 1192466786U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[45].name = "eml_blas_xswap";
  c2_info[45].dominantType = "int32";
  c2_info[45].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xswap.m";
  c2_info[45].fileLength = 245U;
  c2_info[45].fileTime1 = 1192466864U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[46].name = "eml_xcabs1";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[46].fileLength = 371U;
  c2_info[46].fileTime1 = 1192466830U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[47].name = "lt";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved = "[B]lt";
  c2_info[47].fileLength = 0U;
  c2_info[47].fileTime1 = 0U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[48].name = "eq";
  c2_info[48].dominantType = "double";
  c2_info[48].resolved = "[B]eq";
  c2_info[48].fileLength = 0U;
  c2_info[48].fileTime1 = 0U;
  c2_info[48].fileTime2 = 0U;
  c2_info[49].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[49].name = "eml_min_or_max";
  c2_info[49].dominantType = "int32";
  c2_info[49].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[49].fileLength = 7337U;
  c2_info[49].fileTime1 = 1192466798U;
  c2_info[49].fileTime2 = 0U;
  c2_info[50].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[50].name = "le";
  c2_info[50].dominantType = "double";
  c2_info[50].resolved = "[B]le";
  c2_info[50].fileLength = 0U;
  c2_info[50].fileTime1 = 0U;
  c2_info[50].fileTime2 = 0U;
  c2_info[51].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[51].name = "gt";
  c2_info[51].dominantType = "double";
  c2_info[51].resolved = "[B]gt";
  c2_info[51].fileLength = 0U;
  c2_info[51].fileTime1 = 0U;
  c2_info[51].fileTime2 = 0U;
  c2_info[52].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[52].name = "isempty";
  c2_info[52].dominantType = "double";
  c2_info[52].resolved = "[B]isempty";
  c2_info[52].fileLength = 0U;
  c2_info[52].fileTime1 = 0U;
  c2_info[52].fileTime2 = 0U;
  c2_info[53].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[53].name = "eml_blas_xgemm";
  c2_info[53].dominantType = "int32";
  c2_info[53].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xgemm.m";
  c2_info[53].fileLength = 355U;
  c2_info[53].fileTime1 = 1192466854U;
  c2_info[53].fileTime2 = 0U;
  c2_info[54].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c2_info[54].name = "eml_alloc";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[54].fileLength = 2558U;
  c2_info[54].fileTime1 = 1197300744U;
  c2_info[54].fileTime2 = 0U;
  c2_info[55].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[55].name = "ge";
  c2_info[55].dominantType = "double";
  c2_info[55].resolved = "[B]ge";
  c2_info[55].fileLength = 0U;
  c2_info[55].fileTime1 = 0U;
  c2_info[55].fileTime2 = 0U;
  c2_info[56].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[56].name = "eml_div";
  c2_info[56].dominantType = "double";
  c2_info[56].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[56].fileLength = 4254U;
  c2_info[56].fileTime1 = 1192466772U;
  c2_info[56].fileTime2 = 0U;
  c2_info[57].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[57].name = "eml_all_or_any";
  c2_info[57].dominantType = "char";
  c2_info[57].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[57].fileLength = 3266U;
  c2_info[57].fileTime1 = 1192466764U;
  c2_info[57].fileTime2 = 0U;
  c2_info[58].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xger.m";
  c2_info[58].name = "eml_refblas_xger";
  c2_info[58].dominantType = "int32";
  c2_info[58].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[58].fileLength = 357U;
  c2_info[58].fileTime1 = 1192466876U;
  c2_info[58].fileTime2 = 0U;
  c2_info[59].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[59].name = "eml_blas_xdot";
  c2_info[59].dominantType = "int32";
  c2_info[59].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xdot.m";
  c2_info[59].fileLength = 238U;
  c2_info[59].fileTime1 = 1192466852U;
  c2_info[59].fileTime2 = 0U;
  c2_info[60].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[60].name = "power";
  c2_info[60].dominantType = "double";
  c2_info[60].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[60].fileLength = 4979U;
  c2_info[60].fileTime1 = 1192466920U;
  c2_info[60].fileTime2 = 0U;
  c2_info[61].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c2_info[61].name = "cast";
  c2_info[61].dominantType = "double";
  c2_info[61].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[61].fileLength = 866U;
  c2_info[61].fileTime1 = 1192466644U;
  c2_info[61].fileTime2 = 0U;
  c2_info[62].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c2_info[62].name = "eml_xgetrf";
  c2_info[62].dominantType = "int32";
  c2_info[62].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[62].fileLength = 2211U;
  c2_info[62].fileTime1 = 1192466816U;
  c2_info[62].fileTime2 = 0U;
  c2_info[63].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c2_info[63].name = "eml_blas_xtrsm";
  c2_info[63].dominantType = "int32";
  c2_info[63].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xtrsm.m";
  c2_info[63].fileLength = 333U;
  c2_info[63].fileTime1 = 1192466864U;
  c2_info[63].fileTime2 = 0U;
}

static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[108])
{
  c2_info[64].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[64].name = "eml_index_times";
  c2_info[64].dominantType = "int32";
  c2_info[64].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[64].fileLength = 280U;
  c2_info[64].fileTime1 = 1192466788U;
  c2_info[64].fileTime2 = 0U;
  c2_info[65].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[65].name = "eml_ixamax";
  c2_info[65].dominantType = "int32";
  c2_info[65].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[65].fileLength = 646U;
  c2_info[65].fileTime1 = 1192466828U;
  c2_info[65].fileTime2 = 0U;
  c2_info[66].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_ixamax.m";
  c2_info[66].name = "eml_refblas_ixamax";
  c2_info[66].dominantType = "int32";
  c2_info[66].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[66].fileLength = 740U;
  c2_info[66].fileTime1 = 1192466866U;
  c2_info[66].fileTime2 = 0U;
  c2_info[67].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c2_info[67].name = "eml_lusolve";
  c2_info[67].dominantType = "double";
  c2_info[67].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c2_info[67].fileLength = 824U;
  c2_info[67].fileTime1 = 1195314368U;
  c2_info[67].fileTime2 = 0U;
  c2_info[68].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c2_info[68].name = "ones";
  c2_info[68].dominantType = "char";
  c2_info[68].resolved = "[B]ones";
  c2_info[68].fileLength = 0U;
  c2_info[68].fileTime1 = 0U;
  c2_info[68].fileTime2 = 0U;
  c2_info[69].context = "";
  c2_info[69].name = "mldivide";
  c2_info[69].dominantType = "double";
  c2_info[69].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c2_info[69].fileLength = 844U;
  c2_info[69].fileTime1 = 1197300748U;
  c2_info[69].fileTime2 = 0U;
  c2_info[70].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[70].name = "double";
  c2_info[70].dominantType = "double";
  c2_info[70].resolved = "[B]double";
  c2_info[70].fileLength = 0U;
  c2_info[70].fileTime1 = 0U;
  c2_info[70].fileTime2 = 0U;
  c2_info[71].context = "";
  c2_info[71].name = "inv";
  c2_info[71].dominantType = "double";
  c2_info[71].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[71].fileLength = 4521U;
  c2_info[71].fileTime1 = 1195314410U;
  c2_info[71].fileTime2 = 0U;
  c2_info[72].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[72].name = "times";
  c2_info[72].dominantType = "double";
  c2_info[72].resolved = "[B]times";
  c2_info[72].fileLength = 0U;
  c2_info[72].fileTime1 = 0U;
  c2_info[72].fileTime2 = 0U;
  c2_info[73].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[73].name = "eml_assert";
  c2_info[73].dominantType = "char";
  c2_info[73].resolved = "[B]eml_assert";
  c2_info[73].fileLength = 0U;
  c2_info[73].fileTime1 = 0U;
  c2_info[73].fileTime2 = 0U;
  c2_info[74].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[74].name = "nan";
  c2_info[74].dominantType = "char";
  c2_info[74].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c2_info[74].fileLength = 474U;
  c2_info[74].fileTime1 = 1192466744U;
  c2_info[74].fileTime2 = 0U;
  c2_info[75].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[75].name = "eml_varargin_to_size";
  c2_info[75].dominantType = "double";
  c2_info[75].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_varargin_to_size.m";
  c2_info[75].fileLength = 625U;
  c2_info[75].fileTime1 = 1192466812U;
  c2_info[75].fileTime2 = 0U;
  c2_info[76].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[76].name = "min";
  c2_info[76].dominantType = "int32";
  c2_info[76].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[76].fileLength = 308U;
  c2_info[76].fileTime1 = 1192466634U;
  c2_info[76].fileTime2 = 0U;
  c2_info[77].context = "";
  c2_info[77].name = "ctranspose";
  c2_info[77].dominantType = "double";
  c2_info[77].resolved = "[B]ctranspose";
  c2_info[77].fileLength = 0U;
  c2_info[77].fileTime1 = 0U;
  c2_info[77].fileTime2 = 0U;
  c2_info[78].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[78].name = "islogical";
  c2_info[78].dominantType = "int32";
  c2_info[78].resolved = "[B]islogical";
  c2_info[78].fileLength = 0U;
  c2_info[78].fileTime1 = 0U;
  c2_info[78].fileTime2 = 0U;
  c2_info[79].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[79].name = "class";
  c2_info[79].dominantType = "double";
  c2_info[79].resolved = "[B]class";
  c2_info[79].fileLength = 0U;
  c2_info[79].fileTime1 = 0U;
  c2_info[79].fileTime2 = 0U;
  c2_info[80].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[80].name = "eml_index_minus";
  c2_info[80].dominantType = "int32";
  c2_info[80].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[80].fileLength = 277U;
  c2_info[80].fileTime1 = 1192466784U;
  c2_info[80].fileTime2 = 0U;
  c2_info[81].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[81].name = "eml_nonsingleton_dim";
  c2_info[81].dominantType = "logical";
  c2_info[81].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c2_info[81].fileLength = 404U;
  c2_info[81].fileTime1 = 1192466800U;
  c2_info[81].fileTime2 = 0U;
  c2_info[82].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[82].name = "strcmp";
  c2_info[82].dominantType = "char";
  c2_info[82].resolved = "[B]strcmp";
  c2_info[82].fileLength = 0U;
  c2_info[82].fileTime1 = 0U;
  c2_info[82].fileTime2 = 0U;
  c2_info[83].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xdot.m";
  c2_info[83].name = "eml_refblas_xdot";
  c2_info[83].dominantType = "int32";
  c2_info[83].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[83].fileLength = 299U;
  c2_info[83].fileTime1 = 1192466870U;
  c2_info[83].fileTime2 = 0U;
  c2_info[84].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[84].name = "uminus";
  c2_info[84].dominantType = "double";
  c2_info[84].resolved = "[B]uminus";
  c2_info[84].fileLength = 0U;
  c2_info[84].fileTime1 = 0U;
  c2_info[84].fileTime2 = 0U;
  c2_info[85].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/assert_integral";
  c2_info[85].name = "isinteger";
  c2_info[85].dominantType = "double";
  c2_info[85].resolved = "[B]isinteger";
  c2_info[85].fileLength = 0U;
  c2_info[85].fileTime1 = 0U;
  c2_info[85].fileTime2 = 0U;
  c2_info[86].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[86].name = "isa";
  c2_info[86].dominantType = "double";
  c2_info[86].resolved = "[B]isa";
  c2_info[86].fileLength = 0U;
  c2_info[86].fileTime1 = 0U;
  c2_info[86].fileTime2 = 0U;
  c2_info[87].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[87].name = "eml_xger";
  c2_info[87].dominantType = "int32";
  c2_info[87].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c2_info[87].fileLength = 2019U;
  c2_info[87].fileTime1 = 1192466838U;
  c2_info[87].fileTime2 = 0U;
  c2_info[88].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[88].name = "eml_set_singleton_dim";
  c2_info[88].dominantType = "double";
  c2_info[88].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_set_singleton_dim.m";
  c2_info[88].fileLength = 375U;
  c2_info[88].fileTime1 = 1192466806U;
  c2_info[88].fileTime2 = 0U;
  c2_info[89].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[89].name = "ischar";
  c2_info[89].dominantType = "char";
  c2_info[89].resolved = "[B]ischar";
  c2_info[89].fileLength = 0U;
  c2_info[89].fileTime1 = 0U;
  c2_info[89].fileTime2 = 0U;
  c2_info[90].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c2_info[90].name = "eml_ipiv2perm";
  c2_info[90].dominantType = "int32";
  c2_info[90].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c2_info[90].fileLength = 418U;
  c2_info[90].fileTime1 = 1192466790U;
  c2_info[90].fileTime2 = 0U;
  c2_info[91].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[91].name = "eml_refblas_xdotx";
  c2_info[91].dominantType = "int32";
  c2_info[91].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[91].fileLength = 1780U;
  c2_info[91].fileTime1 = 1195314398U;
  c2_info[91].fileTime2 = 0U;
  c2_info[92].context = "";
  c2_info[92].name = "max";
  c2_info[92].dominantType = "double";
  c2_info[92].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[92].fileLength = 308U;
  c2_info[92].fileTime1 = 1192466630U;
  c2_info[92].fileTime2 = 0U;
  c2_info[93].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[93].name = "eml_error";
  c2_info[93].dominantType = "char";
  c2_info[93].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[93].fileLength = 318U;
  c2_info[93].fileTime1 = 1192466776U;
  c2_info[93].fileTime2 = 0U;
  c2_info[94].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/assert_integral";
  c2_info[94].name = "true";
  c2_info[94].dominantType = "";
  c2_info[94].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c2_info[94].fileLength = 237U;
  c2_info[94].fileTime1 = 1192466762U;
  c2_info[94].fileTime2 = 0U;
  c2_info[95].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xtrsm.m";
  c2_info[95].name = "eml_refblas_xtrsm";
  c2_info[95].dominantType = "int32";
  c2_info[95].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[95].fileLength = 8422U;
  c2_info[95].fileTime1 = 1195314406U;
  c2_info[95].fileTime2 = 0U;
  c2_info[96].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[96].name = "zeros";
  c2_info[96].dominantType = "double";
  c2_info[96].resolved = "[B]zeros";
  c2_info[96].fileLength = 0U;
  c2_info[96].fileTime1 = 0U;
  c2_info[96].fileTime2 = 0U;
  c2_info[97].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[97].name = "ndims";
  c2_info[97].dominantType = "double";
  c2_info[97].resolved = "[B]ndims";
  c2_info[97].fileLength = 0U;
  c2_info[97].fileTime1 = 0U;
  c2_info[97].fileTime2 = 0U;
  c2_info[98].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c2_info[98].name = "eml_xgeru";
  c2_info[98].dominantType = "int32";
  c2_info[98].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[98].fileLength = 2305U;
  c2_info[98].fileTime1 = 1192466840U;
  c2_info[98].fileTime2 = 0U;
  c2_info[99].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[99].name = "eml_assert_valid_size_arg";
  c2_info[99].dominantType = "double";
  c2_info[99].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[99].fileLength = 1360U;
  c2_info[99].fileTime1 = 1192466766U;
  c2_info[99].fileTime2 = 0U;
  c2_info[100].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c2_info[100].name = "eml_warning";
  c2_info[100].dominantType = "char";
  c2_info[100].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[100].fileLength = 265U;
  c2_info[100].fileTime1 = 1192466814U;
  c2_info[100].fileTime2 = 0U;
  c2_info[101].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c2_info[101].name = "realmax";
  c2_info[101].dominantType = "";
  c2_info[101].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[101].fileLength = 498U;
  c2_info[101].fileTime1 = 1192466750U;
  c2_info[101].fileTime2 = 0U;
  c2_info[102].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/mat1norm";
  c2_info[102].name = "eml_guarded_nan";
  c2_info[102].dominantType = "char";
  c2_info[102].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[102].fileLength = 485U;
  c2_info[102].fileTime1 = 1192466780U;
  c2_info[102].fileTime2 = 0U;
  c2_info[103].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m/binary_isequal";
  c2_info[103].name = "all";
  c2_info[103].dominantType = "logical";
  c2_info[103].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c2_info[103].fileLength = 400U;
  c2_info[103].fileTime1 = 1192466904U;
  c2_info[103].fileTime2 = 0U;
  c2_info[104].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[104].name = "isvector";
  c2_info[104].dominantType = "double";
  c2_info[104].resolved = "[B]isvector";
  c2_info[104].fileLength = 0U;
  c2_info[104].fileTime1 = 0U;
  c2_info[104].fileTime2 = 0U;
  c2_info[105].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[105].name = "isreal";
  c2_info[105].dominantType = "double";
  c2_info[105].resolved = "[B]isreal";
  c2_info[105].fileLength = 0U;
  c2_info[105].fileTime1 = 0U;
  c2_info[105].fileTime2 = 0U;
  c2_info[106].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[106].name = "rdivide";
  c2_info[106].dominantType = "double";
  c2_info[106].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[106].fileLength = 628U;
  c2_info[106].fileTime1 = 1192466922U;
  c2_info[106].fileTime2 = 0U;
  c2_info[107].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c2_info[107].name = "norm";
  c2_info[107].dominantType = "double";
  c2_info[107].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[107].fileLength = 5060U;
  c2_info[107].fileTime1 = 1192466896U;
  c2_info[107].fileTime2 = 0U;
}

static void c2_mul_wide_s32(int32_T c2_in0, int32_T c2_in1, uint32_T
  *c2_ptrOutBitsHi, uint32_T *c2_ptrOutBitsLo)
{
  uint32_T c2_absIn0;
  uint32_T c2_absIn1;
  int32_T c2_negativeProduct;
  uint32_T c2_in0Hi;
  uint32_T c2_in0Lo;
  uint32_T c2_in1Hi;
  uint32_T c2_in1Lo;
  uint32_T c2_productHiHi;
  uint32_T c2_productHiLo;
  uint32_T c2_productLoHi;
  uint32_T c2_productLoLo;
  uint32_T c2_carry;
  uint32_T c2_outBitsLo;
  uint32_T c2_outBitsHi;
  c2_absIn0 = (uint32_T)(c2_in0 < 0 ? -c2_in0 : c2_in0);
  c2_absIn1 = (uint32_T)(c2_in1 < 0 ? -c2_in1 : c2_in1);
  c2_negativeProduct = !((c2_in0 == 0) || (c2_in1 == 0) || (c2_in0 > 0 == c2_in1
    > 0));
  c2_in0Hi = c2_absIn0 >> 16;
  c2_in0Lo = c2_absIn0 & 65535U;
  c2_in1Hi = c2_absIn1 >> 16;
  c2_in1Lo = c2_absIn1 & 65535U;
  c2_productHiHi = c2_in0Hi * c2_in1Hi;
  c2_productHiLo = c2_in0Hi * c2_in1Lo;
  c2_productLoHi = c2_in0Lo * c2_in1Hi;
  c2_productLoLo = c2_in0Lo * c2_in1Lo;
  c2_carry = (uint32_T)0;
  c2_outBitsLo = c2_productLoLo + (c2_productLoHi << 16);
  if (c2_outBitsLo < c2_productLoLo) {
    c2_carry++;
  }

  c2_productLoLo = c2_outBitsLo;
  c2_outBitsLo = (uint32_T)(c2_outBitsLo + (c2_productHiLo << 16));
  if (c2_outBitsLo < c2_productLoLo) {
    c2_carry++;
  }

  c2_outBitsHi = ((c2_carry + c2_productHiHi) + (c2_productLoHi >> 16)) +
    (c2_productHiLo >> 16);
  if (c2_negativeProduct) {
    c2_outBitsHi = ~c2_outBitsHi;
    c2_outBitsLo = ~c2_outBitsLo;
    c2_outBitsLo++;
    if (c2_outBitsLo == (uint32_T)0) {
      c2_outBitsHi++;
    }
  }

  *c2_ptrOutBitsHi = c2_outBitsHi;
  *c2_ptrOutBitsLo = c2_outBitsLo;
}

static int32_T c2_mul_s32_s32_s32_sat(int32_T c2_a, int32_T c2_b)
{
  uint32_T c2_u32_clo;
  uint32_T c2_u32_chi;
  c2_mul_wide_s32(c2_a, c2_b, &c2_u32_chi, &c2_u32_clo);
  if (((int32_T)c2_u32_chi > 0) || ((c2_u32_chi == (uint32_T)0) && (c2_u32_clo >=
        2147483648U))) {
    return MAX_int32_T;
  } else if (((int32_T)c2_u32_chi < -1) || (((int32_T)c2_u32_chi == -1) &&
              (c2_u32_clo < 2147483648U))) {
    return MIN_int32_T;
  } else {
    return (int32_T)c2_u32_clo;
  }
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_MPC_AVC_implementation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3848961471U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(833016863U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(816346316U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2847218576U);
}

mxArray *sf_c2_MPC_AVC_implementation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2099789788U);
    pr[1] = (double)(3080370370U);
    pr[2] = (double)(3193390112U);
    pr[3] = (double)(1461141214U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(10);
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
      pr[0] = (double)(10);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(10);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "aliasId", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "aliasId", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(10);
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
           2,
           1,
           1,
           5,
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
            unsigned int dimVector[2];
            dimVector[0]= 10;
            dimVector[1]= 10;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"omega",0,c2_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 10;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"eta",0,NULL);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 10;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"f",0,c2_b_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 4;
            dimVector[1]= 10;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"A_cons",0,c2_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"b",0,c2_d_sf_marshall);
          }

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
        _SFD_CV_INIT_EML(0,1,3,0,3,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,789);
        _SFD_CV_INIT_EML_IF(0,0,121,146,169,198);
        _SFD_CV_INIT_EML_IF(0,1,203,213,-1,-2);
        _SFD_CV_INIT_EML_IF(0,2,712,725,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,0,106,117,202);
        _SFD_CV_INIT_EML_FOR(0,1,335,347,753);
        _SFD_CV_INIT_EML_FOR(0,2,522,532,657);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c2_omega)[100];
          real_T (*c2_eta)[10];
          real_T (*c2_f)[10];
          real_T (*c2_A_cons)[40];
          real_T (*c2_b)[4];
          c2_eta = (real_T (*)[10])ssGetOutputPortSignal(chartInstance.S, 1);
          c2_b = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 3);
          c2_omega = (real_T (*)[100])ssGetInputPortSignal(chartInstance.S, 0);
          c2_A_cons = (real_T (*)[40])ssGetInputPortSignal(chartInstance.S, 2);
          c2_f = (real_T (*)[10])ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_omega);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_eta);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_f);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_A_cons);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_b);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_MPC_AVC_implementationMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_MPC_AVC_implementation(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_MPC_AVC_implementation();
  initialize_c2_MPC_AVC_implementation();
}

static void sf_opaque_enable_c2_MPC_AVC_implementation(void *chartInstanceVar)
{
  enable_c2_MPC_AVC_implementation();
}

static void sf_opaque_disable_c2_MPC_AVC_implementation(void *chartInstanceVar)
{
  disable_c2_MPC_AVC_implementation();
}

static void sf_opaque_gateway_c2_MPC_AVC_implementation(void *chartInstanceVar)
{
  sf_c2_MPC_AVC_implementation();
}

static void sf_opaque_terminate_c2_MPC_AVC_implementation(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_MPC_AVC_implementation();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_MPC_AVC_implementation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_MPC_AVC_implementation();
  }
}

static void mdlSetWorkWidths_c2_MPC_AVC_implementation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("MPC_AVC_implementation",
      "MPC_AVC_implementation",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("MPC_AVC_implementation",
                "MPC_AVC_implementation",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("MPC_AVC_implementation",
      "MPC_AVC_implementation",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MPC_AVC_implementation",
        "MPC_AVC_implementation",2,4);
      sf_mark_chart_reusable_outputs(S,"MPC_AVC_implementation",
        "MPC_AVC_implementation",2,1);
    }

    sf_set_rtw_dwork_info(S,"MPC_AVC_implementation","MPC_AVC_implementation",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(4132344480U));
  ssSetChecksum1(S,(3735847161U));
  ssSetChecksum2(S,(3200044047U));
  ssSetChecksum3(S,(2496251264U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_MPC_AVC_implementation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "MPC_AVC_implementation",
      "MPC_AVC_implementation",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_MPC_AVC_implementation(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_MPC_AVC_implementation;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_MPC_AVC_implementation;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_MPC_AVC_implementation;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_MPC_AVC_implementation;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_MPC_AVC_implementation;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_MPC_AVC_implementation;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_MPC_AVC_implementation;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_MPC_AVC_implementation;
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

void c2_MPC_AVC_implementation_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_MPC_AVC_implementation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_MPC_AVC_implementation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_MPC_AVC_implementation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_MPC_AVC_implementation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
