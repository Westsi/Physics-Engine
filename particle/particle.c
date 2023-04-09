#include <stdio.h>
#include "../particle/particle.h"
#include "../vector/vector.h"
#include "../constant/constant.h"
#include "../shape/shape.h"

Particle newOriginParticle() {
    return (Particle) newOriginSphere();
}

void RunUpdate(Particle *p) {
    // in general Δt for this func should be 1 millisecond, if not change
    float dt = 0.001;


    Particle ip = *p;   // REMEMBER! This only allows you to read from struct and update values IN THIS SCOPE
                        // To update globally do p->_attribute_ = ...

    Vec3 change = zeroed;

    // apply forces to change particle's acceleration
    printf("CSA: %f\n", PI*ip.radius*ip.radius);
    change.x += calculateDrag(ip.velocity.x, ip.dragcoefficient, PI*ip.radius*ip.radius, AIR_DENSITY) / ip.mass;
    change.z += calculateDrag(ip.velocity.z, ip.dragcoefficient, PI*ip.radius*ip.radius, AIR_DENSITY) / ip.mass;

    change.y = ((ip.mass * EARTH_GRAVITY) + (ip.velocity.y, ip.dragcoefficient, PI*ip.radius*ip.radius, AIR_DENSITY))/ip.mass;


    // set acceleration to change
    p->acceleration = change;

    // update velocity by acceleration
    // a*Δt=Δv
    p->velocity = add(ip.velocity, multiplyByFloat(change, dt));
    // move particle by velocity
    // s = d/t
    // d = s*t
    p->position = add(multiplyByFloat(p->velocity, dt), p->position);
    
}

void printParticle(Particle *p) {
    Particle ip = *p;

    printf("Position: (%f, %f, %f)\nVelocity: (%f, %f, %f)\nAcceleration: (%f, %f, %f)\n", ip.position.x, ip.position.y, ip.position.z, ip.velocity.x, ip.velocity.y, ip.velocity.z, ip.acceleration.x, ip.acceleration.y, ip.acceleration.z);
    printf("\nConstants:\nRadius: %f\nCross-sectional Area: %f\nMass: %f\n\n", ip.radius, ip.dragcoefficient, ip.mass);
}