#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, c, d;
        cin >> n >> c >> d;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) 
            cin >> arr[i];
        sort(arr.begin(), arr.end());

        long long i = 0;
        long long ans = 0;
        vector<long long> uniq;

        while (i < n) {                      // remove duplicates
            uniq.push_back(arr[i]);
            long long val = arr[i];
            while (i < n && arr[i] == val) {
                ans += c;
                i++;
            }
            ans -= c;
        }

        long long z = LLONG_MAX;
        for (long long i = uniq.size() - 1; i >= 0; i--) {    // iterate downwards
            long long x = uniq.size() - i - 1;
            long long y = uniq[i] - i - 1;
            z = min(z, x * c + y * d);
        }

        ans += z;
        ans = min(ans, n * c + d);
        cout << ans << "\n";
    }
    return 0;
}
