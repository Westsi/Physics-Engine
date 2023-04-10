#include "cuboid.h"
#include <stdio.h>
#include "../../constant/constant.h"
#include "../../vector/vector.h"

Cuboid newOriginCuboid() {
    // using DRAG_COEFFICIENT_SQUARE here is stupid because the shape could have a non square face in the direction that drag is being calculated for
    // but I can't see any clear fixes.
    // HOW?!?!?!
    return (Cuboid) {zeroed, 1, 1, 1, zeroed, zeroed, DRAG_COEFFICIENT_SQUARE, 1};
}

Vec3 calculateOppositeCorner(Cuboid *c) {
    Vec3 tlc = c->cornerposition;
    Vec3 brc = (Vec3) {tlc.x + c->xchange, tlc.y + c->ychange, tlc.z + c->zchange};
    return brc;
}

void printCuboid(Cuboid *c) {
    Cuboid ic = *c;

    // printf("Position: (%f, %f, %f)\nVelocity: (%f, %f, %f)\nAcceleration: (%f, %f, %f)\n", is.position.x, is.position.y, is.position.z, is.velocity.x, is.velocity.y, is.velocity.z, is.acceleration.x, is.acceleration.y, is.acceleration.z);
    // printf("\nConstants:\nRadius: %f\nCross-sectional Area: %f\nMass: %f\n\n", is.radius, is.dragcoefficient, is.mass);
}