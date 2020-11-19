#include "node.h"

Node::Node()
{
    this->adjNodes = vector<int>();
}

void Node::addAdjNode(int adjNodeId)
{
    adjNodes.push_back(adjNodeId);
}

vector<int> Node::getAdjNodes()
{
    return adjNodes;
}

void Node::markVisited() {
    visited = true;
}

void Node::markNotVisited() {
    visited = false;
}

bool Node::isVisited() {
    return visited;
}
