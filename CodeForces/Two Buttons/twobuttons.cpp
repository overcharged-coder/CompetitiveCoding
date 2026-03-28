/*
Problem Name: Two Buttons
Link to problem: https://codeforces.com/problemset/problem/520/B
*/

#include <bits/stdc++.h>
using namespace std;

void button_press(int n, int m, int cnt) {
    if (m < 0) return;
    if (m == n) {
        cout << cnt << endl;
        exit(0);
    }
    if (m < n || m % 2 != 0) {
        button_press(n, m + 1, cnt + 1);
    } else {
        button_press(n, m / 2, cnt + 1);
    }
}

int main() {
    int n, m, cnt = 0; cin >> n >> m;
    button_press(n, m, cnt);
}