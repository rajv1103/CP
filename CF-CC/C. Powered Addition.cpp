#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)

void solve() {
    int n;
    cin >> n;
    int arr[n];
    fo(i, n) cin >> arr[i];

    int max_diff = 0, curr_max = arr[0];

    for (int i = 1; i < n; i++) {
        max_diff = max(max_diff, curr_max - arr[i]);
        curr_max = max(curr_max, arr[i]);
    }
   
   

    int ans = 0, p = 1;
    while (max_diff > 0) {
        max_diff -= min((long long)pow(2, p - 1), (long long)1e18);
        ans++;
        p++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
