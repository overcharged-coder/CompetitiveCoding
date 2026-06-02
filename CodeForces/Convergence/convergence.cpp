/*
Problem Name: Convergence
Link to problem: https://codeforces.com/problemset/problem/2232/A
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, left, right, cur, n, ans, k; cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n; ans = n; vector<long long> alice(n);
        for (int j = 0; j < n; j++) cin >> alice[j];
        sort(alice.begin(), alice.end());
        for (int j = 0; j < n; j++) {
            for (k = j; k < n; k++) {
                if (alice[k] != alice[j]) break;
            }
            left = j; right = n - k;
            cur = max(left, right); ans = min(ans, cur);
            j = k - 1;
        }
        cout << ans << endl;
    }
}