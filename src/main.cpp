#include <iostream>
#include "../include/graph.h"
#include "../include/fileReader.h"

int main(){
    Reader reader;
    Graph graph = reader.readGraph("../data/input.txt");

    std::vector<Graph::Road> asd = graph.getGraph();

    for (auto road : asd)
        std::cout << "from " << road.from << " to " << road.to << " in " << road.length+road.traffic << "\n";
    return 0;
}