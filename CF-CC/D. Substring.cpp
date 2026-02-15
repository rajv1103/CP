#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<vector<int>> g(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        indeg[y]++;
    }

    // dp[u][c] = max count of letter c on any path ending at u
    vector<array<int,26>> dp(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0) q.push(i);

    int processed = 0;
    int ans = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        processed++;

        int letter = s[u] - 'a';
        dp[u][letter]++;

        for (int v : g[u]) {
            for (int c = 0; c < 26; c++)
                dp[v][c] = max(dp[v][c], dp[u][c]);
            if (--indeg[v] == 0) q.push(v);
        }
    }

    if (processed != n) {        // cycle exists
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int c = 0; c < 26; c++)
            ans = max(ans, dp[i][c]);

    cout << ans << '\n';
    return 0;
}
