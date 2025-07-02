#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Step 1: Count total number of nodes
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Step 2: Check if tree is complete
bool isComplete(Node* root, int index, int totalNodes) {
    if (!root) return true;
    if (index >= totalNodes) return false;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Step 3: Check heap property (max heap)
bool isHeapOrder(Node* root) {
    // Leaf node or null
    if (!root || (!root->left && !root->right)) return true;

    // Only left child
    if (root->left && !root->right)
        return (root->data >= root->left->data) && isHeapOrder(root->left);



// NOT NECESSARY  but 🔒 Still, for safety
// Only right child — invalid in a complete binary tree 
    if (!root->left && root->right)
        return false;



    // Both children
    if (root->left && root->right)
        return (root->data >= root->left->data &&
                root->data >= root->right->data &&
                isHeapOrder(root->left) &&
                isHeapOrder(root->right));

    return false; // Should never reach here
}

// Main check function
bool isHeap(Node* root) {
    int total = countNodes(root);
    return isComplete(root, 0, total) && isHeapOrder(root);
}




int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    if (isHeap(root))
        cout << "Yes, it is a Max Heap." << endl;
    else
        cout << "No, it is not a Heap." << endl;

    return 0;
}
