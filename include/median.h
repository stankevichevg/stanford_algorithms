#include <vector>
#include <queue>

#ifndef STANFORD_ALGORITHMS_MEDIAN_H
#define STANFORD_ALGORITHMS_MEDIAN_H

using namespace std;

class MedianMaintainer
{
private:
    priority_queue<int, vector<int>, greater<>> h;
    priority_queue<int> l;
public:
    void push(int item);
    int median();
};

#endif //STANFORD_ALGORITHMS_MEDIAN_H
