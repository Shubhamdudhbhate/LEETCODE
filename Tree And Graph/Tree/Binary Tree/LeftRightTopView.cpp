#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void leftView(TreeNode *root)
{
    if (!root)
        return;

    vector<int> Ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size(); // number of nodes at current level

        for (int i = 0; i < size; i++)
        {

            TreeNode *curr = q.front();
            q.pop();

            // First node at this level
            if (i == 0)
                cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}
// Ans.push_back(q.front()->val);

//  while(size--){

//     TreeNode* curr = q.front(); q.pop();

//     if (curr->left) q.push(curr->left);
//     if (curr->right) q.push(curr->right);
// }

// void leftView(TreeNode* root, int level, vector<int>& Ans) {
//     if (!root) return;

//     if (level == Ans.size()) {
//         Ans.push_back(root->val);
//     }
//     leftView(root->left, level + 1, Ans);
//     leftView(root->right, level + 1, Ans);
// }

//__________________________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________________________

// right view of the binary tree
void rightView(TreeNode *root)
{
    if (!root)
        return;

    vector<int> Ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size(); // number of nodes at current level

        for (int i = 0; i < size; i++)
        {

            TreeNode *curr = q.front();
            q.pop();

            // First node at this level
            if (i == size - 1)
                cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        // Ans.push_back(q.front()->val);
        //  while(size--){

        // TreeNode* curr = q.front(); q.pop();
        // if (curr->right) q.push(curr->right);
        // if (curr->left) q.push(curr->left);
        // }

        // void rightView(TreeNode* root, int level, vector<int>& Ans) {
        //     if (!root) return;
        //     if (level == Ans.size()) {
        //         Ans.push_back(root->val);
        //     }
        //     rightView(root->right, level + 1, Ans);
        //     rightView(root->left, level + 1, Ans);
        // }
    }
}

//__________________________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________________________

class solution
{
public:
    void find(TreeNode *root, int pos, int &l, int &r)
    {

        if (!root)
            return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<int> TopViews(TreeNode *root)
    {

        int l = 0, r = 0;
        find(root, 0, l, r);
        vector<int> Ans(r - l + 1);
        vector<bool> Filled(r - l + 1, false);

        queue<TreeNode *> q;
        queue<int> idx;

        q.push(root);
        idx.push(-l);

        while (!q.empty())
        {

            TreeNode *curr = q.front();
            q.pop();

            int pos = idx.front();
            idx.pop();

            if (!Filled[pos])
            {
                Ans[pos] = curr->val;
                Filled[pos] = true;
            }

            if (curr->left)
            {
                q.push(curr->left);
                idx.push(pos - 1);
            }

            if (curr->right)
            {
                q.push(curr->right);
                idx.push(pos + 1);
            }
        }

        return Ans;
    }
};

//__________________________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________________________

// Recursive function to build top view map

void solve(TreeNode *root, int pos, int level, map<int, pair<int, int>> &topMap)
{

    if (topMap.find(pos) == topMap.end() || level < topMap[pos].second)
    {
        topMap[pos] = {root->val, level};
    }

    solve(root->left, pos - 1, level + 1, topMap);
    solve(root->right, pos + 1, level + 1, topMap);
}

void topView(TreeNode *root)
{
    map<int, pair<int, int>> topMap;
    solve(root, 0, 0, topMap);

    for (auto &it : topMap)
    {
        cout << it.second.first << " ";
    }
    cout << endl;
}

//__________________________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________________________

class Solution
{
public:
    void find(TreeNode *root, int pos, int &l, int &r)
    {

        if (!root)
            return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    void Tview(TreeNode *root, int pos, vector<int> &Ans, vector<int> &Level, int l)
    {

        if (!root)
            return;

        if (Level[pos] > l)
        {
            Ans[pos] = root->val;
            Level[pos] = l;
        }

        Tview(root->left, pos - 1, Ans, Level, l + 1);
        Tview(root->right, pos + 1, Ans, Level, l + 1);
    }

    vector<int> Topview(TreeNode *root)
    {

        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<int> Ans(r - l + 1);
        vector<int> Level(r - l + 1, INT_MAX);

        Tview(root, -1 * l, Ans, Level, 0);

        return Ans;
    }
};
// void TopView(TreeNode *root)
// {
//     if (!root)
//         return;

//     vector<int> Ans;
//     queue<TreeNode *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         int size = q.size(); // number of nodes at current level

//         for (int i = 0; i < size; i++)
//         {

//             TreeNode *curr = q.front();
//             q.pop();

//             // First node at this level
//             if (i == 0 || i == size - 1)
//              if(curr->val!=-1){
//                 cout << curr->val << " ";
//              }
//             if (curr->left)
//                 q.push(curr->left);
//             if (curr->right)
//                 q.push(curr->right);
//         }
//     }
// }

class SolutionB
{
public:
    // Step 1: Find min and max horizontal positions
    void find(TreeNode *root, int pos, int &l, int &r)
    {
        if (!root)
            return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    // Step 2: Recursively build bottom view
    void Bview(TreeNode *root, int pos, vector<int> &Ans, vector<int> &Level, int depth)
    {
        if (!root)
            return;

        // Update if deeper level found for this vertical
        if (Level[pos] <= depth)
        {
            Ans[pos] = root->val;
            Level[pos] = depth;
        }

        Bview(root->left, pos - 1, Ans, Level, depth + 1);
        Bview(root->right, pos + 1, Ans, Level, depth + 1);
    }

    // Step 3: Main function
    vector<int> Bottomview(TreeNode *root)
    {
        int l = 0, r = 0;
        find(root, 0, l, r);

        int width = r - l + 1;
        vector<int> Ans(width);
        vector<int> Level(width, -1); // For bottom view, store max depth (start with -1)

        Bview(root, -l, Ans, Level, 0); // -l to shift index to 0

        return Ans;
    }
};

int main()
{
    // Example usage:
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Left view of the binary tree: ";
    leftView(root); // Output: 1 2 4

    cout << "\nRight view of the binary tree: ";
    rightView(root); // Output: 1 3 6

    solution sol1;
    Solution sol2;
    SolutionB sol3;



    
    cout << "\nTop view of the binary tree: ";

    vector<int> topView = sol2.Topview(root);
    for (int val : topView)
    {
        cout << val << " ";
    }





    cout << "\nTop view of the binary tree: " << endl;
    vector<int> topView2 = sol1.TopViews(root);

    for (int val : topView2)
    {
        cout << val << " ";
    }




    cout << "\nBottom view of the binary tree using map: ";
    vector<int> BottomView = sol3.Bottomview(root); // Output: 4 2 1 3 6
    for (int val : BottomView)
    {
        cout << val << " ";
    }

    cout << endl;
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    cout << endl;
    // Return 0 to indicate successful execution
    cout << "Program executed successfully." << endl;

    return 0;
}