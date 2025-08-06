#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node stores the actual array element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node+1, start, mid);       // Left child
            build(arr, 2*node+2, mid+1, end);       // Right child
            tree[node] = tree[2*node+1] + tree[2*node+2];  // Merge
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;        // No overlap
        if (l <= start && end <= r) return tree[node]; // Total overlap

        int mid = (start + end) / 2;
        int left = query(2*node+1, start, mid, l, r);
        int right = query(2*node+2, mid+1, end, l, r);
        return left + right;  // Merge
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;  // Update leaf
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2*node+1, start, mid, idx, val);
            else
                update(2*node+2, mid+1, end, idx, val);
            tree[node] = tree[2*node+1] + tree[2*node+2]; // Merge
        }
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);  // Safe size
        build(arr, 0, 0, n-1);
    }

    int rangeSum(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    void updateValue(int idx, int val) {
        update(0, 0, n-1, idx, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    
    cout << "Sum of range [1, 3]: " << st.rangeSum(1, 3) << endl; // 15

    st.updateValue(1, 10);  // arr[1] = 10
    cout << "Sum of range [1, 3] after update: " << st.rangeSum(1, 3) << endl; // 22

    return 0;
}
