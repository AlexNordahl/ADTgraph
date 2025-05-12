#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>

#define DEFAULT_EDGE_VALUE 1

class graph
{
private:
    struct edge
    {
        edge (std::string x, std::string y, int value)
        : x(x), y(y), value(value) {}

        std::string x, y;
        int value;
    };

    std::vector<std::vector<int>> *_matrix;
    std::vector<std::pair<std::string, int>> *_vertexes;
    std::vector<edge> *_edges;
    int _size {};
public:
    graph();
    ~graph();

    void addVertex(std::string x);
    void removeVertex(std::string x);
    void setVertexValue(std::string x, int v);
    int getVertexValue(std::string x) const;

    void addEdge(std::string x, std::string y);
    void removeEdge(std::string x, std::string y);
    void setEdgeValue(std::string x, std::string y, int v);
    int getEdgeValue(std::string x, std::string y) const;

    bool adjacent(std::string x, std::string y) const;
    std::vector<std::string> neighbours(std::string x) const;
    
    void printMatrix();
    void printVertexes();
};

#endif