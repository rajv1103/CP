#include <bits/stdc++.h>
using namespace std;
int N = 1e5 + 10;
vector<vector<int>> adj(N);
vector<int> depth(N);

void dfs(int node, int par = -1) {
    for (auto child : adj[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Tree is undirected
    }

    dfs(1);
    int maxind1 = 1;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > depth[maxind1]) {
            maxind1 = i;
        }
        depth[i] = 0;
    }

    dfs(maxind1);
    int maxind2 = maxind1;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > depth[maxind2]) {
            maxind2 = i;
        }
    }

    cout << "Max depth is between " << maxind1 << " and " << maxind2 << endl;
    cout << "Depth is " << depth[maxind2] << endl;

    return 0;
}