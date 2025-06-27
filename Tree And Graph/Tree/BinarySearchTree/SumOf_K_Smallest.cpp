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


void inorder(Node *root, vector<int> &arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

int SumOfKSmallestUtil(Node *root, int &k, int &sum) {
    if (!root || k <= 0) return sum;

    // Traverse left subtree
    SumOfKSmallestUtil(root->left, k, sum);

    // Process current node
    if (k > 0) {
        sum += root->data;
        k--;
    }

    // Traverse right subtree
    SumOfKSmallestUtil(root->right, k, sum);

    return sum;
}       


int KthLargestUtil(Node *root, int &k, int&large) { // helps to arrange element in descending order

    if (!root || k <= 0) return -1;

    // Traverse right subtree first
     KthLargestUtil(root->right, k,large);



    if (k == 1) {
        large= root->data;
        return large;
    }

        k--;

    // Traverse left subtree
     KthLargestUtil(root->left, k,large);

    return -1; // Return the largest element found
}


int main() {




    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int k = 3;
    int p = k; // Number of smallest elements to sum
    int sum = 0;





  //Print the inorder traversal of the BST
    vector<int> arr;            
    inorder(root, arr);
    cout << "Inorder traversal of the BST: ";   
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;





    int result = SumOfKSmallestUtil(root, k, sum);
    if (k > 0) {
        cout << "Not enough elements in the BST to sum " << k << " smallest elements." << endl;
        return 0;
    }
    cout << "Sum of the " << p << " smallest elements in the BST is: " << result << endl;




    k = 4; 
    p=k;
    int large = -1; 
    int kthLargest = KthLargestUtil(root, --k, large);
    if (kthLargest != -1) {
        cout << "The " << p << "th largest element in the BST is: " << kthLargest << endl;
    } else {
        cout << "Not enough elements in the BST to find the " << p<< "th largest element." << endl;
    }



    return 0;
}