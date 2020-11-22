#include "edge.h"

int Edge::getLength() const
{
    return length;
}

Edge::Edge(int endNode, int length) : endNode(endNode), length(length) {}

int Edge::getEndNode() const
{
    return endNode;
}
