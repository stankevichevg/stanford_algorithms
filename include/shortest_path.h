#ifndef STANFORD_ALGORITHMS_SHORTEST_PATH_H
#define STANFORD_ALGORITHMS_SHORTEST_PATH_H

#include "graph.h"

class ShortestPathCalculator {
protected:
    Graph *graph;
public:
    ShortestPathCalculator(Graph *g);
    virtual void calculate(int startNodeId) = 0;
};

class DijkstraBruteForceCalculator: public ShortestPathCalculator {
public:
    DijkstraBruteForceCalculator(Graph *g);
    void calculate(int startNodeId) override;
};

#endif //STANFORD_ALGORITHMS_SHORTEST_PATH_H
