#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;
    int ToatalSize;

    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        ToatalSize = n;
    }

    void insert(int value)
    {

        if (size == ToatalSize)
        {

            cout << "Heap Overflow" << endl;
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while (index > 0 && arr[(index - 1) / 2] < arr[index]) // compare  with parent upto last
        {

            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << "Is inserted into the heap" << endl;
    }

    void deleteMax()
    {
        if (size == 0)
        {
            cout << "Heap Underflow" << endl;
            return;
        }

        cout << "Deleted max element: " << arr[0] << endl;

        arr[0] = arr[size - 1];
        size--;

        int index = 0;

        // Heapify Down
        while (index < size)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest != index)
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else
                break;
        }
    }

    void print()
    {

        for (int i = 0; i < size; i++)
        {

            cout << arr[i] << " ";
        }
    }
};

int main()
{
    MaxHeap heap(10); // Max capacity 10

    heap.insert(50);
    heap.insert(30);
    heap.insert(60);
    heap.insert(20);
    heap.insert(90);
    heap.insert(70);

    heap.print();

    return 0;
}