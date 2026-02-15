#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, s;
    cin >> t >> s;

    map<int, int> freq_t, freq_s;

    for (char c : t) freq_t[c - '0']++;
    for (char c : s) freq_s[c - '0']++;

    freq_s[2] += freq_s[5];
    freq_t[2] += freq_t[5];

    int ans = INT_MAX;

    for (int i = 0; i <= 9; i++) {
        if (freq_t[i] > 0) {
            if (freq_s[i] == 0) {
                ans = 0; 
                break;
            }
            ans = min(ans, freq_s[i] / freq_t[i]);
        }
    }

    cout << ans << endl;
    return 0;
}
