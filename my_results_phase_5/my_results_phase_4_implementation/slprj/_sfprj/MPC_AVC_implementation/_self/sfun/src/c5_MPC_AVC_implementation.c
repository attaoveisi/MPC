/* Include files */

#include "MPC_AVC_implementation_sfun.h"
#include "c5_MPC_AVC_implementation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "MPC_AVC_implementation_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc5_MPC_AVC_implementationInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c5_MPC_AVC_implementation(void);
static void initialize_params_c5_MPC_AVC_implementation(void);
static void enable_c5_MPC_AVC_implementation(void);
static void disable_c5_MPC_AVC_implementation(void);
static void finalize_c5_MPC_AVC_implementation(void);
static void sf_c5_MPC_AVC_implementation(void);
static void c5_c5_MPC_AVC_implementation(void);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static void c5_mrdivide(real_T c5_A[6], real_T c5_B[36], real_T c5_y[6]);
static void c5_eml_xgetrf(real_T c5_A[36], real_T c5_b_A[36], int32_T c5_ipiv[6],
  int32_T *c5_info);
static void c5_eml_warning(void);
static real_T c5_eye(void);
static const mxArray *c5_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_b_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_c_sf_marshall(void *c5_chartInstance, void *c5_u);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[97]);
static void c5_b_info_helper(c5_ResolvedFunctionInfo c5_info[97]);
static void c5_mul_wide_s32(int32_T c5_in0, int32_T c5_in1, uint32_T
  *c5_ptrOutBitsHi, uint32_T *c5_ptrOutBitsLo);
static int32_T c5_mul_s32_s32_s32_sat(int32_T c5_a, int32_T c5_b);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c5_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c5_is_active_c5_MPC_AVC_implementation = 0U;
}

static void initialize_params_c5_MPC_AVC_implementation(void)
{
}

