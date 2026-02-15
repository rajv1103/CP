#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<long long>> adj(n, vector<long long>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<int> del(n);
    for (int i = 0; i < n; i++) {
        cin >> del[i];
        del[i]--; // convert to 0-based
    }

    reverse(del.begin(), del.end());

    vector<long long> ans(n);
    vector<bool> active(n, false);

    for (int k = 0; k < n; k++) {
        int ver = del[k];
        active[ver] = true;

        // Update shortest paths using the new vertex
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][ver] + adj[ver][j]);
            }
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (!active[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!active[j]) continue;
                sum += adj[i][j];
            }
        }
        ans[k] = sum;
    }

    reverse(ans.begin(), ans.end());
    for (auto val : ans) cout << val << " ";
    cout << "\n";

    return 0;
}
