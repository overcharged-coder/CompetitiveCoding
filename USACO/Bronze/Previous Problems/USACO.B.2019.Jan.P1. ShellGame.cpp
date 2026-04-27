
//USACO Bronze
//https://usaco.org/index.php?page=viewproblem2&cpid=891
//USACO Bronze 
//https://usaco.guide/groups/d7eYGfddXq3m2trXG2xt/post/yxuk8S2r38bWhaZO3p0S/problems/no4NPZGC4kF7m7pvecvn
// Name : Cow Shell Game

#include <bits/stdc++.h>
using namespace std;

//Global Variables to get User Inputs
int num_attempts, A[100], B[100], G[100];

// This is a map that will hold the current location of the pebbel.
//  0 ---- 0 ---- 1  ( The thridh shell has the pebbel)
//  0 ---- 1 ---- 0  ( The second shell has the pebbel)
//  1 ---- 0 ---- 0  ( The first shell has the pebbel)

map<int, int> pebble_current_locations;


// Function : scoreForSpecificStart
// This functions takes a specific start as input.
// Then the functions iterates through the swaps and
// simulates swaps using the map variable pebble_current_locations.
// It finally checks if the guess matches the current pebble position.
int scoreForSpecificStart(int pebbleStartPos) {
    
    int retScore = 0;
    
    //Reset start poistion
    //pebble_current_locations.clear();
    pebble_current_locations[1]=0;
    pebble_current_locations[2]=0;
    pebble_current_locations[3]=0;

    //Set the start position of pebble for function 
    pebble_current_locations[pebbleStartPos]=1;

    for (int i = 0; i <= num_attempts; ++i) {

        //Simulate the swaps, we will use swap functions.
        // The value "1" will move to the swapped location.
        swap(
                pebble_current_locations[A[i]],
                pebble_current_locations[B[i]]
            );
        
        //if now we need to check if the guess is right.
        // The selected location "G[i]" would have the pebbel 
        // if the value if 1 after the swap.
        if ( 1 == pebble_current_locations[G[i]])
        {
            retScore++;
        }
    }

    return retScore;
}
int main() {
    
    int bestScore = 0;
    
    //Read all the input parameters.
    cin >> num_attempts;
    for (int i = 0; i <= num_attempts; ++i) {
        cin >> A[i] >> B[i] >> G[i];
    }

    for (int start_pos = 1; start_pos <= 3; start_pos++) {
    
        // Recursivelly build the best score by calling
        // all the starting positions in the loop.
        bestScore = max(bestScore,scoreForSpecificStart(start_pos));
    }

    //Finally, declare the final results.
    cout << bestScore << endl;
    return 0;
}

