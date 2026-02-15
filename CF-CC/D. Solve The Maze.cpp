#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inBounds(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void solve() {
    cin >> n >> m;
    grid.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Step 1: Block around every 'B'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (inBounds(ni, nj)) {
                        if (grid[ni][nj] == 'G') {
                            cout << "No\n"; // impossible if B touches G
                            return;
                        }
                        if (grid[ni][nj] == '.')
                            grid[ni][nj] = '#'; // block empty cell
                    }
                }
            }
        }
    }

    // Step 2: BFS/DFS from exit (n-1, m-1)
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    if (grid[n-1][m-1] != '#') {
        q.push({n-1, m-1});
        vis[n-1][m-1] = 1;
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (inBounds(nx, ny) && !vis[nx][ny] && grid[nx][ny] != '#') {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    // Step 3: Check conditions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'G' && !vis[i][j]) {
                cout << "No\n";
                return;
            }
            if vis[i][j]) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
