/*
Problem Name: Palindromex
Link to problem: https://codeforces.com/contest/2227/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, vals, blockcnt, ans, B, num, b, start, finish, start2, finish2, smallest; cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n; vals = n + 1, B = 450, blockcnt = (vals + B - 1)/B, ans = 0;
        vector<int> palin(2 * n), last(vals, -1), blockmin(blockcnt, -1);
        vector<vector<int>> queries(2 * n);
        for (int j = 0; j < 2 * n; j++) cin >> palin[j];
        for (int c = 0; c < 2 * n; c++){
            int l = c, r = c;
            while ((l - 1 >= 0) && (r + 1 < 2 * n) && (palin[l - 1] == palin[r + 1])){
                l--; r++;
            }
            queries[r].push_back(l);
        }
        for (int c = 1; c < 2 * n; c++){
            int l = c, r = c - 1;
            while ((l - 1 >= 0) && (r + 1 < 2 * n) && (palin[l - 1] == palin[r + 1])){
                l--; r++;
            }
            if (l <= r) queries[r].push_back(l);
        }
        for (int r = 0; r < 2 * n; r++){
            num = palin[r], b = num / B, start = b * B, finish = min(vals, start + B), smallest = 1000000000; last[num] = r;
            for (int j = start; j < finish; j++) smallest = min(smallest, last[j]);
            blockmin[b] = smallest;
            for (int j = 0; j < queries[r].size(); j++){
                int l = queries[r][j], mex = -1;
                for (int b2 = 0; b2 < blockcnt; b2++){
                    if (blockmin[b2] < l){
                        start2 = b2 * B, finish2 = min(vals, start2 + B);
                        for (int x = start2; x < finish2; x++){
                            if (last[x] < l){
                                mex = x; break;
                            }
                        }
                    }
                    if (mex != -1) break;
                }
                ans = max(ans, mex);
            }
        }
        cout << ans << endl;
    }
}