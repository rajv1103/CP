#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,s;
    cin >> n>>s ;
    int ans = 0;
    vector<ll> a(n);
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int i=0;
    int sum=0;
    for(int j=0;j<n;j++){
        sum+=a[j];
        while(sum>=s){
          sum-=a[i];
          i++;
        }
        ans+=j-i+1;
        
    }
    int t=(n*(n+1))/2;
    cout << t-ans << '\n';
    return 0;
}
