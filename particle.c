#include "particle.h"
#include "vector.h"
#include <stdio.h>
#include "constant.h"

Particle newOriginParticle() {
    Particle p = (Particle) {zeroed, zeroed, 1, 1, zeroed};
    return p;
}

float calculateDensity(Particle *p) {
    // assuming that mass and volume are SI
    Particle ip = *p;
    return ip.mass/ip.volume;
}

void RunUpdate(Particle *p) {
    Particle ip = *p;

    // apply forces to change particle's acceleration
    // gravity
    Vec2 forceDueToGravity = (Vec2) {0, ip.mass * EARTHGRAVITY};

    // apply acceleration to velocity

    // move particle by velocity
}

void test(Particle *p) {
    p->position = (Vec3) {10,10,10};
}