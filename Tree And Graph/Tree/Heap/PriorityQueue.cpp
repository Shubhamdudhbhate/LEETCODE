#include <iostream>
#include <cmath>  // for log2()
using namespace std;

class PriorityQueue {
private:
    int* arr;
    int size;
    int capacity;

    // Heapify Up - when inserting
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else break;
        }
    }

    // Heapify Down - when deleting max
    void heapifyDown(int index) {
        int largest = index;

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else break;
        }
    }

public:

    PriorityQueue(int cap) {
        arr = new int[cap];
        size = 0;
        capacity = cap;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full. Cannot insert.\n";
            return;
        }

        arr[size] = value;
        heapifyUp(size);
        size++;
        cout << value << " inserted.\n";
    }

    int getMax() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return -1;
        }
        return arr[0];
    }

    void deleteMax() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "Deleted max: " << arr[0] << endl;
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }



    void print() {                                // not print according to sequence
        cout << "Priority Queue (Max Heap): ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }


void printSorted() {
    int* temp = new int[size];
    int tempSize = size;

    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    cout << "Priority Queue in sorted order (Max to Min): ";

    while (tempSize > 0) {
        cout << temp[0] << " ";

        temp[0] = temp[tempSize - 1];
        tempSize--;

        // Heapify down
        int index = 0;
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < tempSize && temp[left] > temp[largest])
                largest = left;
            if (right < tempSize && temp[right] > temp[largest])
                largest = right;

            if (largest != index) {
                swap(temp[index], temp[largest]);
                index = largest;
            } else break;
        }
    }

    delete[] temp;
    cout << endl;
}



    int getHeight() {
        if (size == 0) return -1;      // Empty heap → height = -1
        return (int)floor(log2(size)); // Use floor(log2(size))
    }




    ~PriorityQueue() {
        delete[] arr;
    }


};


int main() {
    PriorityQueue pq(10);

    pq.insert(30);
    pq.insert(50);
    pq.insert(10);
    pq.insert(40);
    pq.insert(20);

    cout<< "Height of Heap : "<< pq.getHeight()<<endl;


    
    pq.printSorted();

    cout << "Max element: " << pq.getMax() << endl;

    pq.deleteMax();
    pq.printSorted();
    pq.print();

    pq.deleteMax();
    pq.printSorted();
    pq.print();

    pq.printSorted();


    return 0;
}
