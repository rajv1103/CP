#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int par, int prev, int m, vector<vector<int>> &adj, vector<int> &arr) {
    if (prev > m) return 0; // too many cats

    // leaf check (exclude root because root can have only 1 edge too)
    if (node != 1 && adj[node].size() == 1) return 1;

    int ans = 0;
    for (auto child : adj[node]) {
        if (child == par) continue;
        int newPrev = (arr[child] ? prev + 1 : 0);
        ans += dfs(child, node, newPrev, m, adj, arr);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; // 0 or 1 for cats
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << dfs(1, 0, arr[1], m, adj, arr) << endl;
    return 0;
}
