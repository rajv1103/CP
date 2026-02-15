#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> names[i];

    // adjacency list of graph
    vector<vector<int>> adj(26);
    vector<int> indeg(26, 0);
    bool impossible = false;

    // build graph by comparing consecutive words
    for (int i = 0; i < n - 1; i++) {
        string a = names[i];
        string b = names[i + 1];
        int len = min(a.size(), b.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                int u = a[j] - 'a';
                int v = b[j] - 'a';
                adj[u].push_back(v);
                found = true;
                break;
            }
        }

        // check prefix rule
        if (!found && a.size() > b.size()) {
            impossible = true;
        }
    }

    if (impossible) {
        cout << "Impossible\n";
        return 0;
    }

    // compute indegrees
    for (int u = 0; u < 26; u++) {
        for (int v : adj[u]) indeg[v]++;
    }

    // Kahn's algorithm (BFS topological sort)
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    string order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back('a' + u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    // if cycle detected
    if ((int)order.size() < 26) {
        cout << "Impossible\n";
    } else {
        cout << order << "\n";
    }

    return 0;
}
