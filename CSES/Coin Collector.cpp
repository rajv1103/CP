#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, tadj;
vector<int> visited, comp;
stack<int> st;
vector<long long> cost;

// First DFS: order
void dfs1(int node) {
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (!visited[it]) dfs1(it);
    }
    st.push(node);
}

// Second DFS: collect SCC
void dfs2(int node, int id, long long &sum) {
    visited[node] = 1;
    comp[node] = id;
    sum += cost[node];
    for (auto it : tadj[node]) {
        if (!visited[it]) dfs2(it, id, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cost.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> cost[i];

    adj.resize(n + 1);
    tadj.resize(n + 1);
    visited.assign(n + 1, 0);
    comp.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        tadj[y].push_back(x);
    }

    // Step 1: order by finish time
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i);
    }

    // Step 2: assign components
    fill(visited.begin(), visited.end(), 0);
    int scc_count = 0;
    vector<long long> compSum; // store coin sum per SCC

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!visited[node]) {
            ++scc_count;
            long long sum = 0;
            dfs2(node, scc_count, sum);
            compSum.push_back(sum); // compSum[id-1] = sum
        }
    }

    // Step 3: build DAG of SCCs
    vector<vector<int>> dag(scc_count + 1);
    vector<unordered_set<int>> seen(scc_count + 1);

    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            int cu = comp[u], cv = comp[v];
            if (cu != cv && seen[cu].insert(cv).second) {
                dag[cu].push_back(cv);
            }
        }
    }

    // Step 4: DP on DAG for max path sum
    vector<long long> dp(scc_count + 1, -1);
    function<long long(int)> solve = [&](int u) -> long long {
        if (dp[u] != -1) return dp[u];
        long long best = 0;
        for (int v : dag[u]) best = max(best, solve(v));
        return dp[u] = compSum[u - 1] + best; // compSum is 0-indexed
    };

    long long ans = 0;
    for (int i = 1; i <= scc_count; i++) {
        ans = max(ans, solve(i));
    }

    cout << ans << "\n";
    return 0;
}
