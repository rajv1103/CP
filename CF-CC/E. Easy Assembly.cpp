#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            arr[i].push_back(x);
            v.push_back(x);
        }
    }

    sort(v.begin(), v.end());
    int split = n; // best case mein dono sorted hain aur just add them so split=2-2=0 and com =2-1=1

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i].size()-1; j++) {
            int k = lower_bound(v.begin(), v.end(), arr[i][j]) - v.begin();
            if (k == v.size() - 1) {
                split++;
            } else if ( arr[i][j + 1] != v[k + 1]) {
                split++;
            }
        }
    }

    cout << split - n << " " << split - 1 << endl;
    return 0;
}
