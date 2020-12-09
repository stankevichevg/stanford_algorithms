#include <iostream>

#include "traverser.h"

Traverser::Traverser(Graph graph) : graph(graph) { }

DfsTraverser::DfsTraverser(Graph graph) : Traverser(graph)
{
}

void DfsTraverser::dfs(int startNode, NodeVisitor *visitor)
{
    // mark node as explored and visit it
    graph.getNode(startNode)->markVisited();
    visitor->visit(startNode);
    // for each edge
    for (const auto edge : *graph.getNode(startNode)->getOutputEdges())
    {
        // if adj node is unexplored
        if (!graph.getNode(edge.getEndNode())->isVisited())
        {
            dfs(edge.getEndNode(), visitor);
        }
    }
    visitor->leave(startNode);
}

void DfsTraverser::traverse(NodeVisitor *visitor)
{
    for (const auto &node : graph.getAllNodes())
    {
        if (!graph.getNode(node.first)->isVisited())
        {
            dfs(node.first, visitor);
        }
    }
}
