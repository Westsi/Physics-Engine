#include<stdio.h>
#include<math.h>
#include "constant.h"
#include "particle.h"
#include "vector.h"
#include "coordinate.h"

int main(int argc, char argv[]) {
    // printf("Hello World!");

    Particle p = newOriginParticle();
    // printf("%f", calculateTerminalVelocity(&p, AIR_DENSITY));
    // p.velocity.y = -10;

    for (int x = 0; x < 10001; x++) {
        RunUpdate(&p);
    }

    printParticle(&p);

    return 0;
}