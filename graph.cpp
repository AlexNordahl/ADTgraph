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

    for (size_t i = 0; i < _vertexes->size(); i++)
    {
        if (_vertexes->at(i).first == x)
        {
            index = i;
            break;
        }
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
    for (size_t i = 0; i < (*_vertexes).size(); i++)
    {
        if (_vertexes->at(i).first == x)
        {
            _vertexes->at(i).second = v;
            return;
        }
    }
    
}

int graph::getVertexValue(std::string x) const
{
    for (size_t i = 0; i < _vertexes->size(); i++)
    {
        if (_vertexes->at(i).first == x)
            return _vertexes->at(i).second;
    }

    return -1;
}


void graph::addEdge(std::string x, std::string y)
{
    int xIndex = -1;
    int yIndex = -1;

    for (size_t i = 0; i < _vertexes->size(); i++)
    {
        if (_vertexes->at(i).first == x)
            xIndex = i;

        if (_vertexes->at(i).first == y)
            yIndex = i;
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

    for (size_t i = 0; i < _edges->size(); i++)
    {
        if (_edges->at(i).x == x and _edges->at(i).y == y)
        {
            index = i;
            break;
        }
    }

    _edges->erase(_edges->begin() + index);
    
}

void graph::setEdgeValue(std::string x, std::string y, int v)
{
    for (size_t i = 0; i < _edges->size(); i++)
    {
        if (_edges->at(i).x == x and _edges->at(i).y == y)
        {
            _edges->at(i).value = v;
            return;
        }
    }
}

int graph::getEdgeValue(std::string x, std::string y) const
{
    for (size_t i = 0; i < _edges->size(); i++)
        if (_edges->at(i).x == x and _edges->at(i).y == y)
            return _edges->at(i).value;

    return -1;
}


bool graph::adjacent(std::string x, std::string y) const
{
    for (size_t i = 0; i < _edges->size(); i++)
        if (_edges->at(i).x == x and _edges->at(i).y == y)
            return true;

    return false;
}

std::vector<std::string> graph::neighbours(std::string x) const
{   
    std::vector<std::string> result;

    for (size_t i = 0; i < _edges->size(); i++)
    {
        std::string currentX = _edges->at(i).x;
        std::string currentY = _edges->at(i).y;
        
        if (currentX == x)
            result.push_back(currentX);

        if (currentY == x)
            result.push_back(currentY);
    }

    return result;
}


void graph::printMatrix()
{
    for (auto& vertex : *_vertexes)
        std::cout << vertex.first << " ";
    std::cout << std::endl;

    for (size_t i = 0; i < _size; i++)
    {   
        for (size_t j = 0; j < _size; j++)
            std::cout << (_matrix->at(j)).at(i) << " ";
        std::cout << std::endl;
    }
}

void graph::printVertexes()
{
    for (auto& pair : *_vertexes)
        std::cout << pair.first << ": " << pair.second << std::endl;
}