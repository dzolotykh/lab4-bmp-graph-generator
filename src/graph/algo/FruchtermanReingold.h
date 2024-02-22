#ifndef FRUCHTERMANREINGOLD_H
#define FRUCHTERMANREINGOLD_H

#include "../Graph.h"
#include "../../math/Vector2D.h"
#include "../../math/Point2D.h"
#include <type_traits>


class FruchtermanReingold {
public:
    explicit FruchtermanReingold(const Graph& g, size_t width, size_t height, double k = 15.0);

    template<typename callbackT = void(int)>
    void run(size_t iter, callbackT callback = [](int){}) noexcept {
        for (int i = 0; i < iter; ++i) {
            run_iter();
            callback(i);
        }
        scale();
    }

    std::vector<Point2D> get_positions() const noexcept;

private:
    const Graph& g_;
    const double k_;
    double temp_;
    const size_t width_;
    const size_t height_;
    std::vector<Vector2D> move_to_;
    std::vector<Point2D> positions_;

    double fa(double x) const noexcept;
    double fr(double x) const noexcept;
    void run_iter() noexcept;
    void scale() noexcept;
};


#endif // FRUCHTERMANREINGOLD_H
