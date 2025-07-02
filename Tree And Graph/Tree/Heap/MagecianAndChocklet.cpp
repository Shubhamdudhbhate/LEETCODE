#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int maxChocolates(vector<int>& A, int K) {
    priority_queue<int> maxHeap;

    // Step 1: Insert all bags into Max Heap
    for (int chocs : A)
        maxHeap.push(chocs);

    long long total = 0;

    // Step 2: Eat for K minutes
    while (K-- && !maxHeap.empty()) {
        int maxChoc = maxHeap.top(); maxHeap.pop();
        total += maxChoc;

        int refill = maxChoc / 2;
        maxHeap.push(refill);
    }

    return total;
}

int main() {
    vector<int> A = {6, 5}; // Initial chocolates in each bag
    int K = 3;              // Minutes available

    cout << "Max chocolates eaten: " << maxChocolates(A, K) << endl;

    return 0;
}
