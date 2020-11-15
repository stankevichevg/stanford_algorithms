#include "graph.h"

Graph::Graph(bool directed)
{
    this->directed = directed;
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
    this->nodes[id] = Node();
}

void Graph::addEdge(int s, int e)
{
    checkNodeExists(s);
    checkNodeExists(e);
    nodes.find(s)->second.addAdjNode(e);
    if (!directed)
    {
        nodes.find(e)->second.addAdjNode(s);
    }
}

Node Graph::getNode(int id)
{
    checkNodeExists(id);
    return nodes.find(id)->second;
}

map<int, Node> Graph::getAllNodes() {
    return nodes;
}

Graph Graph::revert()
{
    Graph revertedGraph = Graph(directed);
    map<int, Node>::iterator nodeIt;
    for (nodeIt = nodes.begin(); nodeIt != nodes.end(); ++nodeIt)
    {
        revertedGraph.addNode(nodeIt->first);
    }
    for (nodeIt = nodes.begin(); nodeIt != nodes.end(); ++nodeIt)
    {
        int nodeId = nodeIt->first;
        Node node = nodeIt->second;
        for (int & adjNodeIt : node.getAdjNodes()) {
            revertedGraph.addEdge(adjNodeIt, nodeId);
        }
    }
    return revertedGraph;
}
