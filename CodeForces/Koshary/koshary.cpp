/*
Problem Name: Koshary
Link to problem: https://codeforces.com/contest/2227/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x, y; cin >> t;
    bool short_used;
    for (int i = 0; i < t; i++){
        cin >> x >> y; short_used = false;
        if (x % 2 != 0){
            if ((x - 1) % 2 != 0){
                cout << "NO" << endl; continue;
            }
            short_used = true;
        }
        if ((y % 2 != 0)){
            if ((y - 1) % 2 != 0 || short_used == true){
                cout << "NO" << endl; continue;
            }
            short_used = true;
        }
        cout << "YES" << endl;        
    }
}