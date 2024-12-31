#ifndef VISUAL_H
#define VISUAL_H

#include <SFML/Graphics.hpp>
#include "graph.h"

class Visual {
public:
    Visual(sf::RenderWindow& win, Graph& graph);

    std::pair<int, int> calculateCoords(std::pair<int, int> coords);
    void addSelectedPoint(std::pair<int, int> point);
    void render();
private:
    sf::RenderWindow& window;
    Graph& graph;
    std::vector<std::pair<int, int>> selectedPoints;

    void drawSelectedPoints();
    void drawPoints();
    void drawRoads();
    void highlightPath();
};

#endif