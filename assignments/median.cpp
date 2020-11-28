#include <iostream>
#include <fstream>

#include "median.h"

int main()
{
    MedianMaintainer medianMaintainer;
    std::ifstream infile("../data/assignment_2_median.txt");
    int a;
    long long sum;
    while (infile >> a) {
        medianMaintainer.push(a);
        sum += medianMaintainer.median();
    }
    cout << "Sum of medians: " << sum << endl;
}
