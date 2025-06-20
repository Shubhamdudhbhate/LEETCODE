#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>&nums)
    {  int n = nums.size();
       sort(nums.begin(), nums.end());
      
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
            {
                return i; // Return the first missing number
            }
        } 
        return n; 
    }

    int missingNumber2(vector<int> &nums)
    {
        int n = nums.size();
        int total = n * (n + 1) / 2; // Sum of first n natural numbers
        int sum = 0;
        for (int num : nums)
        {
            sum += num; // Calculate the sum of the array
        }
        return total - sum; // The missing number is the difference
    }

    int missingNumber3(vector<int> &nums)
    {
        int n = nums.size();
        int xorSum = 0;
        for (int i = 0; i < n; i++)
        {
            xorSum ^= nums[i]; // XOR all elements in the array
        }
        for (int i = 0; i <= n; i++)
        {
            xorSum ^= i; // XOR all numbers from 0 to n
        }
        return xorSum; // The result is the missing number
    }


    int missingNumber4(vector<int> &nums)
    {
        int n = nums.size();
        int missing = n; // Start with n as the missing number
        for (int i = 0; i < n; i++)
        {
            missing ^= i ^ nums[i]; // XOR current index and value
        }
        return missing; // The result is the missing number
    }


};
