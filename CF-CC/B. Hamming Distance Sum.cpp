#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    // Prefix sum of ones in b
    vector<int> pref(m + 1, 0);
    for (int i = 0; i < m; i++) {
        pref[i + 1] = pref[i] + (b[i] == '1');
    }

    long long ans = 0;

    // For each character in a, check how many mismatches happen
    for (int i = 0; i < n; i++) {
        // In b, this char of a will align with positions i to i+(m-n)
        int left = i;
        int right = i + (m - n);

        int ones = pref[right + 1] - pref[left];
        int total = right - left + 1;
        int zeros = total - ones;

        if (a[i] == '0') {
            // Mismatch when b has '1'
            ans += ones;
        } else {
            // Mismatch when b has '0'
            ans += zeros;
        }
    }

    cout << ans << "\n";
    return 0;
}
