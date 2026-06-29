#include "math_utils.h"

float Lerpf(float a, float b, float t) {
    return a + (b - a) * t;
}

float Remapf(float value, float in_min, float in_max, float out_min, float out_max) {
    return out_min + (out_max - out_min) * ((value - in_min) / (in_max - in_min));
}

Vector2 Vec2Add(Vector2 a, Vector2 b) {
    return (Vector2){
        .x = a.x + b.x,
        .y = a.y + b.y,
    };
}

Vector2 Vec2Sub(Vector2 a, Vector2 b) {
    return (Vector2){
        .x = a.x - b.x,
        .y = a.y - b.y,
    };
}

Vector2 Vec2Multiply(Vector2 a, Vector2 b) {
    return (Vector2){
        .x = a.x * b.x,
        .y = a.y * b.y,
    };
}

Vector2 Vec2Scale(Vector2 vector, float scaler) {
    return (Vector2){
        .x = vector.x * scaler,
        .y = vector.y * scaler,
    };
}

Vector2 Vec2Lerp(Vector2 a, Vector2 b, float t) {
    return (Vector2){
        .x = Lerpf(a.x, b.x, t),
        .y = Lerpf(a.y, b.y, t),
    };
}

float Vec2Dot(Vector2 a, Vector2 b) {
    return (a.x * b.x) + (a.y * b.y);
}
