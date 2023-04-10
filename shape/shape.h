#ifndef SHAPE_H_
#define SHAPE_H_
#include "../vector/vector.h"

float calculateDensity(float mass, float volume);

float calculateTerminalVelocity(float mass, float crossSectionalArea, float dragCoefficient, float fluidDensity);

float calculateDrag(float directionalVelocity, float dragCoefficient, float crossSectionalArea, float fluidDensity);


#endif