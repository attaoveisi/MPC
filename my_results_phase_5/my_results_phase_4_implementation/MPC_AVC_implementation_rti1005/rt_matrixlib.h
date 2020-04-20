#ifndef rt_matrixlib_h
#define rt_matrixlib_h

/* Copyright 2007 The MathWorks, Inc.
 *
 * File    : rt_matrixlib.h
 * Abstract:
 *     Function prototypes for .c sources in rtw/c/src/matrixmath.
 *
 */

/* $Revision: 1.1.6.1 $ */

/*==========*
 * Includes *
 *==========*/
#include "rtwtypes.h"
#include <limits.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Matrix Multiplication Utility Functions */
  extern void rt_MatMultRR_Dbl(real_T *y,
    const real_T *A,
    const real_T *B,
    const int_T dims[3]);

#ifdef CREAL_T

  extern void rt_MatMultRC_Dbl(creal_T *y,
    const real_T *A,
    const creal_T *B,
    const int_T dims[3]);
  extern void rt_MatMultCR_Dbl(creal_T *y,
    const creal_T *A,
    const real_T *B,
    const int_T dims[3]);
  extern void rt_MatMultCC_Dbl(creal_T *y,
    const creal_T *A,
    const creal_T *B,
    const int_T dims[3]);

#endif

  extern void rt_MatMultRR_Sgl(real32_T *y,
    const real32_T *A,
    const real32_T *B,
    const int_T dims[3]);

#ifdef CREAL_T

  extern void rt_MatMultRC_Sgl(creal32_T *y,
    const real32_T *A,
    const creal32_T *B,
    const int_T dims[3]);
  extern void rt_MatMultCR_Sgl(creal32_T *y,
    const creal32_T *A,
    const real32_T *B,
    const int_T dims[3]);
  extern void rt_MatMultCC_Sgl(creal32_T *y,
    const creal32_T *A,
    const creal32_T *B,
    const int_T dims[3]);

#endif

  extern void rt_MatMultAndIncRR_Dbl(real_T *y,
    const real_T *A,
    const real_T *B,
    const int_T dims[3]);

#ifdef CREAL_T

  extern void rt_MatMultAndIncRC_Dbl(creal_T *y,
    const real_T *A,
    const creal_T *B,
    const int_T dims[3]);
  extern void rt_MatMultAndIncCR_Dbl(creal_T *y,
    const creal_T *A,
    const real_T *B,
    const int_T dims[3]);
  extern void rt_MatMultAndIncCC_Dbl(creal_T *y,
    const creal_T *A,
    const creal_T *B,
    const int_T dims[3]);

#endif

  extern void rt_MatMultAndIncRR_Sgl(real32_T *y,
    const real32_T *A,
    const real32_T *B,
    const int_T dims[3]);

#ifdef CREAL_T

  extern void rt_MatMultAndIncRC_Sgl(creal32_T *y,
    const real32_T *A,
    const creal32_T *B,
    const int_T dims[3]);
  extern void rt_MatMultAndIncCR_Sgl(creal32_T *y,
    const creal32_T *A,
    const real32_T *B,
    const int_T dims[3]);
  extern void rt_MatMultAndIncCC_Sgl(creal32_T *y,
    const creal32_T *A,
    const creal32_T *B,
    const int_T dims[3]);

#endif

  /* Matrix Inversion Utility Functions */
  extern void rt_lu_real(real_T *A,
    const int_T n,
    int32_T *piv);

#ifdef CREAL_T

  extern void rt_lu_cplx(creal_T *A,
    const int_T n,
    int32_T *piv);

#endif

  extern void rt_lu_real_sgl(real32_T *A,
    const int_T n,
    int32_T *piv);

#ifdef CREAL_T

  extern void rt_lu_cplx_sgl(creal32_T *A,
    const int_T n,
    int32_T *piv);

#endif

  extern void rt_BackwardSubstitutionRR_Dbl(real_T *pU,
    const real_T *pb,
    real_T *x,
    int_T N,
    int_T P,
    boolean_T unit_upper);

#ifdef CREAL_T

  extern void rt_BackwardSubstitutionRC_Dbl(real_T *pU,
    const creal_T *pb,
    creal_T *x,
    int_T N,
    int_T P,
    boolean_T unit_upper);
  extern void rt_BackwardSubstitutionCC_Dbl(creal_T *pU,
    const creal_T *pb,
    creal_T *x,
    int_T N,
    int_T P,
    boolean_T unit_upper);

