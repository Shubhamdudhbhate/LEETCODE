#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargestStream {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargestStream(int kVal) {
        k = kVal;
    }

    void add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    int getKthLargest() {
        if (minHeap.size() < k)
            return -1; // Not enough elements
        return minHeap.top();
    }
};



class KthSmallestStream {
    priority_queue<int> maxHeap;
    int k;

public:
    KthSmallestStream(int kVal) {
        k = kVal;
    }

    void add(int val) {
        maxHeap.push(val);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    int getKthSmallest() {
        if (maxHeap.size() < k)
            return -1; // Not enough elements
        return maxHeap.top();
    }
};



int main() {
    vector<int> stream = {10, 5, 20, 15, 25, 30};
    int k = 3;

    KthLargestStream largestTracker(k);
    KthSmallestStream smallestTracker(k);

    cout << "After each input:\n";
    for (int num : stream) {
        largestTracker.add(num);
        smallestTracker.add(num);

        cout << "Input: " << num << " → ";
        cout << "3rd Largest: " << largestTracker.getKthLargest() << ", ";
        cout << "3rd Smallest: " << smallestTracker.getKthSmallest() << endl;
    }

    return 0;
}
