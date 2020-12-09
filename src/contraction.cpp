#include "contraction.h"
#include "iostream"

Graph * GraphContractor::getGraph() {
    return graph;
}

void GraphContractor::contract(int nodesToLeave) {
    while (graph->getAllNodes().size() > nodesToLeave)
    {
        Edge edge = selectEdge();
        graph->removeEdges(edge.getStartNode(), edge.getEndNode());
        graph->removeEdges(edge.getEndNode(), edge.getStartNode());

        Node* e = graph->getNode(edge.getEndNode());

        for (Edge output : *e->getOutputEdges())
        {
            graph->addEdge(edge.getStartNode(), output.getEndNode());
        }
        vector<Edge> oEdges = *e->getOutputEdges();
        for (Edge output : oEdges)
        {
            graph->removeEdges(output.getStartNode(), output.getEndNode());
        }

        for (Edge input : *e->getInputEdges())
        {
            graph->addEdge(input.getStartNode(), edge.getStartNode());
        }
        vector<Edge> iEdges = *e->getInputEdges();
        for (Edge input : iEdges)
        {
            graph->removeEdges(input.getStartNode(), input.getEndNode());
        }

        graph->removeNode(edge.getEndNode());
    }
}

template<typename T>
std::pair<int, T> randomFromMap(std::map<int, T> const &v)
{
    auto it = v.cbegin();
    int random = rand() % v.size();
    std::advance(it, random);
    return *it;
}

template<typename T>
T randomFromVector(std::vector<T> const &v) {
    auto it = v.cbegin();
    int random = rand() % v.size();
    std::advance(it, random);
    return *it;
}

Edge RandomGraphContractor::selectEdge()
{
    Node node = randomFromMap(getGraph()->getAllNodes()).second;
    Edge edge = randomFromVector(*node.getInputEdges());
    return edge;
}

RandomGraphContractor::RandomGraphContractor(Graph *graph) {
    this->graph = graph;
}
