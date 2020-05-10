#ifndef SIMPLISTIC_SRC_PRECISION_H_
#define SIMPLISTIC_SRC_PRECISION_H_

#include <math.h>

namespace simplistic {

/**
 * Defines a real number precision. Simplistic can be compiled in single-
 * or doubleprecision versions. By default single precision is provided.
 */
typedef float real;

/** Defines the precision of the square root operator. */
#define real_sqrt sqrtf

}  // namespace simplistic


#endif  // SIMPLISTIC_SRC_PRECISION_H_
