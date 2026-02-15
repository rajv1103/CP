#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
vector<int> adj[MAXN+1];
int in[MAXN+1], out[MAXN+1], euler[2*MAXN+2];
int timer = 0;

void dfs(int u, int p){
    in[u] = ++timer;
    euler[timer] = u;
    for(int v: adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    out[u] = timer;
}

// Segment tree
vector<long long> seg;
vector<long long> arr; // stores values in Euler order

void build(int idx,int l,int r){
    if(l==r){
        seg[idx]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}

void update(int idx,int l,int r,int pos,long long val){
    if(l==r){
        seg[idx]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) update(idx*2,l,mid,pos,val);
    else update(idx*2+1,mid+1,r,pos,val);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}

long long query(int idx,int l,int r,int ql,int qr){
    if(r<ql||l>qr) return 0;
    if(ql<=l && r<=qr) return seg[idx];
    int mid=(l+r)/2;
    return query(idx*2,l,mid,ql,qr)+query(idx*2+1,mid+1,r,ql,qr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<long long> val(n+1);
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);

    arr.assign(n+2,0);
    for(int i=1;i<=n;i++) arr[in[i]]=val[i];

    seg.assign(4*(n+2),0);
    build(1,1,n);

    while(q--){
        int type;cin>>type;
        if(type==1){
            int node; long long newVal;
            cin>>node>>newVal;
            update(1,1,n,in[node],newVal);
        }else{
            int node;cin>>node;
            cout<<query(1,1,n,in[node],out[node])<<"\n";
        }
    }
}
