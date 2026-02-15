#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 9;
const int P = 31;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    vector<ll> power(n + 1, 1);
    vector<ll> hash(n + 1, 0);

    // Precompute powers of P and prefix hashes
    for (int i = 1; i <= n; i++)
        power[i] = (power[i - 1] * P) % MOD;

    for (int i = 0; i < n; i++)
        hash[i + 1] = (hash[i] * P + (s[i] - 'a' + 1)) % MOD;

    // Lambda to compute hash of substring s[l..r]
    auto getHash = [&](int l, int r) -> ll {
        ll res = (hash[r + 1] - hash[l] * power[r - l + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    };

    vector<int> candidates;

    // Find all borders (prefix == suffix)
    for (int len = 1; len < n; ++len) {
        if (getHash(0, len - 1) == getHash(n - len, n - 1))
            candidates.push_back(len);
    }

    // Try longest candidate first
    for (int i = candidates.size() - 1; i >= 0; --i) {
        int len = candidates[i];
        ll targetHash = getHash(0, len - 1);

        // Search in the middle
        for (int j = 1; j < n - len; ++j) {
            if (getHash(j, j + len - 1) == targetHash) {
                cout << s.substr(0, len) << endl;
                return 0;
            }
        }
    }

    cout << "Just a legend" << endl;
    return 0;
}
