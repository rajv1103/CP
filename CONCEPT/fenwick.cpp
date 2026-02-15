#include<bits/stdc++.h>
using namespace std;
vector<int>bit;

void update(int i,int val){
    for(;i<=n;i+=i&-i){
        bit[i]+=val;
    }
}
int presum(int i){
    int res=0;
    for(;i>0;i-=i&-i){
        res+=bit[i];
    }
   return res;
}
int range_sum(int l, int r) {
    return presum(r) - presum(l - 1);
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    bit.assign(n+1,0);
    //build the bit tree
    for(int i=0;i<n;i++){
       update(i+1,arr[i]);
    }
    cout << "Sum of [1..3] = " << range_sum(1, 3) << "\n"; // 1+2+3 = 6
    cout << "Sum of [2..5] = " << range_sum(2, 5) << "\n"; // 2+3+4+5 = 14

    // update: add +10 at index 3 (i.e., a[2] in 0-based)
    update(3, 10);
    cout << "After update: Sum of [1..3] = " << range_sum(1, 3) << "\n"; // 1+2+(3+10) = 16

    return 0;
}