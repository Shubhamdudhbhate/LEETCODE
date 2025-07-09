#include <iostream>
#include <vector>
#include <queue>
#include <tuple> 
#include <climits>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> Node; // {value, list index, element index}

vector<int> smallestRange(vector<vector<int>> &nums)
{
    int k = nums.size();
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;

    int maxVal = INT_MIN;
    for (int i = 0; i < k; i++)       // in same col ,row increasing
    {
        minHeap.push({nums[i][0], i, 0});
        maxVal = max(maxVal, nums[i][0]);
    }

    int rangeStart = 0, rangeEnd = INT_MAX;

    while (true)
    {
        int val = get<0>(minHeap.top());
        int row = get<1>(minHeap.top());
        int col = get<2>(minHeap.top());

        if (maxVal - val < rangeEnd - rangeStart)
        {
            rangeStart = val;
            rangeEnd = maxVal;
        }

        if (col + 1 == nums[row].size())
            break; // that list is over

        int nextVal = nums[row][col + 1];
        minHeap.push({nextVal, row, col + 1});
        maxVal = max(maxVal, nextVal);
    }

    return {rangeStart, rangeEnd};
}
