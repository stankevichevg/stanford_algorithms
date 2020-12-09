#include <iostream>
#include <fstream>
#include <sstream>

#include "graph.h"
#include "contraction.h"

Graph readGraph(std::string filename)
{
    std::ifstream myFile(filename);
    if(!myFile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }
    Graph graph;
    std::string line;
    int nodeId, otherNodeId;
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);
        ss >> nodeId;
        graph.addNode(nodeId);
        while(ss >> otherNodeId)
        {
            graph.addNode(otherNodeId);
            graph.addEdge(nodeId, otherNodeId);
        }
    }
    return graph;
}

void printGraph(Graph* graph)
{
    for (auto node : graph->getAllNodes()) {
        cout << "Node:" << node.first << endl;
        cout << "Inputs: " << endl;
        for (auto inode : *node.second.getInputEdges()) {
            cout << inode.getStartNode() << " ";
        }
        cout << endl;
        cout << "Outputs: " << endl;
        for (auto inode : *node.second.getOutputEdges()) {
            cout << inode.getEndNode() << " ";
        }
        cout << endl;
    }
}

int main()
{
    int minCutSize = INT32_MAX;
    for (int i = 0; i < 100; i++)
    {
        Graph graph = readGraph("../data/kargerMinCut.txt");
        RandomGraphContractor randomGraphContractor(&graph);
        randomGraphContractor.contract(2);
        auto node = graph.getAllNodes().begin()->second;
        int cutSize = node.getOutputEdges()->size();
        if (minCutSize > cutSize)
        {
            minCutSize = cutSize;
            printGraph(&graph);
        }
        cout << "(" << i << ")" << "Min cut is: " << minCutSize << endl;
    }
}