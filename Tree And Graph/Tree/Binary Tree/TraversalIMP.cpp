#include<iostream>
#include <vector>
#include <stack>
using namespace std;



class TreeNode {
public:     
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
public:

 vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root) s.push(root);
        
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);
            
            // Push right child first so that left child is processed first
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        
        return result;
    }

    vector<int>inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;
        
        while (current || !s.empty()) {
            while (current) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }
        
        return result;
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s1, s2;
        if (root) s1.push(root);
        
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            
            // Push left child first so that right child is processed first
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        
        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        
        return result;
    }



};