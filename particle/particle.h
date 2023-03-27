#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "../vector/vector.h"

typedef struct {
    Vec3 position;
    Vec3 acceleration;
    int mass;
    
} Particle;

Particle newOriginParticle();

#endif