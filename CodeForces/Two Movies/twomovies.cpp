/*
Problem Name: Two Movies
Link to problem: https://codeforces.com/contest/1989/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, firstr, secondr, bothpos, bothneg; cin >> t;
    for (int i = 0; i < t; i++){
        firstr = 0, secondr = 0; bothpos = 0, bothneg = 0; cin >> n; vector<int> movie1(n), movie2(n);
        for (int j = 0; j < n; j++) cin >> movie1[j];
        for (int j = 0; j < n; j++) cin >> movie2[j];
        for (int j = 0; j < n; j++) {
            if (movie1[j] > movie2[j]) {
                firstr += movie1[j];
            }
            else if (movie2[j] > movie1[j]) {
                secondr += movie2[j];
            }
            else {
                if (movie1[j] == 1) bothpos++;
                else if (movie1[j] == -1) bothneg++;
            }
        }
        while (bothpos--) {
            if (firstr < secondr) firstr++;
            else secondr++;
        }
        while (bothneg--) {
            if (firstr > secondr) firstr--;
            else secondr--;
        }
        cout << min(firstr, secondr) << endl;
    }
}