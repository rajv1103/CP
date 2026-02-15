  #include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<vector<int>> adj(N);
vector<int> euler, depthArr, first(N, -1); 
int n;

// DFS to build Euler tour and depth
void dfs(int node, int par, int depth) {
    first[node] = (int)euler.size();  // first occurrence
    euler.push_back(node);
    depthArr.push_back(depth);

    for (auto child : adj[node]) {
        if (child == par) continue;
        dfs(child, node, depth + 1);
        // backtrack to node
        euler.push_back(node);
        depthArr.push_back(depth);
    }
}

// Segment Tree for RMQ on depthArr
vector<int> segtree;
void build(int idx, int l, int r) {
    if (l == r) {
        segtree[idx] = l; // store index of depthArr
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    int left = segtree[2 * idx], right = segtree[2 * idx + 1];
    segtree[idx] = (depthArr[left] < depthArr[right] ? left : right);
}

int query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return -1;
    if (ql <= l && r <= qr) return segtree[idx];
    int mid = (l + r) / 2;
    int left = query(2 * idx, l, mid, ql, qr);
    int right = query(2 * idx + 1, mid + 1, r, ql, qr);
    if (left == -1) return right;
    if (right == -1) return left;
    return (depthArr[left] < depthArr[right] ? left : right);
}

int LCA(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right) swap(left, right);
    int idx = query(1, 0, (int)euler.size() - 1, left, right);
    return euler[idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Build Euler Tour
    dfs(1, 0, 0);

    // Build Segment Tree
    int m = euler.size();
    segtree.assign(4 * m, 0);
    build(1, 0, m - 1);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }

    return 0;
}
