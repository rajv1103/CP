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

bool dfs(int node, int par, vector<vector<int>>& adj, vector<int>& subtree, vector<int>& p, vector<int>& h, vector<int>& happy) {
  
    subtree[node] = p[node]; 
    for (auto child : adj[node]) {
        if (child == par) continue;
        if (!dfs(child, node, adj, subtree, p, h, happy)) return 0;
        subtree[node] += subtree[child];
    }

    long long x = subtree[node] + h[node]; 
    if (x % 2 != 0) return false; 
    happy[node] = x / 2;
    if (happy[node] < 0 || happy[node] > subtree[node]) return false;

    
    long long sumChildHappy = 0;
    for (auto child : adj[node]) {
        if (child == par) continue;
        sumChildHappy += happy[child];
    }
    if (sumChildHappy > happy[node]) return false;

    return true;
}


// ─── SOLVE ───────────────────────────────────────────────────────────────────
void solve() {
   int n, m;
cin >> n >> m;
vector<int> p(n+1), h(n+1);
for (int i = 1; i <= n; i++) cin >> p[i];
for (int i = 1; i <= n; i++) cin >> h[i];

vector<vector<int>> adj(n+1);
for (int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}

vector<int> subtree(n+1, 0), happy(n+1, 0);
if (dfs(1, 0, adj, subtree, p, h, happy))
    cout << "YES\n";
else
    cout << "NO\n";
}

int main() {
    FAST_IO;
    int T = 1;
     cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
