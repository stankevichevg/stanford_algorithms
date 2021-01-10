#include <map>
#include <string>
#include <cmath>

#include <fstream>
#include <sstream>
#include <iostream>

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

void readInput(const std::string& filename, map<int, City>& cities)
{
    std::ifstream myFile(filename);
    if(!myFile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    int citiesNumber;
    int cityId;
    double x, y;

    std::string line;
    std::getline(myFile, line);
    std::stringstream ss(line);
    ss >> citiesNumber;
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);
        ss >> cityId;
        ss >> x;
        ss >> y;
        cities[cityId] = City(x, y);
    }
}

double distanceBetweenCities(City &first, City &second)
{
    return sqrt(pow(first.x - second.x, 2.0) + pow(first.y - second.y, 2.0));
}

int main()
{
    map<int, City> cities;
    readInput("../data/nn.txt", cities);
    City firstCity = cities[1];
    City current = firstCity;
    cities.erase(1);
    double currentDistance = 0.0;

    int count = 1;
    while (!cities.empty())
    {
        cout << "Cities processed: " << count << endl;
        int optimalCityId = -1;
        double minDistance = MAXFLOAT;
        for (auto city : cities)
        {
            double dist = distanceBetweenCities(current, city.second);
            if (dist < minDistance)
            {
                minDistance = dist;
                optimalCityId = city.first;
            }
            else if (dist == minDistance && city.first < optimalCityId)
            {
                optimalCityId = city.first;
            }
        }
        current = cities[optimalCityId];
        cities.erase(optimalCityId);
        currentDistance += minDistance;
        count++;
    }
    currentDistance += distanceBetweenCities(current, firstCity);
    cout << "Solution: " << (long) currentDistance << endl;
}
