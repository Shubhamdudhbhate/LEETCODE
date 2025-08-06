#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<long long> tree;
    vector<long long> lazy;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node+1, start, mid);
            build(arr, 2*node+2, mid+1, end);
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
           
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }

            lazy[node] = 0; 
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);

        
        if (r < start || end < l)
            return;

      
        if (l <= start && end <= r) {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }

   
        int mid = (start + end) / 2;
        updateRange(2*node+1, start, mid, l, r, val);
        updateRange(2*node+2, mid+1, end, l, r, val);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }





    long long queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

       
        if (r < start || end < l)
            return 0;

       
        if (l <= start && end <= r)
            return tree[node];

       
        int mid = (start + end) / 2;
        return queryRange(2*node+1, start, mid, l, r)
             + queryRange(2*node+2, mid+1, end, l, r);
    }




public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 0, 0, n-1);
    }

    void rangeUpdate(int l, int r, int val) {
        updateRange(0, 0, n-1, l, r, val);
    }

    long long rangeSum(int l, int r) {
        return queryRange(0, 0, n-1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Initial sum [1, 3]: " << st.rangeSum(1, 3) << endl; // 3+5+7 = 15

    st.rangeUpdate(1, 3, 5); // Add 5 to all elements in [1, 3]

    cout << "After update +5 on [1, 3] → new sum [1, 3]: " << st.rangeSum(1, 3) << endl; // (3+5)+(5+5)+(7+5) = 30

    cout << "Full range sum [0, 5]: " << st.rangeSum(0, 5) << endl;

    return 0;
}
