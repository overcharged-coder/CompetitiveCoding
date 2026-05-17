/*
Problem Name: Exams
Link to problem: https://codeforces.com/problemset/problem/479/C
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, prev = INT_MIN; cin >> n; vector<pair<int, int>> examdates(n);
    for (int i = 0; i < n; i++){
        cin >> examdates[i].first >> examdates[i].second;
    }
    sort(examdates.begin(), examdates.end());
    for (int i = 0; i < n; i++){
        if (examdates[i].second >= prev) prev = examdates[i].second;
        else prev = examdates[i].first;
    }
    cout << prev;
}