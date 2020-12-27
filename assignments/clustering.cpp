#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "disjoint_set.h"

using namespace std;

struct Edge
{
    int firstNode;
    int secondNode;
    int cost;
    Edge(int firstNode, int secondNode, int cost)
    {
        this->firstNode = firstNode;
        this->secondNode = secondNode;
        this->cost = cost;
    }
};

pair<int, vector<Edge>> readGraph(const std::string& filename)
{
    std::ifstream myFile(filename);
    if(!myFile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    int nodesNumber;
    int nodeId, otherNodeId, edgeCost;
    vector<Edge> edges;

    std::string line;
    std::getline(myFile, line);
    std::stringstream ss(line);
    ss >> nodesNumber;
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);
        ss >> nodeId;
        ss >> otherNodeId;
        ss >> edgeCost;
        edges.push_back(Edge(nodeId - 1, otherNodeId - 1, edgeCost));
    }
    return pair(nodesNumber, edges);
}

int main()
{
    pair<int, vector<Edge>> graph = readGraph("../data/clustering1.txt");
    vector<Edge> edges = graph.second;
    sort(edges.begin(), edges.end(), [](const Edge& le, const Edge& re) {
        return le.cost < re.cost;
    });
    DisjointSet clusters(graph.first);
    for (Edge edge : edges)
    {
        int firstNodeCluster = clusters.find(edge.firstNode);
        int secondNodeCluster = clusters.find(edge.secondNode);
        if (firstNodeCluster != secondNodeCluster)
        {
            if (clusters.size() == 4)
            {
                cout << "Maximum spacing of a 4-clustering: " << edge.cost << endl;
                return 0;
            }
            else
            {
                clusters.unionSets(firstNodeCluster, secondNodeCluster);
            }
        }
    }
}
