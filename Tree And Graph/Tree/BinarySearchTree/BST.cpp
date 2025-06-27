#include <iostream>
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

// Insert node into BST
Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);

    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// if input is array
Node *insertArray(Node *root, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

// Inorder traversal (gives sorted order)
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search in BST
bool search(Node *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    else if (key > root->data)
        return search(root->right, key);
}


  Node*deleteNode(Node *&root, int key)
{
    if (!root)
        return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with one child or no child
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = root->right;
        while (temp && temp->left)
            temp = temp->left;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    Node *root1 = nullptr;

    root1 = insert(root1, 50);
    insert(root1, 30);
    insert(root1, 70);
    insert(root1, 20);
    insert(root1, 40);
    insert(root1, 60);
    insert(root1, 80);

    inorder(root1); // Output: 20 30 40 50 60 70 80
    cout << "\nSearch 60: " << (search(root1, 60) ? "Found" : "Not Found");





    Node *root2 = nullptr;

    int arr[] = {20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    root2 = insertArray(root2, arr, n);

    inorder(root2); // Output: 20 30 40 50 60 70 80
    cout << "\nSearch 20: " << (search(root2, 20) ? "Found" : "Not Found");


    root1 = deleteNode(root1, 20);
    cout << "\nAfter deleting 20: ";


    inorder(root1); // Output: 30 40 50 60 70 80
    cout << "\nSearch 20: " << (search(root1, 20)   ? "Found" : "Not Found");

}
