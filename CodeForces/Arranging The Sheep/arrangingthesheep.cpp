/*
Problem Name: Arranging The Sheep
Link to problem: https://codeforces.com/contest/1520/problem/E
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, numSheep, midSheep; long long moves; string sheepGame; cin >> t; vector<int> sheepPos;
    for (int i = 0; i < t; i++){
        cin >> n >> sheepGame; 
        for (int j = 0; j < sheepGame.size(); j++){
            if (sheepGame[j] == '*') sheepPos.push_back(j);
        }
        numSheep = sheepPos.size(); midSheep = numSheep/2;
        if (numSheep == 0 || numSheep == 1){
            cout << 0 << endl; continue;
        }
        for (int j = 0; j < numSheep; j++) moves += abs(sheepPos[j] - (sheepPos[midSheep] - midSheep + j));
        cout << moves << endl;
        sheepPos.clear();
    }
}