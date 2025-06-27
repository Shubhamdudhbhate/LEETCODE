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

// Recursive function to build BST from postorder
Node* buildBSTFromPostorder(vector<int>& postorder, int& index, int minVal, int maxVal) {
    if (index < 0) return nullptr;

    int val = postorder[index];

    // Value must lie within bounds
    if (val < minVal || val > maxVal) return nullptr;

    // Create the root node
    Node* root = new Node(val);
    index--;  // move to the next value (from end to start)

    // Important: build right first, then left
    root->right = buildBSTFromPostorder(postorder, index, val + 1, maxVal);
    root->left = buildBSTFromPostorder(postorder, index, minVal, val - 1);

    return root;
}

// Entry function
Node* postorderToBST(vector<int>& postorder) {
    int index = postorder.size() - 1;  // Start from the last element
    return buildBSTFromPostorder(postorder, index, INT_MIN, INT_MAX);
}

// Utility function to check the result with inorder (should be sorted for BST)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> postorder = {1, 7, 5, 50, 40, 10};

    Node* root = postorderToBST(postorder);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);  // Output: 1 5 7 10 40 50
    return 0;
}
