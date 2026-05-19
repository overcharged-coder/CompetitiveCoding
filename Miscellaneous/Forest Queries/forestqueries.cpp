/*
Problem Name: Forest Queries
Link to problem: https://cses.fi/problemset/task/1652
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, sum; char land; cin >> n >> q; vector<pair<int, int>> inputs(2); vector<vector<int>> forest(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> land;
            forest[i][j] = (land == '*' ? 1 : 0);
            if (j == 0) continue;
            forest[i][j] += forest[i][j - 1];
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n; j++){
            forest[i][j] += forest[i - 1][j];
        }
    }
    /* First pair is x_low and y_low (top left), and second pair is x_high and y_high (bottom right)
       Subtract x_low - 2, y_high - 1
       Then, subtract x_high - 1, y_low - 2
       Add back x_low - 2, y_low - 2
    */
    for (int i = 0; i < q; i++){
        sum = 0;
        cin >> inputs[0].first >> inputs[0].second >> inputs[1].first >> inputs[1].second;
        inputs[0].first--, inputs[0].second--, inputs[1].first--, inputs[1].second--;
        sum += forest[inputs[1].first][inputs[1].second];
        if (inputs[0].first > 0) sum -= forest[inputs[0].first - 1][inputs[1].second];
        if (inputs[0].second > 0) sum -= forest[inputs[1].first][inputs[0].second - 1];
        if (inputs[0].first > 0 && inputs[0].second > 0) sum += forest[inputs[0].first - 1][inputs[0].second - 1];
        cout << sum << endl;
    }
}