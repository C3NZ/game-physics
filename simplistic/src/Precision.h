#ifndef SIMPLISTIC_SRC_PRECISION_H_
#define SIMPLISTIC_SRC_PRECISION_H_

#include <float.h>
#include <math.h>

namespace simplistic {

// Default to single precision accuracy if no accuracy is defined.
#if !(defined(SIMPLISTIC_SINGLE_PRECISION) && \
    defined(SIMPLISTIC_DOUBLE_PRECISION))
  #define SIMPLISTIC_SINGLE_PRECISION
#endif

#ifdef SIMPLISTIC_SINGLE_PRECISION
  typedef float real;

  #define REAL_MAX FLT_MAX
  #define REAL_EPSILON FLT_EPSILON
  #define REAL_PI 3.14159f

  #define REAL_SQRT sqrtf
  #define REAL_ABS fabsf
  #define REAL_SIN sinf
  #define REAL_COS cosf
  #define REAL_EXP expf
  #define REAL_POW powf
  #define REAL_FMOD fmodf
#elif defined(SIMPLISTIC_DOUBLE_PRECISION)
  typedef double real;

  #define REAL_MAX DBL_MAX
  #define REAL_EPSILON DBL_EPSILON
  #define REAL_PI 3.14159265358979

  #define REAL_SQRT sqrt
  #define REAL_ABS fabs
  #define REAL_SIN sin
  #define REAL_COS cos
  #define REAL_EXP exp
  #define REAL_POW pow
  #define REAL_FMOD fmod
#endif

}  // namespace simplistic


#endif  // SIMPLISTIC_SRC_PRECISION_H_
