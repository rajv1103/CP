#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);

    map<int, int> mp; // store "seen version" instead of bool
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]] = 0; // init version = 0
    }

    vector<pair<int, int>> pr;
    int cnt = 0;
    int lstINd = 0;

    int currentVersion = 1; // instead of clearing map

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] == currentVersion) {
            cnt++;
            pr.push_back({lstINd + 1, i + 1});
            lstINd = i + 1;
            currentVersion++; // "reset" without iterating map
        } else {
            mp[arr[i]] = currentVersion;
        }
    }

    if (lstINd == 0) {
        cout << -1 << '\n';
        return 0;
    }

    cout << cnt << '\n';
    for (int i = 0; i < (int)pr.size(); i++) {
        cout << pr[i].first << " " << (i == pr.size() - 1 ? n : pr[i].second) << '\n';
    }
    return 0;
}
