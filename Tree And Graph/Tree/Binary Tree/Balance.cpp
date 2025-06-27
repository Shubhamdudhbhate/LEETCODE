#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int checkHeight(TreeNode *root, bool &valid)
{
    if (!root)
        return 0;

    int left = checkHeight(root->left, valid);
    int right = checkHeight(root->right, valid);

    if (abs(left - right) > 1)
        valid = 0;
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root)
{
    bool valid = 1;

    checkHeight(root, valid);
    return valid;
    ;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    if (isBalanced(root))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is NOT balanced" << endl;

    return 0;
}
