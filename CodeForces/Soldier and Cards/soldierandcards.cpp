/*
Problem Name: Soldier and Cards
Link to problem: https://codeforces.com/problemset/problem/546/C
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c1, c2, cnt = 0, winner, card; cin >> n; 
    bool fightend = false;
    cin >> c1; queue<int> firstcards;
    for (int i = 0; i < c1; i++){
        cin >> card; firstcards.push(card);
    }
    cin >> c2; queue<int> secondcards;
    for (int i = 0; i < c2; i++){
        cin >> card; secondcards.push(card);
    }
    while (!fightend && cnt < 10000){
        if (firstcards.size() == 0){
            fightend = true; winner = 2;
            continue;
        }
        if (secondcards.size() == 0){
            fightend = true; winner = 1;
            continue;
        }
        if (firstcards.front() > secondcards.front()){
            card = firstcards.front(); firstcards.push(secondcards.front()); firstcards.push(card);
            firstcards.pop(); secondcards.pop();
        }
        else{
            card = secondcards.front(); secondcards.push(firstcards.front()); secondcards.push(card);
            secondcards.pop(), firstcards.pop();
        }
        cnt++;
    }
    if (fightend) cout << cnt << " " << winner;
    else cout << -1;
}