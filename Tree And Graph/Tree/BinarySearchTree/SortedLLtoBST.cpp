#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};





TreeNode* BuildBST(vector<int>&Tree, int start, int end) {
    if (start > end) return NULL;

    // Find the middle element
    int mid = start + (end - start +1) / 2;
    
    TreeNode* root = new TreeNode(Tree[mid]);

    root->left = BuildBST(Tree, start, mid - 1);
    root->right = BuildBST(Tree, mid + 1, end);
    
    return root;
}


 TreeNode* sortedListToBST(ListNode* head) {


    vector<int> Tree;
    while (head) {
        Tree.push_back(head->val);
        head = head->next;
    }

    // Build BST from sorted vector
    return BuildBST(Tree, 0, Tree.size() - 1);

}


int main() {
    // Sample sorted linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    TreeNode* root = sortedListToBST(head);

    // Output the root value of the BST
    cout << "Root of BST: " << root->val << endl; // Should print 3 for this example

    return 0;
}