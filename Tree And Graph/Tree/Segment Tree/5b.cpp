#include <bits/stdc++.h>
using namespace std;

class SegmentTreeMaxIndex {
private:
    vector<int> tree;  // stores index of maximum
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = start;  // Store index
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);

            int leftIdx = tree[2 * node];
            int rightIdx = tree[2 * node + 1];
            tree[node] = (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return -1;  // Out of range
        if (L <= start && end <= R) return tree[node]; // Fully in range

        int mid = (start + end) / 2;
        int leftIdx = query(2 * node, start, mid, L, R);
        int rightIdx = query(2 * node + 1, mid + 1, end, L, R);

        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;
        return (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }

public:
    SegmentTreeMaxIndex(const vector<int>& input) {
        arr = input;
        n = input.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int rangeMaxIndex(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }
};



int main() {
    vector<int> heights = {6, 4, 8, 5, 2, 7};
    SegmentTreeMaxIndex st(heights);

    int L = 1, R = 4;
    int idx = st.rangeMaxIndex(L, R);
    cout << "Index of max in range [" << L << ", " << R << "] is: " << idx << endl;
    cout << "Value: " << heights[idx] << endl;

    return 0;
}
