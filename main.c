#include<stdio.h>
#include<math.h>
#include "constant.h"
#include "particle.h"
#include "vector.h"
#include "coordinate.h"

int main(int argc, char argv[]) {
    // printf("Hello World!");

    Particle p = newOriginParticle();
    p.velocity.y = calculateTerminalVelocity(&p, AIR_DENSITY);

    RunUpdate(&p);


    return 0;
}