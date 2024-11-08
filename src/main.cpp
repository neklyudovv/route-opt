#include <iostream>
#include "graph.h"

int main() {
    CityGraph graph(5);

    graph.addRoad(0, 1, 10, 2);
    graph.addRoad(1, 2, 15, 3);  // 1->2length 15, traffic 3
    graph.addRoad(2, 3, 10, 1);
    graph.addRoad(3, 4, 5, 0);
    graph.addRoad(4, 0, 20, 4);

    graph.printGraph();
    return 0;
}
