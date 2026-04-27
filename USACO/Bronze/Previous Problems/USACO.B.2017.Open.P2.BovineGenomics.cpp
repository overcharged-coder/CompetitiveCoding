//USACO 2017 US Open Contest, Bronze
//Problem 2. Bovine Genomics
//Google Slides: https://docs.google.com/presentation/d/1wRxn1JeH8PpG2SKyq9Ux0tglqqEAtK_TlUTZkmO1504/edit#slide=id.p
//USACO Guide Link: https://usaco.guide/groups/d7eYGfddXq3m2trXG2xt/post/HUiqbm1YRSctsEgyrY4e/problems/XUHOHLjsTwg3EZnyvBG8
//USACO Link : https://usaco.org/index.php?page=viewproblem2&cpid=736

#include <bits/stdc++.h>
using namespace std;

int main() {

    int num_lines = 0;
    int num_chars =0;
    int gnomeBlock=0;
    int j=0;
    cin >> num_lines;
    cin >> num_chars;

    vector<string> gnomeBlocksSpottyCows(num_lines);
    vector<string> gnomeBlocksPlainCows(num_lines);
    vector<bool> gnomeBlockPredict(num_chars, false);

    // Read the spotty cow sequences
    for (int i = 0; i < num_lines; i++) {
        cin >> gnomeBlocksSpottyCows[i];}
    
    // Read the plain cow sequences
    for (int i = 0; i < num_lines; i++) {
        cin >> gnomeBlocksPlainCows[i];}

    //Loop through every line of spotty cows
    for ( int i=0;i<num_lines;i++){
        //Loop through every gnaome character
        for (int j=0;j<num_chars;j++){

            //Now for every gnome char , check if there is match in the 
            //plain cows gnome position
            char gnome_cd = gnomeBlocksSpottyCows[i][j];

            //Check if match is found, then done repeat the check
            if ( false == gnomeBlockPredict[j])
            {
                //Get all the characters from a gnome position
                for ( int k=0;k<num_lines;k++){
                    
                    //check for gnome char match
                    if (gnome_cd == gnomeBlocksPlainCows[k][j] ){
                        //record the match.
                        gnomeBlockPredict[j] = true;
                    } // check gnome_cd
                } // Loop k
            } // false == gnomeBlockPredict 
        }  //loop j      
    } //loop i

    int resMatchCount = count(gnomeBlockPredict.begin(), 
                                gnomeBlockPredict.end(), 
                                false);
    cout << resMatchCount << endl;
    return 0;

}