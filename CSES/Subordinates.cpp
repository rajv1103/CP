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


void dfs(int node,int par,vector<vector<int>>&adj,vector<int>&sub){
    sub[node]=1;
    for(auto child:adj[node]){
        if(par==child) continue;
        dfs(child,node,adj,sub);
        sub[node]+=sub[child];
    }
    //sub[node]-=1;
}
void solve() {
    ll n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++){
       int x ;cin>>x;
       adj[i].push_back(x);
       adj[x].push_back(i);
    }
    vi sub(n+1,0);
    dfs(1,0,adj,sub);
    for(int i=1;i<sub.size();i++){
        cout<<sub[i]-1<<" ";
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
