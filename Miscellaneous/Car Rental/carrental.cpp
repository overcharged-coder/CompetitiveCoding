/*
Problem Name: Car Rental
Link to problem: 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cars = 1; cin >> n; vector<pair<int, int>> cartimes(n); vector<tuple<int, int, int>> merged; 
    for (int i = 0; i < n; i++) cin >> cartimes[i].first >> cartimes[i].second;
    sort(cartimes.begin(), cartimes.end());
    for (int i = 0; i < n; i++){
        if (merged.empty() || cartimes[i].first >= get<1>(merged[merged.size() - 1])) merged.push_back({cartimes[i].first, cartimes[i].second, 0});
        else{
            get<1>(merged[merged.size() - 1]) = max(get<1>(merged[merged.size() - 1]), cartimes[i].second);
            get<2>(merged[merged.size() - 1])++;
        }
    }
    for (int i = 0; i < merged.size(); i++) cars += get<2>(merged[i]);
    cout << cars;
}