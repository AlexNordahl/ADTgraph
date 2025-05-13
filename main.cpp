#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{    
    graph g1 {"A", "B", "C"};

    graph g2;

    g2 = g1;

    g2.addEdge("A", "B");
    g2.addEdge("B", "C");
    g2.addEdge("C", "A");

    g2.printMatrix();
    g2.createDotFile();

    return 0;
}