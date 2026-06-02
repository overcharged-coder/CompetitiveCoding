/*
Problem Name: 
Link to problem: 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, a = 0, b = 0; long long curTime = 0; cin >> n >> t; vector<int> books(n);
    for (int i = 0; i < n; i++) cin >> books[i];
    for (a = 0; a < n; a++){
        if (curTime + books[a] < t) curTime += books[a];
        else{
            if (a == n - 1) continue;
            if (books[a + 1] - books[b + 1] < 0) b++;
            else break;
        }
    }
    cout << (a - b) + 1;
}   