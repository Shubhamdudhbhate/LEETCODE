#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MaxSegmentTree {
public:
    int n;
    vector<int> tree;

    MaxSegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int node, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, arr);
        build(2 * node + 2, mid + 1, r, arr);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node + 1, l, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, r, idx, val);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return INT_MIN; // No overlap

        if (ql <= l && r <= qr)
            return tree[node]; // Total overlap

        int mid = (l + r) / 2;
        return max(
            query(2 * node + 1, l, mid, ql, qr),
            query(2 * node + 2, mid + 1, r, ql, qr)
        );
    }

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    int maxRange(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
