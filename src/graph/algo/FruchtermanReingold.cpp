#include "FruchtermanReingold.h"

FruchtermanReingold::FruchtermanReingold(const Graph &g,  size_t width, size_t height, double k) : g_(g)
        ,k_(k)
        ,temp_(g.size())
        ,move_to_(g_.size()),
        positions_(g.size()),
        width_(width),
        height_(height)
        {
            double angle = 2.0 * M_PI / g.size();
            for (Graph::vertexT v_id = 0; v_id < g.size(); v_id++) {
                positions_[v_id].x = cos(v_id * angle);
                positions_[v_id].y = sin(v_id * angle);
            }

        }

double FruchtermanReingold::fa(double x) const noexcept {
    return x * x / k_;
}

double FruchtermanReingold::fr(double x) const noexcept {
    return k_ * k_ / x;
}

std::vector<Point2D> FruchtermanReingold::get_positions() const noexcept {
    return positions_;
}

void FruchtermanReingold::scale() noexcept {
    // find current dimensions
    double x_min = std::numeric_limits<double>::max();
    double x_max = std::numeric_limits<double>::lowest();
    double y_min = std::numeric_limits<double>::max();
    double y_max = std::numeric_limits<double>::lowest();

    for (Graph::vertexT v_id = 0; v_id < g_.size(); v_id++) {
        x_min = std::min(x_min, positions_[v_id].x);
        x_max = std::max(x_max, positions_[v_id].x);
        y_min = std::min(y_min, positions_[v_id].y);
        y_max = std::max(y_max, positions_[v_id].y);
    }

    double cur_width = x_max - x_min;
    double cur_height = y_max - y_min;

    // compute scale factor (0.9: keep some margin)
    double x_scale = width_ / cur_width;
    double y_scale = height_ / cur_height;
    double scale = 0.9 * std::min(x_scale, y_scale);

    // compute offset and apply it to every position
    Vector2D center(x_max + x_min, y_max + y_min);
    Vector2D offset = center / 2.0 * scale;
    for (Graph::vertexT v_id = 0; v_id < g_.size(); v_id++) {
        auto tmp = ((Vector2D) positions_[v_id] * scale - offset);
        positions_[v_id] = Point2D(tmp.x + width_ / 2.0, tmp.y + height_ / 2.0);
    }
}

void FruchtermanReingold::run_iter() noexcept {
    fill(move_to_.begin(), move_to_.end(), Vector2D(0, 0));

    for (Graph::vertexT v = 0; v < g_.size(); ++v) {
        for (Graph::vertexT u = v + 1; u < g_.size(); ++u) {
            auto delta = positions_[v] - positions_[u];
            move_to_[v] += (delta * fr(delta.size()) / delta.size());
            move_to_[u] -= (delta * fr(delta.size()) / delta.size());
        }
    }

    for (Graph::vertexT v = 0; v < g_.size(); ++v) {
        for (Graph::vertexT u : g_.get_neighbours(v)) {
            if (u > v) continue;
            auto delta = positions_[v] - positions_[u];
            move_to_[v] -= (delta * fa(delta.size()) / delta.size());
            move_to_[u] += (delta * fa(delta.size()) / delta.size());
        }
    }

    for (Graph::vertexT v = 0; v < g_.size(); ++v) {
        positions_[v] += (move_to_[v] * std::min(temp_, move_to_[v].size()) / move_to_[v].size());
    }

    temp_ *= 0.99;
    if (temp_ < 0.001) {
        temp_ = 0.001;
    }
}
