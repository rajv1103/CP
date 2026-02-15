#include <bits/stdc++.h>
using namespace std;

int editDistMemo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) {
        return dp[i][j] = editDistMemo(i - 1, j - 1, s1, s2, dp);
    }

    int insertOp = 1 + editDistMemo(i, j - 1, s1, s2, dp);
    int removeOp = 1 + editDistMemo(i - 1, j, s1, s2, dp);
    int replaceOp = 1 + editDistMemo(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = min({insertOp, removeOp, replaceOp});
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << editDistMemo(n - 1, m - 1, s1, s2, dp) << "\n";
}
