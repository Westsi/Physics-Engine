#ifndef SPHERE_H_
#define SPHERE_H_
#include "../../vector/vector.h"

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

void printSphere(Sphere *s);

#endif