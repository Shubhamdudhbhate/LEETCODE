#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

class NumArray {
public:
    vector<int> prefix;

    // Constructor: precomputes prefix sum array
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);  // prefix[0] = 0

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    // sumRange(i, j) = sum of elements from i to j
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
