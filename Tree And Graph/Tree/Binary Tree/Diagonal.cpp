#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> diagonalTraversal1(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        while (node)
        {
            result.push_back(node->val);
            if (node->left)
                q.push(node->left); // left child = next diagonal
            node = node->right;     // right child = same diagonal
        }
    }

    return result;
}

void find(TreeNode *root, int pos, int &l)
{

    if (!root)
        return;

    l = max(l, pos);
    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}

void findDig(TreeNode *root, int pos, vector<vector<int>> &result)
{
    if (!root)
        return;

    result[pos].push_back(root->val);

    findDig(root->left, pos + 1, result); // left child goes to next diagonal
    findDig(root->right, pos, result);    // right child stays on the same diagonal
}

vector<int>diagonalTraversal2(TreeNode *root)
{
    int l = 0;
    find(root, 0, l);
    vector<vector<int>> result(l + 1);

    findDig(root, 0, result);

    vector<int> temp;

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            temp.push_back(result[i][j]);
        }
    }

    return temp;
}

int main()
{
    // Example usage:
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Diagonal Traversal (Method 1): ";
    vector<int> result = diagonalTraversal1(root);
    for (int val : result)
    {
        cout << val << " ";
    }


    cout << endl;



    cout << "Diagonal Traversal (Method 2): " << endl;
    vector<int>result2 = diagonalTraversal2(root);

    for (int val : result2)
    {
        cout << val << " ";
    }

    return 0;
}