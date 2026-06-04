/*
Problem Name: 
Link to problem: 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int openBrack = 0, ans = 0; string regBrack; cin >> regBrack;
    for (int i = 0; i < regBrack.size(); i++){
        if (regBrack[i] == '(') openBrack++;
        else{
            if (openBrack > 0){
                openBrack--; ans += 2;
            }
        }
    }
    cout << ans;
}