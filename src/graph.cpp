#include "graph.h"
#include "edge.h"

Graph::Graph()
{
    this->nodes = map<int, Node>();
}

void Graph::checkNodeExists(int id)
{
    if (nodes.find(id) == nodes.end())
    {
        throw invalid_argument(string("Node does not exist: ").append(to_string(id)));
    }
}

void Graph::addNode(int id)
{
    if (nodes.find(id) == nodes.end()) {
        this->nodes[id] = Node();
    }
}

void Graph::addEdge(int s, int e, int length)
{
    checkNodeExists(s);
    checkNodeExists(e);
    Edge edge = Edge(s, e, length);
    nodes.find(s)->second.addOutputEdge(edge);
    nodes.find(e)->second.addInputEdge(edge);
}

void Graph::removeNode(int id)
{
    if (nodes.find(id) != nodes.end()) {
        this->nodes.erase(id);
    }
}

void Graph::removeEdges(int s, int e)
{
    Node* startNode = getNode(s);
    Node* endNode = getNode(e);
    auto it = startNode->getOutputEdges()->begin();
    while (it != startNode->getOutputEdges()->end())
    {
        if (it->getEndNode() == e)
        {
            it = startNode->getOutputEdges()->erase(it);
        }
        else
        {
            ++it;
        }
    }
    it = endNode->getInputEdges()->begin();
    while (it != endNode->getInputEdges()->end())
    {
        if (it->getStartNode() == s)
        {
            it = endNode->getInputEdges()->erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Graph::addEdge(int s, int e)
{
    addEdge(s, e, 0);
}

Node * Graph::getNode(int id)
{
    checkNodeExists(id);
    return & nodes.find(id)->second;
}

map<int, Node> Graph::getAllNodes() {
    return nodes;
}

Graph Graph::revert()
{
    Graph revertedGraph = Graph();
    map<int, Node>::iterator nodeIt;
    for (nodeIt = nodes.begin(); nodeIt != nodes.end(); ++nodeIt)
    {
        revertedGraph.addNode(nodeIt->first);
    }
    for (nodeIt = nodes.begin(); nodeIt != nodes.end(); ++nodeIt)
    {
        int nodeId = nodeIt->first;
        Node node = nodeIt->second;
        for (Edge & edge : *node.getOutputEdges()) {
            revertedGraph.addEdge(edge.getEndNode(), nodeId, edge.getLength());
        }
    }
    return revertedGraph;
}

void Graph::markAllNodesNotVisited() {
    for (const auto &node : nodes)
    {
        getNode(node.first)->markNotVisited();
    }
}
