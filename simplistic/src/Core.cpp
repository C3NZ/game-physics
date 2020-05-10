#include "Core.h"

#include "Precision.h"

namespace simplistic {

real Vector3::Magnitude() const {
  return real_sqrt(
      x_position_ * x_position_ +
      y_position_ * y_position_ + 
      z_position_ * z_position_);
}

real Vector3::SquareMagnitude() const {
  return x_position_ * x_position_ +
      y_position_ * y_position_ + 
      z_position_ * z_position_;
}

Vector3 Vector3::Normalize() {
  real length = Magnitude();
  if (length > 0) {
    return (*this) * (static_cast<real>(1) / length);
  }

  return *this;
}

}  // namespace simplistic
