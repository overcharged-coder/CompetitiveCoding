/*
Problem Name: Cake Leveling
Link to problem: https://codeforces.com/problemset/problem/2232/B
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long sum, ans, cur; int t, n; cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n; sum = 0, ans = LLONG_MAX; vector<long long> cake(n);
        for (int j = 0; j < n; j++) cin >> cake[j];
        for (int j = 0; j < n; j++){
            sum += cake[j];
            cur = sum/(j + 1);
            ans = min(ans, cur);
            cout << ans << " ";
        }
        cout << endl;
    }
}