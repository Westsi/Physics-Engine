#ifndef VECTOR_H_
#define VECTOR_H_
#include "../coordinate/coordinate.h"

typedef Rectangular Vec2;

typedef Cartesian Vec3;

const Vec2 zeroedVec2 = {0,0};
const Vec3 zeroed = {0,0,0};

Vec2 addVec2(Vec2 a, Vec2 b);
Vec3 add(Vec3 a, Vec3 b);

Vec2 subtractVec2(Vec2 a, Vec2 b);
Vec3 subtract(Vec3 a, Vec3 b);

float scalarMultiplyVec2(Vec2 a, Vec2 b);
float scalarMultiply(Vec3 a, Vec3 b);
float dotProductVec2(Vec2 a, Vec2 b); // wrapper for scalarmultiply()
float dotProduct(Vec3 a, Vec3 b); // wrapper for scalarmultiply()

void printVec(Vec3 a);
void printVec2(Vec2 a);

#endif