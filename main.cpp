#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{
    graph g1;
    g1.addVertex("A");
    g1.addVertex("B");
    g1.addVertex("C");
    g1.setVertexValue("A", 10);
    g1.setVertexValue("B", 5);
    g1.addEdge("A", "B");
    g1.printMatrix();
    g1.printVertexes();
    return 0;
}