#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Step 1: Insert into BST
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Step 2: Build BST from Max Heap array
Node* buildBSTFromHeap(vector<int>& heap) {
    Node* root = nullptr;
    for (int val : heap) {
        root = insertBST(root, val);
    }
    return root;
}

// In-order traversal to verify BST
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}





int main() {
    // Max Heap array (not BST)
    vector<int> maxHeap = {100, 50, 80, 20, 40, 70, 60};

    Node* bstRoot = buildBSTFromHeap(maxHeap);

    cout << "Inorder of BST: ";
    inorder(bstRoot); // Output will be sorted
    return 0;
}

