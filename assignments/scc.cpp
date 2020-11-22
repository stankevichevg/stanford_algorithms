#include <iostream>
#include <scc.h>

#include <fstream>

#include <algorithm>

#include "traverser.h"
#include "graph.h"

Graph readGraph(const char* filename)
{
    Graph graph = Graph();

    for (int i = 1; i <= 875714; i++) {
        graph.addNode(i);
    }
    std::ifstream infile(filename);
    int a, b;
    while (infile >> a >> b)
    {
        graph.addEdge(a, b);
    }
    return graph;
}

int main()
{
    Graph graph = readGraph("../data/assignment_1_graph.txt");
    Graph revertedGraph = graph.revert();
    DfsTraverser sccFirstPassTraverser(revertedGraph);
    FinishTimeTraverser sccSecondPassTraverser(graph);
    // init finish times
    sccFirstPassTraverser.traverse(&sccSecondPassTraverser);
    graph.markAllNodesNotVisited();

    SccCalculator sccCalculator;
    sccSecondPassTraverser.traverse(&sccCalculator);
    graph.markAllNodesNotVisited();

    vector<int> sizes = sccCalculator.getSizes();
    std::sort(sizes.begin(), sizes.end(), greater<int>());
    sizes.resize(4);

    for (const auto size : sizes) {
        cout << size << endl;
    }

    return 0;
}
