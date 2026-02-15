#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<vector<pair<int,int>>> adj(N);
vector<int> dist(N, INF);

int  bfs(int n) {
    deque<int> q;
    q.push_back(1); // Start from node 1
    dist[1] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();

        for (auto child : adj[v]) {
            int u=child.first;
            int wt=child.second;
            if (dist[v] + wt < dist[u]) {
                dist[u] = dist[v] + wt;
                if (wt) q.push_back(u);
                else q.push_front(u);
            }
        }
    }

    return dist[n];
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter u->v: ";
        int u, v;
        cin >> u >> v;

        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1}); // Reverse edge has weight 1
    }

    int result = bfs(n);
    cout << "Shortest distance to node " << n << ": " << result << endl;

    return 0;
}