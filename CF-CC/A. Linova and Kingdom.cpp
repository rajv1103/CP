#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int depth[MAXN], sz[MAXN];

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, 0);

    vector<long long> score;
    score.reserve(n);
    for (int u = 1; u <= n; u++) {
        long long s = 1LL * depth[u] - (sz[u] - 1LL);
        score.push_back(s);
    }

    sort(score.rbegin(), score.rend());

    long long ans = 0;
    for (int i = 0; i < k; i++) ans += score[i];

    cout << ans << "\n";
    return 0;
}
