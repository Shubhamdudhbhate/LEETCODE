#include <iostream>
#include <vector>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Step 1: Inorder traversal to collect sorted values

void storeInorder(Node* root, vector<int>& inorder) {
    if (!root) return;
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

// Step 2: Postorder traversal to overwrite values in Max Heap order
void convertToMaxHeap(Node* root, vector<int>& inorder, int& index) {
    if (!root) return;
    convertToMaxHeap(root->left, inorder, index);
    convertToMaxHeap(root->right, inorder, index);
    root->data = inorder[index--]; // reverse of sorted
}

// Step 3: Master function
void BSTtoMaxHeap(Node* root) {
    vector<int> inorder;
    storeInorder(root, inorder);     // get sorted data
    int index = inorder.size() - 1;  // start from end
    convertToMaxHeap(root, inorder, index);
}

// Print tree in preorder (to check Max Heap order)
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}



int main() {
    /*
           4
         /   \
        2     6
       / \   / \
      1  3  5  7
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    BSTtoMaxHeap(root);

    cout << "Preorder of converted Max Heap: ";
    preorder(root);  // Should show max at top, decreasing order
    return 0;
}
