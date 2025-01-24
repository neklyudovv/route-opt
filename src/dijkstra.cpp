#include "../include/dijkstra.h"
#include <queue>
#include <limits>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct PairHash {
    template <class T1, class T2>
    int operator()(const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ (hash2 << 1);
    }
};

Dijkstra::Dijkstra(Graph& graph) : graph(graph) {}

std::vector<std::pair<int, int>> Dijkstra::findShortestPath(std::pair<int, int> start, std::pair<int, int> end) {
    std::unordered_map<std::pair<int, int>, int, PairHash> distances;
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, PairHash> previous;

    for (const auto& road : graph.getGraph()) {
        distances[road.from] = std::numeric_limits<int>::max();
        distances[road.to] = std::numeric_limits<int>::max();
    }
    distances[start] = 0;

    auto compare = [](const std::pair<int, std::pair<int, int>>& a, const std::pair<int, std::pair<int, int>>& b) {
        return a.first > b.first;
    };

    std::priority_queue<std::pair<int, std::pair<int, int>>,
            std::vector<std::pair<int, std::pair<int, int>>>,
            decltype(compare)> queue(compare);
    queue.emplace(0, start);

    while (!queue.empty()) {
        auto [currentDistance, currentNode] = queue.top();
        queue.pop();

        if (currentNode == end) break;
        if (currentDistance > distances[currentNode]) continue;

        for (const auto& road : graph.getGraph()) { // Перебор всех дорог
            if (road.from == currentNode) { // Только дороги из текущей вершины
                std::pair<int, int> neighbor = road.to;
                int newDistance = currentDistance + road.length + road.traffic;

                if (newDistance < distances[neighbor]) {
                    distances[neighbor] = newDistance;
                    previous[neighbor] = currentNode;
                    queue.emplace(newDistance, neighbor);
                }
            }
        }
    }

    std::vector<std::pair<int, int>> path;
    std::pair<int, int> at = end;
    while (at != start) {
        if (previous.find(at) == previous.end()) return {}; // Нет пути
        path.push_back(at);
        at = previous[at];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}
