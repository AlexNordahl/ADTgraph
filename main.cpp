#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{    
    graph g {"A", "B", "C"};

    g.addEdge("A", "B", 10);
    g.addEdge("B", "A", 15);

    g.createDotFile();

    return 0;
}