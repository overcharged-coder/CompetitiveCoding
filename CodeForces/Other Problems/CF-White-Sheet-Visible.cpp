//CF D3C - White Sheet
//https://codeforces.com/contest/1216/problem/C
//USACO Guide
//https://usaco.guide/groups/rma5Gov1kElNL9hzEHec/post/z0PHo7r5pxSiM5S08ZXy/problems/T4G750G8d5uSUIqCkTfK

#include <bits/stdc++.h>
using namespace std;

//Function : checkIfRectFullyOverlap
// The function would take coordinates of two
// rectangles. Then confirm is the first ( inner )
// rectangles is compltely within the second ( outer )
// rectangle.

bool checkIfRectFullyOverlap ( int inx1, int iny1, int inx2, int iny2,
                                int outx1, int outy1, int outx2, int outy2)
{
    bool isInnerInOuter = false;

    //This function needs to check if the inner rectangle is fully within
    // the outer rectangle.

    // For inner to be within outer the following conditions must satisfy
   if ( 
        (inx1>=outx1) and
        (inx2<=outx2) and
        (iny1>=outy1) and 
        (iny2<=outy2)
    ) 
    {
        isInnerInOuter = true;
    }
   
   return isInnerInOuter;
}

// Function : buildComRectangle
// This function returns the 2 overlapping rectangles
// if they overlap. The function will take two rectangles
// coordinates in the arguments and then populate the out parameters
// with the two cross section rectangles.


bool buildComRectangle (int lx1, int ly1, int lx2, int ly2,
                        int rx1, int ry1, int rx2, int ry2,
                        int &o1x1, int &o1y1, int &o1x2, int &o1y2,
                        int &o2x1, int &o2y1, int &o2x2, int &o2y2) {

    bool retOverlapfound = false;
    bool xOverlapfound = false;
    bool yOverlapfound = false;

    o1x1=-1;o1y1=-1;o1x2=-1;o1y2=-1;o2x1=-1;o2y1=-1;o2x2=-1;o2y2=-1;

    //Calculate width and height for no overlap situation
    int noOverlapWidth = (lx2-lx1)+(rx2-rx1);
    int noOverlapHeight = (ly2-ly1)+(ry2-ry1);
    
    std::vector<int> xCrds = {lx1,lx2,rx1,rx2};
    std::vector<int> yCrds = {ly1,ly2,ry1,ry2};
    // Sort the coordinates to ensure that it is aligned 
    // from small to large and sequenced in that way in the
    // vector.
    std::sort(std::begin(xCrds), std::end(xCrds));
    std::sort(std::begin(yCrds), std::end(yCrds));
    
    // Compute the combined width 
    // It is the difference between the largest and smallest
    // coordinate.
    int combinedWidth = xCrds[3]-xCrds[0];
    int combinedHeight = yCrds[3]-yCrds[0];

    if (noOverlapWidth >= combinedWidth){
        //This means there is an overlap.
        //So we can store the coordinates for the overlap

        //Store the total x-span
        o1x1 = xCrds[0];
        o1x2 = xCrds[3];
        //Store the overlap x coordinates
        o2x1 = xCrds[1];
        o2x2 = xCrds[2];

        xOverlapfound = true;
    }

    if (noOverlapHeight >= combinedHeight){
        //This means there is an overlap.
        //So we can store the coordinates for the overlap
        o1y1 = yCrds[1];
        o1y2 = yCrds[2];
        o2y1 = yCrds[0];
        o2y2 = yCrds[3];
        yOverlapfound = true;
    }

    retOverlapfound = (xOverlapfound and yOverlapfound );
    return retOverlapfound;
}

int main() {

    //White Rectangle Coordinates
    int WX1,WY1,WX2,WY2;
    //1st Black Rectangle Coordinates
    int B1X1,B1Y1,B1X2,B1Y2;
    //2st Black Rectangle Coordinates
    int B2X1,B2Y1,B2X2,B2Y2;
    //Common Rectangle Coordinates
    int C1X1,C1Y1,C1X2,C1Y2;
    int C2X1,C2Y1,C2X2,C2Y2;
    //Reset the combined rectangle coordinates
    C1X1=0;C1Y1=0;C1X2=0;C1Y2=0;
    C2X1=0;C2Y1=0;C2X2=0;C2Y2=0;

       cin >> WX1 >> WY1 >> WX2 >> WY2;
       cin >> B1X1 >> B1Y1 >> B1X2 >> B1Y2;
       cin >> B2X1 >> B2Y1 >> B2X2 >> B2Y2;

    // By default we set that white sheet will be visible.
    // and we will specifically set it to NO for the specific cases.
    string sWhiteSheetIsVisible = "YES";

    //Design.
    //We would try to keep the design simple. 
    //Check is any of the black box covers the white sheet
    if (true == checkIfRectFullyOverlap(WX1,WY1,WX2,WY2,B1X1,B1Y1,B1X2,B1Y2))
    {
        sWhiteSheetIsVisible = "NO";
        //cout << "check1" << endl;
    }
    else if (true == checkIfRectFullyOverlap(WX1,WY1,WX2,WY2,B2X1,B2Y1,B2X2,B2Y2))
    {
        sWhiteSheetIsVisible = "NO";
        //cout << "check2" << endl;

    }
    else
    {
        //Lets build the largest possible rectangle with overlapping boards
        buildComRectangle(B1X1,B1Y1,B1X2,B1Y2,
                            B2X1,B2Y1,B2X2,B2Y2,
                            C1X1,C1Y1,C1X2,C1Y2,
                            C2X1,C2Y1,C2X2,C2Y2);
        
        //Check if the white sheet is covered with any of the cross section
        if (true == checkIfRectFullyOverlap(WX1,WY1,WX2,WY2,C1X1,C1Y1,C1X2,C1Y2))
        {
            sWhiteSheetIsVisible = "NO";
            //cout << "check3" << endl;

        }
        else if (true == checkIfRectFullyOverlap(WX1,WY1,WX2,WY2,C2X1,C2Y1,C2X2,C2Y2)) {
            sWhiteSheetIsVisible = "NO";
           // cout << "check4" << endl;
        }
    }
    cout << sWhiteSheetIsVisible << endl;
}
