#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// ------------- Tree Node Class -------------
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) {
        val = value;
        left = right = NULL;
    }
};

// ------------- Solution Class -------------
class Solution {
public:

    // Step 1: Create Parent Map & Find Target Node
    TreeNode* createParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, int target) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* targetNode = NULL;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == target)
                targetNode = curr;

            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

    // Step 2: Burn the Tree using BFS
    int burnTree(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* targetNode = createParentMap(root, parentMap, target);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(targetNode);
        visited.insert(targetNode);
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burnedThisLevel = false;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();

                if (curr->left && visited.find(curr->left) == visited.end()) {
                    burnedThisLevel = true;
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    burnedThisLevel = true;
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if (parentMap.find(curr) != parentMap.end() && visited.find(parentMap[curr]) == visited.end()) {
                    burnedThisLevel = true;
                    visited.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }

            if (burnedThisLevel)
                time++;
        }

        return time;
    }
};





// ------------- Main Function -------------
int main() {
    // Manually creating a tree:
    /*
             1
            / \
           2   3
          / \
         4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int target = 2;
    cout << "Time to burn the tree = " << sol.burnTree(root, target) << endl;

    return 0;
}

