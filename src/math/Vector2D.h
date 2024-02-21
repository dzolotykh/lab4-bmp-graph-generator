#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>


struct Vector2D {
    // TODO move realisations to .cpp file
    double x, y;

    explicit Vector2D(double _x = 0, double _y = 0): x(_x), y(_y) {}

    Vector2D& operator+=(const Vector2D &other) noexcept {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2D& operator-=(const Vector2D &other) noexcept {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2D& operator*=(double scalar) noexcept {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2D& operator/=(double scalar) noexcept {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    double size() const noexcept {
        return std::sqrt(x * x + y * y);
    }
};

Vector2D operator+(const Vector2D &l, const Vector2D &r) noexcept;

Vector2D operator-(const Vector2D &l, const Vector2D &r) noexcept;

Vector2D operator*(const Vector2D &l, double scalar) noexcept;

Vector2D operator*(double scalar, const Vector2D &r) noexcept;
Vector2D operator/(const Vector2D &l, double scalar) noexcept;


#endif // VECTOR2D_H
