#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
using ld = long double;
using vll = vector<ll>;

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll &x : a) cin >> x;
    vector<vector<long long>> ans;
    for(int i=0;i<n;i++){

        int l=-1;
        int r=n+1;
        int ind=ans.size();
        while(r-l>1){
            int mid=(l+r)/2;
            if(ans[mid].back()<a[i]){
                ind=mid;
                r=mid-1;
            }else l=mid+1;
        }
        if(ind==ans.size()){
            ans.push_back(a[i]);
        }else{
            ans[mid].push_back(a[i]);
        }
    }
    for(auto it:ans){
      for (auto &row : ans) { for (auto v : row) cout << v << ' '; cout << '\n'; }
    }
   
}

int main() {
    FAST_IO;
    solve();
    return 0;
}
