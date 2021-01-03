#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

void readInputFile(const std::string& filename, vector<int>& weights)
{
    std::ifstream myFile(filename);
    if(!myFile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }
    int size;
    int w;
    std::string line;
    std::getline(myFile, line);
    std::stringstream ss(line);
    ss >> size;
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);
        ss >> w;
        weights.push_back(w);
    }
}

set<int> mwis(vector<int> &weights)
{
    int size = weights.size();
    int journal[size + 1];
    journal[0] = 0;
    journal[1] = weights[0];

    for (int i = 2; i < size; i++)
    {
        journal[i] = max(journal[i - 1], journal[i - 2] + weights[i - 1]);
    }
    journal[size] = max(journal[size - 1], journal[size - 2]);

    set<int> IS;
    int j = size;

    while (j >= 1)
    {
        if (journal[j - 1] >= journal[j - 2] + weights[j - 1])
        {
            j -= 1;
        }
        else
        {
            IS.insert(j);
            j -= 2;
        }
    }
    return IS;
}

int main()
{
    vector<int> weights;
    readInputFile("../data/mwis.txt", weights);
    set<int> is = mwis(weights);
    int s[] = {1, 2, 3, 4, 17, 117, 517, 997};
    for (int i = 0; i < 8; i++)
    {
        if (is.find(s[i]) != is.end())
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << endl;
    return 0;
}
