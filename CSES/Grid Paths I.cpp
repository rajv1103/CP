#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Initialize first row
    for (int i = 0; i < n; i++) {
        if (arr[0][i] == '*') break; // everything after obstacle stays 0
        dp[0][i] = 1;
    }

    // Initialize first column
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == '*') break; // everything after obstacle stays 0
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[i][j] == '*') continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n-1][n-1] % MOD << "\n";
    return 0;
}
