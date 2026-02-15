#include <bits/stdc++.h>
using namespace std;
void make_node(int v,vector<int>&parent,vector<int>&size){
    parent[v]=v;
    size[v]=1;
}
int find_par(int x,vector<int>&parent){
    if(x==parent[x]) return x;  // disconnected component
    return parent[x]=find_par(parent[x],parent); //path compression
}
void unionfn(int x,int y,vector<int>&parent,vector<int>&size){
     int par_x=find_par(x,parent);
     int par_y=find_par(y,parent);
     if(par_x != par_y){
         if(size[par_x]<size[par_y]) swap(x,y);  // small wala alwayson left;
         parent[y]=x;
     }
}

int main() {
    int n;
    cin >> n;
    vector<int>parent(n);
    vector<int>size(n);
    for(int i=1;i<=n;i++){
        make_node(i,parent,size);
    }
    int k; cin>>k;
    while(k--){
        int u,v;
        cin>>u>>v;
        unionfn(u,v,parent,size);
    }
    int connected_comp=0;
    for(int i=1;i<=n;i++){
        if(parent[i]==i) connected_comp++;
    }
    cout<<connected_comp<<endl;
    return 0;
}
