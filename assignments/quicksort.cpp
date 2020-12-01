#include <iostream>
#include <fstream>

#include "quicksort.h"

using namespace std;

int * readInputFile(const char* filename)
{
    std::ifstream infile(filename);
    int a;
    int i = 0;
    static int array[10000];
    while (infile >> a)
    {
        array[i] = a;
        i++;
    }
    return array;
}

int main()
{
    int * arr = new int[6] {5, 2, 1, 5, 7, 8};
    cout << median_of_three_element_pivot(arr, 0, 6) << endl;

    int * array = readInputFile("../data/QuickSort.txt");
    int comparisons = quick_sort(array, 0, 10000, &first_element_pivot);
    cout << "Comparisons (first element pivot): " << comparisons << endl;

    array = readInputFile("../data/QuickSort.txt");
    comparisons = quick_sort(array, 0, 10000, &final_element_pivot);
    cout << "Comparisons (final element pivot): " << comparisons << endl;

    array = readInputFile("../data/QuickSort.txt");
    comparisons = quick_sort(array, 0, 10000, &median_of_three_element_pivot);
    cout << "Comparisons (first element pivot): " << comparisons << endl;
}
