#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
int val[N], dp[N], res[N];
int n;

void dfs1(int v, int p) {
    dp[v] = val[v];
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs1(u, v);
        dp[v] += max(0, dp[u]); // take child contribution only if positive
    }
}

void dfs2(int v, int p) {
    res[v] = dp[v];
    for (int u : adj[v]) {
        if (u == p) continue;

        // Save old values
        int old_v = dp[v], old_u = dp[u];

        // Remove child's contribution from parent
        dp[v] -= max(0, dp[u]);
        // Add parent's contribution to child
        dp[u] += max(0, dp[v]);

        dfs2(u, v);

        // Restore values (important for correctness)
        dp[v] = old_v;
        dp[u] = old_u;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        val[i] = (c == 1 ? 1 : -1); // white=+1, black=-1
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1); // bottom-up
    dfs2(1, -1); // reroot

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}
