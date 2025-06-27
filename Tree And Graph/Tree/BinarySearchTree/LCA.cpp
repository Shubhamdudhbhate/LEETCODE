#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


Node* LCA(Node* root, int p, int q) {
    if (!root)
        return root;


    if(root->data > p && root->data > q) {
        return LCA(root->left, p, q);
    } else if (root->data < p && root->data < q) {
        return LCA(root->right, p, q);
    }else{
    return root; 
    }
}

int main() {
    // Sample Tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    int p = 5;  // Node 5
    int q = 1;  // Node 1

    Node* lca = LCA(root, p, q);
    cout << "LCA: " << lca->data << endl;  // Output: 3

    return 0;
}

