#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    int odd_count = 0;
    int odd_index = -1;

    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            odd_count++;
            odd_index = i;
        }
    }

    if (odd_count > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string half = "", mid = "";
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            mid = string(freq[i], 'A' + i);
        } else {
            half += string(freq[i] / 2, 'A' + i);
        }
    }

    string rev_half = half;
    reverse(rev_half.begin(), rev_half.end());

    cout << half + mid + rev_half << '\n';

    return 0;
}
