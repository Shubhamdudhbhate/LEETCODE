#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}



// by morris traversal fixing two nodes in a BST

void fixTwoNodesMorris(Node *root)
{
    Node *current = root, *prev = nullptr, *first = nullptr, *second = nullptr;
    while (current)
    {
        if (!current->left)
        {
            if (prev && prev->data > current->data)
            {
                if (!first)
                    first = prev;
                second = current;
            }
            prev = current;
            current = current->right;
        }
        else
        {
            Node *predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
                predecessor = predecessor->right;

            if (!predecessor->right)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = nullptr;
                if (prev && prev->data > current->data)
                {
                    if (!first)
                        first = prev;
                    second = current;
                }
                prev = current;
                current = current->right;
            }
        }
    }

    if (first && second)
        swap(first->data, second->data);
}