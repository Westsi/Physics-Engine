#ifndef SHAPE_H_
#define SHAPE_H_
#include "../vector/vector.h"

typedef struct {
    Vec3 position;
    Vec3 acceleration;
    Vec3 velocity;
    float radius; // radius of sphere
    float dragcoefficient;
    float mass; // kg
    // volume calculated with 4/3*pi*(r^3)
    // cross sectional area calculated with pi*(r^2)
} Sphere;

Sphere newOriginSphere();

float calculateDensity(float mass, float volume);

float calculateTerminalVelocity(float mass, float crossSectionalArea, float dragCoefficient, float fluidDensity);

float calculateDrag(float directionalVelocity, float dragCoefficient, float crossSectionalArea, float fluidDensity);

void printSphere(Sphere *s);

#endif