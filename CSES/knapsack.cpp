#include <bits/stdc++.h>
using namespace std;

int dp[105][100005];
int fn(int ind, vector<int> &wt, vector<int> &val, int w)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
            return val[0];
        return 0;
    }
    if (w <= 0)
        return 0;
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int notPick = fn(ind - 1, wt, val, w);
    int pick = 0;
    if (wt[ind] <= w)
    {
        pick = val[ind] + fn(ind - 1, wt, val, w - wt[ind]);
    }

    return dp[ind][w] = max(pick, notPick);
}

int main()
{
    int n, w;
    cin >> n >> w;
    int dp[105][100005] = {0};
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
    {
        int wi, vi;
        cin >> wi >> vi;
        wt[i] = wi;
        val[i] = vi;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = w; j >= 0; j--)
        {
            dp[i][j] = max(dp[i][j], val[i] + dp[i][w - wt[j]]);
        }
    }
    cout << dp[0][0];
    return 0;
}
