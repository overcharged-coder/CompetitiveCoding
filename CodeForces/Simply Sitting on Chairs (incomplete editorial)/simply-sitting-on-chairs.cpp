/*
Problem Name: Simply Sitting on Chairs
Link to problem: https://codeforces.com/contest/2210/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, max_chairs, safe; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        vector<int> chairs(n + 1), pos(n + 1);
        for (int j = 1; j <= n; j++) {
            cin >> chairs[j];
            pos[chairs[j]] = j;
        }
        max_chairs = 0; safe = 0;
        for (int k = 1; k <= n; k++) {
            if (pos[k] < k) {
                max_chairs = max(max_chairs, safe);
            }
            safe++;
            if (pos[k] < k) {
                safe--;
            }
        }
        max_chairs = max(max_chairs, safe);
        cout << max_chairs << endl;
    }
}