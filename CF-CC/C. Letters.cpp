#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> dorm(n), pref(n);
    for (int i = 0; i < n; ++i) {
        cin >> dorm[i];
        pref[i] = dorm[i] + (i > 0 ? pref[i - 1] : 0);
    }

    for (int i = 0; i < m; ++i) {
        ll room;
        cin >> room;

        // Find first dormitory where room ≤ prefix sum
        ll idx = lower_bound(pref.begin(), pref.end(), room) - pref.begin();
        ll prev_sum = (idx == 0 ? 0 : pref[idx - 1]);
        ll local_room = room - prev_sum;
        cout << idx + 1 << " " << local_room << "\n";
    }

    return 0;
}