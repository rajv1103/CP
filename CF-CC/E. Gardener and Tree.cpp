#include <bits/stdc++.h>
using namespace std;

// ─── FAST I/O ────────────────────────────────────────────────────────────────
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// ─── TYPE ALIASES ───────────────────────────────────────────────────────────
using ll   = long long;
using vi   = vector<int>;

// ─── SOLVE ───────────────────────────────────────────────────────────────────
void solve() {
    ll n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n+1,0);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++,deg[y]++;
    }
    queue<pair<int,int>> q;
    vector<int> steps(n+1,0);
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            steps[i]=1;
            q.push({i,steps[i]});
        }
    }
    while(!q.empty()){
        auto [v,step]=q.front();
        q.pop();
        for(auto u:adj[v]){
            deg[u]--;
            if(deg[u]==1 && steps[u]==0){
                q.push({u,step+1});
                steps[u]=step+1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(steps[i]>k) cnt++;
    }
    cout<<cnt<<endl;
}

int main() {
    FAST_IO;

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
