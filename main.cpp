#include "Graph.h"
#include "Heap.h"

int main() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addEdge("A", "B", 5);
    g.addEdge("B", "C", 10);
    g.addEdge("A", "C", 15);

    g.displayMap();

    std::cout << "Shortest path from A to C: " << g.dijkstra("A", "C") << std::endl;

    return 0;
}
