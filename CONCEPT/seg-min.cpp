#include <bits/stdc++.h>
using namespace std;

// Build segment tree
void build(int st, int end, int ind, vector<int>& arr, vector<int>& seg) {
    if (st == end) {
        seg[ind] = arr[st];
        return;
    }
    int mid = (st + end) / 2;
    build(st, mid, 2*ind, arr, seg);
    build(mid+1, end, 2*ind+1, arr, seg);
    seg[ind] = min(seg[2*ind] , seg[2*ind+1]);
}

// Update value at position `pos`
void update(int st, int end, int ind, int pos, int val, vector<int>& arr, vector<int>& seg) {
    if (st == end) {
        arr[pos] = val;  
        seg[ind] = arr[pos];
        return;
    }
    int mid = (st + end) / 2;
    if (pos <= mid) {
        update(st, mid, 2*ind, pos, val, arr, seg);
    } else {
        update(mid+1, end, 2*ind+1, pos, val, arr, seg);
    }
    seg[ind] = min(seg[2*ind], seg[2*ind+1]);
}

// Query sum in range [l, r]
int query(int st, int end, int ind, int l, int r, vector<int>& seg) {
    // No overlap
    if (end < l || st > r) return INT_MAX;  //  #### impt 

    // Full overlap
    if (l <= st && end <= r) return seg[ind];

    // Partial overlap
    int mid = (st + end) / 2;
    int left = query(st, mid, 2*ind, l, r, seg);
    int right = query(mid+1, end, 2*ind+1, l, r, seg);
    return min(left, right);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();
    vector<int> seg(4*n); // segment tree size ~ 4*n

    // Build tree
    build(0, n-1, 1, arr, seg);

    cout << "Sum of range [1,3] = " << query(0, n-1, 1, 1, 3, seg) << "\n"; // min(3,5,7) = 3

    update(0, n-1, 1, 1, 10, arr, seg); // arr[1] = 10

    cout << "After update, sum of range [1,3] = " << query(0, n-1, 1, 1, 3, seg) << "\n"; //  min(10,5,7) = 5

}
