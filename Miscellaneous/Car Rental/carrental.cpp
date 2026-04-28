/*
Problem Name: Car Rental
Link to problem: 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cars = 0, cars_cur = 0, time; cin >> n; vector<pair<int, bool>> start_finish;
    for (int i = 0; i < n; i++){
        cin >> time; start_finish.push_back({time, true});
        cin >> time; start_finish.push_back({time, false});
    }
    sort(start_finish.begin(), start_finish.end());
    for (int i = 0; i < 2 * n; i++){
        if (start_finish[i].second == true) cars_cur++;
        else if (start_finish[i].second == false) cars_cur--;
        cars = max(cars_cur, cars);
    }
    cout << cars;
}
