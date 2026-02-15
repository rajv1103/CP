#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;cin>>n>>>m>>k;
    vector<int> arr(n); for(int i=0;i<n;i++) cin>>arr[i];
    vector<pair<int,pair<int,int>>> ops(m); 
      for(int i=0;i<m;i++){
         int l,r,d;
         cin>>l>>r>>d;
         ops[i]={d,{l-1,r-1}};
      }
    vector<int> psum(n+1,0);
    while(k--){
        int x,y;cin>>x>>y;
        for(int i=x-1;i<=y-1;i++){
            psum[ops[i].second.first]+=ops[i].first;
            psum[ops[i].second.second]-=ops[i].first;
        }
    }
    psum.pop_back();
    for(int i=1;i<n;i++){
        psum[i]+=psum[i-1];
    }
    for(int i=0;i<n;i++){
        psum[i]+arr[i];
    }
    for(int i=0;i<n;i++) cout<<psum[i]<<" ";
    
    return 0;
}