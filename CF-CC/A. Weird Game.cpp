#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    // Count the types of positions
    int cnt00 = 0, cnt01 = 0, cnt10 = 0, cnt11 = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == '0' && t[i] == '0') cnt00++;
        else if (s[i] == '0' && t[i] == '1') cnt01++;
        else if (s[i] == '1' && t[i] == '0') cnt10++;
        else if (s[i] == '1' && t[i] == '1') cnt11++;
    }

    int turn = 0; // 0: Yaroslav, 1: Andrey
    int y = 0, a = 0; // number of 1s collected by Yaroslav and Andrey

    for (int moves = 0; moves < 2 * n; ++moves) {
        // Choose optimal position for current player
        if (turn == 0) { // Yaroslav
            if (cnt11 > 0) {
                cnt11--;
                y++;
            } else if (cnt10 > 0) {
                cnt10--;
                y++;
            } else if (cnt01 > 0) {
                cnt01--;
            } else {
                cnt00--;
            }
        } else { // Andrey
            if (cnt11 > 0) {
                cnt11--;
                a++;
            } else if (cnt01 > 0) {
                cnt01--;
                a++;
            } else if (cnt10 > 0) {
                cnt10--;
            } else {
                cnt00--;
            }
        }
        turn ^= 1; // switch player
    }

    if (y > a) cout << "First\n";
    else if (y < a) cout << "Second\n";
    else cout << "Draw\n";

    return 0;
}
