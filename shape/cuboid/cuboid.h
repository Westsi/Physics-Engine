#ifndef CUBOID_H_
#define CUBOID_H_
#include "../../vector/vector.h"

typedef struct {
    Vec3 cornerposition; // the position of the top left corner of the shape
    float xchange; // the difference between the x values of cornerposition and its opposite
    float ychange; // the difference between the y values of cornerposition and its opposite
    float zchange; // the difference between the z values of cornerposition and its opposite
    Vec3 acceleration;
    Vec3 velocity;
    float dragcoefficient;
    float mass; // kg
    // volume calculated with 
    // cross sectional area calculated with 
} Cuboid;

Cuboid newOriginCuboid();

Vec3 calculateOppositeCorner(Cuboid *c);

void printCuboid(Cuboid *c);

#endif