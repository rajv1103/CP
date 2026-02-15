#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    double l = 0.0;
    double r = *max_element(arr.begin(), arr.end());
    
    for (int i = 0; i < 100; i++) { // 100 iterations → enough precision
        double mid = (l + r) / 2.0;
        int cnt = 0;
        for (int len : arr) {
            cnt += (int)(len / mid);
        }
        if (cnt >= k) {
            l = mid; // can make pieces of at least mid → try bigger
        } else {
            r = mid; // too big → try smaller
        }
    }

    cout << fixed << setprecision(10) << l << "\n"; // 10 decimal places for safety
    return 0;
}
