#include <iostream>
#include "../include/graph.h"
#include "../include/fileReader.h"
#include "../include/visual.h"
#include <SFML/Graphics.hpp>

int main(){
    Reader reader;
    Graph graph = reader.readGraph("../data/input.txt");

    std::vector<Graph::Road> asd = graph.getGraph();
    sf::RenderWindow window(sf::VideoMode(800, 600), "route opt");
    Visual visual(window, graph);
    visual.render();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}