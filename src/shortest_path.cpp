#include "shortest_path.h"

#include "set"

#include <iostream>

ShortestPathCalculator::ShortestPathCalculator(Graph *g): graph(g) {}

DijkstraBruteForceCalculator::DijkstraBruteForceCalculator(Graph *g): ShortestPathCalculator(g){}

void DijkstraBruteForceCalculator::calculate(int startNodeId)
{
    set<int> calculatedNodes = set<int>();
    Node *startNode = graph->getNode(startNodeId);
    startNode->setPathLength(0);
    calculatedNodes.insert(startNodeId);
    const int graphSize = graph->getAllNodes().size();
    while (calculatedNodes.size() != graphSize)
    {
        int optimalNodeId;
        int minimum = std::numeric_limits<int>::max();
        for (int nodeId : calculatedNodes) {
            Node* node = graph->getNode(nodeId);
            for (Edge &edge : node->getOutputEdges())
            {
                if (calculatedNodes.find(edge.getEndNode()) == calculatedNodes.end()) {
                    int dijkstraCriteria = node->getPathLength() + edge.getLength();
                    if (minimum > dijkstraCriteria) {
                        optimalNodeId = edge.getEndNode();
                        minimum = dijkstraCriteria;
                    }
                }
            }
        }
        Node *optimalNode = graph->getNode(optimalNodeId);
        optimalNode->setPathLength(minimum);
        calculatedNodes.insert(optimalNodeId);
    }
}