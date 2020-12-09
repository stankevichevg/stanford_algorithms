#include "node.h"

Node::Node()
{
    this->outputEdges = vector<Edge>();
    this->inputEdges = vector<Edge>();
}

void Node::addOutputEdge(const Edge& edge)
{
    outputEdges.push_back(edge);
}

void Node::addInputEdge(const Edge& edge)
{
    inputEdges.push_back(edge);
}

vector<Edge> * Node::getOutputEdges()
{
    return &outputEdges;
}

vector<Edge> * Node::getInputEdges()
{
    return &inputEdges;
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

int Node::getPathLength() const {
    return pathLength;
}

void Node::setPathLength(int pathLength) {
    Node::pathLength = pathLength;
}

void Node::resetState() {
    markNotVisited();
    setPathLength(0);
}
