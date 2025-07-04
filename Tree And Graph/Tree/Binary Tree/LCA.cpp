#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q)
        return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}



int main() {
    // Sample Tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left;        // Node 5
    TreeNode* q = root->right;       // Node 1

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA: " << lca->val << endl;  // Output: 3

    return 0;
}
