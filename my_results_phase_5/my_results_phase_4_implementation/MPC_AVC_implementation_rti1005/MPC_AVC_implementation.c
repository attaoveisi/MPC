/*
 * MPC_AVC_implementation.c
 *
 * Real-Time Workshop code generation for Simulink model "MPC_AVC_implementation.mdl".
 *
 * Model Version              : 1.389
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Mar 02 12:18:25 2016
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
  int_T nXc = 5;
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

/* Shared Utility Functions */
int32_T knopdjekjecjlnoh_eml_ixamax(int32_T eml_n, real_T eml_x[100], int32_T
  eml_ix0, int32_T eml_incx)
{
  int32_T eml_idxmax;
  int32_T eml_ix;
  real_T eml_smax;
  int32_T eml_k;
  real_T eml_x_0;
  if ((!(eml_n < 1)) && (!(eml_incx < 1))) {
    eml_idxmax = 1;
    if (eml_n > 1) {
      eml_ix = eml_ix0;
      eml_smax = fabs(eml_x[eml_ix0 - 1]);
      for (eml_k = 2; eml_k <= eml_n; eml_k++) {
        eml_ix += eml_incx;
        eml_x_0 = fabs(eml_x[eml_ix - 1]);
        if (eml_x_0 > eml_smax) {
          eml_idxmax = eml_k;
          eml_smax = eml_x_0;
        }
      }
    }
  } else {
    return 0;
  }

  return eml_idxmax;
}

void nglfaaiedbaiecba_mldivide(real_T eml_A[100], real_T eml_B[40], real_T
  eml_Y[40])
{
  int32_T eml_info;
  int32_T eml_ip;
  real_T eml_A_0[100];
  int32_T eml_ipiv[10];
  int32_T eml_j;
  real_T eml_temp;
  int32_T eml_kAcol;
  int32_T eml_i;
  int32_T eml_i_0;
  for (eml_info = 0; eml_info < 10; eml_info++) {
    for (eml_ip = 0; eml_ip < 10; eml_ip++) {
      eml_A_0[eml_ip + 10 * eml_info] = eml_A[eml_ip + 10 * eml_info];
    }
  }

  refp1_dbielngdlfcboppp_eml_xget(eml_A_0, eml_ipiv, &eml_info);
  for (eml_info = 0; eml_info < 4; eml_info++) {
    for (eml_ip = 0; eml_ip < 10; eml_ip++) {
      eml_Y[eml_ip + 10 * eml_info] = eml_B[eml_ip + 10 * eml_info];
    }
  }

  for (eml_info = 0; eml_info < 10; eml_info++) {
    if (eml_ipiv[eml_info] != eml_info + 1) {
      eml_ip = eml_ipiv[eml_info];
      for (eml_j = 0; eml_j < 4; eml_j++) {
        eml_temp = eml_Y[eml_info + 10 * eml_j];
        eml_Y[eml_info + 10 * eml_j] = eml_Y[(eml_ip - 1) + 10 * eml_j];
        eml_Y[(eml_ip - 1) + 10 * eml_j] = eml_temp;
      }
    }
  }

  for (eml_info = 0; eml_info < 4; eml_info++) {
    eml_ip = eml_info * 10;
    for (eml_j = 0; eml_j < 10; eml_j++) {
      eml_kAcol = eml_j * 10;
      if (eml_Y[((eml_j + 1) + eml_ip) - 1] != 0.0) {
        for (eml_i = eml_j + 2; eml_i <= 10; eml_i++) {
          eml_Y[(eml_i + eml_ip) - 1] -= eml_Y[((eml_j + 1) + eml_ip) - 1] *
            eml_A_0[(eml_i + eml_kAcol) - 1];
        }
      }
    }
  }

  for (eml_info = 0; eml_info < 4; eml_info++) {
    eml_ip = eml_info * 10;
    for (eml_j = 10; eml_j > 0; eml_j += -1) {
      eml_kAcol = (eml_j - 1) * 10;
      if (eml_Y[(eml_j + eml_ip) - 1] != 0.0) {
        eml_Y[(eml_j + eml_ip) - 1] /= eml_A_0[(eml_j + eml_kAcol) - 1];
        eml_i = eml_j - 1;
        for (eml_i_0 = 1; eml_i_0 <= eml_i; eml_i_0++) {
          eml_Y[(eml_i_0 + eml_ip) - 1] -= eml_Y[(eml_j + eml_ip) - 1] *
            eml_A_0[(eml_i_0 + eml_kAcol) - 1];
        }
      }
    }
  }
}

void nglnohdbopphdjmg_mldivide(real_T eml_A[100], real_T eml_B[10], real_T
  eml_Y[10])
{
  int32_T eml_info;
  int32_T eml_ip;
  real_T eml_A_0[100];
  int32_T eml_ipiv[10];
  real_T eml_temp;
  int32_T eml_i;
  int32_T eml_i_0;
  for (eml_info = 0; eml_info < 10; eml_info++) {
    for (eml_ip = 0; eml_ip < 10; eml_ip++) {
      eml_A_0[eml_ip + 10 * eml_info] = eml_A[eml_ip + 10 * eml_info];
    }
  }

  refp1_dbielngdlfcboppp_eml_xget(eml_A_0, eml_ipiv, &eml_info);
  for (eml_info = 0; eml_info < 10; eml_info++) {
    eml_Y[eml_info] = eml_B[eml_info];
  }

  for (eml_info = 0; eml_info < 10; eml_info++) {
    if (eml_ipiv[eml_info] != eml_info + 1) {
      eml_ip = eml_ipiv[eml_info];
      eml_temp = eml_Y[eml_info];
      eml_Y[eml_info] = eml_Y[eml_ip - 1];
      eml_Y[eml_ip - 1] = eml_temp;
    }
  }

  for (eml_info = 0; eml_info < 10; eml_info++) {
    eml_ip = eml_info * 10;
    if (eml_Y[eml_info] != 0.0) {
      for (eml_i = eml_info + 2; eml_i <= 10; eml_i++) {
        eml_Y[eml_i - 1] -= eml_Y[eml_info] * eml_A_0[(eml_i + eml_ip) - 1];
      }
    }
  }

  for (eml_info = 10; eml_info > 0; eml_info += -1) {
    eml_ip = (eml_info - 1) * 10;
    if (eml_Y[eml_info - 1] != 0.0) {
      eml_Y[eml_info - 1] /= eml_A_0[(eml_info + eml_ip) - 1];
      eml_i = eml_info - 1;
      for (eml_i_0 = 1; eml_i_0 <= eml_i; eml_i_0++) {
        eml_Y[eml_i_0 - 1] -= eml_Y[eml_info - 1] * eml_A_0[(eml_i_0 + eml_ip) -
          1];
      }
    }
  }
}

void refp1_ecbiphdbcbaijmoh_eml_xswa(real_T eml_x[100], int32_T eml_ix0, int32_T
  eml_iy0)
{
  int32_T eml_ix;
  int32_T eml_iy;
  int32_T eml_k;
  real_T eml_temp;
  eml_ix = eml_ix0;
  eml_iy = eml_iy0;
  for (eml_k = 0; eml_k < 10; eml_k++) {
    eml_temp = eml_x[eml_ix - 1];
    eml_x[eml_ix - 1] = eml_x[eml_iy - 1];
    eml_x[eml_iy - 1] = eml_temp;
    eml_iy += 10;
    eml_ix += 10;
  }
}

void refp5_mglfecbinohdlfkf_eml_xger(int32_T eml_m, int32_T eml_n, int32_T
  eml_ix0, int32_T eml_iy0, real_T eml_A[100], int32_T eml_ia0)
{
  int32_T eml_jA;
  int32_T eml_jy;
  int32_T eml_j;
  real_T eml_yjy;
  int32_T eml_ix;
  int32_T eml_loop_ub;
  int32_T eml_ijA;
  eml_jA = eml_ia0 - 1;
  eml_jy = eml_iy0;
  for (eml_j = 1; eml_j <= eml_n; eml_j++) {
    eml_yjy = eml_A[eml_jy - 1];
    if (eml_yjy != 0.0) {
      eml_yjy *= -1.0;
      eml_ix = eml_ix0;
      eml_loop_ub = eml_m + eml_jA;
      for (eml_ijA = 1 + eml_jA; eml_ijA <= eml_loop_ub; eml_ijA++) {
        eml_A[eml_ijA - 1] += eml_A[eml_ix - 1] * eml_yjy;
        eml_ix++;
      }
    }

    eml_jy += 10;
    eml_jA += 10;
  }
}

void refp1_dbielngdlfcboppp_eml_xget(real_T eml_A[100], int32_T eml_ipiv[10],
  int32_T *eml_info)
{
  int32_T eml_j;
  int32_T eml_mmj;
  int32_T eml_jj;
  int32_T eml_jp1j;
  int32_T eml_jpiv_offset;
  int32_T eml_jrow;
  for (eml_j = 0; eml_j < 10; eml_j++) {
    eml_ipiv[eml_j] = 1 + eml_j;
  }

  *eml_info = 0;
  for (eml_j = 0; eml_j < 9; eml_j++) {
    eml_mmj = 9 - eml_j;
    eml_jj = 1 + eml_j * 11;
    eml_jp1j = eml_jj + 1;
    eml_jpiv_offset = knopdjekjecjlnoh_eml_ixamax(eml_mmj + 1, eml_A, eml_jj, 1)
      - 1;
    if (eml_A[(eml_jj + eml_jpiv_offset) - 1] != 0.0) {
      if (eml_jpiv_offset != 0) {
        eml_ipiv[eml_j] = (eml_j + 1) + eml_jpiv_offset;
        eml_jrow = 1 + eml_j;
        refp1_ecbiphdbcbaijmoh_eml_xswa(eml_A, eml_jrow, eml_jrow +
          eml_jpiv_offset);
      }

      eml_jpiv_offset = eml_jp1j + (eml_mmj - 1);
      for (eml_jrow = eml_jp1j; eml_jrow <= eml_jpiv_offset; eml_jrow++) {
        eml_A[eml_jrow - 1] /= eml_A[eml_jj - 1];
      }
    } else {
      *eml_info = eml_j + 1;
    }

    refp5_mglfecbinohdlfkf_eml_xger(eml_mmj, 9 - eml_j, eml_jp1j, eml_jj + 10,
      eml_A, eml_jj + 11);
  }

  if ((*eml_info == 0) && (!(eml_A[99] != 0.0))) {
    *eml_info = 10;
  }
}

