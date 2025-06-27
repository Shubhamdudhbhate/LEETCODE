#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <stack>
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


 void Fixing2Node_Recursive(Node *root, Node *&first, Node *&second, Node *&prev)
{   
    if (!root)
        return;

    Fixing2Node_Recursive(root->left, first, second, prev);

    if (prev && root->data < prev->data)
    {
        if (!first)
            first = prev;

        second = root;
    }
    prev = root;

    Fixing2Node_Recursive(root->right, first, second, prev);

}


void FixBST_Rec(Node *root )
{
    Node *first = nullptr, *second = nullptr, *prev = nullptr;
    Fixing2Node_Recursive(root, first, second, prev);
 // only one time swap is needed if multiple pairs are found then we need to swap only the first and last elements
    if (first && second)
    {
        swap(first->data, second->data);
    }
}






void Fixing2Node_Iterative(Node *root, Node *&first, Node *&second)
{
    Node *prev = nullptr;
    Node *current = root;
   stack<Node *> stack;

    while (current || !stack.empty())
    {
        while (current)
        {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        if (prev && current->data < prev->data)
        {
            if (!first)
                first = prev;

            second = current;
        }
        prev = current;

        current = current->right;
    }
}



void FixBST_iter(Node *root )
{
    Node *first = nullptr, *second = nullptr, *prev = nullptr;
    Fixing2Node_Iterative(root, first, second);
 // only one time swap is needed if multiple pairs are found then we need to swap only the first and last elements
    if (first && second)
    {
        swap(first->data, second->data);
    }
}

















int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);



    vector<int> arr1;
    inorder(root, arr1);

    for (int val : arr1)
        cout << val << " ";





    // Intentionally swapping two nodes to create an invalid BST
    swap(root->left->data, root->right->data); // 5 and 15 are swapped
    vector<int> arr2;
    cout<<endl;
    inorder(root, arr2);

    for (int val : arr2)
        cout << val << " ";
    



    FixBST_iter(root);
    cout << endl;
    vector<int> arr3;
    inorder(root, arr3);
    for (int val : arr3)
        cout << val << " ";



    cout << endl;



    FixBST_Rec(root);
    cout << endl;   
    vector<int> arr4;
    inorder(root, arr4);


    for (int val : arr4)
        cout << val << " ";     

    cout << endl;

    return 0;
}