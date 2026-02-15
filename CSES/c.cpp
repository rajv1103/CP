#include <bits/stdc++.h>
using namespace std;

vector<set<int>> adj;
vector<int> vis;
vector<int> comp;

void dfs(int u) {
    vis[u] = 1;
    comp.push_back(u);
    for (auto v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    adj.resize(26);
    vis.assign(26, 0);

    string a, b, c;
    cin >> a >> b >> c;

    // Step 1: Build direct edges
    for (int i = 0; i < a.size(); i++) {
        adj[a[i] - 'a'].insert(b[i] - 'a');
        adj[b[i] - 'a'].insert(a[i] - 'a');
    }

    // Step 2: Expand to indirect edges
    for (int i = 0; i < 26; i++) {
        if (!vis[i] && !adj[i].empty()) {
            comp.clear();
            dfs(i);  // get whole connected component

            // For each node in component → connect with all others
            for (int u : comp) {
                // remove old neighbors
                adj[u].clear();
                for (int v : comp) {
                    if (u != v) adj[u].insert(v);
                }
            }
        }
    }

    string ans="";
    for(int i=0;i<c.size();i++){
      if(adj[c[i]-'a'].size()==0) ans+=c[i];
      else ans+=char((*adj[c[i]-'a'].begin())+'a');
    }
    cout<<ans<<endl;

    return 0;
}
