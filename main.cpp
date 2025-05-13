#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{    
    graph g1 {"A", "B", "C"};

    graph g2;

    g2 = g1;

    g2.addEdge("A", "B", 10);
    g2.addEdge("B", "C", 15);
    g2.addEdge("C", "A", 20);

    g2.printMatrix();
    g2.createDotFile();

    return 0;
}