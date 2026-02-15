#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
using vll = vector<ll>;

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll &x : a) cin >> x;

    vector<vector<ll>> ans;

    for (ll i = 0; i < n; i++) {
        int l = 0, r = (int)ans.size() - 1;
        int ind = ans.size(); // default: new sequence

        while (l <= r) {
            int mid = (l + r) / 2;
            if (ans[mid].back()< a[i]) { 
                ind = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (ind == (int)ans.size()) {
            ans.push_back({a[i]});
        } else {
            ans[ind].push_back(a[i]);
        }
    }

    // Printing 2D vector
    for (auto &row : ans) {
        for (auto v : row) cout << v << ' ';
        cout << '\n';
    }
}

int main() {
    FAST_IO;
    solve();
    return 0;
}
