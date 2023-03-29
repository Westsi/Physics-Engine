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

    // calculateTerminalVelocity(p, AIR_DENSITY);

    Vec3 change = zeroed;

    // apply forces to change particle's acceleration
    // gravity
    change.y += EARTH_GRAVITY;

    // air resistance
    change.x += calculateDrag(p, AIR_DENSITY, 'x') / ip.mass;
    change.y += calculateDrag(p, AIR_DENSITY, 'y') / ip.mass;
    change.z += calculateDrag(p, AIR_DENSITY, 'z') / ip.mass;

    printVec(change);

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

// Returns NEWTONS - FORCE!!
float calculateDrag(Particle *p, float fluid_density, char xyz) {
    /*
    Returns in N
    Formula is 0.5 * fluid density * relative speed between obj and fluid (normally just speed of obj, but watch out!) SQUARED * drag coefficient * cross sectional area
    Units are:
        relative speed m/s
        density of fluid kg/m-3
        area m-2
        drag coefficient n/a
    */

    Particle ip = *p;

    // ip.velocity.y might not work - check if bug occurs
    float res;
    switch (xyz)
    {
    case 'x':
        res = (0.5 * fluid_density * ip.velocity.x * ip.velocity.x * ip.dragcoefficient * ip.crosssectarea);
        break;
    
    case 'y':
        res = (0.5 * fluid_density * ip.velocity.y * ip.velocity.y * ip.dragcoefficient * ip.crosssectarea);
        break;
    
    case 'z':
        res = (0.5 * fluid_density * ip.velocity.z * ip.velocity.z * ip.dragcoefficient * ip.crosssectarea);
        break;
    
    default:
        break;
    }
    return res;
}