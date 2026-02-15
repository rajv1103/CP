#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> arr(m,INT_MAX);
    for(int i=0;i<n;i++){
        int r,c;cin>>r>>c;
        arr[r-1]=min(arr[r-1],c);
    }
    int ans=0;
    for(int i=0;i<m;i++) ans+=arr[i];
    cout<<min(ans,k)<<endl;
    return 0;
}
