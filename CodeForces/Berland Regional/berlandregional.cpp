/*
Problem Name: Berland Regional
Link to problem: https://codeforces.com/contest/1519/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n; cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n; vector<pair<int, int>> coders(n); unordered_map<int, vector<int>> regionals; vector<long long> regans(n + 1); vector<long long> prefreg;
        for (int j = 0; j < n; j++) cin >> coders[j].second;
        for (int j = 0; j < n; j++) cin >> coders[j].first;
        sort(coders.begin(), coders.end(), greater<pair<int, int>>());
        for (int j = 0; j < n; j++) regionals[coders[j].second].push_back(coders[j].first);
        for (auto &students : regionals){
            prefreg.resize(students.second.size() + 1);
            for (int j = 0; j < students.second.size(); j++) prefreg[j + 1] = prefreg[j] + students.second[j];
            for (int k = 1; k <= students.second.size(); k++) regans[k] += prefreg[students.second.size() - (students.second.size() % k)];
        }
        for (int k = 1; k <= n; k++) cout << regans[k] << " ";
        cout << endl;
    }
}