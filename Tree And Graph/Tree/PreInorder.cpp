#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ------------------ Tree Node Definition ------------------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ------------------ Utility Function to Print Inorder ------------------
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// ------------------ Recursive Build from Preorder & Inorder (Map Based) ------------------
class Solution {
public:
    int preIndex = 0;

    TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];

        root->left = buildTreeRecursive(preorder, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTreeRecursive(preorder, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        return buildTreeRecursive(preorder, inorder, 0, inorder.size() - 1, inMap);
    }
};

// ------------------ Build from Inorder & Postorder ------------------
int find(int in[], int val, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (in[i] == val) return i;
    }
    return -1;
}

TreeNode* buildFromInPost(int in[], int post[], int inStart, int inEnd, int& index) {
    if (inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(post[index--]);
    int pos = find(in, root->val, inStart, inEnd);

    root->right = buildFromInPost(in, post, pos + 1, inEnd, index); // right first
    root->left  = buildFromInPost(in, post, inStart, pos - 1, index);

    return root;
}

// ------------------ Build from Inorder & Preorder ------------------
TreeNode* buildFromInPre(int in[], int pre[], int inStart, int inEnd, int& index) {
    if (inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(pre[index++]);
    int pos = find(in, root->val, inStart, inEnd);

    root->left  = buildFromInPre(in, pre, inStart, pos - 1, index);
    root->right = buildFromInPre(in, pre, pos + 1, inEnd, index);

    return root;
}

// ------------------ Main Driver ------------------
int main() {
    // Build from Inorder & Postorder
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);
    int postIndex = n - 1;

    TreeNode* root1 = buildFromInPost(in, post, 0, n - 1, postIndex);
    cout << "Tree from Inorder + Postorder (Inorder Traversal): ";
    printInorder(root1);
    cout << endl;

    // Build from Inorder & Preorder
    int pre[] = {1, 2, 4, 8, 5, 3, 6, 7};
    int preIndex = 0;

    TreeNode* root2 = buildFromInPre(in, pre, 0, n - 1, preIndex);
    cout << "Tree from Inorder + Preorder (Inorder Traversal): ";
    printInorder(root2);
    cout << endl;

    // Build using vector-based optimized approach (Preorder + Inorder with Hashmap)
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root3 = sol.buildTree(preorder, inorder);
    cout << "Tree from Preorder + Inorder (HashMap Method) (Inorder Traversal): ";
    printInorder(root3);
    cout << endl;

    return 0;
}
