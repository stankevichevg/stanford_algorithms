#ifndef STANFORD_ALGORITHMS_KNAPSACK_H
#define STANFORD_ALGORITHMS_KNAPSACK_H

#include <vector>

using namespace std;

struct Item
{
    int weight;
    int volume;
    Item(int weight, int volume)
    {
        this->weight = weight;
        this->volume = volume;
    }
};

struct KnapsackProblem
{
    int size;
    vector<Item> items;
};

int solveKnapsack(KnapsackProblem& knapsackProblem);

#endif //STANFORD_ALGORITHMS_KNAPSACK_H
