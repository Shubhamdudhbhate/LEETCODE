#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>    
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


// Inorder traversal (gives sorted order)
void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Check if a binary tree is a binary search tree (BST)
//1.0
bool checkBST(Node *root){
    vector<int> arr;
    inorder(root, arr);
    
    for (int i = 1; i < arr.size(); i++) {
           cout << arr[i] << " ";
        if (arr[i] <= arr[i - 1]) {
            return false; // Found an element that is not greater than the previous one
        }
    }
    return true; // All elements are in sorted order
}

//2.0

bool CheckBSTUtil(Node *root, int minVal, int maxVal) {
    if (!root) return true;

    // Check if the current node's value is within the valid range
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }

    // Recursively check the left and right subtrees with updated ranges
    return CheckBSTUtil(root->left, minVal, root->data) &&
 CheckBSTUtil(root->right, root->data, maxVal);
}


//3.0

bool BST(Node *root,int &prev) {
    if (!root) return true;

    // Check left subtree
    if (!BST(root->left, prev)) return false;

    // Check current node
    if (root->data <= prev) return false;
    prev = root->data; // Update previous value

    // Check right subtree
    if(!BST(root->right, prev)) return false;

    return true;
}





int main()
{
    Node *root = nullptr;

    // Constructing a BST
    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // Check if the tree is a BST
    if (checkBST(root)) {
        cout << "The tree is a Binary Search Tree (BST)." << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree (BST)." << endl;
    }

    if( CheckBSTUtil(root, INT_MIN, INT_MAX)) {
        cout << "The tree is a Binary Search Tree (BST) using the second method." << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree (BST) using the second method." << endl;
    }


    int prev = INT_MIN; 
     if(BST(root,prev) ){
        cout << "The tree is a Binary Search Tree (BST) using the third method." << endl;       
    } else {
        cout << "The tree is NOT a Binary Search Tree (BST) using the third method." << endl;
    }   



    return 0;
}   