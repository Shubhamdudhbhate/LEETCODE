#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>    
#include <string>
using namespace std;

;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // store indices
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove smaller elements from back
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();

        dq.push_back(i); // add current index

        // Remove front if it’s out of window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Add to result if window is full
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}
