#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<long>* readInputFile(const char* filename)
{
    std::ifstream infile(filename);
    long a;
    int i = 0;
    auto data = new vector<long>();
    while (infile >> a)
    {
        data->push_back(a);
        i++;
    }
    return data;
}

int main()
{
    vector<long> * data = readInputFile("../data/algo1-programming_prob-2sum.txt");
    sort(data->begin(), data->end());
    set<long> results;
    for (auto j : *data)
    {
        auto left_bound = lower_bound(data->begin(), data->end(), -10000 - j);
        auto right_bound = lower_bound(data->begin(), data->end(), 10000 - j);
        for (auto it = left_bound; it != right_bound; it++)
        {
            if (*it != j) {
                results.insert(j + *it);
            }
        }
    }
    cout << "Answer: " << results.size() << endl;
}
