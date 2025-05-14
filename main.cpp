#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{   
    graph g1 {"A", "B", "C"};
    graph g2 = std::move(g1);

    std::cout << g2.getVertexes();
    std::cout << g1.getVertexes();
    
    return 0;
}