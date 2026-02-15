#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    ll sc[2];
    int nxt[2];
};

node fn1(const node &L, const node &R)
{
    node res;

    for (int s = 0; s < 2; ++s)
    {
        int idx = L.nxt[s];
        res.sc[s] = L.sc[s] + R.sc[idx];
        res.nxt[s] = R.nxt[idx];
    }

    return res;
}

node fn2(ll a, ll b, ll k)
{
    node leaf;
    leaf.sc[0] = a;
    leaf.nxt[0] = 0;
    leaf.sc[1] = b;
    leaf.nxt[1] = 1;

    if (a + k < b)
    {
        leaf.sc[0] = b;
        leaf.nxt[0] = 1;
    }
    if (b + k < a)
    {
        leaf.sc[1] = a;
        leaf.nxt[1] = 0;
    }

    return leaf;
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
        ll k;
        cin >> n >> k;

        vector<ll> arr(n), brr(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> B[i];

        int q;
        cin >> q;
        if (n == 0)
        {
            while (q--)
            {
                int t, pos;
                ll x;
                cin >> t >> pos >> x;
                cout << 0 << "\n";
            }
            continue;
        }

        int m = 1;
        while (m < n)
            m <<= 1;
        vector<node> srr(2 * m);
        node id;
        id.sc[0] = id.sc[1] = 0;
        id.nxt[0] = 0;
        id.nxt[1] = 1;

        for (int i = 0; i < m; i++)
        {
            if (i < n)
            {
                srr[m + i] = fn2(arr[i], brr[i], k);
            }
            else
            {
                srr[m + i] = id;
            }
        }

        for (int p = m - 1; p >= 1; p--)
        {
            srr[p] = fn1(srr[2 * p], srr[2 * p + 1]);
        }

        while (q--)
        {
            int type, pos;
            ll x;
            cin >> type >> pos >> x;

            int idx = pos - 1;

            if (type == 1)
            {
                A[idx] = x;
            }
            else
            {
                B[idx] = x;
            }

            int p = m + idx;
            srr[p] = fn2(A[idx], B[idx], k);

            for (p >>= 1; p > 0; p >>= 1)
            {
                srr[p] = fn1(srr[p << 1], srr[(p << 1) | 1]);
            }

            cout << srr[1].sc[0] << "\n";
        }
    }
    return 0;
}
