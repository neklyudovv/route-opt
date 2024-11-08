#include "graph.h"
#include <iostream>

void CityGraph::addRoad(int from, int to, int length, int traffic) {
    cityMap[from].emplace_back(to, length, traffic);
    cityMap[to].emplace_back(from, length, traffic);
}

void CityGraph::printGraph() {
    for (int i = 0; i < cityMap.size(); i++)
        for (auto road : cityMap[i])
            std::cout << road.to << " " << road.length << " " << road.traffic << std::endl;
}