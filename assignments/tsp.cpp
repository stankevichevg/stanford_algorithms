#include <iostream>
#include <bitset>
#include <fstream>
#include <sstream>

#include "tsp.h"

vector<City> readTspInputFile(const std::string& filename)
{
    std::ifstream myFile(filename);
    if(!myFile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    int citiesNumber;
    double x, y;
    vector<City> cities;

    std::string line;
    std::getline(myFile, line);
    std::stringstream ss(line);
    ss >> citiesNumber;
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);
        ss >> x;
        ss >> y;
        cities.push_back(City(x, y));
    }
    return cities;
}

int main()
{
    vector<City> cities = readTspInputFile("../data/tsp.txt");
    double tspMinDistance = tsp(cities);
    cout << "Minimal distance is: " << tspMinDistance;
}
