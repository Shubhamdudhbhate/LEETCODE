#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void spiralOrder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s1; // Left to right
    stack<TreeNode*> s2; // Right to left

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        // Print left to right
        while (!s1.empty()) {
            TreeNode* node = s1.top(); s1.pop();
            cout << node->val << " ";

            // Left to right → push left then right
            if (node->left) s2.push(node->left);
            if (node->right) s2.push(node->right);
        }

        // Print right to left
        while (!s2.empty()) {
            TreeNode* node = s2.top(); s2.pop();
            cout << node->val << " ";

            // Right to left → push right then left
            if (node->right) s1.push(node->right);
            if (node->left) s1.push(node->left);
        }
    }
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    cout << "Spiral order traversal: ";
    spiralOrder(root);
    cout << endl;

    return 0;
}
