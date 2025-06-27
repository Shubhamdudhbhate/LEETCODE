#include <iostream>
#include <functional>
#include <algorithm>
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




void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}


vector<int> MergeTwoBST(Node *root1, Node *root2)
{

    vector<int> arr1;
    vector<int> arr2;


    inorder(root1 , arr1);
    inorder(root2, arr2);

    vector<int>result;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
            result.push_back(arr1[i++]);
        else if (arr1[i] > arr2[j])
            result.push_back(arr2[j++]);
        else
        {
            result.push_back(arr1[i++]);
            j++;
        }
    }


    while (i < arr1.size())
        result.push_back(arr1[i++]);

    while (j < arr2.size())
        result.push_back(arr2[j++]);

    return result;
}


int main()
{
    // Sample BST1
    Node *root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);
    root1->left->left = new Node(0);
    root1->left->right = new Node(2);

    // Sample BST2
    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);

    vector<int> mergedResult = MergeTwoBST(root1, root2);

    cout << "Merged BST values: ";
    for (int val : mergedResult)
        cout << val << " ";
    cout << endl; // ans should be 0 1 2 3 4 5 6

    return 0;
}