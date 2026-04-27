// USACO 2019 January Contest, Bronze
// Problem 3. Guess the Animal
// USACO Question : https://usaco.org/index.php?page=viewproblem2&cpid=893
// USACO Guide Link : https://usaco.guide/groups/d7eYGfddXq3m2trXG2xt/post/HUiqbm1YRSctsEgyrY4e
// Google Slide Explanation : https://docs.google.com/presentation/d/1gLWrnoPlCJluiTZKSg0-DQ3ay24_snq7Vi7JXkyrlAY/edit#slide=id.p
//

#include <bits/stdc++.h>
using namespace std;

int main() {

    int num_entry = 0;
    cin >> num_entry;

    //Use 2D Array to store the entries
    vector<vector<string>> animalQuestions(num_entry);

    for (int i=0;i<num_entry;i++) {
        string animalName; 
        int numQ;
        cin >> animalName; 
        cin >> numQ;
        for (int j=0;j<numQ;j++) {
           string animalQ;cin >>animalQ;   
           animalQuestions[i].push_back(animalQ);
        }
    }

    int num_match =0;
    int max_num_match =0;

    //Loop and compare all charecteristics of two animals.
    for (int i=0;i<num_entry;i++) {
        for (int j=i+1;j<num_entry;j++) {
        num_match=1; 
        //Check for common charecteristics.
        for (const auto& animalQ : animalQuestions[i]) {
                 for (const auto& CompanimalQ : animalQuestions[j]) {
                    if (animalQ == CompanimalQ ){   
                        //Count the charecteristics matches
                        num_match ++;
                        //No need to compare once you find a match for one charecteristics
                        break;
                    }
                }    
            } 
            max_num_match = max(max_num_match,num_match);
        }   
    }
   
    cout << max_num_match << endl;

}
