#include<stdio.h>
#include<math.h>
#include "constant/constant.h"
#include "particle/particle.h"
#include "vector/vector.h"
#include "coordinate/coordinate.h"

int main(int argc, char argv[]) {
    // printf("Hello World!");

    Particle p = newOriginParticle();
    printParticle(&p);
    printf("%f\n", calculateTerminalVelocity(p.mass, PI*p.radius*p.radius, p.dragcoefficient, AIR_DENSITY));
    // p.velocity.y = -10;

    for (int x = 0; x < 10001; x++) {
        RunUpdate(&p);
    }

    printParticle(&p);

    return 0;
}