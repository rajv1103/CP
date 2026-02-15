#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> mat;
vector<vector<bool>> visited;
vector<vector<pair<int,int>>> parent; // store parent coordinates
vector<vector<char>> moveFrom;        // store move direction

// Directions: L, R, U, D
vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
vector<char> cdir = {'L','R','U','D'};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] != '#' && !visited[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    mat.resize(n);
    for (int i = 0; i < n; i++) cin >> mat[i];

    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int,int>>(m, {-1,-1}));
    moveFrom.assign(n, vector<char>(m, 0));

    int si=-1, sj=-1, ei=-1, ej=-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'A') {
                si = i; sj = j;
            }
            if (mat[i][j] == 'B') {
                ei = i; ej = j;
            }
        }
    }

    // BFS
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj] = true;

    bool found = false;

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        if (x == ei && y == ej) {
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k].first;
            int ny = y + dir[k].second;

            if (valid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x,y};
                moveFrom[nx][ny] = cdir[k];
                q.push({nx,ny});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct path
    string path;
    int x = ei, y = ej;
    while (!(x == si && y == sj)) {
        char move = moveFrom[x][y];
        path.push_back(move);
        auto [px,py] = parent[x][y];
        x = px; y = py;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}
