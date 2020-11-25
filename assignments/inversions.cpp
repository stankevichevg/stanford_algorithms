#include <iostream>
#include <fstream>

#include "inversions.h"

using namespace std;

int * readInputFile(const char* filename)
{
    std::ifstream infile(filename);
    int a;
    int i = 0;
    static int array[100000];
    while (infile >> a)
    {
        array[i] = a;
        i++;
    }
    return array;
}

int main()
{
    int * array = readInputFile("../data/assignment_1_array.txt");
    long long inversions = calculate_inversions(array, 0, 99999);
    cout << "Number if inversions: " << inversions << endl;
    return 0;
}
