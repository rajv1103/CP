#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &depth, vector<vector<int>> &dp) {
    dp[node][0] = par;
    for (int i = 1; i <= 16; i++) {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    for (auto child : adj[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node, adj, depth, dp);
    }
}

int getpar(int n, int k, vector<vector<int>> &dp) {
    for (int i = 16; i >= 0; i--) {
        if ((k >> i) & 1) {
            n = dp[n][i];
        }
    }
    return n;
}

int getlca(int a, int b, vector<int> &depth, vector<vector<int>> &dp) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    a = getpar(a, diff, dp);

    if (a == b) return a;

    for (int i = 16; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> depth(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(17, 0));

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0, adj, depth, dp);

    while (m--) {
        int x;
        cin >> x;
        vector<int> arr(x);
        for (int i = 0; i < x; i++) cin >> arr[i];

        // find deepest node
        int maxdepth = INT_MIN;
        int ind = arr[0];
        for (int v : arr) {
            if (depth[v] > maxdepth) {
                maxdepth = depth[v];
                ind = v;
            }
        }

        bool ok = true;
        for (int v : arr) {
            int lca = getlca(v, ind, depth, dp);
            // check condition (depth[v] - depth[lca] <= 1 ?)
            if (depth[v] - depth[lca] > 1) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
