#include "shortest_path.h"

#include "set"

ShortestPathCalculator::ShortestPathCalculator(Graph *g): graph(g) {}

DijkstraBruteForceCalculator::DijkstraBruteForceCalculator(Graph *g): ShortestPathCalculator(g){}

void DijkstraBruteForceCalculator::calculate(int startNodeId)
{
    set<int> calculatedNodes = set<int>();
    Node *startNode = graph->getNode(startNodeId);
    startNode->setPathLength(0);
    calculatedNodes.insert(startNodeId);
    while (true)
    {
        int optimalNodeId;
        int minimum = std::numeric_limits<int>::max();
        for (int nodeId : calculatedNodes) {
            Node* node = graph->getNode(nodeId);
            for (auto edge : *node->getOutputEdges())
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
        if (minimum != std::numeric_limits<int>::max())
        {
            Node *optimalNode = graph->getNode(optimalNodeId);
            optimalNode->setPathLength(minimum);
            calculatedNodes.insert(optimalNodeId);
        }
        else {
            break;
        }
    }
    for (auto node : graph->getAllNodes())
    {
        if (calculatedNodes.find(node.first) == calculatedNodes.end())
        {
            graph->getNode(node.first)->setPathLength(std::numeric_limits<int>::max());
        }
    }
}

BellmanFordCalculator::BellmanFordCalculator(Graph *g): ShortestPathCalculator(g){}

bool BellmanFordCalculator::isCycleDetected() {
    return cycleDetected;
}

void BellmanFordCalculator::calculate(int startNodeId)
{

    int graphSize = graph->getAllNodes().size();
    int** A = new int*[graphSize + 1];
    for (int i = 0; i < graphSize + 1; i++)
    {
        A[i] = new int[graphSize];
        for (int j = 0; j < graphSize; j++)
        {
            A[i][j] = INT32_MAX;
        }
    }
    A[0][startNodeId] = 0;

    for (int i = 1; i < graphSize + 1; i++)
    {
        for (int j = 0; j < graphSize; j++)
        {
            auto vertex = graph->getNode(j);
            int localMin = INT32_MAX;
            for (Edge edge : *vertex->getInputEdges())
            {
                if (A[i - 1][edge.getStartNode()] != INT32_MAX)
                {
                    int candidateValue = A[i - 1][edge.getStartNode()] + edge.getLength();
                    if (localMin > candidateValue)
                    {
                        localMin = candidateValue;
                    }
                }
            }
            A[i][j] = localMin < A[i - 1][j] ? localMin : A[i - 1][j];
        }
    }

    // detect a negative cycle
    cycleDetected = false;
    for (int i = 0; i < graphSize; i++)
    {
        if (A[graphSize-1][i] != A[graphSize][i])
        {
            cycleDetected = true;
            break;
        }
    }

    if (!cycleDetected)
    {
        for (int i = 0; i < graphSize; i++)
        {
            auto vertex = graph->getNode(i);
            vertex->setPathLength(A[graphSize - 1][i]);
        }
    }

    for (int i = 0; i < graphSize; i++)
    {
        delete A[i];
    }
    delete[] A;
}

JohnsonCalculator::JohnsonCalculator(Graph *g): graph(g) {}

map<int, map<int, int>> JohnsonCalculator::calculate()
{
    // create G' as graph copy
    Graph bfGraph = graph->copy();
    // add new vertex to new graph and add edge to each vertex from it
    int tempNode = bfGraph.getAllNodes().size();
    bfGraph.addNode(tempNode);
    for (const auto& node : bfGraph.getAllNodes())
    {
        if (node.first != tempNode)
        {
            bfGraph.addEdge(tempNode, node.first, 0);
        }
    }
    // run Bellman-Ford algorithm, mark all vertexes by Pi - shortest path length from additional vertex
    BellmanFordCalculator bellmanFordCalculator(&bfGraph);
    bellmanFordCalculator.calculate(tempNode);
    if (bellmanFordCalculator.isCycleDetected())
    {
        return map<int, map<int, int>>();
    }
    // create new graph G'' with modified edge lengths Ce'' = Ce + Pu - Pv
    Graph correctedLengthsGraph;
    for (auto node : graph->getAllNodes())
    {
        correctedLengthsGraph.addNode(node.first);
    }
    for (auto node : graph->getAllNodes())
    {
        for (Edge edge : *node.second.getOutputEdges())
        {
            int adjustment =
                    bfGraph.getNode(edge.getStartNode())->getPathLength() -
                    bfGraph.getNode(edge.getEndNode())->getPathLength();
            correctedLengthsGraph.addEdge(edge.getStartNode(), edge.getEndNode(), edge.getLength() + adjustment);
        }
    }
    // for each vertex run Dijkstra algorithm
    map<int, map<int, int>> result;
    DijkstraBruteForceCalculator dijkstraBruteForceCalculator(&correctedLengthsGraph);
    for (const auto& node : correctedLengthsGraph.getAllNodes())
    {
        dijkstraBruteForceCalculator.calculate(node.first);
        map<int, int> lengths;
        for (const auto& otherNode : correctedLengthsGraph.getAllNodes())
        {
            if (otherNode.second.getPathLength() != INT32_MAX) {
                int adjustment = bfGraph.getNode(otherNode.first)->getPathLength() - bfGraph.getNode(node.first)->getPathLength();
                lengths[otherNode.first] = otherNode.second.getPathLength() + adjustment;
            }
            else
            {
                lengths[otherNode.first] = INT32_MAX;
            }
        }
        result[node.first] = lengths;
    }

    return result;
}
