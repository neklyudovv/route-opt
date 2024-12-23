#include "../include/graph.h"

void Graph::addRoad(std::pair<int, int> from, std::pair<int, int> to, int length, int traffic){
    cityMap.emplace_back(from, to, length, traffic);
}

std::vector<Graph::Road> Graph::getGraph(){
    return cityMap;
}