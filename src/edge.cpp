#include "edge.h"

int Edge::getLength() const
{
    return length;
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
