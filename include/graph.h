#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    struct Road {
        std::pair<int, int> from;
        std::pair<int, int> to;
        int length;
        int traffic;

        Road(std::pair<int, int> from, std::pair<int, int> to, int length, int traffic)
                : from(from), to(to), length(length), traffic(traffic) {}
    };

    Graph() : cityMap() {}
    void addRoad(std::pair<int, int> from, std::pair<int, int> to, int length, int traffic);
    std::vector<Graph::Road> getGraph();

private:
    std::vector<Road> cityMap;
};

#endif // GRAPH_H
