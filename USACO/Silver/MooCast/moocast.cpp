/*
Problem Name: Moocast
Link to problem: https://usaco.org/index.php?page=viewproblem2&cpid=668
*/

#include <bits/stdc++.h>
using namespace std;

void cow_broadcaster(int& cur, int& curbroadcaster, vector<vector<int>>& adj, vector<bool>& visited){
    cur++; visited[curbroadcaster] = true;
    for (int j = 0; j < adj[curbroadcaster].size(); j++){
        if (!visited[adj[curbroadcaster][j]]) cow_broadcaster(cur, adj[curbroadcaster][j], adj, visited);
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n, maxbroadcaster = INT_MIN, dx, dy, range, cur, cur_visited = 0; cin >> n; vector<tuple<int, int, int>> cowinfo(n); vector<vector<int>> adj(n); vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) cin >> get<0>(cowinfo[i]) >> get<1>(cowinfo[i]) >> get<2>(cowinfo[i]);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dx = abs(get<0>(cowinfo[j]) - get<0>(cowinfo[i])); dy = abs(get<1>(cowinfo[j]) - get<1>(cowinfo[i])); range = get<2>(cowinfo[i]);
            if (range >= sqrt((dx * dx) + (dy * dy))){
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++){
        fill(visited.begin(), visited.end(), false);
        cur = 0; cow_broadcaster(cur, i, adj, visited);
        maxbroadcaster = max(maxbroadcaster, cur);
    }
    cout << maxbroadcaster;
}