#include <bits/stdc++.h>
using namespace std;

void djikstra(int n, vector<vector<pair<int, int>>>& adjacency_list, int source, vector<long long>& distance) {
    // priority queue to store the nodes to explore, ordered by their current distance from the source
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dji_queue;
    // push the source node with distance 0 into the priority queue and set its distance to 0
    dji_queue.push({0, source});
    distance[source] = 0;
    while (!dji_queue.empty()) {
        // set dist to the current distance and node to the current node from the top of the priority queue
        auto [dist, node] = dji_queue.top();
        // remove the current node from the priority queue so we can explore its neighbors
        dji_queue.pop();
        // we can skip processing this node if we have already found a shorter path to it by checking it's current value in the distance vector
        if (dist > distance[node]) continue;
        for (int i = 0; i < adjacency_list[node].size(); i++) {
            // initialize neighbor and weight to the neighbor node and edge weight from the adjacency list
            auto [neighbor, weight] = adjacency_list[node][i];
            // check if the path to the current neighbor is shorter than the previously known path
            if (distance[node] + weight < distance[neighbor]) {
                distance[neighbor] = distance[node] + weight;
                // push the current neighbor if it's shorter with the updated parameters
                dji_queue.push({distance[neighbor], neighbor});
            }
        }
    }
}

int main() {
    int n, m, source, target, cost, start, end; cin >> n >> m;
    // adjacency list to store the graph, where each node has a list of pairs (neighbor, cost)
    vector<vector<pair<int, int>>> adjacency_list(n + 1);
    for (int i = 0; i < m; i++){
        cin >> source >> target >> cost;
        adjacency_list[source].push_back({target, cost});
    }
    cin >> start >> end;
    // distance vector to store the shortest distance from the source to each node, initialized to the max long long value
    vector<long long> distance(n + 1, LLONG_MAX);
    djikstra(n, adjacency_list, start, distance);
    if (distance[end] == LLONG_MAX) cout << -1 << endl;
    else cout << distance[end] << endl;
}
