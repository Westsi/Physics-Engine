#include "coordinate.h"
#include <math.h>
#include "constant.h"

Rectangular polarToRect(Polar *p) {
    Polar ip = *p;
    Rectangular r;
    r.x = (float) ip.magnitude * cos(DegreesToRadians(ip.theta));
    r.y = (float) ip.magnitude * sin(DegreesToRadians(ip.theta));
    return r;
}

Polar rectToPolar(Rectangular *r) {
    Rectangular ir = *r;
    Polar p;
    p.magnitude = sqrt((ir.x * ir.x) + (ir.y * ir.y));
    p.theta = RadiansToDegrees((float) atan(ir.y/ir.x));
    return p;
}

Cartesian cylToCart(Cylindrical *c) {
    Cylindrical ic = *c;
    Cartesian cart;
    cart.x = ic.magnitude * cos(DegreesToRadians(ic.theta));
    cart.y = ic.magnitude * sin(DegreesToRadians(ic.theta));
    cart.z = ic.height;
    return cart;
}

Cartesian spherToCart(Spherical *s) {
    Spherical is = *s;
    Cartesian c;
    c.x = is.magnitude * sin(DegreesToRadians(is.phi)) * cos(DegreesToRadians(is.theta));
    c.y = is.magnitude * sin(DegreesToRadians(is.phi)) * sin(DegreesToRadians(is.theta));
    c.z = is.magnitude * cos(DegreesToRadians(is.phi));
    return c;
}

Cylindrical cartToCyl(Cartesian *c) {
    Cartesian ic = *c;
    Cylindrical cyl;

    cyl.magnitude = sqrt((ic.x * ic.x) + (ic.y * ic.y));
    cyl.theta = RadiansToDegrees(atan(ic.y/ic.x));
    cyl.height = ic.z;
    return cyl;
}

Spherical cartToSpher(Cartesian *c) {
    Cartesian ic = *c;
    Spherical s;
    s.magnitude = sqrt((ic.x * ic.x) + (ic.y * ic.y) + (ic.z * ic.z));
    s.theta = RadiansToDegrees(atan(ic.y/ic.x));
    s.phi = RadiansToDegrees(acos(ic.z/s.magnitude));
    return s;
}

Cylindrical spherToCyl(Spherical *s) {
    Spherical is = *s;
    Cylindrical c;
    c.magnitude = is.magnitude * sin(DegreesToRadians(is.theta));
    c.theta = is.theta;
    c.height = is.magnitude * cos(DegreesToRadians(is.theta));
    return c;
}
Spherical cylToSpher(Cylindrical *c) {
    Cylindrical ic = *c;
    Spherical s;
    s.magnitude = sqrt((ic.magnitude * ic.magnitude) + (ic.height * ic.height));
    s.theta = ic.theta;
    s.phi = acos(ic.height/s.magnitude);
    return s;
}

float DegreesToRadians(float f) {
    return (f * PI / 180);
}

float RadiansToDegrees(float f) {
    return (f * 180 / PI);
}