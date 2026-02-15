#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a((size_t)n);
    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());

    ll l = a[n / 2], r = a[n / 2] + k; // Safe upper bound
    ll ans = a[n / 2];

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll cnt = 0; // no overflow now
        for (size_t i = n / 2; i < (size_t)n; i++) {
            if (a[i] < mid) cnt += (mid - a[i]);
        }
        if (cnt <= k) {
            ans = mid;     // Possible, try bigger
            l = mid + 1;
        } else {
            r = mid - 1;   // Too big, try smaller
        }
    }
    cout << ans << "\n";
}

int main() {
    FAST_IO;
    solve();
    return 0;
}
