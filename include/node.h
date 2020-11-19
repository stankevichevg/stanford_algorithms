#ifndef STANFORD_ALGORITHMS_NODE_H
#define STANFORD_ALGORITHMS_NODE_H

#include <vector>

using namespace std;

class Node {
private:
    vector<int> adjNodes;
    bool visited = false;
public:
    Node();
    void addAdjNode(int adjNodeId);
    vector<int> getAdjNodes();
    void markVisited();
    void markNotVisited();
    bool isVisited();
};

#endif

