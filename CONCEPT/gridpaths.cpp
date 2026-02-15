#include <bits/stdc++.h>
using namespace std;

unordered_map<char, pair<int, int>> dir = {
    {'L', {-1, 0}},
    {'R', {1, 0}},
    {'U', {0, -1}},
    {'D', {0, 1}}
};

vector<pair<int, int>> directions = {
    {-1, 0}, 
    {1, 0},  
    {0, -1}, 
    {0, 1}   
};

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < 7 && j < 7; 
}

int fn(int i, int j, int ind, const string &s, vector<vector<bool>> &visited) {
    if (i == 7 && j == 7) return ind == 48 ? 1 : 0; 

    if (visited[i][j]) return 0;
    visited[i][j] =1;
    int res = 0;
    if (s[ind] == '?') {
        for (auto d : directions) {
            int x = i + d.first;
            int y = j + d.second;
            if (isValid(x, y) && !visited[x][y]) {
                res += fn(x, y, ind + 1, s, visited);
            }
        }
    } else {
        auto d = dir[s[ind]];
        int x = i + d.first;
        int y = j + d.second;
        if (isValid(x, y) && !visited[x][y]) {
            res += fn(x, y, ind + 1, s, visited);
        }
    }

    visited[i][j] = 0;
    return res;
}

int main() {
    string s;
    cin >> s;

    vector<vector<bool>> visited(8, vector<bool>(8, false));
    cout << fn(0, 0, 0, s, visited) << endl;

    return 0;
}
