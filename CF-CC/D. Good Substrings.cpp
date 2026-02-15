#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, v;
    cin >> s >> v;
    int k;
    cin >> k;
    set<pair<int, int>> st; // To store unique hashes
    int base[2] = {53, 127};
    int mod[2] = {1000000007, 1000000009};
    int n = s.size(), m = v.size();
    for (int i = 0; i < n; ++i)
    {
        int pow[2] = {1, 1};
        int hash[2] = {0, 0};
        int nb = 0;
        for (int j = i; j < n; ++j)
        {
            if (v[s[j] - 'a'] == '0')
                nb++;
            if (nb > k)
                break;
            for (int l = 0; l < 2; l++)
            {
                hash[l] = (hash[l] + s[j] * pow[l]) % mod[l];
                pow[l] = (pow[l] * base[l]) % mod[l];
            }
            st.insert({hash[0], hash[1]}); // Insert the hash into the set
        }
    }
    cout<<st.size() << endl;
    return 0;
}