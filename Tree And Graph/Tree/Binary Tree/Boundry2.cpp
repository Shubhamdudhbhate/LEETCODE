#include <iostream>
#include <vector>
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
    void LeftSubTree(Node *root, vector<int> &Ans)
    {
        // Node* curr = root;

        // while (curr != NULL)
        // {
        //     if (curr->left != NULL || curr->right != NULL)
        //         Ans.push_back(curr->data);

        //     if (curr->left != NULL)
        //         curr = curr->left;
        //     else
        //         curr = curr->right;
        // }

        if (!root || (!root->left && !root->right))
            return;
        Ans.push_back(root->data);

        if (root->left)
            LeftSubTree(root->left, Ans);
        else
            LeftSubTree(root->right, Ans);
    }

    void leaf(Node *root, vector<int> &Ans)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            Ans.push_back(root->data);
            return;
        }

        leaf(root->left, Ans);
        leaf(root->right, Ans);
    }

    void rightSubtree(Node *root, vector<int> &Ans)
    {
        if (!root || (!root->left && !root->right))
            return;

        if (root->right)
            rightSubtree(root->right, Ans);
        else
            rightSubtree(root->left, Ans);

        Ans.push_back(root->data);
    }

    vector<int> boundry(Node *root)
    {
        vector<int> Ans;

        Ans.push_back(root->data);

        LeftSubTree(root->left, Ans);

        if (root->left || root->right)
            leaf(root, Ans);

        rightSubtree(root->right, Ans);

        return Ans;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> boundary = sol.boundry(root);

    for (int val : boundary)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}