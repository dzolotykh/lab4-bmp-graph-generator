#ifndef FRUCHTERMANREINGOLD_H
#define FRUCHTERMANREINGOLD_H

#include "../Graph.h"
#include "../../math/Vector2D.h"
#include "../../math/Point2D.h"

class FruchtermanReingold {
public:
    FruchtermanReingold(const Graph& g, double k = 15.0);
    void run(std::vector<Point2D>& positions) noexcept;

private:
    const Graph& g_;
    const double k_;
    double temp_;
    std::vector<Vector2D> move_to;

    double fa(double x) const noexcept;
    double fr(double x) const noexcept;
};


#endif // FRUCHTERMANREINGOLD_H