#endif

  extern void rt_ForwardSubstitutionRR_Dbl(real_T *pL,
    const real_T *pb,
    real_T *x,
    int_T N,
    int_T P,
    const int32_T *piv,
    boolean_T unit_lower);

#ifdef CREAL_T

  extern void rt_ForwardSubstitutionRC_Dbl(real_T *pL,
    const creal_T *pb,
    creal_T *x,
    int_T N,
    int_T P,
    const int32_T *piv,
    boolean_T unit_lower);
  extern void rt_ForwardSubstitutionCR_Dbl(creal_T *pL,
    const real_T *pb,
    creal_T *x,
    int_T N,
    int_T P,
    const int32_T *piv,
    boolean_T unit_lower);
  extern void rt_ForwardSubstitutionCC_Dbl(creal_T *pL,
    const creal_T *pb,
    creal_T *x,
    int_T N,
    int_T P,
    const int32_T *piv,
    boolean_T unit_lower);

#endif

  extern void rt_BackwardSubstitutionRR_Sgl(real32_T *pU,
    const real32_T *pb,
    real32_T *x,
    int_T N,
    int_T P,
    boolean_T unit_upper);

#ifdef CREAL_T

  extern void rt_BackwardSubstitutionRC_Sgl(real32_T *pU,
    const creal32_T *pb,
    creal32_T *x,
    int_T N,
    int_T P,
    boolean_T unit_upper);
  extern void rt_BackwardSubstitutionCC_Sgl(creal32_T *pU,
    const creal32_T *pb,
    creal32_T *x,
    int_T N,
    int_T P,
    boolean_T unit_upper);

#endif

  extern void rt_ForwardSubstitutionRR_Sgl(real32_T *pL,
    const real32_T *pb,
    real32_T *x,
    int_T N,
    int_T P,
    const int32_T *piv,
    boolean_T unit_lower);

#ifdef CREAL_T

  extern void rt_ForwardSubstitutionRC_Sgl(real32_T *pL,
    const creal32_T *pb,
    creal32_T *x,
    int_T N,
    int_T P,
    const int32_T *piv,
    boolean_T unit_lower);
  extern void rt_ForwardSubstitutionCR_Sgl(creal32_T *pL,
    const real32_T *pb,
    creal32_T *x,
    int_T N,
    int_T P,
    const int32_T *piv,
    boolean_T unit_lower);
  extern void rt_ForwardSubstitutionCC_Sgl(creal32_T *pL,
    const creal32_T *pb,
    creal32_T *x,
    int_T N,
    int_T P,
    const int32_T *piv,
    boolean_T unit_lower);

#endif

  extern void rt_MatDivRR_Dbl(real_T *Out,
    const real_T *In1,
    const real_T *In2,
    real_T *lu,
    int32_T *piv,
    real_T *x,
    const int_T dims[3]);

#ifdef CREAL_T

  extern void rt_MatDivRC_Dbl(creal_T *Out,
    const real_T *In1,
    const creal_T *In2,
    real_T *lu,
    int32_T *piv,
    creal_T *x,
    const int_T dims[3]);
  extern void rt_MatDivCR_Dbl(creal_T *Out,
    const creal_T *In1,
    const real_T *In2,
    creal_T *lu,
    int32_T *piv,
    creal_T *x,
    const int_T dims[3]);
  extern void rt_MatDivCC_Dbl(creal_T *Out,
    const creal_T *In1,
    const creal_T *In2,
    creal_T *lu,
    int32_T *piv,
    creal_T *x,
    const int_T dims[3]);

#endif

  extern void rt_MatDivRR_Sgl(real32_T *Out,
    const real32_T *In1,
    const real32_T *In2,
    real32_T *lu,
    int32_T *piv,
    real32_T *x,
    const int_T dims[3]);

#ifdef CREAL_T

  extern void rt_MatDivRC_Sgl(creal32_T *Out,
    const real32_T *In1,
    const creal32_T *In2,
    real32_T *lu,
    int32_T *piv,
    creal32_T *x,
    const int_T dims[3]);
  extern void rt_MatDivCR_Sgl(creal32_T *Out,
    const creal32_T *In1,
    const real32_T *In2,
    creal32_T *lu,
    int32_T *piv,
    creal32_T *x,
    const int_T dims[3]);
  extern void rt_MatDivCC_Sgl(creal32_T *Out,
    const creal32_T *In1,
    const creal32_T *In2,
    creal32_T *lu,
    int32_T *piv,
    creal32_T *x,
    const int_T dims[3]);

#endif

  /* Matrix multiplication defines */
