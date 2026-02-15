#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
long long a[N], subsum[N];
long long cost1, sumAll;
long long res;
int n;

void dfs1(int v, int p, int depth) {
    subsum[v] = a[v];
    cost1 += 1LL * depth * a[v]; // contribute to initial cost
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs1(u, v, depth + 1);
        subsum[v] += subsum[u];
    }
}

void dfs2(int v, int p, long long curCost) {
    res = max(res, curCost);
    for (int u : adj[v]) {
        if (u == p) continue;
        long long newCost = curCost + (sumAll - 2 * subsum[u]);
        dfs2(u, v, newCost);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sumAll += a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cost1 = 0;
    dfs1(1, -1, 0);      // compute subsums + cost(1)
    dfs2(1, -1, cost1);  // reroot and compute costs

    cout << res << "\n";
    return 0;
}
