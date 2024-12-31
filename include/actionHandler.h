#ifndef ROUTE_OPT_ACTIONHANDLER_H
#define ROUTE_OPT_ACTIONHANDLER_H

#include "../include/graph.h"
#include "../include/visual.h"
#include "../include/dijkstra.h"
#include <SFML/Graphics.hpp>

class Handler{
public:
    Handler(sf::RenderWindow& win, Graph& graph, Visual& visual, Dijkstra& dijkstra);
    void handleEvent(const sf::Event& event);
private:
    sf::RenderWindow& window;
    Graph& graph;
    Visual& visual;
    Dijkstra& dijkstra;

    int selectedPointA = -1, selectedPointB = -1;

    int findClickedPoint(int mouseX, int mouseY);
    void processSelected();
};

#endif //ROUTE_OPT_ACTIONHANDLER_H
