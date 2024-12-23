#ifndef VISUAL_H
#define VISUAL_H

#include <SFML/Graphics.hpp>
#include "graph.h"

class Visual {
public:
    Visual(sf::RenderWindow& win, Graph& graph);
    void render();

private:
    sf::RenderWindow& window;
    Graph& graph;

    std::pair<int, int> calculateCoords(std::pair<int, int> coords);
    void drawPoints();
    void drawRoads();
};

#endif