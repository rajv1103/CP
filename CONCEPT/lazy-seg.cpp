#include<bits/stdc++.h>
using namespace std;
const int N=1e5;

vector<int>seg(N);
vector<int>lazy(N);
vector<int>arr(N);

void push(int ind,int val){
    if(lazy[ind]!=-1){
       lazy[2*ind]+=val;
       lazy[2*ind+1]+=val;      
    }
    lazy[ind]=0;
}
void build(int st,int end,int ind){
   if(st==end){
      seg[ind]=arr[st];
      return;
   }
    int mid=(st+end)/2;
   build(st,mid,2*ind);
   build(mid+1,end,2*ind+1);
   seg[ind]=seg[2*ind]+seg[2*ind+1];
}
void update(int st,int end,int ind,int l,int r,int val){
   push(ind,val,l,r);
   if(r<st || l>end) return 0;
   if(st>=l && end<=r){
      seg[ind]+=(r-l+1)*val;
      lazy[ind] += val;
      push(ind,val);
      return;     
   };
   int mid=(st+end)/2;

   update(st,mid,2*ind,l,r,val);  
   update(mid+1,end,2*ind+1,l,r,val);
   seg[ind]=seg[2*ind]+seg[2*ind+1];
}
int query(int st,int end,int ind,int l,int r){
   if(r<st || l>end) return 0;
   if(l<=st && r>=end) return seg[ind];
   int mid=(st+end)/2;
   int left=query(st,mid,2*ind,l,r);
   int right=query(mid+1,end,2*ind+1,l,r);
   return left+right;
}

int main(){
    int n;cin>>n;
    cout<<"Enter the number of nodes "<<endl ;
    seg.resize(4*n);
    lazy.resize(4*n);
    arr.resize(n+1);
    cout<<"enter array "<<endl ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    cout<<"before"<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    build(0,n-1,1);
    cout<<query(0,n-1,1,2,4)<<endl;
    update(0,n-1,1,2,10);
    cout<<"after update"<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
    cout<<query(0,n-1,1,2,4)<<endl;
    return 0;
}