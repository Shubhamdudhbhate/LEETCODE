#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

bool canRepresentBST(vector<int>& preorder) {
    stack<int> s;

    int root = INT_MIN;

    for (int val : preorder) {
        // If we find a node smaller than the allowed root value → invalid BST
        if (val < root)
            return false;

        // Keep popping elements that are smaller than current value
        // These popped values become the new "root" (moving to right subtree)
        while (!s.empty() && s.top() < val) {
            root = s.top();
            s.pop();
        }

        // Push current value to stack
        s.push(val);
    }

    return true;  // If we completed loop without conflict
}


int main() {
    vector<int> preorder1 = {10, 5, 1, 7, 40, 50};  // ✅ Valid
    vector<int> preorder2 = {10, 5, 40, 7, 50};     // ❌ Invalid

    cout << "Preorder 1 is " << (canRepresentBST(preorder1) ? "VALID" : "INVALID") << " BST.\n";
    cout << "Preorder 2 is " << (canRepresentBST(preorder2) ? "VALID" : "INVALID") << " BST.\n";

    return 0;
}
