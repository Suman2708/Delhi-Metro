#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <string>

class Graph {
    struct Vertex {
        std::unordered_map<std::string, int> nbrs;
    };

    std::unordered_map<std::string, Vertex> vtces;

public:
    void addVertex(const std::string &vname) {
        vtces[vname] = Vertex();
    }

    void addEdge(const std::string &vname1, const std::string &vname2, int value) {
        vtces[vname1].nbrs[vname2] = value;
        vtces[vname2].nbrs[vname1] = value;
    }

    void displayMap() const {
        for (const auto &v : vtces) {
            std::cout << v.first << " => ";
            for (const auto &nbr : v.second.nbrs) {
                std::cout << "(" << nbr.first << ", " << nbr.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    int dijkstra(const std::string &src, const std::string &dst) {
        std::unordered_map<std::string, int> distances;
        for (const auto &v : vtces) {
            distances[v.first] = std::numeric_limits<int>::max();
        }
        distances[src] = 0;

        using P = std::pair<int, std::string>;
        std::priority_queue<P, std::vector<P>, std::greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dist, current] = pq.top();
            pq.pop();

            if (current == dst) return dist;

            for (const auto &nbr : vtces[current].nbrs) {
                int newDist = dist + nbr.second;
                if (newDist < distances[nbr.first]) {
                    distances[nbr.first] = newDist;
                    pq.push({newDist, nbr.first});
                }
            }
        }

        return -1; // No path found
    }
};
