#ifndef STANFORD_ALGORITHMS_GRAPH_H
#define STANFORD_ALGORITHMS_GRAPH_H

#include <map>

#include "node.h"

class Graph {
protected:
    bool directed;
    map<int, Node> nodes;
protected:
    void checkNodeExists(int id);
public:
    Graph(bool directed);
    void addNode(int id);
    void addEdge(int s, int e);
    Node getNode(int id);
    map<int, Node> getAllNodes();
    Graph revert();
};

#endif
