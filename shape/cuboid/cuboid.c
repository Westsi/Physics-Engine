#include "cuboid.h"
#include <stdio.h>
#include "../../constant/constant.h"

Cuboid newOriginCuboid() {
    return (Cuboid) {};
}

void printCuboid(Cuboid *c) {
    Cuboid ic = *c;

    // printf("Position: (%f, %f, %f)\nVelocity: (%f, %f, %f)\nAcceleration: (%f, %f, %f)\n", is.position.x, is.position.y, is.position.z, is.velocity.x, is.velocity.y, is.velocity.z, is.acceleration.x, is.acceleration.y, is.acceleration.z);
    // printf("\nConstants:\nRadius: %f\nCross-sectional Area: %f\nMass: %f\n\n", is.radius, is.dragcoefficient, is.mass);
}