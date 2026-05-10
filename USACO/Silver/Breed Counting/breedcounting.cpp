/*
Problem Name: Breed Counting
Link to problem: https://usaco.org/index.php?page=viewproblem2&cpid=572
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin); freopen("bcount.out", "w", stdout);
    int n, q, a, b; cin >> n >> q; vector<int> breeds(n); vector<vector<int>> cows(3, vector<int>(n));
    for (int i = 0; i < n; i++){
        cin >> breeds[i];
        if (i != 0){
            for (int j = 0; j < 3; j++) cows[j][i] = cows[j][i - 1];
            cows[breeds[i] - 1][i]++;
        }
        else cows[breeds[i] - 1][i]++;
    }
    for (int i = 0; i < q; i++){
        cin >> a >> b; a--, b--;
        for (int j = 0; j < 3; j++){
            if (a == 0) cout << cows[j][b];
            else cout << cows[j][b] - cows[j][a - 1];
            if (j < 2) cout << " ";
        }
        if (i != (q - 1)) cout << endl;
    }
}