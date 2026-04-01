#include <bits/stdc++.h>
using namespace std;
// using prim's algorithm minimum spanning tree

int main() {
    int n, m, source, target, cost, start, tweight = 0; cin >> n >> m;
    // adjacency list to store the graph
    vector<vector<pair<int, int>>> adjacency_list(n + 1);
    for (int i = 0; i < m; i++){
        cin >> source >> target >> cost;
        adjacency_list[source].push_back({target, cost});
    }
    cin >> start;
    // boolean vector to store whether or not we have arrived at a node in the mst before
    vector<bool> mst(n + 1, false);
    // priority queue to store the edges in the mst, sorted by weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mst_queue;
    // push the node we start from
    mst_queue.push({0, start});
    while (!mst_queue.empty()) {
        // assign weight to the weight of the edge and node to the node we are currently at 
        auto [weight, node] = mst_queue.top();
        // remove the top entry from the queue so we can process the next one
        mst_queue.pop();
        // check if node has already been visited (for extra safety though not necessary)
        if (mst[node]) continue;
        // if not, mark it as visited and add the weight to the total weight
        mst[node] = true;
        tweight += weight;
        for (int i = 0; i < adjacency_list[node].size(); i++) {
            // assign neighbor to the neighboring node and edge weight to the weight of the edge connecting them
            auto [neighbor, edge_weight] = adjacency_list[node][i];
            // if the neighbor has not been visited, add it to the priority queue with its edge weight
            if (!mst[neighbor]) {
                mst_queue.push({edge_weight, neighbor});
            }
        }
    }
    cout << tweight << endl;
}
