#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Inorder traversal to get sorted values from BST
void inorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

// Function to get common nodes in two BSTs
vector<int> getCommonNodess(TreeNode *root1, TreeNode *root2)
{
    vector<int> a, b, result;

    inorder(root1, a); // sorted from BST1
    inorder(root2, b); // sorted from BST2

    int i = 0, j = 0;

    // Two pointer approach
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            result.push_back(a[i]);
            i++, j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}

vector<int>getCommonNodes(TreeNode *root1, TreeNode *root2)
{
    stack<TreeNode *> s1, s2;
    vector<int> result;

    while (true)
    {
        // Push all left children of root1
        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }

        // Push all left children of root2
        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }

        // If either stack is empty, we are done
        if (s1.empty() || s2.empty())
            break;

        TreeNode *top1 = s1.top();
        TreeNode *top2 = s2.top();

        // If both nodes are equal → common node found
        if (top1->val == top2->val)
        {
            result.push_back(top1->val);
            s1.pop();
            s2.pop();
            root1 = top1->right;
            root2 = top2->right;
        }
        // Move in the BST with smaller value
        else if (top1->val < top2->val)
        {
            s1.pop();
            root1 = top1->right;
        }
        else
        {
            s2.pop();
            root2 = top2->right;
        }
    }

    return result;
}


int main()
{
    // Sample BSTs
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);

    TreeNode *root2 = new TreeNode(7);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(9);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(5);

    vector<int> commonNodes = getCommonNodes(root1, root2);
    vector<int> commonNodes2 = getCommonNodess(root1, root2);   

    cout << "Common Nodes: ";
    for (int val : commonNodes)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Common Nodes (Alternative Method): ";
    for (int val : commonNodes2)
    {
        cout << val << " ";
    }   
    cout << endl;
    return 0;
}