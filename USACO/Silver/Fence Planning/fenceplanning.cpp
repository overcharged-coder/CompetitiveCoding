/*
Problem Name: Fence Planning
Link to problem: https://usaco.org/index.php?page=viewproblem2&cpid=944
*/

#include <bits/stdc++.h>
using namespace std;

void connect_network(vector<bool>& visited, int& cur, vector<vector<int>>& moo_networks, int& id, vector<vector<int>>& adj){
    moo_networks[id].push_back(cur);
    visited[cur] = true;
    for (int j = 0; j < adj[cur].size(); j++){
        if (!visited[adj[cur][j]]) connect_network(visited, adj[cur][j], moo_networks, id, adj);
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m, id = 0, maxy, miny, maxx, minx, min_peri = INT_MAX; cin >> n >> m;
    vector<pair<int, int>> cows(n); vector<pair<int, int>> connections(m); vector<vector<int>> moo_networks; vector<int> cow(n); vector<bool> visited(n, false); 
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;
    for (int i = 0; i < m; i++){
        cin >> connections[i].first >> connections[i].second;
        connections[i].first--, connections[i].second--;
    }
    for (int i = 0; i < m; i++){
        adj[connections[i].first].push_back(connections[i].second); adj[connections[i].second].push_back(connections[i].first);
    }
    for (int i = 0; i < n; i++) cow[i] = i;
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        moo_networks.push_back(vector<int>());
        connect_network(visited, i, moo_networks, id, adj);
        id++;
    }
    for (int i = 0; i < moo_networks.size(); i++){
        miny = INT_MAX, maxy = INT_MIN, minx = INT_MAX, maxx = INT_MIN;
        for (int j = 0; j < moo_networks[i].size(); j++){
            if (cows[moo_networks[i][j]].second < miny) miny = cows[moo_networks[i][j]].second;
            if (cows[moo_networks[i][j]].second > maxy) maxy = cows[moo_networks[i][j]].second;
            if (cows[moo_networks[i][j]].first < minx) minx = cows[moo_networks[i][j]].first;
            if (cows[moo_networks[i][j]].first > maxx) maxx = cows[moo_networks[i][j]].first;
        }
        min_peri = min((2 * (maxy - miny)) + (2 * (maxx - minx)), min_peri);
    }
    cout << min_peri;
}