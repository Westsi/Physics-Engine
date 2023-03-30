#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct {
    float x;
    float y;
} Vec2;

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

extern Vec2 zeroedVec2;
extern Vec3 zeroed;

Vec2 addVec2(Vec2 a, Vec2 b);
Vec3 add(Vec3 a, Vec3 b);

Vec2 subtractVec2(Vec2 a, Vec2 b);
Vec3 subtract(Vec3 a, Vec3 b);

float scalarMultiplyVec2(Vec2 a, Vec2 b);
float scalarMultiply(Vec3 a, Vec3 b);
float dotProductVec2(Vec2 a, Vec2 b); // wrapper for scalarmultiply()
float dotProduct(Vec3 a, Vec3 b); // wrapper for scalarmultiply()

Vec2 multiplyByFloatVec2(Vec2 a, float b);
Vec3 multiplyByFloat(Vec3 a, float b);

void printVec(Vec3 a);
void printVec2(Vec2 a);

#endif