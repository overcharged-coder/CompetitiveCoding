
//USACO 2022 US Open Contest, Bronze
//Problem 2. Counting Liars
//Google Slide : https://docs.google.com/presentation/d/1TLXCWyumJMxanEzPAYBTDJK_3kHq0qEipQG_m_Y1csY/edit#slide=id.g33c249e91d0_0_21
//USACO Link: https://usaco.org/index.php?page=viewproblem2&cpid=1228
//USACO Guide Link : https://usaco.guide/bronze/intro-complete?lang=cpp

#include <bits/stdc++.h>
using namespace std;

/*
Function : isTellingTruth
This function evaluates if a cow is telling the truth
assuming that Bessie is at a perticular position.
*/
bool isTellingTruth ( int bessieIsAt,
                      char L_or_G,
                      int prediction)
{
    bool isTellingTruth = false;
    switch (L_or_G) {
    case 'G':
        if ( bessieIsAt >= prediction){
            isTellingTruth = true;
        }
        break;
    case 'L':
        if ( bessieIsAt <= prediction){
            isTellingTruth = true;
        }
        break;
    default:
        // do nothing 
        break;
    }
    return isTellingTruth;
};
int main() {
	
    int num_inputs = 0;
    int min_liars = 0;

    cin >> num_inputs;

    //Consider that all are liers
    min_liars = num_inputs;

    vector<pair<int, char>> cow_positions(num_inputs);

    for (int i=0;i<num_inputs;i++)
    {
        cin >> cow_positions[i].second >> cow_positions[i].first;
    }

    //Now considering that Bessie is in a perticular
    //location find the number of liars.
    //The answer will be minimum of liars calculated
    //for each of the positions.

    for (int i=0;i<num_inputs;i++)
    {
        int bessie_at = cow_positions[i].first;
        int num_of_liars = 0;
        for (int j=0;j<num_inputs;j++)
        {
            //Check if if the cow is telling the truth
            if (false ==  isTellingTruth(bessie_at,
                            cow_positions[j].second,
                            cow_positions[j].first) 
                            )
            {
                num_of_liars ++;
            }
        }
        min_liars = min(min_liars,num_of_liars);
    }

    cout << min_liars << endl;
}
