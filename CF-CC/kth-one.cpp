#include <bits/stdc++.h>
using namespace std;

// Build segment tree
void build(int st, int end, int ind, vector<int>& arr, vector<int>& seg) {
    if (st == end) {
        seg[ind] = arr[st]; // store 0 or 1
        return;
    }
    int mid = (st + end) / 2;
    build(st, mid, 2*ind, arr, seg);
    build(mid+1, end, 2*ind+1, arr, seg);
    seg[ind] = seg[2*ind] + seg[2*ind+1];
}

// Update (flip)
void update(int st, int end, int ind, int pos, vector<int>& arr, vector<int>& seg) {
    if (st == end) {
        arr[pos] ^= 1;      // flip value
        seg[ind] = arr[pos]; // set node value correctly
        return;
    }
    int mid = (st + end) / 2;
    if (pos <= mid) update(st, mid, 2*ind, pos, arr, seg);
    else update(mid+1, end, 2*ind+1, pos, arr, seg);

    seg[ind] = seg[2*ind] + seg[2*ind+1];
}

// Find index of k-th one (0-based)
int kthOne(int st, int end, int ind, int k, vector<int>& seg) {
    if (st == end) return st;

    int mid = (st + end) / 2;
    if (seg[2*ind] > k) {
        return kthOne(st, mid, 2*ind, k, seg);
    } else {
        return kthOne(mid+1, end, 2*ind+1, k - seg[2*ind], seg);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> seg(4*n);
    build(0, n-1, 1, arr, seg);

    while (m--) {
        int type; cin >> type;
        if (type == 1) {
            int i; cin >> i;
            update(0, n-1, 1, i, arr, seg);
        } else {
            int k; cin >> k;
            cout << kthOne(0, n-1, 1, k, seg) << "\n";
        }
    }
    return 0;
}
