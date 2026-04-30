/*
Problem Name: Snowfall
Link to problem: https://codeforces.com/contest/2227/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, num; cin >> t;
    for (int i = 0; i < t; i++){
        vector<int> div6, div2, div3, ndiv, snowf; cin >> n;
        for (int j = 0; j < n; j++){
            cin >> num;
            if (num % 6 == 0) div6.push_back(num);
            else if (num % 2 == 0) div2.push_back(num);
            else if (num % 3 == 0) div3.push_back(num);
            else ndiv.push_back(num);
        }
        for (int j = 0; j < div6.size(); j++) snowf.push_back(div6[j]);
        for (int j = 0; j < div2.size(); j++) snowf.push_back(div2[j]);
        for (int j = 0; j < ndiv.size(); j++) snowf.push_back(ndiv[j]);
        for (int j = 0; j < div3.size(); j++) snowf.push_back(div3[j]);
        for (int j = 0; j < n; j++) {
            if (j == n - 1) cout << snowf[j];
            else cout << snowf[j] << " ";
        }
        cout << endl;
    }
}