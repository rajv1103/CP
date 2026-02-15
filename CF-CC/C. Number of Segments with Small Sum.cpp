#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll s;
    cin >> n >> s;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll ans = 0, sum = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        sum += a[r];

        // Shrink from left if sum exceeds s
        while (sum > s) {
            sum -= a[l];
            ++l;
        }

        // All subarrays from l to r are valid
        ans += (r - l + 1);
    }

    cout << ans << "\n";
    return 0;
}
