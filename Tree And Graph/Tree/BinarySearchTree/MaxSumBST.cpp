#include <iostream>
#include <climits>
using namespace std;

// ------------------ Tree Node ------------------
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// ------------------ Info Structure ------------------
struct Info {
    bool isBST;
    int sum;
    int minVal;
    int maxVal;
    Node* bstRoot;

    Info(bool is_bst, int s, int mn, int mx, Node* root)
        : isBST(is_bst), sum(s), minVal(mn), maxVal(mx), bstRoot(root) {}
};

// ------------------ Solution Class ------------------
class Solution {
public:
    int maxSum = 0;
    Node* maxRoot = nullptr;

    Info findMaxSumBST(Node* root) {
        if (!root)
            return Info(true, 0, INT_MAX, INT_MIN, nullptr);

        Info left = findMaxSumBST(root->left);
        Info right = findMaxSumBST(root->right);

        // If left and right subtrees are BSTs and root is valid
        if (left.isBST && right.isBST &&
            root->data > left.maxVal && root->data < right.minVal) {

            int sum = left.sum + right.sum + root->data;

            if (sum > maxSum) {
                maxSum = sum;
                maxRoot = root;
            }

            return Info(true, sum,
                        min(root->data, left.minVal),
                        max(root->data, right.maxVal),
                        root);
        }

        // Not a BST
        return Info(false, 0, 0, 0, nullptr);
    }

    Node* maxSumBSTinBinaryTree(Node* root) {
        maxSum = 0;
        maxRoot = nullptr;
        findMaxSumBST(root);
        return maxRoot;
    }
};

// ------------------ Print Inorder ------------------
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// ------------------ Build Sample Tree ------------------
Node* buildTestTree() {
    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(6);
    return root;
}

// ------------------ Main ------------------
int main() {
    Node* root = buildTestTree();

    Solution sol;
    Node* bstRoot = sol.maxSumBSTinBinaryTree(root);

    cout << "Maximum Sum BST Subtree Inorder: ";
    printInorder(bstRoot);
    cout << "\nMax Sum: " << sol.maxSum << endl;

    return 0;
}
