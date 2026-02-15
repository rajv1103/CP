#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // Step 1: Precompute minimum suffix characters
    vector<char> minSuffix(n);
    minSuffix[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        minSuffix[i] = min(s[i], minSuffix[i + 1]);
    }

    // Step 2: Simulate the operations
    stack<char> t;
    string u;
    int i = 0;

    while (i < n || !t.empty()) {
        // Always move from s to t
        if (i < n) {
            t.push(s[i]);
            ++i;
        }

        // While top of t is <= the smallest char left in s, move from t to u
        while (!t.empty() && (i == n || t.top() <= minSuffix[i])) {
            u += t.top();
            t.pop();
        }
    }

    // Step 3: Output the result
    cout << u << endl;
    return 0;
}
