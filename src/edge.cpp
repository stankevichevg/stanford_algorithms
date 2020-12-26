#include "edge.h"

int Edge::getLength()
{
    return length;
}

void Edge::setLength(int length)
{
    this->length = length;
}

Edge::Edge(int startNode, int endNode, int length) : startNode(startNode), endNode(endNode), length(length) {}

int Edge::getStartNode() const
{
    return startNode;
}

int Edge::getEndNode() const
{
    return endNode;
}
