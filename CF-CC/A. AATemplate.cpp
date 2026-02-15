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

// ─── UTILITY FUNCTIONS ──────────────────────────────────────────────────────

// Modular exponentiation (a^b mod m)
ll mod_pow(ll a, ll b, ll m = 1e9+7) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Compute factorial mod m (up to n)
vector<ll> fact_pref(int n, ll m = 1e9+7) {
    vector<ll> fact(n+1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i-1] * i % m;
    return fact;
}

// ─── SOLVE ───────────────────────────────────────────────────────────────────
void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (ll &x : a) cin >> x;

    // Example: print the first element and k
    cout << a[0] << " " << k << "\n";
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
