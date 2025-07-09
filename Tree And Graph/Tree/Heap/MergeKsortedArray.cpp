#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// Tuple: {value, array index, element index in array}
typedef tuple<int, int, int> Element;

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Step 1: Push first element of each array into the heap
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    vector<int> result;

    // Step 2: Process the heap
    while (!minHeap.empty()) {

    int val = get<0>(minHeap.top());
    int row = get<1>(minHeap.top());
    int col = get<2>(minHeap.top());

        minHeap.pop();

        result.push_back(val);

        // Push next element from the same array
        if (col + 1 < arrays[row].size()) {
            minHeap.push({arrays[row][col + 1], row, col + 1});
        }
    }

    return result;
}
