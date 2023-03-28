#include "tests.h"
#include "coordinate.h"

void testCoordinates() {
    /*
    Assuming no changes to suite, expected results:
    Polar to Rect (7.071068, 7.071068)
    Rect to Polar (Magnitude: 10.000000, Theta: 45.000000)
    Cyl to Cart (7.071068, 7.071068, 10.000000)
    Cart to Cyl (Magnitude: 10.000000, Theta: 45.000000, Height: 10.000000)
    Spher to Cart (5.000000, 5.000000, 7.071068)
    Cart to Spher (Magnitude: 10.000000, Phi: 45.000000, Theta: 45.000000)
    D to R: 5.759587
    R to D: 330.000000
    */

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
    p.theta = 45;

    c.height = 10;
    c.magnitude = 10;
    c.theta = 45;

    s.magnitude = 10;
    s.theta = 45;
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
    printf("D to R: %f\n", fres);

    fres = RadiansToDegrees(fres);
    printf("R to D: %f\n", fres);
}
void testVectors() {
    printf("Should have written a test ¯\\_(ツ)_/¯");

}
void testParticles() {
    printf("Should have written a test if you wanted to run it, dummy.");
}