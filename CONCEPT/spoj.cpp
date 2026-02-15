#include <bits/stdc++.h>
using namespace std;

int level[8][8];
bool visited[8][8];

vector<pair<int, int>> dir = {
    {1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

// Check if position is inside the board
bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < 8 && j < 8;
}

// Convert chess column character to 0-indexed x
int getX(string s)
{
    return s[0] - 'a';
}

// Convert chess row character to 0-indexed y
int getY(string s)
{
    return s[1] - '1';
}

// BFS to find minimum knight moves
int bfs(int srx, int sry, int dsx, int dsy)
{
    memset(level, 0, sizeof(level));
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({srx, sry});
    visited[srx][sry] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();

        for (auto move : dir)
        {
            int dx = move.first;
            int dy = move.second;
            int nx = x + dx, ny = y + dy;
            if (!isValid(nx, ny) || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            level[nx][ny] = level[x][y] + 1;
            q.push({nx, ny});

            if (nx == dsx && ny == dsy)
                return level[nx][ny]; // Found target
        }
    }

    return level[dsx][dsy]; // In case target was starting point
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int x1 = getX(s1), y1 = getY(s1);
        int x2 = getX(s2), y2 = getY(s2);

        cout << "Min knight moves from " << s1 << " to " << s2 << ": ";
        cout << bfs(x1, y1, x2, y2) << endl;
    }
    return 0;
}