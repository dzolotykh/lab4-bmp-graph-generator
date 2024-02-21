#include "Vector2D.h"

Vector2D operator+(const Vector2D &l, const Vector2D &r) noexcept {
    return Vector2D(l.x + r.x, l.y + r.y);
}

Vector2D operator-(const Vector2D &l, const Vector2D &r) noexcept {
    return Vector2D(l.x - r.x, l.y - r.y);
}

Vector2D operator*(const Vector2D &l, double scalar) noexcept {
    return Vector2D(l.x * scalar, l.y * scalar);
}

Vector2D operator*(double scalar, const Vector2D &r) noexcept {
    return Vector2D(r.x * scalar, r.y * scalar);
}

Vector2D operator/(const Vector2D &l, double scalar) noexcept {
    return Vector2D(l.x / scalar, l.y / scalar);
}
