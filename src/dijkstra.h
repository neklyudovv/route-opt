#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <vector>
#include <utility>

class Dijkstra {
public:
    Dijkstra(const CityGraph& graph);
    std::vector<int> findShortestPath(int start, int end);
private:
    const CityGraph& graph;
};

#endif //DIJKSTRA_H
