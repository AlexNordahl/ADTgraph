#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include "../graph.hpp"


TEST(Vertexes_one, Equals)
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

    std::string temp {"A value 10\nC value 20\nD value 25\n"};

    EXPECT_EQ(g.getVertexes(), temp);
}

TEST(Vertexes_two, Equals)
{
    graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.removeVertex("A");
    g.removeVertex("B");
    g.removeVertex("C");
    g.removeVertex("D");

    std::string temp {"No vertexes"};

    EXPECT_EQ(g.getVertexes(), temp);
}

TEST(Edges, Equals)
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

    std::string temp {"A -> B value: 10\nD -> A value: 25\n"};

    EXPECT_EQ(g.getEdges(), temp);
}

TEST(Adjacent, True)
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

    EXPECT_TRUE(g.adjacent("A", "B"));
}

TEST(Neighbours_one, Equals)
{
    graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("A", "D");

    std::vector<std::string> temp {"B", "C", "D"};

    EXPECT_EQ(g.neighbours("A"), temp);
}

TEST(Neighbours_two, Equals)
{
    graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("A", "D");

    std::vector<std::string> temp {"A"};

    EXPECT_EQ(g.neighbours("B"), temp);
}