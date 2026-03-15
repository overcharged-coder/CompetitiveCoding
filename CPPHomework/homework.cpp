#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>& grid, int i, int j, int k, vector<vector<bool>>& visited, int cur) {
    // check if out of bounds, visited, or not the same island type
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
    if (visited[i][j]) return 0;
    if (grid[i][j] != cur) return 0;
    // set size to 1 for the current cell and mark as visited
    int size = 1;
    visited[i][j] = true;
    // use DFS to explore the four directions and accumulate the size of the island
    size += dfs(grid, i + 1, j, k, visited, cur);
    size += dfs(grid, i - 1, j, k, visited, cur);
    size += dfs(grid, i, j + 1, k, visited, cur);
    size += dfs(grid, i, j - 1, k, visited, cur);
    // return the size of the island type to main
    return size;
}

int main() {
    int n, m, k, cur, size; cin >> n >> m >> k;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> islands(k, 0);
    vector<int> largest_island(k, 0);
    vector<vector<int>> grid(n, vector<int>(m));
    // input grid
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // check if visited
            if (visited[i][j]) continue;
            // set the current island type
            cur = grid[i][j];
            // increment the island count for this type
            islands[cur]++;
            // perform DFS to find the size of this island
            size = dfs(grid, i, j, k, visited, cur);
            // store the largest island size for this type
            largest_island[cur] = max(largest_island[cur], size);
        }
    }
    for (int i = 0; i < k; i++){
        // print k lines with the number of islands and the size of the largest island for each type
        cout << islands[i] << " " << largest_island[i] << endl;
    }
}