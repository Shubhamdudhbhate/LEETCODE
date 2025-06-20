#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int Max = INT_MIN;

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            Max = max(count, Max);

            if (Max>(n / 2)) {

                return nums[i];
            }
        }

        return -1;
    }
};