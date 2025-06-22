#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), count = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];
            if(sum == k) count++;
        }
    }
    return count;
}


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Handle subarrays starting from index 0
        
        int sum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            prefixSumCount[sum]++;
        }

        return count;
    }
};
