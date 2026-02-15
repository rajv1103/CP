#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> sum(1000065, 0); // a bit bigger to avoid overflow
    int cnt = 0;

    // Count occurrences of each exponent
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum[x]++;
    }

    // Merge counts upwards
    for (int i = 0; i < 1000064; i++)
    {                             // up to second last index
        sum[i + 1] += sum[i] / 2; // carry to next power
        sum[i] %= 2;              // keep only 0 or 1 here
        if (sum[i])
            cnt++; // if we have one left, it’s a step
    }

    cout << cnt << "\n";
    return 0;
}
