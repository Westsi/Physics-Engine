#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "coordinate.h"

typedef struct {
    Cartesian position;
    Cartesian acceleration;
    float mass;
    float volume; // density can be calculated with m/v
    Spherical velocity; // i have no idea what this entire block is doing but i hope it works :|
} Particle;

Particle newOriginParticle();

void RunUpdate(Particle *p);

#endif