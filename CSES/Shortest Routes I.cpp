#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<long long> dist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.assign(n+1, {});
    dist.assign(n+1, LLONG_MAX);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist[1] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto top = pq.top(); pq.pop();
        long long d = top.first;
        int node = top.second;

        if(d > dist[node]) continue;

        for(auto &edge : adj[node]) {
            int child = edge.first;
            int wt = edge.second;
            if(dist[node] + wt < dist[child]) {
                dist[child] = dist[node] + wt;
                pq.push({dist[child], child});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dist[i] == LLONG_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
