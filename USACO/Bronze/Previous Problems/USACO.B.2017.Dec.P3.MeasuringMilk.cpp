//USACO 2017 December Contest, Bronze
//Problem 3. Milk Measurement
//USACO Link https://usaco.org/index.php?page=viewproblem2&cpid=761
//USACO Guide Link https://usaco.guide/groups/rma5Gov1kElNL9hzEHec/post/qqEc7gnjHahO87Zj9YFv/problems/CRRtgqjc5MEVBO04XK0W
//Google Slide https://docs.google.com/presentation/d/1bycXz8_Jfbnme_-tsg4VpNOZymtlL7v4lky6zTzyzVs/edit#slide=id.p

#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int num_measures = 0;
    cin >> num_measures;

    vector<tuple<int, int, int>> cowMilkMeasures;

    for (int i = 0; i < num_measures; i++) {
        int num1, num2;
        string text;

        std::unordered_map<std::string, int> cowNumbers = {
            {"Bessie", 0},
            {"Elsie", 1},
            {"Mildred", 2}
        };

        cin >> num1 >> text >> num2;

        cowMilkMeasures.emplace_back(num1, cowNumbers[text], num2); // Efficiently insert tuple
    }
   
 
    sort(cowMilkMeasures.begin(), cowMilkMeasures.end()); 

    int numDisplayChanges = 0;

    int cowMeasures[3] = {7,7,7};
    int curBoard[3] = {0,0,0};
    int prevBoard[3] = {0,0,0};

    // 0 -- Bessie/1 -- Elsie / 2- Mildred
    // {"Bessie", 0},
    // {"Elsie", 1},
    // {"Mildred", 2}
    
    for (const auto& [seqMeasure, cowNum, cowMeasure] : cowMilkMeasures) {

        for ( int i=0;i<3;i++){
            if (i == cowNum){
                cowMeasures[i] += cowMeasure;}
        }
        
        int maxMeasure = max(cowMeasures[0],max(cowMeasures[1],cowMeasures[2]));

        fill(curBoard, curBoard + 3, 0);
        for ( int i=0;i<3;i++){
            if (maxMeasure==cowMeasures[i] ){
                curBoard[i]=1;
            }
        }
        
        if (!std::equal(curBoard, curBoard + 3, prevBoard)) {  
            numDisplayChanges++;
        }

        memcpy(prevBoard, curBoard, sizeof(curBoard));
  
    }
    cout << numDisplayChanges << endl;
}
