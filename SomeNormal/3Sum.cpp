#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;

        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                    if (arr[i] + arr[j] + arr[k] == 0) {
                        vector<int> vec;

                        vec.push_back(arr[i]);
                        vec.push_back(arr[j]);
                        vec.push_back(arr[k]);

                        sort(vec.begin(), vec.end());

                        if (find(ans.begin(), ans.end(), vec) == ans.end()) {
                            ans.push_back(vec);
                        }
                    }
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                    ++left;
                else if (sum > 0)
                    --right;
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;  // skip dup
                    while (left < right && nums[right] == nums[right - 1]) --right; // skip dup
                    ++left;
                    --right;
                }
            }
        }

        return ans;
    }



vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    
    vector<vector<int>> ans;
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        int target = -nums[i];
        set<int> s;

        for (int j = i + 1; j < n; j++) {
            int third = target - nums[j];

            if (s.find(third) != s.end()) {
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }

            s.insert(nums[j]);
        }
    }

    for (auto triplet : uniqueTriplets) {
        ans.push_back(triplet);
    }

    return ans;
}


};

