#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {

        vector<int> ans;
        unordered_set<int> s;

        int n = grid.size();
        int repeat = -1;
        int sum = 0;
        int total = n * n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int val = grid[i][j];
                sum += val;

                if (s.find(grid[i][j]) != s.end())
                {
                    repeat = grid[i][j];
                }
                else
                {
                    s.insert(grid[i][j]);
                }
            }
        }

        int expectedSum = (total * (total + 1)) / 2;
        int missing = expectedSum - (sum - repeat);

        return {repeat, missing};
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& grid) {
        int n = grid.size();

        unordered_set<int> seen;
        int sum = 0;
        int repeat = -1;

        for (int i = 0; i < n; ++i) {
            int val = grid[i];

            if (seen.find(val) != seen.end()) {
                repeat = val;
            } else {
                seen.insert(val);
            }
        }

        return repeat;
    }
};