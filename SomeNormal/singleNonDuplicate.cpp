#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;


            if (mid > 0 && mid < nums.size() - 1) {
                if (nums[mid] == nums[mid + 1]) {
                    if (mid % 2 == 0) {
                        st = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                } else if (nums[mid] == nums[mid - 1]) {
                    if (mid % 2 == 0) {
                        end = mid - 1;
                    } else {
                        st = mid + 1;
                    }
                } else {
                    return nums[mid];  
                }
            } else {

                return nums[mid];
            }
        }
        return -1;
    }
};
