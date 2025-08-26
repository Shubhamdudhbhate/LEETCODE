#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;  // stores index of minimum
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = start; // store index
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);

            int leftIdx = tree[2 * node];
            int rightIdx = tree[2 * node + 1];
            tree[node] = (arr[leftIdx] <= arr[rightIdx]) ? leftIdx : rightIdx;
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return -1;  // out of range
        if (L <= start && end <= R) return tree[node]; // fully in range

        int mid = (start + end) / 2;
        int leftIdx = query(2 * node, start, mid, L, R);
        int rightIdx = query(2 * node + 1, mid + 1, end, L, R);

        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;
        return (arr[leftIdx] <= arr[rightIdx]) ? leftIdx : rightIdx;
    }

public:
    SegmentTree(const vector<int>& input) {
        arr = input;
        n = input.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int rangeMinIndex(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }
};


int main() {
    vector<int> heights = {6, 4, 8, 5, 2, 7};
    SegmentTree st(heights);

    int L = 1, R = 4;
    int idx = st.rangeMinIndex(L, R);
    cout << "Index of min in range [" << L << ", " << R << "] is: " << idx << endl;
    cout << "Value: " << heights[idx] << endl;

    return 0;
}
