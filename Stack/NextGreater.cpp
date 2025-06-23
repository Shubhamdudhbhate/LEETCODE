#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> CircularnextGreaterElements(vector<int> &nums)   // T.C O(n)
    {
        int n = nums.size();
        vector<int> result(n, -1); // Initialize with -1
        stack<int> st;             // Store indices

        // Traverse array twice in reverse (circular)
        for (int i = 2 * n - 1; i >= 0; --i)
        {
            int curr = nums[i % n];

            // Pop all smaller/equal values
            while (!st.empty() && nums[st.top()] <= curr)
            {
                st.pop();
            }

            if (i < n)
            {
                if (!st.empty())
                {
                    result[i] = nums[st.top()];
                }
            }

            // Push index of current element
            st.push(i % n);
        }

        return result;
    }

    vector<int> nextGreaterElement(vector<int> &arr)
    {

        int n = arr.size();     
        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = arr.size() - 1; i >= 0; i--) // T.C = o(n)
        {

            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }

            s.push(arr[i]);
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &arr)
    {

        unordered_map<int, int> M;
        int n = arr.size();
        stack<int> s;

        for (int i = arr.size() - 1; i >= 0; i--) // T.C = o(n)
        {

            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                M[arr[i]] = -1;
            }
            else
            {
                M[arr[i]] = s.top();
            }

            s.push(arr[i]);
        }

        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {

            ans.push_back(M[nums1[i]]);
        }

        return ans;
    }




    vector<int> PreviousSElement(vector<int> &arr)
    {

        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = 0 ; i <n; i++) // T.C = o(n)
        {

            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }

            s.push(arr[i]);
        }
        return ans;
    }
};

// 🔹 Test Driver
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> ans = sol.CircularnextGreaterElements(nums);

    cout << "Next Greater Elements (Circular): ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    vector<int> ansr = sol.nextGreaterElement(nums);

    cout << "Next Greater Elements (Circular): ";
    for (int x : ansr)
        cout << x << " ";
    cout << endl;

    return 0;
}
