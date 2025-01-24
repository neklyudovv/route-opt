#include "../include/actionHandler.h"
#include <iostream>

Handler::Handler(sf::RenderWindow& win, Graph& graph, Visual& visual, Dijkstra& dijkstra)
        : window(win), graph(graph), visual(visual), dijkstra(dijkstra) {}

void Handler::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        int clickedPoint = findClickedPoint(event.mouseButton.x, event.mouseButton.y);
        if (clickedPoint != -1) {
            if (selectedPointA == -1) {
                selectedPointA = clickedPoint;
                visual.addSelectedPoint(graph.getGraph()[selectedPointA].from);
            } else if (selectedPointB == -1) {
                selectedPointB = clickedPoint;
                visual.addSelectedPoint(graph.getGraph()[selectedPointB].from);
                processSelected();
            }
        }
    }
}

int Handler::findClickedPoint(int mouseX, int mouseY) {
    for (int i = 0; i < graph.getGraph().size(); ++i) {
        auto point = graph.getGraph()[i];
        auto [x, y] = visual.calculateCoords(point.from);

        float dx = mouseX - x;
        float dy = mouseY - y;
        if (dx * dx + dy * dy <= 25) {
            return i;
        }
    }
    return -1;
}

void Handler::processSelected() {
    auto pointA = graph.getGraph()[selectedPointA], pointB = graph.getGraph()[selectedPointB];
    std::vector<std::pair<int, int>> path = dijkstra.findShortestPath(pointA.from, pointB.from);
    std::cout<<path.size()<<std::endl;
    for (const auto& p : path) {
        visual.addSelectedPoint(p);
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
}
