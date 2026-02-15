#include <bits/stdc++.h>
#include <vector>
using namespace std;

const long long  MAXN = 1e5 + 5;
const long long  LOG = 17; // log2(MAXN) ≈ 17

vector<vector<long long >> adj;
vector<vector<long long >> dp;
vector<long long > depth;
vector<long long > ans;

void dfs(long long  node, long long  par) {
    dp[node][0] = par;
    for (long long  i = 1; i < LOG; i++) {
        if (dp[node][i - 1] != 0)
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    for (long long  child : adj[node]) {
        if (child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

void dfs2(long long  node, long long  par) {
   
    for (long long  child : adj[node]) {
        if (child == par) continue;
        dfs2(child, node);
        ans[node]+=ans[child];
    }
}

long long  getKpar(long long  a, long long  k) {
    for (long long  i = 0; i < LOG; i++) {
        if ((k >> i) & 1) {
            a = dp[a][i];
            if (a == 0) break;
        }
    }
    return a;
}

long long  getlca(long long  a, long long  b) {
    if (depth[a] > depth[b]) swap(a, b);
    b = getKpar(b, depth[b] - depth[a]);
    if (a == b) return b;

    for (long long  i = LOG - 1; i >= 0; i--) {
        if (dp[a][i] != 0 && dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
           
        }
    }
    return dp[a][0];
}
int  main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long  n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    dp.assign(n + 1, vector<long long >(LOG, 0));
    depth.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    for (long long  i = 0; i < n-1; i++) {
        long long  x,y;
        cin >> x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    dfs(1,0);
    while (q--) {
        long long  a, b;
        cin >> a >> b;
        ans[a]++;
        ans[b]++;
        long long  l=getlca(a,b);
        ans[l]--;
        if (dp[l][0] != 0) ans[dp[l][0]]--;
    }
     dfs2(1, 0);
     for(long long  i=1;i<=n;i++){
        cout<<ans[i]<<" ";
     }

    return 0;
}
