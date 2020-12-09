#ifndef STANFORD_ALGORITHMS_CONTRACTION_H
#define STANFORD_ALGORITHMS_CONTRACTION_H

#include "graph.h"

class GraphContractor {
protected:
    Graph * graph;
    virtual Edge selectEdge() = 0;
public:
    void contract(int nodesToLeave);
    Graph * getGraph();
};

class RandomGraphContractor : public GraphContractor {
protected:
    Edge selectEdge() override;
public:
    RandomGraphContractor(Graph * graph);
};

#endif //STANFORD_ALGORITHMS_CONTRACTION_H
