#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<vector<int>> adj(N);
vector<int> prime_sub(N);
vector<bool> is_prime(N, true);

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
}

void dfs(int node, int par = -1)
{
    prime_sub[node] += is_prime[node] ? 1 : 0;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
        prime_sub[node] += prime_sub[child];
    }
}

int main()
{
    sieve();
    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int max_prod = INT_MIN;
    for (int i = 2; i <= n; i++)
    {
        int x = prime_sub[i];
        int y = prime_sub[1] - x;
        max_prod = max(max_prod, x * y);
    }

    cout << "Max product of prime subtree sums: " << max_prod << endl;
    return 0;
}