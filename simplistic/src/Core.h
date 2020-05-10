#ifndef SIMPLISTIC_SRC_CORE_H_
#define SIMPLISTIC_SRC_CORE_H_

#include "Precision.h"

namespace simplistic {

class Vector3 {
 public:
   Vector3() : x_position_(0), y_position_(0), z_position_(0) {}
   Vector3(const real x, const real y, const real z) 
       : x_position_(x), y_position_(y), z_position_(z) {} 

   /** Return the magnitude of the vector. */
   real Magnitude() const;

   /** Return the square of the magnitude. */
   real SquareMagnitude() const;

   /** Return a new normalized vector of unit length */
   Vector3 Normalize();

   /** Invert the vector */
   inline void Invert() {
     x_position_ = -x_position_;
     y_position_ = -y_position_;
     z_position_ = -z_position_;
   }

   /** Add another vector to the current one in place. */
  inline void operator+=(const Vector3& vector) {
     x_position_ += vector.x_position_;
     y_position_ += vector.y_position_;
     z_position_ += vector.z_position_;
  }

  /** Add another vector to a copy of the of the current one. */
  inline Vector3 operator+(const Vector3& vector) {
    return Vector3(
        x_position_ + vector.x_position_,
        y_position_ + vector.y_position_,
        z_position_ + z_position_);
  }

   /** Multiply the vector by a scalar in place. */
   inline void operator*=(const real value) {
     x_position_ *= value;
     y_position_ *= value;
     z_position_ *= value;
   }

   /** Multiply the current vector by a scalar and return a new one */
   inline Vector3 operator*(const real value) const {
     return Vector3(
         x_position_ * value, y_position_ * value, z_position_ * value);
   }
 private:
   real x_position_, y_position_, z_position_;
   real pad_;
};

}  // namespace simplistic


#endif  // SIMPLISTIC_SRC_CORE_H_
