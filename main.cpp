#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{   
    graph g1 {"A", "B", "C"};

    g1.addEdge("A", "B", 10);
    g1.addEdge("B", "C", 15);
    g1.addEdge("C", "A", 20);

    graph g2 = g1;

    g2.printMatrix();

    return 0;
}