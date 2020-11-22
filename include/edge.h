#ifndef STANFORD_ALGORITHMS_EDGE_H
#define STANFORD_ALGORITHMS_EDGE_H

class Edge {
private:
    int endNode;
    int length;
public:
    Edge(int endNode, int length);
    int getEndNode() const;
    int getLength() const;
};

#endif //STANFORD_ALGORITHMS_EDGE_H
