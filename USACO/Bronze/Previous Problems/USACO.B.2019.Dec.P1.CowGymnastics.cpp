
//USACO 2019 December Contest, Bronze
//Problem 1. Cow Gymnastics
//USACO Link : https://usaco.org/index.php?page=viewproblem2&cpid=963
//USACO Guide Link : https://usaco.guide/groups/d7eYGfddXq3m2trXG2xt/post/HUiqbm1YRSctsEgyrY4e/problems/tVcJPPk4pG2kV60O1lNS
// Google Slides Notes : https://docs.google.com/presentation/d/1ZQ5B28mBRbVLXYapdsW4DYLyMi937RhJV9FDssWDiOQ/edit#slide=id.p

#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

/*
The CowPair class represents a pairing of two cows in a sequence.
cowPair1: Represents the first cow in the sequence.
cowPair2: Represents the second cow in the sequence.
consistentPairCount: Keeps track of how many times this exact 
pairing appears in subsequent sequences.
Overide the == operator to comapre two objects.
*/

struct CowPair {
    int cowPair1, cowPair2;
    int consistentPairCount = 0;

  
    void increamentPairCount() {
        consistentPairCount++;
    }
    
    // Define equality operator for comparison
    bool operator==(const CowPair& other) const {
        bool retComparePair = false;
        if ((cowPair1 == other.cowPair1) && 
                (cowPair2 == other.cowPair2) )
        {
            
            retComparePair = true;
        }
        return retComparePair;
    }
};

int main() {
    
    int num_sessions,num_cows;
    cin >> num_sessions;
    cin >> num_cows;
    
    int cowSessionSeq[20]; 

    vector<string> cowSessions (num_sessions);
    vector<CowPair> cowInitialPairs;
    vector<CowPair> cowCurrentPairs;
  

    //Read the first sequence
    for (int cow=0;cow<num_cows;cow++) {
        cin >> cowSessionSeq[cow];
    }
    
    /*
    for (int cow=0;cow<num_cows;cow++) {
        cout << "cowSessionSeq[" <<cow <<"] = " << cowSessionSeq[cow] << endl;
    }
    */

    //Build pairs for the first sequence.
    //These pairs will be compared to the subsequent sequence pairs.
    for (int cow1=0;cow1<num_cows-1;cow1++) {
 
        for (int cow2=cow1+1;cow2<num_cows;cow2++) {
             cowInitialPairs.push_back({cowSessionSeq[cow1],cowSessionSeq[cow2]});     
        }
    }

    /*
    for ( CowPair cowpair : cowInitialPairs) {
        std::cout << "(" << cowpair.cowPair1 << ", " << cowpair.cowPair2 << ")\n";
    }

    for (size_t i = 0; i < cowInitialPairs.size(); ++i) {
        std::cout << "(" << cowInitialPairs[i].cowPair1 << ", " << cowInitialPairs[i].cowPair2 << ")\n";
    }
    */

    // now read the remaaining sequences
    for (int session=1;session<num_sessions;session++){
        
        // read the requence
        for (int cow=0;cow<num_cows;cow++) {
            cin >> cowSessionSeq[cow];
        }
        
        // for each pair check if the pair from 
        // the first seqeunce matches.
        for (int cow1=0;cow1<num_cows-1;cow1++) {
            for (int cow2=cow1+1;cow2<num_cows;cow2++) {
                CowPair curCoWPair;
                curCoWPair.cowPair1 = cowSessionSeq[cow1];
                curCoWPair.cowPair2 = cowSessionSeq[cow2];
                for ( CowPair& cowinitpair : cowInitialPairs) {
                    if (cowinitpair==curCoWPair){
                        //if the match is found increase the match count
                        cowinitpair.increamentPairCount();
                    }
                }
            }
        }

    }
    /*
    for (size_t i = 0; i < cowInitialPairs.size(); ++i) {
        std::cout << "(" 
                    << cowInitialPairs[i].cowPair1 
                    << ", " 
                    << cowInitialPairs[i].cowPair2
                    << ","
                    << cowInitialPairs[i].consistentPairCount
                    << ")\n";
   
    
    } */
    //int y = 2;
    
    //If a cow pair appears in the same order across all subsequent 
    //sessions (num_sessions - 1 times), its consistentPairCount will 
    //be incremented that many times.At the end, we count how many of 
    //the initial pairs have a consistentPairCount equal to 
    //num_sessions - 1, indicating they remained consistent 
    //throughout all sessions.
    
    int numOfPairsWithSamePairing = std::count_if(cowInitialPairs.begin(), 
                                                  cowInitialPairs.end(), 
                                                  [num_sessions](const CowPair& p) 
                               {return p.consistentPairCount == num_sessions-1;});

    cout << numOfPairsWithSamePairing << endl;


}
