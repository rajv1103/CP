// use where form different nodes we have to visit a node for min time toh saare sources ko ekk saath queue mein insert kar denge

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e6 + 10;

int n, m;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs(vector<vector<int>> &g, vector<vector<int>> &dist, vector<vector<bool>> &vis)
{
    int maxi = INT_MIN;

    // Find the maximum value in the grid
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            maxi = max(maxi, g[i][j]);

    queue<pair<int, int>> q;

    // Enqueue all cells having the maximum value
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == maxi)
            {
                q.push({i, j});
                dist[i][j] = 0;
                vis[i][j] = true;
            }

    // Perform multi-source BFS
    while (!q.empty())
    {
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();

        for (auto mov : dir)
        {
            int nx = dx + mov.first;
            int ny = dy + mov.second;
            if (!isValid(nx, ny) || vis[nx][ny])
                continue;

            vis[nx][ny] = true;
            dist[nx][ny] = dist[dx][dy] + 1;
            q.push({nx, ny});
        }
    }

    // Find the farthest cell's distance
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, dist[i][j]);

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> g(n, vector<int>(m));
        vector<vector<int>> dist(n, vector<int>(m, INF));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << bfs(g, dist, vis) << endl;
    }
    return 0;
}
