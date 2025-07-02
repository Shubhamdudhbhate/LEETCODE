#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minCostToConnectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Step 1: Push all rope lengths into min heap
    for (int rope : ropes) {
        minHeap.push(rope);
    }

    int totalCost = 0;

    // Step 2: Combine ropes until one remains
    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int cost = first + second;
        totalCost += cost;

        // Push combined rope back
        minHeap.push(cost);
    }

    return totalCost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    
    int result = minCostToConnectRopes(ropes);
    cout << "Minimum cost to connect ropes: " << result << endl;

    return 0;
}
