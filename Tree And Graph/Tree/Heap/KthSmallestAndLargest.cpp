#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;

    for (int num : arr) {
        maxHeap.push(num);

        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    return maxHeap.top();
}

int kthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : arr) {
        minHeap.push(num);

        if (minHeap.size() > k)
            minHeap.pop();
    }

    return minHeap.top();
}


int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 4;

    cout <<k<<"th Smallest Element: " << kthSmallest(arr, k) << endl;
    cout <<k<<"th Largest Element: " << kthLargest(arr, k) << endl;

    return 0;
}
