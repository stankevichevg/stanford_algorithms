#ifndef STANFORD_ALGORITHMS_NODE_H
#define STANFORD_ALGORITHMS_NODE_H

#include <vector>

using namespace std;

class Node {
private:
    vector<int> adjNodes;
public:
    Node();
    void addAdjNode(int adjNodeId);
    vector<int> getAdjNodes();
};

#endif

