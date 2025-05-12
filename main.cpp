#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{    
    graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.addEdge("A", "B");
    g.addEdge("B", "C");
    g.addEdge("C", "D");
    g.addEdge("D", "A");

    g.setEdgeValue("A", "B", 10);
    g.setEdgeValue("B", "C", 15);
    g.setEdgeValue("C", "D", 20);
    g.setEdgeValue("D", "A", 25);

    g.removeEdge("B", "C");
    g.removeEdge("C", "D");
    std::cout << g.getEdges();

    return 0;
}