#include "particle.h"
#include "vector.h"
#include <stdio.h>
#include "constant.h"

Particle newOriginParticle() {
    Spherical s;
    s.magnitude = 0;
    s.phi = 0;
    s.theta = 0;
    Particle p = {zeroed, zeroed, 1, 1, s};
    return p;
}

float calculateDensity(Particle *p) {
    // assuming that mass and volume are SI
    Particle ip = *p;
    return ip.mass/ip.volume;
}

void RunUpdate(Particle *p) {
    Particle ip = *p;
    // apply forces to change particle's velocity
    // gravity
    
    // acceleration
    // magnetic
    // lift

    // apply velocity
}