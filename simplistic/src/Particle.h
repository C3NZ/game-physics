#ifndef SIMPLISTIC_SRC_PARTICLE_H_
#define SIMPLISTIC_SRC_PARTICLE_H_

#include <assert.h>

#include "Core.h"
#include "Precision.h"

namespace simplistic {

class Particle {
 public:
  inline Vector3 GetPosition() const { return position_; }
  inline void GetPosition(Vector3* position) const { *position = position_; }
  inline void SetPosition(Vector3 position) { position_ = position; }
  inline void SetPosition(const real x, const real y, const real z) {
    position_.SetX(x);
    position_.SetY(y);
    position_.SetZ(z);
  }

  inline Vector3 GetVelocity() const { return velocity_; }
  inline void GetVelocity(Vector3* velocity) const { *velocity = velocity_; }
  inline void SetVelocity(Vector3 velocity) { velocity_ = velocity; }
  inline void SetVelocity(const real x, const real y, const real z) {
    velocity_.SetX(x);
    velocity_.SetY(y);
    velocity_.SetZ(z);
  }

  inline Vector3 GetAcceleration() const { return acceleration_; }
  inline void GetAcceleration(Vector3* acceleration) const 
      { *acceleration = acceleration_; }
  inline void SetAcceleration(Vector3 acceleration) 
      { acceleration_ = acceleration; }
  inline void SetAcceleration(const real x, const real y, const real z) {
    acceleration_.SetX(x);
    acceleration_.SetY(y);
    acceleration_.SetZ(z);
  }

  inline real GetMass() const {
    if (inverse_mass_ == 0){
      return REAL_MAX;
    } else {
      return inverse_mass_;
    }
  }

  inline void SetMass(const real mass) {
    assert(mass != 0);
    inverse_mass_= static_cast<real>(1.0 / mass);
  }

  inline real GetInverseMass() const { return inverse_mass_; }
  inline void SetInverseMass(const real inverse_mass) 
      { inverse_mass_ = inverse_mass; }

  inline real GetDamping() const { return damping_; }
  inline void SetDamping(const real damping) { damping_ = damping; }

  inline bool HasFiniteMass() const { return inverse_mass_ >= 0.0f; }

  inline void AddForce(const Vector3& force) { force_accumulator_ += force; }
  inline void ClearAccumulator() { force_accumulator_.Clear(); }

  /**
   * Simulate the particles motion over time using the Newton-Euler integration
   * method.
   */
  void Integrate(const real duration) {
    assert(duration > 0.0);
    position_.AddScaledVector(velocity_, duration);

    // Work out acceleration from the force.
    Vector3 resulting_acceleration = acceleration_;
    resulting_acceleration.AddScaledVector(
        force_accumulator_, inverse_mass_);

    // Apply acceleration with damping.
    velocity_.AddScaledVector(resulting_acceleration, duration);

    // Apply damping/drag.
    velocity_ *= REAL_POW(damping_, duration);

    ClearAccumulator();    
  }

  void IntegrateWithAcceleration(const real duration) {
  }

 private:
  Vector3 position_;
  Vector3 velocity_;
  Vector3 acceleration_;
  Vector3 force_accumulator_;

  /**
   * Holds the amount of damping applied to linear motion. Damping is required
   * to remove energy added through numerical instability in the integrator.
   */
  real damping_;

  /** 
   * Holds the inverse of the mass of the particle. It is more useful to hold
   * the inverse mass because integration is simpler and because in real-time
   * simulation it is more useful to hve objects with infinite mass (immovable)
   * than zero mass (completely unstable in numerical simulation).
   */
  real inverse_mass_;
};

}  // namespace simplistic
#endif  // SIMPLISTIC_SRC_CORE_H_
