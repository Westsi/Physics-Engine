#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "coordinate.h"

typedef struct {
    Vec3 position;
    Vec3 acceleration;
    float mass; // kg
    float volume;
    Vec3 velocity;
    float crosssectarea;
    float dragcoefficient;
} Particle;

Particle newOriginParticle();

// Particle newParticle(); // add to this

float calculateDensity(Particle *p);


void RunUpdate(Particle *p);

float calculateTerminalVelocity(Particle *p, float fluid_density);

float calculateDrag(Particle *p, float fluid_density, char xyz);

void printParticle(Particle *p);

#endif