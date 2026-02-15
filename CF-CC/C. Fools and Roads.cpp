#include <bits/stdc++.h>
using namespace std;

long long LOGv; 
vector<vector<long long>> adj;
vector<vector<long long>> dp;
vector<long long> depth;
vector<long long> ans;
vector<pair<int,int>> edges;

void dfs(long long node, long long par) {
    dp[node][0] = par;
    for (long long i = 1; i < LOGv; ++i) {
        long long mid = dp[node][i-1];
        dp[node][i] = (mid == 0 ? 0 : dp[mid][i-1]);
    }
    for (long long child : adj[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

void dfs2(long long node, long long par) {
    for (long long child : adj[node]) {
        if (child == par) continue;
        dfs2(child, node);
        ans[node] += ans[child];
    }
}

long long getKpar(long long a, long long k) {
    for (long long i = 0; i < LOGv && a; ++i) {
        if ((k >> i) & 1) {
            a = dp[a][i];
            if (a == 0) break;
        }
    }
    return a;
}

long long getlca(long long a, long long b) {
    if (depth[a] > depth[b]) swap(a, b);
    b = getKpar(b, depth[b] - depth[a]);
    if (a == b) return a;
    for (long long i = LOGv - 1; i >= 0; --i) {
        if (dp[a][i] != 0 && dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q;
    if (!(cin >> n)) return 0;
    cin >> std::ws; // safe

    adj.assign(n + 1, {});
    edges.clear();
    edges.reserve(n - 1);

    for (long long i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.emplace_back(x, y);
    }

    // compute LOGv dynamically
    LOGv = 1;
    while ((1LL << LOGv) <= n) ++LOGv;
    // dp table
    dp.assign(n + 1, vector<long long>(LOGv, 0));
    depth.assign(n + 1, 0);
    ans.assign(n + 1, 0);

    // build dp[ ][0] and depths via dfs (root at 1)
    depth[1] = 0;
    dfs(1, 0);

    cin >> q;
    while (q--) {
        long long a, b;
        cin >> a >> b;
        ans[a] += 1;
        ans[b] += 1;
        long long l = getlca(a, b);
        ans[l] -= 2;
    }

    // accumulate values from children to parent
    dfs2(1, 0);

   
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        // deeper node has larger depth
        if (depth[u] < depth[v]) swap(u, v); // now u is deeper
        cout << ans[u] << (i + 1 == edges.size() ? '\n' : ' ');
    }

    return 0;
}
