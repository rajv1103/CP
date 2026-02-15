#include <bits/stdc++.h>
using namespace std;

// ─── FAST I/O ────────────────────────────────────────────────────────────────
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// ─── TYPE ALIASES ───────────────────────────────────────────────────────────
using ll   = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using pii  = pair<int,int>;
using pll  = pair<ll,ll>;

// ─── SHORT-HAND MACROS ──────────────────────────────────────────────────────
#define all(x)   (x).begin(), (x).end()
#define sz(x)    int((x).size())
#define pb       push_back
#define F        first
#define S        second

ll fn(char ch, const string &s) {
    vector<ll> pos;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == ch) pos.push_back(i + 1); 
    }
    int m = pos.size();
    if (m <= 1) return 0;

    vector<ll> q(m);
    for (int i = 0; i < m; ++i) q[i] = pos[i] - (i + 1);
    ll med = q[m/2];
    ll cost = 0;
    for (int i = 0; i < m; ++i) cost += llabs(q[i] - med);
    return cost;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << min(fn('a', s), fn('b', s)) << '\n';
}

int main() {
    FAST_IO;

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
