#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted arrays into one
vector<int> mergeTwoArrays(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i++]);
        } else {
            result.push_back(b[j++]);
        }
    }

    // Add remaining elements
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}



// Recursively merge K arrays
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays, int start, int end) {
    if (start == end)
        return arrays[start];

    int mid = (start + end) / 2;

    vector<int> left = mergeKSortedArrays(arrays, start, mid);
    vector<int> right = mergeKSortedArrays(arrays, mid + 1, end);

    return mergeTwoArrays(left, right);
}


// merge(0, 3)
// ├── merge(0, 1)
// │   ├── merge(0, 0) ← base case, return arr[0]
// │   └── merge(1, 1) ← base case, return arr[1]
// │   → merge two results
// ├── merge(2, 3)
// │   ├── merge(2, 2) ← base case, return arr[2]
// │   └── merge(3, 3) ← base case, return arr[3]
// │   → merge two results
// → merge the two big halves




int main() {
    vector<vector<int>> arrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<int> result = mergeKSortedArrays(arrays, 0, arrays.size() - 1);

    cout << "Merged array: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
