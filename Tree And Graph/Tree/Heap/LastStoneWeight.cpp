#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;

    // Step 1: Insert all stones into max heap
    for (int stone : stones)
        maxHeap.push(stone);

    // Step 2: Smash two heaviest stones
    while (maxHeap.size() > 1) {
        int y = maxHeap.top(); maxHeap.pop();  // heaviest
        int x = maxHeap.top(); maxHeap.pop();  // second heaviest

        if (y != x) {
            maxHeap.push(y - x);  // Push difference
        }
        // else: both stones destroyed
    }

    // Step 3: Return last stone or 0
    return maxHeap.empty() ? 0 : maxHeap.top();
}

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << "Last stone weight: " << lastStoneWeight(stones) << endl;
    return 0;
}
