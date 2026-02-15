#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<bool> L(n, false), R(n, false);

        // Build L: can we reach strictly increasing up to i?
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < i) ok = false;
            L[i] = ok;
        }

        // Build R: can we reach strictly decreasing from i to end?
        ok = true;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < (n - 1 - i)) ok = false;
            R[i] = ok;
        }

        // Check for any valid peak position
        bool canSharpen = false;
        for (int i = 0; i < n; i++) {
            if (L[i] && R[i]) {
                canSharpen = true;
                break;
            }
        }

        cout << (canSharpen ? "Yes\n" : "No\n");
    }
    return 0;
}
