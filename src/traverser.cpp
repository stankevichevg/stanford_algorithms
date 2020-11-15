#include <iostream>

#include "traverser.h"

Traverser::Traverser(Graph graph) : graph(graph) {
}

DfsTraverser::DfsTraverser(Graph graph) : Traverser(graph) {
    this->nodesStack = stack<int>();
    this->exploredNodes = set<int>();
}

void DfsTraverser::dfsTraverse(int startNode, NodeVisitor *visitor) {
    // mark node as explored and visit it
    nodesStack.push(startNode);
    while (!nodesStack.empty()) {
        int nodeId = nodesStack.top();
        nodesStack.pop();
        // mark node as explored and visit it
        exploredNodes.insert(nodeId);
        visitor->visit(nodeId);
        // for each edge
        for (int & adjNodeIt : graph.getNode(nodeId).getAdjNodes()) {
            // if adj node is unexplored
            if (exploredNodes.find(adjNodeIt) == exploredNodes.end()) {
                exploredNodes.insert(adjNodeIt);
                nodesStack.push(adjNodeIt);
            }
        }
    }
}

void DfsTraverser::traverse(NodeVisitor *visitor) {
    for (const auto &node : graph.getAllNodes()) {
        if (this->exploredNodes.find(node.first) == this->exploredNodes.end())
        {
            dfsTraverse(node.first, visitor);
        }
    }
}
