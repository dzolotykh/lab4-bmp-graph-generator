#ifndef FRUCHTERMANREINGOLD_H
#define FRUCHTERMANREINGOLD_H

#include "../Graph.h"
#include "../../math/Vector2D.h"
#include "../../math/Point2D.h"

class FruchtermanReingold {
public:
    FruchtermanReingold(const Graph& g, double k = 15.0);
    void operator()(std::vector<Point2D>& positions);

private:
    const Graph& g_;
    const double k_;
    const double k_squared_;
    double temp_;
    std::vector<std::pair<Graph::vertexT, Graph::vertexT>> edges_;
    std::vector<Vector2D> mvmts_;
};


#endif // FRUCHTERMANREINGOLD_H
