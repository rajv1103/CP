#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> t(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> t[i];

    ll base = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == 1) base += a[i];
    }

    ll max_add = 0, curr_add = 0;
    for (int i = 0; i < k; ++i) {
        if (t[i] == 0) curr_add += a[i];
    }

    max_add = curr_add;

    for (int i = k; i < n; ++i) {
        if (t[i - k] == 0) curr_add -= a[i - k];
        if (t[i] == 0) curr_add += a[i];
        max_add = max(max_add, curr_add);
    }

    cout << base + max_add << "\n";
    return 0;
}