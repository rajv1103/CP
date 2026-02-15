#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

vector<int> seg, lazy, arr;

void build(int st, int end, int ind) {
    if (st == end) {
        seg[ind] = arr[st];
        return;
    }
    int mid = (st + end) / 2;
    build(st, mid, 2 * ind);
    build(mid + 1, end, 2 * ind + 1);
    seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
}

void push(int st, int end, int ind) {
    if (lazy[ind] != 0) {
        seg[ind] += (end - st + 1) * lazy[ind];
        if (st != end) { // not leaf
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
}

void update(int st, int end, int ind, int l, int r, int val) {
    push(st, end, ind);

    if (r < st || l > end) return; // no overlap

    if (st >= l && end <= r) { // complete overlap
        lazy[ind] += val;
        push(st, end, ind);
        return;
    }

    int mid = (st + end) / 2;
    update(st, mid, 2 * ind, l, r, val);
    update(mid + 1, end, 2 * ind + 1, l, r, val);
    seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
}

int query(int st, int end, int ind, int l, int r) {
    push(st, end, ind);

    if (r < st || l > end) return 0; // no overlap

    if (l <= st && end <= r) return seg[ind]; // complete overlap

    int mid = (st + end) / 2;
    int left = query(st, mid, 2 * ind, l, r);
    int right = query(mid + 1, end, 2 * ind + 1, l, r);
    return left + right;
}

int main() {
    int n; 
    cin >> n;

    seg.resize(4 * n);
    lazy.resize(4 * n);
    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, n - 1, 1);

    cout << "Initial query [2,4]: " << query(0, n - 1, 1, 2, 4) << endl;

    update(0, n - 1, 1, 2, 4, 10);

    cout << "Query [2,4] after update: " << query(0, n - 1, 1, 2, 4) << endl;

    return 0;
}
