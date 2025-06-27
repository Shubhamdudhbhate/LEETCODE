#include <iostream>
#include <vector>
using namespace std;

// ---------- Tree Node Class ----------
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int value)
    {
        val = value;
        left = right = NULL;
    }
};

// ---------- Solution Class ----------

class Solution
{
public:
    // int maxTime = 0;

    // // Burn all downward nodes from this node at a given time
    // void burnTreeFromNode(TreeNode* node, int time, TreeNode* block) {
    //     if (!node || node == block) return;

    //     maxTime = max(maxTime, time);

    //     burnTreeFromNode(node->left, time + 1, block);
    //     burnTreeFromNode(node->right, time + 1, block);
    // }

    // // Main DFS: returns distance from target node to current node
    // int dfs(TreeNode* root, int target) {
    //     if (!root) return -1;

    //     if (root->val == target) {
    //         burnTreeFromNode(root, 0, NULL);  // Start fire from here
    //         return 1;  // Return 1 to parent, meaning this child is burning
    //     }

    //     int left = dfs(root->left, target);
    //     if (left != -1) {
    //         burnTreeFromNode(root, left, root->left);
    //         return left + 1;
    //     }

    //     int right = dfs(root->right, target);
    //     if (right != -1) {
    //         burnTreeFromNode(root, right, root->right);
    //         return right + 1;
    //     }

    //     return -1;
    // }

    // int burnTree(TreeNode* root, int target) {
    //     maxTime = 0;
    //     dfs(root, target);
    //     return maxTime;

    // }

    int Burn(Node *root, int &time, int target)
    {

        if (root == NULL)
            return 0;

        if (root->val == target)
        {
            return -1;
        }

        int left = Burn(root->left, time, target);   // to find the distance of the target node in the left subtree
        int right = Burn(root->right, time, target); // to find the distance of the target node in the right subtree

        if (left < 0)
        {
            time = max(time, abs(left) + right);
            return left - 1;
        }
        else if (right < 0)
        {
            time = max(time, abs(right) + left);
            return right - 1;
        }else{

         return 1 + max(left, right);  // returning the height of the tree from the current node

        }

        return -1;
    }





     void find (Node *root, int target, Node *&Burn) {

        if(root == NULL)
            return;

        if(root->val == target) {
            Burn = root;   


            find(root->left, target, Burn);  // search in left subtree
            find(root->right, target, Burn); // search in right subtree 
     }

    }
       int height(Node *root) {

        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));

     }
    

     int minTime(Node *root, int target)
    {
        int time = 0;
        Burn(root, time, target);


     Node*Burn = NULL;
     find(root, target, Burn);

      int TimeHeight = height(Burn)-1;

        return time;
    }

};


int main (){

    Solution sol;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 5;
    int time = 0;

    int result = sol.minTime(root, target);
    cout << "Minimum time to burn the tree from target node " << target << " is: " << result << endl;

    return 0;

}