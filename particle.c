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
    // in general Δt for this func should be 1, if not change


    Particle ip = *p;   // REMEMBER! This only allows you to read from struct and update values IN THIS SCOPE
                        // To update globally do p->_attribute_ = ...

    // calculateTerminalVelocity(p, AIR_DENSITY);

    Vec3 change = zeroed;

    // apply forces to change particle's acceleration
    change.x += calculateDrag(p, AIR_DENSITY, 'x') / ip.mass;
    change.z += calculateDrag(p, AIR_DENSITY, 'z') / ip.mass;

    change.y = ((ip.mass * EARTH_GRAVITY) + calculateDrag(p, AIR_DENSITY, 'y'))/ip.mass;

    printVec(change);


    // set acceleration to change
    p->acceleration = change;

    // update velocity by acceleration
    // a*Δt=Δv
    // because Δt = 1 here
    p->velocity = add(ip.velocity, change);

    // move particle by velocity
    p->position = add(p->velocity, p->position);
    

    printParticle(p);
}

// Negative result
float calculateTerminalVelocity(Particle *p, float fluid_density) {
    /*
    Returns in m/s. NEGATIVE result because terminal velocity is generally down.
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

    return -(sqrt(numerator/denominator));
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
    float res;
    float vel;
    switch (xyz)
    {
    case 'x':
        res = (0.5 * fluid_density * ip.velocity.x * ip.velocity.x * ip.dragcoefficient * ip.crosssectarea);
        vel = ip.velocity.x;
        break;
    
    case 'y':
        res = ((0.5 * fluid_density * ip.velocity.y * ip.velocity.y) * ip.dragcoefficient * ip.crosssectarea);
        vel = ip.velocity.y;
        break;
    
    case 'z':
        res = ((0.5 * fluid_density * ip.velocity.z * ip.velocity.z) * ip.dragcoefficient * ip.crosssectarea);
        vel = ip.velocity.z;
        break;
    
    default:
        break;
    }
    printf("Res %c: %f\n", xyz, res);
    printf("Inputs: constant rho, Cd, csa. Velocity = %f\n", vel);
    return res;
}

void printParticle(Particle *p) {
    Particle ip = *p;

    printf("Position: (%f, %f, %f)\nVelocity: (%f, %f, %f)\nAcceleration: (%f, %f, %f)\n", ip.position.x, ip.position.y, ip.position.z, ip.velocity.x, ip.velocity.y, ip.velocity.z, ip.acceleration.x, ip.acceleration.y, ip.acceleration.z);
    // printf("Drag Coefficient: %f\nCross-sectional Area: %f\nMass: %f\nVolume:%f\n", ip.dragcoefficient, ip.crosssectarea, ip.mass, ip.volume);
    printf("\n");
}