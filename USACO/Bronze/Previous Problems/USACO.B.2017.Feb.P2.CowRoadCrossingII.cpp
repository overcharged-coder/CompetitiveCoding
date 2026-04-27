
//USACO 2017 February Contest, Bronze
//Problem 2. Why Did the Cow Cross the Road II
//USACO Link https://usaco.org/index.php?page=viewproblem2&cpid=712
//USACO Guide Link https://usaco.guide/bronze/intro-complete
//Google Slides https://docs.google.com/presentation/d/1gzM3d40wRRhtT1xzyKsAn_Nw2Bqy_zoX6tHBSodIRG4/edit#slide=id.p

#include <bits/stdc++.h>
using namespace std;

int main() {
	string cowSeq;
    cin >> cowSeq;
   // cout << cowSeq << endl;
    int crossingPairs = 0;
    
    for (int i = 0; i < cowSeq.length(); i++) {
        //cout << cowSeq[i] << " ";
        list<char> crossingCowsList;
         
        size_t pos = cowSeq.substr(i+1).find(cowSeq[i]);
        
        if (pos != std::string::npos) {
            //This means the cow has just entered and will
            // exit at pos. So lets get all the cow sequence 
            // entry and exit sequence
            string cowSubSeq = cowSeq.substr(i+1,pos);
            
            if (cowSubSeq.length()>0){
             //   cout  << cowSubSeq << endl;
                std::unordered_map<char, int> charCount;
                
                for (char c : cowSubSeq) {
                        crossingPairs++;
                        charCount[c]++;
                        if (charCount[c] > 1) {
                        crossingPairs=crossingPairs-2;
                        }
                 }
        }
    }

    }
    //Divide by 2 lines will form 1 intersection
    cout << crossingPairs/2 << endl;
}
