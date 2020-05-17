#include "Core.h"

#include "Precision.h"

namespace simplistic {

/**
 * TODO(C3NZ): Investigate into whether or not these values should be allowed to
 * be modified externally in the future.
 */
const Vector3 Vector3::GRAVITY = Vector3(0, -9.81, 0); 
const Vector3 HIGH_GRAVITY = Vector3(0, -19.62, 0);
const Vector3 UP = Vector3(0, 1, 0);
const Vector3 RIGHT = Vector3(1, 0, 0);
const Vector3 OUT_OF_SCREEN = Vector3(0, 0, 1);
const Vector3 X = Vector3(0, 1, 0);
const Vector3 Y = Vector3(1, 0, 0);
const Vector3 Z = Vector3(0, 0, 1);

}  // namespace simplistic
