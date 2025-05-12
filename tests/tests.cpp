#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include "../graph.hpp"


TEST(Vertexes, Equals)
{
    graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.setVertexValue("A", 10);
    g.setVertexValue("B", 15);
    g.setVertexValue("C", 20);
    g.setVertexValue("D", 25);

    g.removeVertex("B");

    std::vector<std::pair<std::string, int>> temp {std::pair("A", 10), std::pair("C", 20), std::pair("D", 25)};

    EXPECT_EQ(g.getVertexes(), temp);
}