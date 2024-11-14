#include "fileReader.h"
#include "../graph.h"
#include <fstream>

FileReader::FileReader(){}

CityGraph FileReader::readGraph(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("no such file");

    int numNodes, from, to, length, traffic;;
    file>>numNodes;
    CityGraph graph(numNodes);

    while (file >> from >> to >> length >> traffic)
        graph.addRoad(from, to, length, traffic);

    return graph;
}
