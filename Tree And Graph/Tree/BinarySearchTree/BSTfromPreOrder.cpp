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

// Recursive function to build BST from preorder using index
Node* buildBSTFromPreorder(vector<int>& preorder, int& index, int minVal, int maxVal) {
    if (index >= preorder.size()) return nullptr;

    int val = preorder[index];

    if (val < minVal || val > maxVal)
        return nullptr;

    Node* root = new Node(val);
    index++;

    // All left children must be < val
    root->left = buildBSTFromPreorder(preorder, index, minVal, val - 1);

    // All right children must be > val
    root->right = buildBSTFromPreorder(preorder, index, val + 1, maxVal);

    return root;
}

// Main function to call
Node* preorderToBST(vector<int>& preorder) {
    int index = 0;
    return buildBSTFromPreorder(preorder, index, INT_MIN, INT_MAX);
}

// Utility to print inorder (should be sorted for a BST)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    Node* root = preorderToBST(preorder);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root); // Should print: 1 5 7 10 40 50

    return 0;
}
