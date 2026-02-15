#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x, m;
        cin >> n >> x >> m;
        int L = x, R = x;
        while (m--) {
            int l, r;
            cin >> l >> r;
            // Check if current range overlaps with [L, R]
            if (r >= L && l <= R) {
                L = min(L, l);
                R = max(R, r);
            }
        }
        cout << R - L + 1 << "\n";
    }

    return 0;
}
