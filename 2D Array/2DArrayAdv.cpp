#include <iostream>
#include <vector>
using namespace std;

bool BinarySearch(const vector<vector<int>> &vec, int key) {
    if (vec.empty() || vec[0].empty()) return false;

    int rows = vec.size();
    int cols = vec[0].size(); // proper column count

    int low = 0, high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int i = mid / cols; // row index   most imp
        int j = mid % cols; // col index   most imp

        if (vec[i][j] == key) {
            cout << "Element found at position: (" << i << ", " << j << ")" << endl;
            return true;
        } else if (vec[i][j] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Element not found.\n";
    return false;
}

int main() {
    vector<vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}
    };

    int key = 6;
    cout << "Hello\n";
    BinarySearch(vec, key);

    return 0;
}

