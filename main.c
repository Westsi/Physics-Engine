#include<stdio.h>
#include<math.h>
#include "particle/particle.h"
#include "vector/vector.h"
#include "coordinate/coordinate.h"

int main(int argc, char argv[]) {
    // printf("Hello World!");

    Rectangular rres;
    Polar pres;
    Cartesian cres;
    Cylindrical cylres;
    Spherical sres;
    float fres;

    Polar p;
    Cylindrical c;
    Spherical s;

    p.magnitude = 10;
    p.theta = 90;

    c.height = 10;
    c.magnitude = 10;
    c.theta = 90;

    s.magnitude = 10;
    s.theta = 90;
    s.phi = 45;

    rres = polarToRect(&p);
    printf("Polar to Rect (%f, %f)\n", rres.x, rres.y);

    pres = rectToPolar(&rres);
    printf("Rect to Polar (Magnitude: %f, Theta: %f)\n", pres.magnitude, pres.theta);

    cres = cylToCart(&c);
    printf("Cyl to Cart (%f, %f, %f)\n", cres.x, cres.y, cres.z);

    cylres = cartToCyl(&cres);
    printf("Cart to Cyl (Magnitude: %f, Theta: %f, Height: %f)\n", cylres.magnitude, cylres.theta, cylres.height);

    cres = spherToCart(&s);
    printf("Spher to Cart (%f, %f, %f)\n", cres.x, cres.y, cres.z);

    sres = cartToSpher(&cres);
    printf("Cart to Spher (Magnitude: %f, Phi: %f, Theta: %f)\n", sres.magnitude, sres.phi, sres.theta);

    fres = DegreesToRadians(330.0f);
    printf("D to R: %f", fres);

    fres = RadiansToDegrees(fres);
    printf("R to D: %f", fres);
    return 0;
}