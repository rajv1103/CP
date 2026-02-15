#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long t;
    cin >> n >> t;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long l = 1;
    long long r = *min_element(arr.begin(), arr.end()) * t; // upper bound
    long long ans = r;

    while (l <= r) {
        long long mid = l + (r - l) / 2;
        __int128 cnt = 0; // prevent overflow in sum
        for (long long x : arr) {
            cnt += mid / x;
            if (cnt >= t) break; // early stop to save time
        }
        if (cnt >= t) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
