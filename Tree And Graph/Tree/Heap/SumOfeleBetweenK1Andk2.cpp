#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    long long sumBetweenTwoKth(long long arr[], long long N, long long k1, long long k2) {
 
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

 
        for (long long i = 0; i < N; i++) {
            minHeap.push(arr[i]);
        }

        long long sum = 0;

        for (long long i = 1; i < k2; i++) {
            long long val = minHeap.top();
            minHeap.pop();

            
            if (i > k1)
                sum += val;
        }

        return sum;
    }
};


int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : arr)
        minHeap.push(num);

    int sum = 0;

    for (int i = 1; i < k2; i++) {
        int val = minHeap.top(); minHeap.pop();  // smallest k2 element

        // only sum elements between k1 and k2
        if (i > k1) sum += val;
    }

    return sum;
}






int main() {
    vector<int> arr = {1, 3, 12, 5, 15, 11};
    int k1 = 3, k2 = 6;

    int result = sumBetweenK1K2(arr, k1, k2);
    cout << "Sum of elements between " << k1 << "-th and " << k2 << "-th smallest is: " << result << endl;
    return 0;
}

