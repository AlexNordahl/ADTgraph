#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include "../graph.hpp"


TEST(Copy_constructor, Equals)
{
    graph g1 {"A", "B", "C"};

    g1.addEdge("A", "B", 10);
    g1.addEdge("B", "C", 15);
    
    graph g2 = g1;

    EXPECT_EQ(g1.getVertexes(), g2.getVertexes());
}

TEST(Copy_assignment_operator, Equals)
{
    graph g1 {"A", "B", "C"};
    graph g2 {"D", "E", "F"};
    
    g2 = g1;

    EXPECT_EQ(g1.getVertexes(), g2.getVertexes());
}

TEST(Move_constructor, TransfersResources)
{
    graph g1 {"A", "B", "C"};

    auto expected = g1.getVertexes();

    graph g2 = std::move(g1);

    EXPECT_EQ(g2.getVertexes(), expected);

    EXPECT_TRUE(g1.getVertexes() == "No vertexes");
}

TEST(Move_assignment_operator, TransfersResources)
{
    graph g1 {"A", "B", "C"};
    graph g2 {"D", "E", "F"};

    auto expected = g1.getVertexes();

    g2 = std::move(g1);

    EXPECT_EQ(g2.getVertexes(), expected);

    EXPECT_TRUE(g1.getVertexes() == "No vertexes");
}