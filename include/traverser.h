#ifndef STANFORD_ALGORITHMS_TRAVERSER_H
#define STANFORD_ALGORITHMS_TRAVERSER_H

#include "graph.h"

#include <set>
#include <stack>

class NodeVisitor {
public:
    virtual void visit(int nodeId) = 0;
    virtual void leave(int nodeId) = 0;
};

class Traverser {
protected:
    Graph graph;
public:
    Traverser(Graph graph);
    virtual void traverse(NodeVisitor *visitor) = 0;
};

class DfsTraverser : public Traverser {
protected:
    void dfs(int startNode, NodeVisitor *visitor);
public:
    DfsTraverser(Graph graph);
    void traverse(NodeVisitor *visitor) override;
};

#endif //STANFORD_ALGORITHMS_TRAVERSER_H
