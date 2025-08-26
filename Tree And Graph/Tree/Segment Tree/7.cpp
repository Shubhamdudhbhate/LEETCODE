#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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
        if (qr < l || ql > r) return -1;  // Out of range   
        if (ql <= l && r <= qr) return tree[i];  // Fully in range
        int mid = (l + r) / 2;  
        int left = queryIndexMin(arr, 2*i+1, l, mid, ql, qr);
        int right = queryIndexMin(arr, 2*i+2, mid+1, r, ql, qr);    

        if (left == -1) return right;   
        if (right == -1) return left;

        return (arr[left] <= arr[right]) ? left : right;
    }   
vector<int>