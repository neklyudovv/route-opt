#ifndef ROUTE_OPT_FILEREADER_H
#define ROUTE_OPT_FILEREADER_H

#include <fstream>
#include "graph.h"

class Reader{
public:
    std::vector<Graph::Road> curr;
    Reader(){};

    Graph readGraph(const std::string& filename){
        Graph graph;
        std::ifstream f(filename);
        if (!f.is_open())
            throw std::runtime_error("no such file");
        int from, to, length, traffic;
        while(f >> from >> to >> length >> traffic)
            graph.addRoad(from, to, length, traffic);
        return graph;
    }
};

#endif //ROUTE_OPT_FILEREADER_H
