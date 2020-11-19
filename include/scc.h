#ifndef STANFORD_ALGORITHMS_SCC_H
#define STANFORD_ALGORITHMS_SCC_H

#include "traverser.h"

class FinishTimeTraverser : public NodeVisitor, public DfsTraverser {
protected:
    int t = 0;
    map<int, int, greater<int>> orderToIndex;
public:
    FinishTimeTraverser(Graph graph);
    void visit(int nodeId) override;
    void leave(int nodeId) override;
    void traverse(NodeVisitor *visitor) override;
};

class SccCalculator : public NodeVisitor {
private:
    int currentLabel = -1;
    int currentSize = 0;
    vector<int> sizes;
public:
    void visit(int nodeId) override;
    void leave(int nodeId) override;
    vector<int> getSizes();
};

#endif //STANFORD_ALGORITHMS_SCC_H
