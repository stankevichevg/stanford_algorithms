#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

#include "graph.h"

Graph readGraph(const std::string& filename)
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
            graph.addEdge(otherNodeId, nodeId, edgeLength);
        }
    }
    return graph;
}

int main()
{
    Graph graph = readGraph("../data/prims_edges.txt");
    set<int> X;
    set<int> V;
    X.insert(1);
    for (int i = 2; i <= graph.getAllNodes().size(); i++)
    {
        V.insert(i);
    }
    long sum;
    while (X.size() != graph.getAllNodes().size())
    {
        int minEdgeLength = INT32_MAX;
        int minEdgeEndNode;
        for (int nodeId : X)
        {
            for (auto edge : *graph.getNode(nodeId)->getOutputEdges())
            {
                bool nodeIsNotIncluded = V.find(edge.getEndNode()) != V.end();
                if (nodeIsNotIncluded && (edge.getLength() < minEdgeLength))
                {
                    minEdgeLength = edge.getLength();
                    minEdgeEndNode = edge.getEndNode();
                }
            }
        }
        sum += minEdgeLength;
        V.erase(minEdgeEndNode);
        X.insert(minEdgeEndNode);
    }
    cout << "Sum of minimum spanning tree edge lengths: " << sum;
}
