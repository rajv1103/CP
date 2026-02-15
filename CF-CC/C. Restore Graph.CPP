#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if(!(cin >> n >> k)) return 0;
    vector<int> d(n+1);
    int maxd = 0;
    for(int i=1;i<=n;i++){ cin >> d[i]; maxd = max(maxd, d[i]); }
    vector<vector<int>> by(maxd+1);
    for(int i=1;i<=n;i++){
        if(d[i] < 0 || d[i] > maxd){ cout << -1 << '\n'; return 0; }
        by[d[i]].push_back(i);
    }
    if(by.size() == 0 || by[0].size() != 1){
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<int,int>> edges;
    // capacities for parents
    // prepare parent queue for level 0 initially
    for(int lvl=1; lvl<=maxd; ++lvl){
        if(by[lvl].empty()) continue;
        if(by[lvl-1].empty()){ cout << -1 << '\n'; return 0; }
        // build queue of parents with capacities
        deque<pair<int,int>> q; // (vertex, remaining cap)
        for(int p : by[lvl-1]){
            int cap = (lvl-1 == 0) ? k : (k-1);
            if(cap > 0) q.emplace_back(p, cap);
        }
        if(q.empty()){ cout << -1 << '\n'; return 0; }
        size_t idxParent = 0;
        for(int child : by[lvl]){
            // find next parent with remaining cap
            while(!q.empty() && q.front().second == 0) q.pop_front();
            if(q.empty()){ cout << -1 << '\n'; return 0; }
            auto pr = q.front(); q.pop_front();
            edges.emplace_back(pr.first, child);
            pr.second--;
            if(pr.second > 0) q.push_front(pr);
        }
    }
    cout << edges.size() << '\n';
    for(auto &e : edges) cout << e.first << ' ' << e.second << '\n';
    return 0;
}
