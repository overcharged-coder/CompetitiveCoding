/*
Problem Name: Books
Link to problem: https://codeforces.com/problemset/problem/279/B
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, j = 0, maxBooks = INT_MIN; long long curTime = 0; cin >> n >> t; vector<int> books(n);
    for (int i = 0; i < n; i++) cin >> books[i];
    for (int i = 0; i < n; i++){
        curTime += books[i];
        while (curTime > t){
            curTime -= books[j]; j++;
        }
        maxBooks = max(maxBooks, (i - j) + 1);
    }
    cout << maxBooks;
}   