#include <math.h>
#include <stdio.h>
#include "vector.h"

Vec2 zeroedVec2 = {0,0};
Vec3 zeroed = {0,0,0};

Vec2 addVec2(Vec2 a, Vec2 b) {
    Vec2 result = {a.x + b.x, a.y + b.y};
    return result;
}

Vec3 add(Vec3 a, Vec3 b) {
    Vec3 result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

Vec2 subtractVec2(Vec2 a, Vec2 b) {
    Vec2 result = {a.x - b.x, a.y - b.y};
    return result;
}

Vec3 subtract(Vec3 a, Vec3 b) {
    Vec3 result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

float scalarMultiplyVec2(Vec2 a, Vec2 b) {
    float result = (a.x * b.x) + (a.y * b.y);
    return result;
}

float scalarMultiply(Vec3 a, Vec3 b) {
    float result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    return result;
}

float dotProductVec2(Vec2 a, Vec2 b) {
    return scalarMultiplyVec2(a, b);
}

float dotProduct(Vec3 a, Vec3 b) {
    return scalarMultiply(a, b);
}

Vec2 multiplyByFloatVec2(Vec2 a, float b) {
    return (Vec2) {a.x * b, a.y * b};
}

Vec3 multiplyByFloat(Vec3 a, float b) {
    return (Vec3) {a.x * b, a.y * b, a.z * b};
}

void printVec(Vec3 a) {
    printf("(%f, %f, %f)\n", a.x, a.y, a.z);
}

void printVec2(Vec2 a) {
    printf("(%f, %f)\n", a.x, a.y);
}