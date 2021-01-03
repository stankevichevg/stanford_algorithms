#include <cmath>

#include "tsp.h"

// http://graphics.stanford.edu/~seander/bithacks.html#NextBitPermutation
unsigned int generate_next_bit_permutation(unsigned int v)
{
    unsigned int t = v | (v - 1);
    return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}

double distance(City &first, City &second)
{
    return sqrt(pow(first.x - second.x, 2.0) + pow(first.y - second.y, 2.0));
}

double tsp(vector<City> &cities)
{
    int citiesNumber = cities.size();
    vector<vector<double>> distances(citiesNumber + 1, vector<double>(citiesNumber + 1, 0));
    for (int i = 1; i <= citiesNumber; i++)
    {
        for (int j = i + 1; j <= citiesNumber; j++)
        {
            double dist = distance(cities[i - 1], cities[j - 1]);
            distances[i][j] = dist;
            distances[j][i] = dist;
        }
    }
    vector<vector<double>> A((1 << citiesNumber) + 1, vector<double>(citiesNumber + 1, INT32_MAX));
    A[1][0] = 0;
    unsigned int maxBitSet = 1 << (citiesNumber - 1);
    for (int m = 2; m <= citiesNumber; m++)
    {
        unsigned int bits = (1 << (m - 1)) - 1;
        while (bits < maxBitSet)
        {
            // for each set of size m that contains 1:
            unsigned int S = bits << 1 | 1;
            for (int j = 1; j < citiesNumber; j++)
            {
                if ((1 << j) & S)
                {
                    // for each j != 1 from citiesSet do
                    unsigned int Sj = S & ~(1UL << j);
                    double foundMin = INT32_MAX;
                    for (int k = 0; k < citiesNumber; k++)
                    {
                        if (k != j && ((1 << j) & S))
                        {
                            double candidate = A[Sj][k] + distances[k + 1][j + 1];
                            if (foundMin > candidate)
                            {
                                foundMin = candidate;
                            }
                        }
                    }
                    A[S][j] = foundMin;
                }
            }
            bits = generate_next_bit_permutation(bits);
        }
    }
    unsigned int S = (1 << citiesNumber) - 1;
    double minDistance = INT32_MAX;
    for (int j = 1; j < citiesNumber; j++)
    {
        double candidate = A[S][j] + distances[j + 1][1];
        if (minDistance > candidate)
        {
            minDistance = candidate;
        }
    }
    return minDistance;
}
