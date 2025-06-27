#include <iostream>
#include <vector>
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

bool DeadEndUtil(Node *root, int min, int max)
{
    if (!root)
        return false;

    if (min == max)
        return true;

    return DeadEndUtil(root->left, min, root->data - 1) ||
           DeadEndUtil(root->right, root->data + 1, max);
}






 bool DeadEnd(Node *root, int min, int max)
{
    if (!root)
        return false;

    // If it's a leaf node, check if it is a dead end
    if (!root->left && !root->right)
    {

        // return (min == max);
     if(root->data - min == 1 && max - root->data == 1)
        {
            return true;
        }else
        {
            return false;
        }

    }

    return DeadEndUtil(root->left, min, root->data ) ||
           DeadEndUtil(root->right, root->data , max);
}


int main()
{
    // Sample Tree
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(16);

    int min = 0, max = INT_MAX;

    if (DeadEnd(root, min, max))
        cout << "Tree contains a dead end." << endl;
    else
        cout << "Tree does not contain a dead end." << endl;



        
     int min = 1, max = INT_MAX;

   if (DeadEndUtil(root, min, max))
        cout << "Tree contains a dead end." << endl;
    else
        cout << "Tree does not contain a dead end." << endl;



    return 0;
}