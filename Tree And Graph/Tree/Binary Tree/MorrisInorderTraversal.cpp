#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


class Solution
{   
    public:

  vector<int>inorder(Node*root) {   // Morris Inorder Traversal o(n) time and o(1) space
        vector<int>Ans;
        if (!root)
            return Ans;

        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                Ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    Ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return Ans;
    }


vector<int> preorder(Node*root, vector<int>&Ans) {   // Morris Preorder Traversal o(n) time and o(1) space
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                Ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    Ans.push_back(curr->data);
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return Ans;
    }
    
    
    vector<int>postorder(Node*root, vector<int>&Ans) {   // Morris Postorder Traversal o(n) time and o(1) space
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->right == NULL)
            {
                Ans.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                Node *prev = curr->right;
                while (prev->left && prev->left != curr)
                    prev = prev->left;

                if (prev->left == NULL)
                {
                    prev->left = curr;
                    Ans.push_back(curr->data);
                    curr = curr->right;
                }
                else
                {
                    prev->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(Ans.begin(), Ans.end());
        return Ans;
    }


  };


  int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    
    vector<int> inorderResult = sol.inorder(root);
    vector<int> preorderResult;
    sol.preorder(root, preorderResult);
    vector<int> postorderResult;
    sol.postorder(root, postorderResult);

    cout << "Inorder: ";
    for (int val : inorderResult) cout << val << " ";
    cout << "\nPreorder: ";
    for (int val : preorderResult) cout << val << " ";
    cout << "\nPostorder: ";
    for (int val : postorderResult) cout << val << " ";

    return 0;
  }