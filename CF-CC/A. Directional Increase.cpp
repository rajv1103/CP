#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using vll = vector<ll>;

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    for (ll &x : a)
        cin >> x;

    vll b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];

    for (int i = 0; i < n; i++) {
        if (b[i] < 0) {
            cout << "NO\n";
            return;
        }
        if(b[i]==0){
          int j=i+1;
          while(j<n){
            if(j<n && b[j]==0) j++;
            else break;
          }
          if(j==n){
             cout<<"YES"<<endl;
             return ;
          }
          else {cout<<"NO"<<endl; 
            return ;
          }
         
        }
    }

    if (b[n - 1] != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main()
{
    FAST_IO;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
