#include <bits/stdc++.h>
using namespace std;

vector<int> computePrefixFunction(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    vector<int> pi = computePrefixFunction(s);

    vector<int> borders;
    int k = pi.back(); // Start from the prefix length at the end of string
    while (k > 0) {
        borders.push_back(k);
        k = pi[k - 1]; // Move to the next shorter border
    }

    sort(borders.begin(), borders.end()); // Increasing order
    for (int b : borders)
        cout << b << " ";
    cout << endl;
    return 0;
}
