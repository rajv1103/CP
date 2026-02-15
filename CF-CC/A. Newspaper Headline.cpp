#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    set<int> arr[26];
    int lastIndex=-1;
    int ans=1;
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a'].insert(i);
    }
    for(int i=0;i<t.size();i++){
        int ch=t[i]-'a';
        if(arr[ch].size()==0){
            cout<<-1<<endl;
            return 0;
        }
        auto it=arr[ch].upper_bound(lastIndex);
        if(it==arr[ch].end()){
            ans++;
            lastIndex=*arr[ch].begin();
        }else{
            lastIndex=*it;
        }
    }
    cout<<ans<<endl;
    return 0;
}