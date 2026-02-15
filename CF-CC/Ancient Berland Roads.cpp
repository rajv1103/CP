#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    vector<long long> sum;
    multiset<long long> *S;

    DSU(int n, vector<long long>& pop, multiset<long long>& MS)
      : p(n+1), sum(n+1), S(&MS) {
        for(int i=1; i<=n; i++){
            p[i]=i;
            sum[i]=pop[i];
            S->insert(pop[i]);
        }
    }

    int find(int x){
        return p[x]==x ? x : p[x]=find(p[x]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        // remove old sums
        S->erase(S->find(sum[a]));
        S->erase(S->find(sum[b]));
        // union by size heuristic
        if(sum[a] < sum[b]) swap(a,b);
        p[b] = a;
        sum[a] += sum[b];
        S->insert(sum[a]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,Q; 
    cin>>N>>M>>Q;

    vector<long long> pop(N+1);
    for(int i=1;i<=N;i++) 
        cin>>pop[i];

    vector<pair<int,int>> edges(M+1);
    for(int i=1;i<=M;i++)
        cin>>edges[i].first>>edges[i].second;

    vector<bool> willDelete(M+1,false);
    struct Query{ char type; int a,k; long long newVal, oldVal; };
    vector<Query> queries(Q+1);

    // Record queries and mark deletions & store old populations
    for(int i=1;i<=Q;i++){
        cin>>queries[i].type;
        if(queries[i].type=='D'){
            cin>>queries[i].k;
            willDelete[queries[i].k]=true;
        } else {
            cin>>queries[i].a>>queries[i].newVal;
            queries[i].oldVal = pop[queries[i].a];
            pop[queries[i].a] = queries[i].newVal;
        }
    }

    // Build DSU on the final state
    multiset<long long> MS;
    DSU dsu(N, pop, MS);
    for(int i=1;i<=M;i++){
        if(!willDelete[i]){
            dsu.unite(edges[i].first, edges[i].second);
        }
    }

    // Process in reverse and record answers
    vector<long long> ansRev(Q+1);
    ansRev[0] = *prev(MS.end());

    for(int r=1; r<=Q; r++){
        auto &qry = queries[Q+1-r];
        if(qry.type=='D'){
            // reversed delete → add edge
            auto [u,v] = edges[qry.k];
            dsu.unite(u,v);

        } else {
            // reversed update → revert population
            int A = qry.a;
            int root = dsu.find(A);

            MS.erase(MS.find(dsu.sum[root]));
            dsu.sum[root] += (qry.oldVal - pop[A]);
            pop[A] = qry.oldVal;
            MS.insert(dsu.sum[root]);
        }
        ansRev[r] = *prev(MS.end());
    }

    // Output in original order
    for(int i=1;i<=Q;i++){
        cout << ansRev[Q-i] << "\n";
    }
    return 0;
}
