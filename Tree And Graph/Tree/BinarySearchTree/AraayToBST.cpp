#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
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

void ArrayToBSTUtil(Node *&root, vector<int> &arr, int &index)
{
    if (index >= arr.size())
        return;

    // Create a new node with the current value
    root = new Node(arr[index++]);

    // Recursively build the left and right subtrees
    ArrayToBSTUtil(root->left, arr, index);
    ArrayToBSTUtil(root->right, arr, index);
}




void ArrayToBST(vector<int> &arr, int start, int end, vector<int> &ans)
{

    if (start > end)
        return;
    int mid = (start + end) / 2;

    ans.push_back(arr[mid]);

    ArrayToBST(arr, start, mid - 1, ans);
    ArrayToBST(arr, mid + 1, end, ans);
}



vector<int>SortedArrayToBST(vector<int> &arr, Node *&root)
{

    vector<int> ans;
    ArrayToBST(arr,0,arr.size()-1,ans);

    return ans;
}





void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

int main()
{
    // Example array to convert to BST
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    // reverse sort the array to ensure it is in descending order
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    Node *root = nullptr;
    int index = 0;

    // Convert the sorted array to a BST
    ArrayToBSTUtil(root, arr, index);

    // Print inorder traversal of the BST
    cout << "1.Inorder traversal of the BST: ";

    vector<int> inorderArr;
    inorder(root, inorderArr);
    for (int val : inorderArr)
    {
        cout << val << " ";
    }
    cout << endl;



    arr = {10, 20, 30, 40, 50, 60, 70};
    vector<int> inorderd;
    SortedArrayToBST(arr, root);    
    cout << "2.Sorted array converted to BST: ";
    // inorder 
    inorder(root, inorderd);

    for (int val : inorderd)
    {
        cout << val << " ";
    }

    return 0;
}