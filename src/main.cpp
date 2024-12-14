#include <iostream>
#include "../include/graph.h"

int main(){
    Graph graph(5);
    graph.addRoad(0, 1, 3, 1);
    graph.addRoad(1, 2, 4, 1);

    std::vector<Graph::Road> asd = graph.getGraph();

    for (auto road : asd)
        std::cout << "from " << road.from << " to " << road.to << " in " << road.length+road.traffic << "\n";
    return 0;
}