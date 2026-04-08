/*
Problem Name: Divide by three, multiply by two
Link to problem: https://codeforces.com/problemset/problem/977/D
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, potential; long long number; cin >> n; vector<pair<int, long long>> number_potential(n);
    for (int i = 0; i < n; i++){
        potential = 0; cin >> number_potential[i].second; number = number_potential[i].second;
        while ((number % 3) == 0){
            potential++;
            number /= 3;
        }
        number_potential[i].first = potential;
    }

    sort(number_potential.begin(), number_potential.end(), [](const pair<int, long long>& firstpair, const pair<int, long long>& secondpair) {
        if (firstpair.first != secondpair.first) return firstpair.first > secondpair.first;
        return firstpair.second < secondpair.second;
    });

    for (int i = 0; i < number_potential.size(); i++){
        if (i != (number_potential.size() - 1)) cout << number_potential[i].second << " ";
        else cout << number_potential[i].second;
    }
}