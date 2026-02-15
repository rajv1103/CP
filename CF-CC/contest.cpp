#include <bits/stdc++.h>
using namespace std;

void fn(vector<long long> &arr, map<pair<int, int>, int> &countMap, long long k)
{
    for (auto val : arr)
    {
        int rem = val % k;
        int cmp = (k - rem) % k;

        int a = min(rem, cmp);
        int b = max(rem, cmp);

        countMap[{a, b}]++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> srr(n), trr(n);
        for (int i = 0; i < n; i++)
            cin >> srr[i];
        for (int i = 0; i < n; i++)
            cin >> trr[i];

        map<pair<int, int>, int> cntsrr, cnttrr;

        fn(srr, cntsrr,k);
        fn(trr, cnttrr,k);

        if (cntsrr == cnttrr)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
