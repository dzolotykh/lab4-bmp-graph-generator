#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    using vertexT = size_t;
    size_t size() const noexcept;
    const std::vector<vertexT>& get_neighbours(vertexT vertex_num) const noexcept;
    explicit Graph(const std::string &path);

private:
    using containerT = std::vector<std::vector<size_t>>;

    containerT g_;
};


#endif // GRAPH_H
