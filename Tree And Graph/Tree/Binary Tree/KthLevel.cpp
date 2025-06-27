#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Recursive function to build binary tree from preorder with -1 as NULL marker
int idx = 0;
Node* buildTree(vector<int>& preorder) {
    if (idx >= preorder.size() || preorder[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(preorder[idx++]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Print nodes at Kth level
void KthLevel(Node* root, int K) {
    if (root == NULL) return;

    if (K == 1) {
        cout << root->data << " ";
        return;
    }

    KthLevel(root->left, K - 1);
    KthLevel(root->right, K - 1);
}

int main() {
    vector<int> preorder = {1, 2, 7, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    KthLevel(root, 3);  // Print all nodes at level 3

    return 0;
}
