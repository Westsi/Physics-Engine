#include<stdio.h>
#include<math.h>
#include "particle.h"
#include "vector.h"
#include "coordinate.h"

int main(int argc, char argv[]) {
    // printf("Hello World!");
    Particle mp;
    mp.position = (Vec3) {0,0,0};
    printf("%f\n", mp.position.x);
    test(&mp);
    printf("%f\n", mp.position.x);
    return 0;
}