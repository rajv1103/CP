#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<vector<int>> adj(N); 
vector<int> p(N);            

// DFS to assign parents
void fn(int node, int par = -1) {
    p[node] = par;
    for (auto child : adj[node]) {
        if (child == par) continue;
        fn(child, node);
    }
}

// Function to trace the path from node to root
vector<int> path(int node) {
    vector<int> ans;
    while (node != -1) {
        ans.push_back(node);
        node = p[node];
    }
    reverse(ans.begin(), ans.end()); // Now it's from root to node
    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        cout << "Enter u->v: ";
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fn(1); // Assuming 1 is the root

    int x, y;
    cout << "Enter the value of X and Y: ";
    cin >> x >> y;

    vector<int> path_x = path(x);
    vector<int> path_y = path(y);

    int min_len = min(path_x.size(), path_y.size());
    int lca = -1;
    for (int i = 0; i < min_len; i++) {
        if (path_x[i] == path_y[i]) {
            lca = path_x[i];
        } else {
            break;
        }
    }

    cout << "LCA IS: " << lca << endl;
    return 0;
}