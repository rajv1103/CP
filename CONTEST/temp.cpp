#include <bits/stdc++.h>
using namespace std;

int fn(char target, int k){
            int curNon = 0;
            for (int i = 0; i < k; ++i) if (s[i] != target) ++curNon;
            int best = curNon;
            for (int i = k; i < n; ++i) {
                if (s[i-k] != target) --curNon;
                if (s[i] != target) ++curNon;
                best = min(best, curNon);
            }
            return best;
        };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        // count 'a' and 'b'
        int cntA = 0, cntB = 0;
        for (char c : s) {
            if (c == 'a') ++cntA;
            else ++cntB;
        }
        if (cntA == 0 || cntB == 0) {
            cout << 0 << '\n';
            continue;
        }
        int ansA = fn('a', cntA);
        int ansB = fn('b', cntB);
        cout << min(ansA, ansB) << '\n';
    }
    return 0;
}
