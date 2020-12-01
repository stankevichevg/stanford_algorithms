#ifndef STANFORD_ALGORITHMS_QUICKSORT_H
#define STANFORD_ALGORITHMS_QUICKSORT_H

int first_element_pivot(int*, int, int);
int final_element_pivot(int*, int, int);
int median_of_three_element_pivot(int*, int, int);

int quick_sort(int * array, int l, int n, int (*pivot)(int*, int, int));

#endif //STANFORD_ALGORITHMS_QUICKSORT_H
