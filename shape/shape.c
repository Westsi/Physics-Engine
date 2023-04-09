#include<math.h>
#include "shape.h"
#include "../constant/constant.h"
#include "../vector/vector.h"

Sphere newOriginSphere() {
    return (Sphere) {zeroed, zeroed, zeroed, 1, DRAG_COEFFICIENT_SPHERE, 1};
}

float calculateDensity(float mass, float volume) {
    // assuming that mass and volume are SI
    return mass/volume;
}


// Negative result
float calculateTerminalVelocity(float mass, float crossSectionalArea, float dragCoefficient, float fluidDensity) {
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

    float numerator = 2 * mass * fabs(EARTH_GRAVITY);
    float denominator = fluidDensity * crossSectionalArea * dragCoefficient;

    return -(sqrt(numerator/denominator));
}

// Returns NEWTONS - FORCE!!
float calculateDrag(float directionalVelocity, float dragCoefficient, float crossSectionalArea, float fluidDensity) {
    /*
    Returns in N
    Formula is 0.5 * fluid density * relative speed between obj and fluid (normally just speed of obj, but watch out!) SQUARED * drag coefficient * cross sectional area
    Units are:
        relative speed m/s
        density of fluid kg/m-3
        area m-2
        drag coefficient n/a
    */
    return (0.5 * fluidDensity * directionalVelocity * directionalVelocity * dragCoefficient * crossSectionalArea);
}