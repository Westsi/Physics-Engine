#include <math.h>

// https://www.cs.mcgill.ca/~rwest/wikispeedia/wpcd/wp/p/Polar_coordinate_system.htm#:~:text=Polar%20coordinates%20can%20also%20be,as%20in%20the%20polar%20coordinates).

typedef struct {
    float magnitude;
    float angle; // degrees
} Polar;

typedef struct {
    float magnitude;
    float theta; // degrees - angle from x axis
    float height;
} Cylindrical;

typedef struct {
    float magnitude;
    float phi; // degrees - angle from z axis
    float theta; // degrees - angle from x axis
} Spherical;

typedef struct {
    float x;
    float y;
    float z;
} Cartesian;