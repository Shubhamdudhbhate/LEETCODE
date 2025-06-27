#include <iostream>
#include <queue>
#include <utility> // for std::pair

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isCousins(TreeNode *root, int x, int y)
{
    if (!root)
        return false;

    queue<pair<TreeNode *, TreeNode *>> q; // {node, parent}
    q.push({root, NULL});

    while (!q.empty())
    {
        int size = q.size();
        TreeNode *parentX = NULL;
        TreeNode *parentY = NULL;

        for (int i = 0; i < size; i++)
        {
            pair<TreeNode *, TreeNode *> current = q.front();
            q.pop();
            TreeNode *node = current.first;
            TreeNode *parent = current.second;

            if (node->val == x)
                parentX = parent;
            if (node->val == y)
                parentY = parent;

            if (node->left)
                q.push({node->left, node});
            if (node->right)
                q.push({node->right, node});
        }

        // After one level
        if (parentX && parentY)
        {
            return parentX != parentY; // Same level, different parent
        }
        else if (parentX || parentY)
        {
            return false; // One found, other not → can't be cousins
        }
    }

    return false;
}

int main()
{
    /*
            1
           / \
          2   3
           \   \
            4   5
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << (isCousins(root, 4, 5) ? "Yes, cousins" : "No, not cousins") << endl;

    return 0;
}
