#include "inversions.h"

long long calculate_split_inversions(int * array, int start, int split, int end)
{
    int leftSize = split - start + 1;
    int rightSize = end - split;
    int left[leftSize];
    int right[rightSize];
    for (int i = 0; i < leftSize; i++)
    {
        left[i] = array[start + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        right[i] = array[split + 1 + i];
    }
    // merge and calculate splits
    int lp = 0;
    int rp = 0;
    int mp = start;
    long long inversions = 0;
    while (lp < leftSize && rp < rightSize)
    {
        if (left[lp] <= right[rp])
        {
            array[mp] = left[lp];
            lp++;
        }
        else
        {
            array[mp] = right[rp];
            rp++;
            inversions += leftSize - lp;
        }
        mp++;
    }
    while (lp < leftSize)
    {
        array[mp] = left[lp];
        lp++;
        mp++;
    }
    while (rp < rightSize)
    {
        array[mp] = right[rp];
        rp++;
        mp++;
    }
    return inversions;
}

long long calculate_inversions(int * array, int start, int end)
{
    if (start == end)
    {
        return 0;
    }
    int split = start + (end - start) / 2;
    long long leftInversions = calculate_inversions(array, start, split);
    long long rightInversions = calculate_inversions(array, split + 1, end);
    long long splitInversions = calculate_split_inversions(array, start, split, end);
    return leftInversions + rightInversions + splitInversions;
}