#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, char> winBy = {{'R', 'P'}, {'S', 'R'}, {'P', 'S'}};
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        // Count frequencies
        map<char, int> freq;
        for (char c : s) freq[c]++;

        // Find the character with max frequency
        char maxCntChar = s[0];
        for (auto &p : freq) {
            if (p.second > freq[maxCntChar]) maxCntChar = p.first;
        }

        // Print the winning move repeated
        cout << string(s.size(), winBy[maxCntChar]) << "\n";
    }
}
