#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
const int LOG = 17; // log2(MAXN) ≈ 17

vector<vector<int>> adj;
vector<vector<int>> dp;
vector<int> depth;

void dfs(int node, int par) {
    dp[node][0] = par;
    for (int i = 1; i < LOG; i++) {
        if (dp[node][i - 1] != 0)
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    for (int child : adj[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

int getKpar(int a, int k) {
    for (int i = 0; i < LOG; i++) {
        if ((k >> i) & 1) {
            a = dp[a][i];
            if (a == 0) break;
        }
    }
    return a;
}

int getlca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = getKpar(a, depth[a] - depth[b]);
    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
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

    int n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    dp.assign(n + 1, vector<int>(LOG, 0));
    depth.assign(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    dfs(1, 0);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << getlca(a, b) << '\n';
    }

    return 0;
}