static void enable_c5_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c5_MPC_AVC_implementation(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void finalize_c5_MPC_AVC_implementation(void)
{
}

static void sf_c5_MPC_AVC_implementation(void)
{
  int32_T c5_i0;
  int32_T c5_i1;
  uint8_T c5_previousEvent;
  real_T *c5_kk;
  real_T *c5_Ps0;
  real_T *c5_Psn;
  real_T *c5_Rs;
  real_T *c5_theta1;
  real_T *c5_theta;
  real_T *c5_Ps1;
  real_T (*c5_H)[6];
  real_T (*c5_V)[6];
  c5_H = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
  c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c5_Rs = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c5_kk = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c5_theta1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c5_Psn = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c5_Ps1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c5_V = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 6);
  c5_Ps0 = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,3);
  _SFD_DATA_RANGE_CHECK(*c5_kk, 0U);
  for (c5_i0 = 0; c5_i0 < 6; c5_i0 = c5_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_H)[c5_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_Ps0, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_Psn, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_Rs, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_theta1, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_theta, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_Ps1, 7U);
  for (c5_i1 = 0; c5_i1 < 6; c5_i1 = c5_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_V)[c5_i1], 8U);
  }

  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c5_c5_MPC_AVC_implementation();
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_MPC_AVC_implementationMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void c5_c5_MPC_AVC_implementation(void)
{
  real_T c5_kk;
  int32_T c5_i2;
  real_T c5_H[6];
  real_T c5_Ps0;
  real_T c5_Psn;
  real_T c5_Rs;
  real_T c5_theta1;
  int32_T c5_i3;
  real_T c5_V[6];
  real_T c5_nargout = 2.0;
  real_T c5_nargin = 7.0;
  real_T c5_Ks[6];
  real_T c5_Ps;
  real_T c5_Ps1;
  real_T c5_theta;
  int32_T c5_i4;
  real_T c5_a[6];
  real_T c5_b;
  int32_T c5_i5;
  real_T c5_b_a[6];
  int32_T c5_i6;
  real_T c5_b_b[6];
  int32_T c5_i7;
  int32_T c5_i8;
  real_T c5_y[36];
  real_T c5_c_a;
  int32_T c5_i9;
  real_T c5_c_b[6];
  int32_T c5_i10;
  real_T c5_b_y[6];
  int32_T c5_i11;
  real_T c5_c_y[6];
  int32_T c5_i12;
  int32_T c5_i13;
  real_T c5_d_y[36];
  real_T c5_dv0[6];
  int32_T c5_i14;
  int32_T c5_i15;
  real_T c5_d_a[6];
  int32_T c5_i16;
  real_T c5_e_a[6];
  real_T c5_d_b;
  int32_T c5_i17;
  real_T c5_e_y[6];
  int32_T c5_i18;
  real_T c5_e_b[6];
  int32_T c5_i19;
  real_T c5_x[6];
  int32_T c5_i20;
  real_T c5_f_y[6];
  int32_T c5_i21;
  real_T c5_b_x[6];
  int32_T c5_i22;
  real_T c5_g_y[6];
  int32_T c5_i23;
  real_T c5_c_x[6];
  int32_T c5_i24;
  real_T c5_h_y[6];
  int32_T c5_i25;
  real_T c5_d_x[6];
  int32_T c5_i26;
  real_T c5_i_y[6];
  int32_T c5_i27;
  real_T c5_e_x[6];
  int32_T c5_i28;
  real_T c5_j_y[6];
  real_T c5_f_x;
  real_T c5_k_y;
  int32_T c5_i29;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_i30;
  real_T c5_f_a[6];
  real_T c5_f_b;
  int32_T c5_i31;
  real_T c5_g_a[6];
  int32_T c5_i32;
  real_T c5_g_b[6];
  int32_T c5_i33;
  real_T c5_g_x[6];
  int32_T c5_i34;
  real_T c5_l_y[6];
  int32_T c5_i35;
  real_T c5_h_x[6];
  int32_T c5_i36;
  real_T c5_m_y[6];
  int32_T c5_i37;
  real_T c5_i_x[6];
  int32_T c5_i38;
  real_T c5_n_y[6];
  int32_T c5_i39;
  real_T c5_j_x[6];
  int32_T c5_i40;
  real_T c5_o_y[6];
  int32_T c5_i41;
  real_T c5_k_x[6];
  int32_T c5_i42;
  real_T c5_p_y[6];
  real_T c5_l_x;
  real_T c5_q_y;
  int32_T c5_i43;
  int32_T c5_c_k;
  int32_T c5_d_k;
  int32_T c5_i44;
  real_T c5_h_a[6];
  int32_T c5_i45;
  real_T c5_h_b[6];
  int32_T c5_i46;
  real_T c5_m_x[6];
  int32_T c5_i47;
  real_T c5_r_y[6];
  int32_T c5_i48;
  real_T c5_n_x[6];
  int32_T c5_i49;
  real_T c5_s_y[6];
  int32_T c5_i50;
  real_T c5_o_x[6];
  int32_T c5_i51;
  real_T c5_t_y[6];
  int32_T c5_i52;
  real_T c5_p_x[6];
  int32_T c5_i53;
  real_T c5_u_y[6];
  int32_T c5_i54;
  real_T c5_q_x[6];
  int32_T c5_i55;
  real_T c5_v_y[6];
  real_T c5_r_x;
  real_T c5_w_y;
  int32_T c5_i56;
  int32_T c5_e_k;
  int32_T c5_f_k;
  real_T c5_i_a;
  real_T c5_i_b;
  real_T c5_j_a;
  int32_T c5_i57;
  real_T c5_k_a[6];
  int32_T c5_i58;
  real_T c5_j_b[6];
  int32_T c5_i59;
  real_T c5_s_x[6];
  int32_T c5_i60;
  real_T c5_x_y[6];
  int32_T c5_i61;
  real_T c5_t_x[6];
  int32_T c5_i62;
  real_T c5_y_y[6];
  int32_T c5_i63;
  real_T c5_u_x[6];
  int32_T c5_i64;
  real_T c5_ab_y[6];
  int32_T c5_i65;
  real_T c5_v_x[6];
  int32_T c5_i66;
  real_T c5_bb_y[6];
  int32_T c5_i67;
  real_T c5_w_x[6];
  int32_T c5_i68;
  real_T c5_cb_y[6];
  real_T c5_x_x;
  real_T c5_db_y;
  int32_T c5_i69;
  int32_T c5_g_k;
  int32_T c5_h_k;
  real_T c5_k_b;
  real_T c5_eb_y;
  int32_T c5_i70;
  real_T c5_l_a[6];
  real_T c5_l_b;
  int32_T c5_i71;
  real_T c5_m_a[6];
  int32_T c5_i72;
  real_T c5_m_b[6];
  int32_T c5_i73;
  int32_T c5_i74;
  real_T c5_fb_y[36];
  real_T c5_n_a;
  int32_T c5_i75;
  real_T c5_n_b[6];
  int32_T c5_i76;
  real_T c5_gb_y[6];
  int32_T c5_i77;
  real_T c5_hb_y[6];
  int32_T c5_i78;
  int32_T c5_i79;
  real_T c5_ib_y[36];
  real_T c5_dv1[6];
  int32_T c5_i80;
  int32_T c5_i81;
  real_T c5_o_a[6];
  int32_T c5_i82;
  real_T c5_p_a[6];
  real_T c5_o_b;
  int32_T c5_i83;
  real_T c5_jb_y[6];
  int32_T c5_i84;
  real_T c5_p_b[6];
  int32_T c5_i85;
  real_T c5_y_x[6];
  int32_T c5_i86;
  real_T c5_kb_y[6];
  int32_T c5_i87;
  real_T c5_ab_x[6];
  int32_T c5_i88;
  real_T c5_lb_y[6];
  int32_T c5_i89;
  real_T c5_bb_x[6];
  int32_T c5_i90;
  real_T c5_mb_y[6];
  int32_T c5_i91;
  real_T c5_cb_x[6];
  int32_T c5_i92;
  real_T c5_nb_y[6];
  int32_T c5_i93;
  real_T c5_db_x[6];
  int32_T c5_i94;
  real_T c5_ob_y[6];
  real_T c5_eb_x;
  real_T c5_pb_y;
  int32_T c5_i95;
  int32_T c5_i_k;
  int32_T c5_j_k;
  int32_T c5_i96;
  real_T c5_q_a[6];
  real_T c5_q_b;
  int32_T c5_i97;
  real_T c5_r_a[6];
  int32_T c5_i98;
  real_T c5_r_b[6];
  int32_T c5_i99;
  real_T c5_fb_x[6];
  int32_T c5_i100;
  real_T c5_qb_y[6];
  int32_T c5_i101;
  real_T c5_gb_x[6];
  int32_T c5_i102;
  real_T c5_rb_y[6];
  int32_T c5_i103;
  real_T c5_hb_x[6];
  int32_T c5_i104;
  real_T c5_sb_y[6];
  int32_T c5_i105;
  real_T c5_ib_x[6];
  int32_T c5_i106;
  real_T c5_tb_y[6];
  int32_T c5_i107;
  real_T c5_jb_x[6];
  int32_T c5_i108;
  real_T c5_ub_y[6];
  real_T c5_kb_x;
  real_T c5_vb_y;
  int32_T c5_i109;
  int32_T c5_k_k;
  int32_T c5_l_k;
  int32_T c5_i110;
  real_T c5_s_a[6];
  int32_T c5_i111;
  real_T c5_s_b[6];
  int32_T c5_i112;
  real_T c5_lb_x[6];
  int32_T c5_i113;
  real_T c5_wb_y[6];
  int32_T c5_i114;
  real_T c5_mb_x[6];
  int32_T c5_i115;
  real_T c5_xb_y[6];
  int32_T c5_i116;
  real_T c5_nb_x[6];
  int32_T c5_i117;
  real_T c5_yb_y[6];
  int32_T c5_i118;
  real_T c5_ob_x[6];
  int32_T c5_i119;
  real_T c5_ac_y[6];
  int32_T c5_i120;
  real_T c5_pb_x[6];
  int32_T c5_i121;
  real_T c5_bc_y[6];
  real_T c5_qb_x;
  real_T c5_cc_y;
  int32_T c5_i122;
  int32_T c5_m_k;
  int32_T c5_n_k;
  real_T c5_t_a;
  real_T c5_t_b;
  real_T c5_u_a;
  int32_T c5_i123;
  real_T c5_v_a[6];
  int32_T c5_i124;
  real_T c5_u_b[6];
  int32_T c5_i125;
  real_T c5_rb_x[6];
  int32_T c5_i126;
  real_T c5_dc_y[6];
  int32_T c5_i127;
  real_T c5_sb_x[6];
  int32_T c5_i128;
  real_T c5_ec_y[6];
  int32_T c5_i129;
  real_T c5_tb_x[6];
  int32_T c5_i130;
  real_T c5_fc_y[6];
  int32_T c5_i131;
  real_T c5_ub_x[6];
  int32_T c5_i132;
  real_T c5_gc_y[6];
  int32_T c5_i133;
  real_T c5_vb_x[6];
  int32_T c5_i134;
  real_T c5_hc_y[6];
  real_T c5_wb_x;
  real_T c5_ic_y;
  int32_T c5_i135;
  int32_T c5_o_k;
  int32_T c5_p_k;
  real_T c5_one;
  real_T c5_I;
  real_T c5_v_b;
  real_T c5_jc_y;
  real_T *c5_b_Ps1;
  real_T *c5_b_theta;
  real_T *c5_b_theta1;
  real_T *c5_b_Rs;
  real_T *c5_b_Psn;
  real_T *c5_b_Ps0;
  real_T *c5_b_kk;
  real_T (*c5_b_H)[6];
  real_T (*c5_b_V)[6];
  c5_b_H = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
  c5_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c5_b_Rs = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c5_b_kk = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c5_b_theta1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c5_b_Psn = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c5_b_Ps1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c5_b_V = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 6);
  c5_b_Ps0 = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  c5_kk = *c5_b_kk;
  for (c5_i2 = 0; c5_i2 < 6; c5_i2 = c5_i2 + 1) {
    c5_H[c5_i2] = (*c5_b_H)[c5_i2];
  }

  c5_Ps0 = *c5_b_Ps0;
  c5_Psn = *c5_b_Psn;
  c5_Rs = *c5_b_Rs;
  c5_theta1 = *c5_b_theta1;
  for (c5_i3 = 0; c5_i3 < 6; c5_i3 = c5_i3 + 1) {
    c5_V[c5_i3] = (*c5_b_V)[c5_i3];
  }

  sf_debug_symbol_scope_push(13U, 0U);
  sf_debug_symbol_scope_add_verbose("nargout", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
    0U, 0, 0U, 0, 0, &c5_nargout);
  sf_debug_symbol_scope_add_verbose("nargin", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
    0, 0U, 0, 0, &c5_nargin);
  sf_debug_symbol_scope_add("Ks", &c5_Ks, c5_c_sf_marshall);
  sf_debug_symbol_scope_add("Ps", &c5_Ps, c5_sf_marshall);
  sf_debug_symbol_scope_add("Ps1", &c5_Ps1, c5_sf_marshall);
  sf_debug_symbol_scope_add("theta", &c5_theta, c5_sf_marshall);
  sf_debug_symbol_scope_add("V", &c5_V, c5_b_sf_marshall);
  sf_debug_symbol_scope_add("theta1", &c5_theta1, c5_sf_marshall);
  sf_debug_symbol_scope_add("Rs", &c5_Rs, c5_sf_marshall);
  sf_debug_symbol_scope_add("Psn", &c5_Psn, c5_sf_marshall);
  sf_debug_symbol_scope_add("Ps0", &c5_Ps0, c5_sf_marshall);
  sf_debug_symbol_scope_add("H", &c5_H, c5_b_sf_marshall);
  sf_debug_symbol_scope_add("kk", &c5_kk, c5_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  if (CV_EML_IF(0, 0, c5_kk == 1.0)) {
    _SFD_EML_CALL(0,4);
    c5_Ps = c5_Ps0;
    _SFD_EML_CALL(0,5);
    for (c5_i4 = 0; c5_i4 < 6; c5_i4 = c5_i4 + 1) {
      c5_a[c5_i4] = c5_H[c5_i4];
    }

    c5_b = c5_Ps;
    for (c5_i5 = 0; c5_i5 < 6; c5_i5 = c5_i5 + 1) {
      c5_b_a[c5_i5] = c5_a[c5_i5] * c5_b;
    }

    for (c5_i6 = 0; c5_i6 < 6; c5_i6 = c5_i6 + 1) {
      c5_b_b[c5_i6] = c5_H[c5_i6];
    }

    for (c5_i7 = 0; c5_i7 < 6; c5_i7 = c5_i7 + 1) {
      for (c5_i8 = 0; c5_i8 < 6; c5_i8 = c5_i8 + 1) {
        c5_y[c5_i8 + 6 * c5_i7] = c5_b_a[c5_i8] * c5_b_b[c5_i7];
      }
    }

    c5_c_a = c5_Ps;
    for (c5_i9 = 0; c5_i9 < 6; c5_i9 = c5_i9 + 1) {
      c5_c_b[c5_i9] = c5_H[c5_i9];
    }

    for (c5_i10 = 0; c5_i10 < 6; c5_i10 = c5_i10 + 1) {
      c5_b_y[c5_i10] = c5_c_a * c5_c_b[c5_i10];
    }

    for (c5_i11 = 0; c5_i11 < 6; c5_i11 = c5_i11 + 1) {
      c5_c_y[c5_i11] = c5_b_y[c5_i11];
    }

    for (c5_i12 = 0; c5_i12 < 6; c5_i12 = c5_i12 + 1) {
      for (c5_i13 = 0; c5_i13 < 6; c5_i13 = c5_i13 + 1) {
        c5_d_y[c5_i13 + 6 * c5_i12] = c5_y[c5_i13 + 6 * c5_i12] + c5_Rs;
      }
    }

    c5_mrdivide(c5_c_y, c5_d_y, c5_dv0);
    for (c5_i14 = 0; c5_i14 < 6; c5_i14 = c5_i14 + 1) {
      c5_Ks[c5_i14] = c5_dv0[c5_i14];
    }

    _SFD_EML_CALL(0,6);
    for (c5_i15 = 0; c5_i15 < 6; c5_i15 = c5_i15 + 1) {
      c5_d_a[c5_i15] = c5_Ks[c5_i15];
    }

    for (c5_i16 = 0; c5_i16 < 6; c5_i16 = c5_i16 + 1) {
      c5_e_a[c5_i16] = c5_H[c5_i16];
    }

    c5_d_b = c5_theta1;
    for (c5_i17 = 0; c5_i17 < 6; c5_i17 = c5_i17 + 1) {
      c5_e_y[c5_i17] = c5_e_a[c5_i17] * c5_d_b;
    }

    for (c5_i18 = 0; c5_i18 < 6; c5_i18 = c5_i18 + 1) {
      c5_e_b[c5_i18] = c5_V[c5_i18] - c5_e_y[c5_i18];
    }

    for (c5_i19 = 0; c5_i19 < 6; c5_i19 = c5_i19 + 1) {
      c5_x[c5_i19] = c5_d_a[c5_i19];
    }

    for (c5_i20 = 0; c5_i20 < 6; c5_i20 = c5_i20 + 1) {
      c5_f_y[c5_i20] = c5_e_b[c5_i20];
    }

    for (c5_i21 = 0; c5_i21 < 6; c5_i21 = c5_i21 + 1) {
      c5_b_x[c5_i21] = c5_x[c5_i21];
    }

    for (c5_i22 = 0; c5_i22 < 6; c5_i22 = c5_i22 + 1) {
      c5_g_y[c5_i22] = c5_f_y[c5_i22];
    }

    for (c5_i23 = 0; c5_i23 < 6; c5_i23 = c5_i23 + 1) {
      c5_c_x[c5_i23] = c5_b_x[c5_i23];
    }

    for (c5_i24 = 0; c5_i24 < 6; c5_i24 = c5_i24 + 1) {
      c5_h_y[c5_i24] = c5_g_y[c5_i24];
    }

    for (c5_i25 = 0; c5_i25 < 6; c5_i25 = c5_i25 + 1) {
      c5_d_x[c5_i25] = c5_c_x[c5_i25];
    }

    for (c5_i26 = 0; c5_i26 < 6; c5_i26 = c5_i26 + 1) {
      c5_i_y[c5_i26] = c5_h_y[c5_i26];
    }

    for (c5_i27 = 0; c5_i27 < 6; c5_i27 = c5_i27 + 1) {
      c5_e_x[c5_i27] = c5_d_x[c5_i27];
    }

    for (c5_i28 = 0; c5_i28 < 6; c5_i28 = c5_i28 + 1) {
      c5_j_y[c5_i28] = c5_i_y[c5_i28];
    }

    c5_f_x = 0.0;
    c5_k_y = c5_f_x;
    c5_i29 = 1;
    for (c5_k = c5_i29; c5_k < 7; c5_k = c5_k + 1) {
      c5_b_k = c5_k;
      c5_k_y = c5_k_y + c5_e_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c5_b_k), 1, 6, 1, 0) - 1] *
        c5_j_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c5_b_k), 1, 6, 1, 0) - 1];
    }

    c5_theta = c5_theta1 + c5_k_y;
    _SFD_EML_CALL(0,7);
    for (c5_i30 = 0; c5_i30 < 6; c5_i30 = c5_i30 + 1) {
      c5_f_a[c5_i30] = c5_Ks[c5_i30];
    }

    c5_f_b = c5_Rs;
    for (c5_i31 = 0; c5_i31 < 6; c5_i31 = c5_i31 + 1) {
      c5_g_a[c5_i31] = c5_f_a[c5_i31] * c5_f_b;
    }

    for (c5_i32 = 0; c5_i32 < 6; c5_i32 = c5_i32 + 1) {
      c5_g_b[c5_i32] = c5_Ks[c5_i32];
    }

    for (c5_i33 = 0; c5_i33 < 6; c5_i33 = c5_i33 + 1) {
      c5_g_x[c5_i33] = c5_g_a[c5_i33];
    }

    for (c5_i34 = 0; c5_i34 < 6; c5_i34 = c5_i34 + 1) {
      c5_l_y[c5_i34] = c5_g_b[c5_i34];
    }

    for (c5_i35 = 0; c5_i35 < 6; c5_i35 = c5_i35 + 1) {
      c5_h_x[c5_i35] = c5_g_x[c5_i35];
    }

    for (c5_i36 = 0; c5_i36 < 6; c5_i36 = c5_i36 + 1) {
      c5_m_y[c5_i36] = c5_l_y[c5_i36];
    }

    for (c5_i37 = 0; c5_i37 < 6; c5_i37 = c5_i37 + 1) {
      c5_i_x[c5_i37] = c5_h_x[c5_i37];
    }

    for (c5_i38 = 0; c5_i38 < 6; c5_i38 = c5_i38 + 1) {
      c5_n_y[c5_i38] = c5_m_y[c5_i38];
    }

    for (c5_i39 = 0; c5_i39 < 6; c5_i39 = c5_i39 + 1) {
      c5_j_x[c5_i39] = c5_i_x[c5_i39];
    }

    for (c5_i40 = 0; c5_i40 < 6; c5_i40 = c5_i40 + 1) {
      c5_o_y[c5_i40] = c5_n_y[c5_i40];
    }

    for (c5_i41 = 0; c5_i41 < 6; c5_i41 = c5_i41 + 1) {
      c5_k_x[c5_i41] = c5_j_x[c5_i41];
    }

    for (c5_i42 = 0; c5_i42 < 6; c5_i42 = c5_i42 + 1) {
      c5_p_y[c5_i42] = c5_o_y[c5_i42];
    }

    c5_l_x = 0.0;
    c5_q_y = c5_l_x;
    c5_i43 = 1;
    for (c5_c_k = c5_i43; c5_c_k < 7; c5_c_k = c5_c_k + 1) {
      c5_d_k = c5_c_k;
      c5_q_y = c5_q_y + c5_k_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c5_d_k), 1, 6, 1, 0) - 1] *
        c5_p_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c5_d_k), 1, 6, 1, 0) - 1];
    }

    for (c5_i44 = 0; c5_i44 < 6; c5_i44 = c5_i44 + 1) {
      c5_h_a[c5_i44] = c5_Ks[c5_i44];
    }

    for (c5_i45 = 0; c5_i45 < 6; c5_i45 = c5_i45 + 1) {
      c5_h_b[c5_i45] = c5_H[c5_i45];
    }

    for (c5_i46 = 0; c5_i46 < 6; c5_i46 = c5_i46 + 1) {
      c5_m_x[c5_i46] = c5_h_a[c5_i46];
    }

    for (c5_i47 = 0; c5_i47 < 6; c5_i47 = c5_i47 + 1) {
      c5_r_y[c5_i47] = c5_h_b[c5_i47];
    }

    for (c5_i48 = 0; c5_i48 < 6; c5_i48 = c5_i48 + 1) {
      c5_n_x[c5_i48] = c5_m_x[c5_i48];
    }

    for (c5_i49 = 0; c5_i49 < 6; c5_i49 = c5_i49 + 1) {
      c5_s_y[c5_i49] = c5_r_y[c5_i49];
    }

    for (c5_i50 = 0; c5_i50 < 6; c5_i50 = c5_i50 + 1) {
      c5_o_x[c5_i50] = c5_n_x[c5_i50];
    }

    for (c5_i51 = 0; c5_i51 < 6; c5_i51 = c5_i51 + 1) {
      c5_t_y[c5_i51] = c5_s_y[c5_i51];
    }

    for (c5_i52 = 0; c5_i52 < 6; c5_i52 = c5_i52 + 1) {
      c5_p_x[c5_i52] = c5_o_x[c5_i52];
    }

    for (c5_i53 = 0; c5_i53 < 6; c5_i53 = c5_i53 + 1) {
      c5_u_y[c5_i53] = c5_t_y[c5_i53];
    }

    for (c5_i54 = 0; c5_i54 < 6; c5_i54 = c5_i54 + 1) {
      c5_q_x[c5_i54] = c5_p_x[c5_i54];
    }

    for (c5_i55 = 0; c5_i55 < 6; c5_i55 = c5_i55 + 1) {
      c5_v_y[c5_i55] = c5_u_y[c5_i55];
    }

    c5_r_x = 0.0;
    c5_w_y = c5_r_x;
    c5_i56 = 1;
    for (c5_e_k = c5_i56; c5_e_k < 7; c5_e_k = c5_e_k + 1) {
      c5_f_k = c5_e_k;
      c5_w_y = c5_w_y + c5_q_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c5_f_k), 1, 6, 1, 0) - 1] *
        c5_v_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c5_f_k), 1, 6, 1, 0) - 1];
    }

    c5_i_a = c5_eye() - c5_w_y;
    c5_i_b = c5_Ps;
    c5_j_a = c5_i_a * c5_i_b;
    for (c5_i57 = 0; c5_i57 < 6; c5_i57 = c5_i57 + 1) {
      c5_k_a[c5_i57] = c5_Ks[c5_i57];
    }

    for (c5_i58 = 0; c5_i58 < 6; c5_i58 = c5_i58 + 1) {
      c5_j_b[c5_i58] = c5_H[c5_i58];
    }

    for (c5_i59 = 0; c5_i59 < 6; c5_i59 = c5_i59 + 1) {
      c5_s_x[c5_i59] = c5_k_a[c5_i59];
    }

    for (c5_i60 = 0; c5_i60 < 6; c5_i60 = c5_i60 + 1) {
      c5_x_y[c5_i60] = c5_j_b[c5_i60];
    }

    for (c5_i61 = 0; c5_i61 < 6; c5_i61 = c5_i61 + 1) {
      c5_t_x[c5_i61] = c5_s_x[c5_i61];
    }

    for (c5_i62 = 0; c5_i62 < 6; c5_i62 = c5_i62 + 1) {
      c5_y_y[c5_i62] = c5_x_y[c5_i62];
    }

    for (c5_i63 = 0; c5_i63 < 6; c5_i63 = c5_i63 + 1) {
      c5_u_x[c5_i63] = c5_t_x[c5_i63];
    }

    for (c5_i64 = 0; c5_i64 < 6; c5_i64 = c5_i64 + 1) {
      c5_ab_y[c5_i64] = c5_y_y[c5_i64];
    }

    for (c5_i65 = 0; c5_i65 < 6; c5_i65 = c5_i65 + 1) {
      c5_v_x[c5_i65] = c5_u_x[c5_i65];
    }

    for (c5_i66 = 0; c5_i66 < 6; c5_i66 = c5_i66 + 1) {
      c5_bb_y[c5_i66] = c5_ab_y[c5_i66];
    }

    for (c5_i67 = 0; c5_i67 < 6; c5_i67 = c5_i67 + 1) {
      c5_w_x[c5_i67] = c5_v_x[c5_i67];
    }

    for (c5_i68 = 0; c5_i68 < 6; c5_i68 = c5_i68 + 1) {
      c5_cb_y[c5_i68] = c5_bb_y[c5_i68];
    }

    c5_x_x = 0.0;
    c5_db_y = c5_x_x;
    c5_i69 = 1;
    for (c5_g_k = c5_i69; c5_g_k < 7; c5_g_k = c5_g_k + 1) {
      c5_h_k = c5_g_k;
      c5_db_y = c5_db_y + c5_w_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c5_h_k), 1, 6, 1, 0) - 1] *
        c5_cb_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c5_h_k), 1, 6, 1, 0) - 1];
    }

    c5_k_b = c5_eye() - c5_db_y;
    c5_eb_y = c5_j_a * c5_k_b;
    c5_Ps1 = c5_eb_y + c5_q_y;
  } else {
    _SFD_EML_CALL(0,9);
    c5_Ps = c5_Psn;
    _SFD_EML_CALL(0,10);
    for (c5_i70 = 0; c5_i70 < 6; c5_i70 = c5_i70 + 1) {
      c5_l_a[c5_i70] = c5_H[c5_i70];
    }

    c5_l_b = c5_Ps;
    for (c5_i71 = 0; c5_i71 < 6; c5_i71 = c5_i71 + 1) {
      c5_m_a[c5_i71] = c5_l_a[c5_i71] * c5_l_b;
    }

    for (c5_i72 = 0; c5_i72 < 6; c5_i72 = c5_i72 + 1) {
      c5_m_b[c5_i72] = c5_H[c5_i72];
    }

    for (c5_i73 = 0; c5_i73 < 6; c5_i73 = c5_i73 + 1) {
      for (c5_i74 = 0; c5_i74 < 6; c5_i74 = c5_i74 + 1) {
        c5_fb_y[c5_i74 + 6 * c5_i73] = c5_m_a[c5_i74] * c5_m_b[c5_i73];
      }
    }

    c5_n_a = c5_Ps;
    for (c5_i75 = 0; c5_i75 < 6; c5_i75 = c5_i75 + 1) {
      c5_n_b[c5_i75] = c5_H[c5_i75];
    }

    for (c5_i76 = 0; c5_i76 < 6; c5_i76 = c5_i76 + 1) {
      c5_gb_y[c5_i76] = c5_n_a * c5_n_b[c5_i76];
    }

    for (c5_i77 = 0; c5_i77 < 6; c5_i77 = c5_i77 + 1) {
      c5_hb_y[c5_i77] = c5_gb_y[c5_i77];
    }

    for (c5_i78 = 0; c5_i78 < 6; c5_i78 = c5_i78 + 1) {
      for (c5_i79 = 0; c5_i79 < 6; c5_i79 = c5_i79 + 1) {
        c5_ib_y[c5_i79 + 6 * c5_i78] = c5_fb_y[c5_i79 + 6 * c5_i78] + c5_Rs;
      }
    }

    c5_mrdivide(c5_hb_y, c5_ib_y, c5_dv1);
    for (c5_i80 = 0; c5_i80 < 6; c5_i80 = c5_i80 + 1) {
      c5_Ks[c5_i80] = c5_dv1[c5_i80];
    }

    _SFD_EML_CALL(0,11);
    for (c5_i81 = 0; c5_i81 < 6; c5_i81 = c5_i81 + 1) {
      c5_o_a[c5_i81] = c5_Ks[c5_i81];
    }

    for (c5_i82 = 0; c5_i82 < 6; c5_i82 = c5_i82 + 1) {
      c5_p_a[c5_i82] = c5_H[c5_i82];
    }

    c5_o_b = c5_theta1;
    for (c5_i83 = 0; c5_i83 < 6; c5_i83 = c5_i83 + 1) {
      c5_jb_y[c5_i83] = c5_p_a[c5_i83] * c5_o_b;
    }

    for (c5_i84 = 0; c5_i84 < 6; c5_i84 = c5_i84 + 1) {
      c5_p_b[c5_i84] = c5_V[c5_i84] - c5_jb_y[c5_i84];
    }

    for (c5_i85 = 0; c5_i85 < 6; c5_i85 = c5_i85 + 1) {
      c5_y_x[c5_i85] = c5_o_a[c5_i85];
    }

    for (c5_i86 = 0; c5_i86 < 6; c5_i86 = c5_i86 + 1) {
      c5_kb_y[c5_i86] = c5_p_b[c5_i86];
    }

    for (c5_i87 = 0; c5_i87 < 6; c5_i87 = c5_i87 + 1) {
      c5_ab_x[c5_i87] = c5_y_x[c5_i87];
    }

    for (c5_i88 = 0; c5_i88 < 6; c5_i88 = c5_i88 + 1) {
      c5_lb_y[c5_i88] = c5_kb_y[c5_i88];
    }

    for (c5_i89 = 0; c5_i89 < 6; c5_i89 = c5_i89 + 1) {
      c5_bb_x[c5_i89] = c5_ab_x[c5_i89];
    }

    for (c5_i90 = 0; c5_i90 < 6; c5_i90 = c5_i90 + 1) {
      c5_mb_y[c5_i90] = c5_lb_y[c5_i90];
    }

    for (c5_i91 = 0; c5_i91 < 6; c5_i91 = c5_i91 + 1) {
      c5_cb_x[c5_i91] = c5_bb_x[c5_i91];
    }

    for (c5_i92 = 0; c5_i92 < 6; c5_i92 = c5_i92 + 1) {
      c5_nb_y[c5_i92] = c5_mb_y[c5_i92];
    }

    for (c5_i93 = 0; c5_i93 < 6; c5_i93 = c5_i93 + 1) {
      c5_db_x[c5_i93] = c5_cb_x[c5_i93];
    }

    for (c5_i94 = 0; c5_i94 < 6; c5_i94 = c5_i94 + 1) {
      c5_ob_y[c5_i94] = c5_nb_y[c5_i94];
    }

    c5_eb_x = 0.0;
    c5_pb_y = c5_eb_x;
    c5_i95 = 1;
    for (c5_i_k = c5_i95; c5_i_k < 7; c5_i_k = c5_i_k + 1) {
      c5_j_k = c5_i_k;
      c5_pb_y = c5_pb_y + c5_db_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c5_j_k), 1, 6, 1, 0) - 1] *
        c5_ob_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c5_j_k), 1, 6, 1, 0) - 1];
    }

    c5_theta = c5_theta1 + c5_pb_y;
    _SFD_EML_CALL(0,12);
    for (c5_i96 = 0; c5_i96 < 6; c5_i96 = c5_i96 + 1) {
      c5_q_a[c5_i96] = c5_Ks[c5_i96];
    }

    c5_q_b = c5_Rs;
    for (c5_i97 = 0; c5_i97 < 6; c5_i97 = c5_i97 + 1) {
      c5_r_a[c5_i97] = c5_q_a[c5_i97] * c5_q_b;
    }

    for (c5_i98 = 0; c5_i98 < 6; c5_i98 = c5_i98 + 1) {
      c5_r_b[c5_i98] = c5_Ks[c5_i98];
    }

    for (c5_i99 = 0; c5_i99 < 6; c5_i99 = c5_i99 + 1) {
      c5_fb_x[c5_i99] = c5_r_a[c5_i99];
    }

    for (c5_i100 = 0; c5_i100 < 6; c5_i100 = c5_i100 + 1) {
      c5_qb_y[c5_i100] = c5_r_b[c5_i100];
    }

    for (c5_i101 = 0; c5_i101 < 6; c5_i101 = c5_i101 + 1) {
      c5_gb_x[c5_i101] = c5_fb_x[c5_i101];
    }

    for (c5_i102 = 0; c5_i102 < 6; c5_i102 = c5_i102 + 1) {
      c5_rb_y[c5_i102] = c5_qb_y[c5_i102];
    }

    for (c5_i103 = 0; c5_i103 < 6; c5_i103 = c5_i103 + 1) {
      c5_hb_x[c5_i103] = c5_gb_x[c5_i103];
    }

    for (c5_i104 = 0; c5_i104 < 6; c5_i104 = c5_i104 + 1) {
      c5_sb_y[c5_i104] = c5_rb_y[c5_i104];
    }

    for (c5_i105 = 0; c5_i105 < 6; c5_i105 = c5_i105 + 1) {
      c5_ib_x[c5_i105] = c5_hb_x[c5_i105];
    }

    for (c5_i106 = 0; c5_i106 < 6; c5_i106 = c5_i106 + 1) {
      c5_tb_y[c5_i106] = c5_sb_y[c5_i106];
    }

    for (c5_i107 = 0; c5_i107 < 6; c5_i107 = c5_i107 + 1) {
      c5_jb_x[c5_i107] = c5_ib_x[c5_i107];
    }

    for (c5_i108 = 0; c5_i108 < 6; c5_i108 = c5_i108 + 1) {
      c5_ub_y[c5_i108] = c5_tb_y[c5_i108];
    }

    c5_kb_x = 0.0;
    c5_vb_y = c5_kb_x;
    c5_i109 = 1;
    for (c5_k_k = c5_i109; c5_k_k < 7; c5_k_k = c5_k_k + 1) {
      c5_l_k = c5_k_k;
      c5_vb_y = c5_vb_y + c5_jb_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c5_l_k), 1, 6, 1, 0) - 1] *
        c5_ub_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c5_l_k), 1, 6, 1, 0) - 1];
    }

    for (c5_i110 = 0; c5_i110 < 6; c5_i110 = c5_i110 + 1) {
      c5_s_a[c5_i110] = c5_Ks[c5_i110];
    }

    for (c5_i111 = 0; c5_i111 < 6; c5_i111 = c5_i111 + 1) {
      c5_s_b[c5_i111] = c5_H[c5_i111];
    }

    for (c5_i112 = 0; c5_i112 < 6; c5_i112 = c5_i112 + 1) {
      c5_lb_x[c5_i112] = c5_s_a[c5_i112];
    }

    for (c5_i113 = 0; c5_i113 < 6; c5_i113 = c5_i113 + 1) {
      c5_wb_y[c5_i113] = c5_s_b[c5_i113];
    }

    for (c5_i114 = 0; c5_i114 < 6; c5_i114 = c5_i114 + 1) {
      c5_mb_x[c5_i114] = c5_lb_x[c5_i114];
    }

    for (c5_i115 = 0; c5_i115 < 6; c5_i115 = c5_i115 + 1) {
      c5_xb_y[c5_i115] = c5_wb_y[c5_i115];
    }

    for (c5_i116 = 0; c5_i116 < 6; c5_i116 = c5_i116 + 1) {
      c5_nb_x[c5_i116] = c5_mb_x[c5_i116];
    }

    for (c5_i117 = 0; c5_i117 < 6; c5_i117 = c5_i117 + 1) {
      c5_yb_y[c5_i117] = c5_xb_y[c5_i117];
    }

    for (c5_i118 = 0; c5_i118 < 6; c5_i118 = c5_i118 + 1) {
      c5_ob_x[c5_i118] = c5_nb_x[c5_i118];
    }

    for (c5_i119 = 0; c5_i119 < 6; c5_i119 = c5_i119 + 1) {
      c5_ac_y[c5_i119] = c5_yb_y[c5_i119];
    }

    for (c5_i120 = 0; c5_i120 < 6; c5_i120 = c5_i120 + 1) {
      c5_pb_x[c5_i120] = c5_ob_x[c5_i120];
    }

    for (c5_i121 = 0; c5_i121 < 6; c5_i121 = c5_i121 + 1) {
      c5_bc_y[c5_i121] = c5_ac_y[c5_i121];
    }

    c5_qb_x = 0.0;
    c5_cc_y = c5_qb_x;
    c5_i122 = 1;
    for (c5_m_k = c5_i122; c5_m_k < 7; c5_m_k = c5_m_k + 1) {
      c5_n_k = c5_m_k;
      c5_cc_y = c5_cc_y + c5_pb_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c5_n_k), 1, 6, 1, 0) - 1] *
        c5_bc_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c5_n_k), 1, 6, 1, 0) - 1];
    }

    c5_t_a = c5_eye() - c5_cc_y;
    c5_t_b = c5_Ps;
    c5_u_a = c5_t_a * c5_t_b;
    for (c5_i123 = 0; c5_i123 < 6; c5_i123 = c5_i123 + 1) {
      c5_v_a[c5_i123] = c5_Ks[c5_i123];
    }

    for (c5_i124 = 0; c5_i124 < 6; c5_i124 = c5_i124 + 1) {
      c5_u_b[c5_i124] = c5_H[c5_i124];
    }

    for (c5_i125 = 0; c5_i125 < 6; c5_i125 = c5_i125 + 1) {
      c5_rb_x[c5_i125] = c5_v_a[c5_i125];
    }

    for (c5_i126 = 0; c5_i126 < 6; c5_i126 = c5_i126 + 1) {
      c5_dc_y[c5_i126] = c5_u_b[c5_i126];
    }

    for (c5_i127 = 0; c5_i127 < 6; c5_i127 = c5_i127 + 1) {
      c5_sb_x[c5_i127] = c5_rb_x[c5_i127];
    }

    for (c5_i128 = 0; c5_i128 < 6; c5_i128 = c5_i128 + 1) {
      c5_ec_y[c5_i128] = c5_dc_y[c5_i128];
    }

    for (c5_i129 = 0; c5_i129 < 6; c5_i129 = c5_i129 + 1) {
      c5_tb_x[c5_i129] = c5_sb_x[c5_i129];
    }

    for (c5_i130 = 0; c5_i130 < 6; c5_i130 = c5_i130 + 1) {
      c5_fc_y[c5_i130] = c5_ec_y[c5_i130];
    }

    for (c5_i131 = 0; c5_i131 < 6; c5_i131 = c5_i131 + 1) {
      c5_ub_x[c5_i131] = c5_tb_x[c5_i131];
    }

    for (c5_i132 = 0; c5_i132 < 6; c5_i132 = c5_i132 + 1) {
      c5_gc_y[c5_i132] = c5_fc_y[c5_i132];
    }

    for (c5_i133 = 0; c5_i133 < 6; c5_i133 = c5_i133 + 1) {
      c5_vb_x[c5_i133] = c5_ub_x[c5_i133];
    }

    for (c5_i134 = 0; c5_i134 < 6; c5_i134 = c5_i134 + 1) {
      c5_hc_y[c5_i134] = c5_gc_y[c5_i134];
    }

    c5_wb_x = 0.0;
    c5_ic_y = c5_wb_x;
    c5_i135 = 1;
    for (c5_o_k = c5_i135; c5_o_k < 7; c5_o_k = c5_o_k + 1) {
      c5_p_k = c5_o_k;
      c5_ic_y = c5_ic_y + c5_vb_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        _SFD_INTEGER_CHECK("k", (real_T)c5_p_k), 1, 6, 1, 0) - 1] *
        c5_hc_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", _SFD_INTEGER_CHECK("k",
        (real_T)c5_p_k), 1, 6, 1, 0) - 1];
    }

    c5_one = 1.0;
    c5_I = c5_one;
    c5_v_b = c5_I - c5_ic_y;
    c5_jc_y = c5_u_a * c5_v_b;
    c5_Ps1 = c5_jc_y + c5_vb_y;
  }

  _SFD_EML_CALL(0,-12);
  sf_debug_symbol_scope_pop();
  *c5_b_theta = c5_theta;
  *c5_b_Ps1 = c5_Ps1;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static void c5_mrdivide(real_T c5_A[6], real_T c5_B[36], real_T c5_y[6])
{
  int32_T c5_i136;
  int32_T c5_i137;
  real_T c5_b_A[36];
  int32_T c5_i138;
  real_T c5_b_B[6];
  int32_T c5_i139;
  int32_T c5_i140;
  real_T c5_c_A[36];
  int32_T c5_i141;
  real_T c5_c_B[6];
  int32_T c5_i142;
  int32_T c5_i143;
  real_T c5_d_A[36];
  int32_T c5_info;
  int32_T c5_ipiv[6];
  real_T c5_e_A[36];
  int32_T c5_i144;
  int32_T c5_i145;
  int32_T c5_i146;
  int32_T c5_b_ipiv[6];
  int32_T c5_b_info;
  real_T c5_CZERO;
  int32_T c5_i147;
  real_T c5_Y[6];
  int32_T c5_i148;
  int32_T c5_i;
  int32_T c5_b_i;
  int32_T c5_ip;
  real_T c5_temp;
  int32_T c5_m;
  int32_T c5_n;
  real_T c5_alpha1;
  int32_T c5_i149;
  int32_T c5_i150;
  real_T c5_f_A[36];
  int32_T c5_ia0;
  int32_T c5_lda;
  int32_T c5_i151;
  real_T c5_d_B[6];
  int32_T c5_ib0;
  int32_T c5_ldb;
  int32_T c5_i152;
  int32_T c5_b_m;
  int32_T c5_b_n;
  real_T c5_b_alpha1;
  int32_T c5_i153;
  int32_T c5_i154;
  real_T c5_g_A[36];
  int32_T c5_b_ia0;
  int32_T c5_b_lda;
  int32_T c5_i155;
  real_T c5_e_B[6];
  int32_T c5_b_ib0;
  int32_T c5_b_ldb;
  int32_T c5_i156;
  int32_T c5_c_m;
  int32_T c5_c_n;
  real_T c5_c_alpha1;
  int32_T c5_i157;
  int32_T c5_i158;
  real_T c5_h_A[36];
  int32_T c5_c_ia0;
  int32_T c5_c_lda;
  int32_T c5_i159;
  real_T c5_f_B[6];
  int32_T c5_c_ib0;
  int32_T c5_c_ldb;
  int32_T c5_i160;
  boolean_T c5_NON_UNIT_ALPHA;
  int32_T c5_i161;
  int32_T c5_i162;
  int32_T c5_i163;
  int32_T c5_Aoffset;
  int32_T c5_i164;
  int32_T c5_i165;
  int32_T c5_i166;
  int32_T c5_Boffset;
  int32_T c5_i167;
  int32_T c5_loop_ub;
  int32_T c5_j;
  int32_T c5_b_j;
  int32_T c5_i168;
  int32_T c5_i169;
  int32_T c5_i170;
  int32_T c5_i171;
  int32_T c5_i172;
  int32_T c5_i173;
  int32_T c5_jBcol;
  int32_T c5_i174;
  int32_T c5_b_loop_ub;
  int32_T c5_c_i;
  int32_T c5_d_i;
  int32_T c5_i175;
  int32_T c5_i176;
  int32_T c5_i177;
  int32_T c5_i178;
  int32_T c5_c_loop_ub;
  int32_T c5_c_j;
  int32_T c5_i179;
  int32_T c5_i180;
  int32_T c5_i181;
  int32_T c5_i182;
  int32_T c5_i183;
  int32_T c5_i184;
  int32_T c5_i185;
  int32_T c5_d_loop_ub;
  int32_T c5_e_i;
  int32_T c5_i186;
  int32_T c5_i187;
  int32_T c5_i188;
  int32_T c5_i189;
  int32_T c5_i190;
  int32_T c5_i191;
  int32_T c5_i192;
  int32_T c5_e_loop_ub;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_i193;
  int32_T c5_i194;
  int32_T c5_i195;
  int32_T c5_i196;
  int32_T c5_i197;
  int32_T c5_i198;
  int32_T c5_kAcol;
  int32_T c5_i199;
  int32_T c5_i200;
  int32_T c5_i201;
  int32_T c5_i202;
  int32_T c5_i203;
  int32_T c5_i204;
  int32_T c5_i205;
  int32_T c5_f_loop_ub;
  int32_T c5_f_i;
  int32_T c5_i206;
  int32_T c5_i207;
  int32_T c5_i208;
  int32_T c5_i209;
  int32_T c5_i210;
  int32_T c5_i211;
  int32_T c5_i212;
  int32_T c5_i213;
  int32_T c5_i214;
  int32_T c5_i215;
  int32_T c5_i216;
  int32_T c5_i217;
  int32_T c5_d_m;
  int32_T c5_d_n;
  real_T c5_d_alpha1;
  int32_T c5_i218;
  int32_T c5_i219;
  real_T c5_i_A[36];
  int32_T c5_d_ia0;
  int32_T c5_d_lda;
  int32_T c5_i220;
  real_T c5_g_B[6];
  int32_T c5_d_ib0;
  int32_T c5_d_ldb;
  int32_T c5_i221;
  int32_T c5_e_m;
  int32_T c5_e_n;
  real_T c5_e_alpha1;
  int32_T c5_i222;
  int32_T c5_i223;
  real_T c5_j_A[36];
  int32_T c5_e_ia0;
  int32_T c5_e_lda;
  int32_T c5_i224;
  real_T c5_h_B[6];
  int32_T c5_e_ib0;
  int32_T c5_e_ldb;
  int32_T c5_i225;
  int32_T c5_f_m;
  int32_T c5_f_n;
  real_T c5_f_alpha1;
  int32_T c5_i226;
  int32_T c5_i227;
  real_T c5_k_A[36];
  int32_T c5_f_ia0;
  int32_T c5_f_lda;
  int32_T c5_i228;
  real_T c5_i_B[6];
  int32_T c5_f_ib0;
  int32_T c5_f_ldb;
  int32_T c5_i229;
  boolean_T c5_b_NON_UNIT_ALPHA;
  int32_T c5_i230;
  int32_T c5_i231;
  int32_T c5_i232;
  int32_T c5_b_Aoffset;
  int32_T c5_i233;
  int32_T c5_i234;
  int32_T c5_i235;
  int32_T c5_b_Boffset;
  int32_T c5_i236;
  int32_T c5_g_loop_ub;
  int32_T c5_d_j;
  int32_T c5_e_j;
  int32_T c5_i237;
  int32_T c5_i238;
  int32_T c5_i239;
  int32_T c5_i240;
  int32_T c5_i241;
  int32_T c5_i242;
  int32_T c5_b_jBcol;
  int32_T c5_i243;
  int32_T c5_h_loop_ub;
  int32_T c5_g_i;
  int32_T c5_h_i;
  int32_T c5_i244;
  int32_T c5_i245;
  int32_T c5_i246;
  int32_T c5_i247;
  int32_T c5_i_loop_ub;
  int32_T c5_f_j;
  int32_T c5_i248;
  int32_T c5_i249;
  int32_T c5_i250;
  int32_T c5_i251;
  int32_T c5_i252;
  int32_T c5_i253;
  int32_T c5_i254;
  int32_T c5_j_loop_ub;
  int32_T c5_i_i;
  int32_T c5_i255;
  int32_T c5_i256;
  int32_T c5_i257;
  int32_T c5_i258;
  int32_T c5_i259;
  int32_T c5_i260;
  int32_T c5_g_m;
  real_T c5_k_loop_ub;
  int32_T c5_c_k;
  int32_T c5_d_k;
  int32_T c5_i261;
  int32_T c5_i262;
  int32_T c5_i263;
  int32_T c5_i264;
  int32_T c5_i265;
  int32_T c5_i266;
  int32_T c5_b_kAcol;
  int32_T c5_i267;
  int32_T c5_i268;
  int32_T c5_i269;
  int32_T c5_i270;
  int32_T c5_i271;
  int32_T c5_i272;
  real_T c5_x;
  int32_T c5_i273;
  int32_T c5_i274;
  int32_T c5_i275;
  real_T c5_b_y;
  real_T c5_b_x;
  real_T c5_c_y;
  real_T c5_z;
  int32_T c5_i276;
  int32_T c5_i277;
  int32_T c5_i278;
  int32_T c5_i279;
  int32_T c5_i280;
  int32_T c5_i281;
  int32_T c5_i282;
  int32_T c5_l_loop_ub;
  int32_T c5_j_i;
  int32_T c5_i283;
  int32_T c5_i284;
  int32_T c5_i285;
  int32_T c5_i286;
  int32_T c5_i287;
  int32_T c5_i288;
  int32_T c5_i289;
  int32_T c5_i290;
  int32_T c5_i291;
  int32_T c5_i292;
  int32_T c5_i293;
  int32_T c5_i294;
  int32_T c5_i295;
  for (c5_i136 = 0; c5_i136 < 6; c5_i136 = c5_i136 + 1) {
    for (c5_i137 = 0; c5_i137 < 6; c5_i137 = c5_i137 + 1) {
      c5_b_A[c5_i137 + 6 * c5_i136] = c5_B[c5_i136 + 6 * c5_i137];
    }
  }

  for (c5_i138 = 0; c5_i138 < 6; c5_i138 = c5_i138 + 1) {
    c5_b_B[c5_i138] = c5_A[c5_i138];
  }

  for (c5_i139 = 0; c5_i139 < 6; c5_i139 = c5_i139 + 1) {
    for (c5_i140 = 0; c5_i140 < 6; c5_i140 = c5_i140 + 1) {
      c5_c_A[c5_i140 + 6 * c5_i139] = c5_b_A[c5_i140 + 6 * c5_i139];
    }
  }

  for (c5_i141 = 0; c5_i141 < 6; c5_i141 = c5_i141 + 1) {
    c5_c_B[c5_i141] = c5_b_B[c5_i141];
  }

  for (c5_i142 = 0; c5_i142 < 6; c5_i142 = c5_i142 + 1) {
    for (c5_i143 = 0; c5_i143 < 6; c5_i143 = c5_i143 + 1) {
      c5_d_A[c5_i143 + 6 * c5_i142] = c5_c_A[c5_i143 + 6 * c5_i142];
    }
  }

  c5_eml_xgetrf(c5_d_A, c5_e_A, c5_ipiv, &c5_info);
  for (c5_i144 = 0; c5_i144 < 6; c5_i144 = c5_i144 + 1) {
    for (c5_i145 = 0; c5_i145 < 6; c5_i145 = c5_i145 + 1) {
      c5_c_A[c5_i145 + 6 * c5_i144] = c5_e_A[c5_i145 + 6 * c5_i144];
    }
  }

  for (c5_i146 = 0; c5_i146 < 6; c5_i146 = c5_i146 + 1) {
    c5_b_ipiv[c5_i146] = c5_ipiv[c5_i146];
  }

  c5_b_info = c5_info;
  if ((real_T)c5_b_info > 0.0) {
    c5_eml_warning();
  }

  c5_CZERO = 0.0;
  for (c5_i147 = 0; c5_i147 < 6; c5_i147 = c5_i147 + 1) {
    c5_Y[c5_i147] = c5_c_B[c5_i147] + c5_CZERO;
  }

  c5_i148 = 1;
  for (c5_i = c5_i148; c5_i < 7; c5_i = c5_i + 1) {
    c5_b_i = c5_i;
    if (c5_b_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv",
         _SFD_INTEGER_CHECK("i", (real_T)c5_b_i), 1, 6, 1, 0) - 1] != c5_b_i) {
      c5_ip = c5_b_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv",
        _SFD_INTEGER_CHECK("i", (real_T)c5_b_i), 1, 6, 1, 0) - 1];
      c5_temp = c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X",
        _SFD_INTEGER_CHECK("i", (real_T)c5_b_i), 1, 6, 1, 0) - 1];
      c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("i",
        (real_T)c5_b_i), 1, 6, 1, 0) - 1] = c5_Y[(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("ip", (real_T)c5_ip),
        1, 6, 1, 0) - 1];
      c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", _SFD_INTEGER_CHECK("ip",
        (real_T)c5_ip), 1, 6, 1, 0) - 1] = c5_temp;
    }
  }

  c5_m = 6;
  c5_n = 1;
  c5_alpha1 = 1.0;
  for (c5_i149 = 0; c5_i149 < 6; c5_i149 = c5_i149 + 1) {
    for (c5_i150 = 0; c5_i150 < 6; c5_i150 = c5_i150 + 1) {
      c5_f_A[c5_i150 + 6 * c5_i149] = c5_c_A[c5_i150 + 6 * c5_i149];
    }
  }

  c5_ia0 = 1;
  c5_lda = 6;
  for (c5_i151 = 0; c5_i151 < 6; c5_i151 = c5_i151 + 1) {
    c5_d_B[c5_i151] = c5_Y[c5_i151];
  }

  c5_ib0 = 1;
  c5_ldb = 6;
  for (c5_i152 = 0; c5_i152 < 6; c5_i152 = c5_i152 + 1) {
    c5_Y[c5_i152] = c5_d_B[c5_i152];
  }

  c5_b_m = c5_m;
  c5_b_n = c5_n;
  c5_b_alpha1 = c5_alpha1;
  for (c5_i153 = 0; c5_i153 < 6; c5_i153 = c5_i153 + 1) {
    for (c5_i154 = 0; c5_i154 < 6; c5_i154 = c5_i154 + 1) {
      c5_g_A[c5_i154 + 6 * c5_i153] = c5_f_A[c5_i154 + 6 * c5_i153];
    }
  }

  c5_b_ia0 = c5_ia0;
  c5_b_lda = c5_lda;
  for (c5_i155 = 0; c5_i155 < 6; c5_i155 = c5_i155 + 1) {
    c5_e_B[c5_i155] = c5_Y[c5_i155];
  }

  c5_b_ib0 = c5_ib0;
  c5_b_ldb = c5_ldb;
  for (c5_i156 = 0; c5_i156 < 6; c5_i156 = c5_i156 + 1) {
    c5_Y[c5_i156] = c5_e_B[c5_i156];
  }

  c5_c_m = c5_b_m;
  c5_c_n = c5_b_n;
  c5_c_alpha1 = c5_b_alpha1;
  for (c5_i157 = 0; c5_i157 < 6; c5_i157 = c5_i157 + 1) {
    for (c5_i158 = 0; c5_i158 < 6; c5_i158 = c5_i158 + 1) {
      c5_h_A[c5_i158 + 6 * c5_i157] = c5_g_A[c5_i158 + 6 * c5_i157];
    }
  }

  c5_c_ia0 = c5_b_ia0;
  c5_c_lda = c5_b_lda;
  for (c5_i159 = 0; c5_i159 < 6; c5_i159 = c5_i159 + 1) {
    c5_f_B[c5_i159] = c5_Y[c5_i159];
  }

  c5_c_ib0 = c5_b_ib0;
  c5_c_ldb = c5_b_ldb;
  for (c5_i160 = 0; c5_i160 < 6; c5_i160 = c5_i160 + 1) {
    c5_Y[c5_i160] = c5_f_B[c5_i160];
  }

  c5_NON_UNIT_ALPHA = (c5_c_alpha1 != 1.0);
  if ((real_T)c5_c_n == 0.0) {
  } else {
    c5_i161 = c5_c_ia0;
    c5_i162 = 1;
    c5_i163 = c5_i161 - c5_i162;
    if ((c5_i161 < 0) && (c5_i162 >= 0) && (c5_i163 >= 0)) {
      c5_i163 = MIN_int32_T;
    } else {
      if ((c5_i161 >= 0) && (c5_i162 < 0) && (c5_i163 < 0)) {
        c5_i163 = MAX_int32_T;
      }
    }

    c5_Aoffset = c5_i163;
    c5_i164 = c5_c_ib0;
    c5_i165 = 1;
    c5_i166 = c5_i164 - c5_i165;
    if ((c5_i164 < 0) && (c5_i165 >= 0) && (c5_i166 >= 0)) {
      c5_i166 = MIN_int32_T;
    } else {
      if ((c5_i164 >= 0) && (c5_i165 < 0) && (c5_i166 < 0)) {
        c5_i166 = MAX_int32_T;
      }
    }

    c5_Boffset = c5_i166;
    if (c5_c_alpha1 == 0.0) {
      c5_i167 = 1;
      c5_loop_ub = c5_c_n;
      for (c5_j = c5_i167; c5_j <= c5_loop_ub; c5_j = c5_j + 1) {
        c5_b_j = c5_j;
        c5_i168 = c5_b_j;
        c5_i169 = 1;
        c5_i170 = c5_i168 - c5_i169;
        if ((c5_i168 < 0) && (c5_i169 >= 0) && (c5_i170 >= 0)) {
          c5_i170 = MIN_int32_T;
        } else {
          if ((c5_i168 >= 0) && (c5_i169 < 0) && (c5_i170 < 0)) {
            c5_i170 = MAX_int32_T;
          }
        }

        c5_i171 = c5_Boffset;
        c5_i172 = c5_mul_s32_s32_s32_sat(c5_i170, c5_c_ldb);
        c5_i173 = c5_i171 + c5_i172;
        if ((c5_i171 < 0) && (c5_i172 < 0) && (c5_i173 >= 0)) {
          c5_i173 = MIN_int32_T;
        } else {
          if ((c5_i171 > 0) && (c5_i172 > 0) && (c5_i173 <= 0)) {
            c5_i173 = MAX_int32_T;
          }
        }

        c5_jBcol = c5_i173;
        c5_i174 = 1;
        c5_b_loop_ub = c5_c_m;
        for (c5_c_i = c5_i174; c5_c_i <= c5_b_loop_ub; c5_c_i = c5_c_i + 1) {
          c5_d_i = c5_c_i;
          c5_i175 = c5_d_i;
          c5_i176 = c5_jBcol;
          c5_i177 = c5_i175 + c5_i176;
          if ((c5_i175 < 0) && (c5_i176 < 0) && (c5_i177 >= 0)) {
            c5_i177 = MIN_int32_T;
          } else {
            if ((c5_i175 > 0) && (c5_i176 > 0) && (c5_i177 <= 0)) {
              c5_i177 = MAX_int32_T;
            }
          }

          c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
            (real_T)c5_i177), 1, 6, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c5_i178 = 1;
      c5_c_loop_ub = c5_c_n;
      for (c5_c_j = c5_i178; c5_c_j <= c5_c_loop_ub; c5_c_j = c5_c_j + 1) {
        c5_b_j = c5_c_j;
        c5_i179 = c5_b_j;
        c5_i180 = 1;
        c5_i181 = c5_i179 - c5_i180;
        if ((c5_i179 < 0) && (c5_i180 >= 0) && (c5_i181 >= 0)) {
          c5_i181 = MIN_int32_T;
        } else {
          if ((c5_i179 >= 0) && (c5_i180 < 0) && (c5_i181 < 0)) {
            c5_i181 = MAX_int32_T;
          }
        }

        c5_i182 = c5_Boffset;
        c5_i183 = c5_mul_s32_s32_s32_sat(c5_i181, c5_c_ldb);
        c5_i184 = c5_i182 + c5_i183;
        if ((c5_i182 < 0) && (c5_i183 < 0) && (c5_i184 >= 0)) {
          c5_i184 = MIN_int32_T;
        } else {
          if ((c5_i182 > 0) && (c5_i183 > 0) && (c5_i184 <= 0)) {
            c5_i184 = MAX_int32_T;
          }
        }

        c5_jBcol = c5_i184;
        if (c5_NON_UNIT_ALPHA) {
          c5_i185 = 1;
          c5_d_loop_ub = c5_c_m;
          for (c5_e_i = c5_i185; c5_e_i <= c5_d_loop_ub; c5_e_i = c5_e_i + 1) {
            c5_d_i = c5_e_i;
            c5_i186 = c5_d_i;
            c5_i187 = c5_jBcol;
            c5_i188 = c5_i186 + c5_i187;
            if ((c5_i186 < 0) && (c5_i187 < 0) && (c5_i188 >= 0)) {
              c5_i188 = MIN_int32_T;
            } else {
              if ((c5_i186 > 0) && (c5_i187 > 0) && (c5_i188 <= 0)) {
                c5_i188 = MAX_int32_T;
              }
            }

            c5_i189 = c5_d_i;
            c5_i190 = c5_jBcol;
            c5_i191 = c5_i189 + c5_i190;
            if ((c5_i189 < 0) && (c5_i190 < 0) && (c5_i191 >= 0)) {
              c5_i191 = MIN_int32_T;
            } else {
              if ((c5_i189 > 0) && (c5_i190 > 0) && (c5_i191 <= 0)) {
                c5_i191 = MAX_int32_T;
              }
            }

            c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c5_i191), 1, 6, 1, 0) - 1] = c5_c_alpha1 * c5_Y[(
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c5_i188), 1, 6, 1, 0) - 1];
          }
        }

        c5_i192 = 1;
        c5_e_loop_ub = c5_c_m;
        for (c5_k = c5_i192; c5_k <= c5_e_loop_ub; c5_k = c5_k + 1) {
          c5_b_k = c5_k;
          c5_i193 = c5_b_k;
          c5_i194 = 1;
          c5_i195 = c5_i193 - c5_i194;
          if ((c5_i193 < 0) && (c5_i194 >= 0) && (c5_i195 >= 0)) {
            c5_i195 = MIN_int32_T;
          } else {
            if ((c5_i193 >= 0) && (c5_i194 < 0) && (c5_i195 < 0)) {
              c5_i195 = MAX_int32_T;
            }
          }

          c5_i196 = c5_Aoffset;
          c5_i197 = c5_mul_s32_s32_s32_sat(c5_i195, c5_c_lda);
          c5_i198 = c5_i196 + c5_i197;
          if ((c5_i196 < 0) && (c5_i197 < 0) && (c5_i198 >= 0)) {
            c5_i198 = MIN_int32_T;
          } else {
            if ((c5_i196 > 0) && (c5_i197 > 0) && (c5_i198 <= 0)) {
              c5_i198 = MAX_int32_T;
            }
          }

          c5_kAcol = c5_i198;
          c5_i199 = c5_b_k;
          c5_i200 = c5_jBcol;
          c5_i201 = c5_i199 + c5_i200;
          if ((c5_i199 < 0) && (c5_i200 < 0) && (c5_i201 >= 0)) {
            c5_i201 = MIN_int32_T;
          } else {
            if ((c5_i199 > 0) && (c5_i200 > 0) && (c5_i201 <= 0)) {
              c5_i201 = MAX_int32_T;
            }
          }

          if (c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c5_i201), 1, 6, 1, 0) - 1] != 0.0) {
            c5_i202 = c5_b_k;
            c5_i203 = 1;
            c5_i204 = c5_i202 + c5_i203;
            if ((c5_i202 < 0) && (c5_i203 < 0) && (c5_i204 >= 0)) {
              c5_i204 = MIN_int32_T;
            } else {
              if ((c5_i202 > 0) && (c5_i203 > 0) && (c5_i204 <= 0)) {
                c5_i204 = MAX_int32_T;
              }
            }

            c5_i205 = c5_i204;
            c5_f_loop_ub = c5_c_m;
            for (c5_f_i = c5_i205; c5_f_i <= c5_f_loop_ub; c5_f_i = c5_f_i + 1)
            {
              c5_d_i = c5_f_i;
              c5_i206 = c5_d_i;
              c5_i207 = c5_kAcol;
              c5_i208 = c5_i206 + c5_i207;
              if ((c5_i206 < 0) && (c5_i207 < 0) && (c5_i208 >= 0)) {
                c5_i208 = MIN_int32_T;
              } else {
                if ((c5_i206 > 0) && (c5_i207 > 0) && (c5_i208 <= 0)) {
                  c5_i208 = MAX_int32_T;
                }
              }

              c5_i209 = c5_b_k;
              c5_i210 = c5_jBcol;
              c5_i211 = c5_i209 + c5_i210;
              if ((c5_i209 < 0) && (c5_i210 < 0) && (c5_i211 >= 0)) {
                c5_i211 = MIN_int32_T;
              } else {
                if ((c5_i209 > 0) && (c5_i210 > 0) && (c5_i211 <= 0)) {
                  c5_i211 = MAX_int32_T;
                }
              }

              c5_i212 = c5_d_i;
              c5_i213 = c5_jBcol;
              c5_i214 = c5_i212 + c5_i213;
              if ((c5_i212 < 0) && (c5_i213 < 0) && (c5_i214 >= 0)) {
                c5_i214 = MIN_int32_T;
              } else {
                if ((c5_i212 > 0) && (c5_i213 > 0) && (c5_i214 <= 0)) {
                  c5_i214 = MAX_int32_T;
                }
              }

              c5_i215 = c5_d_i;
              c5_i216 = c5_jBcol;
              c5_i217 = c5_i215 + c5_i216;
              if ((c5_i215 < 0) && (c5_i216 < 0) && (c5_i217 >= 0)) {
                c5_i217 = MIN_int32_T;
              } else {
                if ((c5_i215 > 0) && (c5_i216 > 0) && (c5_i217 <= 0)) {
                  c5_i217 = MAX_int32_T;
                }
              }

              c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c5_i217), 1, 6, 1, 0) - 1] = c5_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c5_i214), 1, 6, 1, 0) - 1] - c5_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c5_i211), 1, 6, 1, 0) - 1] * c5_h_A[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("", (real_T)
                c5_i208), 1, 36, 1, 0) - 1];
            }
          }
        }
      }
    }
  }

  c5_d_m = 6;
  c5_d_n = 1;
  c5_d_alpha1 = 1.0;
  for (c5_i218 = 0; c5_i218 < 6; c5_i218 = c5_i218 + 1) {
    for (c5_i219 = 0; c5_i219 < 6; c5_i219 = c5_i219 + 1) {
      c5_i_A[c5_i219 + 6 * c5_i218] = c5_c_A[c5_i219 + 6 * c5_i218];
    }
  }

  c5_d_ia0 = 1;
  c5_d_lda = 6;
  for (c5_i220 = 0; c5_i220 < 6; c5_i220 = c5_i220 + 1) {
    c5_g_B[c5_i220] = c5_Y[c5_i220];
  }

  c5_d_ib0 = 1;
  c5_d_ldb = 6;
  for (c5_i221 = 0; c5_i221 < 6; c5_i221 = c5_i221 + 1) {
    c5_Y[c5_i221] = c5_g_B[c5_i221];
  }

  c5_e_m = c5_d_m;
  c5_e_n = c5_d_n;
  c5_e_alpha1 = c5_d_alpha1;
  for (c5_i222 = 0; c5_i222 < 6; c5_i222 = c5_i222 + 1) {
    for (c5_i223 = 0; c5_i223 < 6; c5_i223 = c5_i223 + 1) {
      c5_j_A[c5_i223 + 6 * c5_i222] = c5_i_A[c5_i223 + 6 * c5_i222];
    }
  }

  c5_e_ia0 = c5_d_ia0;
  c5_e_lda = c5_d_lda;
  for (c5_i224 = 0; c5_i224 < 6; c5_i224 = c5_i224 + 1) {
    c5_h_B[c5_i224] = c5_Y[c5_i224];
  }

  c5_e_ib0 = c5_d_ib0;
  c5_e_ldb = c5_d_ldb;
  for (c5_i225 = 0; c5_i225 < 6; c5_i225 = c5_i225 + 1) {
    c5_Y[c5_i225] = c5_h_B[c5_i225];
  }

  c5_f_m = c5_e_m;
  c5_f_n = c5_e_n;
  c5_f_alpha1 = c5_e_alpha1;
  for (c5_i226 = 0; c5_i226 < 6; c5_i226 = c5_i226 + 1) {
    for (c5_i227 = 0; c5_i227 < 6; c5_i227 = c5_i227 + 1) {
      c5_k_A[c5_i227 + 6 * c5_i226] = c5_j_A[c5_i227 + 6 * c5_i226];
    }
  }

  c5_f_ia0 = c5_e_ia0;
  c5_f_lda = c5_e_lda;
  for (c5_i228 = 0; c5_i228 < 6; c5_i228 = c5_i228 + 1) {
    c5_i_B[c5_i228] = c5_Y[c5_i228];
  }

  c5_f_ib0 = c5_e_ib0;
  c5_f_ldb = c5_e_ldb;
  for (c5_i229 = 0; c5_i229 < 6; c5_i229 = c5_i229 + 1) {
    c5_Y[c5_i229] = c5_i_B[c5_i229];
  }

  c5_b_NON_UNIT_ALPHA = (c5_f_alpha1 != 1.0);
  if ((real_T)c5_f_n == 0.0) {
  } else {
    c5_i230 = c5_f_ia0;
    c5_i231 = 1;
    c5_i232 = c5_i230 - c5_i231;
    if ((c5_i230 < 0) && (c5_i231 >= 0) && (c5_i232 >= 0)) {
      c5_i232 = MIN_int32_T;
    } else {
      if ((c5_i230 >= 0) && (c5_i231 < 0) && (c5_i232 < 0)) {
        c5_i232 = MAX_int32_T;
      }
    }

    c5_b_Aoffset = c5_i232;
    c5_i233 = c5_f_ib0;
    c5_i234 = 1;
    c5_i235 = c5_i233 - c5_i234;
    if ((c5_i233 < 0) && (c5_i234 >= 0) && (c5_i235 >= 0)) {
      c5_i235 = MIN_int32_T;
    } else {
      if ((c5_i233 >= 0) && (c5_i234 < 0) && (c5_i235 < 0)) {
        c5_i235 = MAX_int32_T;
      }
    }

    c5_b_Boffset = c5_i235;
    if (c5_f_alpha1 == 0.0) {
      c5_i236 = 1;
      c5_g_loop_ub = c5_f_n;
      for (c5_d_j = c5_i236; c5_d_j <= c5_g_loop_ub; c5_d_j = c5_d_j + 1) {
        c5_e_j = c5_d_j;
        c5_i237 = c5_e_j;
        c5_i238 = 1;
        c5_i239 = c5_i237 - c5_i238;
        if ((c5_i237 < 0) && (c5_i238 >= 0) && (c5_i239 >= 0)) {
          c5_i239 = MIN_int32_T;
        } else {
          if ((c5_i237 >= 0) && (c5_i238 < 0) && (c5_i239 < 0)) {
            c5_i239 = MAX_int32_T;
          }
        }

        c5_i240 = c5_b_Boffset;
        c5_i241 = c5_mul_s32_s32_s32_sat(c5_i239, c5_f_ldb);
        c5_i242 = c5_i240 + c5_i241;
        if ((c5_i240 < 0) && (c5_i241 < 0) && (c5_i242 >= 0)) {
          c5_i242 = MIN_int32_T;
        } else {
          if ((c5_i240 > 0) && (c5_i241 > 0) && (c5_i242 <= 0)) {
            c5_i242 = MAX_int32_T;
          }
        }

        c5_b_jBcol = c5_i242;
        c5_i243 = 1;
        c5_h_loop_ub = c5_f_m;
        for (c5_g_i = c5_i243; c5_g_i <= c5_h_loop_ub; c5_g_i = c5_g_i + 1) {
          c5_h_i = c5_g_i;
          c5_i244 = c5_h_i;
          c5_i245 = c5_b_jBcol;
          c5_i246 = c5_i244 + c5_i245;
          if ((c5_i244 < 0) && (c5_i245 < 0) && (c5_i246 >= 0)) {
            c5_i246 = MIN_int32_T;
          } else {
            if ((c5_i244 > 0) && (c5_i245 > 0) && (c5_i246 <= 0)) {
              c5_i246 = MAX_int32_T;
            }
          }

          c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
            (real_T)c5_i246), 1, 6, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c5_i247 = 1;
      c5_i_loop_ub = c5_f_n;
      for (c5_f_j = c5_i247; c5_f_j <= c5_i_loop_ub; c5_f_j = c5_f_j + 1) {
        c5_e_j = c5_f_j;
        c5_i248 = c5_e_j;
        c5_i249 = 1;
        c5_i250 = c5_i248 - c5_i249;
        if ((c5_i248 < 0) && (c5_i249 >= 0) && (c5_i250 >= 0)) {
          c5_i250 = MIN_int32_T;
        } else {
          if ((c5_i248 >= 0) && (c5_i249 < 0) && (c5_i250 < 0)) {
            c5_i250 = MAX_int32_T;
          }
        }

        c5_i251 = c5_b_Boffset;
        c5_i252 = c5_mul_s32_s32_s32_sat(c5_i250, c5_f_ldb);
        c5_i253 = c5_i251 + c5_i252;
        if ((c5_i251 < 0) && (c5_i252 < 0) && (c5_i253 >= 0)) {
          c5_i253 = MIN_int32_T;
        } else {
          if ((c5_i251 > 0) && (c5_i252 > 0) && (c5_i253 <= 0)) {
            c5_i253 = MAX_int32_T;
          }
        }

        c5_b_jBcol = c5_i253;
        if (c5_b_NON_UNIT_ALPHA) {
          c5_i254 = 1;
          c5_j_loop_ub = c5_f_m;
          for (c5_i_i = c5_i254; c5_i_i <= c5_j_loop_ub; c5_i_i = c5_i_i + 1) {
            c5_h_i = c5_i_i;
            c5_i255 = c5_h_i;
            c5_i256 = c5_b_jBcol;
            c5_i257 = c5_i255 + c5_i256;
            if ((c5_i255 < 0) && (c5_i256 < 0) && (c5_i257 >= 0)) {
              c5_i257 = MIN_int32_T;
            } else {
              if ((c5_i255 > 0) && (c5_i256 > 0) && (c5_i257 <= 0)) {
                c5_i257 = MAX_int32_T;
              }
            }

            c5_i258 = c5_h_i;
            c5_i259 = c5_b_jBcol;
            c5_i260 = c5_i258 + c5_i259;
            if ((c5_i258 < 0) && (c5_i259 < 0) && (c5_i260 >= 0)) {
              c5_i260 = MIN_int32_T;
            } else {
              if ((c5_i258 > 0) && (c5_i259 > 0) && (c5_i260 <= 0)) {
                c5_i260 = MAX_int32_T;
              }
            }

            c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c5_i260), 1, 6, 1, 0) - 1] = c5_f_alpha1 * c5_Y[(
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c5_i257), 1, 6, 1, 0) - 1];
          }
        }

        c5_g_m = c5_f_m;
        c5_k_loop_ub = 1.0;
        for (c5_c_k = c5_g_m; c5_c_k >= (int32_T)c5_k_loop_ub; c5_c_k = c5_c_k +
             -1) {
          c5_d_k = c5_c_k;
          c5_i261 = c5_d_k;
          c5_i262 = 1;
          c5_i263 = c5_i261 - c5_i262;
          if ((c5_i261 < 0) && (c5_i262 >= 0) && (c5_i263 >= 0)) {
            c5_i263 = MIN_int32_T;
          } else {
            if ((c5_i261 >= 0) && (c5_i262 < 0) && (c5_i263 < 0)) {
              c5_i263 = MAX_int32_T;
            }
          }

          c5_i264 = c5_b_Aoffset;
          c5_i265 = c5_mul_s32_s32_s32_sat(c5_i263, c5_f_lda);
          c5_i266 = c5_i264 + c5_i265;
          if ((c5_i264 < 0) && (c5_i265 < 0) && (c5_i266 >= 0)) {
            c5_i266 = MIN_int32_T;
          } else {
            if ((c5_i264 > 0) && (c5_i265 > 0) && (c5_i266 <= 0)) {
              c5_i266 = MAX_int32_T;
            }
          }

          c5_b_kAcol = c5_i266;
          c5_i267 = c5_d_k;
          c5_i268 = c5_b_jBcol;
          c5_i269 = c5_i267 + c5_i268;
          if ((c5_i267 < 0) && (c5_i268 < 0) && (c5_i269 >= 0)) {
            c5_i269 = MIN_int32_T;
          } else {
            if ((c5_i267 > 0) && (c5_i268 > 0) && (c5_i269 <= 0)) {
              c5_i269 = MAX_int32_T;
            }
          }

          if (c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c5_i269), 1, 6, 1, 0) - 1] != 0.0) {
            c5_i270 = c5_d_k;
            c5_i271 = c5_b_jBcol;
            c5_i272 = c5_i270 + c5_i271;
            if ((c5_i270 < 0) && (c5_i271 < 0) && (c5_i272 >= 0)) {
              c5_i272 = MIN_int32_T;
            } else {
              if ((c5_i270 > 0) && (c5_i271 > 0) && (c5_i272 <= 0)) {
                c5_i272 = MAX_int32_T;
              }
            }

            c5_x = c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B",
              _SFD_INTEGER_CHECK("", (real_T)c5_i272), 1, 6, 1, 0) - 1];
            c5_i273 = c5_d_k;
            c5_i274 = c5_b_kAcol;
            c5_i275 = c5_i273 + c5_i274;
            if ((c5_i273 < 0) && (c5_i274 < 0) && (c5_i275 >= 0)) {
              c5_i275 = MIN_int32_T;
            } else {
              if ((c5_i273 > 0) && (c5_i274 > 0) && (c5_i275 <= 0)) {
                c5_i275 = MAX_int32_T;
              }
            }

            c5_b_y = c5_k_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
              _SFD_INTEGER_CHECK("", (real_T)c5_i275), 1, 36, 1, 0) - 1];
            c5_b_x = c5_x;
            c5_c_y = c5_b_y;
            c5_z = c5_b_x / c5_c_y;
            c5_i276 = c5_d_k;
            c5_i277 = c5_b_jBcol;
            c5_i278 = c5_i276 + c5_i277;
            if ((c5_i276 < 0) && (c5_i277 < 0) && (c5_i278 >= 0)) {
              c5_i278 = MIN_int32_T;
            } else {
              if ((c5_i276 > 0) && (c5_i277 > 0) && (c5_i278 <= 0)) {
                c5_i278 = MAX_int32_T;
              }
            }

            c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("",
              (real_T)c5_i278), 1, 6, 1, 0) - 1] = c5_z;
            c5_i279 = 1;
            c5_i280 = c5_d_k;
            c5_i281 = 1;
            c5_i282 = c5_i280 - c5_i281;
            if ((c5_i280 < 0) && (c5_i281 >= 0) && (c5_i282 >= 0)) {
              c5_i282 = MIN_int32_T;
            } else {
              if ((c5_i280 >= 0) && (c5_i281 < 0) && (c5_i282 < 0)) {
                c5_i282 = MAX_int32_T;
              }
            }

            c5_l_loop_ub = c5_i282;
            for (c5_j_i = c5_i279; c5_j_i <= c5_l_loop_ub; c5_j_i = c5_j_i + 1)
            {
              c5_h_i = c5_j_i;
              c5_i283 = c5_h_i;
              c5_i284 = c5_b_kAcol;
              c5_i285 = c5_i283 + c5_i284;
              if ((c5_i283 < 0) && (c5_i284 < 0) && (c5_i285 >= 0)) {
                c5_i285 = MIN_int32_T;
              } else {
                if ((c5_i283 > 0) && (c5_i284 > 0) && (c5_i285 <= 0)) {
                  c5_i285 = MAX_int32_T;
                }
              }

              c5_i286 = c5_d_k;
              c5_i287 = c5_b_jBcol;
              c5_i288 = c5_i286 + c5_i287;
              if ((c5_i286 < 0) && (c5_i287 < 0) && (c5_i288 >= 0)) {
                c5_i288 = MIN_int32_T;
              } else {
                if ((c5_i286 > 0) && (c5_i287 > 0) && (c5_i288 <= 0)) {
                  c5_i288 = MAX_int32_T;
                }
              }

              c5_i289 = c5_h_i;
              c5_i290 = c5_b_jBcol;
              c5_i291 = c5_i289 + c5_i290;
              if ((c5_i289 < 0) && (c5_i290 < 0) && (c5_i291 >= 0)) {
                c5_i291 = MIN_int32_T;
              } else {
                if ((c5_i289 > 0) && (c5_i290 > 0) && (c5_i291 <= 0)) {
                  c5_i291 = MAX_int32_T;
                }
              }

              c5_i292 = c5_h_i;
              c5_i293 = c5_b_jBcol;
              c5_i294 = c5_i292 + c5_i293;
              if ((c5_i292 < 0) && (c5_i293 < 0) && (c5_i294 >= 0)) {
                c5_i294 = MIN_int32_T;
              } else {
                if ((c5_i292 > 0) && (c5_i293 > 0) && (c5_i294 <= 0)) {
                  c5_i294 = MAX_int32_T;
                }
              }

              c5_Y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK(
                "", (real_T)c5_i294), 1, 6, 1, 0) - 1] = c5_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c5_i291), 1, 6, 1, 0) - 1] - c5_Y[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("B", _SFD_INTEGER_CHECK("", (real_T)
                c5_i288), 1, 6, 1, 0) - 1] * c5_k_A[(int32_T)
                _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("", (real_T)
                c5_i285), 1, 36, 1, 0) - 1];
            }
          }
        }
      }
    }
  }

  for (c5_i295 = 0; c5_i295 < 6; c5_i295 = c5_i295 + 1) {
    c5_y[c5_i295] = c5_Y[c5_i295];
  }
}

