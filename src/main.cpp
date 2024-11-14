#include <iostream>
#include "dijkstra.h"
#include "graph.h"
#include "utils/fileReader.h"

int main() {
    FileReader reader;
    CityGraph graph = reader.readGraph("../data/data.txt");

    Dijkstra dijkstra(graph);
    graph.printGraph();

    std::vector<int> path = dijkstra.findShortestPath(0, 3);
    std::cout << "path from 0 to 3:" << "\n";
    for(int node : path)
        std::cout << node << " ";
    return 0;
}
