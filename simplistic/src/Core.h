#ifndef SIMPLISTIC_SRC_CORE_H_
#define SIMPLISTIC_SRC_CORE_H_

#include "simplistic/src/Precision.h"

namespace simplistic {

class Vector3 {
 public:
   real x_position_, y_position_, z_position_;
   Vector3() : x_position_(0), y_position_(0), z_position_(0) {}
   Vector3(const real x, const real y, const real z) 
       : x_position_(x), y_position_(y), z_position_(z) {} 

   inline void Invert() {
    x_position_ = -x_position_;
    y_position_ = -y_position_;
    z_position_ = -z_position_;
   }
 private:
   real pad_;
};

}  // namespace simplistic


#endif  // SIMPLISTIC_SRC_CORE_H_
