#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj, radj;
vector<int> visited;

void dfs(int u, const vector<vector<int>> &graph) {
    visited[u] = 1;
    for (auto v : graph[u]) {
        if (!visited[v]) dfs(v, graph);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    radj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    // Step 1: check reachability from 1 in original graph
    visited.assign(n + 1, 0);
    dfs(1, adj);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
    }

    // Step 2: check reachability from 1 in reversed graph
    visited.assign(n + 1, 0);
    dfs(1, radj);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
