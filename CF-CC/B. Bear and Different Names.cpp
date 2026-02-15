#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<string> s(n - k + 1);
    for (int i = 0; i < n - k + 1; i++) cin >> s[i];

    // Generate 55 unique names
    vector<string> name(55);
    for (int i = 0; i < 55; ++i) {
        name[i] = string(1, 'A' + i / 26) + string(1, 'a' + i % 26);
    }

    vector<string> ans;

    // Initialize first k-1 names
    for (int i = 0; i < k - 1; ++i) {
        ans.push_back(name[i]);
    }

    int idx = k - 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == "YES") {
            ans.push_back(name[idx++]);
        } else {
            ans.push_back(ans[ans.size() - (k - 1)]); // repeat one from k-1 positions back
        }
    }

    for (auto &x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
