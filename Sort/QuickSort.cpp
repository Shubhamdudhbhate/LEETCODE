#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

// Partition using first element as pivot
int partitionFirst(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

// Partition using last element as pivot
int partitionLast(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Partition using middle element as pivot
int partitionMiddle(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[high]); // Move middle to end
    return partitionLast(arr, low, high); // Reuse last pivot logic
}

// Partition using random element as pivot
int partitionRandom(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return partitionLast(arr, low, high); // Reuse last pivot logic
}

// QuickSort with function pointer
void quickSort(vector<int>& arr, int low, int high, int (*partitionFunc)(vector<int>&, int, int)) {
    if (low < high) {
        int pi = partitionFunc(arr, low, high);
        quickSort(arr, low, pi - 1, partitionFunc);
        quickSort(arr, pi + 1, high, partitionFunc);
    }
}

int main() {
    srand(time(0)); // Seed for random pivot

    vector<int> arr;
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "\nChoose Quick Sort Pivot Strategy:\n";
    cout << "1. First element\n";
    cout << "2. Last element\n";
    cout << "3. Middle element\n";
    cout << "4. Random element\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1:
            quickSort(arr, 0, n - 1, partitionFirst);
            break;
        case 2:
            quickSort(arr, 0, n - 1, partitionLast);
            break;
        case 3:
            quickSort(arr, 0, n - 1, partitionMiddle);
            break;
        case 4:
            quickSort(arr, 0, n - 1, partitionRandom);
            break;
        default:
            cout << "Invalid choice.\n";
            return 0;
    }

    cout << "\nSorted Array: ";
    printArray(arr);

    return 0;
}
