#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;

    // Swap children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert left and right
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Utility: Inorder traversal to print tree
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Tree before:
             1
            / \
           2   3
          / \
         4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder before mirror: ";
    inorder(root);
    cout << endl;

    invertTree(root);

    cout << "Inorder after mirror: ";
    inorder(root);
    cout << endl;

    return 0;
}
