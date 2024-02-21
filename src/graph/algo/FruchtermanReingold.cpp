#include "FruchtermanReingold.h"

FruchtermanReingold::FruchtermanReingold(const Graph &g, double k) : g_(g)
        , k_(k)
        , temp_(g.size())
        , move_to(g_.size()) {}

double FruchtermanReingold::fa(double x) const noexcept {
    return x * x / k_;
}

double FruchtermanReingold::fr(double x) const noexcept {
    return k_ * k_ / x;
}

void FruchtermanReingold::run(std::vector<Point2D> &positions) noexcept {
    fill(move_to.begin(), move_to.end(), Vector2D(0, 0));

    for (Graph::vertexT v = 0; v < g_.size(); ++v) {
        for (Graph::vertexT u = v + 1; u < g_.size(); ++u) {
            auto delta = positions[v] - positions[u];
            move_to[v] += (delta * fr(delta.size()) / delta.size());
            move_to[u] -= (delta * fr(delta.size()) / delta.size());
        }
    }

    for (Graph::vertexT v = 0; v < g_.size(); ++v) {
        for (Graph::vertexT u : g_.get_neighbours(v)) {
            if (u > v) continue;
            auto delta = positions[v] - positions[u];
            move_to[v] -= (delta * fa(delta.size()) / delta.size());
            move_to[u] += (delta * fa(delta.size()) / delta.size());
        }
    }

    for (Graph::vertexT v = 0; v < g_.size(); ++v) {
        positions[v] += (move_to[v] * std::min(temp_, move_to[v].size()) / move_to[v].size());
    }

    temp_ *= 0.99;
    if (temp_ < 0.001) {
        temp_ = 0.001;
    }
}
