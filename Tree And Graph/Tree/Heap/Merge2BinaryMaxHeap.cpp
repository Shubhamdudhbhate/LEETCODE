#include <iostream>
#include <vector>
using namespace std;

void heapifyDown(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

vector<int> mergeMaxHeaps(vector<int>& A, vector<int>& B) {
    vector<int> merged;

    // Step 1: Merge both arrays
    for (int x : A) merged.push_back(x);
    for (int x : B) merged.push_back(x);

    int size = merged.size();

    // Step 2: Build heap from bottom-up
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyDown(merged, size, i);
    }

    return merged;
}


int main() {
    vector<int> A = {10, 5, 6, 2};
    vector<int> B = {12, 7, 9};

    vector<int> result = mergeMaxHeaps(A, B);

    cout << "Merged Max Heap: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

