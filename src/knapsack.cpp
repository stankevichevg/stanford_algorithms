#include "knapsack.h"

int knapsack(int itemsNumber, int allowedVolume, vector<Item> items, vector<vector<int>>& table)
{
    if (table[itemsNumber][allowedVolume] != -1)
    {
        return table[itemsNumber][allowedVolume];
    }
    else
    {
        if (allowedVolume < items[itemsNumber].volume)
        {
            return knapsack(itemsNumber - 1, allowedVolume, items, table);
        }
        else
        {
            int optimal = max(
                    knapsack(itemsNumber - 1, allowedVolume, items, table),
                    knapsack(itemsNumber - 1, allowedVolume - items[itemsNumber].volume, items, table) + items[itemsNumber].weight
            );
            table[itemsNumber][allowedVolume] = optimal;
            return optimal;
        }
    }
}

int solveKnapsack(KnapsackProblem& knapsackProblem)
{
    vector<vector<int>> table(knapsackProblem.items.size() + 1, vector<int>(knapsackProblem.size + 1, -1));
    table[0][0] = 0;
    for (int i = 0; i <= knapsackProblem.size; i++)
    {
        table[0][i] = 0;
    }
    return knapsack(knapsackProblem.items.size(), knapsackProblem.size, knapsackProblem.items, table);
}
