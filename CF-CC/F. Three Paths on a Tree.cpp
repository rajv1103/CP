#include <bits/stdc++.h>
#include <vector>
using namespace std;

const long long  MAXN = 1e5 + 5;
const long long  LOG = 17; // log2(MAXN) ≈ 17

vector<vector<long long >> adj;
vector<vector<long long >> dp;
vector<long long > depth;
vector<long long > ans;

void dfs(long long  node, long long  par, vector<long long> &arr) {
    dp[node][0] = par;
    for (long long  i = 1; i < LOG; i++) {
        if (dp[node][i - 1] != 0)
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    for (long long  child : adj[node]) {
        if (child == par) continue;
        arr[child] = arr[node] + 1;
        dfs(child, node, arr);
    }
}
void dfs2(long long  node, long long  par, vector<long long> &arr) {
    for (long long  child : adj[node]) {
        if (child == par) continue;
        arr[child] = arr[node] + 1;
        dfs2(child, node, arr);
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

    long long  n;
    cin >> n;
    adj.resize(n + 1);
    dp.assign(n + 1, vector<long long >(LOG, 0));
    depth.assign(n + 1, 0);
    for (long long  i = 0; i < n-1; i++) {
        long long  x,y;
        cin >> x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    // Build dp and compute depths from node 1
    dfs(1,0,depth);

    int ind=-1;
    long long maxi=LLONG_MIN;
    for(int i=1;i<=n;i++){
        if(maxi<depth[i]){
            maxi=depth[i];
            ind=i;
        }
    }
    int u=ind;

    // compute depths from u to find v (the other diameter endpoint)
    depth.assign(n + 1, 0);
    ind=-1; maxi=LLONG_MIN;
    dfs2(u,0,depth);
    for(int i=1;i<=n;i++){
        if(maxi<depth[i]){
            maxi=depth[i];
            ind=i;
        }
    }
    int v=ind;
    long long diameter_len=depth[v];

    // compute dist arrays from u and v (ensure proper size and type)
    vector<long long> distU(n+1,0), distV(n+1,0);
    distU[u] = 0;
    distV[v] = 0;
    dfs2(u, 0, distU);
    dfs2(v, 0, distV);

    // Step 4: find w maximizing distance to the diameter path
    int w = u;
    long long bestDistToPath = -1;
    for(int i=1; i<=n; i++) {
        if(i==u || i==v) continue;
        long long distToPath = (distU[i] + distV[i] - diameter_len) / 2;
        if(distToPath > bestDistToPath) {
            bestDistToPath = distToPath;
            w = i;
        }
    }
    if(bestDistToPath < 0) bestDistToPath = 0; // fallback, though not needed for n>=3

    cout << (diameter_len + bestDistToPath) << "\n";
    cout << u << " " << v << " " << w << "\n";
    return 0;
}
