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

    void drawPoints();
};

#endif