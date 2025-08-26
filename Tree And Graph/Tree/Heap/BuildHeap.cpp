#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;
    int TotalSize;

    MaxHeap(int capacity)
    {
        arr = new int[capacity];
        size = 0;
        TotalSize = capacity;
    }



    void heapifyDown(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }



    
    // Build heap from an array
    void buildHeap(int input[], int n)
    {
        if (n > TotalSize)
        {
            cout << "Input size exceeds capacity!" << endl;
            return;
        }

        // Copy input array to heap array
        for (int i = 0; i < n; i++)
        {
            arr[i] = input[i];
        }
        size = n;

        // Heapify from last non-leaf node
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }

        cout << "Heap built successfully." << endl;
    }

    void print()
    {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap()
    {
        delete[] arr;
    }
};



int main()
{
    int input[] = {20, 50, 30, 10, 60, 90, 40};
    int n = sizeof(input) / sizeof(input[0]);

    MaxHeap heap(20);
    heap.buildHeap(input, n);

    heap.print();

    return 0;
}
