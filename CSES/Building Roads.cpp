#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

void dfs(int node, int par) {
    visited[node] = 1;
    for (auto child : adj[node]) {
        if (child == par) continue;
        if (!visited[child]) dfs(child, node);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    visited.assign(n + 1, 0);
    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0);
            cnt++;
            ans.push_back(i);
        }
    }

    cout << cnt - 1 << endl;

    if (ans.size() > 1) {
        for (size_t i = 0; i + 1 < ans.size(); i++) {  // use size_t
            cout << ans[i] << " " << ans[i + 1] << endl;
        }
    }

    return 0;
}
