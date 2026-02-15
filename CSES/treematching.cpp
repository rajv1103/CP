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


void dfs(int node,int par,vector<vector<int>>&adj){
  
    for(auto child:adj[node]){
        if(par==child) continue;
        dfs(child,node,adj,sub);
    }
}
void solve() {
    ll n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
       int x,y ;cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
    }
   
}

int main() {
    FAST_IO;

    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
