
//USACO 2020 February Contest, Bronze
//Problem 1. Triangles
// USACO Guide Link :https://usaco.guide/bronze/intro-complete?lang=cpp
// USACO Link : https://usaco.org/index.php?page=viewproblem2&cpid=1011
// Google Slides : https://docs.google.com/presentation/d/1U-WoNzpyQwr-Oxc6XzG2gy2Ir_x6FfjdmtHNybR6PoU/edit#slide=id.g341591e0ce2_0_11

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int computeArea(int x1,int y1,int x2,int y2,int x3,int y3) {
    int returnArea = 0;
    //check if traingle 2 sides || to x and y
    // || = y - when x - coords are the same
    // || = x - when y coords are the same.
    if ( (x1==x2) && (y1==y3))
    {returnArea = abs((x3-x1)*(y2-y1));}
    return returnArea;
};

int main() {
	
    int num_points;
	cin >> num_points;
    vector<pair<int, int>> list_points(num_points);

    for (int i=0;i<num_points;i++)
    {cin >> list_points[i].first >> list_points[i].second;}
   
 
    //We have to develop 3 loops to find out each traingle
    int maxArea = 0;
    for (int i=0;i<num_points;i++)
    { 
        for (int j=0;j<num_points;j++)
        {
            for (int k=0;k<num_points;k++)
            {

                maxArea = max(maxArea,
                        computeArea (
                            list_points[i].first,
                            list_points[i].second,
                            list_points[j].first,
                            list_points[j].second,
                            list_points[k].first,
                            list_points[k].second
                            )
                    );
            } // 
        }   
    }
    cout << maxArea << endl;
}
