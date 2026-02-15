#include <bits/stdc++.h>
using namespace std;

// Maximum number of nodes in the tree
const int N = 1e5 + 10;

// Adjacency list to represent the tree
vector<vector<int>> adj(N);

// Subtree sum array: sub_tree[i] holds sum of node values in subtree rooted at i
vector<int> sub_tree(N);

// Recursive DFS function to compute subtree sums
void fn(int node, int par = -1) {
    sub_tree[node] += node; // Include current node's value

    // Traverse all children
    for (auto child : adj[node]) {
        if (child == par) continue; // Skip parent to avoid cycles
        fn(child, node);            // DFS call to child
        sub_tree[node] += sub_tree[child]; // Add child's subtree sum to current node
    }
}

int main() {
    int n;
    cin >> n; // Read number of nodes

    // Input edges and construct tree
    for (int i = 1; i <= n - 1; i++) {
        cout << "Enter u->v: ";
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge u → v
        adj[v].push_back(u); // Add edge v → u (undirected)
    }

    fn(1); // Compute subtree sums starting from root node 1

    // Goal: Find the maximum product of the sum of two separated components
    int ans = INT_MIN;
    for (int i = 2; i <= n; i++) { // Start from node 2 to avoid disconnecting entire tree
        int x = sub_tree[i];          // Subtree sum of node i
        int y = sub_tree[1] - x;      // Remaining tree sum if edge to i is cut
        ans = max(ans, x * y);        // Maximize the product of the two parts
    }

    cout << "MAX PROD IS: " << ans << endl;
    return 0;
}