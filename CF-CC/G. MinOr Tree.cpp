#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, m, cnt;
vector<int> vis;

void dfs(int u, vector<vector<pair<int,int>>>& g) {
    vis[u] = 1;
    cnt++;
    for (auto [v, w] : g[u]) {
        if (!vis[v]) dfs(v, g);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<pair<int,int>>> adj(n+1);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }

        int ans = (1 << 30) - 1;  // assume all bits are set
        vis.assign(n+1, 0);

        // iterate bits from high to low
        for (int j = 29; j >= 0; j--) {
            // build temp graph without edges having this bit
            vector<vector<pair<int,int>>> temp(n+1);
            for (int i = 1; i <= n; i++) {
                for (auto [v, w] : adj[i]) {
                    if (((w >> j) & 1) == 0) {
                        temp[i].pb({v, w});
                    }
                }
            }

            ans -= (1 << j);   // pretend we can drop this bit
            fill(all(vis), 0);
            cnt = 0;
            dfs(1, temp);

            if (cnt < n) {
                // graph disconnected -> must restore this bit
                ans += (1 << j);
            } else {
                // commit the removal
                adj = temp;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
