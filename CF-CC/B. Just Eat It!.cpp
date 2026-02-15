#include <bits/stdc++.h>
using namespace std;
// Why Only Check a[0...n-2] and a[1...n-1]?
// Because:

// Any subarray that is not the whole array must start or end before the start or end.

// So, every other subarray is fully contained within either:

// Prefix part a[0] to a[n-2]

// OR suffix part a[1] to a[n-1]
bool isValid(vector<long long>& a) {
    long long total = accumulate(a.begin(), a.end(), 0LL);

    long long maxPrefix = LLONG_MIN, sum = 0;
    for (size_t i = 0; i < a.size() - 1; ++i) {
        sum += a[i];
        maxPrefix = max(maxPrefix, sum);
        if (sum < 0) sum = 0;
    }

    long long maxSuffix = LLONG_MIN;
    sum = 0;
    for (size_t i = 1; i < a.size(); ++i) {
        sum += a[i];
        maxSuffix = max(maxSuffix, sum);
        if (sum < 0) sum = 0;
    }

    return (total > max(maxPrefix, maxSuffix));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        cout << (isValid(a) ? "YES" : "NO") << "\n";
    }
    return 0;
}
