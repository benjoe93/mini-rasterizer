#ifndef MINI_RASTERIZER_MATH_UTILS_H
#define MINI_RASTERIZER_MATH_UTILS_H
// Vectors, matrices, transformations

typedef struct Vector2 {
    float x;
    float y;
} Vector2;

typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

typedef struct Vector4 {
    float x;
    float y;
    float z;
    float w;
} Vector4;

float Lerpf(float a, float b, float t);
float Remapf(float value, float in_min, float in_max, float out_min, float out_max);

Vector2 Vec2Add(Vector2 a, Vector2 b);
Vector2 Vec2Sub(Vector2 a, Vector2 b);
Vector2 Vec2Multiply(Vector2 a, Vector2 b);
Vector2 Vec2Scale(Vector2 vector, float scaler);
Vector2 Vec2Lerp(Vector2 a, Vector2 b, float t);
float Vec2Dot(Vector2 a, Vector2 b);

#endif //MINI_RASTERIZER_MATH_UTILS_H
