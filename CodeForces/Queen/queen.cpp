#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool hate;
    vector<pair<int, int>> parent_hate(n + 1);
    vector<vector<int>> children(n + 1);
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        cin >> parent_hate[i].first >> parent_hate[i].second;
        if (parent_hate[i].first == -1) continue;
        else children[parent_hate[i].first].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (parent_hate[i].second == 0) continue;
        hate = true;
        for (int j = 0; j < children[i].size(); j++) {
            if (parent_hate[children[i][j]].second == 0) {
                hate = false;
                break;
            }
        }
        if (hate) result.push_back(i);
    }

    if (result.size() == 0) cout << -1;
    else {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    }
}