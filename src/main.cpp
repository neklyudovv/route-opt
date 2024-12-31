#include "../include/graph.h"
#include "../include/fileReader.h"
#include "../include/visual.h"
#include "../include/actionHandler.h"
#include <SFML/Graphics.hpp>

int main(){
    Reader reader;
    Graph graph = reader.readGraph("../data/input.txt");

    std::vector<Graph::Road> asd = graph.getGraph();
    sf::RenderWindow window(sf::VideoMode(800, 600), "route opt");
    Visual visual(window, graph);

    Dijkstra dijkstra(graph);

    Handler handler(window, graph, visual, dijkstra);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            handler.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }
        visual.render();
    }

    return 0;
}