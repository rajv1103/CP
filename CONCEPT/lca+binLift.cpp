#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<vector<int>> &adj, vector<vector<int>> &dp, vector<int> &level)
{
    dp[node][0] = par;
    for (int i = 1; i <= 16; i++)
    {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        level[child] = level[node] + 1;
        dfs(child, node, adj, dp, level);
    }
}
int getKthpar(int n, int k, vector<vector<int>> &dp)
{

    for (int i = 16; i >= 0; i--)
    {
        if ((k >> i) & 1)
        {
            n = dp[n][i];
        }
    }
    return n;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(17, 0));
    vector<vector<int>> adj(n + 1);
    vector<int> level(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, adj, dp, level);
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (level[a] > level[b])
        {
            swap(a, b);
        }
        int diff = level[b] - level[a];
        b = getKthpar(b, diff, dp);
        if (a == b)
        {
            cout << a << endl;
            continue;
        }
        for (int i = 16; i >= 0; i--)
        {
            if (dp[a][i] != dp[b][i])
            {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        cout << dp[a][0] << endl;
    }

    return 0;
}
