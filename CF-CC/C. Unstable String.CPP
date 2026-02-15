#include <bits/stdc++.h>
using namespace std;

long long  arr0[2] = {0, 0}; // even and odd posis
long long  arr1[2] = {0, 0};
bool isValid()
{
    if (arr0[0] && arr0[1])
        return 0;
    if (arr0[1] && arr1[1])
        return 0;
    if (arr0[0] && arr1[0])
        return 0;
    if (arr1[0] && arr1[1])
        return 0;

    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long l = 0;
        long long ans = 0;
        for (long long r = 0; r < s.size(); r++)
        {
            if (s[r] == '0')
            {
                arr0[r % 2] += 1;
            }
            if (s[r] == '1')
            {
                arr1[r % 2] += 1;
            }
            while (!isValid())
            {
                if (s[l] == '0')
                {
                    arr0[l % 2] -= 1;
                }
                if (s[l] == '1')
                {
                    arr1[l % 2] -= 1;
                }
                l++;
            }
            ans += r - l + 1;
        }
        cout << ans << endl;
        arr0[0]=0;arr0[1]=0;
        arr1[0]=0;arr1[1]=0;
    }

    return 0;
}
