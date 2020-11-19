#include <iostream>

#include "scc.h"

void FinishTimeTraverser::visit(int nodeId)
{
    // do nothing
}

void FinishTimeTraverser::leave(int nodeId)
{
    orderToIndex.insert(make_pair(++t, nodeId));
}

void FinishTimeTraverser::traverse(NodeVisitor *visitor)
{
    for (auto const& entry: orderToIndex)
    {
        if (!graph.getNode(entry.second)->isVisited())
        {
            dfs(entry.second, visitor);
        }
    }
}

FinishTimeTraverser::FinishTimeTraverser(Graph graph) : DfsTraverser(graph) { }

void SccCalculator::visit(int nodeId) {
    if (currentLabel == -1) {
        currentLabel = nodeId;
    }
    currentSize++;
}

void SccCalculator::leave(int nodeId) {
    if (nodeId == currentLabel) {
        sizes.push_back(currentSize);
        currentLabel = -1;
        currentSize = 0;
    }
}

vector<int> SccCalculator::getSizes() {
    return sizes;
}
