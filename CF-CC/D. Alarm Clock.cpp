#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    int l = 0; 


    for (int r = 0; r < n; r++) {
        // Ensure window covers at most m minutes
        while (arr[r] - arr[l] >= m) {
            l++;
        }
        int cnt = r - l + 1; // alarms in this window
        if (cnt >= k) {
            // Remove enough to keep cnt < k
            ans++;
            l++; // remove the earliest alarm in this window
        }
    }

    cout << ans << "\n";
    return 0;
}
