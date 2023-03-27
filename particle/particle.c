#include "particle.h"
#include "vector.h"
#include <stdio.h>

Particle newOriginParticle() {
    Particle p = {zeroed, zeroed};
    return p;
}