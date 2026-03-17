// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int minCoinsToBuy (int LN,int C0,int C1,int CH,string S) {

    int minCoinstoBuy;

    int curCostOfString = int(
        (std::count(S.begin(), S.end(), '0')*C0) + 
        (std::count(S.begin(), S.end(), '1')*C1)
    );    

    int minCoin = min(C0,C1);
    int minCost = LN*minCoin;


    minCoinstoBuy =  curCostOfString;

    if ( minCost < curCostOfString )
    {

        if ( C0 > C1)
        {
            if (abs(C0-C1)-CH > 0) {
               minCoinstoBuy =  (std::count(S.begin(), S.end(), '0')*CH)+
                                (LN*C1);
            }
        }
        else
        {
            if (abs(C0-C1)-CH > 0) {
               minCoinstoBuy =  (std::count(S.begin(), S.end(), '1')*CH)+
                                (LN*C0);
            }
        }
    }

    return minCoinstoBuy;
}
int main() {

    string S;
    int num_of_test_cases = 0;
	int LN,C0,C1,CH; 


    cin >> num_of_test_cases;

    for (int ictr=1;ictr<=num_of_test_cases;ictr++) {
        cin >> LN >> C0 >> C1 >> CH;
	    cin >> S;
        cout << minCoinsToBuy(LN,C0,C1,CH,S) << endl;
    }
}