static void c5_eml_xgetrf(real_T c5_A[36], real_T c5_b_A[36], int32_T c5_ipiv[6],
  int32_T *c5_info)
{
  int32_T c5_i296;
  int32_T c5_i297;
  int32_T c5_i298;
  int32_T c5_hoistedExpr;
  int32_T c5_x[6];
  int32_T c5_i299;
  int32_T c5_i300;
  int32_T c5_j;
  int32_T c5_b_j;
  int32_T c5_a;
  real_T c5_b;
  real_T c5_d0;
  real_T c5_d1;
  int32_T c5_i301;
  int32_T c5_jm1;
  int32_T c5_b_a;
  int32_T c5_b_b;
  int32_T c5_mmj;
  int32_T c5_c_a;
  int32_T c5_d_a;
  int32_T c5_c_b;
  int32_T c5_d_b;
  int32_T c5_jj;
  int32_T c5_e_a;
  real_T c5_e_b;
  real_T c5_d2;
  real_T c5_d3;
  int32_T c5_i302;
  int32_T c5_jp1j;
  int32_T c5_f_a;
  real_T c5_f_b;
  real_T c5_d4;
  real_T c5_d5;
  int32_T c5_i303;
  int32_T c5_n;
  int32_T c5_i304;
  int32_T c5_i305;
  real_T c5_b_x[36];
  int32_T c5_ix0;
  int32_T c5_incx;
  int32_T c5_b_n;
  int32_T c5_i306;
  int32_T c5_i307;
  real_T c5_c_x[36];
  int32_T c5_b_ix0;
  int32_T c5_b_incx;
  int32_T c5_c_n;
  int32_T c5_i308;
  int32_T c5_i309;
  real_T c5_d_x[36];
  int32_T c5_c_ix0;
  int32_T c5_c_incx;
  int32_T c5_ONE;
  int32_T c5_g_a;
  int32_T c5_e_x;
  int32_T c5_ix;
  int32_T c5_f_x;
  int32_T c5_ixinc;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_y;
  real_T c5_i_x;
  real_T c5_b_y;
  real_T c5_smax;
  int32_T c5_i310;
  int32_T c5_loop_ub;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_h_a;
  int32_T c5_g_b;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_c_y;
  real_T c5_l_x;
  real_T c5_d_y;
  real_T c5_s;
  real_T c5_h_b;
  real_T c5_d6;
  real_T c5_d7;
  int32_T c5_i311;
  int32_T c5_jpiv_offset;
  int32_T c5_i_a;
  int32_T c5_i_b;
  int32_T c5_jpiv;
  int32_T c5_j_a;
  int32_T c5_j_b;
  int32_T c5_c;
  int32_T c5_k_a;
  int32_T c5_k_b;
  int32_T c5_jrow;
  int32_T c5_l_a;
  int32_T c5_l_b;
  int32_T c5_jprow;
  int32_T c5_i312;
  int32_T c5_i313;
  real_T c5_m_x[36];
  int32_T c5_d_ix0;
  int32_T c5_iy0;
  int32_T c5_i314;
  int32_T c5_i315;
  int32_T c5_i316;
  int32_T c5_i317;
  real_T c5_n_x[36];
  int32_T c5_e_ix0;
  int32_T c5_b_iy0;
  int32_T c5_i318;
  int32_T c5_i319;
  real_T c5_o_x[36];
  int32_T c5_i320;
  int32_T c5_i321;
  real_T c5_p_x[36];
  int32_T c5_f_ix0;
  int32_T c5_c_iy0;
  int32_T c5_i322;
  int32_T c5_i323;
  real_T c5_q_x[36];
  int32_T c5_r_x;
  int32_T c5_b_ix;
  int32_T c5_s_x;
  int32_T c5_iy;
  int32_T c5_i324;
  int32_T c5_c_k;
  real_T c5_temp;
  int32_T c5_m_a;
  int32_T c5_m_b;
  int32_T c5_n_a;
  int32_T c5_n_b;
  int32_T c5_i325;
  int32_T c5_i326;
  int32_T c5_i327;
  int32_T c5_i328;
  int32_T c5_b_jp1j;
  int32_T c5_o_a;
  int32_T c5_p_a;
  real_T c5_o_b;
  real_T c5_d8;
  real_T c5_d9;
  int32_T c5_i329;
  int32_T c5_p_b;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_b_i;
  real_T c5_t_x;
  real_T c5_e_y;
  real_T c5_u_x;
  real_T c5_f_y;
  real_T c5_z;
  int32_T c5_m;
  int32_T c5_q_a;
  int32_T c5_q_b;
  int32_T c5_d_n;
  int32_T c5_g_ix0;
  int32_T c5_r_a;
  int32_T c5_r_b;
  int32_T c5_d_iy0;
  int32_T c5_i330;
  int32_T c5_i331;
  real_T c5_c_A[36];
  int32_T c5_s_a;
  int32_T c5_s_b;
  int32_T c5_ia0;
  int32_T c5_i332;
  int32_T c5_i333;
  int32_T c5_b_m;
  int32_T c5_e_n;
  int32_T c5_h_ix0;
  int32_T c5_e_iy0;
  int32_T c5_i334;
  int32_T c5_i335;
  real_T c5_d_A[36];
  int32_T c5_b_ia0;
  int32_T c5_i336;
  int32_T c5_i337;
  int32_T c5_c_m;
  int32_T c5_f_n;
  int32_T c5_i_ix0;
  int32_T c5_f_iy0;
  int32_T c5_i338;
  int32_T c5_i339;
  real_T c5_e_A[36];
  int32_T c5_c_ia0;
  int32_T c5_i340;
  int32_T c5_i341;
  int32_T c5_d_m;
  int32_T c5_g_n;
  int32_T c5_j_ix0;
  int32_T c5_g_iy0;
  int32_T c5_i342;
  int32_T c5_i343;
  real_T c5_f_A[36];
  int32_T c5_d_ia0;
  int32_T c5_i344;
  int32_T c5_i345;
  int32_T c5_e_m;
  int32_T c5_h_n;
  real_T c5_alpha1;
  int32_T c5_k_ix0;
  int32_T c5_h_iy0;
  int32_T c5_i346;
  int32_T c5_i347;
  real_T c5_g_A[36];
  int32_T c5_e_ia0;
  int32_T c5_i348;
  int32_T c5_i349;
  int32_T c5_v_x;
  int32_T c5_ixstart;
  int32_T c5_t_a;
  real_T c5_t_b;
  real_T c5_d10;
  real_T c5_d11;
  int32_T c5_i350;
  int32_T c5_jA;
  int32_T c5_w_x;
  int32_T c5_jy;
  int32_T c5_i351;
  int32_T c5_c_loop_ub;
  int32_T c5_c_j;
  real_T c5_yjy;
  real_T c5_b_temp;
  int32_T c5_c_ix;
  real_T c5_u_a;
  int32_T c5_u_b;
  real_T c5_d12;
  real_T c5_d13;
  int32_T c5_i352;
  int32_T c5_i353;
  int32_T c5_v_a;
  int32_T c5_v_b;
  int32_T c5_d_loop_ub;
  int32_T c5_ijA;
  int32_T c5_b_ijA;
  int32_T c5_w_a;
  int32_T c5_w_b;
  int32_T c5_x_a;
  int32_T c5_x_b;
  int32_T c5_y_a;
  int32_T c5_y_b;
  int32_T c5_x_x;
  for (c5_i296 = 0; c5_i296 < 6; c5_i296 = c5_i296 + 1) {
    for (c5_i297 = 0; c5_i297 < 6; c5_i297 = c5_i297 + 1) {
      c5_b_A[c5_i297 + 6 * c5_i296] = c5_A[c5_i297 + 6 * c5_i296];
    }
  }

  for (c5_i298 = 0; c5_i298 < 6; c5_i298 = c5_i298 + 1) {
    c5_hoistedExpr = 0;
    c5_x[c5_i298] = 1 + c5_i298;
  }

  for (c5_i299 = 0; c5_i299 < 6; c5_i299 = c5_i299 + 1) {
    c5_ipiv[c5_i299] = c5_x[c5_i299];
  }

  *c5_info = 0;
  c5_i300 = 1;
  for (c5_j = c5_i300; c5_j < 6; c5_j = c5_j + 1) {
    c5_b_j = c5_j;
    c5_a = c5_b_j;
    c5_b = 1.0;
    c5_d0 = c5_b;
    c5_d1 = c5_d0 < 0.0 ? ceil(c5_d0 - 0.5) : floor(c5_d0 + 0.5);
    if (c5_d1 < 2.147483648E+009) {
      if (c5_d1 >= -2.147483648E+009) {
        c5_i301 = (int32_T)c5_d1;
      } else {
        c5_i301 = MIN_int32_T;
      }
    } else {
      c5_i301 = MAX_int32_T;
    }

    c5_jm1 = c5_a - c5_i301;
    c5_b_a = 6;
    c5_b_b = c5_b_j;
    c5_mmj = c5_b_a - c5_b_b;
    c5_c_a = 1;
    c5_d_a = c5_jm1;
    c5_c_b = 7;
    c5_d_b = c5_d_a * c5_c_b;
    c5_jj = c5_c_a + c5_d_b;
    c5_e_a = c5_jj;
    c5_e_b = 1.0;
    c5_d2 = c5_e_b;
    c5_d3 = c5_d2 < 0.0 ? ceil(c5_d2 - 0.5) : floor(c5_d2 + 0.5);
    if (c5_d3 < 2.147483648E+009) {
      if (c5_d3 >= -2.147483648E+009) {
        c5_i302 = (int32_T)c5_d3;
      } else {
        c5_i302 = MIN_int32_T;
      }
    } else {
      c5_i302 = MAX_int32_T;
    }

    c5_jp1j = c5_e_a + c5_i302;
    c5_f_a = c5_mmj;
    c5_f_b = 1.0;
    c5_d4 = c5_f_b;
    c5_d5 = c5_d4 < 0.0 ? ceil(c5_d4 - 0.5) : floor(c5_d4 + 0.5);
    if (c5_d5 < 2.147483648E+009) {
      if (c5_d5 >= -2.147483648E+009) {
        c5_i303 = (int32_T)c5_d5;
      } else {
        c5_i303 = MIN_int32_T;
      }
    } else {
      c5_i303 = MAX_int32_T;
    }

    c5_n = c5_f_a + c5_i303;
    for (c5_i304 = 0; c5_i304 < 6; c5_i304 = c5_i304 + 1) {
      for (c5_i305 = 0; c5_i305 < 6; c5_i305 = c5_i305 + 1) {
        c5_b_x[c5_i305 + 6 * c5_i304] = c5_b_A[c5_i305 + 6 * c5_i304];
      }
    }

    c5_ix0 = c5_jj;
    c5_incx = 1;
    c5_b_n = c5_n;
    for (c5_i306 = 0; c5_i306 < 6; c5_i306 = c5_i306 + 1) {
      for (c5_i307 = 0; c5_i307 < 6; c5_i307 = c5_i307 + 1) {
        c5_c_x[c5_i307 + 6 * c5_i306] = c5_b_x[c5_i307 + 6 * c5_i306];
      }
    }

    c5_b_ix0 = c5_ix0;
    c5_b_incx = c5_incx;
    c5_c_n = c5_b_n;
    for (c5_i308 = 0; c5_i308 < 6; c5_i308 = c5_i308 + 1) {
      for (c5_i309 = 0; c5_i309 < 6; c5_i309 = c5_i309 + 1) {
        c5_d_x[c5_i309 + 6 * c5_i308] = c5_c_x[c5_i309 + 6 * c5_i308];
      }
    }

    c5_c_ix0 = c5_b_ix0;
    c5_c_incx = c5_b_incx;
    c5_ONE = 1;
    if ((real_T)c5_c_n < 1.0) {
    } else if ((real_T)c5_c_incx < 1.0) {
    } else {
      c5_g_a = c5_ONE;
      if ((real_T)c5_c_n > 1.0) {
        c5_e_x = c5_c_ix0;
        c5_ix = c5_e_x;
        c5_f_x = c5_c_incx;
        c5_ixinc = c5_f_x;
        c5_g_x = c5_d_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
          _SFD_INTEGER_CHECK("ix", (real_T)c5_ix), 1, 36, 1, 0) - 1];
        c5_h_x = 0.0;
        c5_y = fabs(c5_h_x);
        c5_i_x = c5_g_x;
        c5_b_y = fabs(c5_i_x);
        c5_smax = c5_b_y + c5_y;
        c5_i310 = 2;
        c5_loop_ub = c5_c_n;
        for (c5_k = c5_i310; c5_k <= c5_loop_ub; c5_k = c5_k + 1) {
          c5_b_k = c5_k;
          c5_h_a = c5_ix;
          c5_g_b = c5_ixinc;
          c5_ix = c5_h_a + c5_g_b;
          c5_j_x = c5_d_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
            _SFD_INTEGER_CHECK("ix", (real_T)c5_ix), 1, 36, 1, 0) - 1];
          c5_k_x = 0.0;
          c5_c_y = fabs(c5_k_x);
          c5_l_x = c5_j_x;
          c5_d_y = fabs(c5_l_x);
          c5_s = c5_d_y + c5_c_y;
          if (c5_s > c5_smax) {
            c5_g_a = c5_b_k;
            c5_smax = c5_s;
          }
        }
      }

      goto label_1;
    }

    c5_g_a = 0;
   label_1:
    ;
    c5_h_b = 1.0;
    c5_d6 = c5_h_b;
    c5_d7 = c5_d6 < 0.0 ? ceil(c5_d6 - 0.5) : floor(c5_d6 + 0.5);
    if (c5_d7 < 2.147483648E+009) {
      if (c5_d7 >= -2.147483648E+009) {
        c5_i311 = (int32_T)c5_d7;
      } else {
        c5_i311 = MIN_int32_T;
      }
    } else {
      c5_i311 = MAX_int32_T;
    }

    c5_jpiv_offset = c5_g_a - c5_i311;
    c5_i_a = c5_jj;
    c5_i_b = c5_jpiv_offset;
    c5_jpiv = c5_i_a + c5_i_b;
    if (c5_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK(
          "jpiv", (real_T)c5_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if ((real_T)c5_jpiv_offset != 0.0) {
        c5_j_a = c5_b_j;
        c5_j_b = c5_jpiv_offset;
        c5_c = c5_j_a + c5_j_b;
        c5_ipiv[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv", _SFD_INTEGER_CHECK(
          "j", (real_T)c5_b_j), 1, 6, 1, 0) - 1] = c5_c;
        c5_k_a = 1;
        c5_k_b = c5_jm1;
        c5_jrow = c5_k_a + c5_k_b;
        c5_l_a = c5_jrow;
        c5_l_b = c5_jpiv_offset;
        c5_jprow = c5_l_a + c5_l_b;
        for (c5_i312 = 0; c5_i312 < 6; c5_i312 = c5_i312 + 1) {
          for (c5_i313 = 0; c5_i313 < 6; c5_i313 = c5_i313 + 1) {
            c5_m_x[c5_i313 + 6 * c5_i312] = c5_b_A[c5_i313 + 6 * c5_i312];
          }
        }

        c5_d_ix0 = c5_jrow;
        c5_iy0 = c5_jprow;
        for (c5_i314 = 0; c5_i314 < 6; c5_i314 = c5_i314 + 1) {
          for (c5_i315 = 0; c5_i315 < 6; c5_i315 = c5_i315 + 1) {
            c5_b_A[c5_i315 + 6 * c5_i314] = c5_m_x[c5_i315 + 6 * c5_i314];
          }
        }

        for (c5_i316 = 0; c5_i316 < 6; c5_i316 = c5_i316 + 1) {
          for (c5_i317 = 0; c5_i317 < 6; c5_i317 = c5_i317 + 1) {
            c5_n_x[c5_i317 + 6 * c5_i316] = c5_b_A[c5_i317 + 6 * c5_i316];
          }
        }

        c5_e_ix0 = c5_d_ix0;
        c5_b_iy0 = c5_iy0;
        for (c5_i318 = 0; c5_i318 < 6; c5_i318 = c5_i318 + 1) {
          for (c5_i319 = 0; c5_i319 < 6; c5_i319 = c5_i319 + 1) {
            c5_o_x[c5_i319 + 6 * c5_i318] = c5_n_x[c5_i319 + 6 * c5_i318];
          }
        }

        for (c5_i320 = 0; c5_i320 < 6; c5_i320 = c5_i320 + 1) {
          for (c5_i321 = 0; c5_i321 < 6; c5_i321 = c5_i321 + 1) {
            c5_p_x[c5_i321 + 6 * c5_i320] = c5_o_x[c5_i321 + 6 * c5_i320];
          }
        }

        c5_f_ix0 = c5_e_ix0;
        c5_c_iy0 = c5_b_iy0;
        for (c5_i322 = 0; c5_i322 < 6; c5_i322 = c5_i322 + 1) {
          for (c5_i323 = 0; c5_i323 < 6; c5_i323 = c5_i323 + 1) {
            c5_q_x[c5_i323 + 6 * c5_i322] = c5_p_x[c5_i323 + 6 * c5_i322];
          }
        }

        c5_r_x = c5_f_ix0;
        c5_b_ix = c5_r_x;
        c5_s_x = c5_c_iy0;
        c5_iy = c5_s_x;
        c5_i324 = 1;
        for (c5_c_k = c5_i324; c5_c_k < 7; c5_c_k = c5_c_k + 1) {
          c5_temp = c5_q_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
            _SFD_INTEGER_CHECK("ix", (real_T)c5_b_ix), 1, 36, 1, 0) - 1];
          c5_q_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK(
            "ix", (real_T)c5_b_ix), 1, 36, 1, 0) - 1] = c5_q_x[(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("iy", (real_T)
            c5_iy), 1, 36, 1, 0) - 1];
          c5_q_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK(
            "iy", (real_T)c5_iy), 1, 36, 1, 0) - 1] = c5_temp;
          c5_m_a = c5_iy;
          c5_m_b = 6;
          c5_iy = c5_m_a + c5_m_b;
          c5_n_a = c5_b_ix;
          c5_n_b = 6;
          c5_b_ix = c5_n_a + c5_n_b;
        }

        for (c5_i325 = 0; c5_i325 < 6; c5_i325 = c5_i325 + 1) {
          for (c5_i326 = 0; c5_i326 < 6; c5_i326 = c5_i326 + 1) {
            c5_o_x[c5_i326 + 6 * c5_i325] = c5_q_x[c5_i326 + 6 * c5_i325];
          }
        }

        for (c5_i327 = 0; c5_i327 < 6; c5_i327 = c5_i327 + 1) {
          for (c5_i328 = 0; c5_i328 < 6; c5_i328 = c5_i328 + 1) {
            c5_b_A[c5_i328 + 6 * c5_i327] = c5_o_x[c5_i328 + 6 * c5_i327];
          }
        }
      }

      c5_b_jp1j = c5_jp1j;
      c5_o_a = c5_jp1j;
      c5_p_a = c5_mmj;
      c5_o_b = 1.0;
      c5_d8 = c5_o_b;
      c5_d9 = c5_d8 < 0.0 ? ceil(c5_d8 - 0.5) : floor(c5_d8 + 0.5);
      if (c5_d9 < 2.147483648E+009) {
        if (c5_d9 >= -2.147483648E+009) {
          c5_i329 = (int32_T)c5_d9;
        } else {
          c5_i329 = MIN_int32_T;
        }
      } else {
        c5_i329 = MAX_int32_T;
      }

      c5_p_b = c5_p_a - c5_i329;
      c5_b_loop_ub = c5_o_a + c5_p_b;
      for (c5_i = c5_b_jp1j; c5_i <= c5_b_loop_ub; c5_i = c5_i + 1) {
        c5_b_i = c5_i;
        c5_t_x = c5_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          _SFD_INTEGER_CHECK("i", (real_T)c5_b_i), 1, 36, 1, 0) - 1];
        c5_e_y = c5_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          _SFD_INTEGER_CHECK("jj", (real_T)c5_jj), 1, 36, 1, 0) - 1];
        c5_u_x = c5_t_x;
        c5_f_y = c5_e_y;
        c5_z = c5_u_x / c5_f_y;
        c5_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("i",
          (real_T)c5_b_i), 1, 36, 1, 0) - 1] = c5_z;
      }
    } else {
      *c5_info = c5_b_j;
    }

    c5_m = c5_mmj;
    c5_q_a = 6;
    c5_q_b = c5_b_j;
    c5_d_n = c5_q_a - c5_q_b;
    c5_g_ix0 = c5_jp1j;
    c5_r_a = c5_jj;
    c5_r_b = 6;
    c5_d_iy0 = c5_r_a + c5_r_b;
    for (c5_i330 = 0; c5_i330 < 6; c5_i330 = c5_i330 + 1) {
      for (c5_i331 = 0; c5_i331 < 6; c5_i331 = c5_i331 + 1) {
        c5_c_A[c5_i331 + 6 * c5_i330] = c5_b_A[c5_i331 + 6 * c5_i330];
      }
    }

    c5_s_a = c5_jj;
    c5_s_b = 7;
    c5_ia0 = c5_s_a + c5_s_b;
    for (c5_i332 = 0; c5_i332 < 6; c5_i332 = c5_i332 + 1) {
      for (c5_i333 = 0; c5_i333 < 6; c5_i333 = c5_i333 + 1) {
        c5_b_A[c5_i333 + 6 * c5_i332] = c5_c_A[c5_i333 + 6 * c5_i332];
      }
    }

    c5_b_m = c5_m;
    c5_e_n = c5_d_n;
    c5_h_ix0 = c5_g_ix0;
    c5_e_iy0 = c5_d_iy0;
    for (c5_i334 = 0; c5_i334 < 6; c5_i334 = c5_i334 + 1) {
      for (c5_i335 = 0; c5_i335 < 6; c5_i335 = c5_i335 + 1) {
        c5_d_A[c5_i335 + 6 * c5_i334] = c5_b_A[c5_i335 + 6 * c5_i334];
      }
    }

    c5_b_ia0 = c5_ia0;
    for (c5_i336 = 0; c5_i336 < 6; c5_i336 = c5_i336 + 1) {
      for (c5_i337 = 0; c5_i337 < 6; c5_i337 = c5_i337 + 1) {
        c5_b_A[c5_i337 + 6 * c5_i336] = c5_d_A[c5_i337 + 6 * c5_i336];
      }
    }

    c5_c_m = c5_b_m;
    c5_f_n = c5_e_n;
    c5_i_ix0 = c5_h_ix0;
    c5_f_iy0 = c5_e_iy0;
    for (c5_i338 = 0; c5_i338 < 6; c5_i338 = c5_i338 + 1) {
      for (c5_i339 = 0; c5_i339 < 6; c5_i339 = c5_i339 + 1) {
        c5_e_A[c5_i339 + 6 * c5_i338] = c5_b_A[c5_i339 + 6 * c5_i338];
      }
    }

    c5_c_ia0 = c5_b_ia0;
    for (c5_i340 = 0; c5_i340 < 6; c5_i340 = c5_i340 + 1) {
      for (c5_i341 = 0; c5_i341 < 6; c5_i341 = c5_i341 + 1) {
        c5_b_A[c5_i341 + 6 * c5_i340] = c5_e_A[c5_i341 + 6 * c5_i340];
      }
    }

    c5_d_m = c5_c_m;
    c5_g_n = c5_f_n;
    c5_j_ix0 = c5_i_ix0;
    c5_g_iy0 = c5_f_iy0;
    for (c5_i342 = 0; c5_i342 < 6; c5_i342 = c5_i342 + 1) {
      for (c5_i343 = 0; c5_i343 < 6; c5_i343 = c5_i343 + 1) {
        c5_f_A[c5_i343 + 6 * c5_i342] = c5_b_A[c5_i343 + 6 * c5_i342];
      }
    }

    c5_d_ia0 = c5_c_ia0;
    for (c5_i344 = 0; c5_i344 < 6; c5_i344 = c5_i344 + 1) {
      for (c5_i345 = 0; c5_i345 < 6; c5_i345 = c5_i345 + 1) {
        c5_b_A[c5_i345 + 6 * c5_i344] = c5_f_A[c5_i345 + 6 * c5_i344];
      }
    }

    c5_e_m = c5_d_m;
    c5_h_n = c5_g_n;
    c5_alpha1 = -1.0;
    c5_k_ix0 = c5_j_ix0;
    c5_h_iy0 = c5_g_iy0;
    for (c5_i346 = 0; c5_i346 < 6; c5_i346 = c5_i346 + 1) {
      for (c5_i347 = 0; c5_i347 < 6; c5_i347 = c5_i347 + 1) {
        c5_g_A[c5_i347 + 6 * c5_i346] = c5_b_A[c5_i347 + 6 * c5_i346];
      }
    }

    c5_e_ia0 = c5_d_ia0;
    for (c5_i348 = 0; c5_i348 < 6; c5_i348 = c5_i348 + 1) {
      for (c5_i349 = 0; c5_i349 < 6; c5_i349 = c5_i349 + 1) {
        c5_b_A[c5_i349 + 6 * c5_i348] = c5_g_A[c5_i349 + 6 * c5_i348];
      }
    }

    if (c5_alpha1 == 0.0) {
    } else {
      c5_v_x = c5_k_ix0;
      c5_ixstart = c5_v_x;
      c5_t_a = c5_e_ia0;
      c5_t_b = 1.0;
      c5_d10 = c5_t_b;
      c5_d11 = c5_d10 < 0.0 ? ceil(c5_d10 - 0.5) : floor(c5_d10 + 0.5);
      if (c5_d11 < 2.147483648E+009) {
        if (c5_d11 >= -2.147483648E+009) {
          c5_i350 = (int32_T)c5_d11;
        } else {
          c5_i350 = MIN_int32_T;
        }
      } else {
        c5_i350 = MAX_int32_T;
      }

      c5_jA = c5_t_a - c5_i350;
      c5_w_x = c5_h_iy0;
      c5_jy = c5_w_x;
      c5_i351 = 1;
      c5_c_loop_ub = c5_h_n;
      for (c5_c_j = c5_i351; c5_c_j <= c5_c_loop_ub; c5_c_j = c5_c_j + 1) {
        c5_yjy = c5_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          _SFD_INTEGER_CHECK("jy", (real_T)c5_jy), 1, 36, 1, 0) - 1];
        if (c5_yjy != 0.0) {
          c5_b_temp = c5_yjy * c5_alpha1;
          c5_c_ix = c5_ixstart;
          c5_u_a = 1.0;
          c5_u_b = c5_jA;
          c5_d12 = c5_u_a;
          c5_d13 = c5_d12 < 0.0 ? ceil(c5_d12 - 0.5) : floor(c5_d12 + 0.5);
          if (c5_d13 < 2.147483648E+009) {
            if (c5_d13 >= -2.147483648E+009) {
              c5_i352 = (int32_T)c5_d13;
            } else {
              c5_i352 = MIN_int32_T;
            }
          } else {
            c5_i352 = MAX_int32_T;
          }

          c5_i353 = c5_i352 + c5_u_b;
          c5_v_a = c5_e_m;
          c5_v_b = c5_jA;
          c5_d_loop_ub = c5_v_a + c5_v_b;
          for (c5_ijA = c5_i353; c5_ijA <= c5_d_loop_ub; c5_ijA = c5_ijA + 1) {
            c5_b_ijA = c5_ijA;
            c5_b_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK(
              "ijA", (real_T)c5_b_ijA), 1, 36, 1, 0) - 1] = c5_b_A[(int32_T)
              _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("ijA", (real_T)
              c5_b_ijA), 1, 36, 1, 0) - 1] + c5_b_A[(int32_T)
              _SFD_EML_ARRAY_BOUNDS_CHECK("A", _SFD_INTEGER_CHECK("ix", (real_T)
              c5_c_ix), 1, 36, 1, 0) - 1] * c5_b_temp;
            c5_w_a = c5_c_ix;
            c5_w_b = 1;
            c5_c_ix = c5_w_a + c5_w_b;
          }
        }

        c5_x_a = c5_jy;
        c5_x_b = 6;
        c5_jy = c5_x_a + c5_x_b;
        c5_y_a = c5_jA;
        c5_y_b = 6;
        c5_jA = c5_y_a + c5_y_b;
      }
    }
  }

  if ((real_T)*c5_info == 0.0) {
    if (!(c5_b_A[35] != 0.0)) {
      c5_x_x = 6;
      *c5_info = c5_x_x;
    }
  }
}

