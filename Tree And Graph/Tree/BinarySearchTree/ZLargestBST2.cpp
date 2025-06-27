#include <iostream>
#include <climits>
using namespace std;

// ----------------- Node Structure -----------------
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// ----------------- Info Structure -----------------
// For returning multiple values from each subtree
struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;

    Info(bool is_bst, int sz, int mn, int mx)
        : isBST(is_bst), size(sz), minVal(mn), maxVal(mx) {}
};

// ----------------- Solution Class -----------------
class Solution {
public:
    int maxBSTSize = 0;

    // Postorder traversal to check if subtree is BST
    Info largestBSTSubtree(Node* root) {
        if (!root) return Info(true, 0, INT_MAX, INT_MIN);

        Info left = largestBSTSubtree(root->left);
        Info right = largestBSTSubtree(root->right);

        if (left.isBST && right.isBST &&
            root->data > left.maxVal && root->data < right.minVal) {

            int size = left.size + right.size + 1;
            maxBSTSize = max(maxBSTSize, size);

            return Info(true, size,
                        min(root->data, left.minVal),
                        max(root->data, right.maxVal));
        }

        return Info(false, 0, 0, 0);
    }

    int largestBST(Node* root) {
        maxBSTSize = 0;
        largestBSTSubtree(root);
        return maxBSTSize;
    }
};

// ----------------- Create Test Tree -----------------
Node* buildTestTree() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->left = new Node(7);  // Violates BST
    root->right->right = new Node(20);
    return root;
}

// ----------------- Main Function -----------------
int main() {
    Node* root = buildTestTree();

    Solution s;
    int result = s.largestBST(root);
    cout << "Largest BST size in the tree: " << result << endl;

    return 0;
}
