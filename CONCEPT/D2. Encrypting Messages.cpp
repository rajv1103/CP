#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> arr(n), b(m);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> diff(n + 2, 0);

    // Build difference array
    for (int j = 0; j < m; j++) {
        int start = j;
        int end = j + (n - m) + 1; // last index + 1
        diff[start] = (diff[start] + b[j]) % c;
        diff[end] = (diff[end] - b[j] + c) % c; // avoid negative
    }

    // Prefix sum to apply additions
    for (int i = 1; i < n; i++) {
        diff[i] = (diff[i] + diff[i - 1]) % c;
    }

    // Apply to array
    for (int i = 0; i < n; i++) {
        int val = (arr[i] + diff[i]) % c;
        cout << val << (i == n - 1 ? '\n' : ' ');
    }
    return 0;
}









