#include "../include/visual.h"
#include <iostream>
#include <SFML/Graphics.hpp>

/* data.txt :
данные по точкам графа должны быть, по сути, координатами x и y
которые здесь должны быть преобразованы под позицию на экране
при этом так, чтобы ничего за края не вылезало
получается нужно масштабировать под текущий размер окна и отрисовывать */


Visual::Visual(sf::RenderWindow& win, Graph& graph)
        : window(win), graph(graph) {}

void Visual::render(){
    window.clear();

    drawPoints();

    window.display();
}

void Visual::drawPoints(){
    for (size_t i = 0; i < graph.getGraph().size(); ++i){
        auto point = graph.getGraph()[i];
        sf::CircleShape pointShape(5);
        pointShape.setFillColor(sf::Color::Green);
        pointShape.setPosition(point.from.first*10, point.from.second*10);
        window.draw(pointShape);
    }
}