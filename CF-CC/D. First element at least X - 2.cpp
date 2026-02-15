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
   seg[ind] = max(seg[2*ind], seg[2*ind+1]);
}

// Update value at position `pos`
void update(int st, int end, int ind, int pos, int val, vector<int>& arr, vector<int>& seg) {
    if (st == end) {
        arr[pos] = val;
        seg[ind] = val;
        return;
    }
    int mid = (st + end) / 2;
    if (pos <= mid) {
        update(st, mid, 2*ind, pos, val, arr, seg);
    } else {
        update(mid+1, end, 2*ind+1, pos, val, arr, seg);
    }
   seg[ind] = max(seg[2*ind], seg[2*ind+1]);
}

// Query sum in range [l, r]
int query(int st, int end, int ind, int l, int x, vector<int>& seg) {
    if (end < l || seg[ind] < x) return -1; // no valid index here
    if (st == end) return st; // leaf node, and seg[ind] >= x ensured
    
    int mid = (st + end) / 2;
    int left = query(st, mid, 2*ind, l, x, seg);
    if (left != -1) return left;  // found in left
    return query(mid+1, end, 2*ind+1, l, x, seg); // otherwise right
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> seg(4*n);
    build(0, n-1, 1, arr, seg);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int ind, val;
            cin >> ind >> val;
            update(0, n-1, 1, ind, val, arr, seg);
        } else {
            int x, l;
            cin >> x >> l;
            cout << query(0, n-1, 1, l, x, seg) << "\n";
        }
    }
}

