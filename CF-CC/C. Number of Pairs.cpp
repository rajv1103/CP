#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());
        ll ans = 0;

        for (int i = 0; i < n; ++i) {
            // Find lower and upper bounds for a[j] such that:
            // l - a[i] <= a[j] <= r - a[i], and j > i
            int low = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
            int high = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin();
            ans += (high - low);
        }

        cout << ans << "\n";
    }

    return 0;
}
