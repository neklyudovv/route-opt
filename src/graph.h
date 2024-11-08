#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class CityGraph {
private:
    struct Road {
        int to;        // Конечная вершина дороги
        int length;    // Длина дороги
        int traffic;   // Уровень пробки

        Road(int destination, int roadLength, int trafficLevel)
            : to(destination), length(roadLength), traffic(trafficLevel) {}
    };

public:
    std::vector<std::vector<Road>> cityMap;

    CityGraph(int numNodes) : cityMap(numNodes) {}
    void addRoad(int from, int to, int length, int traffic);
    void printGraph();
};

#endif // GRAPH_H
