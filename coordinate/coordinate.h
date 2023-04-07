#ifndef COORDINATE_H_
#define COORDINATE_H_
#include <math.h>
#include "vector.h"

// https://www.cs.mcgill.ca/~rwest/wikispeedia/wpcd/wp/p/Polar_coordinate_system.htm#:~:text=Polar%20coordinates%20can%20also%20be,as%20in%20the%20polar%20coordinates).

typedef struct
{
    float magnitude;
    float theta; // degrees - angle from x axis
} Polar;

typedef struct
{
    float magnitude;
    float theta; // degrees - angle from x axis
    float height;
} Cylindrical;

typedef struct
{
    float magnitude;
    float phi;   // degrees - angle from z axis
    float theta; // degrees - angle from x axis
} Spherical;

typedef Vec2 Rectangular;

typedef Vec3 Cartesian;

Rectangular polarToRect(Polar *p);
Polar rectToPolar(Rectangular *r);

Cartesian cylToCart(Cylindrical *c);
Cartesian spherToCart(Spherical *s);
Cylindrical cartToCyl(Cartesian *c);
Spherical cartToSpher(Cartesian *c);

Cylindrical spherToCyl(Spherical *s);
Spherical cylToSpher(Cylindrical *c);

float DegreesToRadians(float f);
float RadiansToDegrees(float f);

#endif