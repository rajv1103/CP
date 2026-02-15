#include <bits/stdc++.h>
using namespace std;

/*
   Binary Lifting technique:
   -------------------------
   We preprocess a dp table such that:
   dp[node][i] = 2^i-th ancestor of 'node'

   Example:
   dp[node][0] = parent
   dp[node][1] = 2nd ancestor (parent of parent)
   dp[node][2] = 4th ancestor
   dp[node][3] = 8th ancestor
   ...
   Using this table, we can jump in powers of 2 to reach any k-th ancestor.
*/

// DFS to build binary lifting table
void dfs(int node, int par, vector<vector<int>> &adj, vector<vector<int>> &dp)
{
    // Base case: 2^0-th ancestor = direct parent
    dp[node][0] = par;

    // Fill ancestors for all powers of 2
    // dp[node][i] = 2^i-th ancestor = dp[ dp[node][i-1] ][i-1]
    for (int i = 1; i <= 16; i++)
    {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    // DFS children (ignore parent)
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        dfs(child, node, adj, dp);
    }
}

int main()
{
    int n;
    cin >> n; // number of nodes

    // Binary lifting table: dp[node][i] = 2^i-th ancestor of node
    vector<vector<int>> dp(n + 1, vector<int>(17, 0));

    // Adjacency list of the tree
    vector<vector<int>> adj(n + 1);

    // Input edges (tree has n-1 edges)
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Precompute dp table using DFS (rooting tree at 1, parent of root = 0)
    dfs(1, 0, adj, dp);

    int q;
    cin >> q; // number of queries

    while (q--)
    {
        int node, k;
        cin >> node >> k; // find k-th ancestor of 'node'

        // Jump upwards according to binary representation of k
        for (int i = 16; i >= 0; i--)
        {
            if ((k >> i) & 1)
            {                       // if i-th bit of k is set
                node = dp[node][i]; // move up by 2^i ancestors
                if (node == 0)
                    break; // if we go above root, stop
            }
        }

        cout << node << "\n"; // answer for this query
    }

    return 0;
}
