/*
Problem Name: Fall Down
Link to problem: https://codeforces.com/contest/1669/problem/G
*/

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

void dfs(vector<vector<char>>& grid) {
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
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        dfs(grid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
}