/* Shared Utility Functions */
void jeknbaaaecbalfkf_mrdivide(real_T eml_A[6], real_T eml_B[36], real_T eml_y[6])
{
  int32_T eml_j;
  int32_T eml_mmj;
  real_T eml_A_0[36];
  int8_T eml_ipiv[6];
  int32_T eml_jj;
  int32_T eml_jp1j;
  int32_T eml_n;
  int32_T eml_a;
  int32_T eml_ix;
  real_T eml_smax;
  int32_T eml_k;
  real_T eml_x;
  int32_T eml_n_0;
  int32_T eml_jA;
  real_T eml_Y[6];
  for (eml_j = 0; eml_j < 6; eml_j++) {
    for (eml_mmj = 0; eml_mmj < 6; eml_mmj++) {
      eml_A_0[eml_mmj + 6 * eml_j] = eml_B[eml_j + 6 * eml_mmj];
    }

    eml_ipiv[eml_j] = (int8_T)(1 + eml_j);
  }

  for (eml_j = 0; eml_j < 5; eml_j++) {
    eml_mmj = 5 - eml_j;
    eml_jj = 1 + eml_j * 7;
    eml_jp1j = eml_jj + 1;
    eml_n = eml_mmj + 1;
    eml_a = 1;
    eml_ix = eml_jj;
    eml_smax = fabs(eml_A_0[eml_jj - 1]);
    for (eml_k = 2; eml_k <= eml_n; eml_k++) {
      eml_ix++;
      eml_x = fabs(eml_A_0[eml_ix - 1]);
      if (eml_x > eml_smax) {
        eml_a = eml_k;
        eml_smax = eml_x;
      }
    }

    eml_n = eml_a - 1;
    if (eml_A_0[(eml_jj + eml_n) - 1] != 0.0) {
      if (eml_n != 0) {
        eml_ipiv[eml_j] = (int8_T)((eml_j + 1) + eml_n);
        eml_a = 1 + eml_j;
        eml_k = eml_a + eml_n;
        for (eml_n = 0; eml_n < 6; eml_n++) {
          eml_x = eml_A_0[eml_a - 1];
          eml_A_0[eml_a - 1] = eml_A_0[eml_k - 1];
          eml_A_0[eml_k - 1] = eml_x;
          eml_k += 6;
          eml_a += 6;
        }
      }

      eml_a = eml_jp1j + (eml_mmj - 1);
      for (eml_ix = eml_jp1j; eml_ix <= eml_a; eml_ix++) {
        eml_A_0[eml_ix - 1] /= eml_A_0[eml_jj - 1];
      }
    }

    eml_n_0 = 5 - eml_j;
    eml_jA = eml_jj + 6;
    eml_n = eml_jj + 6;
    for (eml_a = 1; eml_a <= eml_n_0; eml_a++) {
      eml_x = eml_A_0[eml_n - 1];
      if (eml_x != 0.0) {
        eml_x *= -1.0;
        eml_ix = eml_jp1j;
        eml_k = eml_mmj + eml_jA;
        for (eml_jj = 1 + eml_jA; eml_jj <= eml_k; eml_jj++) {
          eml_A_0[eml_jj - 1] += eml_A_0[eml_ix - 1] * eml_x;
          eml_ix++;
        }
      }

      eml_n += 6;
      eml_jA += 6;
    }
  }

  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_Y[eml_j] = eml_A[eml_j];
  }

  for (eml_n = 0; eml_n < 6; eml_n++) {
    if (eml_ipiv[eml_n] != eml_n + 1) {
      eml_a = (int32_T)eml_ipiv[eml_n];
      eml_x = eml_Y[eml_n];
      eml_Y[eml_n] = eml_Y[eml_a - 1];
      eml_Y[eml_a - 1] = eml_x;
    }
  }

  for (eml_n = 0; eml_n < 6; eml_n++) {
    eml_a = eml_n * 6;
    if (eml_Y[eml_n] != 0.0) {
      for (eml_ix = eml_n + 2; eml_ix <= 6; eml_ix++) {
        eml_Y[eml_ix - 1] -= eml_Y[eml_n] * eml_A_0[(eml_ix + eml_a) - 1];
      }
    }
  }

  for (eml_n = 6; eml_n > 0; eml_n += -1) {
    eml_a = (eml_n - 1) * 6;
    if (eml_Y[eml_n - 1] != 0.0) {
      eml_Y[eml_n - 1] /= eml_A_0[(eml_n + eml_a) - 1];
      eml_ix = eml_n - 1;
      for (eml_k = 1; eml_k <= eml_ix; eml_k++) {
        eml_Y[eml_k - 1] -= eml_Y[eml_n - 1] * eml_A_0[(eml_k + eml_a) - 1];
      }
    }
  }

  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_y[eml_j] = eml_Y[eml_j];
  }
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
    int32_T i;
    real_T unnamed_idx;
    real_T unnamed_idx_0;

    /* StateSpace Block: '<Root>/Analog Filter Design1' */
    {
      MPC_AVC_implementation_B.AnalogFilterDesign1 =
        MPC_AVC_implementation_P.AnalogFilterDesign1_C*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[3];
    }

    /* Outputs for atomic SubSystem: '<S2>/Kalman Filter' incorporates:
     *  UnitDelay: '<S7>/Unit Delay3'
     */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      for (i = 0; i < 18; i++) {
        /* UnitDelay: '<S7>/Unit Delay3' */
        MPC_AVC_implementation_B.UnitDelay3_f[i] =
          MPC_AVC_implementation_DWork.UnitDelay3_DSTATE_j[i];
      }

      /* Gain Block: '<S7>/A'
       * About '<S7>/A :'
       *   Gain value: A


       */
      {
        static const int_T dims[3] = { 18, 18, 1 };

        rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.A, (real_T *)
                         &MPC_AVC_implementation_P.A_Gain[0],
                         (real_T *)MPC_AVC_implementation_B.UnitDelay3_f, &dims
                         [0]);
      }

      /* Gain Block: '<S7>/C'
       * About '<S7>/C :'
       *   Gain value: C


       */
      {
        static const int_T dims[3] = { 1, 18, 1 };

        rt_MatMultRR_Dbl((real_T *)&MPC_AVC_implementation_B.C, (real_T *)
                         &MPC_AVC_implementation_P.C_Gain[0],
                         (real_T *)MPC_AVC_implementation_B.UnitDelay3_f, &dims
                         [0]);
      }
    }

    /* Integrator: '<S7>/Integrator' */
    MPC_AVC_implementation_B.Integrator =
      MPC_AVC_implementation_X.Integrator_CSTATE;

    /* Gain: '<S7>/Gain' */
    MPC_AVC_implementation_B.Gain_l = MPC_AVC_implementation_P.Gain_Gain_h *
      MPC_AVC_implementation_B.Integrator;

    /* Embedded MATLAB Block: '<S7>/MATLAB Function1'
     */
    /* Embedded MATLAB Function 'Controller/Kalman Filter/MATLAB Function1': '<S10>:1' */
    /* '<S10>:1:4' */
    MPC_AVC_implementation_B.kk1 = floor(MPC_AVC_implementation_B.Gain_l) + 1.0;

    /* Embedded MATLAB Block: '<S7>/MATLAB Function2'
     */
    {
      int32_T eml_i0;
      int32_T eml_i1;

      /* Embedded MATLAB Function 'Controller/Kalman Filter/MATLAB Function2': '<S11>:1' */
      /* '<S11>:1:4' */
      /* '<S11>:1:6' */
      eml_i0 = (int32_T)(floor(MPC_AVC_implementation_B.Gain_l) + 1.0) - 1;
      for (eml_i1 = 0; eml_i1 < 18; eml_i1++) {
        MPC_AVC_implementation_B.y_j[eml_i1] =
          MPC_AVC_implementation_P.Lf1_Value[eml_i1 + 18 * eml_i0];
      }
    }

    /* Inport: '<S7>/y' */
    MPC_AVC_implementation_B.y = MPC_AVC_implementation_B.AnalogFilterDesign1;

    /* Sum: '<S7>/Sum1' */
    MPC_AVC_implementation_B.Sum1 = MPC_AVC_implementation_B.y -
      MPC_AVC_implementation_B.C;

    {
      static const int_T dims[3] = { 18, 1, 1 };

      rt_MatMultRR_Dbl(MPC_AVC_implementation_B.Product_l,
                       MPC_AVC_implementation_B.y_j,
                       &MPC_AVC_implementation_B.Sum1, &dims[0]);
    }

    /* end of Outputs for SubSystem: '<S2>/Kalman Filter' */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      {
        static const int_T dims[3] = { 10, 18, 1 };

        rt_MatMultRR_Dbl(MPC_AVC_implementation_B.Product, (real_T*)
                         &MPC_AVC_implementation_P.psi_Value[0],
                         MPC_AVC_implementation_B.UnitDelay3_f, &dims[0]);
      }

      for (i = 0; i < 10; i++) {
        /* Sum: '<S6>/Add2' incorporates:
         *  Constant: '<S6>/zeros(1,10)'
         */
        MPC_AVC_implementation_B.Add2[i] = MPC_AVC_implementation_B.Product[i] -
          MPC_AVC_implementation_P.zeros110_Value[i];
      }

      /* UnitDelay: '<S2>/Unit Delay16' */
      MPC_AVC_implementation_B.UnitDelay16[0] =
        MPC_AVC_implementation_DWork.UnitDelay16_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay16[1] =
        MPC_AVC_implementation_DWork.UnitDelay16_DSTATE[1];

      /* Gain: '<S2>/Gain13' */
      MPC_AVC_implementation_B.Gain13[0] = MPC_AVC_implementation_P.Gain13_Gain *
        MPC_AVC_implementation_B.UnitDelay16[0];
      MPC_AVC_implementation_B.Gain13[1] = MPC_AVC_implementation_P.Gain13_Gain *
        MPC_AVC_implementation_B.UnitDelay16[1];

      /* Gain: '<S2>/Gain16' */
      MPC_AVC_implementation_B.Gain16[0] = MPC_AVC_implementation_P.Gain16_Gain *
        MPC_AVC_implementation_B.UnitDelay16[0];
      MPC_AVC_implementation_B.Gain16[1] = MPC_AVC_implementation_P.Gain16_Gain *
        MPC_AVC_implementation_B.UnitDelay16[1];
      MPC_AVC_implementation_B.Gain16[2] = MPC_AVC_implementation_P.Gain16_Gain *
        MPC_AVC_implementation_B.Gain13[0];
      MPC_AVC_implementation_B.Gain16[3] = MPC_AVC_implementation_P.Gain16_Gain *
        MPC_AVC_implementation_B.Gain13[1];

      /* UnitDelay: '<S2>/Unit Delay13' */
      MPC_AVC_implementation_B.UnitDelay13[0] =
        MPC_AVC_implementation_DWork.UnitDelay13_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay13[1] =
        MPC_AVC_implementation_DWork.UnitDelay13_DSTATE[1];

      /* Gain: '<S2>/Gain11' */
      MPC_AVC_implementation_B.Gain11[0] = MPC_AVC_implementation_P.Gain11_Gain *
        MPC_AVC_implementation_B.UnitDelay13[0];
      MPC_AVC_implementation_B.Gain11[1] = MPC_AVC_implementation_P.Gain11_Gain *
        MPC_AVC_implementation_B.UnitDelay13[1];

      /* Gain: '<S2>/Gain15' */
      MPC_AVC_implementation_B.Gain15[0] = MPC_AVC_implementation_P.Gain15_Gain *
        MPC_AVC_implementation_B.UnitDelay13[0];
      MPC_AVC_implementation_B.Gain15[1] = MPC_AVC_implementation_P.Gain15_Gain *
        MPC_AVC_implementation_B.UnitDelay13[1];
      MPC_AVC_implementation_B.Gain15[2] = MPC_AVC_implementation_P.Gain15_Gain *
        MPC_AVC_implementation_B.Gain11[0];
      MPC_AVC_implementation_B.Gain15[3] = MPC_AVC_implementation_P.Gain15_Gain *
        MPC_AVC_implementation_B.Gain11[1];

      /* UnitDelay: '<S2>/Unit Delay14' */
      MPC_AVC_implementation_B.UnitDelay14[0] =
        MPC_AVC_implementation_DWork.UnitDelay14_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay14[1] =
        MPC_AVC_implementation_DWork.UnitDelay14_DSTATE[1];

      /* Gain: '<S2>/Gain12' */
      MPC_AVC_implementation_B.Gain12[0] = MPC_AVC_implementation_P.Gain12_Gain *
        MPC_AVC_implementation_B.UnitDelay14[0];
      MPC_AVC_implementation_B.Gain12[1] = MPC_AVC_implementation_P.Gain12_Gain *
        MPC_AVC_implementation_B.UnitDelay14[1];

      /* Gain: '<S2>/Gain18' */
      MPC_AVC_implementation_B.Gain18[0] = MPC_AVC_implementation_P.Gain18_Gain *
        MPC_AVC_implementation_B.UnitDelay14[0];
      MPC_AVC_implementation_B.Gain18[1] = MPC_AVC_implementation_P.Gain18_Gain *
        MPC_AVC_implementation_B.UnitDelay14[1];
      MPC_AVC_implementation_B.Gain18[2] = MPC_AVC_implementation_P.Gain18_Gain *
        MPC_AVC_implementation_B.Gain12[0];
      MPC_AVC_implementation_B.Gain18[3] = MPC_AVC_implementation_P.Gain18_Gain *
        MPC_AVC_implementation_B.Gain12[1];

      /* UnitDelay: '<S2>/Unit Delay15' */
      MPC_AVC_implementation_B.UnitDelay15[0] =
        MPC_AVC_implementation_DWork.UnitDelay15_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay15[1] =
        MPC_AVC_implementation_DWork.UnitDelay15_DSTATE[1];

      /* Gain: '<S2>/Gain14' */
      MPC_AVC_implementation_B.Gain14[0] = MPC_AVC_implementation_P.Gain14_Gain *
        MPC_AVC_implementation_B.UnitDelay15[0];
      MPC_AVC_implementation_B.Gain14[1] = MPC_AVC_implementation_P.Gain14_Gain *
        MPC_AVC_implementation_B.UnitDelay15[1];

      /* Gain: '<S2>/Gain17' */
      MPC_AVC_implementation_B.Gain17[0] = MPC_AVC_implementation_P.Gain17_Gain *
        MPC_AVC_implementation_B.UnitDelay15[0];
      MPC_AVC_implementation_B.Gain17[1] = MPC_AVC_implementation_P.Gain17_Gain *
        MPC_AVC_implementation_B.UnitDelay15[1];
      MPC_AVC_implementation_B.Gain17[2] = MPC_AVC_implementation_P.Gain17_Gain *
        MPC_AVC_implementation_B.Gain14[0];
      MPC_AVC_implementation_B.Gain17[3] = MPC_AVC_implementation_P.Gain17_Gain *
        MPC_AVC_implementation_B.Gain14[1];

      /* UnitDelay: '<S2>/Unit Delay12' */
      MPC_AVC_implementation_B.UnitDelay12[0] =
        MPC_AVC_implementation_DWork.UnitDelay12_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay12[1] =
        MPC_AVC_implementation_DWork.UnitDelay12_DSTATE[1];

      /* Gain: '<S2>/Gain25' */
      MPC_AVC_implementation_B.Gain25[0] = MPC_AVC_implementation_P.Gain25_Gain *
        MPC_AVC_implementation_B.UnitDelay12[0];
      MPC_AVC_implementation_B.Gain25[1] = MPC_AVC_implementation_P.Gain25_Gain *
        MPC_AVC_implementation_B.UnitDelay12[1];

      /* Gain: '<S2>/Gain28' */
      MPC_AVC_implementation_B.Gain28[0] = MPC_AVC_implementation_P.Gain28_Gain *
        MPC_AVC_implementation_B.UnitDelay12[0];
      MPC_AVC_implementation_B.Gain28[1] = MPC_AVC_implementation_P.Gain28_Gain *
        MPC_AVC_implementation_B.UnitDelay12[1];
      MPC_AVC_implementation_B.Gain28[2] = MPC_AVC_implementation_P.Gain28_Gain *
        MPC_AVC_implementation_B.Gain25[0];
      MPC_AVC_implementation_B.Gain28[3] = MPC_AVC_implementation_P.Gain28_Gain *
        MPC_AVC_implementation_B.Gain25[1];

      /* UnitDelay: '<S2>/Unit Delay9' */
      MPC_AVC_implementation_B.UnitDelay9[0] =
        MPC_AVC_implementation_DWork.UnitDelay9_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay9[1] =
        MPC_AVC_implementation_DWork.UnitDelay9_DSTATE[1];

      /* Gain: '<S2>/Gain23' */
      MPC_AVC_implementation_B.Gain23[0] = MPC_AVC_implementation_P.Gain23_Gain *
        MPC_AVC_implementation_B.UnitDelay9[0];
      MPC_AVC_implementation_B.Gain23[1] = MPC_AVC_implementation_P.Gain23_Gain *
        MPC_AVC_implementation_B.UnitDelay9[1];

      /* Gain: '<S2>/Gain27' */
      MPC_AVC_implementation_B.Gain27[0] = MPC_AVC_implementation_P.Gain27_Gain *
        MPC_AVC_implementation_B.UnitDelay9[0];
      MPC_AVC_implementation_B.Gain27[1] = MPC_AVC_implementation_P.Gain27_Gain *
        MPC_AVC_implementation_B.UnitDelay9[1];
      MPC_AVC_implementation_B.Gain27[2] = MPC_AVC_implementation_P.Gain27_Gain *
        MPC_AVC_implementation_B.Gain23[0];
      MPC_AVC_implementation_B.Gain27[3] = MPC_AVC_implementation_P.Gain27_Gain *
        MPC_AVC_implementation_B.Gain23[1];

      /* UnitDelay: '<S2>/Unit Delay10' */
      MPC_AVC_implementation_B.UnitDelay10[0] =
        MPC_AVC_implementation_DWork.UnitDelay10_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay10[1] =
        MPC_AVC_implementation_DWork.UnitDelay10_DSTATE[1];

      /* Gain: '<S2>/Gain24' */
      MPC_AVC_implementation_B.Gain24[0] = MPC_AVC_implementation_P.Gain24_Gain *
        MPC_AVC_implementation_B.UnitDelay10[0];
      MPC_AVC_implementation_B.Gain24[1] = MPC_AVC_implementation_P.Gain24_Gain *
        MPC_AVC_implementation_B.UnitDelay10[1];

      /* Gain: '<S2>/Gain30' */
      MPC_AVC_implementation_B.Gain30[0] = MPC_AVC_implementation_P.Gain30_Gain *
        MPC_AVC_implementation_B.UnitDelay10[0];
      MPC_AVC_implementation_B.Gain30[1] = MPC_AVC_implementation_P.Gain30_Gain *
        MPC_AVC_implementation_B.UnitDelay10[1];
      MPC_AVC_implementation_B.Gain30[2] = MPC_AVC_implementation_P.Gain30_Gain *
        MPC_AVC_implementation_B.Gain24[0];
      MPC_AVC_implementation_B.Gain30[3] = MPC_AVC_implementation_P.Gain30_Gain *
        MPC_AVC_implementation_B.Gain24[1];

      /* UnitDelay: '<S2>/Unit Delay11' */
      MPC_AVC_implementation_B.UnitDelay11[0] =
        MPC_AVC_implementation_DWork.UnitDelay11_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay11[1] =
        MPC_AVC_implementation_DWork.UnitDelay11_DSTATE[1];

      /* Gain: '<S2>/Gain26' */
      MPC_AVC_implementation_B.Gain26[0] = MPC_AVC_implementation_P.Gain26_Gain *
        MPC_AVC_implementation_B.UnitDelay11[0];
      MPC_AVC_implementation_B.Gain26[1] = MPC_AVC_implementation_P.Gain26_Gain *
        MPC_AVC_implementation_B.UnitDelay11[1];

      /* Gain: '<S2>/Gain29' */
      MPC_AVC_implementation_B.Gain29[0] = MPC_AVC_implementation_P.Gain29_Gain *
        MPC_AVC_implementation_B.UnitDelay11[0];
      MPC_AVC_implementation_B.Gain29[1] = MPC_AVC_implementation_P.Gain29_Gain *
        MPC_AVC_implementation_B.UnitDelay11[1];
      MPC_AVC_implementation_B.Gain29[2] = MPC_AVC_implementation_P.Gain29_Gain *
        MPC_AVC_implementation_B.Gain26[0];
      MPC_AVC_implementation_B.Gain29[3] = MPC_AVC_implementation_P.Gain29_Gain *
        MPC_AVC_implementation_B.Gain26[1];

      /* UnitDelay: '<S2>/Unit Delay7' */
      MPC_AVC_implementation_B.UnitDelay7[0] =
        MPC_AVC_implementation_DWork.UnitDelay7_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay7[1] =
        MPC_AVC_implementation_DWork.UnitDelay7_DSTATE[1];

      /* Gain: '<S2>/Gain33' */
      MPC_AVC_implementation_B.Gain33[0] = MPC_AVC_implementation_P.Gain33_Gain *
        MPC_AVC_implementation_B.UnitDelay7[0];
      MPC_AVC_implementation_B.Gain33[1] = MPC_AVC_implementation_P.Gain33_Gain *
        MPC_AVC_implementation_B.UnitDelay7[1];

      /* Gain: '<S2>/Gain36' */
      MPC_AVC_implementation_B.Gain36[0] = MPC_AVC_implementation_P.Gain36_Gain *
        MPC_AVC_implementation_B.UnitDelay7[0];
      MPC_AVC_implementation_B.Gain36[1] = MPC_AVC_implementation_P.Gain36_Gain *
        MPC_AVC_implementation_B.UnitDelay7[1];
      MPC_AVC_implementation_B.Gain36[2] = MPC_AVC_implementation_P.Gain36_Gain *
        MPC_AVC_implementation_B.Gain33[0];
      MPC_AVC_implementation_B.Gain36[3] = MPC_AVC_implementation_P.Gain36_Gain *
        MPC_AVC_implementation_B.Gain33[1];

      /* UnitDelay: '<S2>/Unit Delay1' */
      MPC_AVC_implementation_B.UnitDelay1[0] =
        MPC_AVC_implementation_DWork.UnitDelay1_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay1[1] =
        MPC_AVC_implementation_DWork.UnitDelay1_DSTATE[1];

      /* Gain: '<S2>/Gain31' */
      MPC_AVC_implementation_B.Gain31[0] = MPC_AVC_implementation_P.Gain31_Gain *
        MPC_AVC_implementation_B.UnitDelay1[0];
      MPC_AVC_implementation_B.Gain31[1] = MPC_AVC_implementation_P.Gain31_Gain *
        MPC_AVC_implementation_B.UnitDelay1[1];

      /* Gain: '<S2>/Gain35' */
      MPC_AVC_implementation_B.Gain35[0] = MPC_AVC_implementation_P.Gain35_Gain *
        MPC_AVC_implementation_B.UnitDelay1[0];
      MPC_AVC_implementation_B.Gain35[1] = MPC_AVC_implementation_P.Gain35_Gain *
        MPC_AVC_implementation_B.UnitDelay1[1];
      MPC_AVC_implementation_B.Gain35[2] = MPC_AVC_implementation_P.Gain35_Gain *
        MPC_AVC_implementation_B.Gain31[0];
      MPC_AVC_implementation_B.Gain35[3] = MPC_AVC_implementation_P.Gain35_Gain *
        MPC_AVC_implementation_B.Gain31[1];

      /* UnitDelay: '<S2>/Unit Delay2' */
      MPC_AVC_implementation_B.UnitDelay2[0] =
        MPC_AVC_implementation_DWork.UnitDelay2_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay2[1] =
        MPC_AVC_implementation_DWork.UnitDelay2_DSTATE[1];

      /* Gain: '<S2>/Gain32' */
      MPC_AVC_implementation_B.Gain32[0] = MPC_AVC_implementation_P.Gain32_Gain *
        MPC_AVC_implementation_B.UnitDelay2[0];
      MPC_AVC_implementation_B.Gain32[1] = MPC_AVC_implementation_P.Gain32_Gain *
        MPC_AVC_implementation_B.UnitDelay2[1];

      /* Gain: '<S2>/Gain38' */
      MPC_AVC_implementation_B.Gain38[0] = MPC_AVC_implementation_P.Gain38_Gain *
        MPC_AVC_implementation_B.UnitDelay2[0];
      MPC_AVC_implementation_B.Gain38[1] = MPC_AVC_implementation_P.Gain38_Gain *
        MPC_AVC_implementation_B.UnitDelay2[1];
      MPC_AVC_implementation_B.Gain38[2] = MPC_AVC_implementation_P.Gain38_Gain *
        MPC_AVC_implementation_B.Gain32[0];
      MPC_AVC_implementation_B.Gain38[3] = MPC_AVC_implementation_P.Gain38_Gain *
        MPC_AVC_implementation_B.Gain32[1];

      /* UnitDelay: '<S2>/Unit Delay6' */
      MPC_AVC_implementation_B.UnitDelay6[0] =
        MPC_AVC_implementation_DWork.UnitDelay6_DSTATE[0];
      MPC_AVC_implementation_B.UnitDelay6[1] =
        MPC_AVC_implementation_DWork.UnitDelay6_DSTATE[1];

      /* Gain: '<S2>/Gain34' */
      MPC_AVC_implementation_B.Gain34[0] = MPC_AVC_implementation_P.Gain34_Gain *
        MPC_AVC_implementation_B.UnitDelay6[0];
      MPC_AVC_implementation_B.Gain34[1] = MPC_AVC_implementation_P.Gain34_Gain *
        MPC_AVC_implementation_B.UnitDelay6[1];

      /* Gain: '<S2>/Gain37' */
      MPC_AVC_implementation_B.Gain37[0] = MPC_AVC_implementation_P.Gain37_Gain *
        MPC_AVC_implementation_B.UnitDelay6[0];
      MPC_AVC_implementation_B.Gain37[1] = MPC_AVC_implementation_P.Gain37_Gain *
        MPC_AVC_implementation_B.UnitDelay6[1];
      MPC_AVC_implementation_B.Gain37[2] = MPC_AVC_implementation_P.Gain37_Gain *
        MPC_AVC_implementation_B.Gain34[0];
      MPC_AVC_implementation_B.Gain37[3] = MPC_AVC_implementation_P.Gain37_Gain *
        MPC_AVC_implementation_B.Gain34[1];

      /* Sum: '<S2>/Add1' incorporates:
       *  Constant: '<S2>/B_cons1'
       */
      MPC_AVC_implementation_B.Add1[0] =
        (((((((((((MPC_AVC_implementation_B.Gain16[0] +
                   MPC_AVC_implementation_B.Gain15[0]) +
                  MPC_AVC_implementation_B.Gain18[0]) +
                 MPC_AVC_implementation_B.Gain17[0]) +
                MPC_AVC_implementation_B.Gain28[0]) +
               MPC_AVC_implementation_B.Gain27[0]) +
              MPC_AVC_implementation_B.Gain30[0]) +
             MPC_AVC_implementation_B.Gain29[0]) +
            MPC_AVC_implementation_B.Gain36[0]) +
           MPC_AVC_implementation_B.Gain35[0]) +
          MPC_AVC_implementation_B.Gain38[0]) + MPC_AVC_implementation_B.Gain37
         [0]) + MPC_AVC_implementation_P.B_cons1_Value[0];
      MPC_AVC_implementation_B.Add1[1] =
        (((((((((((MPC_AVC_implementation_B.Gain16[1] +
                   MPC_AVC_implementation_B.Gain15[1]) +
                  MPC_AVC_implementation_B.Gain18[1]) +
                 MPC_AVC_implementation_B.Gain17[1]) +
                MPC_AVC_implementation_B.Gain28[1]) +
               MPC_AVC_implementation_B.Gain27[1]) +
              MPC_AVC_implementation_B.Gain30[1]) +
             MPC_AVC_implementation_B.Gain29[1]) +
            MPC_AVC_implementation_B.Gain36[1]) +
           MPC_AVC_implementation_B.Gain35[1]) +
          MPC_AVC_implementation_B.Gain38[1]) + MPC_AVC_implementation_B.Gain37
         [1]) + MPC_AVC_implementation_P.B_cons1_Value[1];
      MPC_AVC_implementation_B.Add1[2] =
        (((((((((((MPC_AVC_implementation_B.Gain16[2] +
                   MPC_AVC_implementation_B.Gain15[2]) +
                  MPC_AVC_implementation_B.Gain18[2]) +
                 MPC_AVC_implementation_B.Gain17[2]) +
                MPC_AVC_implementation_B.Gain28[2]) +
               MPC_AVC_implementation_B.Gain27[2]) +
              MPC_AVC_implementation_B.Gain30[2]) +
             MPC_AVC_implementation_B.Gain29[2]) +
            MPC_AVC_implementation_B.Gain36[2]) +
           MPC_AVC_implementation_B.Gain35[2]) +
          MPC_AVC_implementation_B.Gain38[2]) + MPC_AVC_implementation_B.Gain37
         [2]) + MPC_AVC_implementation_P.B_cons1_Value[2];
      MPC_AVC_implementation_B.Add1[3] =
        (((((((((((MPC_AVC_implementation_B.Gain16[3] +
                   MPC_AVC_implementation_B.Gain15[3]) +
                  MPC_AVC_implementation_B.Gain18[3]) +
                 MPC_AVC_implementation_B.Gain17[3]) +
                MPC_AVC_implementation_B.Gain28[3]) +
               MPC_AVC_implementation_B.Gain27[3]) +
              MPC_AVC_implementation_B.Gain30[3]) +
             MPC_AVC_implementation_B.Gain29[3]) +
            MPC_AVC_implementation_B.Gain36[3]) +
           MPC_AVC_implementation_B.Gain35[3]) +
          MPC_AVC_implementation_B.Gain38[3]) + MPC_AVC_implementation_B.Gain37
         [3]) + MPC_AVC_implementation_P.B_cons1_Value[3];

      /* Embedded MATLAB Block: '<S2>/MATLAB Function'
       */
      {
        int32_T eml_j;
        int32_T eml_mmj;
        real_T eml_y[100];
        real_T eml_x[100];
        int32_T eml_ipiv[10];
        int32_T eml_jj;
        int32_T eml_jp1j;
        int32_T eml_jpiv_offset;
        int32_T eml_jrow;
        int32_T eml_loop_ub;
        int32_T eml_i;
        int8_T eml_p[10];
        real_T eml_kk;
        real_T eml_a[10];
        real_T eml_y_0;
        real_T eml_dv0[40];
        real_T eml_hoistedExpr[40];
        real_T eml_P[16];
        real_T eml_hoistedExpr_0[10];
        real_T eml_d[4];
        real_T eml_lambda[4];
        int32_T eml_exitg1;
        real_T eml_lambda_p[4];
        real_T eml_a_0[4];

        /* Embedded MATLAB Function 'Controller/MATLAB Function': '<S8>:1' */
        /*  eta=-omega\f; */
        /* '<S8>:1:5' */
        for (eml_j = 0; eml_j < 10; eml_j++) {
          for (eml_mmj = 0; eml_mmj < 10; eml_mmj++) {
            eml_y[eml_mmj + 10 * eml_j] = 0.0;
            eml_x[eml_mmj + 10 * eml_j] =
              MPC_AVC_implementation_P.omega_Value[eml_mmj + 10 * eml_j];
          }

          eml_ipiv[eml_j] = 1 + eml_j;
        }

        for (eml_j = 0; eml_j < 9; eml_j++) {
          eml_mmj = 9 - eml_j;
          eml_jj = 1 + eml_j * 11;
          eml_jp1j = eml_jj + 1;
          eml_jpiv_offset = knopdjekjecjlnoh_eml_ixamax(eml_mmj + 1, eml_x,
            eml_jj, 1) - 1;
          if (eml_x[(eml_jj + eml_jpiv_offset) - 1] != 0.0) {
            if (eml_jpiv_offset != 0) {
              eml_ipiv[eml_j] = (eml_j + 1) + eml_jpiv_offset;
              eml_jrow = 1 + eml_j;
              refp1_ecbiphdbcbaijmoh_eml_xswa(eml_x, eml_jrow, eml_jrow +
                eml_jpiv_offset);
            }

            eml_loop_ub = eml_jp1j + (eml_mmj - 1);
            for (eml_i = eml_jp1j; eml_i <= eml_loop_ub; eml_i++) {
              eml_x[eml_i - 1] /= eml_x[eml_jj - 1];
            }
          }

          refp5_mglfecbinohdlfkf_eml_xger(eml_mmj, 9 - eml_j, eml_jp1j, eml_jj +
            10, eml_x, eml_jj + 11);
        }

        for (eml_j = 0; eml_j < 10; eml_j++) {
          eml_p[eml_j] = (int8_T)(1 + eml_j);
        }

        for (eml_jpiv_offset = 0; eml_jpiv_offset < 10; eml_jpiv_offset++) {
          eml_jrow = eml_ipiv[eml_jpiv_offset];
          if (eml_jrow > eml_jpiv_offset + 1) {
            eml_loop_ub = (int32_T)eml_p[eml_jrow - 1];
            eml_p[eml_jrow - 1] = eml_p[eml_jpiv_offset];
            eml_p[eml_jpiv_offset] = (int8_T)eml_loop_ub;
          }
        }

        for (eml_jpiv_offset = 0; eml_jpiv_offset < 10; eml_jpiv_offset++) {
          eml_jrow = (int32_T)eml_p[eml_jpiv_offset];
          eml_y[eml_jpiv_offset + 10 * (eml_jrow - 1)] = 1.0;
          for (eml_loop_ub = eml_jpiv_offset + 1; eml_loop_ub < 11; eml_loop_ub
               ++) {
            if (eml_y[(eml_loop_ub - 1) + 10 * (eml_jrow - 1)] != 0.0) {
              for (eml_i = eml_loop_ub + 1; eml_i < 11; eml_i++) {
                eml_y[(eml_i - 1) + 10 * (eml_jrow - 1)] -= eml_y[(eml_loop_ub -
                  1) + 10 * (eml_jrow - 1)] * eml_x[(eml_i - 1) + 10 *
                  (eml_loop_ub - 1)];
              }
            }
          }
        }

        for (eml_jpiv_offset = 0; eml_jpiv_offset < 10; eml_jpiv_offset++) {
          eml_jrow = eml_jpiv_offset * 10;
          for (eml_loop_ub = 10; eml_loop_ub > 0; eml_loop_ub += -1) {
            eml_i = (eml_loop_ub - 1) * 10;
            if (eml_y[(eml_loop_ub + eml_jrow) - 1] != 0.0) {
              eml_y[(eml_loop_ub + eml_jrow) - 1] /= eml_x[(eml_loop_ub + eml_i)
                - 1];
              eml_j = eml_loop_ub - 1;
              for (eml_mmj = 1; eml_mmj <= eml_j; eml_mmj++) {
                eml_y[(eml_mmj + eml_jrow) - 1] -= eml_y[(eml_loop_ub + eml_jrow)
                  - 1] * eml_x[(eml_mmj + eml_i) - 1];
              }
            }
          }
        }

        for (eml_j = 0; eml_j < 10; eml_j++) {
          for (eml_mmj = 0; eml_mmj < 10; eml_mmj++) {
            eml_x[eml_mmj + 10 * eml_j] = -eml_y[eml_mmj + 10 * eml_j];
          }
        }

        for (eml_j = 0; eml_j < 10; eml_j++) {
          MPC_AVC_implementation_B.eta[eml_j] = 0.0;
          for (eml_mmj = 0; eml_mmj < 10; eml_mmj++) {
            MPC_AVC_implementation_B.eta[eml_j] =
              MPC_AVC_implementation_B.eta[eml_j] + eml_x[eml_j + 10 * eml_mmj] *
              MPC_AVC_implementation_B.Add2[eml_mmj];
          }
        }

        /* '<S8>:1:6' */
        eml_kk = 0.0;
        for (eml_jpiv_offset = 0; eml_jpiv_offset < 4; eml_jpiv_offset++) {
          /* '<S8>:1:7' */
          for (eml_j = 0; eml_j < 10; eml_j++) {
            eml_a[eml_j] = MPC_AVC_implementation_P.A_cons_Value[eml_jpiv_offset
              + (eml_j << 2)];
          }

          eml_y_0 = 0.0;
          for (eml_jrow = 0; eml_jrow < 10; eml_jrow++) {
            eml_y_0 += eml_a[eml_jrow] * MPC_AVC_implementation_B.eta[eml_jrow];
          }

          if (eml_y_0 > MPC_AVC_implementation_B.Add1[eml_jpiv_offset]) {
            /* '<S8>:1:8' */
            /* '<S8>:1:9' */
            eml_kk++;
          } else {
            /* '<S8>:1:11' */
          }
        }

        if (!(eml_kk == 0.0)) {
          /* '<S8>:1:17' */
          for (eml_j = 0; eml_j < 4; eml_j++) {
            for (eml_mmj = 0; eml_mmj < 10; eml_mmj++) {
              eml_dv0[eml_mmj + 10 * eml_j] =
                MPC_AVC_implementation_P.A_cons_Value[eml_j + (eml_mmj << 2)];
            }
          }

          nglfaaiedbaiecba_mldivide(&MPC_AVC_implementation_P.omega_Value[0],
            eml_dv0, eml_hoistedExpr);
          for (eml_j = 0; eml_j < 4; eml_j++) {
            for (eml_mmj = 0; eml_mmj < 4; eml_mmj++) {
              eml_P[eml_j + (eml_mmj << 2)] = 0.0;
              for (eml_jj = 0; eml_jj < 10; eml_jj++) {
                eml_P[eml_j + (eml_mmj << 2)] +=
                  MPC_AVC_implementation_P.A_cons_Value[eml_j + (eml_jj << 2)] *
                  eml_hoistedExpr[eml_jj + 10 * eml_mmj];
              }
            }
          }

          /* '<S8>:1:18' */
          nglnohdbopphdjmg_mldivide(&MPC_AVC_implementation_P.omega_Value[0],
            MPC_AVC_implementation_B.Add2, eml_hoistedExpr_0);
          for (eml_j = 0; eml_j < 4; eml_j++) {
            eml_kk = 0.0;
            for (eml_mmj = 0; eml_mmj < 10; eml_mmj++) {
              eml_kk += MPC_AVC_implementation_P.A_cons_Value[eml_j + (eml_mmj <<
                2)] * eml_hoistedExpr_0[eml_mmj];
            }

            eml_d[eml_j] = eml_kk + MPC_AVC_implementation_B.Add1[eml_j];
          }

          /* '<S8>:1:20' */
          /* '<S8>:1:21' */
          for (eml_j = 0; eml_j < 4; eml_j++) {
            eml_lambda[eml_j] = 0.0;
          }

          /*  al=10; */
          eml_loop_ub = 1;
          eml_exitg1 = 0U;
          while ((eml_exitg1 == 0U) && (eml_loop_ub <= 38)) {
            /* '<S8>:1:23' */
            /* find tomegae elements in tomegae solution vector one by one */
            /*  km could be larger if tomegae Lagranger multiplier omegaas a slow */
            /*  convergence rate. */
            /* '<S8>:1:28' */
            for (eml_j = 0; eml_j < 4; eml_j++) {
              eml_lambda_p[eml_j] = eml_lambda[eml_j];
            }

            for (eml_jpiv_offset = 0; eml_jpiv_offset < 4; eml_jpiv_offset++) {
              /* '<S8>:1:29' */
              /* '<S8>:1:30' */
              for (eml_j = 0; eml_j < 4; eml_j++) {
                eml_a_0[eml_j] = eml_P[eml_jpiv_offset + (eml_j << 2)];
              }

              eml_kk = 0.0;
              for (eml_jrow = 0; eml_jrow < 4; eml_jrow++) {
                eml_kk += eml_a_0[eml_jrow] * eml_lambda[eml_jrow];
              }

              /* '<S8>:1:31' */
              /* '<S8>:1:32' */
              eml_kk = (-((eml_kk - eml_P[eml_jpiv_offset + (eml_jpiv_offset <<
                2)] * eml_lambda[eml_jpiv_offset]) + eml_d[eml_jpiv_offset])) /
                eml_P[eml_jpiv_offset + (eml_jpiv_offset << 2)];

              /* '<S8>:1:33' */
              if ((0.0 >= eml_kk) || ((boolean_T)rtIsNaN(eml_kk))) {
                eml_kk = 0.0;
              }

              eml_lambda[eml_jpiv_offset] = eml_kk;
            }

            /* '<S8>:1:36' */
            for (eml_j = 0; eml_j < 4; eml_j++) {
              eml_kk = eml_lambda_p[eml_j];
              eml_a_0[eml_j] = eml_lambda[eml_j] - eml_kk;
              eml_kk = eml_lambda[eml_j] - eml_kk;
              eml_lambda_p[eml_j] = eml_kk;
            }

            eml_kk = 0.0;
            for (eml_jpiv_offset = 0; eml_jpiv_offset < 4; eml_jpiv_offset++) {
              eml_kk += eml_a_0[eml_jpiv_offset] * eml_lambda_p[eml_jpiv_offset];
            }

            if (eml_kk < 1.0E-007) {
              /* '<S8>:1:37' */
              eml_exitg1 = 1U;
            } else {
              eml_loop_ub++;
            }
          }

          /* '<S8>:1:41' */
          for (eml_j = 0; eml_j < 10; eml_j++) {
            for (eml_mmj = 0; eml_mmj < 10; eml_mmj++) {
              eml_x[eml_mmj + 10 * eml_j] =
                -MPC_AVC_implementation_P.omega_Value[eml_mmj + 10 * eml_j];
            }
          }

          nglnohdbopphdjmg_mldivide(eml_x, MPC_AVC_implementation_B.Add2,
            eml_hoistedExpr_0);
          for (eml_j = 0; eml_j < 4; eml_j++) {
            for (eml_mmj = 0; eml_mmj < 10; eml_mmj++) {
              eml_dv0[eml_mmj + 10 * eml_j] =
                MPC_AVC_implementation_P.A_cons_Value[eml_j + (eml_mmj << 2)];
            }
          }

          nglfaaiedbaiecba_mldivide(&MPC_AVC_implementation_P.omega_Value[0],
            eml_dv0, eml_hoistedExpr);
          for (eml_j = 0; eml_j < 10; eml_j++) {
            eml_kk = 0.0;
            for (eml_mmj = 0; eml_mmj < 4; eml_mmj++) {
              eml_kk += eml_hoistedExpr[eml_j + 10 * eml_mmj] *
                eml_lambda[eml_mmj];
            }

            MPC_AVC_implementation_B.eta[eml_j] = eml_hoistedExpr_0[eml_j] -
              eml_kk;
          }
        } else {
          /* '<S8>:1:14' */
        }
      }

      /* Gain Block: '<S2>/L_m'
       * About '<S2>/L_m :'
       *   Gain value: L_m


       */
      {
        static const int_T dims[3] = { 2, 10, 1 };

        rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.L_m, (real_T *)
                         &MPC_AVC_implementation_P.L_m_Gain[0],
                         (real_T *)MPC_AVC_implementation_B.eta, &dims[0]);
      }

      /* Gain: '<S2>/Gain1' */
      MPC_AVC_implementation_B.Gain1[0] = MPC_AVC_implementation_P.Gain1_Gain *
        MPC_AVC_implementation_B.L_m[0];
      MPC_AVC_implementation_B.Gain1[1] = MPC_AVC_implementation_P.Gain1_Gain *
        MPC_AVC_implementation_B.L_m[1];

      /* Gain: '<S2>/Gain7' */
      MPC_AVC_implementation_B.Gain7[0] = MPC_AVC_implementation_P.Gain7_Gain *
        MPC_AVC_implementation_B.UnitDelay16[0];
      MPC_AVC_implementation_B.Gain7[1] = MPC_AVC_implementation_P.Gain7_Gain *
        MPC_AVC_implementation_B.UnitDelay16[1];

      /* Gain: '<S2>/Gain10' */
      MPC_AVC_implementation_B.Gain10[0] = MPC_AVC_implementation_P.Gain10_Gain *
        MPC_AVC_implementation_B.UnitDelay13[0];
      MPC_AVC_implementation_B.Gain10[1] = MPC_AVC_implementation_P.Gain10_Gain *
        MPC_AVC_implementation_B.UnitDelay13[1];

      /* Gain: '<S2>/Gain9' */
      MPC_AVC_implementation_B.Gain9[0] = MPC_AVC_implementation_P.Gain9_Gain *
        MPC_AVC_implementation_B.UnitDelay14[0];
      MPC_AVC_implementation_B.Gain9[1] = MPC_AVC_implementation_P.Gain9_Gain *
        MPC_AVC_implementation_B.UnitDelay14[1];

      /* Gain: '<S2>/Gain8' */
      MPC_AVC_implementation_B.Gain8[0] = MPC_AVC_implementation_P.Gain8_Gain *
        MPC_AVC_implementation_B.UnitDelay15[0];
      MPC_AVC_implementation_B.Gain8[1] = MPC_AVC_implementation_P.Gain8_Gain *
        MPC_AVC_implementation_B.UnitDelay15[1];

      /* Gain: '<S2>/Gain22' */
      MPC_AVC_implementation_B.Gain22[0] = MPC_AVC_implementation_P.Gain22_Gain *
        MPC_AVC_implementation_B.UnitDelay12[0];
      MPC_AVC_implementation_B.Gain22[1] = MPC_AVC_implementation_P.Gain22_Gain *
        MPC_AVC_implementation_B.UnitDelay12[1];

      /* Gain: '<S2>/Gain21' */
      MPC_AVC_implementation_B.Gain21[0] = MPC_AVC_implementation_P.Gain21_Gain *
        MPC_AVC_implementation_B.UnitDelay9[0];
      MPC_AVC_implementation_B.Gain21[1] = MPC_AVC_implementation_P.Gain21_Gain *
        MPC_AVC_implementation_B.UnitDelay9[1];

      /* Gain: '<S2>/Gain20' */
      MPC_AVC_implementation_B.Gain20[0] = MPC_AVC_implementation_P.Gain20_Gain *
        MPC_AVC_implementation_B.UnitDelay10[0];
      MPC_AVC_implementation_B.Gain20[1] = MPC_AVC_implementation_P.Gain20_Gain *
        MPC_AVC_implementation_B.UnitDelay10[1];

      /* Gain: '<S2>/Gain19' */
      MPC_AVC_implementation_B.Gain19[0] = MPC_AVC_implementation_P.Gain19_Gain *
        MPC_AVC_implementation_B.UnitDelay11[0];
      MPC_AVC_implementation_B.Gain19[1] = MPC_AVC_implementation_P.Gain19_Gain *
        MPC_AVC_implementation_B.UnitDelay11[1];

      /* Gain: '<S2>/Gain6' */
      MPC_AVC_implementation_B.Gain6[0] = MPC_AVC_implementation_P.Gain6_Gain *
        MPC_AVC_implementation_B.UnitDelay7[0];
      MPC_AVC_implementation_B.Gain6[1] = MPC_AVC_implementation_P.Gain6_Gain *
        MPC_AVC_implementation_B.UnitDelay7[1];

      /* Gain: '<S2>/Gain5' */
      MPC_AVC_implementation_B.Gain5[0] = MPC_AVC_implementation_P.Gain5_Gain *
        MPC_AVC_implementation_B.UnitDelay1[0];
      MPC_AVC_implementation_B.Gain5[1] = MPC_AVC_implementation_P.Gain5_Gain *
        MPC_AVC_implementation_B.UnitDelay1[1];

      /* Gain: '<S2>/Gain4' */
      MPC_AVC_implementation_B.Gain4[0] = MPC_AVC_implementation_P.Gain4_Gain *
        MPC_AVC_implementation_B.UnitDelay2[0];
      MPC_AVC_implementation_B.Gain4[1] = MPC_AVC_implementation_P.Gain4_Gain *
        MPC_AVC_implementation_B.UnitDelay2[1];

      /* Gain: '<S2>/Gain3' */
      MPC_AVC_implementation_B.Gain3[0] = MPC_AVC_implementation_P.Gain3_Gain *
        MPC_AVC_implementation_B.UnitDelay6[0];
      MPC_AVC_implementation_B.Gain3[1] = MPC_AVC_implementation_P.Gain3_Gain *
        MPC_AVC_implementation_B.UnitDelay6[1];

      /* Sum: '<S2>/Add' */
      MPC_AVC_implementation_B.Add[0] =
        ((((((((((MPC_AVC_implementation_B.Gain7[0] +
                  MPC_AVC_implementation_B.Gain10[0]) +
                 MPC_AVC_implementation_B.Gain9[0]) +
                MPC_AVC_implementation_B.Gain8[0]) +
               MPC_AVC_implementation_B.Gain22[0]) +
              MPC_AVC_implementation_B.Gain21[0]) +
             MPC_AVC_implementation_B.Gain20[0]) +
            MPC_AVC_implementation_B.Gain19[0]) +
           MPC_AVC_implementation_B.Gain6[0]) + MPC_AVC_implementation_B.Gain5[0])
         + MPC_AVC_implementation_B.Gain4[0]) + MPC_AVC_implementation_B.Gain3[0];
      MPC_AVC_implementation_B.Add[1] =
        ((((((((((MPC_AVC_implementation_B.Gain7[1] +
                  MPC_AVC_implementation_B.Gain10[1]) +
                 MPC_AVC_implementation_B.Gain9[1]) +
                MPC_AVC_implementation_B.Gain8[1]) +
               MPC_AVC_implementation_B.Gain22[1]) +
              MPC_AVC_implementation_B.Gain21[1]) +
             MPC_AVC_implementation_B.Gain20[1]) +
            MPC_AVC_implementation_B.Gain19[1]) +
           MPC_AVC_implementation_B.Gain6[1]) + MPC_AVC_implementation_B.Gain5[1])
         + MPC_AVC_implementation_B.Gain4[1]) + MPC_AVC_implementation_B.Gain3[1];

      /* Gain: '<S2>/Gain2' */
      MPC_AVC_implementation_B.Gain2[0] = MPC_AVC_implementation_P.Gain2_Gain *
        MPC_AVC_implementation_B.Add[0];
      MPC_AVC_implementation_B.Gain2[1] = MPC_AVC_implementation_P.Gain2_Gain *
        MPC_AVC_implementation_B.Add[1];

      /* Sum: '<S2>/Sum' */
      MPC_AVC_implementation_B.Sum[0] = MPC_AVC_implementation_B.Gain1[0] +
        MPC_AVC_implementation_B.Gain2[0];
      MPC_AVC_implementation_B.Sum[1] = MPC_AVC_implementation_B.Gain1[1] +
        MPC_AVC_implementation_B.Gain2[1];
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
      MPC_AVC_implementation_B.Product_j =
        MPC_AVC_implementation_P.deltaFreq_Value /
        MPC_AVC_implementation_P.targetTime_Value;

      /* Gain: '<S1>/Gain' */
      MPC_AVC_implementation_B.Gain = MPC_AVC_implementation_P.Gain_Gain *
        MPC_AVC_implementation_B.Product_j;
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

    /* Gain: '<Root>/Gain1' */
    MPC_AVC_implementation_B.Gain1_m = MPC_AVC_implementation_P.Gain1_Gain_f *
      MPC_AVC_implementation_B.Output;

    /* Gain Block: '<Root>/H'
     * About '<Root>/H :'
     *   Gain value: Hg


     */
    {
      static const int_T dims[3] = { 6, 1, 1 };

      rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.H, (real_T *)
                       &MPC_AVC_implementation_P.H_Gain[0],
                       (real_T *)&MPC_AVC_implementation_B.Gain1_m, &dims[0]);
    }

    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain Block: '<Root>/B'
       * About '<Root>/B :'
       *   Gain value: Bg


       */
      {
        static const int_T dims[3] = { 6, 2, 1 };

        rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.B, (real_T *)
                         &MPC_AVC_implementation_P.B_Gain[0],
                         (real_T *)MPC_AVC_implementation_B.Sum, &dims[0]);
      }

      /* S-Function (sfix_udelay) Block: '<Root>/Delay'
       * About '<Root>/Delay :'
       * Integer/Tapped Delay Block: '<Root>/Delay'


       */
      (void) memcpy(MPC_AVC_implementation_B.Delay,
                    &MPC_AVC_implementation_DWork.Delay_X[0],
                    6*sizeof(real_T));

      /* Gain Block: '<Root>/Ag'
       * About '<Root>/Ag :'
       *   Gain value: Ag


       */
      {
        static const int_T dims[3] = { 6, 6, 1 };

        rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.Ag, (real_T *)
                         &MPC_AVC_implementation_P.Ag_Gain[0],
                         (real_T *)MPC_AVC_implementation_B.Delay, &dims[0]);
      }
    }

    for (i = 0; i < 6; i++) {
      /* Sum: '<Root>/Add' */
      MPC_AVC_implementation_B.Add_f[i] = (MPC_AVC_implementation_B.H[i] +
        MPC_AVC_implementation_B.B[i]) + MPC_AVC_implementation_B.Ag[i];
    }

    /* Outputs for atomic SubSystem: '<S2>/Recursive LS_all' incorporates:
     *  Sum: '<S9>/Add2'
     */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function (sfix_udelay) Block: '<S9>/Delay'
       * About '<S9>/Delay :'
       * Integer/Tapped Delay Block: '<S9>/Delay'


       */
      (void) memcpy(MPC_AVC_implementation_B.Delay_d,
                    &MPC_AVC_implementation_DWork.Delay_X_e[0],
                    6*sizeof(real_T));

      /* Gain Block: '<S9>/Ag'
       * About '<S9>/Ag :'
       *   Gain value: Ag


       */
      {
        static const int_T dims[3] = { 6, 6, 1 };

        rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.Ag_b, (real_T *)
                         &MPC_AVC_implementation_P.Ag_Gain_k[0],
                         (real_T *)MPC_AVC_implementation_B.Delay_d, &dims[0]);
      }

      /* Gain Block: '<S9>/Bg'
       * About '<S9>/Bg :'
       *   Gain value: Bg


       */
      {
        static const int_T dims[3] = { 6, 2, 1 };

        rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.Bg, (real_T *)
                         &MPC_AVC_implementation_P.Bg_Gain[0],
                         (real_T *)MPC_AVC_implementation_B.Sum, &dims[0]);
      }
    }

    for (i = 0; i < 6; i++) {
      /* Sum: '<S9>/Add2' */
      MPC_AVC_implementation_B.Add2_i[i] = (MPC_AVC_implementation_B.Add_f[i] -
        MPC_AVC_implementation_B.Ag_b[i]) - MPC_AVC_implementation_B.Bg[i];
    }

    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* UnitDelay: '<S9>/Unit Delay4' */
      MPC_AVC_implementation_B.UnitDelay4 =
        MPC_AVC_implementation_DWork.UnitDelay4_DSTATE;

      /* UnitDelay: '<S9>/Unit Delay3' */
      MPC_AVC_implementation_B.UnitDelay3 =
        MPC_AVC_implementation_DWork.UnitDelay3_DSTATE;
    }

    /* Embedded MATLAB Block: '<S9>/MATLAB Function1'
     */
    {
      int32_T eml_k;
      real_T eml_a[6];
      int32_T eml_i0;
      real_T eml_dv0[36];
      real_T eml_Ks[6];
      real_T eml_b[6];
      real_T eml_y;
      real_T eml_y_0;
      real_T eml_y_1;

      /* Embedded MATLAB Function 'Controller/Recursive LS_all/MATLAB Function1': '<S12>:1' */
      if (MPC_AVC_implementation_B.kk1 == 1.0) {
        /* '<S12>:1:3' */
        /* '<S12>:1:5' */
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_a[eml_k] = MPC_AVC_implementation_P.Ps_Value *
            MPC_AVC_implementation_P.Hg_Value[eml_k];
        }

        for (eml_k = 0; eml_k < 6; eml_k++) {
          for (eml_i0 = 0; eml_i0 < 6; eml_i0++) {
            eml_dv0[eml_i0 + 6 * eml_k] =
              MPC_AVC_implementation_P.Hg_Value[eml_i0] *
              MPC_AVC_implementation_P.Ps_Value *
              MPC_AVC_implementation_P.Hg_Value[eml_k] +
              MPC_AVC_implementation_P.Rs_Value;
          }
        }

        jeknbaaaecbalfkf_mrdivide(eml_a, eml_dv0, eml_Ks);

        /* '<S12>:1:6' */
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_b[eml_k] = MPC_AVC_implementation_B.Add2_i[eml_k] -
            MPC_AVC_implementation_P.Hg_Value[eml_k] *
            MPC_AVC_implementation_B.UnitDelay3;
        }

        eml_y = 0.0;
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_y += eml_Ks[eml_k] * eml_b[eml_k];
        }

        MPC_AVC_implementation_B.theta = MPC_AVC_implementation_B.UnitDelay3 +
          eml_y;

        /* '<S12>:1:7' */
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_a[eml_k] = eml_Ks[eml_k] * MPC_AVC_implementation_P.Rs_Value;
          eml_b[eml_k] = eml_Ks[eml_k];
        }

        eml_y = 0.0;
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_y += eml_a[eml_k] * eml_b[eml_k];
        }

        eml_y_0 = 0.0;
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_y_0 += eml_Ks[eml_k] * MPC_AVC_implementation_P.Hg_Value[eml_k];
        }

        eml_y_1 = 0.0;
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_y_1 += eml_Ks[eml_k] * MPC_AVC_implementation_P.Hg_Value[eml_k];
        }

        MPC_AVC_implementation_B.Ps1 = (1.0 - eml_y_0) *
          MPC_AVC_implementation_P.Ps_Value * (1.0 - eml_y_1) + eml_y;
      } else {
        /* '<S12>:1:10' */
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_a[eml_k] = MPC_AVC_implementation_B.UnitDelay4 *
            MPC_AVC_implementation_P.Hg_Value[eml_k];
        }

        for (eml_k = 0; eml_k < 6; eml_k++) {
          for (eml_i0 = 0; eml_i0 < 6; eml_i0++) {
            eml_dv0[eml_i0 + 6 * eml_k] =
              MPC_AVC_implementation_P.Hg_Value[eml_i0] *
              MPC_AVC_implementation_B.UnitDelay4 *
              MPC_AVC_implementation_P.Hg_Value[eml_k] +
              MPC_AVC_implementation_P.Rs_Value;
          }
        }

        jeknbaaaecbalfkf_mrdivide(eml_a, eml_dv0, eml_Ks);

        /* '<S12>:1:11' */
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_b[eml_k] = MPC_AVC_implementation_B.Add2_i[eml_k] -
            MPC_AVC_implementation_P.Hg_Value[eml_k] *
            MPC_AVC_implementation_B.UnitDelay3;
        }

        eml_y = 0.0;
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_y += eml_Ks[eml_k] * eml_b[eml_k];
        }

        MPC_AVC_implementation_B.theta = MPC_AVC_implementation_B.UnitDelay3 +
          eml_y;

        /* '<S12>:1:12' */
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_a[eml_k] = eml_Ks[eml_k] * MPC_AVC_implementation_P.Rs_Value;
          eml_b[eml_k] = eml_Ks[eml_k];
        }

        eml_y = 0.0;
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_y += eml_a[eml_k] * eml_b[eml_k];
        }

        eml_y_0 = 0.0;
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_y_0 += eml_Ks[eml_k] * MPC_AVC_implementation_P.Hg_Value[eml_k];
        }

        eml_y_1 = 0.0;
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_y_1 += eml_Ks[eml_k] * MPC_AVC_implementation_P.Hg_Value[eml_k];
        }

        MPC_AVC_implementation_B.Ps1 = (1.0 - eml_y_0) *
          MPC_AVC_implementation_B.UnitDelay4 * (1.0 - eml_y_1) + eml_y;
      }
    }

    /* end of Outputs for SubSystem: '<S2>/Recursive LS_all' */

    /* Gain Block: '<Root>/inv(Bg'*Bg)*Hg'
     * About '<Root>/inv(Bg'*Bg)*Hg :'
     *   Gain value: inv(Bg'*Bg)*(Bg'*Hg)


     */
    {
      static const int_T dims[3] = { 2, 1, 1 };

      rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.invBgBgHg, (real_T *)
                       &MPC_AVC_implementation_P.invBgBgHg_Gain[0],
                       (real_T *)&MPC_AVC_implementation_B.theta, &dims[0]);
    }

    /* Gain: '<Root>/on_off1' */
    MPC_AVC_implementation_B.on_off1[0] = MPC_AVC_implementation_P.on_off1_Gain *
      MPC_AVC_implementation_B.invBgBgHg[0];
    MPC_AVC_implementation_B.on_off1[1] = MPC_AVC_implementation_P.on_off1_Gain *
      MPC_AVC_implementation_B.invBgBgHg[1];

    /* Sum: '<Root>/Add2' */
    MPC_AVC_implementation_B.Add2_m[0] = MPC_AVC_implementation_B.Sum[0] -
      MPC_AVC_implementation_B.on_off1[0];
    MPC_AVC_implementation_B.Add2_m[1] = MPC_AVC_implementation_B.Sum[1] -
      MPC_AVC_implementation_B.on_off1[1];

    /* Saturate: '<Root>/Saturation' */
    unnamed_idx = MPC_AVC_implementation_B.Add2_m[0];
    unnamed_idx_0 = MPC_AVC_implementation_B.Add2_m[1];
    MPC_AVC_implementation_B.Saturation[0] = rt_SATURATE(unnamed_idx,
      MPC_AVC_implementation_P.Saturation_LowerSat,
      MPC_AVC_implementation_P.Saturation_UpperSat);
    MPC_AVC_implementation_B.Saturation[1] = rt_SATURATE(unnamed_idx_0,
      MPC_AVC_implementation_P.Saturation_LowerSat,
      MPC_AVC_implementation_P.Saturation_UpperSat);

    /* Gain: '<Root>/on_off2' */
    MPC_AVC_implementation_B.on_off2[0] = MPC_AVC_implementation_P.on_off2_Gain *
      MPC_AVC_implementation_B.Saturation[0];
    MPC_AVC_implementation_B.on_off2[1] = MPC_AVC_implementation_P.on_off2_Gain *
      MPC_AVC_implementation_B.Saturation[1];

    /* Gain: '<Root>/Amplifier' */
    MPC_AVC_implementation_B.Amplifier[0] =
      MPC_AVC_implementation_P.Amplifier_Gain *
      MPC_AVC_implementation_B.on_off2[0];
    MPC_AVC_implementation_B.Amplifier[1] =
      MPC_AVC_implementation_P.Amplifier_Gain *
      MPC_AVC_implementation_B.on_off2[1];
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* Gain: '<Root>/Amplifier2' */
    MPC_AVC_implementation_B.Amplifier2[0] =
      MPC_AVC_implementation_P.Amplifier2_Gain *
      MPC_AVC_implementation_B.invBgBgHg[0];
    MPC_AVC_implementation_B.Amplifier2[1] =
      MPC_AVC_implementation_P.Amplifier2_Gain *
      MPC_AVC_implementation_B.invBgBgHg[1];
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* Saturate: '<Root>/Saturation1' */
    unnamed_idx = MPC_AVC_implementation_B.Gain1_m;
    MPC_AVC_implementation_B.Saturation1 = rt_SATURATE(unnamed_idx,
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
    MPC_AVC_implementation_B.dSpace_gain1[0] =
      MPC_AVC_implementation_P.dSpace_gain1_Gain *
      MPC_AVC_implementation_B.on_off2[0];
    MPC_AVC_implementation_B.dSpace_gain1[1] =
      MPC_AVC_implementation_P.dSpace_gain1_Gain *
      MPC_AVC_implementation_B.on_off2[1];
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL2 */
      ds2102_out(DS2102_1_BASE, 2, (dsfloat)
                 MPC_AVC_implementation_B.dSpace_gain1[0]);

      /* This comment workarounds a Real-Time Workshop code generation problem */

      /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL3 */
      ds2102_out(DS2102_1_BASE, 3, (dsfloat)
                 MPC_AVC_implementation_B.dSpace_gain1[1]);

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

      /* Gain: '<Root>/dSpace_gain2' */
      MPC_AVC_implementation_B.dSpace_gain2 =
        MPC_AVC_implementation_P.dSpace_gain2_Gain *
        MPC_AVC_implementation_B.SFunction1;
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

    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Sin: '<Root>/Sine Wave' */
      if (MPC_AVC_implementation_DWork.systemEnable == 1) {
        MPC_AVC_implementation_DWork.lastSin = sin
          (MPC_AVC_implementation_P.SineWave_Freq *
           MPC_AVC_implementation_M->Timing.t[1]);
        MPC_AVC_implementation_DWork.lastCos = cos
          (MPC_AVC_implementation_P.SineWave_Freq *
           MPC_AVC_implementation_M->Timing.t[1]);
        MPC_AVC_implementation_DWork.systemEnable = 0;
      }

      MPC_AVC_implementation_B.SineWave = ((MPC_AVC_implementation_DWork.lastSin
        * MPC_AVC_implementation_P.SineWave_PCos +
        MPC_AVC_implementation_DWork.lastCos *
        MPC_AVC_implementation_P.SineWave_PSin) *
        MPC_AVC_implementation_P.SineWave_HCos +
        (MPC_AVC_implementation_DWork.lastCos *
         MPC_AVC_implementation_P.SineWave_PCos -
         MPC_AVC_implementation_DWork.lastSin *
         MPC_AVC_implementation_P.SineWave_PSin) *
        MPC_AVC_implementation_P.SineWave_Hsin) *
        MPC_AVC_implementation_P.SineWave_Amp +
        MPC_AVC_implementation_P.SineWave_Bias;
    }

    /* Step: '<Root>/Step' */
    unnamed_idx = MPC_AVC_implementation_M->Timing.t[0];
    if (unnamed_idx < MPC_AVC_implementation_P.Step_Time) {
      MPC_AVC_implementation_B.Step = MPC_AVC_implementation_P.Step_Y0;
    } else {
      MPC_AVC_implementation_B.Step = MPC_AVC_implementation_P.Step_YFinal;
    }

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
  {
    real_T HoldSine;
    real_T HoldCosine;
    int32_T i;

    /* Update for atomic SubSystem: '<S2>/Kalman Filter' incorporates:
     *  Update for UnitDelay: '<S7>/Unit Delay3'
     */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain Block: '<S7>/B'
       * About '<S7>/B :'
       *   Gain value: B


       */
      {
        static const int_T dims[3] = { 18, 2, 1 };

        rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.B_i, (real_T *)
                         &MPC_AVC_implementation_P.B_Gain_k[0],
                         (real_T *)MPC_AVC_implementation_B.Gain1, &dims[0]);
      }
    }

    for (i = 0; i < 18; i++) {
      /* Sum: '<S7>/Sum' */
      MPC_AVC_implementation_B.Sum_l[i] = (MPC_AVC_implementation_B.B_i[i] +
        MPC_AVC_implementation_B.Product_l[i]) + MPC_AVC_implementation_B.A[i];
    }

    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      for (i = 0; i < 18; i++) {
        /* Update for UnitDelay: '<S7>/Unit Delay3' */
        MPC_AVC_implementation_DWork.UnitDelay3_DSTATE_j[i] =
          MPC_AVC_implementation_B.Sum_l[i];
      }
    }

    /* end of Update for SubSystem: '<S2>/Kalman Filter' */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S2>/Unit Delay16' */
      MPC_AVC_implementation_DWork.UnitDelay16_DSTATE[0] =
        MPC_AVC_implementation_B.Sum[0];
      MPC_AVC_implementation_DWork.UnitDelay16_DSTATE[1] =
        MPC_AVC_implementation_B.Sum[1];

      /* Update for UnitDelay: '<S2>/Unit Delay13' */
      MPC_AVC_implementation_DWork.UnitDelay13_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay16[0];
      MPC_AVC_implementation_DWork.UnitDelay13_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay16[1];

      /* Update for UnitDelay: '<S2>/Unit Delay14' */
      MPC_AVC_implementation_DWork.UnitDelay14_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay13[0];
      MPC_AVC_implementation_DWork.UnitDelay14_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay13[1];

      /* Update for UnitDelay: '<S2>/Unit Delay15' */
      MPC_AVC_implementation_DWork.UnitDelay15_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay14[0];
      MPC_AVC_implementation_DWork.UnitDelay15_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay14[1];

      /* Update for UnitDelay: '<S2>/Unit Delay12' */
      MPC_AVC_implementation_DWork.UnitDelay12_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay15[0];
      MPC_AVC_implementation_DWork.UnitDelay12_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay15[1];

      /* Update for UnitDelay: '<S2>/Unit Delay9' */
      MPC_AVC_implementation_DWork.UnitDelay9_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay12[0];
      MPC_AVC_implementation_DWork.UnitDelay9_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay12[1];

      /* Update for UnitDelay: '<S2>/Unit Delay10' */
      MPC_AVC_implementation_DWork.UnitDelay10_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay9[0];
      MPC_AVC_implementation_DWork.UnitDelay10_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay9[1];

      /* Update for UnitDelay: '<S2>/Unit Delay11' */
      MPC_AVC_implementation_DWork.UnitDelay11_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay10[0];
      MPC_AVC_implementation_DWork.UnitDelay11_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay10[1];

      /* Update for UnitDelay: '<S2>/Unit Delay7' */
      MPC_AVC_implementation_DWork.UnitDelay7_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay11[0];
      MPC_AVC_implementation_DWork.UnitDelay7_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay11[1];

      /* Update for UnitDelay: '<S2>/Unit Delay1' */
      MPC_AVC_implementation_DWork.UnitDelay1_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay7[0];
      MPC_AVC_implementation_DWork.UnitDelay1_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay7[1];

      /* Update for UnitDelay: '<S2>/Unit Delay2' */
      MPC_AVC_implementation_DWork.UnitDelay2_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay1[0];
      MPC_AVC_implementation_DWork.UnitDelay2_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay1[1];

      /* Update for UnitDelay: '<S2>/Unit Delay6' */
      MPC_AVC_implementation_DWork.UnitDelay6_DSTATE[0] =
        MPC_AVC_implementation_B.UnitDelay2[0];
      MPC_AVC_implementation_DWork.UnitDelay6_DSTATE[1] =
        MPC_AVC_implementation_B.UnitDelay2[1];

      /* Integer/Tapped Delay Block: '<Root>/Delay'
       */
      (void) memcpy(&MPC_AVC_implementation_DWork.Delay_X[0],
                    MPC_AVC_implementation_B.Add_f,
                    6*sizeof(real_T));
    }

    /* Update for atomic SubSystem: '<S2>/Recursive LS_all' */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Integer/Tapped Delay Block: '<S9>/Delay'
       */
      (void) memcpy(&MPC_AVC_implementation_DWork.Delay_X_e[0],
                    MPC_AVC_implementation_B.Add_f,
                    6*sizeof(real_T));

      /* Update for UnitDelay: '<S9>/Unit Delay4' */
      MPC_AVC_implementation_DWork.UnitDelay4_DSTATE =
        MPC_AVC_implementation_B.Ps1;

      /* Update for UnitDelay: '<S9>/Unit Delay3' */
      MPC_AVC_implementation_DWork.UnitDelay3_DSTATE =
        MPC_AVC_implementation_B.theta;
    }

    /* end of Update for SubSystem: '<S2>/Recursive LS_all' */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Sin: '<Root>/Sine Wave' */
      HoldSine = MPC_AVC_implementation_DWork.lastSin;
      HoldCosine = MPC_AVC_implementation_DWork.lastCos;
      MPC_AVC_implementation_DWork.lastSin = HoldSine *
        MPC_AVC_implementation_P.SineWave_HCos + HoldCosine *
        MPC_AVC_implementation_P.SineWave_Hsin;
      MPC_AVC_implementation_DWork.lastCos = HoldCosine *
        MPC_AVC_implementation_P.SineWave_HCos - HoldSine *
        MPC_AVC_implementation_P.SineWave_Hsin;
    }
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
  {
    int32_T i;

    /* StateSpace Block: '<Root>/Analog Filter Design1' */
    {
      ((StateDerivatives_MPC_AVC_implem *)
        MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE
        [0] = MPC_AVC_implementation_P.AnalogFilterDesign1_B*
        MPC_AVC_implementation_B.dSpace_gain2;
      ((StateDerivatives_MPC_AVC_implem *)
        MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE
        [0] += (MPC_AVC_implementation_P.AnalogFilterDesign1_A[0])*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[0]
        + (MPC_AVC_implementation_P.AnalogFilterDesign1_A[1])*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[1];
      ((StateDerivatives_MPC_AVC_implem *)
        MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE
        [1] = (MPC_AVC_implementation_P.AnalogFilterDesign1_A[2])*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[0];
      ((StateDerivatives_MPC_AVC_implem *)
        MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE
        [2] = (MPC_AVC_implementation_P.AnalogFilterDesign1_A[3])*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[1]
        + (MPC_AVC_implementation_P.AnalogFilterDesign1_A[4])*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[2]
        + (MPC_AVC_implementation_P.AnalogFilterDesign1_A[5])*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[3];
      ((StateDerivatives_MPC_AVC_implem *)
        MPC_AVC_implementation_M->ModelData.derivs)->AnalogFilterDesign1_CSTATE
        [3] = (MPC_AVC_implementation_P.AnalogFilterDesign1_A[6])*
        MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[2];
    }

    /* Derivatives for atomic SubSystem: '<S2>/Kalman Filter' */
    if (rtmIsMajorTimeStep(MPC_AVC_implementation_M) &&
        MPC_AVC_implementation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain Block: '<S7>/B'
       * About '<S7>/B :'
       *   Gain value: B


       */
      {
        static const int_T dims[3] = { 18, 2, 1 };

        rt_MatMultRR_Dbl((real_T *)MPC_AVC_implementation_B.B_i, (real_T *)
                         &MPC_AVC_implementation_P.B_Gain_k[0],
                         (real_T *)MPC_AVC_implementation_B.Gain1, &dims[0]);
      }
    }

    for (i = 0; i < 18; i++) {
      /* Sum: '<S7>/Sum' */
      MPC_AVC_implementation_B.Sum_l[i] = (MPC_AVC_implementation_B.B_i[i] +
        MPC_AVC_implementation_B.Product_l[i]) + MPC_AVC_implementation_B.A[i];
    }

    /* Derivatives for Integrator: '<S7>/Integrator' incorporates:
     *  Constant: '<S7>/Constant'
     */
    ((StateDerivatives_MPC_AVC_implem *)
      MPC_AVC_implementation_M->ModelData.derivs)->Integrator_CSTATE =
      MPC_AVC_implementation_P.Constant_Value;

    /* end of Derivatives for SubSystem: '<S2>/Kalman Filter' */
  }
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

  rtmSetTFinal(MPC_AVC_implementation_M, 2.4990000000000002E+001);
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
    for (i = 0; i < 217; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&MPC_AVC_implementation_B.Delay_d[0]);
    for (i = 0; i < 152; i++) {
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
      &MPC_AVC_implementation_DWork.UnitDelay16_DSTATE[0];
    for (i = 0; i < 58; i++) {
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
  MPC_AVC_implementation_M->Sizes.numContStates = (5);/* Number of continuous states */
  MPC_AVC_implementation_M->Sizes.numY = (0);/* Number of model outputs */
  MPC_AVC_implementation_M->Sizes.numU = (0);/* Number of model inputs */
  MPC_AVC_implementation_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  MPC_AVC_implementation_M->Sizes.numSampTimes = (2);/* Number of sample times */
  MPC_AVC_implementation_M->Sizes.numBlocks = (137);/* Number of blocks */
  MPC_AVC_implementation_M->Sizes.numBlockIO = (107);/* Number of block outputs */
  MPC_AVC_implementation_M->Sizes.numBlockPrms = (450923);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* StateSpace Block: '<Root>/Analog Filter Design1' */
    MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[0] =
      MPC_AVC_implementation_P.AnalogFilterDesign1_X0;
    MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[1] =
      MPC_AVC_implementation_P.AnalogFilterDesign1_X0;
    MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[2] =
      MPC_AVC_implementation_P.AnalogFilterDesign1_X0;
    MPC_AVC_implementation_X.AnalogFilterDesign1_CSTATE[3] =
      MPC_AVC_implementation_P.AnalogFilterDesign1_X0;

    /* InitializeConditions for atomic SubSystem: '<S2>/Kalman Filter' incorporates:
     *  InitializeConditions for UnitDelay: '<S7>/Unit Delay3'
     */
    for (i = 0; i < 18; i++) {
      /* InitializeConditions for UnitDelay: '<S7>/Unit Delay3' */
      MPC_AVC_implementation_DWork.UnitDelay3_DSTATE_j[i] =
        MPC_AVC_implementation_P.UnitDelay3_X0;
    }

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    MPC_AVC_implementation_X.Integrator_CSTATE =
      MPC_AVC_implementation_P.Integrator_IC;

    /* end of InitializeConditions for SubSystem: '<S2>/Kalman Filter' */

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay16' */
    MPC_AVC_implementation_DWork.UnitDelay16_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay16_X0;
    MPC_AVC_implementation_DWork.UnitDelay16_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay16_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay13' */
    MPC_AVC_implementation_DWork.UnitDelay13_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay13_X0;
    MPC_AVC_implementation_DWork.UnitDelay13_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay13_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay14' */
    MPC_AVC_implementation_DWork.UnitDelay14_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay14_X0;
    MPC_AVC_implementation_DWork.UnitDelay14_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay14_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay15' */
    MPC_AVC_implementation_DWork.UnitDelay15_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay15_X0;
    MPC_AVC_implementation_DWork.UnitDelay15_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay15_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay12' */
    MPC_AVC_implementation_DWork.UnitDelay12_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay12_X0;
    MPC_AVC_implementation_DWork.UnitDelay12_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay12_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay9' */
    MPC_AVC_implementation_DWork.UnitDelay9_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay9_X0;
    MPC_AVC_implementation_DWork.UnitDelay9_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay9_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay10' */
    MPC_AVC_implementation_DWork.UnitDelay10_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay10_X0;
    MPC_AVC_implementation_DWork.UnitDelay10_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay10_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay11' */
    MPC_AVC_implementation_DWork.UnitDelay11_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay11_X0;
    MPC_AVC_implementation_DWork.UnitDelay11_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay11_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay7' */
    MPC_AVC_implementation_DWork.UnitDelay7_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay7_X0;
    MPC_AVC_implementation_DWork.UnitDelay7_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay7_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
    MPC_AVC_implementation_DWork.UnitDelay1_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay1_X0;
    MPC_AVC_implementation_DWork.UnitDelay1_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay1_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay2' */
    MPC_AVC_implementation_DWork.UnitDelay2_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay2_X0;
    MPC_AVC_implementation_DWork.UnitDelay2_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay6' */
    MPC_AVC_implementation_DWork.UnitDelay6_DSTATE[0] =
      MPC_AVC_implementation_P.UnitDelay6_X0;
    MPC_AVC_implementation_DWork.UnitDelay6_DSTATE[1] =
      MPC_AVC_implementation_P.UnitDelay6_X0;

    /* Integer/Tapped Delay Block: '<Root>/Delay'
     * Initialize State
     * Initial Condition parameter uses the same data type and scaling as Output0
     */
    {
      int_T i1;
      real_T *dw_X = &MPC_AVC_implementation_DWork.Delay_X[0];
      for (i1=0; i1 < 6; i1++) {
        dw_X[i1] = MPC_AVC_implementation_P.Delay_InitialCondition;
      }
    }

    /* InitializeConditions for atomic SubSystem: '<S2>/Recursive LS_all' */

    /* Integer/Tapped Delay Block: '<S9>/Delay'
     * Initialize State
     * Initial Condition parameter uses the same data type and scaling as Output0
     */
    {
      int_T i1;
      real_T *dw_X = &MPC_AVC_implementation_DWork.Delay_X_e[0];
      for (i1=0; i1 < 6; i1++) {
        dw_X[i1] = MPC_AVC_implementation_P.Delay_InitialCondition_j;
      }
    }

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay4' */
    MPC_AVC_implementation_DWork.UnitDelay4_DSTATE =
      MPC_AVC_implementation_P.UnitDelay4_X0;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay3' */
    MPC_AVC_implementation_DWork.UnitDelay3_DSTATE =
      MPC_AVC_implementation_P.UnitDelay3_X0_o;

    /* end of InitializeConditions for SubSystem: '<S2>/Recursive LS_all' */
  }
}

void MdlStart(void)
{
  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL1 */
  ds2102_out(DS2102_1_BASE, 1, 0);

  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL2 */
  ds2102_out(DS2102_1_BASE, 2, 0);

  /* dSPACE I/O Board DS2102 #1 Unit:DAC Group:CHANNEL3 */
  ds2102_out(DS2102_1_BASE, 3, 0);

  /* SignalGenerator Block: <Root>/Signal Generator (modif. by dSPACE) */
  rti_siggen_init(MPC_AVC_implementation_P.SignalGenerator_Amplitude,
                  MPC_AVC_implementation_P.SignalGenerator_Frequency, 0.001, 1,
                  &RTISigGenPtr.SignalGenerator_1);
  MdlInitialize();

  /* Enable for Sin: '<Root>/Sine Wave' */
  MPC_AVC_implementation_DWork.systemEnable = 1;
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
