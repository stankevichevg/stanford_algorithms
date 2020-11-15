#include "node.h"

Node::Node() {
    this->adjNodes = vector<int>();
}

void Node::addAdjNode(int adjNodeId) {
    adjNodes.push_back(adjNodeId);
}

vector<int> Node::getAdjNodes() {
    return adjNodes;
}
