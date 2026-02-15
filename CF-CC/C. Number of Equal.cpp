#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<ll> a(n), b(n);
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
        
    int i=0,j=0;
    
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            int t = a[i];
            int cnt1 = 0, cnt2 = 0;
            while (i < n && a[i] == t) {
                cnt1++;
                i++;
            }
            while (j < m && b[j] == t) {
                cnt2++;
                j++;
            }
            ans += cnt1 * cnt2;
        }
    }

   

    cout << ans ;
    return 0;
}
