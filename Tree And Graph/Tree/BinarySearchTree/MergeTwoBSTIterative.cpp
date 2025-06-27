#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <stack>
#include <iterator>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};


void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

vector<int> MergeTwoBSTIterative(Node *root1, Node *root2)
{
 stack<Node*> stack1, stack2;
 vector<int> result;    
    Node *current1 = root1, *current2 = root2;
    while (current1 || !stack1.empty() || current2 || !stack2.empty())
    {
        while (current1)
        {
            stack1.push(current1);
            current1 = current1->left;
        }
        while (current2)
        {
            stack2.push(current2);
            current2 = current2->left;
        }

        if (!stack2.empty() && (stack1.empty() || stack2.top()->data < stack1.top()->data))
        {
            current2 = stack2.top();
            stack2.pop();
            result.push_back(current2->data);
            current2 = current2->right;
        }
        else
        {
            current1 = stack1.top();
            stack1.pop();
            result.push_back(current1->data);
            current1 = current1->right;
        }
    }

    return result;
}



int main()
{
    Node *root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    vector<int> mergedResult = MergeTwoBSTIterative(root1, root2);

    cout << "Merged BST elements: ";
    for (int val : mergedResult)
        cout << val << " ";
    cout << endl;

    return 0;
}


