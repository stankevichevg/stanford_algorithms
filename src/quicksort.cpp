#include "quicksort.h"

int first_element_pivot(int* array, int l, int n)
{
    return l;
}

int final_element_pivot(int* array, int l, int n)
{
    return l + n - 1;
}

int median_of_three_element_pivot(int* array, int l, int n)
{
    int middle = 0;
    if (n % 2 == 0) {
        middle = l + (n - 1) / 2;
    }
    else
    {
        middle = l + n / 2;
    }

    if (array[l] < array[middle] && array[middle] < array[l + n - 1] ||
        array[l] > array[middle] && array[middle] > array[l + n - 1])
    {
        return middle;
    }
    else if (array[l] < array[l + n - 1] && array[l + n - 1] < array[middle] ||
        array[l] > array[l + n - 1] && array[l + n - 1] > array[middle])
    {
        return l + n - 1;
    }
    else // if (array[middle] < array[l] < array[l + n - 1])
    {
        return l;
    }
}

int quick_sort(int * array, int l, int n, int (*pvt)(int*, int, int))
{
    if (n == 1 || n == 0)
    {
        return 0;
    }

    int pivot = pvt(array, l, n);

    int temp = array[l];
    array[l] = array[pivot];
    array[pivot] = temp;

    int pv = array[l];
    int i = l + 1;

    for (int j = l + 1; j < l + n; j++)
    {
        if (array[j] < pv)
        {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            i++;
        }
    }
    temp = array[i - 1];
    array[i - 1] = array[l];
    array[l] = temp;

    int left = quick_sort(array, l, i - l - 1, pvt);
    int right = quick_sort(array, i, n - (i - l), pvt);

    return n - 1 + left + right;
}

