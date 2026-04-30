/*
Problem Name: Party Monster
Link to problem: https://codeforces.com/contest/2227/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, l_br, r_br; string s; cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n >> s; l_br = 0; r_br = 0;
        for (int j = 0; j < n; j++){
            if (s[j] == '(') l_br++;
            else r_br++;
        }
        if (l_br == r_br) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}