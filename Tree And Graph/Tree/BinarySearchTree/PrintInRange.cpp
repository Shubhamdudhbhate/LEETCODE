#include <iostream>
#include <vector>
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

void Find(Node *root, int low, int high, vector<int> &result)
{
    if (!root)
        return;

    if (root->data > low && root->data > high)
    {
        Find(root->left, low, high, result);
    }
    else if (root->data < low && root->data < high)
    {
        Find(root->right, low, high, result);
    }
    else
    {

        Find(root->left, low, high, result);
        result.push_back(root->data);
        Find(root->right, low, high, result);
    }
}

vector<int> PrintInRange(Node *root, int low, int high)
{
    vector<int> result;
    Find(root, low, high, result);
    return result;
}

int main()
{
    // Sample Tree
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    int low = 7, high = 15;

    vector<int> result = PrintInRange(root, low, high);

    cout << "Nodes in range [" << low << ", " << high << "]: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}