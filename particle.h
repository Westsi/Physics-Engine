#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "vector.h"
#include "coordinate.h"

typedef struct {
    Vec3 position;
    Vec3 acceleration;
    float mass;
    float volume; // density can be calculated with m/v
    Spherical velocity; // i have no idea what this entire block is doing but i hope it works :|
} Particle;

Particle newOriginParticle();

void RunUpdate(Particle *p);

#endif