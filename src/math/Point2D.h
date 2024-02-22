#ifndef POINT2D_H
#define POINT2D_H

#include "Vector2D.h"

struct Point2D {
    double x, y;

    explicit Point2D(double _x = 0, double _y = 0): x(_x), y(_y) {}

    explicit operator Vector2D() const noexcept;

    Point2D& operator+=(const Vector2D &other) noexcept;

    Point2D& operator-=(const Vector2D &other) noexcept;
};

Point2D operator+(const Point2D &l, const Vector2D &s) noexcept;

Point2D operator-(const Point2D &l, const Vector2D &s) noexcept;

Vector2D operator-(const Point2D &l, const Point2D &s) noexcept;


#endif // POINT2D_H
