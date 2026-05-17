/*
Problem Name: Arranging The Sheep
Link to problem: https://codeforces.com/contest/1520/problem/E
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n; string sheepGame; cin >> t;
    for (int i = 0; i < t; i++){
        int numSheep, midSheep; long long moves = 0; cin >> n >> sheepGame; vector<int> sheepPos;
        for (int j = 0; j < sheepGame.size(); j++){
            if (sheepGame[j] == '*') sheepPos.push_back(j);
        }
        numSheep = sheepPos.size(); midSheep = numSheep/2;
        if (numSheep == 0 || numSheep == 1){
            cout << 0 << endl; continue;
        }
        for (int j = 0; j < numSheep; j++) moves += abs(sheepPos[j] - (sheepPos[midSheep] - midSheep + j));
        cout << moves << endl;
    }
}