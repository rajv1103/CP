#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int n,k,ans;
vector<int> p(9);
bool check1(int x,int step){
    if(step>k) return 0;
    if(x==1) return 1;
    return check1(p[x],step+1);
}
void dfs(int x){                              /// x is the house
    if(x>k){
        bool temp=1;
        for(int i=1;i<=k&&temp;i++){
            temp&=check1(p[i],0);
        }
        if(temp) ans++;
              return ;
    }
    for(int i=1;i<=k;i++){
        p[x]=i;
        dfs(x+1);
    }
}
int main(){
     cin>>n>>k;
     dfs(1);
     for(int i=k+1;i<=n;i++){
        ans=(ans*1ll*(n-k))%mod;
     }
     cout<<ans<<endl;
    return 0;
}