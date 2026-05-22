/*
Problem Name: Candy Box
Link to problem: https://codeforces.com/problemset/problem/1183/D
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, n, candy, candycount, prevcandy; cin >> q; 
    for (int i = 0; i < q; i++){
        cin >> n; unordered_map<int, int> group_sizes; candycount = 0; 
        for (int j = 0; j < n; j++){
            cin >> candy; group_sizes[candy]++;
        }
        vector<pair<int, int>> group_sizec(group_sizes.begin(), group_sizes.end());
        sort(group_sizec.begin(), group_sizec.end(), [](const auto& x, const auto& y){return x.second > y.second;});
        for (int j = 0; j < group_sizec.size(); j++){
            if (j == 0){
                prevcandy = group_sizec[j].second; candycount += prevcandy; continue;
            }
            if (prevcandy <= group_sizec[j].second){
                if (prevcandy == 1) break;
                prevcandy--; candycount += prevcandy; continue;
            }
            else{
                prevcandy = group_sizec[j].second; candycount += prevcandy;
            }
        }
        cout << candycount << endl;
    }
}