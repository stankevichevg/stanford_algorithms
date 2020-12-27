#ifndef STANFORD_ALGORITHMS_UNION_FIND_H
#define STANFORD_ALGORITHMS_UNION_FIND_H

struct Element
{
    int root;
    int size;
};

class DisjointSet
{
private:
    int setsNumber;
    Element* data;
public:
    DisjointSet(int setsNumber);
    ~DisjointSet();
    int find(int element);
    bool unionSets(int first, int second);
    int size();
};

#endif //STANFORD_ALGORITHMS_UNION_FIND_H
