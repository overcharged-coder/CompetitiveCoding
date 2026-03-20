#include <bits/stdc++.h>
using namespace std;

bool checker(vector<vector<char>>& grid) {
    bool finished_simulation = true;
    for (int i = 0; i < (grid.size() - 1); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '*' && grid[i + 1][j] == '.') {
                swap(grid[i][j], grid[i + 1][j]);
                finished_simulation = false;
            }
        }
    }
    return finished_simulation;
}

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    while (!checker(grid)) {
        for (int i = 0; i < (grid.size() - 1); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '*' && grid[i + 1][j] == '.') {
                    swap(grid[i][j], grid[i + 1][j]);
                }
            }
        }
    }
}

int main() {
    int t, n, m; cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        dfs(grid, visited, n - 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
}