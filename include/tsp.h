#ifndef STANFORD_ALGORITHMS_TSP_H
#define STANFORD_ALGORITHMS_TSP_H

#include <vector>

using namespace std;

struct City
{
    double x;
    double y;
    City() {};
    City(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

double tsp(vector<City> &cities);

#endif //STANFORD_ALGORITHMS_TSP_H
