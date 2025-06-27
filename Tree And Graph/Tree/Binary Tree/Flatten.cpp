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
    void Flatten(Node *root)
    {

        while (root != NULL)
        {
            if (root->left == NULL)
            {
                root = root->right;
            }
            else
            {
                Node *prev = root->left;

                while (prev->right && prev->right != root)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = root->right;
                    root->right = root->left;
                    root->left = NULL;
                    root = root->right;
                }
            }
        }
    }
};


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Solution sol;
    sol.Flatten(root);

    // Print the flattened tree
    Node *curr = root;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    
    return 0;
}