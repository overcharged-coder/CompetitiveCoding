/*
Problem Name: A Simple Sequence
Link to problem: https://codeforces.com/contest/2210/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n; cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        for (int i = n; i >= 1; i--){
            cout << i << " ";
        }
        cout << endl;
    }
}