static void c5_eml_warning(void)
{
  int32_T c5_i354;
  static char c5_cv0[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  char c5_varargin_1[21];
  int32_T c5_i355;
  static char c5_cv1[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o',
    ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char c5_varargin_2[40];
  int32_T c5_i356;
  char c5_u[21];
  const mxArray *c5_y = NULL;
  int32_T c5_i357;
  char c5_b_u[40];
  const mxArray *c5_b_y = NULL;
  for (c5_i354 = 0; c5_i354 < 21; c5_i354 = c5_i354 + 1) {
    c5_varargin_1[c5_i354] = c5_cv0[c5_i354];
  }

  for (c5_i355 = 0; c5_i355 < 40; c5_i355 = c5_i355 + 1) {
    c5_varargin_2[c5_i355] = c5_cv1[c5_i355];
  }

  for (c5_i356 = 0; c5_i356 < 21; c5_i356 = c5_i356 + 1) {
    c5_u[c5_i356] = c5_varargin_1[c5_i356];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create(&c5_u, "y", 8, 0U, 1U, 2, 1, 21));
  for (c5_i357 = 0; c5_i357 < 40; c5_i357 = c5_i357 + 1) {
    c5_b_u[c5_i357] = c5_varargin_2[c5_i357];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 8, 0U, 1U, 2, 1, 40));
  sf_mex_call("warning", 0U, 2U, 14, c5_y, 14, c5_b_y);
}

static real_T c5_eye(void)
{
  real_T c5_one;
  c5_one = 1.0;
  return c5_one;
}

static const mxArray *c5_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_b_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i358;
  real_T c5_b_u[6];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for (c5_i358 = 0; c5_i358 < 6; c5_i358 = c5_i358 + 1) {
    c5_b_u[c5_i358] = (*((real_T (*)[6])c5_u))[c5_i358];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 6));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_c_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i359;
  real_T c5_b_u[6];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for (c5_i359 = 0; c5_i359 < 6; c5_i359 = c5_i359 + 1) {
    c5_b_u[c5_i359] = (*((real_T (*)[6])c5_u))[c5_i359];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 1, 6));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_MPC_AVC_implementation_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[97];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i360;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  c5_b_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 97));
  for (c5_i360 = 0; c5_i360 < 97; c5_i360 = c5_i360 + 1) {
    c5_r0 = &c5_info[c5_i360];
    sf_mex_addfield(c5_m0, sf_mex_create(c5_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
                    "nameCaptureInfo", c5_i360);
    sf_mex_addfield(c5_m0, sf_mex_create(c5_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c5_r0->name)), "name",
                    "nameCaptureInfo", c5_i360);
    sf_mex_addfield(c5_m0, sf_mex_create(c5_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c5_i360);
    sf_mex_addfield(c5_m0, sf_mex_create(c5_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved",
                    "nameCaptureInfo", c5_i360);
    sf_mex_addfield(c5_m0, sf_mex_create(&c5_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c5_i360);
    sf_mex_addfield(c5_m0, sf_mex_create(&c5_r0->fileTime1, "nameCaptureInfo", 7,
      0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i360);
    sf_mex_addfield(c5_m0, sf_mex_create(&c5_r0->fileTime2, "nameCaptureInfo", 7,
      0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i360);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[97])
{
  c5_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c5_info[0].name = "eml_assert_valid_size_arg";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[0].fileLength = 1360U;
  c5_info[0].fileTime1 = 1192466766U;
  c5_info[0].fileTime2 = 0U;
  c5_info[1].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c5_info[1].name = "intmin";
  c5_info[1].dominantType = "char";
  c5_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c5_info[1].fileLength = 1505U;
  c5_info[1].fileTime1 = 1192466730U;
  c5_info[1].fileTime2 = 0U;
  c5_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[2].name = "eml_min_or_max";
  c5_info[2].dominantType = "int32";
  c5_info[2].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[2].fileLength = 7337U;
  c5_info[2].fileTime1 = 1192466798U;
  c5_info[2].fileTime2 = 0U;
  c5_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[3].name = "isreal";
  c5_info[3].dominantType = "int32";
  c5_info[3].resolved = "[B]isreal";
  c5_info[3].fileLength = 0U;
  c5_info[3].fileTime1 = 0U;
  c5_info[3].fileTime2 = 0U;
  c5_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c5_info[4].name = "floor";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[4].fileLength = 550U;
  c5_info[4].fileTime1 = 1192466686U;
  c5_info[4].fileTime2 = 0U;
  c5_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xger.m";
  c5_info[5].name = "eml_refblas_xger";
  c5_info[5].dominantType = "int32";
  c5_info[5].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c5_info[5].fileLength = 357U;
  c5_info[5].fileTime1 = 1192466876U;
  c5_info[5].fileTime2 = 0U;
  c5_info[6].context = "";
  c5_info[6].name = "mtimes";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[6].fileLength = 1990U;
  c5_info[6].fileTime1 = 1197652350U;
  c5_info[6].fileTime2 = 0U;
  c5_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[7].name = "ndims";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved = "[B]ndims";
  c5_info[7].fileLength = 0U;
  c5_info[7].fileTime1 = 0U;
  c5_info[7].fileTime2 = 0U;
  c5_info[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/assert_integral";
  c5_info[8].name = "ne";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[B]ne";
  c5_info[8].fileLength = 0U;
  c5_info[8].fileTime1 = 0U;
  c5_info[8].fileTime2 = 0U;
  c5_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[9].name = "cast";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c5_info[9].fileLength = 866U;
  c5_info[9].fileTime1 = 1192466644U;
  c5_info[9].fileTime2 = 0U;
  c5_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[10].name = "strcmp";
  c5_info[10].dominantType = "char";
  c5_info[10].resolved = "[B]strcmp";
  c5_info[10].fileLength = 0U;
  c5_info[10].fileTime1 = 0U;
  c5_info[10].fileTime2 = 0U;
  c5_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[11].name = "eml_ixamax";
  c5_info[11].dominantType = "int32";
  c5_info[11].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c5_info[11].fileLength = 646U;
  c5_info[11].fileTime1 = 1192466828U;
  c5_info[11].fileTime2 = 0U;
  c5_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[12].name = "false";
  c5_info[12].dominantType = "";
  c5_info[12].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c5_info[12].fileLength = 238U;
  c5_info[12].fileTime1 = 1192466720U;
  c5_info[12].fileTime2 = 0U;
  c5_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c5_info[13].name = "eml_set_singleton_dim";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_set_singleton_dim.m";
  c5_info[13].fileLength = 375U;
  c5_info[13].fileTime1 = 1192466806U;
  c5_info[13].fileTime2 = 0U;
  c5_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[14].name = "eml_warning";
  c5_info[14].dominantType = "char";
  c5_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c5_info[14].fileLength = 265U;
  c5_info[14].fileTime1 = 1192466814U;
  c5_info[14].fileTime2 = 0U;
  c5_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c5_info[15].name = "eml_refblas_xgerx";
  c5_info[15].dominantType = "int32";
  c5_info[15].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[15].fileLength = 2218U;
  c5_info[15].fileTime1 = 1195314402U;
  c5_info[15].fileTime2 = 0U;
  c5_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c5_info[16].name = "isstruct";
  c5_info[16].dominantType = "int32";
  c5_info[16].resolved = "[B]isstruct";
  c5_info[16].fileLength = 0U;
  c5_info[16].fileTime1 = 0U;
  c5_info[16].fileTime2 = 0U;
  c5_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[17].name = "eml_xdotu";
  c5_info[17].dominantType = "int32";
  c5_info[17].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c5_info[17].fileLength = 1346U;
  c5_info[17].fileTime1 = 1195314372U;
  c5_info[17].fileTime2 = 0U;
  c5_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c5_info[18].name = "imag";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved = "[B]imag";
  c5_info[18].fileLength = 0U;
  c5_info[18].fileTime1 = 0U;
  c5_info[18].fileTime2 = 0U;
  c5_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c5_info[19].name = "realmax";
  c5_info[19].dominantType = "";
  c5_info[19].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c5_info[19].fileLength = 498U;
  c5_info[19].fileTime1 = 1192466750U;
  c5_info[19].fileTime2 = 0U;
  c5_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[20].name = "eml_div";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[20].fileLength = 4254U;
  c5_info[20].fileTime1 = 1192466772U;
  c5_info[20].fileTime2 = 0U;
  c5_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[21].name = "power";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[21].fileLength = 4979U;
  c5_info[21].fileTime1 = 1192466920U;
  c5_info[21].fileTime2 = 0U;
  c5_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c5_info[22].name = "real";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved = "[B]real";
  c5_info[22].fileLength = 0U;
  c5_info[22].fileTime1 = 0U;
  c5_info[22].fileTime2 = 0U;
  c5_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c5_info[23].name = "eml_check_dim";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c5_info[23].fileLength = 1434U;
  c5_info[23].fileTime1 = 1192466768U;
  c5_info[23].fileTime2 = 0U;
  c5_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[24].name = "size";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved = "[B]size";
  c5_info[24].fileLength = 0U;
  c5_info[24].fileTime1 = 0U;
  c5_info[24].fileTime2 = 0U;
  c5_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c5_info[25].name = "eml_scalexp_size";
  c5_info[25].dominantType = "int32";
  c5_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c5_info[25].fileLength = 872U;
  c5_info[25].fileTime1 = 1192466806U;
  c5_info[25].fileTime2 = 0U;
  c5_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[26].name = "eml_all_or_any";
  c5_info[26].dominantType = "char";
  c5_info[26].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c5_info[26].fileLength = 3266U;
  c5_info[26].fileTime1 = 1192466764U;
  c5_info[26].fileTime2 = 0U;
  c5_info[27].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[27].name = "times";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved = "[B]times";
  c5_info[27].fileLength = 0U;
  c5_info[27].fileTime1 = 0U;
  c5_info[27].fileTime2 = 0U;
  c5_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c5_info[28].name = "minus";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved = "[B]minus";
  c5_info[28].fileLength = 0U;
  c5_info[28].fileTime1 = 0U;
  c5_info[28].fileTime2 = 0U;
  c5_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c5_info[29].name = "abs";
  c5_info[29].dominantType = "double";
  c5_info[29].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[29].fileLength = 990U;
  c5_info[29].fileTime1 = 1192466652U;
  c5_info[29].fileTime2 = 0U;
  c5_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c5_info[30].name = "eml_varargin_to_size";
  c5_info[30].dominantType = "double";
  c5_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_varargin_to_size.m";
  c5_info[30].fileLength = 625U;
  c5_info[30].fileTime1 = 1192466812U;
  c5_info[30].fileTime2 = 0U;
  c5_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c5_info[31].name = "ischar";
  c5_info[31].dominantType = "char";
  c5_info[31].resolved = "[B]ischar";
  c5_info[31].fileLength = 0U;
  c5_info[31].fileTime1 = 0U;
  c5_info[31].fileTime2 = 0U;
  c5_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xtrsm.m";
  c5_info[32].name = "eml_refblas_xtrsm";
  c5_info[32].dominantType = "int32";
  c5_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[32].fileLength = 8422U;
  c5_info[32].fileTime1 = 1195314406U;
  c5_info[32].fileTime2 = 0U;
  c5_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_ixamax.m";
  c5_info[33].name = "eml_refblas_ixamax";
  c5_info[33].dominantType = "int32";
  c5_info[33].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c5_info[33].fileLength = 740U;
  c5_info[33].fileTime1 = 1192466866U;
  c5_info[33].fileTime2 = 0U;
  c5_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[34].name = "eml_isa_uint";
  c5_info[34].dominantType = "double";
  c5_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c5_info[34].fileLength = 239U;
  c5_info[34].fileTime1 = 1192466792U;
  c5_info[34].fileTime2 = 0U;
  c5_info[35].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c5_info[35].name = "intmax";
  c5_info[35].dominantType = "char";
  c5_info[35].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[35].fileLength = 1535U;
  c5_info[35].fileTime1 = 1192466728U;
  c5_info[35].fileTime2 = 0U;
  c5_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[36].name = "eml_xswap";
  c5_info[36].dominantType = "int32";
  c5_info[36].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c5_info[36].fileLength = 1219U;
  c5_info[36].fileTime1 = 1192466844U;
  c5_info[36].fileTime2 = 0U;
  c5_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c5_info[37].name = "eml_blas_xswap";
  c5_info[37].dominantType = "int32";
  c5_info[37].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xswap.m";
  c5_info[37].fileLength = 245U;
  c5_info[37].fileTime1 = 1192466864U;
  c5_info[37].fileTime2 = 0U;
  c5_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c5_info[38].name = "uminus";
  c5_info[38].dominantType = "double";
  c5_info[38].resolved = "[B]uminus";
  c5_info[38].fileLength = 0U;
  c5_info[38].fileTime1 = 0U;
  c5_info[38].fileTime2 = 0U;
  c5_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[39].name = "eml_assert";
  c5_info[39].dominantType = "char";
  c5_info[39].resolved = "[B]eml_assert";
  c5_info[39].fileLength = 0U;
  c5_info[39].fileTime1 = 0U;
  c5_info[39].fileTime2 = 0U;
  c5_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[40].name = "isinteger";
  c5_info[40].dominantType = "double";
  c5_info[40].resolved = "[B]isinteger";
  c5_info[40].fileLength = 0U;
  c5_info[40].fileTime1 = 0U;
  c5_info[40].fileTime2 = 0U;
  c5_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c5_info[41].name = "eml_blas_xdot";
  c5_info[41].dominantType = "int32";
  c5_info[41].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xdot.m";
  c5_info[41].fileLength = 238U;
  c5_info[41].fileTime1 = 1192466852U;
  c5_info[41].fileTime2 = 0U;
  c5_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c5_info[42].name = "eml_lusolve";
  c5_info[42].dominantType = "double";
  c5_info[42].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[42].fileLength = 824U;
  c5_info[42].fileTime1 = 1195314368U;
  c5_info[42].fileTime2 = 0U;
  c5_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[43].name = "class";
  c5_info[43].dominantType = "double";
  c5_info[43].resolved = "[B]class";
  c5_info[43].fileLength = 0U;
  c5_info[43].fileTime1 = 0U;
  c5_info[43].fileTime2 = 0U;
  c5_info[44].context = "";
  c5_info[44].name = "ctranspose";
  c5_info[44].dominantType = "double";
  c5_info[44].resolved = "[B]ctranspose";
  c5_info[44].fileLength = 0U;
  c5_info[44].fileTime1 = 0U;
  c5_info[44].fileTime2 = 0U;
  c5_info[45].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_scalar_bin_extremum";
  c5_info[45].name = "isnan";
  c5_info[45].dominantType = "int32";
  c5_info[45].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c5_info[45].fileLength = 472U;
  c5_info[45].fileTime1 = 1192466736U;
  c5_info[45].fileTime2 = 0U;
  c5_info[46].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c5_info[46].name = "double";
  c5_info[46].dominantType = "double";
  c5_info[46].resolved = "[B]double";
  c5_info[46].fileLength = 0U;
  c5_info[46].fileTime1 = 0U;
  c5_info[46].fileTime2 = 0U;
  c5_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[47].name = "isa";
  c5_info[47].dominantType = "double";
  c5_info[47].resolved = "[B]isa";
  c5_info[47].fileLength = 0U;
  c5_info[47].fileTime1 = 0U;
  c5_info[47].fileTime2 = 0U;
  c5_info[48].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c5_info[48].name = "zeros";
  c5_info[48].dominantType = "double";
  c5_info[48].resolved = "[B]zeros";
  c5_info[48].fileLength = 0U;
  c5_info[48].fileTime1 = 0U;
  c5_info[48].fileTime2 = 0U;
  c5_info[49].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[49].name = "colon";
  c5_info[49].dominantType = "int32";
  c5_info[49].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c5_info[49].fileLength = 7324U;
  c5_info[49].fileTime1 = 1197300746U;
  c5_info[49].fileTime2 = 0U;
  c5_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[50].name = "isnumeric";
  c5_info[50].dominantType = "int32";
  c5_info[50].resolved = "[B]isnumeric";
  c5_info[50].fileLength = 0U;
  c5_info[50].fileTime1 = 0U;
  c5_info[50].fileTime2 = 0U;
  c5_info[51].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[51].name = "le";
  c5_info[51].dominantType = "double";
  c5_info[51].resolved = "[B]le";
  c5_info[51].fileLength = 0U;
  c5_info[51].fileTime1 = 0U;
  c5_info[51].fileTime2 = 0U;
  c5_info[52].context = "";
  c5_info[52].name = "eq";
  c5_info[52].dominantType = "double";
  c5_info[52].resolved = "[B]eq";
  c5_info[52].fileLength = 0U;
  c5_info[52].fileTime1 = 0U;
  c5_info[52].fileTime2 = 0U;
  c5_info[53].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[53].name = "min";
  c5_info[53].dominantType = "int32";
  c5_info[53].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[53].fileLength = 308U;
  c5_info[53].fileTime1 = 1192466634U;
  c5_info[53].fileTime2 = 0U;
  c5_info[54].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[54].name = "eml_scalexp_compatible";
  c5_info[54].dominantType = "int32";
  c5_info[54].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c5_info[54].fileLength = 376U;
  c5_info[54].fileTime1 = 1192466804U;
  c5_info[54].fileTime2 = 0U;
  c5_info[55].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[55].name = "ones";
  c5_info[55].dominantType = "char";
  c5_info[55].resolved = "[B]ones";
  c5_info[55].fileLength = 0U;
  c5_info[55].fileTime1 = 0U;
  c5_info[55].fileTime2 = 0U;
  c5_info[56].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c5_info[56].name = "eml_blas_xtrsm";
  c5_info[56].dominantType = "int32";
  c5_info[56].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xtrsm.m";
  c5_info[56].fileLength = 333U;
  c5_info[56].fileTime1 = 1192466864U;
  c5_info[56].fileTime2 = 0U;
  c5_info[57].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/assert_integral";
  c5_info[57].name = "true";
  c5_info[57].dominantType = "";
  c5_info[57].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c5_info[57].fileLength = 237U;
  c5_info[57].fileTime1 = 1192466762U;
  c5_info[57].fileTime2 = 0U;
  c5_info[58].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m/binary_isequal";
  c5_info[58].name = "all";
  c5_info[58].dominantType = "logical";
  c5_info[58].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[58].fileLength = 400U;
  c5_info[58].fileTime1 = 1192466904U;
  c5_info[58].fileTime2 = 0U;
  c5_info[59].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[59].name = "mldivide";
  c5_info[59].dominantType = "double";
  c5_info[59].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c5_info[59].fileLength = 844U;
  c5_info[59].fileTime1 = 1197300748U;
  c5_info[59].fileTime2 = 0U;
  c5_info[60].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[60].name = "gt";
  c5_info[60].dominantType = "double";
  c5_info[60].resolved = "[B]gt";
  c5_info[60].fileLength = 0U;
  c5_info[60].fileTime1 = 0U;
  c5_info[60].fileTime2 = 0U;
  c5_info[61].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[61].name = "eml_error";
  c5_info[61].dominantType = "char";
  c5_info[61].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[61].fileLength = 318U;
  c5_info[61].fileTime1 = 1192466776U;
  c5_info[61].fileTime2 = 0U;
  c5_info[62].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[62].name = "eml_index_plus";
  c5_info[62].dominantType = "int32";
  c5_info[62].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[62].fileLength = 272U;
  c5_info[62].fileTime1 = 1192466786U;
  c5_info[62].fileTime2 = 0U;
  c5_info[63].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[63].name = "isscalar";
  c5_info[63].dominantType = "double";
  c5_info[63].resolved = "[B]isscalar";
  c5_info[63].fileLength = 0U;
  c5_info[63].fileTime1 = 0U;
  c5_info[63].fileTime2 = 0U;
}

static void c5_b_info_helper(c5_ResolvedFunctionInfo c5_info[97])
{
  c5_info[64].context = "";
  c5_info[64].name = "plus";
  c5_info[64].dominantType = "double";
  c5_info[64].resolved = "[B]plus";
  c5_info[64].fileLength = 0U;
  c5_info[64].fileTime1 = 0U;
  c5_info[64].fileTime2 = 0U;
  c5_info[65].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[65].name = "eml_index_minus";
  c5_info[65].dominantType = "int32";
  c5_info[65].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c5_info[65].fileLength = 277U;
  c5_info[65].fileTime1 = 1192466784U;
  c5_info[65].fileTime2 = 0U;
  c5_info[66].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[66].name = "eml_xtrsm";
  c5_info[66].dominantType = "int32";
  c5_info[66].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c5_info[66].fileLength = 2205U;
  c5_info[66].fileTime1 = 1195314374U;
  c5_info[66].fileTime2 = 0U;
  c5_info[67].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[67].name = "ge";
  c5_info[67].dominantType = "double";
  c5_info[67].resolved = "[B]ge";
  c5_info[67].fileLength = 0U;
  c5_info[67].fileTime1 = 0U;
  c5_info[67].fileTime2 = 0U;
  c5_info[68].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c5_info[68].name = "mpower";
  c5_info[68].dominantType = "double";
  c5_info[68].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[68].fileLength = 3338U;
  c5_info[68].fileTime1 = 1192466918U;
  c5_info[68].fileTime2 = 0U;
  c5_info[69].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c5_info[69].name = "logical";
  c5_info[69].dominantType = "double";
  c5_info[69].resolved = "[B]logical";
  c5_info[69].fileLength = 0U;
  c5_info[69].fileTime1 = 0U;
  c5_info[69].fileTime2 = 0U;
  c5_info[70].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[70].name = "nargin";
  c5_info[70].dominantType = "";
  c5_info[70].resolved = "[B]nargin";
  c5_info[70].fileLength = 0U;
  c5_info[70].fileTime1 = 0U;
  c5_info[70].fileTime2 = 0U;
  c5_info[71].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xswap.m";
  c5_info[71].name = "eml_refblas_xswap";
  c5_info[71].dominantType = "int32";
  c5_info[71].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c5_info[71].fileLength = 981U;
  c5_info[71].fileTime1 = 1192466884U;
  c5_info[71].fileTime2 = 0U;
  c5_info[72].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c5_info[72].name = "islogical";
  c5_info[72].dominantType = "int32";
  c5_info[72].resolved = "[B]islogical";
  c5_info[72].fileLength = 0U;
  c5_info[72].fileTime1 = 0U;
  c5_info[72].fileTime2 = 0U;
  c5_info[73].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c5_info[73].name = "int32";
  c5_info[73].dominantType = "double";
  c5_info[73].resolved = "[B]int32";
  c5_info[73].fileLength = 0U;
  c5_info[73].fileTime1 = 0U;
  c5_info[73].fileTime2 = 0U;
  c5_info[74].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[74].name = "nargout";
  c5_info[74].dominantType = "";
  c5_info[74].resolved = "[B]nargout";
  c5_info[74].fileLength = 0U;
  c5_info[74].fileTime1 = 0U;
  c5_info[74].fileTime2 = 0U;
  c5_info[75].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c5_info[75].name = "lt";
  c5_info[75].dominantType = "double";
  c5_info[75].resolved = "[B]lt";
  c5_info[75].fileLength = 0U;
  c5_info[75].fileTime1 = 0U;
  c5_info[75].fileTime2 = 0U;
  c5_info[76].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c5_info[76].name = "isequal";
  c5_info[76].dominantType = "char";
  c5_info[76].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c5_info[76].fileLength = 2029U;
  c5_info[76].fileTime1 = 1192466732U;
  c5_info[76].fileTime2 = 0U;
  c5_info[77].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c5_info[77].name = "eml_xdot";
  c5_info[77].dominantType = "int32";
  c5_info[77].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c5_info[77].fileLength = 1223U;
  c5_info[77].fileTime1 = 1192466832U;
  c5_info[77].fileTime2 = 0U;
  c5_info[78].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c5_info[78].name = "eml_blas_ixamax";
  c5_info[78].dominantType = "int32";
  c5_info[78].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_ixamax.m";
  c5_info[78].fileLength = 216U;
  c5_info[78].fileTime1 = 1192466848U;
  c5_info[78].fileTime2 = 0U;
  c5_info[79].context = "";
  c5_info[79].name = "mrdivide";
  c5_info[79].dominantType = "double";
  c5_info[79].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[79].fileLength = 638U;
  c5_info[79].fileTime1 = 1197300750U;
  c5_info[79].fileTime2 = 0U;
  c5_info[80].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c5_info[80].name = "isempty";
  c5_info[80].dominantType = "double";
  c5_info[80].resolved = "[B]isempty";
  c5_info[80].fileLength = 0U;
  c5_info[80].fileTime1 = 0U;
  c5_info[80].fileTime2 = 0U;
  c5_info[81].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c5_info[81].name = "eml_blas_xger";
  c5_info[81].dominantType = "int32";
  c5_info[81].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xger.m";
  c5_info[81].fileLength = 292U;
  c5_info[81].fileTime1 = 1192466856U;
  c5_info[81].fileTime2 = 0U;
  c5_info[82].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[82].name = "eml_index_times";
  c5_info[82].dominantType = "int32";
  c5_info[82].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c5_info[82].fileLength = 280U;
  c5_info[82].fileTime1 = 1192466788U;
  c5_info[82].fileTime2 = 0U;
  c5_info[83].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c5_info[83].name = "eml_alloc";
  c5_info[83].dominantType = "int32";
  c5_info[83].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c5_info[83].fileLength = 2558U;
  c5_info[83].fileTime1 = 1197300744U;
  c5_info[83].fileTime2 = 0U;
  c5_info[84].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c5_info[84].name = "eml_xger";
  c5_info[84].dominantType = "int32";
  c5_info[84].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c5_info[84].fileLength = 2019U;
  c5_info[84].fileTime1 = 1192466838U;
  c5_info[84].fileTime2 = 0U;
  c5_info[85].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c5_info[85].name = "eml_nonsingleton_dim";
  c5_info[85].dominantType = "logical";
  c5_info[85].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c5_info[85].fileLength = 404U;
  c5_info[85].fileTime1 = 1192466800U;
  c5_info[85].fileTime2 = 0U;
  c5_info[86].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c5_info[86].name = "eml_is_float_class";
  c5_info[86].dominantType = "char";
  c5_info[86].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[86].fileLength = 226U;
  c5_info[86].fileTime1 = 1197652350U;
  c5_info[86].fileTime2 = 0U;
  c5_info[87].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c5_info[87].name = "eml_refblas_xdotx";
  c5_info[87].dominantType = "int32";
  c5_info[87].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c5_info[87].fileLength = 1780U;
  c5_info[87].fileTime1 = 1195314398U;
  c5_info[87].fileTime2 = 0U;
  c5_info[88].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[88].name = "isvector";
  c5_info[88].dominantType = "double";
  c5_info[88].resolved = "[B]isvector";
  c5_info[88].fileLength = 0U;
  c5_info[88].fileTime1 = 0U;
  c5_info[88].fileTime2 = 0U;
  c5_info[89].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[89].name = "eml_xgeru";
  c5_info[89].dominantType = "int32";
  c5_info[89].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c5_info[89].fileLength = 2305U;
  c5_info[89].fileTime1 = 1192466840U;
  c5_info[89].fileTime2 = 0U;
  c5_info[90].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c5_info[90].name = "isinf";
  c5_info[90].dominantType = "double";
  c5_info[90].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c5_info[90].fileLength = 472U;
  c5_info[90].fileTime1 = 1192466734U;
  c5_info[90].fileTime2 = 0U;
  c5_info[91].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[91].name = "eml_xgetrf";
  c5_info[91].dominantType = "int32";
  c5_info[91].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c5_info[91].fileLength = 2211U;
  c5_info[91].fileTime1 = 1192466816U;
  c5_info[91].fileTime2 = 0U;
  c5_info[92].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c5_info[92].name = "eml_xcabs1";
  c5_info[92].dominantType = "double";
  c5_info[92].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c5_info[92].fileLength = 371U;
  c5_info[92].fileTime1 = 1192466830U;
  c5_info[92].fileTime2 = 0U;
  c5_info[93].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/internal/eml_blas_xdot.m";
  c5_info[93].name = "eml_refblas_xdot";
  c5_info[93].dominantType = "int32";
  c5_info[93].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c5_info[93].fileLength = 299U;
  c5_info[93].fileTime1 = 1192466870U;
  c5_info[93].fileTime2 = 0U;
  c5_info[94].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[94].name = "not";
  c5_info[94].dominantType = "logical";
  c5_info[94].resolved = "[B]not";
  c5_info[94].fileLength = 0U;
  c5_info[94].fileTime1 = 0U;
  c5_info[94].fileTime2 = 0U;
  c5_info[95].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[95].name = "eml_index_class";
  c5_info[95].dominantType = "";
  c5_info[95].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[95].fileLength = 909U;
  c5_info[95].fileTime1 = 1192466782U;
  c5_info[95].fileTime2 = 0U;
  c5_info[96].context = "";
  c5_info[96].name = "eye";
  c5_info[96].dominantType = "double";
  c5_info[96].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c5_info[96].fileLength = 1616U;
  c5_info[96].fileTime1 = 1192466720U;
  c5_info[96].fileTime2 = 0U;
}

static void c5_mul_wide_s32(int32_T c5_in0, int32_T c5_in1, uint32_T
  *c5_ptrOutBitsHi, uint32_T *c5_ptrOutBitsLo)
{
  uint32_T c5_absIn0;
  uint32_T c5_absIn1;
  int32_T c5_negativeProduct;
  uint32_T c5_in0Hi;
  uint32_T c5_in0Lo;
  uint32_T c5_in1Hi;
  uint32_T c5_in1Lo;
  uint32_T c5_productHiHi;
  uint32_T c5_productHiLo;
  uint32_T c5_productLoHi;
  uint32_T c5_productLoLo;
  uint32_T c5_carry;
  uint32_T c5_outBitsLo;
  uint32_T c5_outBitsHi;
  c5_absIn0 = (uint32_T)(c5_in0 < 0 ? -c5_in0 : c5_in0);
  c5_absIn1 = (uint32_T)(c5_in1 < 0 ? -c5_in1 : c5_in1);
  c5_negativeProduct = !((c5_in0 == 0) || (c5_in1 == 0) || (c5_in0 > 0 == c5_in1
    > 0));
  c5_in0Hi = c5_absIn0 >> 16;
  c5_in0Lo = c5_absIn0 & 65535U;
  c5_in1Hi = c5_absIn1 >> 16;
  c5_in1Lo = c5_absIn1 & 65535U;
  c5_productHiHi = c5_in0Hi * c5_in1Hi;
  c5_productHiLo = c5_in0Hi * c5_in1Lo;
  c5_productLoHi = c5_in0Lo * c5_in1Hi;
  c5_productLoLo = c5_in0Lo * c5_in1Lo;
  c5_carry = (uint32_T)0;
  c5_outBitsLo = c5_productLoLo + (c5_productLoHi << 16);
  if (c5_outBitsLo < c5_productLoLo) {
    c5_carry++;
  }

  c5_productLoLo = c5_outBitsLo;
  c5_outBitsLo = (uint32_T)(c5_outBitsLo + (c5_productHiLo << 16));
  if (c5_outBitsLo < c5_productLoLo) {
    c5_carry++;
  }

  c5_outBitsHi = ((c5_carry + c5_productHiHi) + (c5_productLoHi >> 16)) +
    (c5_productHiLo >> 16);
  if (c5_negativeProduct) {
    c5_outBitsHi = ~c5_outBitsHi;
    c5_outBitsLo = ~c5_outBitsLo;
    c5_outBitsLo++;
    if (c5_outBitsLo == (uint32_T)0) {
      c5_outBitsHi++;
    }
  }

  *c5_ptrOutBitsHi = c5_outBitsHi;
  *c5_ptrOutBitsLo = c5_outBitsLo;
}

static int32_T c5_mul_s32_s32_s32_sat(int32_T c5_a, int32_T c5_b)
{
  uint32_T c5_u32_clo;
  uint32_T c5_u32_chi;
  c5_mul_wide_s32(c5_a, c5_b, &c5_u32_chi, &c5_u32_clo);
  if (((int32_T)c5_u32_chi > 0) || ((c5_u32_chi == (uint32_T)0) && (c5_u32_clo >=
        2147483648U))) {
    return MAX_int32_T;
  } else if (((int32_T)c5_u32_chi < -1) || (((int32_T)c5_u32_chi == -1) &&
              (c5_u32_clo < 2147483648U))) {
    return MIN_int32_T;
  } else {
    return (int32_T)c5_u32_clo;
  }
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c5_MPC_AVC_implementation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1236258000U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(400253010U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4025038007U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3179277433U);
}

mxArray *sf_c5_MPC_AVC_implementation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1370124300U);
    pr[1] = (double)(3069654740U);
    pr[2] = (double)(2402112914U);
    pr[3] = (double)(3594939954U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "aliasId", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "aliasId", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "aliasId", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
           5,
           1,
           1,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"kk",0,
                              c5_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"H",0,c5_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Ps0",0,
                              NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Psn",0,
                              NULL);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Rs",0,
                              NULL);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"theta1",
                              0,NULL);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"theta",0,
                              NULL);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Ps1",0,
                              NULL);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"V",0,NULL);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,334);
        _SFD_CV_INIT_EML_IF(0,0,59,69,198,334);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c5_kk;
          real_T (*c5_H)[6];
          real_T *c5_Ps0;
          real_T *c5_Psn;
          real_T *c5_Rs;
          real_T *c5_theta1;
          real_T *c5_theta;
          real_T *c5_Ps1;
          real_T (*c5_V)[6];
          c5_H = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 1);
          c5_theta = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c5_Rs = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c5_kk = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c5_theta1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c5_Psn = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c5_Ps1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c5_V = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 6);
          c5_Ps0 = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_kk);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_H);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_Ps0);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_Psn);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_Rs);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_theta1);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_theta);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_Ps1);
          _SFD_SET_DATA_VALUE_PTR(8U, c5_V);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration
      (_MPC_AVC_implementationMachineNumber_,chartInstance.chartNumber,
       chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c5_MPC_AVC_implementation(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c5_MPC_AVC_implementation();
  initialize_c5_MPC_AVC_implementation();
}

static void sf_opaque_enable_c5_MPC_AVC_implementation(void *chartInstanceVar)
{
  enable_c5_MPC_AVC_implementation();
}

static void sf_opaque_disable_c5_MPC_AVC_implementation(void *chartInstanceVar)
{
  disable_c5_MPC_AVC_implementation();
}

static void sf_opaque_gateway_c5_MPC_AVC_implementation(void *chartInstanceVar)
{
  sf_c5_MPC_AVC_implementation();
}

static void sf_opaque_terminate_c5_MPC_AVC_implementation(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c5_MPC_AVC_implementation();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_MPC_AVC_implementation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_MPC_AVC_implementation();
  }
}

