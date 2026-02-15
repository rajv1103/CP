#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target = n / m;
    vector<int> need;
    vector<int> cnt(m + 1, 0);
    for (int x : arr)
    {
        if (x >= 1 && x <= m)
            cnt[x]++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt[i] < target)
        {
            int want = target - cnt[i];
            for (int j = 0; j < want; j++)
                need.push_back(i);
        }
    }
    int change = 0;
    for (int i = 0; i < n && !need.empty(); i++)
    { // >m wale ko hatao;
        if (arr[i] > m)
        {
            arr[i] = need.back();
            cnt[need.back()]++;
            need.pop_back();
            change++;
        }
    }
    // need puri karo
    for (int i = 0; i < n && !need.empty(); i++)
    {
        if (arr[i] >= 1 && arr[i] <= m && cnt[arr[i]] > target)
        {

            cnt[arr[i]]--;
            arr[i] = need.back();
            cnt[need.back()]++;
            need.pop_back();
            change++;
        }
    }
    cout << target << " " << change << "\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
    return 0;
}