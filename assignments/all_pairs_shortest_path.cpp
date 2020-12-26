#include <iostream>
#include <fstream>
#include <sstream>

#include "shortest_path.h"

void printSolutionResult(int result);

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
        graph.addNode(nodeId - 1);
        while(ss >> otherNodeId)
        {
            graph.addNode(otherNodeId - 1);
            ss.ignore();
            ss >> edgeLength;
            graph.addEdge(nodeId - 1, otherNodeId - 1, edgeLength);
        }
    }
    return graph;
}

int findMinPath(Graph *graph)
{
    int minLength = INT32_MAX;
    for (auto node : graph->getAllNodes())
    {
        if (minLength > node.second.getPathLength())
        {
            minLength = node.second.getPathLength();
        }
    }
    return minLength;
}

int solveProblem(Graph *graph)
{
    // create G' as graph copy
    Graph bfGraph = graph->copy();
    // add new vertex to new graph and add edge to each vertex from it
    int tempNode = bfGraph.getAllNodes().size();
    bfGraph.addNode(tempNode);
    for (const auto& node : bfGraph.getAllNodes())
    {
        if (node.first != tempNode)
        {
            bfGraph.addEdge(tempNode, node.first, 0);
        }
    }
    // run Bellman-Ford algorithm, mark all vertexes by Pi - shortest path length from additional vertex
    BellmanFordCalculator bellmanFordCalculator(&bfGraph);
    bellmanFordCalculator.calculate(tempNode);
    if (bellmanFordCalculator.isCycleDetected())
    {
        return INT32_MAX;
    }
    else
    {
        return findMinPath(&bfGraph);
    }
}

void printSolutionResult(int result) {
    if (result == INT32_MAX)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << "" << result << endl;
    }
}

int main()
{
    Graph graph = readGraph("../data/g1.txt");
    int result = solveProblem(&graph);
    printSolutionResult(result);

    graph = readGraph("../data/g2.txt");
    result = solveProblem(&graph);
    printSolutionResult(result);

    graph = readGraph("../data/g3.txt");
    result = solveProblem(&graph);
    printSolutionResult(result);
}
