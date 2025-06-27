#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Vertical traversal of a binary tree

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void find(Node *root, int pos, int &l, int &r, vector<int> &ans)
    {
        if (root == NULL)
            return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r, ans);
        find(root->right, pos + 1, l, r, ans);
    }

    vector<int> VerticalOrder(Node *root)
    {

        int l = 0;
        int r = 0;

        vector<vector<int>> Positive(r + 1);
        vector<vector<int>> Negative(abs(l) + 1);

        queue<Node *> q;
        q.push(root);

        queue<int> index;
        index.push(0);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            if (pos >= 0)
            {
                Positive[pos].push_back(curr->data);
            }
            else
            {
                Negative[abs(pos)].push_back(curr->data);
            }

            if (curr->left)
            {
                q.push(curr->left);
                index.push(pos - 1);
            }
            if (curr->right)
            {
                q.push(curr->right);
                index.push(pos + 1);
            }
        }

        vector<int> ans;
        for (int i = 0; i < Negative.size(); i++)
        {
            for (int j = 0; j < Negative[i].size(); j++)
            {
                ans.push_back(Negative[i][j]);
            }
        }

        for (int i = 0; i < Positive.size(); i++)
        {
            for (int j = 0; j < Positive[i].size(); j++)
            {
                ans.push_back(Positive[i][j]);
            }
        }

        return ans;
    }
};
