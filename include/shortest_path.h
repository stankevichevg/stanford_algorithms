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

class BellmanFordCalculator: public ShortestPathCalculator {
private:
    bool cycleDetected = false;
public:
    BellmanFordCalculator(Graph *g);
    void calculate(int startNodeId) override;
    bool isCycleDetected();
};

class JohnsonCalculator {
protected:
    Graph *graph;
public:
    JohnsonCalculator(Graph *g);
    map<int, map<int, int>> calculate();
};

#endif //STANFORD_ALGORITHMS_SHORTEST_PATH_H
