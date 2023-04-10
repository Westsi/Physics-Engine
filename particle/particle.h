#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "../coordinate/coordinate.h"
#include "../vector/vector.h"
#include "../shape/shape.h"
#include "../shape/sphere/sphere.h"

typedef Sphere Particle;

Particle newOriginParticle();

void RunUpdate(Particle *p);

void printParticle(Particle *p);

#endif