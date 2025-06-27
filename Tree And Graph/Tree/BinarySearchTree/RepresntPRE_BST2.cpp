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

class solution
{

public:


  void BST(int arr[], int &index, int minVal, int maxVal, int N)
    {
        // Base case: if index exceeds size of array
        if (index >= N)
            return;

        // If current value is within the valid range
        if (arr[index] > minVal && arr[index] < maxVal)
        {
            // Process current node
            int val = arr[index];
            index++;

            // Recur for left and right subtrees
            BST(arr, index, minVal, val, N);
            BST(arr, index, val, maxVal, N);
        }
    }





    int canRepresentBST(int arr[], int N)
    {
        {

            int index = 0;

            BST(arr, index, INT_MIN, INT_MAX, N);

            return index == N;
        }

    }

};




int main()
{
    solution sol;

    int arr1[] = {10, 5, 1, 7, 40, 50}; // Valid BST
    int arr2[] = {10, 5, 40, 7, 50};    // Invalid BST

    cout << "Array 1 is " << (sol.canRepresentBST(arr1, sizeof(arr1) / sizeof(arr1[0])) ? "VALID" : "INVALID") << " BST.\n";
    cout << "Array 2 is " << (sol.canRepresentBST(arr2, sizeof(arr2) / sizeof(arr2[0])) ? "VALID" : "INVALID") << " BST.\n";

    return 0;
}