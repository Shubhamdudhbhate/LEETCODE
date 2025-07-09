#include <iostream>
#include <queue>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

class Solution
{
public:
    int KthSmallest(vector<vector<int>> &mat, int n, int k)
    {
        // Min Heap: {value, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Step 1: Push first element of each row into heap
        for (int i = 0; i < n; i++)
        {
            minHeap.push({mat[i][0], {i, 0}});
        }

        int ans = -1;

        // Step 2: Pop k times
        while (k--)
        {
            auto element = minHeap.top();
            minHeap.pop();

            ans = element.first;
            int row = element.second.first;
            int col = element.second.second;

            // Push next element from same row
            if (col + 1 < n)
            {
                minHeap.push({mat[row][col + 1], {row, col + 1}});
            }
        }

        return ans;
    }

    //_____________________________________________________________________________________________________________________________
    //_____________________________________________________________________________________________________________________________

    int countLessEqual(vector<vector<int>> &matrix, int mid, int n)
    {
        int count = 0;
        int row = n - 1;
        int col = 0;

        while (row >= 0 && col < n)
        {
            if (matrix[row][col] <= mid)
            {
                count += (row + 1); // all elements in current column from 0 to row
                col++;
            }
            else
            {
                row--;
            }
        }

        return count;
    }

    int KthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid, n);

            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return low;
    }



};

int main()
{
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}};

    int k = 8;
    Solution obj;
    int result = obj.KthSmallest(matrix, matrix.size(), k);

    cout << "K-th smallest element is: " << result << endl; // Output: 13

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}};
    int k = 8;

    Solution sol;
    cout << "K-th smallest element is: " << sol.KthSmallest(matrix, k) << endl;

    return 0;
}
