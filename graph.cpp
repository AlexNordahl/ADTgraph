#include "graph.hpp"

graph::graph() = default;

graph::graph(std::initializer_list<std::string> list) : graph()
{
    for (const auto& arg : list)
        addVertex(arg);
}

graph::~graph() = default;

graph::graph(const graph &rhs) : graph()
{
    for (const std::vector<int> elem : rhs._matrix)
    {
        std::vector<int> temp = std::move(elem);
        _matrix.push_back(temp);
    }

    for (const std::pair<std::string, int> elem : rhs._vertexes)
        _vertexes.push_back(elem);

    for (const edge elem : rhs._edges)
        _edges.push_back(elem);
    
    _size = rhs._size;
}
 
graph &graph::operator=(const graph &rhs)
{
    _matrix.clear();
    _vertexes.clear();
    _edges.clear();

    for (const std::vector<int> elem : rhs._matrix)
    {
        std::vector<int> temp = std::move(elem);
        _matrix.push_back(temp);
    }

    for (const std::pair<std::string, int> elem : rhs._vertexes)
        _vertexes.push_back(elem);

    for (const edge elem : rhs._edges)
        _edges.push_back(elem);
    
    _size = rhs._size;

    return *this;
}

graph::graph(graph &&rhs) noexcept
{
    _matrix = std::move(rhs._matrix);
    _vertexes = std::move(rhs._vertexes);
    _edges = std::move(rhs._edges);
    _size = rhs._size;

    rhs._size = 0;
}

graph& graph::operator=(graph &&rhs) noexcept
{
    if (this == &rhs)
        return *this;

    _matrix = std::move(rhs._matrix);
    _vertexes = std::move(rhs._vertexes);
    _edges = std::move(rhs._edges);
    _size = std::move(rhs._size);
    rhs._size = 0;

    return *this;
}


void graph::addVertex(std::string x)
{
    _matrix.push_back(std::vector<int>(++_size, 0));

    _vertexes.push_back(std::pair(x, 0));
    for (auto& row : _matrix)
        row.push_back(0);
}

void graph::removeVertex(std::string x)
{
    int index = -1;

    int i = 0;
    for (const auto& vertex : _vertexes)
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

    _vertexes.erase(_vertexes.begin() + index);

    _matrix.erase(_matrix.begin() + index);

    for (auto& row : _matrix)
    {
        row.erase(row.begin() + index);
    }

    _size--;
}

void graph::setVertexValue(std::string x, int v)
{
    for (auto& vertex : _vertexes)
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
    for (auto& vertex : _vertexes)
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
    for (const auto& vertex : _vertexes)
    {
        if (vertex.first == x)
            xIndex = i;

        if (vertex.first == y)
            yIndex = i;
        
        i++;
    }

    if (xIndex == -1 and yIndex == -1)
    {
        std::cerr << "Error: Vertexes not found" << std::endl;
        return;
    }

    _matrix.at(xIndex).at(yIndex) = 1;
    _matrix.at(yIndex).at(xIndex) = 1;

    _edges.push_back(edge(x, y, DEFAULT_EDGE_VALUE));
}

void graph::addEdge(std::string x, std::string y, int v)
{
    addEdge(x, y);
    setEdgeValue(x, y, v);
}

void graph::removeEdge(std::string x, std::string y)
{
    int index = -1;

    int i = 0;
    for (const auto& edge : _edges)
    {
        if (edge.x == x and edge.y == y)
        {
            index = i;
            break;
        }
        i++;
    }

    _edges.erase(_edges.begin() + index);
    
}

void graph::setEdgeValue(std::string x, std::string y, int v)
{
    for (auto& edge : _edges)
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
    for (const auto& edge : _edges)
        if (edge.x == x and edge.y == y)
            return edge.value;

    return -1;
}


bool graph::adjacent(std::string x, std::string y) const
{
    for (const auto& edge : _edges)
        if (edge.x == x and edge.y == y)
            return true;

    return false;
}

std::vector<std::string> graph::neighbours(std::string x) const
{   
    std::vector<std::string> result;

    for (const auto& edge : _edges)
    {
        std::string currentX = edge.x;
        std::string currentY = edge.y;
        
        if (currentX == x)
            result.push_back(currentY);
        else if (currentY == x)
            result.push_back(currentX);
    }

    return result;
}


void graph::printMatrix()
{
    for (const auto& vertex : _vertexes)
        std::cout << vertex.first << " ";
    std::cout << std::endl;
    
    for (const auto& column : _matrix)
    {      
        for (size_t j = 0; j < _size; j++)
            std::cout << column.at(j) << " ";
        std::cout << std::endl;
    }
}

void graph::printVertexes()
{
    for (auto& pair : _vertexes)
        std::cout << pair.first << ": " << pair.second << std::endl;
}

std::string graph::getVertexes()
{
    if (_vertexes.empty())
        return "No vertexes";

    std::string result {};

    for (const auto& elem : _vertexes)
        result += elem.first + " value " + std::to_string(elem.second) + "\n";
    
    return result;
}

std::string graph::getEdges()
{
    if (_vertexes.empty())
        return "No edges";

    std::string result {};

    for (const auto& elem : _edges)
        result += elem.x + " -> " + elem.y + " value: " + std::to_string(elem.value) + "\n";
    
    return result;
}

void graph::createDotFile(int size, int dpi)
{
    std::unordered_set<std::string> vertexes;

    std::ofstream dotFile("graph.dot");

    dotFile << "digraph {\n";
    dotFile << "\tsize=\"" << size << "," << size << "\";\n";
    dotFile << "\tdpi=" << dpi << ";\n";

    for (const auto& edge : _edges)
    {
        dotFile << "\t " << edge.x << " -> " << edge.y << "[label = " << edge.value << "];\n";
        vertexes.insert(edge.x);
        vertexes.insert(edge.y);
    }

    for (const auto& vertex : _vertexes)
    {
        if (!vertexes.contains(vertex.first))
            dotFile << "\t " << vertex.first << "\n";
    }
    
    dotFile << "}";

    dotFile.close();
}