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
    void removeNode(int id);
    void addEdge(int s, int e);
    void addEdge(int s, int e, int length);
    void removeEdges(int s, int e);
    Node * getNode(int id);
    map<int, Node> getAllNodes();
    Graph revert();
    void markAllNodesNotVisited();
    Graph copy();
};

#endif
