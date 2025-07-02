#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct Cell {
    int val, row, col;
    Cell(int v, int r, int c) : val(v), row(r), col(c) {}

    bool operator>(const Cell& other) const {
        return val > other.val;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;
    set<pair<int, int>> visited;

    minHeap.push(Cell(matrix[0][0], 0, 0));
    visited.insert({0, 0});

    int count = 0;
    int result = matrix[0][0];

    while (!minHeap.empty() && count < k) {
        Cell current = minHeap.top(); minHeap.pop();
        result = current.val;
        count++;

        int r = current.row;
        int c = current.col;

        if (r + 1 < n && visited.count({r + 1, c}) == 0) {
            minHeap.push(Cell(matrix[r + 1][c], r + 1, c));
            visited.insert({r + 1, c});
        }

        if (c + 1 < n && visited.count({r, c + 1}) == 0) {
            minHeap.push(Cell(matrix[r][c + 1], r, c + 1));
            visited.insert({r, c + 1});
        }


            }

    return result;
}


int kthLargest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int total = n * n;
    return kthSmallest(matrix, total - k + 1);
}




int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    cout << "K-th smallest: " << kthSmallest(matrix, k) << endl; // Output: 13
}
