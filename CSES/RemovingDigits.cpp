#include <bits/stdc++.h>
using namespace std;

int getmaxi(int k){
   int maxi=INT_MIN;
    while(k){
        maxi=max(maxi,k%10);
        k/=10;
    }
    return maxi;
}
int fn(int i){
   if(i%10==i) return 1;
   return 1+fn(i-getmaxi(i));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n ;
    cout<< fn(n)<<endl;
    

    return 0;
}
