#ifndef SIMPLISTIC_SRC_PARTICLE_H_
#define SIMPLISTIC_SRC_PARTICLE_H_

#include "Core.h"
#include "Precision.h"

namespace simplistic {

class Particle {
 public:
  inline void SetPosition(Vector3 position) { position_ = position; }
  inline Vector3 GetPosition() const { return position_; }

  inline void SetVelocity(Vector3 velocity) { velocity_ = velocity; }
  inline Vector3 GetVelocity() const { return velocity_; }

  inline void SetAcceleration(Vector3 acceleration) 
      { acceleration_ = acceleration; }
  inline Vector3 GetAcceleration() const { return acceleration_; }

 private:
  Vector3 position_;
  Vector3 velocity_;
  Vector3 acceleration_;

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
