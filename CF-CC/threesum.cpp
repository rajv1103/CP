#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1; 
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rem = x - arr[i].first - arr[j].first;

  
            auto it = lower_bound(arr.begin() + j + 1, arr.end(), make_pair(rem, 0));

            if (it != arr.end() && it->first == rem) {
                cout << arr[i].second << " " << arr[j].second << " " << it->second << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
