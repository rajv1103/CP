#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> cost(n+1), page(n+1);
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 1; i <= n; i++) cin >> page[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];  // not taking
            if (j >= cost[i]) 
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + page[i]); // taking
        }
    }
    cout << dp[n][x] << "\n";
}
