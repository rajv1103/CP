#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        vector<int> arr(26,0);
        int cnt=0;// not deleted element;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a']){
                cnt+=2;
                arr.assign(26,0);
            }else{
                arr[s[i]-'a']=1;
            }
        }
        cout<<n-cnt<<endl;
    }
    return 0;
}