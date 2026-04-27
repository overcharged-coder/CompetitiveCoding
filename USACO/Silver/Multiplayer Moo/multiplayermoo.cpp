/*
Problem Name: Multiplayer Moo
Linn to problem: https://usaco.org/index.php?page=viewproblem2&cpid=836
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    int n, next_id = 0, cur, sizes, region = 0, best = 0, nextrow, nextcol, up, least, great, color1, color2, best2 = 0, stamp = 0, total = 0; cin >> n;
    vector<vector<int>> moo(n, vector<int>(n)); vector<vector<int>> regions(n, vector<int>(n, -1)); vector<int> size; vector<int> color; 
    unordered_map<int, int> reorder; set<pair<int, int>> visited; map<pair<int, int>, vector<int>> pair_starts;
    int directionx[4] = {1, -1, 0, 0};
    int directiony[4] = {0, 0, 1, -1};
    // make all the ids of the cows to be in counting order from 0 to make acessing elements easier
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> moo[i][j];
            if (!reorder.count(moo[i][j])) reorder[moo[i][j]] = next_id++;
            moo[i][j] = reorder[moo[i][j]];
        }
    }
    // find the regions of cows with the same id and their sizes and colors
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (regions[i][j] != -1) continue;
            cur = moo[i][j]; sizes = 0;
            queue<pair<int, int>> processor; processor.push({i, j});
            regions[i][j] = region;
            while (!processor.empty()){
                auto [row, col] = processor.front();
                processor.pop();
                sizes++;
                for (int d = 0; d < 4; d++){
                    nextrow = row + directionx[d]; nextcol = col + directiony[d];
                    if (nextrow < 0 || nextrow >= n || nextcol < 0 || nextcol >= n) continue;
                    if (regions[nextrow][nextcol] != -1) continue;
                    if (moo[nextrow][nextcol] != cur) continue;                           
                    regions[nextrow][nextcol] = region;
                    processor.push({nextrow, nextcol});
                }
            }
            color.push_back(cur);
            size.push_back(sizes);
            best = max(best, sizes);
            region++;
        }
    }
    // make the adjacency list for the regions
    vector<vector<int>> adj(region);                         
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i + 1 < n){
                cur = regions[i][j]; up = regions[i + 1][j];
                if (cur != up){
                    least = min(cur, up); great = max(cur, up);
                    if (!visited.count({least, great})){
                        visited.insert({least, great});
                        adj[cur].push_back(up); adj[up].push_back(cur);
                    }
                    color1 = color[cur]; color2 = color[up];
                    if (color1 > color2) swap(color1, color2);
                    pair_starts[{color1, color2}].push_back(cur);
                    pair_starts[{color1, color2}].push_back(up);
                }
            }
            if (j + 1 < n){
                cur = regions[i][j]; up = regions[i][j + 1];
                if (cur != up){
                    least = min(cur, up); great = max(cur, up);
                    if (!visited.count({least, great})){
                        visited.insert({least, great});
                        adj[cur].push_back(up); adj[up].push_back(cur);
                    }
                    color1 = color[cur]; color2 = color[up];
                    if (color1 > color2) swap(color1, color2);
                    pair_starts[{color1, color2}].push_back(cur);
                    pair_starts[{color1, color2}].push_back(up);
                }
            }
        }
    }
    // for each pair of colors, find the largest connected component of regions with those colors
    vector<int> seen(region, 0);
    for (auto& pair : pair_starts){
        stamp++;
        color1 = pair.first.first; color2 = pair.first.second;
        for (int start : pair.second){
            if (seen[start] == stamp) continue;
            total = 0; seen[start] = stamp;
            queue<int> process; process.push(start);
            while (!process.empty()){
                cur = process.front();
                process.pop();
                total += size[cur];
                for (int curneighbor : adj[cur]){
                if (seen[curneighbor] == stamp) continue;
                    if (color[curneighbor] != color1 && color[curneighbor] != color2) continue;
                    seen[curneighbor] = stamp;
                    process.push(curneighbor);
                }
            }
            best2 = max(best2, total);
        }
    }
    cout << best << endl << best2;
}