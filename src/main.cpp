#include <iostream>

#include "traverser.h"
#include "graph.h"


class NodePrinter : public NodeVisitor {
public:
    void visit(int nodeId) override {
        std::cout << nodeId << " ";
    }
};

int main()
{
    Graph graph = Graph(true);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);
    graph.addEdge(5, 7);

    DfsTraverser dfsGraphTraverser(graph);
    NodePrinter printer;

    std::cout << "Graph DFS traverse:" << std::endl;
    dfsGraphTraverser.traverse(&printer);
    std::cout << std::endl;

    return 0;
}
