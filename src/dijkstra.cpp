#include "dijkstra.h"
#include <queue>
#include <limits>
#include <unordered_map>

Dijkstra::Dijkstra(const CityGraph& graph) : graph(graph) {}

std::vector<int> Dijkstra::findShortestPath(int start, int end) {
    std::vector<int> distances(graph.cityMap.size(), std::numeric_limits<int>::max());
    distances[start] = 0;
    std::unordered_map<int, int> previous;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<>> queue;
    queue.emplace(0, start);

    while (!queue.empty()) {
        int currentDistance = queue.top().first;
        int currentNode = queue.top().second;
        queue.pop();

        if (currentNode==end)
            break;

        if (currentDistance>distances[currentNode])
            continue;

        for (auto road:graph.cityMap[currentNode]) {
            int neighbor = road.to;
            int newDistance = currentDistance + road.length + road.traffic;

            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                previous[neighbor] = currentNode;
                queue.emplace(newDistance, neighbor);
            }
        }
    }

    std::vector<int> path;
    for (int at=end; at!=start; at=previous[at]){
        if (previous.find(at) == previous.end())
            return {};
        path.push_back(at);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}
