#include "disjoint_set.h"

DisjointSet::DisjointSet(int setsNumber)
{
    this->setsNumber = setsNumber;
    this->data = new Element[setsNumber];
    for (int i = 0; i < setsNumber; i++)
    {
        data[i].root = i;
        data[i].size = 1;
    }
}

DisjointSet::~DisjointSet()
{
    delete this->data;
}

int DisjointSet::find(int element)
{
    if (element == data[element].root)
    {
        return element;
    }
    else
    {
        return find(data[element].root);
    }
}

int DisjointSet::size()
{
    return this->setsNumber;
}

bool DisjointSet::unionSets(int first, int second)
{
    Element &firstElement = data[first];
    Element &secondElement = data[second];
    if (firstElement.root != first || secondElement.root != second || first == second)
    {
        return false;
    }
    else
    {
        if (firstElement.size < secondElement.size)
        {
            firstElement.root = second;
            secondElement.size += firstElement.size;
        }
        else
        {
            secondElement.root = first;
            firstElement.size += secondElement.size;
        }
        this->setsNumber -= 1;
        return true;
    }
}
