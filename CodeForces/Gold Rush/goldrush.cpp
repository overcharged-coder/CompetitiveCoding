/*
Problem Name: Gold Rush
Link to problem: https://codeforces.com/contest/1829/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int n, int m, bool& gold_found){
    if (gold_found) return;
    if (n == m) {
        gold_found = true;
        return;
    }
    if ((n % 3) != 0) return;
    if (n < m) return;
    dfs(n / 3, m, gold_found);
    dfs((2 * n) / 3, m, gold_found);
}

int main() {
    int t, n, m; cin >> t;
    bool gold_found = false;
    for (int i = 0; i < t; i++){
        gold_found = false;
        cin >> n >> m;
        dfs(n, m, gold_found);
        if (gold_found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}