#include "particle.h"
#include "../vector/vector.h"
#include <stdio.h>
#include "../constant.h"

Particle newOriginParticle() {
    Particle p = {zeroed, zeroed, 1};
    return p;
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