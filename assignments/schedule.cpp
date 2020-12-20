#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Job {
    int weight;
    int length;
    Job(int weight, int length) {
        this -> weight = weight;
        this -> length = length;
    }
};

vector<Job> readJobs(const std::string& filename)
{
    std::ifstream myFile(filename);
    if(!myFile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }
    vector<Job> jobs;
    std::string line;
    int jobsNumber, length, weight;
    std::getline(myFile, line);
    std::stringstream ss(line);
    ss >> jobsNumber;
    while (std::getline(myFile, line))
    {
        std::stringstream ssLine(line);
        ssLine >> weight;
        ssLine >> length;
        jobs.push_back(Job(weight, length));
    }
    return jobs;
}

long weightedCompletionTimeSum(const vector<Job>& schedule)
{
    long sum = 0;
    int completionTime = 0;
    for (auto it : schedule)
    {
        completionTime += it.length;
        sum += it.weight * completionTime;
    }
    return sum;
}

int main() {
    vector<Job> schedule = readJobs("../data/job.txt");
    sort(schedule.begin(), schedule.end(), [](const Job& lj, const Job& rj) {
        int leftDifference = lj.weight - lj.length;
        int rightDifference = rj.weight - rj.length;
        if (leftDifference == rightDifference) {
            return lj.weight > rj.weight;
        }
        else
        {
            return leftDifference > rightDifference;
        }
    });
    cout << "Weighted completion time sum for (weight - length) score: " << weightedCompletionTimeSum(schedule) << endl;
    sort(schedule.begin(), schedule.end(), [](const Job& lj, const Job& rj) {
        double leftDifference = ((double) lj.weight) / lj.length;
        double rightDifference = ((double) rj.weight) / rj.length;
        if (leftDifference == rightDifference) {
            return lj.weight > rj.weight;
        }
        else
        {
            return leftDifference > rightDifference;
        }
    });
    cout << "Weighted completion time sum for (weight/length) score: " << weightedCompletionTimeSum(schedule) << endl;
}
