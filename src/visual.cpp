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

    drawRoads();
    drawPoints();
    drawSelectedPoints();
    highlightPath();

    window.display();
}

std::pair<int, int> Visual::calculateCoords(std::pair<int, int> coords){
    float windowWidth = static_cast<float>(window.getSize().x);
    float windowHeight = static_cast<float>(window.getSize().y);

    float minX = graph.getGraph()[0].from.first, maxX = minX;
    float minY = graph.getGraph()[0].from.second, maxY = minY;

    for (const auto& point : graph.getGraph()) {
        minX = std::min((int)minX, std::min(point.from.first, point.to.first));
        maxX = std::max((int)maxX, std::max(point.from.first, point.to.first));
        minY = std::min((int)minY, std::min(point.from.second, point.to.second));
        maxY = std::max((int)maxY, std::max(point.from.second, point.to.second));
    }

    minX -= 20;
    maxX += 20;
    minY -= 20;
    maxY += 20;

    float scale = std::min(windowWidth / (maxX-minX+1), windowHeight / (maxY-minY+1));

    float offsetX = (windowWidth - (maxX-minX)*scale) / 2;
    float offsetY = (windowHeight - (maxY-minY)*scale) / 2;

    return {(coords.first-minX)*scale + offsetX, (coords.second-minY)*scale+offsetY};
}

void Visual::drawPoints(){
    for (size_t i = 0; i < graph.getGraph().size(); ++i){
        auto point = graph.getGraph()[i];
        sf::CircleShape pointShape(5), pointShapeTo(5);
        pointShape.setFillColor(sf::Color::Green);
        pointShapeTo.setFillColor(sf::Color::Green);
        auto [x1, y1] = calculateCoords(point.from);
        auto [x2, y2] = calculateCoords(point.to); // now also drawing dest. point due to bug
        pointShape.setPosition(x1-pointShape.getRadius(), y1-pointShape.getRadius());
        pointShapeTo.setPosition(x2-pointShape.getRadius(), y2-pointShape.getRadius());
        window.draw(pointShape);
        window.draw(pointShapeTo);
    }
}

void Visual::drawRoads() {
    for (const auto& road : graph.getGraph()) {
        auto [startX, startY] = calculateCoords(road.from);
        auto [endX, endY] = calculateCoords(road.to);
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(startX, startY)),
                sf::Vertex(sf::Vector2f(endX, endY))
        };

        line[0].color = sf::Color::White;
        line[1].color = sf::Color::White;

        window.draw(line, 2, sf::Lines);
    }
}

void Visual::addSelectedPoint(std::pair<int, int> point){
    selectedPoints.push_back(point);
}

void Visual::drawSelectedPoints(){
    for (const auto& point : selectedPoints) {
        sf::CircleShape pointShape(5);
        pointShape.setFillColor(sf::Color::Red);
        auto [x, y] = calculateCoords(point);
        pointShape.setPosition(x - pointShape.getRadius(), y - pointShape.getRadius());
        window.draw(pointShape);
    }
}

void Visual::highlightPath(){
    if(selectedPoints.size()>2){
        for (size_t i = 2; i < selectedPoints.size() - 1; ++i) {
            auto [startX, startY] = calculateCoords(selectedPoints[i]);
            auto [endX, endY] = calculateCoords(selectedPoints[i + 1]);
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(startX, startY)),
                    sf::Vertex(sf::Vector2f(endX, endY))
            };

            line[0].color = sf::Color::Red;
            line[1].color = sf::Color::Red;

            window.draw(line, 2, sf::Lines);
        }
    }
}