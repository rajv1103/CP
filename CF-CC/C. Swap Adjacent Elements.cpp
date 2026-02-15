#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n ;
    int ans = 0;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i)cin >> a[i];
    int i=0;int j=0;
    while(i<=j&&j<n-1){
        while(a[j]>a[j+1]) j++;
        if(i>0&&a[i]<a[i-1]){
               if(s[i]==0&&s[i-1]==0){
                cout<<"NO"<<endl;
                return 0;
            }else{
                swap(a[i],a[i-1]);
                i=j;j++;
            }
         }
         if(a[j]>a[j+1]){
            if(s[j]==0&&s[j+1]==0){
                cout<<"NO"<<endl;
                return 0;
            }else{
                swap(a[j],a[j+1]);
                i=j;j++;
            }
         }
    }
    if(i==n-1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
