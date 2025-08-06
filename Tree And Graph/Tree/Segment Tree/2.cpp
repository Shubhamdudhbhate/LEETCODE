#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int sum;
    int minVal;
    int maxVal;
};

class SegmentTree {
    vector<TreeNode> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], arr[start], arr[start]};
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node+1, start, mid);
            build(arr, 2*node+2, mid+1, end);

            tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
            tree[node].minVal = min(tree[2*node+1].minVal, tree[2*node+2].minVal);
            tree[node].maxVal = max(tree[2*node+1].maxVal, tree[2*node+2].maxVal);
        }
    }

    TreeNode query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return {0, INT_MAX, INT_MIN}; // No overlap
        if (l <= start && end <= r) return tree[node];          // Total overlap

        int mid = (start + end) / 2;
        TreeNode left = query(2*node+1, start, mid, l, r);
        TreeNode right = query(2*node+2, mid+1, end, l, r);

        TreeNode result;
        result.sum = left.sum + right.sum;
        result.minVal = min(left.minVal, right.minVal);
        result.maxVal = max(left.maxVal, right.maxVal);
        return result;
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = {val, val, val};
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2*node+1, start, mid, idx, val);
            else
                update(2*node+2, mid+1, end, idx, val);

            tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
            tree[node].minVal = min(tree[2*node+1].minVal, tree[2*node+2].minVal);
            tree[node].maxVal = max(tree[2*node+1].maxVal, tree[2*node+2].maxVal);
        }
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n-1);
    }

    int rangeSum(int l, int r) {
        return query(0, 0, n-1, l, r).sum;
    }

    int rangeMin(int l, int r) {
        return query(0, 0, n-1, l, r).minVal;
    }

    int rangeMax(int l, int r) {
        return query(0, 0, n-1, l, r).maxVal;
    }

    void updateValue(int idx, int val) {
        update(0, 0, n-1, idx, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Initial Range [1, 4]:\n";
    cout << "Sum = " << st.rangeSum(1, 4) << endl;     // 3+5+7+9 = 24
    cout << "Min = " << st.rangeMin(1, 4) << endl;     // 3
    cout << "Max = " << st.rangeMax(1, 4) << endl;     // 9

    st.updateValue(2, 10); // Update arr[2] = 10

    cout << "\nAfter update arr[2] = 10:\n";
    cout << "Sum = " << st.rangeSum(1, 4) << endl;     // 3+10+7+9 = 29
    cout << "Min = " << st.rangeMin(1, 4) << endl;     // 3
    cout << "Max = " << st.rangeMax(1, 4) << endl;     // 10

    return 0;
}
