#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>


struct Vector2D {
    double x, y;

    explicit Vector2D(double _x = 0, double _y = 0) noexcept: x(_x), y(_y) {}

    Vector2D& operator+=(const Vector2D &other) noexcept;

    Vector2D& operator-=(const Vector2D &other) noexcept;

    Vector2D& operator*=(double scalar) noexcept;

    Vector2D& operator/=(double scalar) noexcept;

    double size() const noexcept;
};

Vector2D operator+(const Vector2D &l, const Vector2D &r) noexcept;

Vector2D operator-(const Vector2D &l, const Vector2D &r) noexcept;

Vector2D operator*(const Vector2D &l, double scalar) noexcept;

Vector2D operator*(double scalar, const Vector2D &r) noexcept;
Vector2D operator/(const Vector2D &l, double scalar) noexcept;


#endif // VECTOR2D_H
