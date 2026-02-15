

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, tadj;
vector<int> visited, comp;
stack<int> st;

void dfs1(int node) {
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (!visited[it]) dfs1(it);
    }
    st.push(node);
}

void dfs2(int node, int id) {
    comp[node] = id;
    visited[node] = 1;
    for (auto it : tadj[node]) {
        if (!visited[it]) dfs2(it, id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

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

    // Step 1: DFS to fill stack
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i);
    }

    // Step 2: Transpose DFS
    fill(visited.begin(), visited.end(), 0);
    int scc_count = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            ++scc_count;
            dfs2(node, scc_count);
        }
    }

    // Output
    cout << scc_count << "\n";
    for (int i = 1; i <= n; i++) {
        cout << comp[i] << " ";
    }
    cout << "\n";

    return 0;
}
