#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN];
int color[MAXN];

int cntA = 0;  // count of nodes in set A

void dfs(int u, int c, int parent) {
    color[u] = c;
    if (c == 0) cntA++;  // 0 = Set A, 1 = Set B
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, c ^ 1, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Run DFS from node 1
    dfs(1, 0, -1);

    long long a = cntA;
    long long b = n - cntA;
    long long result = a * b - (n - 1);

    cout << result << "\n";
    return 0;
}
