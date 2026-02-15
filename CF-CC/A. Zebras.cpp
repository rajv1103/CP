#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> arr;   // Each zebra sequence
    stack<int> waitFor0;       // Sequences expecting '0'
    stack<int> waitFor1;       // Sequences expecting '1'

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (!waitFor0.empty()) {
                // Continue a sequence waiting for 0
                int idx = waitFor0.top();
                waitFor0.pop();
                arr[idx].push_back(i + 1);
                waitFor1.push(idx);
            } else {
                // Start a new sequence
                arr.push_back({});
                int idx = arr.size() - 1;
                arr[idx].push_back(i + 1);
                waitFor1.push(idx);
            }
        } else { // s[i] == '1'
            if (!waitFor1.empty()) {
                // Continue a sequence waiting for 1
                int idx = waitFor1.top();
                waitFor1.pop();
                arr[idx].push_back(i + 1);
                waitFor0.push(idx);
            } else {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    // ✅ In Zebras, all sequences must end with '0'
    // That means no sequence should be waiting for '0' at the end
    if (!waitFor0.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    cout << arr.size() << "\n";
    for (auto &seq : arr) {
        cout << seq.size();
        for (int pos : seq) {
            cout << " " << pos;
        }
        cout << "\n";
    }

    return 0;
}
