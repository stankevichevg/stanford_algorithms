#ifndef STANFORD_ALGORITHMS_NODE_H
#define STANFORD_ALGORITHMS_NODE_H

#include <vector>
#include "edge.h"

using namespace std;

class Node {
private:
    vector<Edge> outputEdges;
    bool visited = false;
public:
    Node();
    void addOutputEdge(const Edge& edge);
    vector<Edge> getOutputEdges();
    void markVisited();
    void markNotVisited();
    bool isVisited();
};

#endif

