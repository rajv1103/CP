#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> scc;
vector<vector<int>> tadj;
stack<int>st;
vector<int> visited;
void dfs(int node){
     visited[node]=1;
     for(auto it:adj[node]){
        if(!visited[it])dfs(it);
     }
     st.push(node);
}
void dfs2(int node,vector<int> &temp){
    temp.push_back(node);
     visited[node]=1;
     for(auto it:tadj[node]){
        if(!visited[it])dfs2(it,temp);
     }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    tadj.resize(n+1);
    visited.resize(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        tadj[y].push_back(x);
    }
    dfs(1);
   fill(visited.begin(), visited.end(), 0);
    while(!st.empty()){
        int node=st.top();st.pop();
        if(!visited[node]){
            vector<int>temp;
            dfs2(node,temp);
            scc.push_back(temp);

        }
    }
    cout<<scc.size()<<endl;
    for(auto it:scc){
        for(auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
