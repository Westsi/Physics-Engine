#include "particle.h"
#include "vector.h"
#include <stdio.h>
#include "constant.h"

Particle newOriginParticle() {
    Particle p = (Particle) {zeroed, zeroed, 1, 1, zeroed, PI, DRAG_COEFFICIENT_SPHERE};
    return p;
}

float calculateDensity(Particle *p) {
    // assuming that mass and volume are SI
    Particle ip = *p;
    return ip.mass/ip.volume;
}

void RunUpdate(Particle *p) {
    Particle ip = *p;   // REMEMBER! This only allows you to read from struct and update values IN THIS SCOPE
                        // To update globally do p->_attribute_ = ...

    calculateTerminalVelocity(p, AIR_DENSITY);

    // apply forces to change particle's acceleration
    // gravity
    Vec2 forceDueToGravity = (Vec2) {0, ip.mass * EARTH_GRAVITY};

    // calculate acceleration by adding all the vectors

    // apply acceleration to velocity

    // move particle by velocity
}

float calculateTerminalVelocity(Particle *p, float fluid_density) {
    /*
    Returns in m/s
    Formula is sqrt((2mass*gravity)/(density of fluid (generally air) * cross-sectional area of object * drag coefficient))
    Units are:
        mass kg
        gravity m/s-2
        density of fluid kg/m-3
        area m-2
        drag coefficient n/a
    */


    Particle ip = *p;

    float numerator = 2 * ip.mass * fabs(EARTH_GRAVITY);
    float denominator = fluid_density * ip.crosssectarea * ip.dragcoefficient;

    return sqrt(numerator/denominator);
}