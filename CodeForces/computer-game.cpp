#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& cells, int i, int j, vector<vector<bool>>& visited, bool &level_possible) {
    if (i < 0 || i >= cells.size() || j < 0 || j >= cells[0].size()) return;
    if (visited[i][j]) return;
    if ((cells[i][j] == 1)) return;
    if (i == 0 && (j == (cells[0].size() - 1))) level_possible = true;
    visited[i][j] = true;
    dfs(cells, i + 1, j, visited, level_possible);
    dfs(cells, i - 1, j, visited, level_possible);
    dfs(cells, i, j + 1, visited, level_possible);
    dfs(cells, i, j - 1, visited, level_possible);
    dfs(cells, i + 1, j + 1, visited, level_possible);
    dfs(cells, i + 1, j - 1, visited, level_possible);
    dfs(cells, i - 1, j - 1, visited, level_possible);
    dfs(cells, i - 1, j + 1, visited, level_possible);
}


int main() {
    int t, n; cin >> t;
    string row;
    bool level_possible;
    for (int i = 0; i < t; i++){
        level_possible = false; cin >> n;
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        vector<vector<int>> cells(2, vector<int>(n));
        cin >> row;
        for (int j = 0; j < n; j++){
            cells[0][j] = row[j] - '0';
        }
        cin >> row;
        for (int j = 0; j < n; j++){
            cells[1][j] = row[j] - '0';
        }
        if (cells[1][0] == 1) cells[1][0] = 0;
        if (cells[0][n - 1] == 1) cells[0][n - 1] = 0;
        dfs(cells, 1, 0, visited, level_possible);
        if (level_possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}