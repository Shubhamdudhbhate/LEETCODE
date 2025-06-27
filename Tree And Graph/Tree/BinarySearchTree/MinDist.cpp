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


void MinDistUtil(Node *root, int &minDist, int &prev)
{
    if (!root) return;

    // Traverse left subtree
    MinDistUtil(root->left, minDist, prev);

    // Calculate distance from previous node
    if (prev != -1) {
        minDist = min(minDist, abs(root->data - prev));
    }
    prev = root->data; // Update previous value

    // Traverse right subtree
    MinDistUtil(root->right, minDist, prev);
}


int main (){


    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int minDist = INT_MAX;
    int prev = -1; // Initialize previous value

    MinDistUtil(root, minDist, prev);

    if (minDist == INT_MAX) {
        cout << "The tree has no nodes." << endl;
    } else {
        cout << "Minimum distance between any two nodes is: " << minDist << endl;
    }

    return 0;


}