#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include "graph.h"

class FileReader {
public:
    FileReader();
    CityGraph readGraph(std::string filename);
};

#endif //FILEREADER_H
