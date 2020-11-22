#include <iostream>
#include <fstream>
#include <sstream>

#include "graph.h"
#include "shortest_path.h"

Graph readGraph(std::string filename)
{
    std::ifstream myFile(filename);
    if(!myFile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }
    Graph graph;
    std::string line;
    int nodeId, otherNodeId, edgeLength;
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);
        ss >> nodeId;
        graph.addNode(nodeId);
        while(ss >> otherNodeId)
        {
            graph.addNode(otherNodeId);
            ss.ignore();
            ss >> edgeLength;
            graph.addEdge(nodeId, otherNodeId, edgeLength);
        }
    }
    return graph;
}

int main()
{
    Graph graph = readGraph("../data/assignment_2_graph.txt");
    DijkstraBruteForceCalculator dijkstra(&graph);
    dijkstra.calculate(1);
    int vertices[10] = {7,37,59,82,99,115,133,165,188,197};
    for (int i = 0; i < 9; i++)
    {
        cout << graph.getNode(vertices[i])->getPathLength() << ",";
    }
    cout << graph.getNode(vertices[9])->getPathLength() << endl;
}
