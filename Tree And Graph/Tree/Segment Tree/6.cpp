#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    int n;
    vector<int> tree;

    void build(vector<int>& arr, int i, int l, int r) {
        if (l == r) {
            tree[i] = l;  
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2*i+1, l, mid);
        build(arr, 2*i+2, mid+1, r);

        int left = tree[2*i+1];
        int right = tree[2*i+2];
        tree[i] = (arr[left] <= arr[right]) ? left : right;
    }

    int queryIndexMin(vector<int>& arr, int i, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return -1;
        if (ql <= l && r <= qr) return tree[i];

        int mid = (l + r) / 2;
        int left = queryIndexMin(arr, 2*i+1, l, mid, ql, qr);
        int right = queryIndexMin(arr, 2*i+2, mid+1, r, ql, qr);

        if (left == -1) return right;
        if (right == -1) return left;
        return (arr[left] <= arr[right]) ? left : right;
    }

    
    int binarySearchGE(vector<int>& arr, int l, int r, int target) {
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int idx = queryIndexMin(arr, 0, 0, n-1, l, mid);
            if (idx != -1 && arr[idx] >= target) {
                res = idx;
                r = mid - 1;  
            } else {
                l = mid + 1;
            }
        }
        return res;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 0, 0, n-1);
    }

    // Query index of min in range
    int getIndexOfMin(vector<int>& arr, int l, int r) {
        return queryIndexMin(arr, 0, 0, n-1, l, r);
    }

    // Binary search: find index in [l, r] where value >= target
    int findFirstGreaterEqual(vector<int>& arr, int l, int r, int target) {
        return binarySearchGE(arr, l, r, target);
    }
};

int main() {
    vector<int> arr = {5, 1, 7, 3, 9, 2, 6};
    SegmentTree st(arr);

    int l = 1, r = 6;
    int idxMin = st.getIndexOfMin(arr, l, r);
    cout << "Index of min in range [" << l << ", " << r << "] = " << idxMin << ", value = " << arr[idxMin] << endl;

    int target = 4;
    int idxGE = st.findFirstGreaterEqual(arr, l, r, target);
    if (idxGE != -1)
        cout << "First index in range [" << l << ", " << r << "] with value >= " << target << " is " << idxGE << ", value = " << arr[idxGE] << endl;
    else
        cout << "No element >= " << target << " in range\n";

    return 0;
}
