#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap; // max-heap for left side{10,9,8,7,6,5,4,3,2,1}
    priority_queue<int, vector<int>, greater<int>> minHeap; // {1,2,3,4,5,6,7,8,9,10}

public:
    // Add number to the stream
    void addNum(int num) {
        maxHeap.push(num);

        // Ensure order: maxHeap top (biggest of the small number)  ≤  minHeap top(smallest of the big numbers)
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int temp = maxHeap.top(); maxHeap.pop();
            minHeap.push(temp);
        }

        // Balance the sizes
        if (maxHeap.size() > minHeap.size() + 1) {
            int temp = maxHeap.top(); maxHeap.pop();
            minHeap.push(temp);
        } else if (minHeap.size() > maxHeap.size()) {
            int temp = minHeap.top(); minHeap.pop();
            maxHeap.push(temp);
        }
    }

    // Return current median
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};

int main() {
    MedianFinder mf;
    vector<int> stream = {5, 15, 1, 3};

    for (int num : stream) {
        mf.addNum(num);
        cout << "Current median: " << mf.findMedian() << endl;
    }

    return 0;
}
