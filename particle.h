#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "coordinate.h"

typedef struct {
    Cartesian position;
    Cartesian acceleration;
    float mass;
    float volume;
    Spherical velocity;
} Particle;  // i have no idea what this entire block is doing but i hope it works :|

Particle newOriginParticle();

Particle newParticle(); // add to this

float calculateDensity(Particle *p);


void RunUpdate(Particle *p);

#endif