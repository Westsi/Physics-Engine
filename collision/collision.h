#include "../vector/vector.h"
#include "../coordinate/coordinate.h"
#include "../particle/particle.h"
#include <stdbool.h>

bool areColliding(Particle *a, Particle *b);

void applyCollisionForces(Particle *a, Vec3 forces);