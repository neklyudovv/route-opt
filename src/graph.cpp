#include "../include/graph.h"

void Graph::addRoad(int from, int to, int length, int traffic){
    cityMap.emplace_back(from, to, length, traffic);
}

std::vector<Graph::Road> Graph::getGraph(){
    return cityMap;
}