#include "Point2D.h"

Point2D operator+(const Point2D &l, const Vector2D &s) noexcept {
    return Point2D(l.x + s.x, l.y + s.y);
}

Point2D operator-(const Point2D &l, const Vector2D &s) noexcept {
    return Point2D(l.x - s.x, l.y - s.y);
}

Vector2D operator-(const Point2D &l, const Point2D &s) noexcept {
    return Vector2D(l.x - s.x, l.y - s.y);
}

Point2D::operator Vector2D() const noexcept {
    return Vector2D(x, y);
}

Point2D& Point2D::operator+=(const Vector2D &other) noexcept {
    x += other.x;
    y += other.y;
    return *this;
}

Point2D& Point2D::operator-=(const Vector2D &other) noexcept {
    x -= other.x;
    y -= other.y;
    return *this;
}
