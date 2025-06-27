#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    int Pathasum(Node *root, int &maxSum)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
        {
            return root->data;
        }

        int leftSum = Pathasum(root->left, maxSum);
        int rightSum = Pathasum(root->right, maxSum);

        if (root->left && root->right)
        {
            maxSum = max(maxSum, leftSum + rightSum + root->data);
            return max(leftSum, rightSum) + root->data;
        }
        else if (root->left)
        {
            return leftSum + root->data;
        }
        else
        {
            return rightSum + root->data;
        }
    }

    int MaxPathSum(Node *root)
    {
        int maxSum = INT_MIN;
        int val = Pathasum(root, maxSum);

        if (root->left && root->right)
        {
            return maxSum;
        }
        else
        {
            return max(val, maxSum);
        }
    }
};

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution sol;
    cout << "Max Path Sum: " << sol.MaxPathSum(root) << endl;

    return 0;
}