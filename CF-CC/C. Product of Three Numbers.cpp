#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool found = false;

        for (int i = 2; i * i * i <= n; ++i) {
            if (n % i != 0) continue;
            int rem1 = n / i;
            for (int j = i + 1; j * j <= rem1; ++j) {
                if (rem1 % j != 0) continue;
                int k = rem1 / j;
                if (k > j) {
                    cout << "YES\n";
                    cout << i << " " << j << " " << k << '\n';
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) cout << "NO\n";
    }

    return 0;
}