#ifndef CMULT_RE
#define CMULT_RE(X,Y)                  ( (X).re * (Y).re - (X).im * (Y).im)
#define CMULT_IM(X,Y)                  ( (X).re * (Y).im + (X).im * (Y).re)
#endif

#define CMULT_XCONJ_RE(X,Y)            ( (X).re * (Y).re + (X).im * (Y).im)
#define CMULT_XCONJ_IM(X,Y)            ( (X).re * (Y).im - (X).im * (Y).re)
#define CMULT_YCONJ_RE(X,Y)            ( (X).re * (Y).re + (X).im * (Y).im)
#define CMULT_YCONJ_IM(X,Y)            (-(X).re * (Y).im + (X).im * (Y).re)
#define CMULT_XYCONJ_RE(X,Y)           ( (X).re * (Y).re - (X).im * (Y).im)
#define CMULT_XYCONJ_IM(X,Y)           (-(X).re * (Y).im - (X).im * (Y).re)

  /* Complex conjugate: */
#define CCONJ(X,Y)                     { (Y).re = (X).re; (Y).im = -((X).im); }

  /* Complex magnitude squared ( X * conj(X), or |X|^2 ) */
#define CMAGSQ(X)                      ((X).re * (X).re + (X).im * (X).im)

  /* Quick (approximate) complex absolute value: */
#define CQABS(X)                       (fabs((X).re) + fabs((X).im))

  /* Quick (approximate) complex absolute value for singles: */
#define CQABSSGL(X)                    (real32_T)(fabs( (real_T) (X).re) + fabs( (real_T) (X).im))
#ifdef CREAL_T

  /* Complex reciprocal: C = 1 / B  (A=1) */
#define CRECIP(B,C)                    { const real_T _s = 1.0 / CQABS(B); real_T _d; creal_T _bs; _bs.re = (B).re * _s; _bs.im = (B).im * _s; _d = 1.0 / CMAGSQ(_bs); (C).re = ( _s * _bs.re) * _d; (C).im = (-_s * _bs.im) * _d; }

  /* Complex reciprocal: C = 1 / B  (A=1) */
#define CRECIPSGL(B,C)                 { const real32_T _s = 1.0F / CQABSSGL(B); real32_T _d; creal32_T _bs; _bs.re = (B).re * _s; _bs.im = (B).im * _s; _d = 1.0F / CMAGSQ(_bs); (C).re = ( _s * _bs.re) * _d; (C).im = (-_s * _bs.im) * _d; }

  /* Complex division: C = A / B for singles */
#define CDIV(A,B,C)                    { if ((B).im == 0.0) { (C).re = (A).re / (B).re; (C).im = (A).im / (B).re; } else { const real_T _s = 1.0 / CQABS(B); real_T _d; creal_T _as, _bs; _as.re = (A).re * _s; _as.im = (A).im * _s; _bs.re = (B).re * _s; _bs.im = (B).im * _s; _d = 1.0 / CMAGSQ(_bs); (C).re = CMULT_YCONJ_RE(_as, _bs) * _d; (C).im = CMULT_YCONJ_IM(_as, _bs) * _d; } }

  /* Complex division: C = A / B for singles*/
#define CDIVSGL(A,B,C)                 { if ((B).im == 0.0F) { (C).re = (A).re / (B).re; (C).im = (A).im / (B).re; } else { const real32_T _s = 1.0F / CQABSSGL(B); real32_T _d; creal32_T _as, _bs; _as.re = (A).re * _s; _as.im = (A).im * _s; _bs.re = (B).re * _s; _bs.im = (B).im * _s; _d = 1.0F / CMAGSQ(_bs); (C).re = CMULT_YCONJ_RE(_as, _bs) * _d; (C).im = CMULT_YCONJ_IM(_as, _bs) * _d; } }
#endif

  /* Hypotenuse: c = sqrt(a^2 + b^2) */
#define CHYPOT(A,B,C)                  { if (fabs(A) > fabs(B)) { real_T _tmp = (B)/(A); (C) = (fabs(A)*sqrt(1+_tmp*_tmp)); } else { if ((B) == 0.0) { (C) = 0.0; } else { real_T _tmp = (A)/(B); (C) = (fabs(B)*sqrt(1+_tmp*_tmp)); } } }

  /* Complex modulus: Y = abs(X) */
#define CABS(X,Y)                      CHYPOT((X).re, (X).im, (Y))
#ifdef __cplusplus

}
#endif
#endif                                 /* rt_matrixlib_h */
