#ifndef POINT2D_H
#define POINT2D_H

#include "Vector2D.h"

struct Point2D {
    double x, y;

    explicit Point2D(double _x = 0, double _y = 0): x(_x), y(_y) {}

    explicit operator Vector2D() const;

    Point2D& operator+=(const Vector2D &other);

    Point2D& operator-=(const Vector2D &other);
};

Point2D operator+(const Point2D &l, const Vector2D &s);

Point2D operator-(const Point2D &l, const Vector2D &s);

Vector2D operator-(const Point2D &l, const Point2D &s);


#endif // POINT2D_H
