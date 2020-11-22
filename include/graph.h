#ifndef STANFORD_ALGORITHMS_GRAPH_H
#define STANFORD_ALGORITHMS_GRAPH_H

#include <map>

#include "node.h"

class Graph {
protected:
    map<int, Node> nodes;
protected:
    void checkNodeExists(int id);
public:
    Graph();
    void addNode(int id);
    void addEdge(int s, int e);
    void addEdge(int s, int e, int length);
    Node * getNode(int id);
    map<int, Node> getAllNodes();
    Graph revert();
    void markAllNodesNotVisited();
};

#endif
