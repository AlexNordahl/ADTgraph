#include "graph.hpp"

graph::graph()
{
    _matrix = new std::vector<std::vector<int>>();
    _vertexes = new std::vector<std::pair<std::string, int>>();
    _edges = new std::vector<edge>();
}

graph::~graph()
{
    delete _matrix;
}

void graph::addVertex(std::string x)
{
    _matrix->push_back(std::vector<int>(++_size, 0));

    _vertexes->push_back(std::pair(x, 0));
    for (auto& row : *_matrix)
    {
        row.push_back(0);
    }
}

void graph::removeVertex(std::string x)
{
    int index = -1;

    int i = 0;
    for (const auto& vertex : *_vertexes)
    {
        if (vertex.first == x)
        {
            index = i;
            break;
        }
        i++;
    }

    if (index == -1)
    {
        std::cerr << "Trying to remove non-existing element" << std::endl;
        return;
    }

    _vertexes->erase(_vertexes->begin() + index);

    _matrix->erase(_matrix->begin() + index);

    for (auto& row : *_matrix)
    {
        row.erase(row.begin() + index);
    }

    _size--;
}

void graph::setVertexValue(std::string x, int v)
{
    for (auto& vertex : *_vertexes)
    {
        if (vertex.first == x)
        {
            vertex.second = v;
            return;
        }
    }

    std::cerr << "Trying to set non-existing element" << std::endl;
    
}

int graph::getVertexValue(std::string x) const
{
    for (auto& vertex : *_vertexes)
    {
        if (vertex.first == x)
            return vertex.second;
    }

    return -1;
}


void graph::addEdge(std::string x, std::string y)
{
    int xIndex = -1;
    int yIndex = -1;

    int i = 0;
    for (const auto& vertex : *_vertexes)
    {
        if (vertex.first == x)
            xIndex = i;

        if (vertex.first == y)
            yIndex = i;
        
        i++;
    }

    if (xIndex == -1 and yIndex ==-1)
    {
        std::cerr << "Error: Vertexes not found" << std::endl;
        return;
    }

    _matrix->at(xIndex).at(yIndex) = 1;
    _matrix->at(yIndex).at(xIndex) = 1;

    _edges->push_back(edge(x, y, DEFAULT_EDGE_VALUE));
}

void graph::removeEdge(std::string x, std::string y)
{
    int index = -1;

    int i = 0;
    for (const auto& edge : *_edges)
    {
        if (edge.x == x and edge.y == y)
        {
            index = i;
            break;
        }
        i++;
    }

    _edges->erase(_edges->begin() + index);
    
}

void graph::setEdgeValue(std::string x, std::string y, int v)
{
    for (auto& edge : *_edges)
    {
        if (edge.x == x and edge.y == y)
        {
            edge.value = v;
            return;
        }
    }
}

int graph::getEdgeValue(std::string x, std::string y) const
{
    for (const auto& edge : *_edges)
        if (edge.x == x and edge.y == y)
            return edge.value;

    return -1;
}


bool graph::adjacent(std::string x, std::string y) const
{
    for (const auto& edge : *_edges)
        if (edge.x == x and edge.y == y)
            return true;

    return false;
}

std::vector<std::string> graph::neighbours(std::string x) const
{   
    std::vector<std::string> result;

    for (const auto& edge : *_edges)
    {
        std::string currentX = edge.x;
        std::string currentY = edge.y;
        
        if (currentX == x)
            result.push_back(currentX);

        if (currentY == x)
            result.push_back(currentY);
    }

    return result;
}


void graph::printMatrix()
{
    for (const auto& vertex : *_vertexes)
        std::cout << vertex.first << " ";
    std::cout << std::endl;

    int i = 0;
    for (const auto& column : *_matrix)
    {   
        for (size_t j = 0; j < _size; j++)
            std::cout << column.at(i) << " ";
        std::cout << std::endl;
        i++;
    }
}

void graph::printVertexes()
{
    for (auto& pair : *_vertexes)
        std::cout << pair.first << ": " << pair.second << std::endl;
}

std::string graph::getVertexes()
{
    if (_vertexes->empty())
        return "No vertexes";

    std::string result {};

    for (const auto& elem : *_vertexes)
        result += elem.first + " value " + std::to_string(elem.second) + "\n";
    
    return result;
}

std::string graph::getEdges()
{
    if (_vertexes->empty())
        return "No edges";

    std::string result {};

    for (const auto& elem : *_edges)
        result += elem.x + " -> " + elem.y + " value: " + std::to_string(elem.value) + "\n";
    
    return result;
}