#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "knapsack.h"

void readInputFile(const std::string& filename, KnapsackProblem& knapsackProblem)
{
    std::ifstream myFile(filename);
    if(!myFile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }
    int knapsackSize, numberOfItems;
    int weight, volume;
    std::string line;
    std::getline(myFile, line);
    std::stringstream ss(line);
    ss >> knapsackSize;
    knapsackProblem.size = knapsackSize;
    ss >> numberOfItems;
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);
        ss >> weight;
        ss >> volume;
        knapsackProblem.items.push_back(Item(weight, volume));
    }
}

int main()
{
    KnapsackProblem knapsackProblem;
    readInputFile("../data/knapsack.txt", knapsackProblem);
    cout << "Optimal solution for knapsack problem: " << solveKnapsack(knapsackProblem) << endl;

    KnapsackProblem bigKnapsackProblem;
    readInputFile("../data/knapsack_big.txt", bigKnapsackProblem);
    cout << "Optimal solution for big knapsack problem: " << solveKnapsack(bigKnapsackProblem) << endl;
    return 0;
}
