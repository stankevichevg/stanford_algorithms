#ifndef STANFORD_ALGORITHMS_EDGE_H
#define STANFORD_ALGORITHMS_EDGE_H

class Edge {
private:
    int startNode;
    int endNode;
    int length;
public:
    Edge(int startNode, int endNode, int length);
    int getStartNode() const;
    int getEndNode() const;
    int getLength() const;
};

#endif //STANFORD_ALGORITHMS_EDGE_H
