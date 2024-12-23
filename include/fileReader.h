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
        int fromX, fromY, toX, toY, length, traffic;
        while(f >> fromX >> fromY >> toX >> toY >> length >> traffic)
            graph.addRoad(std::pair<int,int>(fromX, fromY),
                    std::pair<int, int>(toX, toY), length, traffic);
        return graph;
    }
};

#endif //ROUTE_OPT_FILEREADER_H
