#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{    
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");

    g.addEdge("A", "B", 10);
    g.addEdge("A", "C", 15);

    g.createDotFile();

    return 0;
}