static void mdlSetWorkWidths_c5_MPC_AVC_implementation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("MPC_AVC_implementation",
      "MPC_AVC_implementation",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("MPC_AVC_implementation",
                "MPC_AVC_implementation",5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("MPC_AVC_implementation",
      "MPC_AVC_implementation",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MPC_AVC_implementation",
        "MPC_AVC_implementation",5,7);
      sf_mark_chart_reusable_outputs(S,"MPC_AVC_implementation",
        "MPC_AVC_implementation",5,2);
    }

    sf_set_rtw_dwork_info(S,"MPC_AVC_implementation","MPC_AVC_implementation",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1240465413U));
  ssSetChecksum1(S,(3930343783U));
  ssSetChecksum2(S,(4135765432U));
  ssSetChecksum3(S,(1162780014U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_MPC_AVC_implementation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "MPC_AVC_implementation",
      "MPC_AVC_implementation",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_MPC_AVC_implementation(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_MPC_AVC_implementation;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c5_MPC_AVC_implementation;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c5_MPC_AVC_implementation;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c5_MPC_AVC_implementation;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c5_MPC_AVC_implementation;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c5_MPC_AVC_implementation;
  chartInstance.chartInfo.mdlStart = mdlStart_c5_MPC_AVC_implementation;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_MPC_AVC_implementation;
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

void c5_MPC_AVC_implementation_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_MPC_AVC_implementation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_MPC_AVC_implementation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_MPC_AVC_implementation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_MPC_AVC_implementation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
