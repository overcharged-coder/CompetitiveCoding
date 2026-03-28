/*
Problem Name: DZY Loves Chessboard
Link to problem: https://codeforces.com/problemset/problem/445/A
*/

#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int sr, int sc, vector<string>& grid, vector<string>& ans, vector<vector<bool>>& visited, int n, int m) {
    int nr, nc, r, c;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    ans[sr][sc] = 'B';

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        
        for (int k = 0; k < 4; k++) {
            nr = r + dr[k];
            nc = c + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] != '.' || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            if (ans[r][c] == 'B') {
                ans[nr][nc] = 'W';
            } else {
                ans[nr][nc] = 'B';
            }
            q.push({nr, nc});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<string> ans = grid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j, grid, ans, visited, n, m);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}