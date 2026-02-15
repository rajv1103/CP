#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[v] will store up to k shortest distances to v
    vector<vector<ll>> dist(n + 1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1].push_back(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u].back()) continue;

        for (auto [v, w] : adj[u]) {
            ll nd = d + w;
            if ((int)dist[v].size() < k) {
                dist[v].push_back(nd);
                sort(dist[v].begin(), dist[v].end());
                pq.push({nd, v});
            } else if (dist[v].back() > nd) {
                dist[v].back() = nd;
                sort(dist[v].begin(), dist[v].end());
                pq.push({nd, v});
            }
        }
    }

    for (ll x : dist[n]) cout << x << " ";
    cout << "\n";
    return 0;
}
