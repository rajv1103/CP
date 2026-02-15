#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> p(n + 1), c(n + 1);
    vector<vector<int>> children(n + 1);

    int root = -1;
    for (int i = 1; i <= n; ++i) {
        int pi, ci;
        cin >> pi >> ci;   // pi = parent of i, ci = respect flag
        p[i] = pi;
        c[i] = ci;
        if (pi == -1) root = i;
        else children[pi].push_back(i);
    }

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (p[i] == -1) continue;          // root can't be deleted
        if (c[i] != 1) continue;           // must not respect parent
        bool flag = true; // i.e., all children have c=1
        for (int u : children[i]) {
            if (c[u] == 0) {               // a child respects i -> can't delete i
                flag = false;
                break;
            }
        }
        if (flag) ans.push_back(i);
    }

    if (ans.empty()) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < (int)ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
