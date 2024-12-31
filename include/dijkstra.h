#ifndef ROUTE_OPT_DIJKSTRA_H
#define ROUTE_OPT_DIJKSTRA_H

#include "graph.h"
#include <vector>
#include <utility>

class Dijkstra {
public:
    Dijkstra(Graph& graph);
    std::vector<std::pair<int, int>> findShortestPath(std::pair<int, int> start, std::pair<int, int> end);
private:
    Graph& graph;
};

#endif //ROUTE_OPT_DIJKSTRA_H
