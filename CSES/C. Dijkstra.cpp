    #include<bits/stdc++.h>
    using namespace std;
    #define ll  long long 
    vector<vector<pair<ll,ll>>>adj;
    vector<ll >parent;
    vector<ll> dist;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;


    int main(){
        int n,m;cin>>n>>m;
        adj.assign(n+1,{});
        parent.assign(n+1,-1);
        dist.assign(n+1,LLONG_MAX);
        dist[1]=0;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a, c});
        }

        pq.push({0,1});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int d=it.first;
            if(d>dist[node]) continue;
            for(auto jt :adj[node]){
                int child=jt.first;
                int wt=jt.second;
                if(child==parent[node]) continue;
                if(dist[child]>dist[node]+wt){
                    parent[child]=node;
                    dist[child]=dist[node]+wt;
                    pq.push({dist[child],child});
  
                }
            }
        }
        if(parent[n]==-1){
            cout<<-1<<endl;
            return 0;
        }
        vector<int> path;
        int i=n;
        while(parent[i]!=-1){
            path.push_back(i);
            i=parent[i];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for(auto it:path){
            cout<<it<<" ";
        }
        return 0;
    }