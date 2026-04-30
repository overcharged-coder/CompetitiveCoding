/*
Problem Name: 
Link to problem: 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, best; long long tot, unmoved, basemoved; cin >> t;
    for (int i = 0; i < t; i++){
        tot = 0, unmoved = 0; best = 0; cin >> n; vector<int> blocks(n), suf(n), freq(n + 1, 0);
        for (int j = 0; j < n; j++){
            cin >> blocks[j]; tot += blocks[j];
        }
        suf[n - 1] = blocks[n - 1];
        for (int j = n - 2; j >= 0; j--) suf[j] = min(blocks[j], suf[j + 1]);
        for (int j = 0; j < suf.size(); j++) unmoved += suf[j];
        basemoved = tot - unmoved;
        for (int j = 0; j < n; j++){
            freq[suf[j]]++;
            best = max(best, freq[blocks[j]]);
        }
        cout << basemoved + max(0, best - 1) << endl;
    }
}