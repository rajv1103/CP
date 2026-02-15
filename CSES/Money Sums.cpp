#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> val(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        total += val[i];
    }

    vector<bool> dp(total + 1, false);
    dp[0] = true;

    for (int x : val) {
        for (int s = total; s >= 0; s--) {
            if (dp[s]) dp[s + x] = true;
        }
    }

    vector<int> ans;
    for (int s = 1; s <= total; s++) {
        if (dp[s]) ans.push_back(s);
    }

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << " ";
    cout << "\n";
}
