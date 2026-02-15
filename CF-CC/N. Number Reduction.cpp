#include <bits/stdc++.h>
using namespace std;

// Macro to iterate from l to r - 1
#define fo2(i, l, r) for (int i = (l); i < (r); i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int k;
        cin >> k;
        int ind = 0;

        // Find the smallest character in the first k+1 positions
        fo2(i, 0, k + 1)
        {
            if (s[i] != '0' && s[i] < s[ind])
            {
                ind = i;
            }
        }

        k -= ind;

        string ans;
        ans.push_back(s[ind]);

        for (int i = ind + 1; i < s.size(); i++)
        {
            while (k > 0 && ans.size() > 1 && ans.back() > s[i])
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(s[i]);
        }

        // Remove remaining characters if needed
        while (k--)
        {
            ans.pop_back();
        }

        cout<<ans<<endl;
    }

    return 0;
}