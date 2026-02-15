#include <bits/stdc++.h>
using namespace std;

// ─── FAST I/O ────────────────────────────────────────────────────────────────
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// ─── TYPE ALIASES ───────────────────────────────────────────────────────────
using ll   = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using pii  = pair<int,int>;
using pll  = pair<ll,ll>;

// ─── SHORT-HAND MACROS ──────────────────────────────────────────────────────
#define all(x)   (x).begin(), (x).end()
#define sz(x)    int((x).size())
#define pb       push_back
#define F        first
#define S        second

// DFS to compute depths
void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& depth) {
    for (auto child : adj[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node, adj, depth);
    }
}

// ─── SOLVE ───────────────────────────────────────────────────────────────────
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 2; i < n+1; i++) {
        int x;
        cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }

    // First DFS from node 1
    vector<int> depth(n+1,0);
    dfs(1, 0, adj, depth);
   map<int,int> mp;
for (int i=1;i<=n;i++) {
      mp[depth[i]]++;   // count nodes per depth
}
   int ans=0;
 for (auto it : mp) {
    ans += (it.second % 2);
}
    cout<<ans<<endl;
}

int main() {
    FAST_IO;
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
