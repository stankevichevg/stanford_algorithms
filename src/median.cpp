#include <bits/stdc++.h>

#include "median.h"

int MedianMaintainer::median() {
    if (h.size() > l.size())
    {
        return h.top();
    }
    else if (h.size() <= l.size())
    {
        return l.top();
    }
}

void MedianMaintainer::push(int item) {
    if (!l.empty() && item <= l.top())
    {
        l.push(item);
    }
    else
    {
        h.push(item);
    }
    if (h.size() != l.size())
    {
        if (h.size() + 1 > l.size())
        {
            l.push(h.top());
            h.pop();
        }
        else if (l.size() + 1 > h.size())
        {
            h.push(l.top());
            l.pop();
        }
    }
}
