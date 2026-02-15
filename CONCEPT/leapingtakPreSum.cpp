#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    vector<pair<int,int>> arr(k);
    for(int i=0;i<k;i++){
         cin >> arr[i].first >> arr[i].second;
    }

    vector<int>sum(n+1,0);
    sum[1]=1;
    for(int i=2;i<=n;i++){
          ll curr=0;
          for(int j=0;j<k;j++){
              int l=arr[j].first;
              int r=arr[j].second; // l se r ke beech steps size hain ,checkkt that step pr current i pr kitne tarike se aa skte;
              int left=max(i-r,1);
              int right=i-l;
              if(right<1) continue;
              curr += (sum[right] - sum[left - 1] + MOD) % MOD;
              curr %= MOD;
          }
          sum[i] = (sum[i - 1] + curr) % MOD;
    }
   ll ans = (sum[n] - sum[n - 1] + MOD) % MOD;
    cout << ans << "\n";

    return 0;
}