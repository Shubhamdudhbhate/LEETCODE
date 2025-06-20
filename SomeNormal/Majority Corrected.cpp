#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = nums[0];  // Start with first element
        int count = 1;            // One vote for it

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == candidate) {
                count++;  // Same as candidate, increase count
            } else {
                count--;  // Different, decrease count

                if (count == 0) {
                    candidate = nums[i];  // New candidate
                    count = 1;
                }
            }
        }

        return candidate;
    }
};


