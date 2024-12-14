#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    struct Road {
        int from;
        int to;
        int length;
        int traffic;

        Road(int from, int to, int length, int traffic)
                : from(from), to(to), length(length), traffic(traffic) {}
    };

    Graph(int numNodes) : cityMap() { numNodes = cityMap.size(); }
    void addRoad(int from, int to, int length, int traffic);
    std::vector<Graph::Road> getGraph();

private:
    std::vector<Road> cityMap;
};

#endif // GRAPH_H
