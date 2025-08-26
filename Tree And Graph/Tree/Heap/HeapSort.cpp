#include <iostream>
using namespace std;


void heapifyDown(int arr[], int size, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, size, largest);
    }
}


void buildMaxHeap(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapifyDown(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
  
    buildMaxHeap(arr, n);


    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);      
        heapifyDown(arr, i, 0);   
    }
}

// Utility Function to Print Array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}




// Driver Code
int main()
{
    int arr[] = {20, 50, 30, 10, 60, 90, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
